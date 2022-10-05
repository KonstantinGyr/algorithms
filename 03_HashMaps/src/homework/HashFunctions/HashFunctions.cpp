#include <string>
#include <cassert>

using namespace std;

int hashString(string input) {
    int sum = 0;
    for(auto letter:input){
        sum +=letter;
    }
    return sum;
}

int hashInt(int input) {
    int product = 0;
    while (input != 0){
        if(input%10 != 0){
            if(product == 0){
                product = input%10;
            } else{
                product *= input%10;
            }
            input /= 10;
        } else{
            return 0;
        }
    }
    return product;
}

struct Student {
    int age;
    string name;
};

int hashStudent(Student input) {
    return hashInt(input.age)+ hashString(input.name);
}

int main(void) {
    assert(hashInt(10) == hashInt(10));
    assert(hashInt(10) != hashInt(11));

}
