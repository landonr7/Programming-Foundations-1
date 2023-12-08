#ifndef ANIMAL_H
#define ANIMAL_H

#include <fstream>

using namespace std;

class Animal {

    public:
    //Constructors
    Animal();
    Animal(const int &IDIn, const string typeIn, const float &weightIn, const int &ageIn, const float &priceIn);
    
    //Copy constructor
    Animal(const Animal & copy);
    
    //Destructor
    ~Animal();
    
    //Print Method
    void print() const;
    
    //Getters
    int getID() const;
    string getType() const;
    float getWeight() const;
    int getAge() const;
    float getPrice() const;
    
    //Setters
    void setID(const int &IDin);
    void setType(const string typeIn);
    void setWeight(const float &weightIn);
    void setAge(const int &ageIn);
    void setPrice(const float &priceIn);
    
    //Public account attributes
    int ID;
    string type;
    float weight;
    int age;
    float price;
    
    private:
    //Private account attributes
    
};

#endif