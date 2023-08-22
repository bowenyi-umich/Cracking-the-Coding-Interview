#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void urlify(string& input, int trueLen){
  int empty_count = 0;
  for (int i = 0; i < trueLen; i++){
    if(input[i] == ' '){
      empty_count++;
    }
  }
  int actual = trueLen - 1;
  int end = trueLen + empty_count * 2 - 1;
  for(int i = actual; i >= 0; i--)
    if(input[i] == ' '){
      input[end--] = '0';
      input[end--] = '2';
      input[end--] = '%';
     } else {
      swap(input[i], input[end]);
      end--;
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