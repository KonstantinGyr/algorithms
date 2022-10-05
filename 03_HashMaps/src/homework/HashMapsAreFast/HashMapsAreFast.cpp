#include <vector>
#include <cassert>

using namespace std;

int findGoodIndex(long long key,vector<long long> &buff ) {
    int index = key % buff.size();
    for (int i = 0; i < buff.size(); i++) {
        int probingIndex = (index + i) % buff.size();
        if ((buff[probingIndex] == 0) || (buff[probingIndex] == key)) {
            return probingIndex;
        }
    }
    return -1;
}

vector<long long> getUniqueNumbers(vector<long long> &inputArray) {
    vector<long long> buff(inputArray.size());
    for (int j = 0; j < inputArray.size(); ++j) {
        int index = findGoodIndex(inputArray[j],buff);
        if (buff[index] == 0){
            buff[index] = inputArray[j];
        } else if (buff[index] == inputArray[j]){
            inputArray.erase(inputArray.begin() + j);
            j--;
        }
    }
    return inputArray;
}

bool isThereTwoNumbers(vector<int> numbers, int X) {
    vector<bool>positiveNum(10);
    vector<bool>negativeNum(10);
    for(auto num: numbers){
        if(num>=0){
            if(num>positiveNum.size()) positiveNum.resize(num);
            if(positiveNum[num])return true;
            else positiveNum[num] = true;
        } else {
            if(abs(num)>negativeNum.size()) negativeNum.resize(abs(num));
            if(negativeNum[abs(num)]) return true;
            else{
                negativeNum[abs(num)] = true;
            }
        }
        int diffNum = X - num;
        if(diffNum == num)continue;
        if(diffNum>=0){
            if(diffNum>positiveNum.size()) positiveNum.resize(diffNum);
            if(positiveNum[diffNum])return true;
            else positiveNum[diffNum] = true;
        } else {
            if(abs(diffNum)>negativeNum.size()) negativeNum.resize(abs(diffNum));
            if(negativeNum[abs(diffNum)]) return true;
            else{
                negativeNum[abs(diffNum)] = true;
            }
        }
    }
    return false;
}

int main(void) {
    vector<long long> a = {+79127231920, +79127231921, +79127231920, +79127231923, +79127231922, +79127231921, +79127231923, +79127231924};
    assert(getUniqueNumbers(a) == vector<long long>({+79127231920, +79127231921, +79127231923, +79127231922, +79127231924}));
    assert(isThereTwoNumbers({1, -2, 3, 4}, 2) == true);
    assert(isThereTwoNumbers({1, -2, 3, 4}, 6) == false);
    assert(isThereTwoNumbers({1, -2, 3, 4}, -1) == true);
    assert(isThereTwoNumbers({1, -2, 3, 4}, -5) == false);
    assert(isThereTwoNumbers({1, -2, 3, 4}, 5) == true);
}
