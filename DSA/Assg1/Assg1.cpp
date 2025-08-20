// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. Cheryl Cheong Kah Voon A23CS0060
// 2. Chua Jia Lin A23CS0069
// 3. Gui Kah Sin A23CS0080

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// function headers
void listStudent(Student* [], int);
void sortByName(Student* [],int);
void sortByGrade(Student* [],int);

// main function
int main() {
    const int LIST_SIZE = 10;
    string name;
    int cw, fe, idx = 0;
    Student* studList[LIST_SIZE];

    fstream fileIn("Marks.txt", ios::in);

    if (!fileIn) {
        cout << "File input/output error!\n";
        return 1;

    } else {
        while (fileIn >> name >> cw >> fe) {
            studList[idx] = new Student(name, cw, fe);
            idx++;
        }
        
        int opt = 0;

        while (opt != 4) {
            cout << "\n1. List results (original list)";
            cout << "\n2. List results (sort by name)";
            cout << "\n3. List results (sort by grade)";
            cout << "\n4. Exit\n\n";
            
            cout << "Enter your choice [1, 2, 3, 4]: ";
            cin >> opt;
            
            if (opt == 1) {
                listStudent(studList, idx);
            }
            
            else if (opt == 2) {
            	sortByName(studList, idx);
                listStudent(studList, idx);
            }
            
            else if (opt == 3) {
            	sortByGrade(studList, idx);
                listStudent(studList, idx);
            }
            
            if (opt != 4) system("pause");
        }

        fileIn.close();
    }

    return 0;
}

// function implementation
void listStudent(Student* sl[], int size) {
    for (int i = 0; i < size; i++) {
        sl[i]->printResult();
    }
}

void sortByName(Student* sl[],int size){
	bool sorted=false;
	for(int pass=1;pass<size && !sorted;pass++){
		sorted=true;
		for(int i=0;i<size-pass;i++){
			if(sl[i]->getName()>sl[i+1]->getName()){
				Student *temp=sl[i];
				sl[i]=sl[i+1];
				sl[i+1]=temp;
				sorted=false;
			}
		}
	}
}

void sortByGrade(Student* sl[],int size){
	bool sorted=false;
	for(int pass=1;pass<size && !sorted;pass++){
		sorted=true;
		for(int i=0;i<size-pass;i++){
			if(sl[i]->getGrade()>sl[i+1]->getGrade() || (sl[i]->getGrade()==sl[i+1]->getGrade()) && (sl[i]->getName()>sl[i+1]->getName())){
				Student *temp=sl[i];
				sl[i]=sl[i+1];
				sl[i+1]=temp;
				sorted=false;
			}
		}
	}
}






