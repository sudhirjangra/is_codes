#include <iostream>
#include <string>

using namespace std;

// Function to perform substitution operation in Hill Cipher
string substitution(string plaintext, const int key[3][3], int mod)
{
    string ciphertext = "";

    // Padding if necessary
    if (plaintext.length() % 3 != 0)
    {
        plaintext += string(3 - (plaintext.length() % 3), 'x');
        // std::cout << "plaintext: " << plaintext << std::endl;
    }

    // Apply substitution
    for (size_t i = 0; i < plaintext.length(); i += 3)
    {
        int block[3] = {plaintext[i] - 'a', plaintext[i + 1] - 'a', plaintext[i + 2] - 'a'};
        int newBlock[3] = {0};
        
        // Matrix multiplication for substitution
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                newBlock[j] += key[j][k] * block[k];
            }
            newBlock[j] %= mod;
        }

        // Convert back to characters and add to ciphertext
        for (int j = 0; j < 3; ++j)
        {
            ciphertext += static_cast<char>(newBlock[j] + 'a');
        }
    }

    return ciphertext;
}

int main()
{
    string plaintext = "act";
    int key[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key, 3x3 matrix
    int mod = 26;                                             // Modulus for the characters

    // Perform substitution
    string ciphertext = substitution(plaintext, key, mod);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
