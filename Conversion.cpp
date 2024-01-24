#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

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
    std::unordered_set<char> allHexDigits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F','a','b','c','d','e','f'};
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
    {'E', "1110"},{'F', "1111"}, {'a', "1010"},{'b', "1011"},{'c', "1100"},{'d', "1101"},
    {'e', "1110"},{'f', "1111"}
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
    {"1110", 'E'}, {"1111", 'F'},{"1010", 'a'}, {"1011", 'b'}, {"1100", 'c'}, {"1101", 'd'},
    {"1110", 'e'}, {"1111", 'f'}
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

std::string hexToDec(std::string hexNum) {
    std::unordered_map<char, std::string> allHexToDecDigis = {
    {'0', "0"}, {'1', "1"},{'2', "2"},{'3', "3"},{'4', "4"},
    {'5', "5"},{'6', "6"},{'7', "7"},{'8', "8"},{'9', "9"},
    {'A', "10"},{'B', "11"},{'C', "12"},{'D', "13"},
    {'E', "14"},{'F', "15"}, {'a', "10"},{'b', "11"},{'c', "12"},{'d', "13"},
    {'e', "14"},{'f', "15"}
    };
    int j = 0;
    std::string decNumStr = "";
    int decNumInt = 0;
    //the algorithm for converting Hex to Dec, goes from string, to int, and back to string.
    for (int i = hexNum.size() - 1; i >= 0; i--)
    {
        int tempNum = stoi(allHexToDecDigis[hexNum[i]]);
        decNumInt += tempNum * static_cast<int>(std::pow(16, j));
        j++;
    }
    return(decNumStr.append(std::to_string(decNumInt)));
}

bool isNumber(std::string DecNum) {
    std::unordered_set<char> allBiDigits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


    //checks if every ch is one of the possible digits
    for (char ch : DecNum) {
        if (allBiDigits.count(ch) > 0) {
            continue;
        }
        else {
            std::cout << "Not a Decimal Number input, or is a negitave Decimal Number.\n";
            return false;
        }
    }
    return true;
}


std::string DecToHex(std::string decNumStr) {
    std::unordered_map<std::string, char> allDecToHex = {
        {"0", '0'}, {"1", '1'}, {"2", '2'}, {"3", '3'}, {"4", '4'},
        {"5", '5'}, {"6", '6'}, {"7", '7'}, {"8", '8'}, {"9", '9'},
        {"10", 'A'}, {"11", 'B'}, {"12", 'C'}, {"13", 'D'},
        {"14", 'E'}, {"15", 'F'}
    };

    std::string hexNumStr = "";
    int j = 0;
    int decNumInt = stoi(decNumStr);
    //algorithm to convert dec to hex.
    while (decNumInt > 0) {
        int tempMod = decNumInt % 16;
        decNumInt /= 16;

        hexNumStr = allDecToHex[std::to_string(tempMod)] + hexNumStr;
    }
    return(hexNumStr);
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
            std::cout << "Enter a Hexidecimal number (Do not include the 0x part):";

            std::string hexNum = getUserInput();
            if (notHex(hexNum)) {
                continue;
            }
            else {
                std::cout << "The binary is: " << hexToDec(hexNum) << std::endl;
            }

        }
        else if (userInput == "DH") {
            std::cout << "Enter a Decimal number:";
            std::string DecNum = getUserInput();
            if (isNumber(DecNum))
            {
                std::string hexNum = DecToHex(DecNum);

                std::cout << "The hexadecimal number is: 0x" << hexNum << std::endl;

            }
        }
        else if (userInput == "Quit" || userInput == "quit") {
            break;
        }
        else {
            std::cout << "Invalid input \n";
        }
    }
}