#include "random.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Random::Random(){
  srand(time(NULL));
}

int Random::between(int min, int max) {
  if (min == max) {
     return min;
  } 
  return (rand() % ((max + 1) - min )) + min;
}