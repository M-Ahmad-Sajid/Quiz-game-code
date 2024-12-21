#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int askQuestions() {   // Function to ask questions and calculate score
    int score = 0;  // Initialize score


      
	  // Array of MCQs, their options and the correct answers
      
      
    string questions[20] = { // here are the questions
        "What is the capital of France?\n1. Paris\n2. Berlin\n3. Madrid\n4. Rome", //1
        "Which is the largest planet?\n1. Earth\n2. Jupiter\n3. Mars\n4. Venus",//2
        "What is the boiling point of water(All choices are in celcius?\n1. 100\n2. 90\n3. 80\n4. 120",//3
        "In tennis players, which side of elbow gets injured?\n1. Inside\n2. Outside\n3. Front\n4. Behind",//4
        "In golf player injury is common to which part?\n1. Hand\n2. Elbow\n3. Arm\n4.Fingers",//5
        "Who won the FIFA World Cup in 2018?\n1. Brazil\n2. Germany\n3. France\n4. Argentina",//6
        "Which club has won most uefa champions league titles?\n1. Real Madrid\n2. Barcelona\n3. Chelsea\n4. Manchester City",//7
        "Who is the GOAT in football?\n1. Cristiano Ronaldo\n2. Lionel Messi\n3. Robert Lewandowski\n4. Neymar Jr",//8
        "In which country did the first ever FIFA World Cup take place in 1930?\n1. Brazil\n2. Italy\n3. Uruguay\n4. Argentina",//9
        "What is the primary business focus of Andrew Tate's 'Hustler's University'?\n1. Fitness coaching\n2. Financial independence and online business\n3. Fashion design\n4. Travel and tourism",//10
        "Who wrote the play 'Romeo and Juliet'?\n1. Charles Dickens\n2. William Shakespeare\n3. Mark Twain\n4.Jane Austen",//11
        "What is the largest ocean in the world?\n1. Atlantic Ocean\n2. Indian Ocean\n3. Southern Ocean\n4. Pacific Ocean",//12
        "Who invented the telephone?\n1. Nikola Tesla\n2. Alexander Graham Bell\n3. Thomas Edison\n4. Benjamin Franklin",//13
        "In which year did World War II end?\n1. 1939\n2.1941\n3. 1950\n4. 1945",//14
        "What is the currency of Japan?\n1.  Yuan\n2. Won\n3. Yen\n4.  Ringgit",//15
        "Which country is known as the 'Land of the Rising Sun'?\n1. China\n2. South Korea\n3. Japan\n4. Thailand",//16
        "The Great Wall of China was primarily built to protect against invasions from which group?\n1. Mongols\n2. Japanese\n3. Persians\n4. Romans",//17
        "Which element has the chemical symbol 'O'?\n1. Oxygen\n2.  Osmium/n3. Ozone\n4.  Opium",//18
        " Which city is known as the 'Big Apple'?\n1. Los Angeles\n2. Chicago\n3. New York City\n4. Miami",//19
        " In which country did the Olympic Games originate?\n1. Italy/n2. Greece\n3. France\n4. Germany"
        
         
    };

	
    int answers[20] = {1, 2, 1, 2, 2, 3, 1, 1, 3, 2, 2, 4, 2, 4, 3, 3, 1, 1, 3, 2}; // Correct answers of mcqs

    for (int i = 0; i < 20; i++) {
        int choice;
        cout << questions[i] << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;


        // Checking  the answer 
        if (choice == answers[i]) {
            score++;  // Increase score for correct answer
        }
        
    }

    return score;  // Returning final score
}





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
