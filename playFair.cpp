#include <iostream>
#include <string>
#include <exception>

int findInArray(char chr, char *arr)
{
    for (int i = 0; i < 25; i++)
    {
        if (arr[i] == chr)
        {
            return i;
        }
    }
    return -1;
}
void checkRowColums(char first, char second, char *matrix)
{
    int p1 = findInArray(first, matrix);
    int p2 = findInArray(second, matrix);
    // Same columns
    if ((p1 % 5) == p2 % 5)
    {
        p1 >= 20 ? std::cout << matrix[p1 % 5] : std::cout << matrix[p1 + 5];
        p2 >= 20 ? std::cout << matrix[p2 % 5] : std::cout << matrix[p2 + 5];
        return;
    }
    // Same row [Difference < 5 and same row checked by comparing the quotient we get dividing by 5 ]
    else if ((p1 / 5 == p2 / 5))
    {
        p1 % 5 == 4 ? std::cout << matrix[p1 - 4] : std::cout << matrix[p1 + 1];
        p2 % 5 == 4 ? std::cout << matrix[p2 - 4] : std::cout << matrix[p2 + 1];
        return;
    }
    // Box condition
    int diff = abs(p1 % 5 - p2 % 5);
    if (p1 > p2)
    {
        std::cout << matrix[p1 - diff];
        std::cout << matrix[p2 + diff];
    }
    std::cout << matrix[p1 + diff];
    std::cout << matrix[p2 - diff];
    return;
}

void playfair(char first, char second, char *matrix)
{
    if (first == second)
    {
        char first1 = first;
        char tempX = 'x';
        checkRowColums(first, tempX, matrix);
        checkRowColums(first, tempX, matrix);
        return;
    }
    checkRowColums(first, second, matrix);
}
int main()
{
    std::string key;
    std::string msg;

    char *matrix = new char[25];

    std::cout << "Enter the key : ";
    std::cin >> key;
    std::cout << "Enter the message : ";
    std::cin >> msg;

    // Inserting key
    for (int i = 0; i < key.length(); i++)
    {
        if (key.at(i) == 'j')
        {
            matrix[i] = 'i';
            continue;
        }
        matrix[i] = key.at(i);
    }

    // Inserting rest of the alphabets
    for (int i = 0, count = 0; i < 26; i++)
    {
        if (key.find((char)(i + 97)) > 26)
        {
            if ((char)(i + 97) == 'j')
            {
                continue;
            }
            matrix[key.size() + count++] = (char)(i + 97);
        }
    }

    // Replacing j with i in user input
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg.at(i) == 'j')
        {
            msg.replace(i, i + 1, "i");
        }
    }

    for (int i = 0; i < msg.size(); i += 2)
    {
        char first = msg.at(i);
        char second = 'x';
        try
        {
            second = msg.at(i + 1);
            playfair(first, second, matrix);
        }
        catch (...)
        {
            playfair(first, second, matrix);
        }
    }
}