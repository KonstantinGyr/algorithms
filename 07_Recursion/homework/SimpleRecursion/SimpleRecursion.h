#pragma once

class SimpleRecursion {
public:
    SimpleRecursion() {};
    virtual ~SimpleRecursion() {};
    // Task #1
    static int findRecursionFibonacci(int n) {
        if(n == 0)return 0;
        else if(n == 1)return 1;
        return findRecursionFibonacci(n-2) +  findRecursionFibonacci(n - 1);
        // Please implement
    }
};