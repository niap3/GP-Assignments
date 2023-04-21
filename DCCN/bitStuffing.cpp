#include <iostream>
#include <string>

using namespace std;

int stuffInterval = 5;

string bitStuffing(string input) {
    string output = "";
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        output += input[i];
        if (count == stuffInterval) {
            output += '0';
            count = 0;
        }
    }
    return output;
}

int main() {
    string input, output;
    cout << "Enter the bit string: ";
    cin >> input;
    output = bitStuffing(input);
    cout << "After bit stuffing: " << output << endl;
    return 0;
}
