#include "array_max.h"
#include <cmath>
using std::vector;


namespace ArrayMax {

// Task #1
int findSmallestTransaction(vector<int> transactions) {
    int minTransaction=INT_MIN;
    for(auto item:transactions){
        if(item>minTransaction){
            minTransaction=item;
        }
    }
    return minTransaction; // Please implement
}

// Task #2
int findBestStudentMistakes(vector<int> students) {
    int minErrors = INT_MAX;
    for(auto item:students){
        if(item<minErrors){
            minErrors = item;
        }
    }
    return minErrors; // Please implement
}

// Task #3
double findAverageTime(vector<int> times) {
    double sum = 0;
    for (auto item:times){
        sum+=item;
    }
    return sum/times.size(); // Please implement
}

// Task #4
int findMostProfitableClient(vector<vector<int>> income) {
    int bestIncome = INT_MIN;
    int bestCustomer;
    int count  = -1;
    for( auto item:income){
        int sum = INT_MIN;
        count++;
        for(auto gain:item){
            sum+=gain;
        }
        if(sum>bestIncome){
            bestIncome = sum;
            bestCustomer = count;
        }
    }
    return bestCustomer; // Please implement
}
} // namespace ArrayMax
