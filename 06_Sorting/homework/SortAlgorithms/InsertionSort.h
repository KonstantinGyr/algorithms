#pragma once
#include "Animal.h"
#include <vector>

static void insertionSort(std::vector<Animal*> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        auto temp = arr[i];
        int ptr;
        for (ptr = i; (ptr>0)&&(arr[ptr - 1]->getWeight() > temp->getWeight());ptr--) {
            arr[ptr] = arr[ptr-1];
        }
        arr[ptr] = temp;
    }
}


