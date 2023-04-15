#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
    cout << "Welcome to the number guessing game!" << endl;
    cout << "For each game, you have at most 3 chances to guess a secret number from 1 to 10." << endl;
    int total_games = 0, total_wins = 0;
    int number, boot;
    srand(time(0));
    do{
        boot = rand() %10 + 1; // [a, b] => rand() %(b - a + 1) + a;
        int count = 0; // guess number
        // cout << "(Secret " << boot << ")\n\n";
        cout << "\nEnter a number from 1 to 10. Enter 0 to exit: ";
        do{
            count++; // Increase the number of guesses
            cin >> number;
            if(number != boot && number != 0 && count != 3)
                cout << "Not correct, try aganin: ";
        }while(count != 3 && number != 0 && number != boot);
        if(count > 1){ // In case of playing (count> 1), on the contrary, the case of pressing will not count as 1 game
            total_games++;
            if(number == boot){
                cout << "Congratutation, correct! Let's start a new game." << endl;
                total_wins++; //Increase the number of victories
            }else
                cout << "\nNot corect. You have reached your 3 trials. The correct number is " << boot << "\nLets start a new game.\n";
        }
    }while(number != 0); // Perform when the number is different from 0
    cout << "Here is your game summary:\n";
    cout << "\nTotal games:\t" << total_games << endl; 
    cout << "Total wins:\t" << total_wins << endl; 
    cout << "Total losses:\t" << total_games - total_wins << endl; 
    return 0;
}