#include <iostream>
#include <chrono>
using namespace std::chrono;

int A[50]; // initialize global array

int FibonacciR(int n){
    if (n <= 1) return n; // keep going until complete
    return FibonacciR(n-1) + FibonacciR(n-2); 
}

int fibd(int n){
    // Helper function to calculate the remaining sequence
    if (n<2) return n; // If 0 or 1, then no need to continue
    if(A[n]!=-1) return A[n]; // return if finished
    A[n] = fibd(n-1) + fibd(n-2); // top-down approach
    return A[n];
}

int FibonacciD(int n){
    // initialize beginning values of the sequence
    A[0] = 0; 
    A[1] = 1;
    // call helper function to finish sequence
    return fibd(n); 
}

int main(){
    // For testing, copied from assignment
    int n;
    std::cout << "n = ";
    std::cin >> n;
    for(int i=0; i<=n; i++) A[i] = -1;

    auto start = high_resolution_clock::now();
    std::cout << "Fibonacci Recursive: " << FibonacciR(n) << std::endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    std::cout << "Time taken: " << duration.count() << std::endl;

    start = high_resolution_clock::now();
    std::cout << "Fibonacci Dynamic:   " << FibonacciD(n) << std::endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    std::cout << "Time taken: " << duration.count() << std::endl;
}