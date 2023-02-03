#pragma once
#include <ctime>
#include <functional>
#include <vector>
#include <cstdlib>
#include <iostream>

template<class T>
class Sorting
{

public:
    Sorting(std::function<int(const T&, const T&, int& sortComparisons)> compareTo = [](const T& a,
        const T& b, int& sortComparisons) {
            ++sortComparisons;
            return a < b ? -1 : a == b ? 0 : 1;
        }) {
        this->compareTo = compareTo;
    };
    virtual ~Sorting() {};
    int selectionSortComparisons = 0;
    int insertionSortComparisons = 0;
    int bubbleSortComparisons = 0;
    int quickSortComparisons = 0;
    int mergeSortComparisons = 0;
    double selectionSortExecutionTime = 0;
    double insertionSortExecutionTime = 0;
    double bubbleSortExecutionTime = 0;
    double quickSortExecutionTime = 0;
    double mergeSortExecutionTime = 0;
    std::vector<int>buf;

    void selectionSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        for(int i = 0;i < data.size() - 1;++i){
            int indMin = i;
            bool flag = false;
            for(int j = i + 1;j < data.size();++j){
                if(data[j] < data[indMin]){
                    indMin = j;
                    flag = true;
                }
                if(data[j] < data[j - 1])flag = true;
            }
            if(!flag)break;
            std::swap(data[i],data[indMin]);
        }
        selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
      /*  std::cout<<"selectionSort: ";
        for(auto elem:data){
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;*/
    }

    void insertionSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        for(int i = 0; i < data.size(); ++i){
            auto valElem = data[i];
            int ptr ;
            for(ptr = i; (ptr > 0) && (data [ptr - 1] > valElem); ptr--){
                data[ptr] = data[ptr - 1];
            }
            data[ptr] = valElem;
        }
        insertionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
        /* std::cout<<"insertionSort: ";
       * for(auto elem:data){
             std::cout<<elem<<" ";
         }
         std::cout<<std::endl;*/
    }

    void bubbleSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        for(int i = 0;i < data.size();++i){
            bool flag = false;
            for(int j = 1;j < data.size()-i;++j){
                if(data[j] < data[j - 1]){
                    std::swap(data[j],data[j - 1]);
                    flag = true;
                }
            }
            if(!flag)break;
        }
        bubbleSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
      /*  std::cout<<"bubbleSort:    ";
        for(auto elem:data){
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;*/
    }

    void merge(std::vector<T>& data,int l,int m,int r){
        buf.clear();
        int leftPtr = l,rightPtr = m;
        while (leftPtr < m ||rightPtr < r){
            if(leftPtr == m){
                buf.push_back(data[rightPtr++]);
                continue;
            }
            if(rightPtr == r){
                buf.push_back(data[leftPtr++]);
                continue;
            }
            if(data[leftPtr] < data[rightPtr]){
                buf.push_back( data[leftPtr++]);
            }
            else{
                buf.push_back( data[rightPtr++]);
            }

        }
        for(int i = l;i < r;++i){
            data[i] = buf[i - l];
        }
    }

    void sortM(std::vector<T>& data,int left,int right){
        if(right - left <= 1)return;
        int middle = (left + right)/2;
        sortM(data,left,middle);
        sortM(data,middle,right);
        merge(data,left,middle,right);
    }

    void mergeSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        int l = 0;
        int r = data.size()  ;
        sortM(data,l,r);
        //
        selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
       /* std::cout<<"mergeSort:     ";
        for(auto elem:data){
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;*/
    }

    void qSort(std::vector<T>& data, int l, int r){
        int leftPtr = l,rightPtr = r - 1;
        if(data.empty())return;
        if(rightPtr <= leftPtr)return;
        int ptrMedian = l + rand() % ((r - l) + 1);
        auto median = data[ptrMedian];
        while (leftPtr - rightPtr < 1){
            while (data[leftPtr] < median){
                leftPtr++;
            }
            while (data[rightPtr] > median){
                rightPtr--;
            }
            if(leftPtr <= rightPtr) {
                std::swap(data[leftPtr], data[rightPtr]);
                leftPtr++;
                rightPtr--;
            }
        }
            qSort(data,l,leftPtr );
            qSort(data,leftPtr,r);
    }

    void quickSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        int l = 0;
        int r = data.size();
        qSort(data,l,r);
        //
        quickSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
        /* std::cout<<"quickSort:     ";
       * for(auto elem:data){
             std::cout<<elem<<" ";
         }
         std::cout<<std::endl;*/
    }
private:
    void swap(std::vector<T>& data, int index1, int index2)
    {
        T temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

    void quickSort(std::vector<T>& array, int low, int high) {
        if (array.empty())
            return;//завершить выполнение если длина массива равна 0

        if (low >= high)
            return;//завершить выполнение если уже нечего делить

        // выбрать опорный элемент
        int middle = low + (high - low) / 2;
        auto opora = array[middle];

        // разделить на подмассивы, который больше и меньше опорного элемента
        int i = low, j = high;
        while (i <= j) {
            while (compareTo(array[i], opora) < 0) {
                i++;
            }

            while (compareTo(array[j], opora) > 0) {
                j--;
            }

            if (i <= j) {//меняем местами
                swap(array, i, j);
                i++;
                j--;
            }
        }

        // вызов рекурсии для сортировки левой и правой части
        if (low < j)
            quickSort(array, low, j);

        if (high > i)
            quickSort(array, i, high);
    }


    std::function<int(const T&, const T&, int &sortComparisons)> compareTo;
};