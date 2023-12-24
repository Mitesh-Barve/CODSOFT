//SIMPLE CALCULATOR//
/*Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.*/
#include<iostream>
#include<bits/stdc++>
using namespace std;

int main()
{ 
	long long num1, num2, result;
	cout << "Enter the First number=";
	cin >> num1;

	cout << "Enter the Second number=";
	cin >> num2;

	char operation;
	cout << "Enter the operation=";
	cin >> operation;


	switch (operation)
	{
	case'+':
		result = num1 + num2;
		cout << "Result=" << num1 << "+" << num2 << "=" << result << endl;
		break;

	case'-':
		result = num1 - num2;
		cout << "Result=" << num1 << "-" << num2 << "=" << result << endl;
		break;

	case '/':
		if (num2 != 0) {
			result = num1 / num2;
			cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
		}
		else {
			cout << "Error! Division by zero is not allowed." << endl;
		}
		break;

	case '*':
		result = num1 * num2;
		cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
		break;

	}


	return 0;


}


