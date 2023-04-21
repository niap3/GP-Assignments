// C++ program to generate random numbers
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int a, temp, choice, w, s, d, value, failed;
    int arr[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 5 + 1;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "press 1 for swapping, press 2 for clearing & any other key for quitting";
    cin >> choice;
    if (choice == 1)
    {
        cout << "enter the two positions for swapping";
        cin >> w >> a;
        cin >> s >> d;
        temp = arr[w][a];
        arr[w][a] = arr[s][d];
        arr[s][d] = temp;
    }
    else if (choice == 2)
    {
        cout << "enter first and last spot for clearing\n";
        cin >> w >> a;
        cin >> s >> d;
        value = arr[w][a];
        int saveW = w;
        int saveA = a;
        if (w == s)
        {
            // same row
            while (a != d + 1)
            {
                if (value == arr[w][saveA++])
                {
                    continue;
                }
                else
                {
                    failed = 1;
                    break;
                }
            }
            if (failed != 1)
            {
                for (int i = a; i < d; i++)
                {
                    arr[w][i] = rand() % 5 + 1;
                }
            }
            else
            {
                cout << "wrong selection, try again";
                return 0;
            }
        }
        else
        {
            // different row
            while (w != s + 1)
            {
                if (value == arr[saveW++][a])
                {
                    continue;
                }
                else
                {
                    failed = 1;
                    break;
                }
            }
            if (failed != 1)
            {
                for (int i = w; i < s; i++)
                {
                    arr[i][a] = rand() % 5 + 1;
                }
            }
            else
            {
                cout << "wrong selection, try again";
                return 0;
            }
        }
    }

    cout << "enter first and last spot for clearing\n";
    cin >> w >> a;
    cin >> s >> d;
    value = arr[w][a];
    int saveW = w;
    int saveA = a;
    if (w == s)
    {
        // same row
        while (a != d + 1)
        {
            if (value == arr[w][saveA++])
            {
                continue;
            }
            else
            {
                failed = 1;
                break;
            }
        }
        if (failed != 1)
        {
            for (int i = a; i < d; i++)
            {
                arr[w][i] = rand() % 5 + 1;
            }
        }
        else
        {
            cout << "wrong selection, try again";
            return 0;
        }
    }
    else
    {
        // different row
        while (w != s + 1)
        {
            if (value == arr[saveW++][a])
            {
                continue;
            }
            else
            {
                failed = 1;
                break;
            }
        }
        if (failed != 1)
        {
            for (int i = w; i < s; i++)
            {
                arr[i][a] = rand() % 5 + 1;
            }
        }
        else
        {
            cout << "wrong selection, try again";
            return 0;
        }
    }

    return 0;
}





void randomFill(int a, int b, int c, int d, int e, int f, int g=-1, int h=-1, int i=-1, int j=-1){
        if (i == -1){
            if (g == -1){
                if (e == -1){
                    if (c == -1){
                        // store a,b
                    }
                    else{
                        // store a,b c,d
                    }
                }
                else{
                    // clear a,b c,d e,f
                }
            }
            else{
                // clear a,b c,d e,f g,h
            }
        }
        else{
            // clear a,b c,d e,f g,h i,j
        }