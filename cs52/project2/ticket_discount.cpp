#include <iostream>
using namespace std;

int main()
{
  int age;
  cout << "tickets cost 14 dollars\n";
  cout << "Input age: ";
  cin >> age;

  if (age < 18)
    {
      cout << "You can get a 10 dollar admission for being a minor.\n";
    }

  if (age > 65)
    {
      cout << "You can get a 10 dollar admission for being a senior citizen.";
    }
}

