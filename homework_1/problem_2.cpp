// Goal: Learn I/O in CPP and dynamic memory.
// Created on: Jan 28, 2021
// Author: Emily Costa

#include <iostream>

void print_avg_grades(int *grades, int class_size){
    int *p;
    int sum;
    for(p=grades; p<grades+class_size; p++) sum += *p;
    std::cout << "Average grade in class: " << sum/class_size << "\n";
}

void print_top_student(int *grades, std::string *names, int class_size){
    int top_grade = 0;
    std::string top_student = "";
    for(int i=0; i<class_size; i++){
        if(*(grades+i)>top_grade){
            top_grade = *(grades+i);
            top_student = *(names+i);
        }
    }
    std::cout << "The top student, " << top_student << ", has grade " << top_grade << "\n";
}

void print_failing_students(int *grades, std::string *names, int class_size){
    std::cout << "The name and grade of students with grade <50: \n";
    for(int i=0; i<class_size; i++){
        if(*(grades+i)<50) std::cout << "Name: " << *(names+i) << ", Grade: " << *(grades+i) << "\n";
    }
}

void print_names_with_a(int *grades, std::string *names, int class_size){
    std::cout << "The name and grade of students with last names that start with 'a': \n";
    for(int i=0; i<class_size; i++){
        if((*(names+i)).find("a")==0 || (*(names+i)).find("A")==0) std::cout << "Name: " << *(names+i) << ", Grade: " << *(grades+i) << "\n";
    }
}

int main(){
    int class_size;
    std::cout << "Teacher, what is the number of students in your class?" << "\n";
    std::cin  >> class_size;
    std::string *names = new std::string [class_size];
    int *grades = new int(class_size);
    for(int i=0; i<class_size; i++){
        std::cout << "Enter last name of student " << i << ":\n";
        std::cin  >> names[i];
        std::cout << "Enter grade (0-100) of student " << i << ":\n";
        std::cin  >> grades[i];
    }
    print_avg_grades(grades, class_size);
    print_top_student(grades, names, class_size);
    print_failing_students(grades, names, class_size);
    print_names_with_a(grades, names, class_size);
}