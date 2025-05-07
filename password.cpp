#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random character from a given character set
char getRandomChar(const string& charSet) {
    return charSet[rand() % charSet.length()];
}

// Function to generate the password
string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSymbols) {
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    string allChars;
    if (useUpper) allChars += upper;
    if (useLower) allChars += lower;
    if (useDigits) allChars += digits;
    if (useSymbols) allChars += symbols;

    if (allChars.empty()) {
        return "Error: No character types selected.";
    }

    string password;
    for (int i = 0; i < length; i++) {
        password += getRandomChar(allChars);
    }
    return password;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int length;
    char upperChoice, lowerChoice, digitChoice, symbolChoice;
    bool useUpper, useLower, useDigits, useSymbols;

    cout << "=== Password Generator ===" << endl;

    cout << "Enter desired password length: ";
    cin >> length;

    cout << "Include uppercase letters? (y/n): ";
    cin >> upperChoice;
    useUpper = (upperChoice == 'y' || upperChoice == 'Y');

    cout << "Include lowercase letters? (y/n): ";
    cin >> lowerChoice;
    useLower = (lowerChoice == 'y' || lowerChoice == 'Y');

    cout << "Include digits? (y/n): ";
    cin >> digitChoice;
    useDigits = (digitChoice == 'y' || digitChoice == 'Y');

    cout << "Include symbols? (y/n): ";
    cin >> symbolChoice;
    useSymbols = (symbolChoice == 'y' || symbolChoice == 'Y');

    string password = generatePassword(length, useUpper, useLower, useDigits, useSymbols);

    cout << "Generated Password: " << password << endl;

    return 0;
}
