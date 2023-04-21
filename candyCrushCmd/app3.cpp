#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int i, j, array[5][5];

    

    for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                array[i][j] = rand() % 5 + 1;
            }
        }

    for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << "\n";
        }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (array[i][j] == array[i + 1][j] == array[i + 2][j])
            {
                // clear 3
                array[i][j] = 6;
                array[i + 1][j] = 6;
                array[i + 2][j] = 6;
                if (array[i + 2][j] == array[i + 3][j])
                {
                    // clear 4
                    array[i + 3][j] = 6;
                    if (array[i + 3][j] == array[i + 4][j])
                    {
                        // clear 5
                        array[i + 4][j] = 6;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << "\n";
        }
}