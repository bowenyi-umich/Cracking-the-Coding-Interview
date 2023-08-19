#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> matrix) {
  int l = 0;
  int r = matrix.size() - 1;
  while (r > l){
    for (int i = 0; i < r - l; i++){
      int t = l;
      int b = r;
      int temp = matrix[t][l + i];
      // top left = bottom left
      matrix[t][l + i] = matrix[b - i][l];

      // bottom left = bottom right
      matrix[b - i][l] = matrix[b][r - i];

      // bottom right = top right
      matrix[b][r - i] = matrix[t + i][r];

      // top right = temp
      matrix[t + i][r] = temp;
    }
    l++;
    r--;
  }
}

int main() {

}