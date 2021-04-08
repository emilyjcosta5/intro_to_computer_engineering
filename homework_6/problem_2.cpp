#include <math.h>
#include <iostream>
#include <chrono>
using namespace std::chrono;

int max(int a, int b){ 
    return (a > b)? a : b;
}

int price(int l, int rod_size){
    int price;
    if(l==1) price = 1;
    else if(l<rod_size) price = floor(double(l)*2.5);
    else price = double(l)*2.5-1;
    return price;
}

int CutRodR(int rod_size){
    int result = 0;
    for(int l=0; l<rod_size; l++) 
        result = max(result, price(l, rod_size)+CutRodR(rod_size-l-1));
    return result;
}

int CutRodD(int rod_size){
    int results[rod_size+1];
    results[0] = 0;
    for(int i=1; i<=rod_size; i++){
        int result = 0;
        for(int j=0; j<i; j++)
            result = max(result, price(j, rod_size)+results[i-j-1]);
        results[i] = result;
    }
    return results[rod_size];
}

int main(){
    int test_cases[] = {5,10,15,20,25,30,35,40,45,50};
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    for(int i=0; i<10;i++){
        std::cout << "Rod Size: " << test_cases[i] << std::endl;
        std::cout << "----------" << std::endl;
        start = high_resolution_clock::now();
        std::cout << "Recursive Max Revenue: " << CutRodR(test_cases[i]) << std::endl;
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop-start);
        std::cout << "Recursive Time: " << duration.count() << std::endl;
        std::cout << std::endl;
    }
    for(int i=0; i<10;i++){
        std::cout << "Rod Size: " << test_cases[i] << std::endl;
        std::cout << "----------" << std::endl;
        start = high_resolution_clock::now();
        std::cout << "Dynamic Max Revenue: " << CutRodD(test_cases[i]) << std::endl;
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop-start);
        std::cout << "Dynamic Time: " << duration.count() << std::endl;
        std::cout << std::endl;
    }
}
