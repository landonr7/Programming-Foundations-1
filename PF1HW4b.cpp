/******************************************************************************
Author: Landon Reynolds 010975968
Date: 10/19/2022

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

//main dish costs
const double costSpecial1 = 14.95;
const double costSpecial2 = 9.95;
const string special1 = "Chum Burger";
const string special2 = "Chum Stick";

//---------------------------------------------------------------------------
// Name: getTableOrder
// Parameters: const int numPeople, int & numSpecial1, int & numSpecial2
// Returns: none
// Purpose: This function asks how many people ordered special1, how many ordered
// special2, and updates through the pass-by-reference parameters
// There should be an error-checking loop to make sure that the total number of dishes
// ordered is less than the number of people sitting there (some people may just be
// eating unlimited breadsticks, so the number doesn't have to match exactly)
//---------------------------------------------------------------------------
void getTableOrder(const int numPeople, int & numSpecial1, int & numSpecial2){
    cout << "How many people are ordering the Chum Burger? >> " << endl;
    cin >> numSpecial1; //Input for Chum Burger
    
    cout << "How many people are ordering the Chum Stick? >> " << endl;
    cin >> numSpecial2; //Input for Chum Stick
    
    while (numPeople < (numSpecial1 + numSpecial2)) {
        cout << "You're ordering too much slop... did Krabs put you up to this? Try ordering again with"
        "the appropriate amount of Specials." << endl;
        cout << "How many people are ordering the Chum Burger? >> " << endl;
        cin >> numSpecial1; //Input for Chum Burger
        cout << "How many people are ordering the Chum Stick? >> " << endl;
        cin >> numSpecial2; //Input for Chum Stick
    }

    if((numSpecial1 + numSpecial2) < numPeople){
        cout << "Excellent... " << numSpecial1 << " Chum Burger(s) and " << numSpecial2 << " Chum Stick(s) with "
        << (  numPeople - (numSpecial1 + numSpecial2)) << " order(s) of Chum Fries, enjoy your... meal..." << endl;
    }
    
    else if((numSpecial1 + numSpecial2) == numPeople){
        cout << "Excellent... " << numSpecial1 << " Chum Burger(s) and " << numSpecial2 << " Chum Stick(s) enjoy your... meal..." << endl;
    }

}

//---------------------------------------------------------------------------
// Name: calculateTip
// Parameters: const int numPeople, const double bill, double & tip
// Returns: none
// Purpose: Calculate the tip.  If there are 8 or more people, 
// the tip was already added, but ask if they would like to add more.
// The user should be able to add a percentage or a specific amount.  
// (be sure to add to the tip that's possibly already there)
// Include error checking for inputs.
//---------------------------------------------------------------------------
void calculateTip(const int numPeople, const double bill, double & tip){
    char addTip, realTip = '\0';
    float pTip, sTip = 0.0;
    float eightTip = 0.0;
    if (numPeople >= 8){
        eightTip = .2;
    }
    cout << "Would you like to add an additional tip? (Input y/n) >> ";
    cin >> addTip;
    addTip = tolower(addTip);
    
    while(addTip != 'y' && addTip != 'n'){ //Error checking for y/n
        cout << "INVALID! Try again." << endl;
        cin >> addTip; 
    addTip = tolower(addTip);
    }
    
    if(addTip == 'y'){
        cout << "Excellent... now would you like to tip a percentage or a specific amount? (Input p/s) >>";
        cin >> realTip;
        realTip = tolower(realTip);
        
        while(realTip != 'p' && realTip != 's'){ //Error checking for p/s
            cout << "INVALID! Try again." << endl;
            cin >> realTip; 
        realTip = tolower(realTip);
        }
        
        if(realTip == 'p'){ //Percentage branch
            cout << "What percentage would you like to tip? (Input a decimal number between 0 and 1) >>";
            cin >> pTip;
            pTip += eightTip;
            
            while(pTip <= 0  && pTip > 1){ //Error checking for 0 to 1
                cout << "INVALID! Try again." << endl;
                cin >> pTip; 
                pTip += eightTip;
            }
            cout << "Your additional tip is now added to your bill." << endl;
            tip += (bill * pTip);
        }
        else if(realTip == 's'){ //Specific amount branch
            cout << "How much money would you like to tip? (Input a dollar amount) >>";
            cin >> sTip;
            sTip += eightTip;
            
            while(sTip <= 0){ //Error checking for 0 to 100
                cout << "INVALID! Try again." << endl;
                cin >> sTip;
                sTip += eightTip;
            }
            cout << "Your additional tip is now added to your bill." << endl;
            tip = sTip + (eightTip * bill);
        }
    }  
    else if(addTip == 'n'){
        cout << "Well then, once again, enjoy your... meals..." << endl;
    }
}


//---------------------------------------------------------------------------
// Name: calculateCost
// Parameters: const int numPeople, const int numSpecial1, const int numSpecial2, double & tip
// Returns: the cost of the meal
// Purpose: Calculate the total cost of everyone's meals.  If there are more than
// 8 people dining, update the tip parameter to a mandatory 20%.  Then, call the calculateTip function
// to find out how much they tip
// Note: if there are more people than meals ordered, the extra people should be
// charged $5 each for unlimited breadsticks
//---------------------------------------------------------------------------
float calculateCost(const int numPeople, const int numSpecial1, const int numSpecial2, double & tip){
    float cost = 0;
    float bill = (numSpecial1 * 14.95) + (numSpecial2 * 9.95) + ((numPeople - (numSpecial1 + numSpecial2)) * 5.00);
    if(numPeople >= 8){
       cout << "A tip of 20% has been added to your bill." << endl;
    }
    calculateTip(numPeople, bill, tip);
    cost = bill + tip;

 return cost;
}

//---------------------------------------------------------------------------
// Name: displayFinalBill
// Parameters: const int numPeople, const int special1, const int special2, const double bill, const double tip
// Returns: nothing
// Purpose: This function prints the receipt information - how many people got which dish,
// how many just had breadsticks, the price of everyone's food, the tip, and the final bill
//---------------------------------------------------------------------------
void displayFinalBill(const int numPeople, const int numSpecial1, const int numSpecial2, double & totalBill, double & tip){
    
    float bill = (numSpecial1 * 14.95) + (numSpecial2 * 9.95) + ((numPeople -(numSpecial1 + numSpecial2)) * 5.00);
    //Print total 
    cout << "There were " << numPeople << " people in your party today.";
    cout << fixed << setprecision(2);
    cout << "\nYour bill: " << endl;
    cout << "------------------------------------------" << endl;
    cout << "\tChum Burger $14.95:          " << numSpecial1 << endl;
    cout << "\tChum Stick $9.95:            " << numSpecial2 << endl;
    cout << "\tChum Fries $5.00:            " << numPeople - (numSpecial1 + numSpecial2) << endl;
    cout << "\tSubtotal:                   $" << bill << endl;
    cout << "\tTip:                        $" << tip << endl;
    cout << "\tTOTAL:                      $" << bill + tip << endl;
    cout << "------------------------------------------" << endl;
}


//---------------------------------------------------------------------------
// Name: orderMoreEntrees
// Parameters: char & orderMore
// Returns: nothing
// Purpose: This function asks the user if they want to order more food, checks to 
// ensure that the user enters a 'y' or an 'n', and returns the answer (by updating the parameter)
// If they enter an uppercase letter, it gets converted to lowercase
//---------------------------------------------------------------------------
void orderMoreEntrees(char & orderMore){
    char more = '\0';
    cout << "Would you Barnacle Heads like to order more from the Chum Bucket? (Input (y/n) >>" << endl;
    cin >> more;
    more = tolower(more);
    
    while(more != 'y' && more != 'n'){ //Error checking for y/n
        cout << "INVALID! Try again." << endl;
        cin >> more; 
        more = tolower(more);
    }
    
    if(more == 'y'){
        orderMore = 'y';
    }
    
    else if(more == 'n'){
        orderMore = 'n';
    }
}


//---------------------------------------------------------------------------
// Name: resetVariables
// Parameters: double & totalBill, double & tip, int & numPeople, int & numSpecial1, int & numSpecial2
// Returns: nothing
// Purpose: This function resets the values of all variables passed in
//---------------------------------------------------------------------------
void resetVariables(double & totalBill, double & tip, int & numPeople, int & numSpecial1, int & numSpecial2){
    totalBill = 0.0;
    tip = 0.0;
    numPeople = 0;
    numSpecial1 = 0;
    numSpecial2 = 0;
}


int main()
{
    cout << "Landon Reynolds 010975968" << endl;
    double totalBill, tip;
    int numPeople, numSpecial1, numSpecial2;
    char orderMore = 'n';

    do
    {
        cout << "How many people are in your party? >> ";
        cin >> numPeople;
        while((numPeople <= 0) && (isalpha(numPeople)))
        {
            cout << "Invalid input.  How many people are in your party? >> ";
            cin >> numPeople;
        }
        cout << "\n\nWelcome to the Chum Bucket! It appears there are " << numPeople << " dining with us today.\n";
            
        getTableOrder(numPeople, numSpecial1, numSpecial2);
        totalBill = calculateCost(numPeople, numSpecial1, numSpecial2, tip);
        displayFinalBill(numPeople, numSpecial1, numSpecial2, totalBill, tip);
        orderMoreEntrees(orderMore);
        if(orderMore == 'y')
        {
            resetVariables(totalBill, tip, numPeople, numSpecial1, numSpecial2);
        }
    } while(orderMore != 'n');
    cout << "Karen! Kick these fine paying customers out immediately!\n" << endl;
    cout << "The code has ran successfully, now walk the plank!!\n";
    return 0;
}