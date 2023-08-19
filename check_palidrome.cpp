#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cctype>

using namespace std;

bool check_palidrome(string& input){
  // make unordered_map to track the frequency of each letter
  unordered_map<char, int> freq_map;
  for(auto c: input){
    if(isalpha(c)){
      freq_map[tolower(c)]++;
    }
  }

  // track the number of odd frequencies
  int odd_count = 0;
  for(auto freq: freq_map){
    if (odd_count > 1){
      return false;
    }
    if(freq.second % 2 != 0){
      odd_count++;
    }
  }

  return true;
}

int main(){
  string input = "Taco Cat";
  if(check_palidrome(input)){
    cout << "It is permutation of a palidrome" << endl; 
  } else {
    cout << "It's not permutation of a palidrome" << endl;
  }
  return 0;
}