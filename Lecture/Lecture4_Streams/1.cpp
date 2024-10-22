#include <iostream>
#include <sstream>
#include <string>

int main() {
    // 部分 Bjarne 引述
    std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
    
    // 创建一个 stringstream
    std::stringstream ss(initial_quote);
    
    // 数据接收目的地
    std::string first;
    std::string last;
    std::string language, extracted_quote;
    
    // 从 stringstream 中提取内容
    ss >> first >> last >> language;
    //此时first是Bjarne last是Stroustrup language是C
    // 获取剩余的句子
    std::getline(ss, extracted_quote);
    //extracted_quote是剩下的所有
    // 输出结果
    std::cout << first << " " << last << " said this: " << language << " " << extracted_quote << std::endl;

    return 0;
}
