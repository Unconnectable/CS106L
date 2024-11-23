# Move Functions

 • SMFs Recap 

> • What is a special member function? 

• The Problem 

> • How do our SMFs cause unnecessary copies? 

• lvalues and rvalues 

> • How does C++ distinguish between persistent and temporary objects? 

```cpp
void foo(Photo pic) {
	Photo beReal = pic; //lvalue
    Photo insta = takePhoto();//rvalue
}
```

```cpp
void uploadToInsta(Photo pic);  // pic 是按值传递的参数
int main() {
    Photo selfie = takePhoto(); // selfie 是一个左值
    uploadToInsta(selfie); // 这里会进行一次不必要的拷贝
    //selfie 会被复制到 pic 中
}

```

```cpp
void uploadToInsta(Photo& pic);
 int main() {
     Photo selfie = takePhoto(); // selfie is lvalue 
	 uploadToInsta(selfie); // 不会进行拷贝
     //因为函数的参数是& 是lvaue
     //函数直接操作原始对象，不会创建副本
 }
```

### **`右值引用`**:`&&`,**`左值引用`**:`&`,

```cpp
void upload(Photo &&pic);
int main()
{
    upload(takePhoto());
}
```



• Move Semantics 

> • How can we avoid making unnecessary copies? And a code demo! 

如何使用`srd::move`

```cpp
void PhotoCollection::insert(const Photo &pic, int pos)
{
    for (int i = size(); i > pos; i--)
        elems[i] = std::move(elems[i – 1]);
    elems[i] = pic;
}
```



• `std::move`and `SMFs `

> •How can we ”opt-in” to move semantics? Which SMFs should I define

### **`Rule of Zero`:**

如果一个类不管理内存（或其他外部资源），编译器生成的SMF版本是足够的

### **`Rule of Three`:**

***If you need any one of these, you need them all***

- Destructor
- Copy Assignment
- Copy Constructor

​	如果一个类管理外部资源，我们必须定义`copy assignment/ constructor`,如果我们不定义，编译器生成的SMF将不会复制底层资源.这会导致错误，例如两个对象引用相同的底层数据。

### **`Rule of Five`:**

​	定义了`copy/constructor/copy assign`,我们也需要定义`move/move assign`

***If you need any of these, you probably want them all***:

-  Destructor 
-  Copy Assignment 
-  Copy Constructor 
-  Move Assignment  (Optional) 
-  Move Constructor (Optional)
