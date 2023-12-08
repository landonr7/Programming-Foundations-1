#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
const float pumpkinS = 7.0 ; //Declaring and initializing selling prices for Vegetable
const float eggPlantS = 5.0;
const float stringBeanS =4.5;
const float okraS =4.0;
    
const float A = 4.5; //Declaring branch choices for vegtables and their buying prices
const float B = 4.0;
const float C = 2.0;
const float D = 1.5;

char Vege;

int seedNum;
float totalCost; //Total amount spent on vegetables
float revenue; //Amount after disaster has taken place
  
int deadPlants;
int plantsLeft;
cout << "Vegetable Selling Prices:" << endl << "Pumpkin -- $7.00" << endl << "Eggplant -- $5.00" //Displays vegetable selling prices
    << endl << "Okra -- $4.50" << endl << "String Beans -- $4.00" << endl << endl;
    
cout << "Please use A, B, C, or D to choose the vegetable you want to buy and note its price:" << endl << //Displays vegetable cost
    "A.Pumpkin -- $4.50" << endl << "B.Eggplant -- $4.00" << endl << "C.Okra -- $2.00" << endl << "D.String Beans -- $1.50" << endl << endl;
    
cin >> Vege; //User input

    switch (Vege)
    {
     case 'A': //case for Pumpkin
        cout << "How many plants of pumpkin are you going to purchase? " << endl; 
        cin >> seedNum;
        if (seedNum < 0) { //Error handling
            cout << "Don't waste my time." << endl;
            return 0;
        }
        totalCost = seedNum * A;
        cout << "You are buying " << seedNum << " pumpkin seed(s) and spent $" << fixed << setprecision(2) << totalCost << "." << endl;
        
        srand(time(0)); // this is how we would set up the srand() function;
        //event = rand() % 3; //Random event range 0 or 1
        deadPlants = 0;
        deadPlants = rand() % seedNum + 1; //Random plant destroying range 0 to seedNum
        plantsLeft = seedNum - deadPlants;

        revenue = plantsLeft * pumpkinS;
        //case 0: //Locust event
        if (totalCost > revenue) { //Losing money
                cout << "Oh pity! A plague of locusts has demolished all of your plants, you incurred a loss of $" << fixed << setprecision(2) << totalCost - (plantsLeft * pumpkinS) << ", maybe next season." << endl;
            }
            if (totalCost == revenue) { //Breaking even
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants, if you sell them now you'll break even." << endl;
            }
            if (totalCost < revenue)  { //Making profit
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants! If you sell them now you'll make $" << fixed << setprecision(2) << revenue - totalCost << " in revenue, congrats! " << endl;
            }
            cout << endl;
            break;
     case 'B': //case for Eggplant
        cout << "How many seeds of eggplant are you going to purchase?" << endl;
        cin >> seedNum;
        if (seedNum < 0) { //Error handling
            cout << "Don't waste my time." << endl;
            return 0;
        }
        totalCost = seedNum * B;
        cout << "You are buying " << seedNum << " eggplant seed(s) and spent $" << fixed << setprecision(2) << totalCost << "." << endl;

        srand(time(0)); // this is how we would set up the srand() function;
        //event = rand() % 3; //Random event range 0 or 1
        deadPlants = 0;
        deadPlants = rand() % seedNum + 1; //Random plant destroying range 0 to seedNum
        plantsLeft = seedNum - deadPlants;
        
        revenue = plantsLeft * eggPlantS;
        //case 0: //Locust event
            if (totalCost > revenue) { //Losing money
                cout << "Oh pity! A plague of locusts has demolished all of your plants, you incurred a loss of $" << fixed << setprecision(2) << totalCost - (plantsLeft * eggPlantS) << ", maybe next season." << endl;
            }
            if (totalCost == revenue) { //Breaking even
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants, if you sell them now you'll break even." << endl;
            }
            if (totalCost < revenue)  { //Making profit
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants! If you sell them now you'll make $" << fixed << setprecision(2) << revenue - totalCost << " in revenue, congrats! " << endl;
            }
            cout << endl;        
            break;
        
     case 'C': //case for Okra
        cout << "How many seeds of okra are you going to purchase?" << endl;    
        cin >> seedNum;
        if (seedNum < 0) { //Error handling
            cout << "Don't waste my time." << endl;
            return 0;
        }
        totalCost = seedNum * C;
        cout << "You are buying " << seedNum << " okra seed(s) and spent $" << fixed << setprecision(2) << totalCost << "." << endl;

        srand(time(0)); // this is how we would set up the srand() function;
        //event = rand() % 3; //Random event range 0 or 1
        deadPlants = 0;
        deadPlants = rand() % seedNum + 1; //Random plant destroying range 0 to seedNum
        plantsLeft = seedNum - deadPlants;
        
        revenue = plantsLeft * okraS;
        //case 0: //Locust event
            if (totalCost > revenue) { //Losing money
                cout << "Oh pity! A plague of locusts has demolished all of your plants, you incurred a loss of $" << fixed << setprecision(2) << totalCost - (plantsLeft * okraS) << ", maybe next season." << endl;
            }
            if (totalCost == revenue) { //Breaking even
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants, if you sell them now you'll break even." << endl;
            }
            if (totalCost < revenue)  { //Making profit
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants! If you sell them now you'll make $" << fixed << setprecision(2) << revenue - totalCost << " in revenue, congrats! " << endl;
            }
            cout << endl;        
            break;
     case 'D': //case for String Bean
        cout << "How many seeds of string bean are you going to purchase?" << endl;
        cin >> seedNum;
        if (seedNum < 0) { //Error handling
            cout << "Don't waste my time." << endl;
            return 0;
        }
        totalCost = seedNum * D;
        cout << "You are buying " << seedNum << " string bean seed(s) and spent $" << fixed << setprecision(2) << totalCost << "." << endl;

        srand(time(0)); // this is how we would set up the srand() function;
        //event = rand() % 3; //Random event range 0 or 1
        deadPlants = 0;
        deadPlants = rand() % seedNum + 1; //Random plant destroying range 0 to seedNum
        plantsLeft = seedNum - deadPlants;
        
        revenue = plantsLeft * stringBeanS;
        //case 0: //Locust event
            if (totalCost > revenue) { //Losing money
                cout << "Oh pity! A plague of locusts has demolished all of your plants, you incurred a loss of $" << fixed << setprecision(2) << totalCost - (plantsLeft * stringBeanS) << ", maybe next season." << endl;
            }
            if (totalCost == revenue) { //Breaking even
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants, if you sell them now you'll break even." << endl;
            }
            if (totalCost < revenue)  { //Making profit
                cout << "Oh pity! A plague of locusts has demolished " << deadPlants << " of your plants! If you sell them now you'll make $" << fixed << setprecision(2) << revenue - totalCost << " in revenue, congrats! " << endl;
            }
            cout << endl;  
        break;
     default:
        cout << endl;
    }
cout << "The code has finished executing, go bug someone else." << endl;
return 0;
}      


