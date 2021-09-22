#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int first_line;
	int second_line;
	int third_line;
	int fourth_line;

	cin  >> a >> b >> c;

	first_line = (a + b) % c;
	second_line = ((a % c) + (b % c)) % c;
	third_line = (a * b) % c;
	fourth_line = ((a % c) * (b % c)) % c;

	cout << first_line << "\n";
	cout << second_line  << "\n";
	cout <<  third_line << "\n";
	cout << fourth_line << "\n";

}
