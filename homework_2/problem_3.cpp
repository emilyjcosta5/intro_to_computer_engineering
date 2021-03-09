// Call the functions with values for n between 1 and 10 then answer 
// the provided questions.
// Goal: learn recursion
// Created on: Feb 8, 2021
// Author: Emily Costa

#include <iostream>
#include <time.h> 
#include <chrono> 
using namespace std::chrono; 

int F1(int n){
    if(n==0) return 1;
    return F1(n-1)+F1(n-1);
}

int F2(int n){
    if(n==0) return 1;
    if(n%2==0){
        int result=F2(n/2);
        return result*result;
    }
    else return 2*F2(n-1);
}

int main(){
    for(int i=1; i<11; i++){
        std::cout << "For i=" << i << std::endl;
        std::cout << "F1=" << F1(i) << std::endl;
        std::cout << "F2=" << F2(i) << std::endl;
    }

    auto start = high_resolution_clock::now();
    F1(30);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by F1 with n=30: "
         << duration.count() << " microseconds" << std::endl; 

    start = high_resolution_clock::now();
    F2(30);
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by F2 with n=30: "
         << duration.count() << " microseconds" << std::endl; 
    return 0;
}