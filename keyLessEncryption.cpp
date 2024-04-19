#include <bits/stdc++.h>
int main()
{
    std::string s;
    int jump;
    std::cout << "enter string : ";
    std::cin >> s;
    std::cout << "characters you want to jump : " << std::endl;
    std::cin >> jump;
    // abcd
    std::cout << "encrypted string is : ";
    for (int i = 0; i < jump + 1; i++)
    {
        for (int j = i; j < s.length(); j += jump + 1)
        {
            std::cout << s[j];
        }
    }
    std::cout << std::endl;
}