#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;
std::string getUserInput() {
    std::string userInput = "";
    std::cin >> userInput;
    return userInput;
}
//gives greeting
void displayGreeting() {
    std::cout << "Type one of the following or type quit to exit the program.\n\n";
    std::cout << "B2U - Unsigned Encoding\nB2T - Twos Complement Encoding\nT2U - Twos Complement Signed to Unsigned Conversion\nU2C - Unsigned to Twos Complement Signed Conversion\n";
}
//checks if binary
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

std::string binaryToUnsigned(std::string biNum) {

    std::string encodedNum;
    int index = 0;
    char one = '1';
    int total = 0;
    // traverses backward, 
    for (auto it = biNum.rbegin(); it != biNum.rend(); it++) {//equation implimentation
        if (*it == one) {
            total += pow(2, index);
        }
        index += 1;
    }
    encodedNum = std::to_string(total);
    return(encodedNum);
}

//checks if number is decimal/base 10
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
//lets the number also be negitive
bool isNumberOrNegNum(std::string DecNum) {
    std::unordered_set<char> allBiDigits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


    //checks if every ch is one of the possible digits
    for (char ch : DecNum) {
        if (allBiDigits.count(ch) > 0 || DecNum[0] == '-') {
            continue;
        }
        else {
            std::cout << "Not a Decimal Number input, or is a negitave Decimal Number.\n";
            return false;
        }
    }
    return true;
}
//Finding Tmax, Tmin, and Umax
int tMax(string wordsize) {
    int tempi = ((pow(2, stoi(wordsize) - 1)) - 1);
    return tempi;
}
int tMin(string wordsize) {
    int tempi = (-(pow(2, stoi(wordsize) - 1)));
    return tempi;
}
int uMax(string wordsize) {
    int tempi = pow(2, stoi(wordsize)) - 1;
    return tempi;
}

string twosToUnsigned(string decNum, string wordSize) {
    if ( ( -(pow(2, stoi(wordSize) - 1))) <= (stoi(decNum)) && (stoi(decNum)) <= ((pow(2, stoi(wordSize) - 1))-1)) {// checks if the value is in the prober range
        //equation implimentation
        if (stoi(decNum) < 0) {
            int tempi = stoi(decNum) + pow(2, stoi(wordSize));
            return to_string(tempi);
        }
        else if(stoi(decNum) >= 0){
            return decNum;
        }
    }
    else {
        cout << "Incorect word size. \n";
        return "Incorect word size";
    }
}

std::string binaryToTwosComp(std::string biNum, std::string wordSize) {
    std::string twoCompResult = "0";
    if (biNum[0] == '1') {
        biNum[0] = '0';
        int tempi = stoi(binaryToUnsigned(biNum)) - pow(2, (stoi(wordSize) - 1));
        twoCompResult = std::to_string(tempi);
    }
    else {
        twoCompResult = binaryToUnsigned(biNum);
    }
    return(twoCompResult);
}

string unsignedToTwos(string decNum, string wordSize) {
    std::string unsignedResult = "0";
    if ((0 <= (stoi(decNum))) && (stoi(decNum)) <= uMax(wordSize) && wordSize != "0") {// checks if the value is in the prober range
        //equation implimentation
        if (stoi(decNum) <= tMax(wordSize)) {
            return decNum;
        }
        else if (stoi(decNum) > tMax(wordSize)) {
            int tempi2 = stoi(decNum) - pow(2, (stoi(wordSize)));
            return to_string(tempi2);
        }
    }
    else {
        cout << "Incorect word size. \n";
        return "Incorect word size";
    }
}

int main() {
    std::string userInput;
    bool runningMenu = true;

    while (runningMenu) {
        displayGreeting();
        userInput = getUserInput();

        if (userInput == "B2U")
        {
            std::cout << "Enter a Binary Number:";
            std::string biNum = getUserInput();
            if (isBinary(biNum))
            {
                std::string encodedNum = binaryToUnsigned(biNum);

                std::cout << "The Encoding is: " << encodedNum << std::endl;

            }
        }
        
        else if (userInput == "B2T")
            {
                std::cout << "Enter a binary value to encode and the word size in bits:";
                //get input
                std::cout << std::endl << "Value:";
                std::string biNum = getUserInput();
                std::cout << std::endl << "Bit:";
                std::string wordSize = getUserInput();

                if (stoi(wordSize) != biNum.size()) {
                    std::cout << "Incorect word size for the binary numer inputed.\n";
                }
                else if (isBinary(biNum)) {
                    std::cout << "The number is: " << binaryToTwosComp(biNum, wordSize) << std::endl;
                }

            }

        else if (userInput == "T2U") {
            std::cout << "Enter a twos complement signed decimal integer and the word size:";
            //get input
            std::cout << std::endl << "Value:";
            std::string decNum = getUserInput();
            std::cout << std::endl << "Bit:";
            std::string wordSize = getUserInput();

        
            if (isNumberOrNegNum(decNum) && isNumber(wordSize)) {
                if (twosToUnsigned(decNum, wordSize) == "Incorect word size") {
                    continue;
                }
                else {
                    std::cout << "The number is: " << twosToUnsigned(decNum, wordSize) << std::endl;
                }
                
            }
        }
        
        else if (userInput == "U2C") {
            std::cout << "Enter an unsigned decimal integer and the word size in bits number:";
            //get input
            std::cout << std::endl << "Value:";
            std::string decNum = getUserInput();
            std::cout << std::endl << "Bit:";
            std::string wordSize = getUserInput();

            if (isNumber(decNum) && isNumber(wordSize)) {
                if (unsignedToTwos(decNum, wordSize) == "Incorect word size") {
                    continue;
                }
                else {
                    std::cout << "The number is: " << unsignedToTwos(decNum, wordSize) << std::endl;
                }
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