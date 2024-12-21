#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void playGame() {       // Function of the main game logic and scoreboard
    string name;
    int age;
    
    cout<<"Hello"<<endl;

    // Get user name and age
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    
    char choice;// Asking user if he/she wants to play
    cout << name << ", do you want to play the quiz game? (y/n): ";
    cin >> choice;


    if (choice == 'y' || choice == 'Y') { //checking options
        int score = askQuestions();  // to get the score from the quiz
     // displaying score
             cout << "\n" << name << " | you scored : " << score;


           // saving the name and score in the file
        ofstream scoreFile;
          scoreFile.open("scoreboard.txt", ios::app);  // Open in append mode
        if (scoreFile.is_open()) {
            scoreFile << name << " " << score<< " out of 20"<< endl;
            scoreFile.close();  // Close the file after writing
        } 
		else {
            cout << "Error opening the scoreboard file.\n";
        }
        
        
        cout<<"\nGood Bye";
        

        //to display the scoreboard
          cout << "\nScoreboard:\n";
         ifstream scoreFileRead("scoreboard.txt");
        string line;
        while (getline(scoreFileRead, line)) {
            cout << line << endl;
        }
    } 
	else {
        cout << "Maybe next time, " << name << "!\n";
    }
}


int main() {
	

    cout << "Welcome to the Quiz Game!\n";
    
    playGame();  // Start the game
    
    
    return 0;
}
