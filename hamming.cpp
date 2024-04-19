#include <iostream>
#include <string>
#include <math.h>
#include <random>
#include <time.h>

int main()
{
    srand(time(NULL));
    std::string msg;
    std::cout << "Enter the msg: ";
    std::cin >> msg;

    int redBits = 0;
    int parity = 0;
    int msgSize = msg.size();

    for (int i = 0; (pow(2, i) < msgSize + i + 1); i++)
    {
        redBits++;
        msg.insert((int)pow(2, i) - 1, "x", 1);
    }

    std::cout << msg << std::endl;
    std::cout << "Enter the parity Even(0) or Odd(1): ";
    std::cin >> parity;

    for (int i = 0; i < redBits; i++)
    {
        int localParity = parity;
        for (int j = pow(2, i); j <= msg.length(); j++)
        {
            if (((int)pow(2, i) & j) && msg.at(j - 1) != 'x')
            {
                localParity ^= msg.at(j - 1) == '1';
            }
        }
        msg.replace(msg.find_first_of('x'), 1, localParity == 1 ? "1" : "0");
        std::cout << msg << std::endl;
    }
    std::cout << "Sending the msg: \n"
              << msg << std::endl;
    int randPos = rand() % msg.length();
    msg.replace(randPos, 1, msg.at(randPos) == '1' ? "0" : "1");
    std::cout << "Receiving the msg:\n"
              << msg << std::endl;

    int wrongBit = 0;
    for (int i = 0; i < redBits; i++)
    {
        int localParity = parity;
        for (int j = pow(2, i); j <= msg.length(); j++)
        {
            if ((int)pow(2, i) & (j))
            {
                localParity ^= msg.at(j - 1) == '1'; // 0
            }
        }

        if (parity == 0)
        {
            (localParity == parity) ? wrongBit += 0 : wrongBit += (int)pow(2, i);
        }
        else
        {

            (localParity == parity) ? wrongBit += (int)pow(2, i) : wrongBit += 0;
        }

        std::cout << std::endl
                  << (localParity == parity) << "  " << pow(2, i) << " " << wrongBit << std::endl;
    }
    wrongBit == 0 ? std::cout << "No error :)" : std::cout << "Error at position " << wrongBit;
}
