/* 
 * File:   main.cpp
 * Author: Aurelisa J. Sindhunirmala
 * Created on June 2, 2023, 10:18 AM
 * Purpose: Project 2; Create a blackjack game Version 8
 */

//System Libraries
#include <iostream>     //Input-Output Library
#include <iomanip>      //Format Library
#include <cstdlib>      //Random functions
#include <ctime>        //Set Random Library
#include <fstream>      //File Stream Library
#include <string>       //String Library
#include <vector>       //Vector Library
using namespace std;

//User Libraries

//Global Constants - Math/Physics/Chemistry/Conversions ONLY!!!!



//Function Prototypes
void intro();                   //Opening of the game
void menu(int&);                //Menu settings of the game
void display();                 //2 dimensioned arrays
int  getN(int);                 //Getting the player's answers
void opt1();                    //Menu Option 1
void opt2();                    //Menu Option 2
void opt3();                    //Menu Option 3
void def(int);                  //Default switch case for Menu
bool checkBj(int);              //Check Blackjack
bool isBust(int&);              //Check if player's hand exceeds 21 (bust)
bool isBust(int&, int);         //Check if a specific hand exceeds a given limit
void bubSort(vector<int>&);     //Sort the player's hand with bubble sort
void cdType(int);               //Get the card type: Suits in Deck
void selSort(int[], int);       //Sort the player's comment
bool linSch(int[], int, int);   //Linear search to see if sum of player's card = 21

//Execution Begins HERE!!!
int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Map Input to Output - Process
    //Opening of the game
    intro();
    
    //Declare an array to store player names
    string plyName[1];
    int plyAge[1],
        inp,
        option;
    
    //Get player information
    for (int i = 0; i < 1; i++){
        cout << "Enter the name of player:" << endl;
        cin >> plyName[i];
        
        cout << "Enter your age: " << endl;
        cin >> plyAge[i];
    }
    
    
    //Display player information
    cout << "Player's Information " << endl;
    for (int i = 0; i < 1; i++){
        cout << "Player's name: " << plyName[i] << endl;
        cout << "Player's age: " << plyAge[i] << endl;
    }
    
    do{ //switch case for rules, start, or exit game
        menu(option);
        switch(option){
            case 1: opt1(); break;
            case 2: opt2(); break;
            case 3: opt3(); break;
            default: def(inp);
        }
    } while (inp > 0 && inp < 3);
    
    //Exit stage right
    return 0;
}

void intro(){  //Opening of the game
    //Display Output for Intro
    cout << setw(35) << "||===========================||" << endl;
    cout << setw(35) << "||   Welcome to Blackjack!   ||" << endl;
    cout << setw(35) << "||  Let's play and have fun! ||" << endl;
    cout << setw(35) << "||===========================||" << endl; 
}

void menu(int& option){ //Menu settings of the game
    //Declare variables
    bool vldInp = false;
    int defVal;
    
    while (!vldInp){ //User enter choice and program reads
        display();
        cout << endl << "Enter your choice"; 
        if (option != 0){
            cout << option;
        }
        cout << ": ";
        
        option = getN(defVal);
        
        if (option < 1 || option > 3){
            cout << "Invalid input. Please enter a number between 1 and 3." << endl << endl;
        } else{
            vldInp = true;
        }
    }
}

void display(){ //2 dimensioned arrays
    const int OPTION = 3;
    const string menuOpt[OPTION][2] = {
        {"1. Rules", "Rules of the Game"},
        {"2. Start", "Start the Game"},
        {"3. Exit ", "Exit the Game"}
    };
    cout << endl << "Menu Settings" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    cout <<endl << "Choose one of the options:" << endl;
    
    for (int i = 0; i < OPTION; i++){
        cout << setw(12);
        if (i == OPTION - 1){
            cout << setw(12);
        }
        cout << menuOpt[i][0] << "- " << menuOpt[i][1] << endl;
    }
}

int getN(int defVal){ //Getting the player's answers
    defVal = 0;
    int inp;
    cin >> inp;
    return (inp != 0) ? inp : defVal;
}

void opt1(){ //Print out rules of the game
    //Rules
    cout << "\nLet's get to know the game better!\n";
    cout << "1) The maximum value to bet is $500." << endl;
    cout << "2) The dealer draws two cards from the deck to each player." << endl;
    cout << "3) The dealer will let one of their card facing up,"
                " player will have to let two cards facing up the whole time." << endl;
    cout << "4) This game will not have any Jacks, Queens, and Kings."
            " All number cards are worth its own value." << endl;
    cout << "5) The player that has a total value closest or equal to 21 wins." << endl;
}

bool isBust(int& handTot, int limit){ //Read if the player busts = 21
    if(handTot > limit){
        cout << "Bust! You lose, better luck next time!" << endl << endl;
        return true;
    }
    return false;
}

bool isBust(int& plyTot){
    return isBust(plyTot, 21);
}

bool linSch(int arr[], int size, int key){ //linear search to see if player's sum card = 21
    for (int i = 0; i < size; i++){
        if (arr[i] == key){
            return true;
        }
    }
    return false;
}

void bubSort(vector<int>& arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                //Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void cdType(int type){ //suits in the card deck
    switch(type){
        case 1: cout << "Spade"; break;
        case 2: cout << "Heart"; break;
        case 3: cout << "Clubs"; break;
        case 4: cout << "Diamond"; break;
        default: break;
    }
}

void opt2(){
    //Declare variables
    int ans,                //player's input toward the menu settings
        cards,              //range of the total cards in a deck
        getCard,            //get card
        plyTot,             //Sum of player's cards worth
        dealTot;            //Sum of dealer's cards worth
    
    float plyBet;           //Player's bet
    
    char choice,            //Player's choice, H/S
         ansBet,            //Player's choice, Y/N to bet 
         answr;             //Player's choice if want to continue game or exit game
    
    bool cont;              //Continuation of game
    
    static int gameCnt;     //Count the number of games played
       
    //Initialize variable
    cont = true; // Control the game loop
    gameCnt = 0; // Game count
    
    do{
        //Reset variables for a new game
        plyTot = 0;
        dealTot = 0;
        vector<int> plyHand; //Player's hand
        
        //Player's option to bet alone or let the computer bet for the player
        cout << endl << "Before we start, let's place a bet! Do you want to let the computer place a random value of bet? (Y/N)" << endl;
        cin >> ansBet;

        if (ansBet == 'Y' || ansBet == 'y'){
            //computer randomly pick number from file input
            //Open input file
            fstream in;
            int rows, cols;

            in.open("out.dat",ios::in);

            //Read the number of rows and columns from the input file
            in >> rows >> cols;

            //Generate random row and column numbers within the bounds of the input file
            int randRow = rand() % rows + 1;
            int randCol = rand() % cols + 1;

            //Loop through each number in the input file and find the one corresponding to the randomly selected row and column
            for (int i = 1; i <= rows; i++){
                for (int j = 1; j <= cols; j++){
                    in >> plyBet;
                    if (i == randRow && j == randCol){
                        //Display the randomly selected number to the user as their bet
                        cout << fixed << setprecision(2) << showpoint;
                        cout << "Your bet is $" << plyBet << endl;
                    }
                }
            }
            in.close();

        //When the user choose to bet on their own
        } else if (ansBet == 'N' || ansBet == 'n'){
            cout << "Place your bet! (Remember: bet must be less than $500)" << endl;
            cin >> plyBet;

            //Player's bet cannot be more than 500
            if (plyBet > 500){
                cout << "Don't bet too much! You've exceeded the limit" << endl;
            } else { //Cannot be negative
                plyBet = abs(plyBet);
            }
            //Print the player's bet
            cout << fixed << setprecision(2) << showpoint;
            cout << "Your bet is $" << plyBet << endl;
        }

        //Cards for player
        for (int i = 1; i <= 2; i++){
            cards = rand() % 52 + 1;     //set the range to [1,52]
            getCard = cards % 11 + 1;       //set the range of value each card is worth [1,11]
            plyHand.push_back(getCard);
            cout << "Player's Card " << i <<" = " << getCard << " of ";
            cdType(rand() % 4 + 1);
            cout << endl;
        }
        
        //Sort the player's hand using bubble sort
        bubSort(plyHand);
        
        //Calculate the player's total
        for (int i = 0; i < plyHand.size(); i++){
            plyTot += plyHand[i];
        }
        cout << "Player's Total = " << plyTot << endl << endl;
        
        //Player make choice
        while (cont && (dealTot <= 21 || plyTot <= 21 || dealTot != 21 || plyTot != 21)){
            cout << "Would you like to hit or stay? (H/S)" << endl;
            cin >> choice;
            cout << endl;

            //If player choose hit
            if (choice == 'H' || choice == 'h'){
                cards = rand() % 52 + 1;
                getCard = cards % 11 + 1;
                plyHand.push_back(getCard);
                cout << "Player's new card = " << getCard << " of ";
                cdType(rand() % 4 + 1);
                cout << endl;
                plyTot += getCard;
                cout << "Player's Total = " << plyTot << endl << endl;

                //if plyTot > 21
                if (isBust (plyTot)){
                    return;
                }
                
                //Linear search for a specific card value
                int schVal = 21;
                int pCard[2],
                    numPC = 2;
                bool found = linSch(pCard, numPC, schVal);
                if (found){
                    cout << endl << "Player has a card with value of " << schVal << endl;
                } else{
                    cout << "Player does not have a card with value of " << schVal << endl;
                    cout << "I suggest to keep on going!" << endl << endl;
                }
            } else if (choice == 'S' || choice == 's'){
                //Dealer's turn to getCard
                cards = rand() % 52 + 1;
                getCard = cards % 11 + 1;
                dealTot += getCard;
                cout << "Dealer's Card = " << getCard << " of ";
                cdType(rand() % 4 + 1);
                cout << endl;
                cout << "Dealer's Total = " << dealTot << endl << endl;

                //If dealer's total value is more than 17, dealer will not take another card
                if (dealTot < 17 && dealTot != 21){
                    for (int cards = 0; cards < dealTot; cards++){
                        cards = rand() % 52 + 1;
                        getCard = cards % 11 + 1;
                    }
                    dealTot += getCard;
                    cout << "Dealer's new card = " << getCard << " of ";
                    cdType(rand() % 4 + 1);
                    cout << endl;
                    cout << "Dealer's Total = " << dealTot << endl << endl;
                } else if (dealTot > 21){
                    cout << "Dealer busts, you win!" << endl;
                    cout << "You got your bet of $ " << plyBet << " back" << endl;
                }

                //If dealer's and user's total value is less than or equal to 21
                if (dealTot <= 21 && plyTot <= 21){
                    if (dealTot > plyTot){
                        cout << "Dealer wins, you lose!" << endl << endl;
                        cont = false;
                    } else if (dealTot < plyTot){
                        cout << "Congratulations, you win!" << endl;
                        cout << "You got your bet of $ " << plyBet << " back" << endl;
                        cont = false;
                    } else{
                    cout << "It's a tie!" << endl << endl;
                    cont = false;
                    }
                }
            }
        }
        
        //Check for blackjack for Player
        if (checkBj(plyTot)){
            plyHand.clear();    //Reset to player's hand
            return;           //Continue to the next iteration of the do-while loop
        }

        //Check if the player wants to continue playing
        cout << "\nDo you want to play again? (Y/N)" << endl;
        cin >> answr;

        if (answr == 'N' || answr == 'n'){
            cont = false; //Exit the game loop if player chooses N
        } else if (answr == 'Y' || answr == 'y'){
            cont = true;  //Continue the game loop if player chooses Y
        }
        //Increment the game count after each game
        gameCnt++;
        cout << endl << "Total number of games played: " << gameCnt << endl;
    } while (cont);
    
    //Return to the main menu
    return;
}

void selSort(int arr[], int size){ //selection sort to rearrange the comments alphabetically
    for (int i = 0; i < size - 1; i++){
        int minIndx = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[minIndx]){
                minIndx = j;
            }
        }
        if (minIndx != i){
            //Swap the elements
            int temp = arr[i];
            arr[i] = arr[minIndx];
            arr[minIndx] = temp;
        }
    }
}

void opt3(){ //Print out the outro
    //Declare variable
    string cmnt;    //Player's comment about the game
    
    //Exit
    cout << endl << "Thanks for playing, see you next time!" << endl;

    //User's comment about the game
    cout << "Please leave a comment for us to improve in the future!" << endl;
    cin >> cmnt;
    
    //Sort the comment characters in ascending order
    int cmnSize = cmnt.size();
    int cmnChar[cmnSize];
    for (int i = 0; i < cmnSize; i++){
        cmnChar[i] = cmnt[i];
    }
    selSort(cmnChar, cmnSize);
    
    //Display the sorted comment characters
    cout << "\nThank you for your feedback!" << endl;
    cout << "Here is some fun fact we can give you!" << endl;
    cout << "The sorted comment (in characters) for your first word is ";
    for (int i = 0; i < cmnSize; i++){
        cout << static_cast<char>(cmnChar[i]);
    }
    cout << endl;
    
    return;
}

void def(int ans){ //Default switch case for menu
    cout << endl << "Exiting game." << endl;
    exit(0); //Terminate the program and return control to the operating system
}

bool checkBj(int plyTot){ //Check blackjack
    return (plyTot == 21) ? (cout << "Blackjack! You win!\n", true) : false;
}