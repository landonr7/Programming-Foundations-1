#include "AnimalDB.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//Constructors
AnimalDB::AnimalDB() {
    
    numA = 0;
    choiceNum = 0;
    
}
//    Animal(const int &IDIn, const string typeIn, const float &weightIn, const int &ageIn, const float &priceIn)

//Copy constructor
AnimalDB::AnimalDB(const AnimalDB & copy) {
    
    numA = copy.numA;
    choiceNum = copy.choiceNum;
    
    for(int i = 0; i <= numA; i++) {
        inventoryArray[i] = copy.inventoryArray[i];
        
    }
    
    for(int i = 0; i <= choiceNum; i++) {
        choiceArray[i] = copy.choiceArray[i];
        
    }
}

//Destructor
AnimalDB::~AnimalDB() {
    
}

//Print Methods
//Inventory
void AnimalDB::inventoryPrint() const {
    for(int i = 0; i < numA; i++) {
        inventoryArray[i].print();
    }

}
//Shopping Cart
void AnimalDB::cartPrint() const {
    for(int i = 0; i < choiceNum; i++) {
        choiceArray[i].print();
    }
   
}
//Type
void AnimalDB::animalTypePrint(const string &type1) const {
    for(int i = 0; i < numA; i++) {
        if(inventoryArray[i].getType() == type1) {
            inventoryArray[i].print();
        }
    }
   
}
//Weight range
void AnimalDB::animalWeightPrint(const float &minWeight, const float &maxWeight) const {
    for(int i = 0; i < numA; i++) {
        if((inventoryArray[i].getWeight() >= minWeight) && (inventoryArray[i].getWeight() <= maxWeight)) {
            inventoryArray[i].print();
        }
    }
    
}
//Age range
void AnimalDB::animalAgePrint(int &minAge, int &maxAge) const {
    for(int i = 0; i < numA; i++) {
        if((inventoryArray[i].getAge() >= minAge) && (inventoryArray[i].getAge() <= maxAge)) {
            inventoryArray[i].print();
        }
    }
   
}
//ID
void AnimalDB::animalIDPrint(int &id) const {
    for(int i = 0; i < numA; i++) {
        if(inventoryArray[i].getID() == id) {
            inventoryArray[i].print();
        }
    }
}
//Price
void AnimalDB::printCost(const float &Price) const {
for (int i = 0; i < numA; i++){
    if (inventoryArray[i].getPrice() == Price)
        inventoryArray[i].print();
    }
}
//Getters
int AnimalDB::getinventoryNum() const {
    return numA;
}
int AnimalDB::getchoiceNum() const {
    return choiceNum;
}

//Setters

//Return Methods
Animal AnimalDB::currentAnimal(int &index) {
    Animal animalNew(choiceArray[index]);
    
    return animalNew;
}

Animal AnimalDB::userAnimal(int &choiceNum) {
    Animal animalNew1(inventoryArray[choiceNum]);
    
    return animalNew1;
}
float AnimalDB::cartTotal() const {
float cost = 0.0;

for (int i = 0; i < choiceNum; i++){
    cost += choiceArray[i].getPrice();
}
return cost;
}

//Insert Methods
//
bool AnimalDB::insertDonnaAnimal(const Animal &newAnimal) {
    if(numA < size) {
        inventoryArray[numA] = newAnimal;
        numA++;
        
        return true;
    }
    else {
        return false;
    }
    
}
//Adds animal to cart
bool AnimalDB::setUserAnimal(int &ID) {
    Animal object1;
    if((ID < size) && ID >= 0) {
        if(inventoryArray[ID].getID() != -1) {
            choiceArray[choiceNum] = inventoryArray[ID];
            choiceNum++;
            inventoryArray[ID] = object1;
            return true;
        } 
        else {
        cout << "Duplicate addition." << endl;
        return false;
        }
    }
    cout << "Id out of range" << endl;
    return false;
}
