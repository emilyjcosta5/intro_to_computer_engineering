#include <stdlib.h>  
#include <bits/stdc++.h>
#include <stdio.h>

int hash_function(int key, int table_size){
    return key%table_size;
}

void fill_table(int data[], int data_size, int table_size){
    int hash_table[table_size] = {0};
    int key;
    int hash;
    for(int i=0;i<data_size;i++){
        hash = hash_function(data[i], table_size);
        hash_table[hash]++;
    }
    // Find the min and max collisions, mean of collisions
    int min = INT_MAX, max = INT_MIN;
    int total = 0;
    for (int i: hash_table){
        i--;
        if (i < min) min = i;
        if (i > max) max = i;
        total += i;
    }
    double mean = (double)total/(double)table_size;
    // Find variance of collisions
    int sq_df = 0;
    for (int i: hash_table){
        i--;
        sq_df += (i-mean)*(i-mean);
    }
    double variance = (double)sq_df/(double)table_size;
    std::cout << "Table Size: " << table_size << std::endl;
    std::cout << "Minimum Collisions: " << min << std::endl;
    std::cout << "Maximum Collisions: " << max << std::endl;
    std::cout << "Average Collisions: " << mean << std::endl;
    std::cout << "Variance of Collisions: " << variance << std::endl;
}

int main(){
    // Generate random data
    int bdays[1000] = {0};
    int month = 0;
    int day = 0;
    int year = 0;
    for(int i=0;i<1000;i++){
        month = (rand()%12+1)*10000; // Jan-Dec
        day   = (rand()%28+1)*100;   // 1-28
        year  = rand()%5;            // 2000-2004
        bdays[i] = month+day+year;
    }
    // Size of the Tables
    int m_1 = 97;
    int m_2 = 98;
    int m_3 = 100;
    int m_4 = 101;
    // Run experiments
    fill_table(bdays, 1000, m_1);
    fill_table(bdays, 1000, m_2);
    fill_table(bdays, 1000, m_3);
    fill_table(bdays, 1000, m_4);
    return 0;
}


