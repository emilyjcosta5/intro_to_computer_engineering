// Swap two int values. 
// Goal: learn pass-by-pointer and pass-by-reference.
// Created on: Jan 28, 2021
// Author: Emily Costa

#include <iostream>

void SwapP(int *x, int *y){
    // Swaps values of two int variables using pass-by-pointer
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SwapR(int &x, int &y){
    // Swaps values of two int variables using pass-by-reference
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int x = 5;
    int y = 3;
    std::cout << "X before pointer swap: " << x << "\n";
    std::cout << "Y before pointer swap: " << y << "\n";
    SwapP(&x, &y);
    std::cout << "X after pointer swap: " << x << "\n";
    std::cout << "Y after pointer swap: " << y << "\n";
    SwapR(x, y);
    std::cout << "X after reference swap: " << x << "\n";
    std::cout << "Y after reference swap: " << y << "\n";
}