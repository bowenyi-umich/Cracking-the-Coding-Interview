#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void setRow0(vector<vector<int>>& matrix, int row){
    for (auto& element : matrix[row]) {
      element = 0;
    }
} 

void setCol0(vector<vector<int>>& matrix, int col){
    for (int i = 0; i < matrix.size(); i++){
      matrix[i][col] = 0;
    }
}

void zeroMatrix(vector<vector<int>>& matrix) {
  vector<bool> row0(matrix.size());
  vector<bool> col0(matrix.size());
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[0].size(); col++) {
            if (matrix[row][col] == 0) {
                row0[row] = true;
                col0[col] = true;
            }
        }
    }

    // set rows to 0
    for (int i = 0; i < row0.size(); i++){
      if(row0[i]){
        setRow0(matrix, i);
      }
    }

    // set columns to 0
    for (int j = 0; j < col0.size(); j++){
      if(col0[j]){
        setCol0(matrix, j);
      }
    }
}


int main() {
  vector<vector<int>> test;
  vector<int> row1 = {1, 1, 1};
  vector<int> row2 = {2, 0, 3};
  vector<int> row3 = {4, 5, 6};
  test.push_back(row1);
  test.push_back(row2);
  test.push_back(row3);
  zeroMatrix(test);
  
  for (int i = 0; i < test.size(); i++){
    for (int j = 0; j < test[0].size(); j++){
      cout << test[i][j] << " ";
    }
  }
}