#include <iostream>
#include<sstream>
#include <string>
#include <fstream>


using namespace std;

void listProgram();
void calculator();
bool isNumber(char symbol);
int toInt(string number);
bool validate(string str);
// left trim
string& ltrim(string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

string& rtrim(string& str, const string& chars = "\t\n\v\f\r ")
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

string& trim(string& str, const string& chars = "\t\n\v\f\r ")
{
	return ltrim(rtrim(str, chars), chars);
}


void printArr(int* arr, int size) {
	cout << "{";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << "}" << '\n';
}

int* addElement(int* arr, int& size, int value) {



	int* temparr = new int[size + 1]{};

	for (int i = 0; i < size; i++) {
		temparr[i] = arr[i];
	}

	temparr[size] = value;

	delete[] arr;

	size++;
	return temparr;
}

int* deleteArr(int* arr, int& size, int value) {
	int* delArr = new int[size - 1]{};
	int delSize = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] == value)
			delSize = i;
		else
			continue;
	}

	for (int a = 0; a < size; a++) {
		if (a < delSize)
			delArr[a] = arr[a];
		else if (a > delSize)
			delArr[a - 1] = arr[a];
	}
	size--;
	return delArr;
}

int* delete_i(int* arr, int& size, int index) {
	int* tempArr = new int[size - 1]();


	for (int i = 0; i < size; i++) {
		if (i < index)
			tempArr[i] = arr[i];
		else if (i > index)
			tempArr[i - 1] = arr[i];
	}

	size--;
	return tempArr;
}

int main() {

	string command;
	while (true) {
		cout << "console>";
		getline(std::cin, command);
		trim(command);
		if (command == "list") {
			listProgram();
		}if (command == "calculator") {
			calculator();
		}
		else if (command == "exit") {
			cout << "shutdown";
			exit(0);
		}
	}
	return 0;
}

void listProgram() {

	int size = 0;
	int* numbers = new int [size] {};

	while (true) {
		cout << "console>list>";
		string command;
		cin >> command;

		if (command == "add") {
			int number = 0;
			cout << "console:list>Please add a number:";
			cin >> number;
			cout << "Number successfully added\n";
			numbers = addElement(numbers, size, number);
		}
		if (command == "delete") {
			int value = 0;
			cout << "console:list>Which is a number?:";
			cin >> value;
			cout << "Number successfully deleted\n";
			numbers = deleteArr(numbers, size, value);
		}
		if (command == "delete_i") {
			int index;
			cout << "console>list>Which is a index?:";
			cin >> index;
			cout << "Index successfully deleted\n";
			numbers = delete_i(numbers, size, index);
		}
		if (command == "print") {
			printArr(numbers, size);
		}
		if (command == "exit") {
			break;
		}

	}

	delete[] numbers;
}

void calculator() {

	while (true) {
		cout << "console>calculator>";
		string command;
		getline(std::cin, command);
		trim(command);
		//cout << "{ " << command << " }\n";
		if (command == "exit")
		{
			break;
		}
		validate(command);

	}


}

// <type> <name>;

bool isOperator(char symbol) {

	char symbols[] = { '+', '/', '-', '*' };
	for (int i = 0; i < 10; i++) {
		if (symbol == symbols[i]) {
			return true;
		}
	}
	return false;

}
bool isSpace(char symbol) {
	if (symbol == ' ')
	{
		return true;
	}
	else
		return false;
}

// Validate
// 5 - 22 : - 10 + 55

bool validate(string str) {
	for (int i = 0; i < str.size(); i++)
	{
		char symbol = str[i];
		if (!isNumber(symbol) &&
			!isOperator(symbol) && !isSpace(symbol))
		{
			cout << "error";
			return false;
		}

	}

	return true;
}


bool isNumber(char symbol) {

	char nums[10] = { '1','2','3','4','5','6','7','8','9','0' };

	for (int i = 0; i < 10; i++) {
		if (symbol == nums[i]) {

			return true;
		}
	}
	return false;

}

int toInt(string number) {

	stringstream ss;

	ss << number;

	int result;

	ss >> result;

	return result;

}
