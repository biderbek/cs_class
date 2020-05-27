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
  cout << "ebet,<value>,<horse 1>,<horse 2> =>\n\t EXACTA bets cost 50 dollars to place but you win 300 dollars if you guess the exact winning order of the top two horses.\n";
  cout << "ebox,<int>,<horse 1>,<horse 2> =>\n\t EXACTABOX bet costs 25 dollars to place but you win 150 if you guess the top two horses in any order.\n";
  cout << "pb => Print your balance.\n";
  cout << "Enter a command: ";
  cin >> s;
  boost::split(r, s, boost::is_any_of(","), boost::token_compress_on);
  return r;
}


class Race {

   int myarray[3] = { 1, 2, 3};

public:

   // constructor
  Race() {
    // set the random seed here
    srand (time(NULL));
  }

   // run the imaginary race
   void readysetgo() {

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

};

class Wallet {
public:
  int currentDollars;
  void printWallet(){
    cout << "You currently have: " << currentDollars << endl;
  }
};


int main()
{

  Wallet myWallet;
  myWallet.currentDollars=300;
  vector<string> myChoices = myMenu();

  while(true){
    if (myChoices[0] == "pb") {
      cout << "Current balance:" << myWallet.currentDollars << endl;
      continue;
    }


    if (myChoices[0] == "ebet"){
      continue;
    }


    if (myChoices[0] == "ebox"){
      continue;
    }
    cout << "Race!" << endl;
    srand(time(NULL));   // initialize a random seed

    Race r;

    // run 10 races to show this works
    for (int i=0; i<10; i++) {
      // Shuffle integer array.to run the race
      r.readysetgo();

      // print out the first place
      cout << r.first() << " " << r.second() << " " << r.third() << endl ;

    }
  }
  return 0;
}
