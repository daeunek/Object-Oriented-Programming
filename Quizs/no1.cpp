#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOccurrences(const vector<char>& vec, char ch) {
    int count = 0;
    for (char c : vec) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

char patternCheck(char ch, vector<vector<char>>& charVector) {
    // Count occurrences of the character in the vector
    int count = 0;
    for (const auto& row : charVector) {
        count += countOccurrences(row, ch);
    }

    // Check if the character occurs more than 4 times
    if (count > 4) {
        return 'n';
    }

    // Check for horizontal pattern, vertical pattern, and diagonal patterns
    int horizontalCount = 0, verticalCount = 0, diagonalCount1 = 0, diagonalCount2 = 0;
    for (int i = 0; i < 4; ++i) {
        // Horizontal and Vertical patterns
        switch (charVector[i][0] == ch && charVector[i][1] == ch && charVector[i][2] == ch && charVector[i][3] == ch) {
            case true:
                horizontalCount = 4;
                break;
        }

        switch (charVector[0][i] == ch && charVector[1][i] == ch && charVector[2][i] == ch && charVector[3][i] == ch) {
            case true:
                verticalCount = 4;
                break;
        }

        // Diagonal patterns
        switch (charVector[i][i] == ch) {
            case true:
                diagonalCount1++;
                break;
        }

        switch (charVector[i][3 - i] == ch) {
            case true:
                diagonalCount2++;
                break;
        }
    }

    // Determine the pattern based on counts using switch
    switch (horizontalCount) {
        case 4:
            return '-';
    }

    switch (verticalCount) {
        case 4:
            return '|';
    }

    switch (diagonalCount1) {
        case 4:
            return '\\';
    }

    switch (diagonalCount2) {
        case 4:
            return '/';
    }

    // Character doesn't form any specific pattern
    return 'n';
}

int main() {
    // Take user input for the 4x4 vector
    vector<vector<char>> charVector(4, vector<char>(4));
    cout << "Enter the 4x4 vector of characters:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> charVector[i][j];
        }
    }

    // Take user input for the character to check
    char ch;
    cout << "Enter the character to check: ";
    cin >> ch;

    // Call the patternCheck function and print the result
    char result = patternCheck(ch, charVector);
    cout << "Pattern: " << result << endl;

    return 0;
}