#include <vector>
#include <string>
// Stack implemented using dynamic array inside
class Stack {
private:
    // Array where we store the data
    std::vector<long> a;
    // Number of elements that we actually store in the array. <= a.length
    int size{ 0 };
public:
    Stack() {
        a.resize(10);        
    }
    virtual ~Stack() {};

    int getSize() {
        return size;
    }

    // This function is called when it's not enough memory to fit new elements.
    // It creates new long array and copies all the elements there.
    void reallocate() {
        if(getSize() == a.size()){
            a.resize(getSize()*2);
        }
        else if( getSize() <= a.size()/4){
            a.resize(a.size()/2);
        }
    }

    // Adds element to the end of the stack
    void push_back(long x) {
        if(getSize()==a.size()){
            reallocate();
        }
        a[size] = x;
        size ++;
    }

    // Removes last element from the stack and returns its value
    long pop_back() {
        long lastElem = a[size - 1];
        a[size - 1] = 0;
        size --;

        if(getSize()*4 <= a.size() && a.size()>10){
            reallocate();
        }
        return lastElem;
    }

    // Returns value of the last element in the stack
    long top() {
        return a[size - 1];
    }

    static long calcPolish(const std::string& s) {
         Stack stack;
        bool sign = true;
        std::string strBuffer ;
        long result ;
        int count = 0;
        for(auto character:s){
            long longBuffer ;
            if(s.front() == '-' ) sign = false;
            if(character >= '0' && character <= '9') strBuffer += character;
            else if(character == ' ' ){
                if(!strBuffer.empty()){
                stack.push_back(std::stol(strBuffer));
                strBuffer.clear();}
            }
            else if(character == '+' && stack.getSize() > 0){
                longBuffer = stack.pop_back();
                result = stack.pop_back() + longBuffer  ;
                stack.push_back(result);
            }
            else if(character == '-' && stack.getSize() > 0){
                longBuffer = stack.pop_back();
                result = stack.pop_back() - longBuffer ;
                stack.push_back(result);
            }
            else if(character == '*' && stack.getSize() > 0){
                longBuffer = stack.pop_back();
                result = stack.pop_back() * longBuffer ;
                stack.push_back(result);
            }
            count++;
            if(character >= '0' && character <= '9' && count == s.length()){
                stack.push_back(std::stol(strBuffer));
            }
        }
        result = stack.top();
        if(!sign)result = -result;
        return result;
    }
};

