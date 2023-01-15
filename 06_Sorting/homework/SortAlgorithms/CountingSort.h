#pragma once
#include <vector>

static void countingSort(std::vector<int> &arr, int maxValue) {
  std::vector<int>countNum(maxValue,0);
  for(auto elem : arr){
      countNum[elem]++;
  }
  int ptr = 0;
  for(int i= 0;i < countNum.size();i++){
      for(int j = 0;j < countNum[i];j++) {
          arr[ptr] = i;
          ptr++;
      }
  }
}

