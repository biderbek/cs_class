#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>;

using namespace std;

vector<string> carStable;

carStable.push_back ("porsche");
carStable.push_back ("benz");


class myCar {
  int speed=0;
  int horn=0;

public:
  myCar(){
    horn=1;
  }

  myCar(int x){
    speed=x*10;
  }

  void setHorn(int x){
    horn=x;
  }

  int getHorn(){
    return horn;
  }

  void setSpeed(int x){
    speed=x;
  }

  int getSpeed(){
    return speed;
  }
};




int main(){
  myCar porsche;
  myCar benz(10);

  // check porsche speed
  cout << "Porsche: \n My Speed is " << porsche.getSpeed() << endl;

  // returns 100
  if (porsche.getHorn() == 0) {
    cout << "My Horn is off." << endl;
  } else {
    cout << "My Horn is on." << endl;
  }

  cout << endl << "Benz: \n My Speed is " << benz.getSpeed() << endl;

  benz.setSpeed(120);

  cout << endl << "Benz: \n My Speed has changed to " << benz.getSpeed() << endl;


}


