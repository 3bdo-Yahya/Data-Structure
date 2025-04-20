#include<iostream>
using namespace std;

void fact(int no, int facto)
{
	if (no <= 1)
	{
		//Final computation and returning and restoring address
		cout << "\nThe Factorial is = " << facto;
		return;
	}
	else
	{
		//Partiial computation of the program
		facto = facto * no;
		//Function call to itself, that is recursion
		fact(--no, facto);
	}
}
int main()
{
	int number, factorial;
	//Initialization of formal parameters, local variables and etc.
	factorial = 1;
	cout << "\nEnter the No = ";
	cin >> number;
	//Starting point of the function, which calls itself
	fact(number, factorial);
}