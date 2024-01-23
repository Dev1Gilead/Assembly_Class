#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

//#include <cmath>

std::string getUserInput() {
    std::string userInput = "";
    std::cin >> userInput;
    return userInput;
}

void displayGreeting() {
    std::cout << "Type one of the following or type quit to exit the program.\n\n";
    std::cout << "HB - Hex to Binary\nBH - Binary to Hex\nHD - Hex to Decimal\nDH - Decimal to Hex\n";
}
bool notHex(std::string userInput) {
    //checks if every ch is one of the possible hex digits
    std::unordered_set<char> allHexDigits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    for (char ch : userInput) {
        if (allHexDigits.count(ch) > 0) {
            continue;
        }
        else {
            std::cout << "Not a Hexedecimal number, try again.\n";
            return true;
        }
    }
    return false;
}

bool isBinary(std::string biInput) {
    std::unordered_set<char> allBiDigits = { '0','1' };

    
    //checks if every ch is one of the possible binary digits
    for (char ch : biInput) {
        if (allBiDigits.count(ch) > 0) {
            continue;
        }
        else {
            std::cout << "Not a binary input.\n";
            return false;
        }
    }
    return true;
}
std::string hexToBi(std::string hexNum) {
    std::unordered_map<char, std::string> allHexToBiDigits = {
    {'0', "0000"}, {'1', "0001"},{'2', "0010"},{'3', "0011"},{'4', "0100"},
    {'5', "0101"},{'6', "0110"},{'7', "0111"},{'8', "1000"},{'9', "1001"},
    {'A', "1010"},{'B', "1011"},{'C', "1100"},{'D', "1101"},
    {'E', "1110"},{'F', "1111"}
    };

    std::string binaryResult = "";
    for (char ch : hexNum) {
        binaryResult.append(allHexToBiDigits[ch]);
    }
    return (binaryResult);

}
std::string BiToHex(std::string biNum) {
 
    while ((biNum.length() % 4) != 0) {
        biNum.insert(0, 1, '0');
    }
    std::unordered_map<std::string, char> allBiToHex = {
    {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'}, {"0100", '4'},
    {"0101", '5'}, {"0110", '6'}, {"0111", '7'}, {"1000", '8'}, {"1001", '9'},
    {"1010", 'A'}, {"1011", 'B'}, {"1100", 'C'}, {"1101", 'D'},
    {"1110", 'E'}, {"1111", 'F'}
    };

    int index = biNum.length() / 4;

    std::string hexNum = "";
    int indexNum = 0;
    // gets the first four digits, converts it to hex, and saves it in a string
    for (int i = 1; i <= index; i++) {
        std::string fourBiDigits = biNum.substr(indexNum, 4);
        indexNum += 4;
        hexNum.push_back(allBiToHex[fourBiDigits]);
    }
    return(hexNum);
}

int main() {
    std::string userInput;
    bool runningMenu = true;

    while (runningMenu) {
        displayGreeting();
        userInput = getUserInput();
        
        if (userInput == "HB") 
        {
            std::cout << "Enter a Hexidecimal number (Do not include the 0x part):";

            std::string hexNum = getUserInput();
            if (notHex(hexNum)) {
                continue;
            }
            else {
                std::cout << "The binary is: " << hexToBi(hexNum) << std::endl;
            }
        }

        else if (userInput == "BH") 
        {
            std::cout << "Enter a Binary Number:";
            std::string biNum = getUserInput();
            if (isBinary(biNum)) 
            {
                std::string hexNum = BiToHex(biNum);

                std::cout << "The hexadecimal number is: 0x" << hexNum << std::endl;

            }
        }

        else if (userInput == "HD") {


        }
        else if (userInput == "DH") {

        }
        else if (userInput == "Quit" || userInput == "quit") {
            break;
        }
        else {
            std::cout << "Invalid input";
        }
    }
}