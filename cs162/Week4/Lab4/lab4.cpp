#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

class Dice {
public:
    Dice();
    Dice(int numSides);
    virtual int rollDice() const;
protected:
    int numSides;
};

Dice::Dice() {
    numSides = 6;
    srand(time(NULL)); // Seeds random number generator
}

Dice::Dice(int numSides) {
    this->numSides = numSides;
    srand(time(NULL)); // Seeds random number generator
}

int Dice::rollDice() const {
    return (rand() % numSides) + 1;
}

// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}


class LoadedDice : public Dice {
public:
    LoadedDice();
    LoadedDice(int numberSides);

    virtual int rollDice() const;
};

LoadedDice::LoadedDice() {
    numSides = 6;
    srand(time(NULL)); 
}

LoadedDice::LoadedDice(int numberSides) {
    this->numSides = numberSides;
    srand(time(NULL)); 
}

int LoadedDice::rollDice() const {
    int cheat = rand() % 2;

    if (cheat) {
        return numSides;
    }
    else {
        return Dice::rollDice();
    }
}

double mean(int results[], int size);
int median(int results[], int size);
int mode(int results[], int size);
double standardDev(int results[], int size);

int main() {
    Dice number1(6);
    Dice number2(6);
    const int SIZE = 100;
    int diceResults[SIZE];
    LoadedDice num1(6);
    LoadedDice num2(6);
    int loadedDiceResults[SIZE];
    
    for (int i = 0; i < SIZE; ++i) {
        diceResults[i] = rollTwoDice(number1, number2);
        loadedDiceResults[i] = rollTwoDice(num1, num2);
     } 

    cout << "Mean of Dice:                      " 
        << mean(diceResults, SIZE) << endl;
    cout << "Mean of Loaded Dice:               " 
        << mean(loadedDiceResults, SIZE) << endl;

    cout << "Median of Dice:                    " 
        << median(diceResults, SIZE) << endl;
    cout << "Median of Loaded Dice:             " 
        << median(loadedDiceResults, SIZE) << endl;

    cout << "Mode of Dice:                      "
        << mode(diceResults, SIZE) << endl;
    cout << "Mode of Loaded Dice:               "
        << mode(loadedDiceResults, SIZE) << endl;

    cout << "Standard Deviation of Dice:        "
        << standardDev(diceResults, SIZE) << endl;
    cout << "Standard Deviation of Loaded Dice: "
        << standardDev(loadedDiceResults, SIZE) << endl;

    return 0;
}

 
double mean(int results[], int size) {
    double temp = 0;

    for (int i = 0; i < size; ++i)
    {
        temp += results[i];
    }

    return temp / size;
}

int median(int results[], int size) {
    sort(results, results + size);

    int mid1;
    int mid2;

    if (size % 2 == 0)
    {
        mid1 = size / 2;
        mid2 = mid1 - 1;

        return (results[mid1] + results[mid2]) / 2;
    }
    else {
        mid1 = size / 2;
        return results[mid1];
    }    
}

int mode(int results[], int size) {
    sort(results, results + size);
    int temp = results[0];
    int tempCount = 0;
    int mode;
    int modeCount = 0;

    for (int i = 0; i < size; ++i)
    {
        if (temp == results[i])
        {
            tempCount++;
        }
        else {
            temp = results[i];
            tempCount = 1;
        }
        if (tempCount > modeCount)
        {
            modeCount = tempCount;
            mode = temp;
        }
    }
    return mode;
}

double standardDev(int results[], int size) {
    double standDev = 0;

    double dMean = mean(results, size);
    
    for (int i = 0; i < size; ++i)
    {
        double value = results[i];
        standDev += pow(value - dMean, 2);    
    }

    return standDev / size;
}


