// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. Chua Jia Lin A23CS0069
// 2. Cheryl Cheong Kah Voon A23CS0060

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
using namespace std;


Student::Student(string n="",int cw=0,int fe=0){
			name=n;
			cwMark=cw;
			feMark=fe;
		}
		
int Student::getTotalMark(){
    		return (cwMark+feMark);
		}
		
string Student::getGrade(){
			int totalmark=0;
			totalmark=getTotalMark();
			if (totalmark>=75 && totalmark<=100)
				return "A";
			else if (totalmark>=65 && totalmark<=74)
				return "B";
			else if (totalmark>=50 && totalmark<=64)
				return "C";
			else if (totalmark>=35 && totalmark<=49)
				return "D";
			else
				return "E";
		}
		
void Student::printInfo(){
			cout<<"Name: "<<name<<endl;
			cout<<"Coursework: "<<cwMark<<endl;
			cout<<"Final Exam: "<<feMark<<endl;
		}
		
void Student::printResult(){
			cout<<name<<" "<<getTotalMark()<<" "<<getGrade()<<endl;
		}
		
void Student::printResultFile(fstream& outfile){
				outfile<<name<<" "<<getTotalMark()<<" "<<getGrade();
				outfile<<endl;
		}
		
Student::~Student(){
			cout<<"Destroy student object - "<<name<<endl;
		}


// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];
    
    fstream infile("Mark.txt",ios::in);
    if(!infile){
    	cout<<"File cannot be opened!";
    	return 0;
	}
    	
    fstream outfile("Results.txt",ios::out);
    if(!outfile){
    	cout<<"File cannot be opened!";
    	return 0;
	}
 
    string n=" ";
    int cw=0;
    int fe=0;
    int count=0;
    
	while(!infile.eof()){
		infile>>n>>cw>>fe;
		studList[count]=new Student(n,cw,fe);
		count++;
	}
	infile.close();
	
	cout<<"Student mark info:"<<endl;
	for(int i=0;i<count;i++){
		studList[i]->printInfo();
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"Print and save results to file:"<<endl;
	for(int i=0;i<count;i++){
		studList[i]->printResult();
		studList[i]->printResultFile(outfile);
		delete studList[i];
	}
	outfile.close();
	
    return 0;
}


		