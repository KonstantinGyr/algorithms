#include <iostream>
#include <vector>
#include <cassert>

class List {
public:
    List() {};
    virtual ~List() {};

    struct Node {
        int x;
        Node* next = nullptr;
		Node(int _x){
			x = _x;
		}
    };
    // Pointer to the beginning of the list
    Node* begin{ nullptr };
    // Adds element to the beginning of the list
    void push_front(int x) {
        Node* n = new Node(x);
        n->next = begin;
        begin = n;
    }

    // This function could be useful for debugging and testing.
    void print(std::string str) {
        std::cout<<str<<" : ";
        Node* n = begin;
        while (n != nullptr) {
            std::cout << n->x << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }

    // This function should return copy of the list where every second element is removed. Initial list should not be changed.
    // E.g. if we run copyEverySecond on list [1, 2, 3, 4, 5, 6, 7, 100, 120, 162, 0, 1] new list with values [1, 3, 5, 7, 120, 0] should be returned.
    List copyEverySecond() {
        List secList;
        std::vector<int>vec = this->toArray();
        Node* n = begin;
        for(int i = vec.size()-1;i>=0;--i){
            if((i + 1)%2 != 0){
                secList.push_front(vec[i]);
            }
            n = n->next;
        }
        return secList;
    }

    // Returns number of elements in list
    int getSize() {
        int size = 0;
        Node* n = begin;
        while (n != nullptr){
           size ++ ;
           n = n->next;
        }
        return size;
    }

    // This function converts our list to an array. New array is created with values the same as in list.
    std::vector<int> toArray() {
        std::vector<int>vecList;
        Node *n = begin;
        while (n != nullptr){
            vecList.push_back(n->x);
            n = n->next;
        }
        return vecList;
    }

    // This function removes elements x.next from the list
    // O(1) time is expected
    void removeAfter(Node* x) {
        assert(x->next != nullptr &&" Next element is nullptr ");
        Node* n = begin;
        while (n != x){
            n = n->next;
        }
        if(n != nullptr) {
            n->next = n->next->next;
        }
        print("Remove");

        /* TODO IMPLEMENT THIS */
    }

    // This function inserts new element with value val right after the element x.
    // O(1) time is expected
    void insertAfter(Node* x, int val) {
        Node* n = new Node(val) ;
        n->next = x->next;
        x->next = n;
        print("Insert");
    }

    // This function removes all elements from the list that are divisible by x.
    // E.g. list {1, 2, 3, 4, 4, 10, 7}  after filterDivisible(2) would look like {1, 3, 7}.
    // O(N) time is expected.
    void filterDivisible(int _x) {
        Node *n = begin;
        while (n != nullptr){
            if(n->x%_x == 0 && n == begin){
                begin = n->next;
                n = begin;
            } else if (n->next != nullptr && n->next->x%_x == 0 ){
                n->next = n->next->next;
            } else{
            n = n->next;
            }
        }
    }

    // This function returns Node from the list by index. O(N) time is expected.
    Node* getAt(int index) {
        assert(index >= 0 && index<= this->getSize() && " Index is oversize ");
        Node* n = begin;
        int count = 0;
        while (count != index){
           n = n->next;
           count++;
        }
        return n;
    }

    // This function creates List from an array
    static List fromArray(const std::vector<int>& a) {
        List l;
        for (int i = a.size() - 1; i >= 0; --i) {
            l.push_front(a[i]);
        }

        return l;
    }
};
