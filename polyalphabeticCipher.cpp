#include<bits/stdc++.h>
int main(){
    std::string str;
    std::string key;
    std::cout<<"enter message and key : ";
    std::cin>>str>>key;
    for(auto i = 0;i < str.length();i++){
        int temp = int(str[i]) - 97 + int(key[i]) - 97;
        std::cout<<char(temp % 26 + 97);
    }
}
