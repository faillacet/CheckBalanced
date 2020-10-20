#include "GenStack.h"
#include "ReadFile.h"
#include <iostream>
#include <string>
using namespace std;


int main (int argv, char* argc[]) {
	string input;
	cout << "Enter File Name: " <<endl;
	cin >> input;

	GenStack<char> stack;
	ReadFile file;
	
	bool secondRun = false;
	bool bal = true;
	while (bal==true) {
		if (secondRun == true) {
			cout << "Enter File Name: "<<endl;
			cin >> input;
		}
		bal = file.checkBalance(input, stack);
		if (bal==false) {
		break;
		}
		cout << "Balanced!" <<endl;
		cout << "Would you like to check another file? Y/N" << endl;
		char again;
		cin >> again;
		if (again == 'N' || again == 'n') {
			return 0;
		}
		secondRun = true;
	}
	cout << "Not Balanced!" <<endl;
	return 0;
}



