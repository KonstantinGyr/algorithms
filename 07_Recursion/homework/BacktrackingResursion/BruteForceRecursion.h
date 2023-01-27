#pragma once
#include <string>
#include <vector>
#include <cmath>

std::vector<std::string> digitToPossibleLetters  {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
};
 std::vector<std::string>result;
class BruteForceRecursion {
public:
    BruteForceRecursion() {};
    virtual ~BruteForceRecursion() {};
    // Task #1
     static void recursivF(std::vector<int>&num, std::vector<std::vector<int>> &vec, int pos){
        if(pos >= num.size()){
            vec.push_back(num);
            return ;
        }
        else{
            for(int i = pos;i <num.size();i++){
                std::swap(num[i],num[pos]);
                recursivF(num, vec, pos + 1);
                std::swap(num[i],num[pos]);
            }
        }
    }

    static std::vector<std::vector<int>> orderOfReleaseFeatures(const std::vector<int> &numbersOfFeatures) {
        std::vector<std::vector<int>> resultVV;
        recursivF((std::vector<int> &) numbersOfFeatures, resultVV, 0);
        return resultVV; // Please implement
    }

    // Task #2
    static int recurs(int n,int k){
        if(n == 0) return 0;
        else if(k <= 0 && n != 0) return 1;
        while (n - pow(3,k)<0)k--;
        return recurs(n-pow(3,k),k-1);
}
    static bool checkPowersOfThree(int number) {
        int k = 0;
        while (number - pow(3,k) > 0 )k++;
        return recurs(number,k) == 1 ? false : true; // Please implement
    }

    // Task #3
     static void recFoo(std::vector<int> dig,int count,std::string &buf){
         if(dig.size() == count){
             result.push_back(buf);
             return;
         }
         for(int i = 0;i < digitToPossibleLetters[dig[count]].size();++i){
             buf[count] = digitToPossibleLetters[dig[count]][i];
             recFoo(dig,count + 1,buf);

         }
     }

     static std::vector<std::string> possibleMessages(const std::string &digits) {
         result.clear();
         if(digits.empty()) return result;
         std::string buf(digits.size(),0);
         std::vector<int>vecNum;
         for(auto d:digits){
             std::string ch;
             ch.push_back(d);
             if(ch == "0" || ch == "1")continue;
             vecNum.push_back(std::stoi(ch));
         }
         recFoo(vecNum,0,buf);
        return result; // Please implement
    }

};