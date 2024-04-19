#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

std::string railFenceEncrypt(const std::string &text, int key) {
    std::vector<std::string> rails(key);
    int index = 0;
    int step = 1;

    for (char c : text) {
        rails[index].push_back(c);
        if (index == 0) step = 1;
        else if (index == key - 1) step = -1;
        index += step;
    }

    std::string cipherText;
    for (const std::string &rail : rails) cipherText += rail;
    return cipherText;
}
// 
int main() {
    std::string text = "defend the east wall";
    int key = 3;

    std::string cipherText = railFenceEncrypt(text, key);
    std::cout << "Cipher Text: " << cipherText << std::endl;

    return 0;
}
