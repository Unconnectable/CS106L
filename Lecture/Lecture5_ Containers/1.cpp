#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec { 1, 2, 3, 4 };
    vec.push_back(5);
    vec.push_back(6);
    vec[1] = 20;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    return 0;
}