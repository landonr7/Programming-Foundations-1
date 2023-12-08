#include <iostream>
#include <time.h>
using namespace std;

int dirtWidth;
int count = 0;

int opusSpot = 0; //Slots that each worm is in
int ursulaSpot = 0;

int bumpSpot = 0; //Slots where worms are in same slot

int leftWorm; //Worm on the left side
int rightWorm; //Worm on the right side



int main()
{
    srand(time(0)); //Random function
    
    do { //Places spaces for dirtWidth
        cout << "How much room will you give the worms?" << endl;
        cin >> dirtWidth;
    }
    while (dirtWidth <= 1); //Error handling
        opusSpot = dirtWidth / 2 ;
        ursulaSpot = dirtWidth / 2;

    while (((opusSpot > 0) && (opusSpot < dirtWidth)) && ((ursulaSpot > 0) && (ursulaSpot < dirtWidth))) { //Putting worms in dirt spots
        cout << "|"; //last stone wall
        
        if(opusSpot < ursulaSpot) { //If Opus is on the left he is named leftWorm
            leftWorm = opusSpot;
            rightWorm = ursulaSpot;
        }
        else {
            leftWorm = ursulaSpot; //If Ursula is on the left she is name leftWorm
            rightWorm = opusSpot;
        }
        
        for(count = 1; count < leftWorm; count++) { //Places dirt on the left of leftWorm
            cout << " ";
        }
        if(opusSpot != ursulaSpot) { //If both worms are not in the same spot
            if(leftWorm == opusSpot){ //Locates Opus with "O"
                cout << "O";
            }
            else {
                cout << "U";
            }
        }
        else {
            cout << " "; 
            cout << "x"; //Where the worms meet
        }
        if (opusSpot != ursulaSpot) { //Places dirt between worms
            for (count = leftWorm; count < rightWorm; count++) {
                cout << " ";
            }
        }
        if (opusSpot != ursulaSpot) { //Locates Ursula with "U"
            if (opusSpot == rightWorm) {
                cout << "O";
            }
            else {
                cout << "U";
            }
        }
        for(count = count + 1; count < dirtWidth; count++) { //Places dirt
            cout << " ";
        }
        cout << "|"; 
        cout << endl;

        opusSpot = opusSpot + rand() % 3 - 1; //Random movement
        ursulaSpot = ursulaSpot + rand() % 3 - 1;
     } 
     
    cout << endl << "The code has executed successfully, go jump in a lake." << endl;
    return 0;
}