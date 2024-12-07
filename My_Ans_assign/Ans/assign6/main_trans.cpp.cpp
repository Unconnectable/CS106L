/*
 * CS106L 作业 6: 探索课程
 * 创建者: Haven Whitney，修改者: Jacob Roberts-Baca 和 Fabio Ibanez
 */

/** 学生 TODO：你需要在这里包含一个相关的头文件！ */

#include "autograder/utils.hpp"

/**
 * 课程结构体。这个在作业 1 中应该很熟悉了！
 */
struct Course
{
  std::string title;           // 课程标题
  std::string number_of_units; // 学分数
  std::string quarter;         // 开设学期

  /**
   * 你不需要再忽略这个了！我们现在为 Course 结构体定义了 `==` 操作符。
   */
  bool operator==(const Course& other) const
  {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

class CourseDatabase
{
public:
  CourseDatabase(std::string filename)
  {
    auto lines = read_lines(filename); // 读取文件中的每一行
    std::transform(lines.begin(),
                   lines.end(),
                   std::back_inserter(courses),
                   [](std::string line) {
                     auto parts = split(line, ','); // 按逗号分隔每一行
                     return Course{ parts[0], parts[1], parts[2] }; // 创建 Course 对象
                   });
  }

  /**
   * 根据给定的课程标题在数据库中查找课程，如果存在的话。
   * @param course_title 要查找的课程标题。
   * @return 你需要弄清楚返回什么！
   */
  FillMeIn find_course(std::string course_title)
  {
    /* 学生 TODO：实现这个方法！你需要更改返回类型。 */
    throw std::runtime_error("find_course 尚未实现");
  }

private:
  std::vector<Course> courses; // 存储课程的向量
};

int
main(int argc, char* argv[])
{
  static_assert(
    !std::is_same_v<std::invoke_result_t<decltype (&CourseDatabase::find_course), 
                      CourseDatabase, std::string>,
                    FillMeIn>,
    "你必须更改 CourseDatabase::find_course 的返回类型为其他类型，而不是 FillMeIn。");

  if (argc == 2) {
    CourseDatabase db("autograder/courses.csv"); // 创建课程数据库实例
    auto course = db.find_course(argv[1]); // 查找传入的课程

    /* 学生 TODO：更改此条件。如何检查数据库中是否存在所需的课程？ */
    if (false) {  // 这个条件需要被修改为检查课程是否找到
      std::cout << "找到课程: " << course->title << ","
                << course->number_of_units << "," << course->quarter << "\n";
    } else {
      std::cout << "课程未找到。\n";
    }

    return 0;
  }
  
  return run_autograder();
}
