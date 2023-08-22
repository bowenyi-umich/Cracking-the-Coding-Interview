#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

list<list<int>> listDepth(TreeNode* root){
  list<list<int>> ans;
  queue<TreeNode*> visited;
  visited.push(root);
  while(!visited.empty()){
    list<int> level;
    int n = visited.size();
    for (int i = 0; i < n; i++){
      TreeNode* front = visited.front();
      visited.pop();
      if(front->left) visited.push(front->left);
      if(front->right) visited.push(front->right);
      level.push_back(front->val);
    }
    ans.push_back(level);
  }
  return ans;
}






