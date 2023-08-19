#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void urlify(string& input, int trueLen){
  // calculate empty spaces 
  int empty_space = 0;
  for (int i = 0; i < trueLen; i++){
    if(input[i] == ' '){
      empty_space++;
    }
  }

  // Calculate how many space we actually need to replace empty spaces by "%20"
  int actual = trueLen + 2 * empty_space;

  // Edit the input string in-place from backwards by using two pointers
  int index = actual - 1;
  for (int i = trueLen - 1; i >= 0; i--){
    if(input[i] != ' '){
      swap(input[i], input[index]);
      index--;
    } else {
      input[index--] = '0';
      input[index--] = '2';
      input[index--] = '%';
    }
  }
  return;
}

int main() {
    string str = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    urlify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}