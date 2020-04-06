#include <iostream>
using namespace std;

int main()
{
  int score;
  cout << "Human, input score (1-100): ";
  cin >> score;
  if (score >= 90 and score <= 100){
      cout << "You got an A!\n";
     }
  if (score >= 80 and score <= 89) {
      cout << "You got an B!\n";
     }
  if (score >= 70 and score <= 79) {
      cout << "You got a C!\n";
 }
  if (score >= 60 and score <= 69) {
      cout << "It's a D";
  }
  if (score >= 1 and score <= 59 )
      cout << "Yeah you did fail, I’m sorry.";

  return 0;

}

