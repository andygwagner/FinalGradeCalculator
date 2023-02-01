#include<iostream>
#include<string>

using namespace std;

double findPercent(string);
double findEarned(string, double, double);

int main() {
	string Name;
	string Catagories[5] = { "Homework", "Exam", "Inclass Assignment", "Quiz", "Lab" };
	double Weight[5] = { 0, 0 , 0 , 0 , 0 };
	double Percents[5] = { 0, 0 , 0 , 0 , 0 };
	double Earned[5] = { 0, 0 , 0 , 0 , 0 };

	int looper = 0;
	char option;

	double temp1 = 0;
	double temp2 = 0;
	double Final = 0;

	cout << "Enter Class Name: ";
	getline(cin, Name);
	for (int i = 0; i < 5; i++) {
		cout << "What % of the final grade does the " << Catagories[i] << " equal?: ";
		cin >> Weight[i];
	}

	while (looper == 0) {
		cout << "MENU" << endl <<
			"h - Add homework grades" << endl <<
			"e - Add exam grades" << endl <<
			"a - Add inclass assignment grades" << endl <<
			"q - Add quiz grades" << endl <<
			"l - Add lab grades" << endl <<
			"t - Calculate total grade" << endl <<
			"0 - exit" << endl;
		cin >> option;
		switch (option) {
		case 'h':
			Percents[0] = findPercent(Catagories[0]);
			cout << "Total Homework Percent Earned: " << Percents[0] * 100 << endl;
			break;
		case 'e':
			Percents[1] = findPercent(Catagories[1]);
			cout << "Total Exam Percent Earned: " << Percents[1] * 100 << endl;
			break;
		case 'a':
			Percents[2] = findPercent(Catagories[2]);
			cout << "Total Inclass Assignment Percent Earned: " << Percents[2] * 100 << endl;
			break;
		case 'q':
			Percents[3] = findPercent(Catagories[3]);
			cout << "Total Quiz Percent Earned: " << Percents[3] * 100 << endl;
			break;
		case 'l':
			Percents[4] = findPercent(Catagories[4]);
			cout << "Total Lab Percent Earned: " << Percents[4] * 100 << endl;
			break;
		case 't':
			for (int i = 0; i < 5; i++) {
				Earned[i] = findEarned(Catagories[i], Percents[i], Weight[i]);
			}

			for (int i = 0; i < 5; i++) {
				temp1 = temp1 + Earned[i];
				temp2 = temp2 + Weight[i];
				Final = temp1 / temp2;
			}
			cout << "Your final grade for " << Name << " is: " << Final * 100 << endl;
			break;
		case '0':
			looper = 1;
			break;
		}
	}

	return 0;
}

double findPercent(string s) {
	double arr[20];
	int Weight;
	int looper = 0;
	int counter = 0;
	double temp;
	double total = 0;

	cout << "Enter " << s << " Weight: ";
	cin >> Weight;
	cout << "Enter " << s << " Grades (exit using negative nummber): ";
	while (looper == 0) {
		cin >> temp;
		if (temp >= 0) {
			arr[counter] = temp;
			total = total + temp;
			counter++;
		}
		else {
			looper = 1;
		}
	}

	Weight = Weight * counter;
	double Percent = total / Weight;
	cout << s << " total is: " << total << endl;
	cout << "Total " << s << " Weight: " << Weight << endl;

	return Percent;
}

double findEarned(string s, double p, double f) {
	double earned = 0;
	earned = p * f;
	cout << "Final " << s << " Points earned: " << earned << "/" << f << endl;
	return earned;
}