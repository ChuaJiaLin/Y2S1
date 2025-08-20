// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. Chua Jia Lin A23CS0069
// 2. Cheryl Cheong Kah Voon A23CS0060

#include <iostream>
#include <string>

using namespace std;

// Class defintion
class Student {
    private:
    	string name;
    	int cwMark;
    	int feMark;
    public:
    	Student(string,int,int);
    	int getTotalMark();
    	string getGrade();
    	void printInfo();
    	void printResult();
    	void printResultFile(fstream&);
    	~Student();
};
