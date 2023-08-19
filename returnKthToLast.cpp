#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* returnKth(ListNode* head, int k) {
  ListNode* cur = head;
  int size = 0;
  for (; cur; cur = cur->next) {
    size++;
  }
  int steps = size - k;
  if(steps < 0){
    return nullptr;
  }
  ListNode* toReturn = head;
  while (steps--) {
    toReturn = toReturn->next;
  }
  return toReturn;
}