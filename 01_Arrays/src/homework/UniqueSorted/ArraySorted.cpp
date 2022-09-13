#include "ArraySorted.h"

vector<pair<long long, int>> groupPhoneNumbers(vector<long long> phoneNumbers) {
    vector<pair<long long, int>> ans;
    long long prevNum = phoneNumbers[0];
    int count = 0;
    for (int i=0;i<phoneNumbers.size();i++) {
        if(phoneNumbers[i] != prevNum) {
            ans.emplace_back(prevNum, count);
            prevNum = phoneNumbers[i];
            count = 1;
            if(i == phoneNumbers.size()-1) {
                ans.emplace_back(phoneNumbers[i], count);
            }
            continue;
        } else {
            ++count;
        }
        if(i == phoneNumbers.size()-1){
            ans.emplace_back(phoneNumbers[i],count);
        }
    }
    return ans;
}

vector<pair<string, int>>sum(vector<pair<string, int>>&inputVec){
    vector<pair<string, int>>sumData;
    string name;
    int sum = 0;
    name = inputVec[0].first;
    int count = 0;
    for(auto pair:inputVec){
        ++count;
        if(pair.first == name){
            sum += pair.second;
        }
        else  {
           sumData.push_back({name,sum});
           name = pair.first;
           sum = pair.second;
        }
        if(count == inputVec.size()){
            sumData.push_back({name,sum});
        }

    }
    return sumData;
}


vector<pair<string, int>> cryptoCurrencyAnalysis(string fileContents) {
    vector<pair<string,int>>convertData;
    string name;
    string data;
    int count = 0;
    for(auto letter:fileContents){
        ++count;
        if(letter>='A'&&letter<='Z'){
            name+=letter;
        }
        else if(letter>='0'&&letter<='9'){
            data.push_back(letter);
        }
        if(letter == '\n'|| count==fileContents.size())  {
            int digitData = std::stoi(data);
            std::pair<string ,int> oPair;
            oPair={name,digitData};
            convertData.emplace_back(oPair);
            name.clear();
            data.clear();
        }
    }
    return sum(convertData);
}