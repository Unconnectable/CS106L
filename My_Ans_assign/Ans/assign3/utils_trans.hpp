/*
 * CS106L 作业 3：创建一个类
 * 由 Fabio Ibanez 创建，Jacob Roberts-Baca 进行了修改。
 */

/* ========================================================================= *
 * 不需要担心这一部分内容。                                                *
 * （除非你非常好奇并且想了解更多！）                                          *
 * ========================================================================= */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/**
 * 运行自动评分程序
 * 
 * @returns 如果成功运行自动评分程序，则返回 0，否则返回非零值。
 */
int run_autograder() {
  // 定义一个 lambda 函数，用于运行外部程序
  auto run_program = [](std::string program, std::initializer_list<std::string> args,
                        bool silent = false) {
    std::stringstream ss;

    ss << program;  // 将程序名添加到字符串流中
    for (const auto& arg : args) {  // 遍历参数并将其添加到字符串流
      ss << ' ' << arg;
    }

    // 如果 silent 为 true，则将输出重定向到空设备
    if (silent) {
#ifdef _WIN32
      ss << " >nul 2>&1";  // Windows 系统将输出重定向到 null
#else
      ss << " >/dev/null 2>&1";  // 非 Windows 系统将输出重定向到 /dev/null
#endif
    }

    std::cout.flush();  // 刷新输出缓冲区
    return system(ss.str().c_str());  // 执行系统命令并返回结果
  };

  std::string python;
  // 尝试找到合适的 Python 解释器
  for (const auto& option : {"python", "python3", "/usr/bin/python3", "/usr/bin/python"}) {
    if (run_program(option, {"--version"}, true) == 0) {  // 检查 Python 版本
      python = option;
      break;
    }
  }

  // 如果找不到 Python 解释器，则输出错误并退出
  if (python.empty()) {
    std::cerr << "在系统中未找到 Python。请安装 Python 并重试。" << "\n";
    std::exit(1);  // 退出程序，返回错误码 1
  }

  // 运行自动评分程序
  return run_program(python, {"autograder/autograder.py"});
}
