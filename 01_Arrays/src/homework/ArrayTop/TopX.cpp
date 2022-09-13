#include <vector>
#include <climits>
#include <algorithm>

#include "TopX.h"

using namespace std;

int findMaxUnderBoundary(const vector<int>& inp, int topBoundary) {
    int cur = INT_MIN;
    for (int i = 0; i < inp.size(); ++i) {
        if (inp[i] < topBoundary) {
            cur = max(cur, inp[i]);
        }
    }
    return cur;
}

vector<int> findTopElements(const vector<int>& inp, int numberOfElements) {
    // Создадим массив для результата
    vector<int> res;
    vector<int>current = inp;

    for (int i = 0; i < numberOfElements; i++) {
        int currentMax = INT_MIN;
        int count = 0;
        for(int i=0;i<current.size();i++){
            if(current[i]>currentMax){
                currentMax = current[i];
                count = i;
            }
        }
        res.push_back(currentMax);
        current.erase(current.begin()+count);
    }
    return res;
}

vector<int> findBottomElements(const vector<int>& inp, int elements) {
    vector<int>res;
    vector<int>currentVec = inp;
    for (int i = 0; i < elements; i++) {
        int currentMin = INT_MAX;
        int count = 0;
        for(int i=0;i<currentVec.size();i++){
            if(currentVec[i]<currentMin){
                currentMin = currentVec[i];
                count = i;
            }
        }
        res.push_back(currentMin);
        currentVec.erase(currentVec.begin()+count);
    }
    return res; // Please implement
}
