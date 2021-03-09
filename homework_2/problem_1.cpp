// Implement a merge-sort algorithm
// Goal: learn merge-sort
// Created on: Feb 8, 2021
// Author: Emily Costa

#include <iostream>
#include <math.h>
#include <random>
#include <climits>

void print_array(int A[], int p, int r){
    for (int i = p; i < r+1; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

bool check_array_sort(int A[], int p, int r){
    // check for unsorted
    for (int i = p; i < r; i++)
        if (A[i] > A[i+1])
            return false;
    return true;
}

void merge(int A[], int p, int q, int r){
    // Merge two arrays that are sorted.
    // Check if already sorted.
    if(!check_array_sort(A, p, r)){
        // Create the pointers
        int n_1 = q-p+1;
        int n_2 = r-q;
        // Create new temporary arrays
        int L[n_1+1], R[n_2+1];
        // Fill with data from array A
        for(int i=0; i<n_1; i++) L[i]=A[p+i];
        for(int j=0; j<n_2; j++) R[j]=A[q+j+1];
        // Add a sentinal value of inf to end of each temporary array
        L[n_1] = INT_MAX;
        R[n_2] = INT_MAX;
        // Pointers to start of new arrays
        int i = 0;
        int j = 0;
        // Now do the sort
        for(int k=p; k<r+1; k++){
            if(L[i]<R[j]){
                A[k]=L[i];
                i++;
            }
            else{
                A[k]=R[j];
                j++;
            } 
        }
    }
    else{
        std::cout << "Already sorted subarray: ";
        print_array(A, p, r);
    }
}

void merge_sort(int A[], int p, int r){
    // Breakdown the array and sort recursively.
    if(p<r){
        int q = floor((p+r)/2);
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        //std::cout << "p= " << p << "\nq=" << q << "\nr= " << r << std::endl;
        merge(A, p, q, r);
    }
}

int main(){
    int n;
    std::cout << "Input the number of integers in A, n: ";
    std::cin >> n;
    int A[n];

    // Create random array
    for (int i = 0; i < n; i++) A[i]=rand()%100;
    // Print array before sort
    std::cout << "Array before mergesort:  ";
    int size_A = sizeof(A)/sizeof(A[0]);
    print_array(A, 0, size_A-1);
    //for (size_t i=0; i<size_A; i++) std::cout << A[i] << " ";
    // Sort array
    merge_sort(A, 0, n-1);
    // Print array after sort
    std::cout << "Array after mergesort:   ";
    print_array(A, 0, size_A-1);
    std::cout << std::endl;
    //merge_sort(A, 0, n-1);
    return 0;
}