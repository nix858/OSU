#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int* makeArray(const char* fileName, int& size) {

  vector<int> vect;
  ifstream inFile;
  inFile.exceptions(ifstream::failbit | ifstream::badbit);
  
  try {
    inFile.open(fileName);
    
    while(!inFile.eof()) {
      int temp;
      inFile >> temp; 
      vect.push_back(temp);
    } 

    inFile.close(); 
  } 
  catch (ifstream::failure& e){
    cout << "File error!" << endl;
    exit(1);
  } 

  size = vect.size();

  int* array = new int[size];

  for (int i = 0; i < size; ++i) {
    array[i] = vect[i];
  }
  cout << size << endl;
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

int main(int argc, char const *argv[]) {

  if (argc != 2)
  {
    cout << "Please provide a file name as a command line argument." << endl;
    return 1;
  }

  const char* fileName = argv[1];

  int size = -1;

  int* array = makeArray(fileName, size);

  /*
  //I looked up how to calculate execution time and I decided to
  //use the code I found at http://www.cplusplus.com/forum/beginner/40563/
  //submitted by fun2code (1678), on April 11, 2011 which displayed the time
  //in miliseconds. 
  */

  int start_s = clock();
  int zeroPos = linearSearch(array, size, 0);
  int stop_s=clock();
  if (zeroPos == -1) {
    cout << "NOT FOUND!" << endl;
  } else {
    cout << "Linear search result for '0' in array: " << zeroPos << endl;
  }
  cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  start_s = clock();
  bubbleSort(array, size);
  cout << "Bubble sort completed" << endl;
  stop_s=clock();
  cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
  
  start_s = clock();        
  zeroPos = binarySearch(array, size, 0);
  stop_s=clock();
  if (zeroPos == -1) {
    cout << "NOT FOUND!" << endl;
  } else {
    cout << "Binary search result for '0' in array: " << zeroPos << endl;
  }
  cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
  cout << endl;
  
  delete[] array; 
  return 0;
}
