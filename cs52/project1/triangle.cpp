#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
  // Part 1 CircleArea
  cout << "Part 1 CircleArea\n";

  double radius=2.5;
  double area;

  area = 3.14159 * radius * radius;

  cout << area;

  cout << endl << endl;

  // Part 2 TicTacShmoe
  cout << "Part 2 TicTacShmoe\n";

  cout <<
    "1 0 0\n\n"
    "0 1 0\n\n"
    "0 0 1\n\n"
    "0     0     1\n\n\n\n"
    "0     1     0\n\n\n\n"
    "1     0     0\n\n\n\n";


  // Part 3 TriangleArea
  cout << "Part 3 TriangleArea\n";


  double base=3.5;
  double height=4.85;
  cout << base*height*.5 << endl << endl;


  // Part 4 MilesToKilometers
  cout << "Part 4 MilesToKilometers\n";

  double m2k=1.60934;
  double miles=60;
  cout << miles*m2k << endl << endl;

  // Part 5 MyInitials
  cout << "Part 5 MyInitials\n\n";

  cout <<
    "J S\nJ S\nJ S\n\n";

  // Part 6 DoubleUp
  cout << "Part 6 DoubleUp\n";

  int my_number;
  cout << "input a number: ";
  cin >> my_number;

  cout << "~Double up is " << my_number*2 << "~\n";

  return 0;
}
