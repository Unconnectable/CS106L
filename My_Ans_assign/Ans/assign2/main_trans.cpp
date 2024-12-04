/*
 * CS106L 作业 2：婚姻契约
 * 由 Haven Whitney 创建，Fabio Ibanez 和 Jacob Roberts-Baca 进行了修改。
 *
 * 欢迎来到 CS106L 作业 2！请完成此文件中的每个 STUDENT TODO。
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

std::string kYourName = "Phrink CS106L"; // 别忘了修改这个！ 

/**
 * 接收文件名并返回一个包含所有申请者名字的集合。
 *
 * @param filename  要读取的文件名。
 *                  文件的每一行都会包含一个申请者的名字。
 * @returns         一个包含所有从文件中读取的申请者名字的集合。
 *
 * @remark 如果需要，可以将此函数（以及其下方的函数）的返回类型更改为 `std::unordered_set`。
 * 如果这样做，请确保也更改 `utils.h` 中相应的函数。
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: 实现这个函数
}

/**
 * 接收一个学生名字的集合，并返回一个包含与给定学生名字相匹配的名字的队列。
 *
 * @param name      返回的名字队列应包含与该名字具有相同首字母的名字。
 * @param students  学生名字的集合。
 * @return          一个包含每个匹配名字指针的队列。
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: 实现这个函数。
}

/**
 * 接收一个指向可能匹配名字的队列，并确定真正的匹配！
 *
 * 您可以按自己的方式实现这个函数，但尽量做一些比简单的 `pop()` 更复杂的操作。
 *
 * @param matches  可能匹配的队列。
 * @return         您的魔法真爱。
 *                 如果 `matches` 为空，将返回 "NO MATCHES FOUND."。
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: 实现这个函数。
}

/* #### 请不要修改此调用自动评分程序的代码！ #### */
int main() { 
    
    return run_autograder(); 
}
