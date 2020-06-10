#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class myCar {
  int speed=0;
  int horn=0;

public:
  myCar(){
    horn=1;
  }

  myCar(int x){
    speed=x;
    speed=speed*10;
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

  myCar porsche(10);
  myCar benz;

  vector<myCar> carStable;

  carStable.push_back (porsche);
  carStable.push_back (benz);

  // check porsche speed
  cout << "Porsche: \n My Speed is " << porsche.getSpeed() << endl ;

  // returns 100
  if (porsche.getHorn() == 0) {
    cout << " My Horn is off." << endl;
  } else {
    cout << " My Horn is on.";
  }

  cout << "Benz: \n My Speed is " << benz.getSpeed() << endl;

  benz.setSpeed(120);

  cout << "Benz: \n My Speed has changed to " << benz.getSpeed();

}


