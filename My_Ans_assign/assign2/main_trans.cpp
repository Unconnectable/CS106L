/*
 * CS106L 任务 2: 婚姻契约
 * 创建者: Haven Whitney，修改者: Fabio Ibanez 和 Jacob Roberts-Baca。
 *
 * 欢迎来到 CS106L 的任务 2！请完成此文件中的每个学生 TODO
 * 您不需要修改其他文件。
 *
 */
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "utils.h"
std::string kYourName = "学生 TODO"; // 别忘了更改此处！

/**
 * 接受一个文件名并返回一个包含所有申请人姓名的集合。
 *
 * @param filename  要读取的文件名。
 *                  每一行代表一个申请人的姓名。
 * @returns         一个包含从文件读取的所有申请人姓名的集合。
 *
 * @remark 您可以自由修改此函数（及其下面的函数）的返回类型，使用 `std::unordered_set`。
 * 如果这样做，请确保相应地更新 `utils.h` 中的相关函数。
 */
std::set<std::string> get_applicants(std::string filename) {
  // 学生 TODO: 实现此函数。
}

/**
 * 接受一个学生姓名集合并返回一个与给定姓名首字母相同的匹配姓名队列。
 *
 * @param name      返回的姓名队列应与此姓名具有相同的首字母。
 * @param students  学生姓名的集合。
 * @return          包含每个匹配姓名指针的队列。
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // 学生 TODO: 实现此函数。
}

/**
 * 接受一个可能匹配的指针队列并确定唯一的匹配！
 *
 * 您可以以任意方式实现此函数，但请尝试做一些比简单的 `pop()` 更复杂的操作。
 *
 * @param matches 可能的匹配队列。
 * @return       您的唯一匹配。
 *               如果 `matches` 为空，返回 "没有找到匹配。"
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // 学生 TODO: 实现此函数。
}

/* #### 请勿修改此调用评分程序的代码！ #### */
int main() { return run_autograder(); }
