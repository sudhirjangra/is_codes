#include <iostream>
#include <string>

int main()
{
    std::string msg, key;
    std::cout << "Enter the message and the key: ";
    std::cin >> msg >> key;
    for (int i = 0; i < msg.length(); i++)
    {
        std::cout << (char)('a' + ((msg.at(i) ^ key.at(i % key.length())) % 97));
    }
}
