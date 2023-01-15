#pragma once
#include <vector>

//Реализовать метод сортировки пузырьком
static void bubbleSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
      bool flag = false;
      for (int j = 0; j < n - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
              std::swap(arr[j+1], arr[j]);
              flag = true;
          }
      }
      if(!flag) return;
  }
}
