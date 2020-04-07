#include <iostream>

using namespace std;

int main(){
  int userNumber;
  int aboveFifty=0;

  while ( userNumber != 0 ){
    cout << "Enter a number: ";
    cin >> userNumber;
    if ( userNumber > 50) {
      cout << "Your number is greater than 50.\n";
      aboveFifty++;
    } else {
      cout << "Your number is not over 50.\n";
    }
  }
  cout << "You entered numbers over fifty "\
       << aboveFifty << " times." << endl;
}

