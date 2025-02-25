#include <iostream>
using namespace std;
#define CLEAR_SCREEN "cls"
const int MAX_CARS = 100;
string driverNames[MAX_CARS];
int carNumbers[MAX_CARS];
double hoursStayed[MAX_CARS];
string timeSlots[MAX_CARS];
bool reserved[MAX_CARS];
bool vip[MAX_CARS];
int totalCars = 0;
void clearScreen() {
	system(CLEAR_SCREEN);
}
void login() {
	string pass = "";
	cout << "\n\n\n\n\t\t\t\t======Car Parking System Login======";
	cout << "\n\n\n\n\t\t\t\t\tEnter Password ::";
	cin >> pass;
	if (pass == "123") {
		cout << "\n\n\n\n\t\t\t\tAccess Granted ! Welcome to our system \n\n";
		cout << "\t\t\t======================================================";
	} else {
	clearScreen();
		cout << "\n\n\n\n\t\t\t\t  Access Aborted....Please Try again!!\n";
		login();
	}
	clearScreen();
}
void arrival() {
	clearScreen();
	if (totalCars < MAX_CARS) {
		cout << "\n\t\t>)Enter the name of the driver: ";
		cin >> driverNames[totalCars];
		cout << "\t\t>)Enter the car number: ";
		cin >> carNumbers[totalCars];
		cout << "\t\t>)Enter the number of hours of stay: ";
		cin >> hoursStayed[totalCars];
		cout << "\t\t>)Enter the time slot: ";
		cin >> timeSlots[totalCars];
		cout << "\t\t>)Is the parking reserved? (1 for yes, 0 for no): ";
		cin >> reserved[totalCars];
		cout << "\t\t>)Is the driver a VIP? (1 for yes, 0 for no): ";
		cin >> vip[totalCars];
		cout << "\n\t\tCar parked successfully!\n";
		totalCars++;
	} else {
		cout << "\n\t\tSorry, the parking lot is full!\n";
	}
}
void displayAllCars() {
	clearScreen();
	if (totalCars == 0) {
		cout << "\n\t\t\tNo cars parked yet.\n";
	} else {
		cout << "\n\t\t========== All Parked Cars ==========\n";
		for (int i = 0; i < totalCars; ++i) {
			cout << "\n\t\t\tDriver Name: " << driverNames[i] << endl;
			cout << "\t\t\tCar Number: " << carNumbers[i] << endl;
			cout << "\t\t\tHours Stayed: " << hoursStayed[i] << endl;
			cout << "\t\t\tTime Slot: " << timeSlots[i] << endl;
			cout << "\t\t\tReserved: " << (reserved[i] ? "Yes" : "No") << endl;
			cout << "\t\t\tVIP: " << (vip[i] ? "Yes" : "No") << endl;
			cout << "\t\t\t=====================================\n";
		}
	}
}
void calculateCharges() {
	clearScreen();
	if (totalCars == 0) {
		cout << "\n\t\t\tNo cars parked yet.\n";
	} else {
		cout << "\n\t\t========== Calculate Charges ==========\n";
		for (int i = 0; i < totalCars; ++i) {
			double rate = vip[i] ? 20 : 25;
			double charges = hoursStayed[i] * rate;
			cout << "\n\t\t\tDriver Name: " << driverNames[i] << endl;
			cout << "\t\t\tCar Number: " << carNumbers[i] << endl;
			cout << "\t\t\tCharges: " << charges << " rupees" << endl;
			cout << "\t\t=====================================\n";
		}
	}
}
int main() {
	int choice;
	login();
	do {
		cout << "\n\n\t\t======CAR PARKING RESERVATION SYSTEM======";
		cout << "\n\t\t\t=============================\n\t\t\t";
		cout << "1. Arrival of a Car\n\t\t\t";
		cout << "2. Display All Parked Cars\n\t\t\t";
		cout << "3. Calculate Charges\n\t\t\t";
		cout << "4. Exit";
		cout << "\n\t\t\t=============================\n\t\t\t";

		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				arrival();
				break;
			case 2:
				displayAllCars();
				break;
			case 3:
				calculateCharges();
				break;
			case 4:
				cout << "\n\t\t\tExiting the program. Goodbye!\n";
				break;
			default:
				cout << "\n\t\t\tInvalid choice. Please try again.\n";
		}
	} while (choice != 4);
	return 0;
}
