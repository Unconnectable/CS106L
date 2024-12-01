# **std::optional & type safety!**

## **Type safety** 

Type Safety: The extent to  which a language  guarantees the behavior  of programs

看一个样例

```cpp
void removeOddsFromEnd(vector<int> &vec)
{
    while (vec.back() % 2 == 1)
    {
        vec.pop_back();
    }
}
```

简单解析下代码:` vector::back()`返回`vec`里的最后一个元素,` vector::pop_back()`弹出`vec`的最后一个元素

存在的问题如下:当``vec`为空时会出现未定义的行为

改进代码:

```cpp
void removeOddsFromEnd(vector<int> &vec)
{
    while (!vec.empty() && vec.back() % 2 == 1)
    {
        vec.pop_back();
    }
}
```

还存在问题:`vec.back()`仍然可能不存在

```cpp
valueType &vector<valueType>::back()
{
    return *(begin() + size() - 1);
}
```

如果不存在的话，这里的解指操作是非法的.必须确定他的指针指向存在的地址才能解指.

```cpp
valueType &vector<valueType>::back()
{
    if (empty())
        throw std::out_of_range;
    return *(begin() + size() - 1);
}// 保证了地址存在
```

考虑`std::pair`的写法

```cpp
std::pair<bool, valueType &> vector<valueType>::back()
{
    if (empty())
    {
        return {false, valueType()};
    }
    return {true, *(begin() + size() - 1)};
}
```

可能存在的问题:

- `valueType()`的构造函数不存在
- 调用构造函数的花费太大

## std::optional

`std::optional<T>` 是一个模板类，它要么包含类型 `T` 的值，要么不包含任何值（用 `std::nullopt` 表示）。

`std::nullopt` 只能与 `std::optional<T>` 一起使用，表示一个空的（未初始化的）`optional` 对象。和`nullptr`不一样.

`std::optional` 类型具有以下方法：

- `.value()`：返回包含的值，如果没有值，则抛出 `bad_optional_access` 错误。
- `.value_or(valueType val)`：返回包含的值，如果没有值，则返回默认值 `val`。
- `.has_value()`：如果包含值，则返回 `true`，否则返回 `false`。

改正的代码

```cpp
void removeOddsFromEnd(vector<int> &vec)
{
    while (vec.back().value() % 2 == 1)
    {
        vec.pop_back();
    }
}
//使用opt
void removeOddsFromEnd(vector<int> &vec)
{
    while (vec.back().has_value() && vec.back().value() % 2 == 1)
    {
        vec.pop_back();
    }
}

//以下也是improved的方法不过不推荐

void removeOddsFromEnd(vector<int> &vec)
{
    while (vec.back().value_or(2) % 2 == 1)
    {
        vec.pop_back();
    }
}

void removeOddsFromEnd(vector<int> &vec)
{
    while (vec.back().value_or(2) % 2 == 1)
    {
        vec.pop_back();
    }
}
```

还存在的一些错误

```cpp
int thisFunctionSucks(vector<int> &vec)
{
    return vec[0];
}
```

`vec`空的时候`[ ]`操作会出问题

一种理想的结局方案,但是`std::optional`的`<T>`不能是地址

```cpp
std::optional<valueType &>
vector<valueType>::operator[](size_t index)
{
    return *(begin() + index);
}
```

可能的修正方案

```cpp
valueType &vector<valueType>::operator[](size_t index)
{
    return *(begin() + index);
}
valueType &vector<valueType>::at(size_t index)
{
    if (index >= size())
        throw std::out_of_range;
    return *(begin() + index);
}
```

使用 `std::optional` 返回的优点：

- 函数签名创建了更具信息性的契约。
- 类函数调用具有保证且可用的行为。

缺点：

- 你将需要在每个地方使用 `.value()`。
- （在 C++ 中）仍然可能出现 `bad_optional_access` 错误。
- （在 C++ 中）`optional` 也可能有未定义行为（`*optional` 与 `.value()` 的作用相同，但没有错误检查）。
- 在很多情况下，我们希望使用 `std::optional<T&>`，但我们并没有这个选项。



`optional`带函数的使用

- `.and_then(function f)`
  如果包含的值存在，返回调用 `f(value)` 的结果，否则返回 `std::nullopt`（`f` 必须返回 `std::optional`）。
- `.transform(function f)`
  如果包含的值存在，返回调用 `f(value)` 的结果，否则返回 `std::nullopt`（`f` 必须返回 `std::optional<valueType>`）。
- `.or_else(function f)`
  如果值存在，返回值本身，否则返回调用 `f` 的结果。

example:调用`lambda`函数传入`optional`

```cpp
void removeOddsFromEnd(vector<int> &vec)
{
    auto isOdd = [](optional<int> num)
    {
        if (num)
            return num % 2 == 1;
        else
            return std::nullopt;
        // return num ? (num % 2 == 1) : {};
    };
    while (vec.back().and_then(isOdd))
    {
        vec.pop_back();
    }
}

```

- Only add features if they solve an actual problem

- Programmers should be free to choose their style
- Compartmentalization is key
- Allow the programmer full control if they want it
-  Don’t sacrifice performance except as a last resort
- Enforce safety at compile time whenever possible

- 通过使用严格的类型系统，你可以保证程序的行为！
- `std::optional` 是实现这一目标的工具：你可以返回一个值或返回“无值”（使用 `.has_value()`、`.value_or()`、`.value()`）。
- 这可能会变得笨重且缓慢，因此 C++ 在大多数 STL 数据结构中并未使用 `optional`。
- 然而，许多语言都在使用它！
- 除了在类中使用它，你还可以在应用程序代码中根据需要使用它！这在实践中是非常推荐的。