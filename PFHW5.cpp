#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int DAYS = 7;
const int WEEKS = 12;

void arrayFill(int min, int max, int funcArray[DAYS][WEEKS]){
    //Ask for a min and a max then place random numbers into array

    int i = max - min;
   
    for (int a = 0; a < DAYS; a++){ //Fills table with random numbers between min and max
       
        for (int b = 0; b < WEEKS; b++){
            funcArray[a][b] = (rand() % i + min);
        }
    }  
}


void specificDayWeek(int dayNum, int weekNum, int funcArray[DAYS][WEEKS]){
    //Ask for number of day and week user needs, output value at specific day, and let user change that value
    int change = 0;
   
    do {
        cout << "Enter a day number for the table (0-6).\n";
        cin >> dayNum; //Gets day number for table
    } while ((dayNum < 0) || (dayNum >= 7));
   
    do {
        cout << "Enter a week number for the table (0-11).\n";
        cin >> weekNum; //Gets week number for table
    } while ((weekNum < 0) || (weekNum >= 12));
   
    cout << "How much did you make on day " << dayNum << " week " << weekNum << "?\n";
    cin >> change;
   
    funcArray[dayNum][weekNum] = change; //Makes user input value take place of chosen day and week value
}

void printCertainWeek(int oneWeek, int funcArray[DAYS][WEEKS]){
    //Ask user for which week they want to print and print tips of certain week

    do {
    cout << "Which week from the table would you like to see?\n"; //Gets week number from user
    cin >> oneWeek;
    }
    while ((oneWeek < 0) || (oneWeek > 12));
       
    cout << "Week " << oneWeek << endl;
   
    for (int day = 0; day < DAYS; day++){ //Prints array of input week
        cout << "|" << setw(3) << funcArray[day][oneWeek] << setw(3) << "|";
        cout << endl;
    }
}

void printEveryWeek(int funcArray[DAYS][WEEKS]){
    //Print whole array and diplay tips made everyday
    for (int day = 0; day < DAYS; day++){ //Prints out whole array
       
        for (int week = 0; week < WEEKS; week++){
            cout << "|" << setw(3) << funcArray[day][week] << setw(3) << "|";
        }
       
    cout << endl;
    }
}

void weekTipSum(int funcArray[DAYS][WEEKS]){
    //Print tip sum of each week and display which week made most money
    int sum = 0;
    int temp = 0;
    int weekOf = 0;
   
    for (int b = 0; b < WEEKS; b++){
        sum = 0; //Resets the sum for each week
       
        for (int a = 0; a < DAYS; a++) {
            sum += funcArray[a][b]; //Adds up weekly tips
        }    
       
        if (temp < sum){ //Finds greatest sum
            temp = sum;
            weekOf = b;
        }
        switch(b){ //Connects a week's sum (b) to its corresponding week
            case 0:
                cout << "For week zero you made $" << sum << endl;
                break;
            case 1:
                cout << "For week one you made $" << sum << endl;

                break;
            case 2:
                cout << "For week two you made $" << sum << endl;

                break;
            case 3:
                cout << "For week three you made $" << sum << endl;
           
                break;
            case 4:
                cout << "For week four you made $" << sum << endl;
           
                break;
            case 5:
                cout << "For week five you made $" << sum << endl;
           
                break;
            case 6:
                cout << "For week six you made $" << sum << endl;
           
                break;
            default:
                cout << " " << endl;
        }        
    }
   
    cout << "Week " << weekOf << " made the most tips with $" << temp << endl; //Displays week that made most tips
}
void avgEarnedEachDay(int funcArray[DAYS][WEEKS]){
    //Print avg number of each day of the week's tips and print which day has the greatest tip avg
    int sum = 0;
    int temp = 0;
    int dayOf = 0;
    int avg = 0;
    string maxAvg = " ";
   
    for (int b = 0; b < DAYS; b++){
       
        for (int a = 0; a < WEEKS; a++) {
            sum += funcArray[b][a];
        }    
        avg = sum / WEEKS; //Average calculation
       
        sum = 0; //Resets sum for each day of the week
       
        if (avg > temp){ //Finds greatest average
            temp = avg;
            dayOf = b;
        }
       
        switch(b){ //Connects the average of a day of the week's tips to its corresponding day
            case 0:
                cout << "Sundays made an average of $" << avg << endl;
                break;
            case 1:
                cout << "Mondays made an average of $" << avg << endl;

                break;
            case 2:
                cout << "Tuesdays made an average of $" << avg << endl;

                break;
            case 3:
                cout << "Wednesdays made an average of $" << avg << endl;
           
                break;
            case 4:
                cout << "Thursdays made an average of $" << avg << endl;
           
                break;
            case 5:
                cout << "Fridays made an average of $" << avg << endl;
           
                break;
            case 6:
                cout << "Saturdays made an average of $" << avg << endl;
           
                break;
            default:
                cout << " " << endl;
        }        
       
    }

    switch(dayOf){ //Finds which day the max average belongs to
        case 0:
            maxAvg = "Sunday";
            break;
        case 1:
            maxAvg = "Monday";
            break;
        case 2:
            maxAvg = "Tuesday";
            break;
        case 3:
            maxAvg = "Wednesday";
            break;
        case 4:
            maxAvg = "Thursday";
            break;
        case 5:
            maxAvg = "Friday";
            break;
        case 6:
            maxAvg = "Saturday";
        default:
            cout << " " << endl;
    }
   
    cout << endl << maxAvg << " on average made the greatest tip with $" << temp << endl; //Displays which day of the week makes the most tips on average
}


int main()
{
    int funcArray[DAYS][WEEKS] = {0};
    char appChoice = '\0';
    int min, max, week = 0;
    int day = 0;
    do {

        srand(time(0));
       
        cout << "\n-------------Features-------------\n" << "Please choose a letter from A-F to use the features of this app or enter 0 to exit\n" << endl;
        cout << "A. Array filling\n" << "B. Table editing\n" << "C. Certain week's tips\n" << "D. Overall view of table\n" << "E. Tips week by week\n"
             << "F. Average tips by day of the week\n" << "0. Exit\n\n"; //Displays all functions
       
        cin >> appChoice;
        appChoice = toupper(appChoice);
       
        switch(appChoice){ //Choses which function to execute
           
            case 'A':
                cout << "You have chosen part A.\n";
                cout << "Enter a minimum number for the table.\n";
                cin >> min; //Gets minimum value for table
                cout << "Enter a maximum number for the table.\n";
                cin >> max; //Gets maximum value for table
                arrayFill(min, max, funcArray);
                break;
           
            case 'B':
                cout << "You have chosen part B.\n";
                specificDayWeek(day, week, funcArray);
                break;
           
            case 'C':
                cout << "You have chosen part C.\n";
                printCertainWeek(week, funcArray);
                break;            
           
            case 'D':
                cout << "You have chosen part D.\n";
                printEveryWeek(funcArray);
                break;            
           
            case 'E':
                cout << "You have chosen part E.\n";
                weekTipSum(funcArray);
                break;
           
            case 'F':
                cout << "You have chosen part F.\n";
                avgEarnedEachDay(funcArray);
                break;
           
            case '0':
                return 0;
                break;
           
            default :
                cout << "Invalid input please try again.\n";
        }
    } while(appChoice != 0);
   
    return 0;
}
