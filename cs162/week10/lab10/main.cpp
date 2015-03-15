#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

long fibIt(int n);
int fibRec(int num);
long rfactorial (int n);
long factorialHelper (int n, int result);
long factorial(int n);

int main()
{
  /*
  //I looked up how to calculate execution time and I decided to
  //use the code I found at http://www.cplusplus.com/forum/beginner/40563/
  //submitted by fun2code (1678), on April 11, 2011 which displayed the time
  //in miliseconds. 
  */

  int start_s = clock();
  fibIt(30);
  int stop_s = clock();
  cout << "Iterative time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
  cout << endl;

  start_s = clock();
  fibRec(30);
  stop_s = clock();
  cout << "Double Recursive time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
  cout << endl; 

  start_s = clock();
  rfactorial(30);
  stop_s = clock();
  cout << "Recursive factorial time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
  cout << endl;  

  start_s = clock();
  factorial(30);
  stop_s = clock();
  cout << "Tail Recursive factorial time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
  cout << endl;
 
  return 0;
}

/* 
    http://codereview.stackexchange.com/questions/28346/fibonacci-sequence-implementation
    author: Levin Fritz, July 11, 2013 at 16:13
*/
long fibIt(int n) {
    if (n == 0) return 0;
    long previous = 0;
    long current = 1;
    for (int i = 1; i < n; ++i) {
        long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}


/* 
    http://runnable.com/UqfN-4zVBhVwAAH9/solving-the-fibonacci-number-sequence-
    using-recursion-in-c%2B%2B-for-recursive
    author: Racoonacoon
*/
int fibRec(int num) {
  if(num == 0) {
    return 0;
  }

  if(num == 1) {
    return 1;
  }

  int result = fibRec(num - 1) + fibRec(num - 2);
  return result;
}


/*Not Tail Recursive. Code provided in lab. */
long rfactorial (int n) {
 if (n == 1)
  return 1;
 else
  return n * rfactorial(n-1);
}

/* Tail Recursive. Code provided in lab.*/
long factorialHelper (int n, int result) {
 if (n == 1) 
  return result;
 else
  return factorialHelper(n-1, n*result);
}

long factorial(int n) {
 return factorialHelper(n,1);
}





   