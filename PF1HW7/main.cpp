#include "Animal.h"
#include "AnimalDB.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <set>
#include <string>

void readFile(const string filename, AnimalDB &animals) {
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // declare local temp. class variables for reading data
    int id = 1;
    string type;
    float weight;
    int age;
    float price;
    string extra;
    char dollar;

    while (!din.eof()) {
        // logic for reading in data, ignoring unwanted data
        din >> type >> weight;
        getline(din, extra);
        din >> age;
        getline(din, extra);
        din.get(dollar);
        din >> price;
        getline(din, extra);

        // define new Animal object and insert new animal into Donna's inventory
        Animal newAnimal(id++, type, weight, age, price);
        if (!din.eof())
            animals.insertDonnaAnimal(newAnimal);
    }
    din.close();
}

void writeFile(const string filename2, AnimalDB animals) {
    // open file for output, check if failed
    ofstream dout;
    dout.open(filename2.c_str());

    if (dout.fail()) {
        cout << "Error; file " << filename2 << " could not be opened" << endl;
        return;
    }

    // loop for each index in the userCart array, write data of each Animal object to output file in CSV formats
    for (int i = 0; i < animals.getchoiceNum(); i++) {
        Animal currentAnimal = animals.currentAnimal(i);
        dout << currentAnimal.getID() << ','
        << currentAnimal.getType() << ','
        << currentAnimal.getWeight() << ','
        << currentAnimal.getAge() << ','
        << currentAnimal.getPrice() << ',' << endl;
    }
    dout << ",,,," << animals.cartTotal();
    dout.close();
}

void printMenu() {
    cout << "\nWelcome to Donna's Farm! Here are your choices:"
    << "\n1: Print all animals in Donna's inventory"
    << "\n2: Print your current shopping cart"
    << "\n3: Print animals of a certain type"
    << "\n4: Print animals within a range of weight"
    << "\n5: Print animals within a range of age"
    << "\n6: Add an animal to your shopping cart"
    << "\n7: Print your current shopping cart total"
    << "\n8: Complete your order, print receipt and exit the program\n";
}

char getUserChoice() {
    char userChoice = '\0';

    do {
        cout << "\nEnter menu selection: ";
        cin >> userChoice;
        if (userChoice < '1' || userChoice > '8')
            cout << "\nError: invalid input. Please try again." << endl;
    } while (userChoice < '1' || userChoice > '8');

    return userChoice;
}

int main() {
    //you will be writing this code!
    //Declaring object
    AnimalDB object;
    
    //Declaring files
    string filename = "donnaInventory.txt";
    string filename2 = "receipt.txt";
    
    //Read file
    readFile(filename, object);
    
    //Declaring switch
    char c = '0';
    
    

    string type1;
    //Age varibles
    int minAge, maxAge;
    minAge = 0;
    maxAge = 0;
    //Weight variables
    
    float minWeight, maxWeight;
    minWeight = 0;
    maxWeight = 0;
    
    int id;
    char again;
    
    //Do this switch case while input is between 1 and 8
    do {
        printMenu();
        c = getUserChoice();
        switch(c) {
            //Prints all of Donna's inventory
            case '1':
                cout << "Inventory:" << endl; 
                object.inventoryPrint();
                break;
            
            //Prints all of shopping cart
            case '2':
                cout << "Your Shopping Cart:" << endl;
                object.cartPrint();
                break;
            
            //Sorts animals by type
            case '3':
                cout << "Enter the type of animal would you like to see from the following?" << endl;
                cout << "Rooster," << " " << "Horse," << " " << "Goat," << " " << "Cow," << " " << "Mule," << " " << "Turkey," << endl
                     << "Donkey," << " " << "Pig," << " " << "Duck," << " " << "Sheep," << " " << "Chicken,"  << " " << "and Rabbit" << endl;
                cin >> type1;
                type1[0] = toupper(type1[0]);
                object.animalTypePrint(type1);
                break;
            
            //Sorts animals in certain weight range
            case '4':
                cout << "Enter a minimum weight number for your desired weight range." << endl;
                cin >> minWeight;
                while(minWeight < 0) {
                    cout << "Enter a minimum weight number for your desired weight range." << endl;
                    cin >> minWeight;
                }
                cout << "Enter a maximum weight number for your desired weight range." << endl;
                cin >> maxWeight;             
                while(maxWeight < minWeight) {
                    cout << "Enter a maximum weight number for your desired weight range." << endl;
                    cin >> maxWeight;
                }

                object.animalWeightPrint(minWeight, maxWeight);
                break;
            
            //Sorts animals in certain age range
            case '5':
                
                cout << "Enter a minimum age number for your desired age range." << endl;
                cin >> minAge;
                while(minAge < 0) {
                    cout << "Enter a minimum age number for your desired age range." << endl;
                    cin >> minWeight;
                }
                cout << "Enter a maximum age number for your desired age range." << endl;
                cin >> maxAge;
                while(maxAge < minAge) {
                    cout << "Enter a minimum age number for your desired age range." << endl;
                    cin >> minWeight;
                }
                object.animalAgePrint(minAge, maxAge);
                break;
            
            //Adds animals to shopping cart
            case '6':
                do {
                    cout << "Which animal would you like to add to your cart? (Enter an ID #)" << endl;
                    cin >> id;
                    while((id > 100) || (id < 0)) {
                        cin >> id;
                    }
                    id--;
                    if(id < object.setUserAnimal(id)) {
                        object.animalIDPrint(id);
                    
                    }
                    cout << "Would you like to add another?" << endl;
                    cin >> again;
                    again = tolower(again);
                    while((again != 'n') && (again != 'y')) {
                        cout << "Input a valid character. (y/n)" << endl;
                        cin >> again;
                        again = tolower(again);
                    }
                } while(again == 'y');
                    break;
            
            //Prints total shopping cart amount
            case '7':
            
                cout << "Shopping cart Total:" << endl;
                cout << fixed << setprecision(2) << object.cartTotal();
                break;
            
            //Writes receipt
            case '8':
            
                cout << "Order Completed." << endl;
                writeFile(filename2, object);
                break;
        }
            
    }while((c >= '1') && (c < '8'));
    return 0;
}
