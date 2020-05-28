#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <array>
#include <time.h>
#include <vector>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split


using namespace std;


// Menu function
vector<string> myMenu(){
  string s;
  vector<string> r;
  cout << endl;
  cout << "ebet,<horse 1>,<horse 2> =>\n\t EXACTA bets cost 50 dollars to place but you win 300 dollars if you guess the exact winning order of the top two horses.\n";
  cout << "ebox,<horse 1>,<horse 2> =>\n\t EXACTABOX bet costs 25 dollars to place but you win 150 if you guess the top two horses in any order.\n";
  cout << "pb => Print your balance.\n";
  cout << "Enter a command: ";
  cin >> s;
  boost::split(r, s, boost::is_any_of(","), boost::token_compress_on);
  return r;
}


class Race {

  int myarray[4] = { 1, 2, 3, 4};

public:

   // constructor
  Race() {
    // set the random seed here
    srand (time(NULL));
  }

   // run the imaginary race
   void readysetgo() {

     cout << "Race!" << endl;

       int n = sizeof(myarray)/sizeof(myarray[0]) ;

       // Loop over array.
       for (int i = 0; i < n; i++) {
           // Get a random index of the array past the current index.
           // ... The argument is an exclusive bound.
           //     It will not go past the array's end.
           int randomValue = i + ( rand() % (n - i) );
           // Swap the random element with the present element.
           int randomElement = myarray[randomValue];
           myarray[randomValue] = myarray[i];
           myarray[i] = randomElement;
       }
   }; // end shuffle

   int first() {
       return myarray[0];
   }
   int second() {
       return myarray[1];
   }
   int third() {
       return myarray[2];
   }
  int fourth() {
    return myarray[3];
  }
  void placements() {
    cout << "Resuts: " + to_string(first()) + " " + to_string(second()) + " " + to_string(third()) + " " + to_string(fourth()) << endl;
  }

};

class Wallet {
private:
  int currentDollars;

public:
  void printWallet(){
    cout << "You currently have: " << currentDollars << endl;
  }
  int getCurrentDollars(){
    return currentDollars;
  }
  void setCurrentDollars(int x){
    currentDollars=x;
  }
};


int main()
{

  Wallet myWallet;
  myWallet.setCurrentDollars(300);
  Race myRace;
  srand(time(NULL));   // initialize a random seed

  while(true){

    vector<string> myChoices = myMenu();

    if (myChoices[0] == "pb") {
      myWallet.printWallet();
      continue;
    }

    if (myChoices[0] == "ebet"){
      myRace.readysetgo();
      if (myWallet.getCurrentDollars() - 50 > 0 ) {
        cout << "You do not have enough money for this bet.\n";
        continue;
      }
      myRace.readysetgo();
      if (stoi(myChoices[1]) == myRace.first() and stoi(myChoices[2]) == myRace.second() ){
        cout << "You won.\n";
        continue;
      }
      continue;
    }


    if ( myChoices[0] == "ebox"){
      myRace.readysetgo();
      myRace.placements();
      if (myWallet.getCurrentDollars() - 50 < 0 ) {
        cout << "You do not have enough money for this bet.\n";
          } else if (( stoi(myChoices[1]) == myRace.first() or stoi(myChoices[1]) == myRace.second() ) and ( stoi(myChoices[2]) == myRace.first() or stoi(myChoices[2]) == myRace.second() )) {
        cout << "You won.\n";
      } else {
        cout << "You lost.\n";
      }
      continue;
    }
  }
  return 0;
}
