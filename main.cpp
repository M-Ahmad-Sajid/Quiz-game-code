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

