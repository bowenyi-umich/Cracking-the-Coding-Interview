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

/*
1 -> 3 -> 9 -> 4 -> 2    x = 4
head:  1
tail:  1


// insert to the end of linked list
ListNode* insert;
tail->next = insert;
tail = insert;


// insert to the front of the list:
ListNode* insert;
insert->next = head;
head = insert;


4 -> 1 -> 
*/
ListNode* partition(ListNode* node, int k) {
  ListNode* head = node;
  ListNode* tail = node;
  while(node){
    ListNode* next = node->next;
    if(node->val < k){
      node->next = head;
      head = node;
    } else {
      tail->next = node;
      tail = node;
    }
    node = next;
  }
  tail->next = nullptr;
  return head;
}