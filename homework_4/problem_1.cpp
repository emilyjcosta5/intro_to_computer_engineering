// Created on: Mar 8, 2021
// Author: Emily Costa

#include<chrono>
#include<iostream>
#include<fstream>
#include<stdexcept>
using namespace std;

int moves;
int comps;

/****************************************************************************************/

// Utility Functions.
void swap(int* x, int* y){
    moves++; // add when swap, or "movement", occurs.
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

bool check_sorted(int A[], int n){
    if (n == 1 || n == 0)
        return true;
    if (A[n-1] < A[n-2])
        return false;
    return check_sorted(A, n-1);
}

void print_array(int A[], int n){
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    std::cout <<std::endl;
}

/****************************************************************************************/

// Implemented Insertion Sort algorithm.
void insertion_sort(int A[], int n){ 
    int key, i; 
    for (int j=1; j<n; j++){ 
        key = A[j]; 
        i = j-1; 
        comps++; // initial comparison
        while(i>=0 && A[i]>key){ 
            comps++; // comparing A[i] to key
            A[i+1] = A[i]; 
            i = i-1; 
        } 
        if(i!=j-1) moves++; // check if an insert occurs, or "movement"
        A[i+1] = key; 
    } 
} 

/****************************************************************************************/

// Implemented Heap Sort algorithm.
void max_heapify(int A[], int n, int i){
    int largest;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && A[l]>A[i]) largest = l;
    else largest=i;
    comps++; // comparing A[l] and A[i]
    if(r<n && A[r]>A[largest]) largest = r;
    comps++; // comparing A[r] and A[largest]
    if(largest!=i){
        swap(&A[i], &A[largest]);
        max_heapify(A, n, largest);
    }
}
 
void heap_sort(int A[], int n){
    // Build Heap with initial.
    for(int i=n/2-1; i>=0; i--)
        max_heapify(A, n, i);
    for(int i=n-1; i>0; i--) {
        swap(&A[0], &A[i]);
        max_heapify(A, i, 0);
    }
}

/****************************************************************************************/

// Implemented Quick Sort algorithm.
int partition (int A[], int p, int r){
    int x = A[r]; 
    int i = p-1;
    for (int j=p; j<=r-1; j++){
        // Move element if smaller or equal to the pivot, x.
        comps++; // Initial comparison
        if (A[j]<=x){
            comps++; // comparing element with pivot.
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[r]);
    return (i+1);
}


void quick_sort(int A[], int p, int r){
    if (p<r){
        comps++; // comparing the high and low, p and r.
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

/****************************************************************************************/

int main(){
    // Generate our arrays
    int n = 1000; // size of arrays
    // Generate BST array
    int bst[n];
    for(int i=0;i<n;i++) bst[i] = i+1;
    // Generate AVG array
    srand(time(NULL));
    int avg[n];
    for(int i=0;i<n;i++) avg[i] = rand()%100000;
    // Generate WST array
    int wst[n];
    int j = n;
    for(int i=0;i<n;i++) wst[i] = j--;

    //print_array(bst, n);
    //print_array(avg, n);
    //print_array(wst, n);

    // Temporary array for copying the arrays and unning the sorts.
    int tmp[n];

    // Open file to output the results.
    ofstream outf;
    outf.open("sort.txt");
    if(outf.fail()){
        cerr << "Error: Could not open output file\n";
        exit(1);
    }

    // Add column names to file
    outf << "Sort,Case,Moves,Comparisons" << std::endl;

    // 1. Run Insertion Sort
    //    a. Best case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = bst[i];
    insertion_sort(tmp, n);
    if(check_sorted(tmp, n)) outf << "Insertion,Best," << moves << "," << comps << std::endl;
    else std::cout << "Insertion Sort not sorting" << std::endl;
    //    b. Average case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = avg[i];
    insertion_sort(tmp, n);
    if(check_sorted(tmp, n)) outf << "Insertion,Average," << moves << "," << comps << std::endl;
    else std::cout << "Insertion Sort not sorting" << std::endl;
    //    c. Worst case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = wst[i];
    insertion_sort(tmp, n);
    if(check_sorted(tmp, n)) outf << "Insertion,Worst," << moves << "," << comps << std::endl;
    else std::cout << "Insertion Sort not sorting" << std::endl;

    // 2. Run Heap Sort
    //    a. Best case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = bst[i];
    heap_sort(tmp, n);
    if(check_sorted(tmp, n)) outf << "Heap,Best," << moves << "," << comps << std::endl;
    else std::cout << "Heap Sort not sorting" << std::endl;
    //    b. Average case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = avg[i];
    heap_sort(tmp, n);
    if(check_sorted(tmp, n)) outf << "Heap,Average," << moves << "," << comps << std::endl;
    else std::cout << "Heap Sort not sorting" << std::endl;
    //    c. Worst case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = wst[i];
    heap_sort(tmp, n);
    if(check_sorted(tmp, n)) outf << "Heap,Worst," << moves << "," << comps << std::endl;
    else std::cout << "Heap Sort not sorting" << std::endl;

    // 3. Run Quick Sort
    //    a. Best case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = bst[i];
    quick_sort(tmp, 0, n-1);
    if(check_sorted(tmp, n)) outf << "Quick,Best," << moves << "," << comps << std::endl;
    else std::cout << "Quick Sort not sorting" << std::endl;
    //    b. Average case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = avg[i];
    quick_sort(tmp, 0, n-1);
    if(check_sorted(tmp, n)) outf << "Quick,Average," << moves << "," << comps << std::endl;
    else std::cout << "Quick Sort not sorting" << std::endl;
    //    c. Worst case
    moves = 0;
    comps = 0;
    for(int i=0;i<n;i++) tmp[i] = wst[i];
    quick_sort(tmp, 0, n-1);
    if(check_sorted(tmp, n)) outf << "Quick,Worst," << moves << "," << comps << std::endl;
    else std::cout << "Quick Sort not sorting" << std::endl;

    outf.close();
    return 0;
}