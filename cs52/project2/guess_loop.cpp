#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
  srand((unsigned)time(0));
  int myRandNum;
  int playerNum;
  myRandNum = (rand()%100)+1;
  cout << "Player please pick a number (0-100) ";
  cin >> playerNum;
  cout << "\n Dealer has " << myRandNum << "\n";

  if (myRandNum > 21) {
    myRandNum=myRandNum-21;
  } else {
    myRandNum=21-myRandNum;
  }
  if (playerNum > 21) {
    playerNum=playerNum-21;
  } else {
    playerNum=21-playerNum;
  }

  if (playerNum < myRandNum){
    cout << "Player wins\n";
  } else {
    cout << "Dealer wins\n";
  }
}


