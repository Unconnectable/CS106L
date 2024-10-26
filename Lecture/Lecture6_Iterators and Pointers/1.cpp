#include <cstdio>
#include <iostream>
#include <vector>
int main(){
    std::vector<int>s{1,2,3,4};
    for(auto it:s){
        std::cout<<it<<std::endl;
    }
    for(auto it = s.begin() ; it!=s.end() ; it++){
        auto elem = *it;
        std::cout <<elem<<std::endl;
    }
    return 0;
}