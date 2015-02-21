#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double input1;
    double input2;

    ofstream outputFile;
    outputFile.open("sortedNumbers.txt");

    ifstream inputFile1;
    inputFile1.open("numbers1.txt");

    if(inputFile1.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    ifstream inputFile2;
    inputFile2.open("numbers2.txt");

    if(inputFile2.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    bool moreInput = inputFile1.peek() != EOF || inputFile2.peek() != EOF;
    input1 = nan("1");
    input2 = nan("2");

    while (moreInput) {

        bool input1HasInput = inputFile1.peek() != EOF;
        bool input2HasInput = inputFile2.peek() != EOF;

        if (input1HasInput && isnan(input1))
        {
            inputFile1 >> input1;
        }

        if (input2HasInput && isnan(input2))
        {
            inputFile2 >> input2;
        }

        if (isnan(input1)) {
            //one is empty
            outputFile << input2 << endl;
            input2 = nan("2");
        } 
        else if (isnan(input2)) {
            //two is empty
            outputFile << input1 << endl;
            input1 = nan("1");
        } 
        else {
            if (input1 < input2)
            {
                outputFile << input1 << endl;
                input1 = nan("1");
            }
            else {
                outputFile << input2 << endl;
                input2 = nan("2");
            }
        }

        moreInput = inputFile1.peek() != EOF || inputFile2.peek() != EOF; 
    }

    inputFile1.close();
    inputFile2.close();
    
    return 0;
}
