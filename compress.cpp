#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

string compress(string input){
  int count = 1;
  string ans;

  for (int i = 0; i < input.length(); i++){
      if(count == 1 || i == input.length()){
        ans.push_back(input[i]);
    }
      if(i != input.length() && input[i] == input[i + 1]){
        count++;
      } else {
        string add_count = to_string(count);
        ans += add_count;
        count = 1;
      }
    
  }

  if(ans.length() >= input.length()){
    return input;
  }

  return ans;
}

int main(){
  string test1 = "aaBBccaaa"; // expected: a2B2c2a3
  string test2 = "ab"; // expected: ab 

  cout << "test result for test1: " << compress(test1) << endl;
  cout << "test result for test2: " << compress(test2) << endl;
}