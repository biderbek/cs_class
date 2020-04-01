#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{

  int dealerWon=0;
  int playerWon=0;
  while (true){
    int myRandNum;
    int playerNum;

    myRandNum = (rand()%100)+1;
    cout << "Player please pick a number (0-100) ";
    cin >> playerNum;
    if (playerNum==21){
      break;
    }

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
      playerWon++;
    } else {
      cout << "Dealer wins\n";
      dealerWon++;
    }
  }

  cout << "Number of hands played: " << playerWon+dealerWon << "\n";
  cout << "Dealer won: " << dealerWon << "\n";
  cout << "Player won: " << playerWon << "\n";
  cout << "You’re " << playerWon << " for " << dealerWon << "\n";
  cout << "    Come back to the CS052\nRock on.\n";
  /* printf? */

}

