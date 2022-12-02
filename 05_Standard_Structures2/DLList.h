#include <iostream>
#include <vector>
#include <string>

class DLList {
public:
    DLList() {};
    virtual ~DLList() {};

    struct Node {
        int x;
        Node* next{ nullptr };
        Node* prev{ nullptr };
        Node(int x) {
            this->x = x;
        }
    };
    // You should store pointer to the first element of the list here
    Node* begin{ nullptr };
    // You should store pointer to the last element of the list here
    Node* end{ nullptr };

    // This function should add new element with value x to the front of the list

    void push_front(int x) {
        Node* n = new Node(x);
        if (begin == nullptr) {
            begin = n;
            end = n;
        }
        else
        {
            n->next = begin;
            begin->prev = n;
            begin = n;        
        }
    }

    // This function should add new element with value x to the end of the list
    void push_back(int x) {
        Node* n = new Node(x);
        if (end == nullptr) {
            begin = n;
            end = n;
        }
        else {
            n->next = nullptr;
            n->prev = end;
            end->next = n;
            end = n;
        }
    }

    // This function could be useful for debug purposes
    void print() {
        Node* n = begin;
        while (n != nullptr) {
            std::cout << n->x << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }

    // This function should return the number of element in the list
    int getSize() {
        int count = 0;       
        if (begin == nullptr)return 0;
        Node* n = begin;
        while (n != nullptr) {
            count++;
            n = n->next;
        }
        return count;
    }

    // This function should return an array with values the same as in list
    std::vector<int> toArray() {
        std::vector<int>outVec;
        Node* n = begin;
        while (n != nullptr) {
            outVec.emplace_back(n->x);
            n = n->next;
        }
        return outVec;
    }


    // This function should remove the element x from the list
    void remove(Node* x) {
        Node* prev = x->prev;
        Node* next = x->next;
        if (prev != nullptr) {
            prev->next = next;
        }
        if (next != nullptr) {
           next->prev  = prev;
        }
        x->next = nullptr;
        x->prev = nullptr;
        if (begin == x) {
            begin = next;
        }
        if (end == x) {
            end = prev;
        }
    }

    // This function should remove first element in the list and return its value
    int pop_front() {
        Node* n = begin;
        remove(begin);
        return n->x;
    }

    // This function should remove last element in the list and return its value
    int pop_back() {
        Node* n = end;
        remove(end);
        return n->x;
    }

    // This function should insert element with the value val after the element x
    void insertAfter(Node* x, int val) {
        Node* n = new Node(val);
        if (x == end) {
            n->next = nullptr;
            end = n;
        }
        else
        {
            Node* next = x->next;
            
            n->next = next;
            next->prev = n;
        }
        x->next = n;
        n->prev = x;
                
    }

    // This function should return element at index
    Node* getAt(int index) {
        Node* n = begin;
        int count = 0;
        while (n != nullptr){
            if (count == index)return n;
            n = n->next;
            count++;
        }
        return nullptr;
    }

    // This function construct list from the array
    static DLList fromArray(const std::vector<int> &a) {
        DLList l;
        for (int i = 0; i < a.size(); ++i) {
            l.push_back(a[i]);
        }
        return l;
    }
};