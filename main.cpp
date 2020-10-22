#include "GenStack.h"
#include "ReadFile.h"
#include <iostream>
#include <string>
using namespace std;


int main (int argc, char* argv[]) {
	string input;
	if (argc > 1) {
		cout << "Opening: " << argv[1] << endl;
		input = argv[1];
	}
	else {
		cout << "Enter File Name: " <<endl;		// used in case of no file name recieved from terminal
		cin >> input;
	}
	
	bool secondRun = false;
	bool bal = true;
	while (bal==true) {
		if (secondRun == true) {
			cout << "Enter File Name: "<<endl;
			cin >> input;
		}
		GenStack<char> stack;
		ReadFile file;
		bal = file.checkBalance(input, stack);
		if (file.getExit()==false) {					//exit program in case of being unable to open file
			return 0;
		}
		if (bal==false) {							//exit program in case of file not being balanced
			break;
		}
		cout << "Balanced!" <<endl;
		cout << "Would you like to check another file? Y/N" << endl;	//prompt to run program again
		char again;
		cin >> again;
		if (again == 'N' || again == 'n') {			//exit program if no need to read another file
			return 0;
		}
		secondRun = true;
	}
	cout << "Not Balanced!" <<endl;
	return 0;
}



