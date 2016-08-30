//James Robertson, CS 1337.503
//	Yeah don't copy this it's pretty busted
//Started on 8/29/2016


//am I allowed to import this much stuff?
#include <iostream>;
#include <string>;
#include <iomanip>;

using namespace std;

bool DefineInputIntegrity(string);

//I seriously didn't know how classes in C++ work until I started this
//Why not just use a class to hold all my stuff in it?
class Company {
	string month;
	int year;
	float income;
	float taxArray[3];

public:
	Company(string, int, float);
	void CalculateTaxes();
	void Output();
};

Company::Company(string s, int y, float in){
	month = s;
	year = y;
	income = in;
}

void Company::CalculateTaxes() {
	taxArray[0] = income * 0.065;
	taxArray[1] = income * 0.0275;
	taxArray[2] = taxArray[0] + taxArray[1];
}

void Company::Output() {
	cout << "\n\n\t" << month << " " << year << endl;
	cout << "---------------------------" << endl;
	cout << "Sales for this month:  " << income << endl;
	cout << "Total:                 " << taxArray[2] + income << endl << endl;
	cout << "County Sales Tax:      " << taxArray[1] << endl;
	cout << "State Sales Tax:       " << taxArray[0] << endl;
	cout << "Total of Tax:          " << taxArray[2] << endl;
}


int main() {
	//Yeah I know, while(true) is scary but I don't care
	while (true) {
		//Input is re-declared every loop to prevent any type of carry over from the past iteration
		string validationInput;
		string s;
		int y;
		float in;

		cout << "\nPlease enter a month (string)" << endl;
		cin >> s;
		cout << "\nPlease enter the year (integer)" << endl;
		cin >> y;
		cout << "\nPlease enter the income for the month (float)" << endl;
		cin >> in;

		//We even start a new company every iteration
		Company foo(s, y, in);
		
		foo.CalculateTaxes();
		foo.Output();
		
		// --> Foo the entrepreneur
		cout << "\n\nWould you care to calculate another month? [y/n]" << endl;
		cin >> validationInput;

		DefineInputIntegrity(validationInput);

		if (validationInput.compare("n") == 0) {
			break;
		}
	}

	cout << "\nThanks for using the great program" << endl;

	cin.clear();
	cin.ignore(256,'\n'); //Actually let the user look at the program's output before it closes

    return 0;
}

//I never thought I would willingly use recursion after I left APCS, oh what have I become
bool DefineInputIntegrity(string inputIntegrity) {
	if (inputIntegrity.compare("y") == 0 || inputIntegrity.compare("n") == 0) {
		return true;
	}
	else {
		cout << "Please input y or n, it's not that hard" << endl;
		cin >> inputIntegrity;

		DefineInputIntegrity(inputIntegrity);
	}
}

/*
Try entering a letter into the year input
in all honesty, c++ is more than robust enough that I don't need a try catch block
	since I don't want to throw exceptions all over the place ---> http://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input
	that is a input validation function that should work

TODO: input validation for the program input
	  rounding numbers - yeah idk how to do that, cout.setprecision may work, if you can find out the number of digits in a number then add 2 :^)
	  really just that infinite loop when you enter a string into the year input, idk why it does that only there

*/