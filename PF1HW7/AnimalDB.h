#ifndef ANIMALDB_H
#define ANIMALDB_H

#include "Animal.h"
#include <fstream>

using namespace std;

class AnimalDB {

    public:
    //Constructors
    AnimalDB();
    
    //Copy constructor
    AnimalDB(const AnimalDB & copy);
    
    //Destructor
    ~AnimalDB();
    
    //Print Methods
    void inventoryPrint() const;
    void cartPrint() const;
    void animalTypePrint(const string &) const;
    void animalWeightPrint(const float &, const float &) const;
    void animalAgePrint(int &, int &) const;
    void animalIDPrint(int &) const;
    void printCost(const float &) const;
    
    //Getters
    int getinventoryNum() const; 
    int getchoiceNum() const;
    
    //Setters
    bool insertDonnaAnimal(const Animal &);
    bool setUserAnimal(int &);
    
    //Return Methods
    Animal currentAnimal(int &);
    Animal userAnimal(int &choiceNum);
    float cartTotal() const;
    
    //Public account attributes
    int type;
    float weight;
    int age;
    float price;
    
    private:
    //Private account attributes
    static const int size = 100;
    int numA = 0;
    int choiceNum = 0;
    Animal inventoryArray[size];
    Animal choiceArray[size];
};

#endif