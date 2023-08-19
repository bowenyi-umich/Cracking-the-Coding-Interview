#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;


bool check_replacement(string s1, string s2) {
  int p1 = 0;
  int p2 = 0;
  int diff = 0;
  for (; p1 < s1.length(); p1++, p2++) {
    if (diff > 1) {
      return false;
    }
    if (s1[p1] != s2[p2]) {
      diff++;
    }
  }
  return true;
}

bool check_insert(string longer, string shorter) {
  int l = 0;
  int s = 0;
  int diff = 0;

  while (l < longer.size() && s < shorter.size()) {
    if (diff > 1) {
      return false;
    }
    if (longer[l] != shorter[s]) {
      diff++;
      l++;
    } else if (longer[l] == shorter[s]){
      l++;
      s++;
    }
  }

  if (longer.size() - l > 1) {
    return false;
  }

  return true;
  /*
  l: P L E

  S: P L

  l: P E L

  s: P L
  */
}

bool oneaway(string s1, string s2) {
  // if s1 and s2 differ more than 1 in their lengths
  int len1 = s1.length();
  int len2 = s2.length();
  if (abs(len1 - len2) > 1) {
    return false;
  }

  // if s1 and s2 have the same length
  if (s1.length() == s2.length()) {
    return check_replacement(s1, s2);
  }

  // if s1 and s2 have different lengths (differs by 1)
  if (s1.length() > s2.length()) {
    return check_insert(s1, s2);
  } else {
    return check_insert(s2, s1);
  }
}


int main() {
  string test1a = "palae";
  string test1b = "pal";

  if (oneaway(test1a, test1b)) {
    cout << "test1: It's one edit away" << endl;
  } else {
    cout << "test1: Not one edit away" << endl;
  }

  string test2a = "ple";
  string test2b = "plee";
  if (oneaway(test2a, test2b)) {
    cout << "test2: It's one edit away" << endl;
  } else {
    cout << "test2: Not one edit away" << endl;
  }

  string test3a = "PLE";
  string test3b = "PL";
  if (oneaway(test3a, test3b)) {
    cout << "test3: It's one edit away" << endl;
  } else {
    cout << "test3: Not one edit away" << endl;
  }

  string test4a = "pe";
  string test4b = "pl";
  if (oneaway(test4a, test4b)) {
    cout << "test4: It's one edit away" << endl;
  } else {
    cout << "test4: Not one edit away" << endl;
  }
}