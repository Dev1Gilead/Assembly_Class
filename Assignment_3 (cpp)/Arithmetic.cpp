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
    std::cout << "A - Twos Complement Addition\nN - Twos Complement Negation\nM - Twos Complement Multiplication\nD - Twos Complement Division by Power of Two\n";
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
            std::cout << "Not a Decimal Number input.\n";
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
bool isInAdditionRange(string xstr, string ystr, string strw) {
    int w = stoi(strw);
    int x = stoi(xstr);
    int y = stoi(ystr);

    int tempLeft = ( -1 * pow(2, w - 1));
    int tempRight = pow(2, w - 1);
    if (tempLeft <= y && tempLeft <= x && x <= tempRight && y <= tempRight)
    {
        return true;
    }

    return false;
}
//addition equation functions
bool positiveOverflowAddition(string xstr, string ystr, string strw) {
    int w = stoi(strw);
    int x = stoi(xstr);
    int y = stoi(ystr);
    int tempLeft = pow(2, w - 1);
    if (tempLeft <= x + y) {
        return true;
    }
    return false;
}
bool normalAddition(string xstr, string ystr, string strw) {
    int w = stoi(strw);
    int x = stoi(xstr);
    int y = stoi(ystr);
    int tempLeft = (-1 * pow(2, w - 1));
    int tempRigt = (pow(2, w - 1));
    if (tempLeft <= x + y && x + y < tempRigt) {
        return true;
    }
    return false;
}
bool negitiveOverflowAddition(string xstr, string ystr, string strw) {
    int w = stoi(strw);
    int x = stoi(xstr);
    int y = stoi(ystr);
    int tempRigt = (-1 * pow(2, w - 1));
    if (x + y < tempRigt) {
        return true;
    }
    return false;
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

string twosAddition(string decNum1, string decNum2, string wordSize) {
    //equation implementation
    if (isInAdditionRange(decNum1, decNum2, wordSize)) {
        if (positiveOverflowAddition(decNum1, decNum2, wordSize)) { //positive overflow
            int temp = pow(2, stoi(wordSize));
            int resultInt = stoi(decNum1) + stoi(decNum2) - temp;
            return (to_string(resultInt));
        }
        if (normalAddition(decNum1, decNum2, wordSize)) { //normal
            return(to_string(stoi(decNum1) + stoi(decNum2)));
        }
        if (negitiveOverflowAddition(decNum1, decNum2, wordSize)) { //negitive overflow
            int temp = pow(2, stoi(wordSize));
            int resultInt = stoi(decNum1) + stoi(decNum2) + temp;
            return (to_string(resultInt));
        }

    }
    else {
        cout << "Not in the addition range.\n";
        return "Not in the addition range.";
    }
}
string twosNegation(string xstr, string w) {
    int x = stoi(xstr);
    //equation implementation
    if (tMin(w) <= x && x <= tMax(w)) {
        if(x == tMin(w)){
            return xstr;
        }
        else if (x > tMin(w)) {
            int tempX = -x;
            string result = to_string(tempX);
            return result;
        }
        else {
            cout << "error.\n";
        }
    }
    else {
        cout << "Not in range for negation.";
        return("Not in range for negation.");
    }

}
string twosMultiplication(string decNum1, string decNum2, string wordSize) {
    //equation
    if (tMin(wordSize) <= stoi(decNum1) && tMin(wordSize) <= stoi(decNum2) && stoi(decNum1) <= tMax(wordSize) && stoi(decNum2) <= tMax(wordSize)) {

        //equation (x + y) mod(w)
        int twoPowW = pow(2, stoi(wordSize));
        cout << twoPowW << endl;
        int numberInt = ((stoi(decNum1) * stoi(decNum2)) % twoPowW);
        
        //gives a negitive number
        if (numberInt < 0) {
            numberInt = (numberInt + twoPowW) % twoPowW;
        }

  
        //conversion
        string numStr = to_string(numberInt);
        string result = unsignedToTwos(numStr, wordSize);

        return result;

    }
    else {
        cout << "Not in muliplication range.\n";
        return("Not in muliplication range.");
    }

}
string twosDivision(string decNum, string powerOfTwo) {
    //converting my string to ints
    int x = stoi(decNum);
    int k = stoi(powerOfTwo);
    int result;
    //implementaion of the equations
    if (x >= 0) {
        result = x >> k; //rounding down
    }
    else {
        result = (x + (1 << k) - 1) >> k; //rounding up
    }

    return to_string(result);
}


int main() {
    std::string userInput;
    bool runningMenu = true;

    while (runningMenu) {
        displayGreeting();
        userInput = getUserInput();

        if (userInput == "A" || userInput == "a")
        {
            std::cout << "Enter 2 decimal integers and the word size:";
            //get input
            std::cout << std::endl << "Value 1:";
            std::string decNum1 = getUserInput();
            std::cout << std::endl << "Value 2:";
            std::string decNum2 = getUserInput();
            std::cout << std::endl << "Word Size:";
            std::string wordSize = getUserInput();

            if (isNumberOrNegNum(decNum1) && isNumberOrNegNum(decNum2) && isNumber(wordSize))
            {
                std::string nagation = twosAddition(decNum1, decNum2, wordSize);

                if (nagation == "Not in the addition range.") {
                    continue;
                }
                else {
                    std::cout << "The addition result is: " << nagation << std::endl;
                }
                

            }
        }

        else if (userInput == "N" || userInput == "n")
        {
            std::cout << "Enter a decimal integer and the word size:";
            //get input
            std::cout << std::endl << "Value:";
            std::string Num = getUserInput();
            std::cout << std::endl << "Word Size:";
            std::string wordSize = getUserInput();


            if (isNumber(wordSize) && isNumberOrNegNum(Num)) {

                string result = twosNegation(Num, wordSize);
                if (result == "Not in range for negation.") {
                    continue;
                }
                else {
                    cout << "The nagation is: " << result << std::endl;
                }

            }

        }

        else if (userInput == "M" || userInput == "m") {
            std::cout << "Enter 2 decimal integers and the word size:";
            //get input
            std::cout << std::endl << "Value 1:";
            std::string decNum1 = getUserInput();
            std::cout << std::endl << "Value 2:";
            std::string decNum2 = getUserInput();
            std::cout << std::endl << "Bit:";
            std::string wordSize = getUserInput();


            if (isNumberOrNegNum(decNum1) && isNumberOrNegNum(decNum2) && isNumber(wordSize)) {
                if (twosMultiplication(decNum1, decNum2, wordSize) == "Incorect word size" || twosMultiplication(decNum1, decNum2, wordSize) == "Not in muliplication range." ) {
                    continue;
                }
                else {
                    std::cout << "The number is: " << twosMultiplication(decNum1, decNum2, wordSize) << std::endl;
                }

            }
        }

        else if (userInput == "D" || userInput == "d") {
            std::cout << "Enter a decimal integer and the power of 2 to divide by:";
            //get input
            std::cout << std::endl << "Value:";
            std::string decNum = getUserInput();
            std::cout << std::endl << "Power of 2:";
            std::string powerOfTwo = getUserInput();

            if (isNumberOrNegNum(decNum) && isNumber(powerOfTwo)) {

                std::cout << "The number is: " << twosDivision(decNum, powerOfTwo) << std::endl;

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