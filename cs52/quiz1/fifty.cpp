#include <iostream>

using namespace std;

int main(){
  int userNumber;

  cout << "Enter a number: ";
  cin >> userNumber;
  if ( userNumber > 50) {
    cout << "Your number is greater than 50.\n";
  } else {
    cout << "Your number is not over 50.\n";
  }

}

