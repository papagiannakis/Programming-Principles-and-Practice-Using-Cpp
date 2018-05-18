//written by Jtaim
//date 24 Sept 2015
//updated 10 Dec 2016
//Programming: Principles and Practice Using C++ Second Edition

/*
Section 4 Drill step 4.
1. Write a program that consists of a while-loop that (each time around the loop)
   reads in two int numbers and then prints them. Exit the program when a terminating '|' is entered.
2. Change the program to write out the smaller value is: followed by the smaller of the
   numbers and the larger value is: followed by the larger value.
3. Augment the program so that it writes the line the numbers are equal (only) if they are equal.
4. Change the program so that it uses double instead of int.
*/

#include "section4.h"	//custom header

int main()
{
	using namespace std;
	const char terminationChar = '|';	//termination character
	const int howMany = 2;				//numbers to get per loop iteration

	double enteredNumber;
	vector<decltype(enteredNumber)> enteredNumbers;
	bool stop{ false };
	while (!stop)
	{
		cout << "Enter two numbers. Enter " << terminationChar << " to exit.\n";
		for (int itr = 0; itr < howMany; ++itr)
		{
			if (cin >> enteredNumber) {
				enteredNumbers.push_back(enteredNumber);
			}
			else {	//check for valid termination
				cin.clear();	//clear cin errors
				char c;
				cin >> c;
				if (c == terminationChar) {
					enteredNumbers.clear();
					stop = true;
					break;
				}
				else {
					simple_error("invalid number entry");
				}
			}
		}
		// print numbers if valid
		if (!stop) {
			cout << "Entered numbers: ";
			for (auto i : enteredNumbers) {
				cout << i << " ";
			}
			cout << endl;
			sort(enteredNumbers.begin(), enteredNumbers.end());
			if (enteredNumbers.front() == enteredNumbers.back()) {
				cout << "The entered numbers are equal.\n";
			}
			else {
				cout << "smaller value is: " << enteredNumbers.front() << endl;
				cout << "larger value is: " << enteredNumbers.back() << endl;
			}
		}
		//clear vector for next set of numbers
		enteredNumbers.clear();
	}
	cout << "Bye\n";
	keep_window_open();
	return 0;
}