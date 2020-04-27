#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int myMenu(){
  int myChoice;
  cout << endl;
  cout << "1. Print the current value of bitcoin.\n";
  cout << "2. Buy bitcoin.\n";
  cout << "3. Sell bitcoins\n";
  cout << "4. Print your bitcoin balance.\n";
  cout << "5. Print your transaction history.\n";
  cout << "Enter a number: ";
  cin >> myChoice;
  return myChoice;
}


class Wallet {
public:
  string ticker="BTC";
  int currentCoins;
  void printWallet(){
    cout << ticker << ":" << currentCoins << endl;
  }
};

class Ledger {
public:
  vector<string> ledger;
  void storeTransaction(string myEntry){
    ledger.push_back(myEntry);
  }

  void printLedger(){
    unsigned i;
    for (i=0; i<ledger.size();i++){
      cout << ledger.at(i) << endl;
    }
  }
};

class myDate {
public:
  string stringDate(){
    time_t now = time(0);
    char* dt = ctime(&now);
    string s(dt);
    s.erase(s.find_last_not_of(" \n\r\t")+1);
    return s;
  }
};

class getLive {
public:
  int btcPrice(){
    srand (time(NULL));
    int b = rand() % 1000 + 5000;
    return b;
  }
};

string toString(auto &i){
  // https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
  // https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
  stringstream ss;
  ss << i;
  string s;
  s=ss.str();
  s.erase(s.find_last_not_of(" \n\r\t")+1);
  return s;
}

int main(){

  int myDollars=20000;
  int bitCoinValue=5400;
  int myChoice=0;

  Wallet myWallet;
  Ledger myLedger;

  myWallet.currentCoins=0;

  myDate m;
  cout << m.stringDate();

  while (myChoice!=6){
    myChoice = myMenu();

    switch(myChoice) {

    case 1:
      cout << "The current value of Bitcoin is " << bitCoinValue << endl;
      getLive g;
      bitCoinValue=g.btcPrice();
      cout << "The new value of Bitcoin is " << bitCoinValue << endl;
      break;

    case 2:
      int buyBTC;
      cout << "Buy how many Bitcoin? ";
      cin >> buyBTC;
      int myCost;
      myCost=buyBTC*bitCoinValue;
      if (myCost > myDollars) {
        cout << "No bitcoin bought, you don't have enough $$$\n"; 
      } else {
        myWallet.currentCoins+=buyBTC;
        myDollars-=myCost;
        cout << "My current number of bitcoins: " << myWallet.currentCoins << endl;
        cout << "My current USDs: " << myDollars << endl;
        myDate d;
        string myMessage;
        myMessage=d.stringDate() + ": " + "Bought " + toString(buyBTC) + " BTC. for " + toString(bitCoinValue) + " My cash " + toString(myDollars) + " My BTC " + toString(myWallet.currentCoins);
        myLedger.ledger.push_back(myMessage);
      }

      break;

    case 3:
      int sellBTC;
      cout << "Sell how many Bitcoin? ";
      cin >> sellBTC;
      if (sellBTC > myWallet.currentCoins) {
        cout << "You can't sell more bitcoins than " << myWallet.currentCoins << endl;
      } else {
        myWallet.currentCoins-=sellBTC;
        myDollars+=sellBTC*bitCoinValue;
        cout << "My current number of bitcoins: " << myWallet.currentCoins << endl;
        cout << "My current USDs: " << myDollars << endl;
        myDate d;
        string myMessage;
        myMessage=d.stringDate() + ": " + "Sold " + toString(sellBTC) + " BTC. for " + toString(bitCoinValue) + " My cash " + toString(myDollars) + " My BTC " + toString(myWallet.currentCoins);
        myLedger.ledger.push_back(myMessage);
      }
      break;

    case 4:
      cout << "My current bitcoins are: " << myWallet.currentCoins << endl;
      cout << "My current USDs: " << myDollars << endl;
      break;

    case 5:
      cout << "My transaction history:" << endl;
      unsigned int i;
      for (i=0;i<myLedger.ledger.size();i++) {
        cout << myLedger.ledger.at(i) << endl;
      }
      break;
    default:
      cout << "invalid" << endl;
    }
  }

}
