#include <iostream>
#include <string>

using namespace std;

string encrypt(string plaintext, int shift) {
    string ciphertext = "";
    for (char& c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        ciphertext += c;
    }
    return ciphertext;
}

int main() {
    string plaintext;
    int shift; // Example shift value
    std::cout<<"enter message and key : ";
    std::cin>>plaintext>>shift;

    string ciphertext = encrypt(plaintext, shift);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
