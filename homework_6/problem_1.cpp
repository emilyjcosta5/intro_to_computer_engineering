#include <iostream>

int A[50];

int FibonacciR(int n){
    if (n <= 1)
        return n;
    return FibonacciR(n-1) + FibonacciR(n-2);
}

int FibonacciD(int n){
    A[0] = 0;
    A[1] = 1;
    return _fibd(n); 
}

int _fibd(int n){
    if (n < 2) {
      return n;
    }
    // if we have already solved this subproblem, simply return the result from the cache
    if(A[n] != -1)
      return A[n];
    A[n] = FibonacciD(n-1) + FibonacciD(n-2);
    return A[n];
}

int main(){
    int n;
    std::cout << "n = ";
    std::cin >> n;

    for(int i=0; i<=n; i++) A[i] = -1;

    FibonacciR(n);
    FibonacciD(n);
}