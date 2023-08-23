#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *right, *left, *parent;
};

node* findSuccessor(node* target){
  if(!target) return nullptr;
  if(target->right){
    return findMin(target->right);
  }
  else {
    node* up = target->parent;
    node* child = target;
    while(up && up->left != child){
      child = up;
      up = up->parent;
    }
    return up;
  }
}

node* findMin(node* root){
  if(!root) return nullptr;
  return findMin(root->left);
}