#include <bits/stdc++.h>
void display(std::vector<int> message)
{
    for (auto i = 0; i < message.size(); i++)
    {
        std::cout << message[i];
    }
}
int main()
{
    // on sender's side.

    int temp, parity, count = 0, newCount = 0, receiverParity;
    std::vector<int> message;
    std::cout << "enter message : ";
    for (auto i = 0; i < 8; i++)
    {
        std::cin >> temp;
        message.push_back(temp);
    }
    std::cout << "parity method you want to use ? even (0) or odd (1). ";
    std::cin >> parity;
    if (parity == 0)
    {
        for (auto i = 0; i < message.size(); i++)
        {
            if (message[i] == 1)
            {
                count++;
            }
        }
        std::cout << "adding the parity bit.." << std::endl;
        if (count % 2 == 0)
        {
            message.insert(message.begin(), 0);
        }
        else
        {
            message.insert(message.begin(), 1);
        }
    }
    else
    {
        for (auto i = 0; i < message.size(); i++)
        {
            if (message[i] == 1)
            {
                count++;
            }
        }
        std::cout << "adding the parity bit.." << std::endl;
        if (count % 2 == 0)
        {
            message.insert(message.begin(), 1);
        }
        else
        {
            message.insert(message.begin(), 0);
        }
    }
    srand(time(0));
    int pos = rand() % (message.size() - 1) + 1;
    int val = rand() % 2;
    message[pos] = val;

    // on receiver's side.
    
    for (auto i = 1; i < message.size(); i++)
    {
        if (message[i] == 1)
        {
            newCount++;
        }
    }
    if (newCount % 2 == 0)
    {
        receiverParity = 0;
    }
    else
    {
        receiverParity = 1;
    }
    if(message[0] == receiverParity){
        std::cout<<"no error detected."<<std::endl;
    }
    else{
        std::cout<<"error detected."<<std::endl;
    }
}