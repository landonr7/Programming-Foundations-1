#include "Animal.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
//Default constructor
Animal::Animal() {
    ID = -1;
    type = '\0';
    weight = 0.0;
    age = 0;
    price = 0.0;
}
//Constructor
Animal::Animal(const int &IDIn, const string typeIn, const float &weightIn, const int &ageIn, const float &priceIn) {
    ID = IDIn;
    type = typeIn;
    weight = weightIn;
    age = ageIn;
    price = priceIn;
}

//Copy constructor
Animal::Animal(const Animal & copy) {
    ID =  copy.ID;
    type = copy.type; ;
    weight = copy.weight;
    age = copy.age;
    price = copy.price;
}

//Destructor
Animal::~Animal() {
    
}

//Print Method
void Animal::print() const {
    cout << ID << " " << type << " " << fixed << setprecision(2) << weight << " " << age << " " << price << endl;
}
    
//Getters
int Animal::getID() const {
    
    return ID;
}
string Animal::getType() const {
    
    return type;
}
float Animal::getWeight() const {
    
    return weight;
}
int Animal::getAge() const {
    
    return age;
}
float Animal::getPrice() const {
    
    return price;
}

//Setters
void Animal::setID(const int &IDin) {
    
    ID = IDin;
}
void Animal::setType(const string typeIn) {
    
    type = typeIn;
}
void Animal::setWeight(const float &weightIn) {
    
    weight = weightIn;
}
void Animal::setAge(const int &ageIn) {
    
    age = ageIn;
}
void Animal::setPrice(const float &priceIn) {
    
    price = priceIn;
}