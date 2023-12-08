/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>

//Declarations
int dustinMoney;
int lucasMoney;
int mikeMoney;
int maxMoney;

int dustinGame;
int lucasGame;
int mikeGame;
int maxGame;

float arcadeProfit;

using namespace std;

int main()
{
    cout << "Welcome To The Hawkins Palace Arcade and Casino Resort Bistro Bed & Breakfast Cafe Lounge on the Water!" << endl << endl;
    
//Input section
    cout << "Dustin, how many quarters did you bring with you to this fine establishment today?" << endl; //Dustin's Money
    cin >> dustinMoney;
    if (dustinMoney > 0) {
        cout << "You said you brought " << dustinMoney << " quarters to the arcade." << endl; //echo
        cout << "And how many quarters does your favorite game cost?" << endl; // Cost of Dustin's favorite game.
        cin >> dustinGame;
        cout << "You said your favorite game costs " << dustinGame << " quarters to play." << endl << endl; //echo
    }
    else {
        cout << "Dustin, if you have no money please leave." << endl;
    }
    
    cout << "How about you Lucas? How fun did you bring with you today?" << endl; //Lucas' Money
    cin >> lucasMoney;
    if (lucasMoney > 0) {
        cout << "You said you brought " <<lucasMoney << " quarters to the arcade." << endl; //echo
        cout << "And how many quarters does your favorite game cost?" << endl; // Cost of Lucas's favorite game.
        cin >> lucasGame;
        cout << "You said your favorite game costs " << lucasGame << " quarters to play." << endl << endl; //echo
    }
    else {
        cout << "Lucas, if you have no money please leave." << endl;
    }
    
    cout << "Big Money Mike! How many quarters did you bring today?" << endl; //Mike's Money
    cin >> mikeMoney;
    if (mikeMoney > 0) {
        cout << "You said you brought " << mikeMoney << " quarters to the arcade." << endl; //echo
        cout << "And how many quarters does your favorite game cost?" << endl; // Cost of Mike's favorite game.
        cin >> mikeGame;
        cout << "You said your favorite game costs " << mikeGame << " quarters to play." << endl << endl; //echo
        }
    else {
        cout << "Mike, if you have no money please leave." << endl;
    }
    
    cout << "Max, How many quarters did you bring today?" << endl; //Max's Money
    cin >> maxMoney;
    if (maxMoney > 0) {
        cout << "You said you brought " << maxMoney << " quarters to the arcade." << endl; //echo
        cout << "And how many quarters does your favorite game cost?" << endl; // Cost of Max's favorite game.
        cin >> maxGame;
        cout << "You said your favorite game costs " << maxGame << " quarters to play." << endl << endl; //echo
    }
    else {
        cout << "Max, if you have no money please leave." << endl;
    }
    
//Division section
    if (dustinMoney % dustinGame != 0) {
    cout << "Dustin, with the amount of quarters you brought today you can play your favorite game " << dustinMoney / dustinGame //Dustin's leftovers
    << " times with " << dustinMoney % dustinGame << " quarters left to buy whatever sugary mess you want!" << endl;    

    }
    else {
    cout << "Dustin, with the amount of quarters you brought today you can play your favorite game " << dustinMoney / dustinGame 
    << " times with no quarters left to spend on nasty garbage food!" << endl;
    }

    if (lucasMoney % lucasGame != 0) {
    cout << "Lucus, with the amount of quarters you brought today you can play your favorite game " << lucasMoney / lucasGame //Lucas' leftovers
    << " times with " << lucasMoney % lucasGame << " quarters left to buy whatever sugary mess you want!" << endl;    

    }
    else {
    cout << "Lucss, with the amount of quarters you brought today you can play your favorite game " << lucasMoney / lucasGame 
    << " times with no quarters left to spend on nasty garbage food!" << endl;
    }
    
    if (mikeMoney % mikeGame != 0) {
    cout << "Mike, with the amount of quarters you brought today you can play your favorite game " << mikeMoney / mikeGame //Mike's leftovers
    << " times with " << mikeMoney % mikeGame << " quarters left to buy whatever sugary mess you want!" << endl;    

    }
    else {
    cout << "Mike, with the amount of quarters you brought today you can play your favorite game " << mikeMoney / mikeGame 
    << " times with no quarters left to spend on nasty garbage food!" << endl;
    }
    
        if (maxMoney % maxGame != 0) {
    cout << "Max, with the amount of quarters you brought today you can play your favorite game " << maxMoney / maxGame //Max's leftovers
    << " times with " << maxMoney % maxGame << " quarters left to buy whatever sugary mess you want!" << endl << endl;    

    }
    else {
    cout << "Max, with the amount of quarters you brought today you can play your favorite game " << maxMoney / maxGame 
    << " times with no quarters left to spend on nasty garbage food!" << endl << endl;
    }

//Calculating profits
    cout << "On an average night, how much money does The Hawkins Palace Arcade and Casino Resort Bistro Bed & Breakfast Cafe"; 
    cout <<"Lounge on the Water make?" << endl;
    cin >> arcadeProfit;
    cout <<  "You said the arcade makes $" << fixed << setprecision(2) << arcadeProfit << " any given night." << endl << endl; //Nightly profits
    cout << "That means this place is cranking out $" << arcadeProfit * 6 << " per week, man that's a lot of money." << endl << endl; //Weekly profits
    cout << "But that also means it makes $" << arcadeProfit * 24 << " every month, that's some big money right there." << endl << endl; //Monthly profits
    cout << "and that means this place is raking in $" << arcadeProfit * 312 << " annually, that's like sooooo much money." << endl << endl; //Annual profits
    
    
    
    cout << "The program has fully executed, thank you and have a wonderful night."; //Test to make sure code didn't crash.
    return 0;
}
