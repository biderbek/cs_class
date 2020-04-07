#include <iostream>

using namespace std;

int main(){
  int voltage;

  cout << "Enter a number: ";
  cin >> voltage;
  if ( voltage < 30) {
    cout << "low voltage\n";
  } else if ( voltage >= 30 && voltage <= 60) {
    cout << "medium voltage\n";
  } else if ( voltage >= 61 and voltage <= 100 ) {
    cout << "high voltage\n";
  }

}

