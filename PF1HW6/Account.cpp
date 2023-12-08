#include "Account.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

Account::Account(const string firstNameIn, const string lastNameIn, const string PINIn, const string accountNumberIn) { //Constructor
    firstName = firstNameIn;
    lastName = lastNameIn;
    PIN = PINIn;
    accountNumber = accountNumberIn;
}

Account::Account(const Account & copy) { //Copy constructor
    firstName = copy.firstName;
    lastName = copy.lastName;
    PIN = copy.PIN;
    accountNumber = copy.accountNumber;
}

Account::~Account() { //Destructor

}

void Account::print() const { //Print method
    cout << firstName << " " << lastName << " " << PIN << " " << accountNumber << endl;
}

string Account::getFirstName() const { //Getters
    return firstName;
}

string Account::getLastName() const {
    return lastName;
}

string Account::getPIN() const {
    return PIN;
}

string Account::getAccountNumber() const {
    return accountNumber;
}

void Account::setFirstName(const string firstNameIn) { //Setters
    firstName = firstNameIn;
}

void Account::setLastName(const string lastNameIn) {
    lastName = lastNameIn;
}

void Account::setPIN(const string PINIn) {
    PIN = PINIn;
}

void Account::setAccountNumber(const string accountNumberIn) {
    accountNumber = accountNumberIn;
}
