#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isSeries(int x)
{
    int y, n = 0;
    y = x / 3;

    // checking if input = , then returns 3
    if (y == 1)
        return 3;

    // checking if input is divisible by 3, because all numbers in the series are divisible by 3
    if (x % 3 != 0)
        return 0;

    // at the end, y can be 1 because of 2/2. so, to prevent that, do y != 1
    while (y != 1)
    {
        if (y % 2 == 0)
            n += 1;
        else
            return 0;
        y = y / 2;
    }

    // returning n value to calculate in main
    return n;
}

int main()
{
    int input, output, powOutput;
    std::cout << "Enter value: ";
    std::cin >> input;
    output = isSeries(input);
    powOutput = pow(2, output + 1);
    if (output == 0)
        std::cout << "You can't make a double bracket matchup out of " << input << " teams";
    else
        std::cout << "You can make a double bracket matchup out of " << input << " teams\n"
                  << "Number of matches are: " << input + powOutput - 2 << "\n"
                  << powOutput << " teams in the upper bracket and " << input - powOutput << " teams in the lower bracket\n";
    return 0;
}