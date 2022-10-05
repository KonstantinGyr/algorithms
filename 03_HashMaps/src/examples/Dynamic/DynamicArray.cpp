#include <iostream>
#include <memory>
using namespace std;

class DynamicArray {
public:
    DynamicArray() {
        values = (int*)malloc(sizeof(int) * 8);
        size = 8;
        currentIndex = 0;
    }
    ~DynamicArray() {
        free(values);
    }
    int *values;
    int size;
    int currentIndex;

    void add(int value) {
        values[currentIndex] = value;
        currentIndex++;
        if (currentIndex == size) {
            resize(size * 2);
        }
    }

    void deleteElementAt(int index) {
        if(index>=0&&index<size){
            for(int i = index;i < currentIndex;++i){
                values[i] = values[i+1];
            }
            currentIndex--;
        }
        if(currentIndex<=size/4){
            resize((size/2));
        }
    }

    void resize(int newSize) {
        values = (int*)realloc(values, newSize * sizeof(int));
        size = newSize;
    }
};

int main(void) {
    DynamicArray a;
    for (int i = 0; i < 28; ++i) {
        a.add(i);
    }
    for (int i = 0; i < 30; ++i) {
        cout << a.values[i] << " ";
    }
    cout << endl;
    cout << a.currentIndex << " " << a.size << endl;
    for(int i = 0;i < 25;i++){
        a.deleteElementAt(2);
    }
    for (int i = 0; i < a.size; ++i) {
        cout << a.values[i] << " ";
    }
    cout << endl;
    cout << a.currentIndex << " " << a.size << endl;
}
