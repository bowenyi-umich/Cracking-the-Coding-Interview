#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

node* findSuccessor(node* root, int target){
  // base case: if root is null, return null
  if(!root) return nullptr;

  // find the target node
  node* targetNode = findTarget(root, target);

  // if target has right subtree, inorder successor is the leftmost node on its right
  if(targetNode->right){
    return findMin(root);
  }

  // if target doesn't have right subtree, then inorder sucessor must be at the top
  node* successor = nullptr;
  node* cur = root;
  while(cur != targetNode){
    if(cur->data > target){ // must go left
      successor = cur;
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }
  return successor;
}

node* findTarget(node* root, int data){
  if(!root) return nullptr;
  if(root->data == data) return root;
  if(root->data < data) return findTarget(root->right, data);
  if(root->data > data) return findTarget(root->left, data);
}

node* findMin(node* root){
  if(!root) return nullptr;
  return findMin(root->left);
}



