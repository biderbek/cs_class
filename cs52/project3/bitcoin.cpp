#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int myMenu(){
  int myChoice;
  cout << "Enter a number:\n";
  cout << "1. Print the current value of bitcoin.\n";
  cout << "2. Buy bitcoin.\n";
  cout << "3. Sell bitcoins\n";
  cout << "4. Print your bitcoin balance.\n";
  cout << "5. Print your transaction history.\n";
  cin >> myChoice;
  return myChoice;
}

int main(){

  /*
    MENU
  1. The user can ask for the current value of bitcoin (just use a default value initially of 5400k).
  2. They can buy bitcoin.
  3. They can sell bitcoin.
  4. They can print their balance (show their current USD, the number of bitcoins they have, and USD value of the bitcoins they have)
  5. They can print the history of their buy and sell transactions out. This should have the time, which you can format however you want ie: bought 1 bitcoin on September 12, 2019.
  */

  int bitCoinValue=5400;
  int bitCoinBalance=0;
  int myChoice=0;

  while (myChoice!=6){
    myChoice = myMenu();
    switch(myChoice) {
    case 1:
      cout << "choice 1" << endl;
      break;
    case 2:
      cout << "choice 2" << endl;
      break;
    case 3:
      cout << "choice 3" << endl;
      break;
    case 4:
      cout << "choice 4" << endl;
      break;
    case 5:
      cout << "choice 5" << endl;
      break;
    default:
      cout << "invalid" << endl;
    }
  }




  class Wallet {
    
  };

  class Ledger {
    
  };

  class myDate {
  public:
    string returnDate(){
      locale::global(std::locale("en_US.UTF-8"));
      time_t t = time(nullptr);
      char mbstr[100];
      if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&t))) {
        return mbstr;
      } else {
        return "error";
      }
    }
  };





}
