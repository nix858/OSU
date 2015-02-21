#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int* makeArray(string fileName, int& size) {

    vector<int> vect;
    ifstream inFile;
    inFile.open(fileName.c_str() );

    if(inFile.fail()) {
        cout << "Error. File did not open!";
        exit(1);
    }

    while(!inFile.eof())
    {
        int temp;
        inFile >> temp; 
        vect.push_back(temp);
    }   
    
    inFile.close();

    size = vect.size();

    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = vect[i];
    }

    return array;
}

int linearSearch(int array[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

void bubbleSort(int array[], int size) {
    bool swap;
    do {
        swap = false;
        for(int i = 0; i < (size-1); i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true; 
            } 
        }
    } while(swap);
}


int binarySearch(int array[], int size, int value) {
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1;
    bool found = false;

    while(!found && first <=last) {
        middle = (first + last) / 2;
        if (array[middle] == value) {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) {
            last = middle -1;
        }
        else {
            first = middle + 1;
        }
    }
    return position;
}

int main() {
    string fileName;
    int size = -1;

    cout << "What is the name of the file?";
    getline(cin, fileName); 

    int* array = makeArray(fileName, size);

    int zeroPos = linearSearch(array, size, 0);
    cout << "Linear search result for '0' in array: " << zeroPos << endl;

    bubbleSort(array, size);

    cout << "sorted:\n";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
    
    zeroPos = binarySearch(array, size, 5);
    cout << "Binary search result for '5' in array: " << zeroPos << endl;
    if (zeroPos == -1) {
        cout << "NOT FOUND!" << endl;
    }
    
    delete[] array; 
    return 0;
}