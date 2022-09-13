#include "ArrayUnique.h"
#include <vector>
#include <string>

using namespace std;

vector<char> lettersLearnedToday(string word) {
    vector<char>res;
    res.push_back(word[0]) ;
    for(auto letter:word){
        bool ok = false;
        for(auto uniqLetter:res){
            if(letter == uniqLetter){
                ok = true;
                break;
            }
        }
        if(!ok) {
            res.push_back(letter);
        }
    }
    return res; // please implement
}

int avoidJailDueToTaxFraud(vector<vector<int>> report) {
    vector<int>uniqueNumbers(0) ;
    for(auto provider:report) {
        for(auto pay:provider){
            for(auto num:uniqueNumbers){
                if(num == pay){
                    return pay;
                }
            }
            uniqueNumbers.push_back(pay);
        }
    }
    return -1;  // please implement
}