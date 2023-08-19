#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void sort_stack(stack<int>& input){
  stack<int> sorted;
  int temp;
  while(!input.empty()){
    temp = input.top();
    input.pop();
    while(!sorted.empty() && temp < sorted.top()){
      input.push(sorted.top());
      sorted.pop();
    }
    sorted.push(temp);
  }
  while(!sorted.empty()){
    input.push(sorted.top());
    sorted.pop();
  }
  return;
}

// Overly complicated
// void sort_stack(stack<int>& input){
//   stack<int> sorted;
//   int temp;
//   while(!input.empty()){
//     temp = input.top();
//     // if sorted is empty || if temp is greater or equal to sorted.top()
//     if(sorted.empty() || temp >= sorted.top()){
//       sorted.push(temp);
//       input.pop();
//     } else {
//       input.pop();
//       int counter = 0;
//       while(!sorted.empty() && temp < sorted.top()){
//         input.push(sorted.top());
//         sorted.pop();
//         counter++;
//       }
//       sorted.push(temp);
//       while(counter--){
//         sorted.push(input.top());
//         input.pop();
//       }
//     }
//   }

//   while(!sorted.empty()){
//     input.push(sorted.top());
//     sorted.pop();
//   }

//   return;
// }

int main(){
  stack<int> test;
  test.push(1);
  test.push(3);
  test.push(0);
  test.push(1);
  test.push(2);
/* 
test:
  2 
  1
  0
  3
  1
*/
/*
  sorted:
  0
  1
  1
  2
  3
*/
  sort_stack(test);
  while (!test.empty()){
    cout << test.top() << " ";
    test.pop();
  }
}