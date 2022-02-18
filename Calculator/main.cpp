#include <iostream>
using namespace std;

double readNumbers(string name) {
	double number;

	cout << "Введите " << name << " число: ";
	cin >> number;

	return number;
}

char readOperation() {
	char operation;

	cout << "Введите числовую операцию (+, -, *, /): ";
	cin >> operation;

	return operation;
}

int findErrors(char operation, double secondNumber) {
	int error;
	switch (operation)
	{
	case '+': {
		error = 0;
		break;
	}

	case '-': {
		error = 0;
		break;
	}

	case '*': {
		error = 0;
		break;
	}

	case '/': {
		error = (secondNumber == 0 ? 1 : 0);
		break;
	}

	default: {
		error = 2;
		break;
	}
	}

	return error;
}

double calculateResult(double firstNumber, double secondNumber, char operation) {
	double result{};

	switch (operation)
	{
	case '+' : {
			result = firstNumber + secondNumber;
			break;
		}

	case '-': {
		result = firstNumber - secondNumber;
		break;
	}
	case '*': {
		result = firstNumber * secondNumber;
		break;
	}
	case '/': {

		result = firstNumber / secondNumber;
		break;
	}
	default:
		result = 0;
		break;
	}

	return result;
}

void writeResult(double firstNumber, double secondNumber, char operation, double result) {
	cout << firstNumber << operation << secondNumber << "=" << result ;
}

void writeError(int error) {
	if (error == 1) {
		cout << "Нельзя делить на 0!";
	} else {
		cout << "Введённая операция некорректна";
	}
}

void main() {
	setlocale(LC_ALL, "Russian");

	double firstNumber = readNumbers("первое");
	double secondNumber = readNumbers("второе");
	char operation = readOperation();

	int error = findErrors(operation, secondNumber);

	if (error == 0) {
		double result = calculateResult(firstNumber, secondNumber, operation);
		writeResult(firstNumber, secondNumber, operation, result);
	}
	else {
		writeError(error);
	}
}