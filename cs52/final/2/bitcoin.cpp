#include <ctime>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <typeinfo>
#include <iterator>
#include <vector>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split

using namespace std;

// Menu function
vector<string> myMenu(){
  string s;
  vector<string> r;
  cout << endl;
  cout << "p => Print the current value of bitcoin.\n";
  cout << "buy,<int> => Buy bitcoin.\n";
  cout << "sell,<int> => Sell bitcoins\n";
  cout << "pb => Print your bitcoin balance.\n";
  cout << "t => Print your transaction history.\n";
  cout << "Enter a command: ";
  cin >> s;
  boost::split(r, s, boost::is_any_of(","), boost::token_compress_on);
  return r;
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
    ofstream f;
    f.open("/tmp/ledger.log");
    f << myEntry << endl;
    f.close();
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
  string myChoice;

  Wallet myWallet;
  Ledger myLedger;

  myWallet.currentCoins=0;

  myDate m;
  cout << m.stringDate();


  // Split string



  // INput list from split tring
  while (true){
    vector<string> myChoices = myMenu();

    if (myChoices[0] == "p") {
      cout << "The current value of Bitcoin is " << bitCoinValue << endl;
      getLive g;
      bitCoinValue=g.btcPrice();
      cout << "The new value of Bitcoin is " << bitCoinValue << endl;
      continue;
    }

    if (myChoices.at(0) == "buy"){
      int buyBTC;
      int myCost;
      buyBTC = stoi(myChoices.at(1));
      cout << "buyBTC: " << typeid(buyBTC).name() << endl;

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
        myLedger.storeTransaction(myMessage);
      }
      continue;
    }

    if (myChoices.at(0) == "sell"){
      int sellBTC;
      sellBTC = stoi(myChoices[1]);
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
        myLedger.storeTransaction(myMessage);
      }
      continue;
    }

    if (myChoices.at(0) == "pb"){
      cout << "My current bitcoins are: " << myWallet.currentCoins << endl;
      cout << "My current USDs: " << myDollars << endl;
      continue;
    }

    if (myChoices.at(0) == "t"){
      cout << "My transaction history:" << endl;
      unsigned int i;
      for (i=0;i<myLedger.ledger.size();i++) {
        cout << myLedger.ledger.at(i) << endl;
      }
      continue;
    }

    cout << "invalid" << endl;
  }
}

