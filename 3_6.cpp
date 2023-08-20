#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class animal{
  public:
  animal(string name): name(name){

  }

  void setOrder(int n){
    order = n;
  }

  int getOrder(){
    return order;
  }

  bool olderThan(animal a){
    return order > a.order;
  }

  private: 
  int order;
  string name;

};

class dog: animal{
};

class cat: animal{

};

class animalShelter{
  public:
  void enque(animal a){
    a.setOrder(order);
    order++;
    // Not very meaningful
  }
  
  animal dequeAny(){

  }

  animal dequeDogs(){

  }

  animal dequeCats(){

  }

  private:
  list<dog> dogs;
  list<cat> cats;
  int order = 0;

};