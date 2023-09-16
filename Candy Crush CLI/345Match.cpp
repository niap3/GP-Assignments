
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

class matrix
{
public:
    int a, temp, choice, w, s, d, value, failed;
    int array[5][5];

    void createMatrix()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                array[i][j] = rand() % 5 + 1;
            }
        }
    }

    void displayMatrix()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void swapValues(int w, int a, int s, int d)
    {
        int temp = array[w][a];
        array[w][a] = array[s][d];
        array[s][d] = temp;
    }

    void randomFill()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (array[i][j] == 6)
                {
                    array[i][j] = rand() % 5 + 1;
                }
            }
        }

    }

    void clearValues()
    {
        int i, j;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                // horizontal
                if (array[i][j] == array[i][j + 1] && array[i][j + 1] == array[i][j + 2])
                {
                    // clear 3
                    array[i][j] = 6;
                    array[i][j + 1] = 6;
                    array[i][j + 2] = 6;
                    if (array[i][j + 2] == array[i][j + 3])
                    {
                        // clear 4
                        array[i][j + 3] = 6;
                        if (array[i][j + 3] == array[i][j + 4])
                        {
                            // clear 5
                            array[i][j + 4] = 6;
                        }
                    }
                }

                // vertical
                if (array[i][j] == array[i + 1][j] && array[i + 1][j] == array[i + 2][j])
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

                // square & l
                if (array[i][j] == array[i][j + 1])
                {
                    // L check
                    if (array[i][j + 1] = array[i + 1][j + 1])
                    {
                        // square check
                        if (array[i + 1][j + 1] == array[i + 1][j])
                        {
                            // square clear
                            array[i][j] = 6;
                            array[i][j + 1] = 6;
                            array[i + 1][j + 1] = 6;
                            array[i + 1][j] = 6;
                        }
                        else
                        {
                            // clear L
                            array[i][j] = 6;
                            array[i][j + 1] = 6;
                            array[i + 1][j + 1] = 6;
                        }
                    } // L check
                    else if (array[i][j + 1] == array[i + 1][j])
                    {
                        // clear L
                        array[i][j] = 6;
                        array[i][j + 1] = 6;
                        array[i + 1][j] = 6;
                    } // L check
                    else if (array[i][j + 1] == array[i - 1][j])
                    {
                        // clear L
                        array[i][j] = 6;
                        array[i][j + 1] = 6;
                        array[i - 1][j] = 6;
                    } // L check
                    else if (array[i][j + 1] == array[i - 1][j + 1])
                    {
                        // clear L
                        array[i][j] = 6;
                        array[i][j + 1] = 6;
                        array[i - 1][j + 1] = 6;
                    }
                }
            }
        }
    }
};

int main()
{
    srand(time(0));
    int w, a, s, d;
    int choice;
    matrix grid;
    grid.createMatrix();
    grid.displayMatrix();
    while (1)
    {
        cout << "\nDo you want to swap(1) or clear matrix(0)? Press 2 to exit the game\n";
        cin >> choice;
        if (choice == 0)
        {
            grid.clearValues();
            // grid.randomFill();
        }
        else if (choice == 1)
        {
            cout << "\nEnter positions for swapping:\t";
            cin >> w >> a >> s >> d;
            grid.swapValues(w, a, s, d);
        }
        else if (choice == 2)
        {
            exit(0);
        }
        else
        {
            cout << "\nInvalid choice, try again...\n";
        }
        grid.displayMatrix();
    }

    return (0);
}
