#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

  srand(time(NULL));
  cout << rand() % 100 + 200 << endl;

  }
