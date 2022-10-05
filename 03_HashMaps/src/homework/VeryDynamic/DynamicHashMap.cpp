#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, string> KV;

class HashMap {
public:
    KV *entries = new KV[8];
    int size = 8;
    int numberOfElements = 0;
    ~HashMap() {
        delete[] entries;
    }
    int hashFunction(string key) {
        long long a = 0;
        for (unsigned char c : key) {
            a = (a * 239 + c) % 1000000007;
        }
        return a;
    }

    void add(string key, string value) {
        int index = findGoodIndex(key);
        entries[index] = make_pair(key, value);
        numberOfElements++;
        if (numberOfElements == size) {
            resize(size * 2);
        }
    }

    void resize(int newSize) {
        KV *newEntries = new KV[newSize];
        swap(newEntries, entries);
        swap(newSize, size);
        for (int i = 0; i < newSize; i++) {
            KV entry = newEntries[i];
            int index = findGoodIndex(entry.first);
            entries[index] = entry;
        }
        delete[] newEntries;
    }

    string get(string key) {
        int index = findGoodIndex(key);
        if (index == -1) {
            return "";
        }
        KV entry = entries[index];
        return entry.second;
    }

    int findGoodIndex(string key) {
        int hash = hashFunction(key);
        int index = hash % size;
        for (int i = 0; i < size; i++) {
            int probingIndex = (index + i) % size;
            KV entry = entries[probingIndex];
            if ((entry.first.size() == 0) || (entry.first == key)) {
                return probingIndex;
            }
        }
        return -1;
    }

    void deleteKey(string key) {
        for(int i = 0;i<size;i++){
            KV entry = entries[i];
            if(entry.first == key){
                entry.first = "";
                entry.second = "";
                entries[i] = entry;
                numberOfElements--;
                break;
            }
        }
        if(numberOfElements <= size/4){
            resize(size/2);
        }
    }

    vector<string> getAllKeys() {
        vector<string>allKeys;
        for(int i = 0;i<size;++i){
            KV entry = entries[i];
            if(entry.first != "" ){
                allKeys.push_back(entry.first);
            }
        }
        return allKeys;
    }

    vector<string> getAllValues() {
        vector<string>allValues;
        for(int i = 0;i<size;++i){
            KV entry = entries[i];
            if(entry.second != ""){
                allValues.push_back(entry.second);
            }
        }
        return allValues;
    }
};

void printMap(HashMap &h){
    for(int i = 0;i<h.size;++i){
        KV entry = h.entries[i];
        cout <<entry.first<<" "<< h.get(entry.first) << endl;
    }
    cout << h.numberOfElements << " " << h.size << endl;
}

void printVector(vector<string>vec){
    for(auto str:vec){
        cout<<str<<" ";
    }
    cout<<endl;
}

int main(void) {
    HashMap h;
    h.add("Hello", "world");
    cout << h.get("Hello") << endl;
    cout << h.get("Hellop") << endl;
    h.add("test", "best");
    cout << h.get("test") << endl;
    printMap(h);
    for (char c = 'a'; c <= 'z'; ++c) {
        string s = " ";
        s[0] = c;
        h.add(s, s);
    }
    printMap(h);
    cout << h.get("Hello") << endl;
    h.deleteKey("Hello");
    cout << h.get("Hello") << endl;
    h.add("Hello", "something else");
    cout << h.get("Hello") << endl;
    printVector(h.getAllKeys());
    printVector(h.getAllValues());
    h.deleteKey("d");
    printMap(h);
    for (char c = 'a'; c <= 't'; ++c) {
        string s = " ";
        s[0] = c;
        h.deleteKey(s);
    }
    printMap(h);
}