#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class multiStack{
  public:
  multiStack(int stackSize){
    stackCap = stackSize;
    values = vector<int>(numOfStacks * stackSize, -1);
    sizes = vector<int>(3, 0);
  }

  void push(int stackNum, int val){
    // When that stack is not full
    if(sizes[stackNum] < stackCap){
      // capacity = 10, stackNum = 1, stack 1 already has 6 elements in it
      values[stackNum * stackCap + sizes[stackNum]] = val;
      sizes[stackNum]++;
    }
    // when the stack is full, then just return
    else {
      return;
    }
  }

  void pop(int stackNum){
    //normal case
    if(sizes[stackNum] != 0){
      // capacity = 10, stackNum = 1, stack 1 already has 6 elements in it
      values[stackNum * stackCap + sizes[stackNum] - 1] = -1;
      sizes[stackNum]--;
    }
    // when stack is empty
    else {
      return;
    }
  }

  int top(int stackNum){
    return values[stackNum * stackCap + sizes[stackNum] - 1];
  }

  bool empty(int stackNum){
    return sizes[stackNum] == 0;
  }

  private:
    vector<int> values;
    vector<int> sizes;
    int numOfStacks = 3;
    int stackCap;
};