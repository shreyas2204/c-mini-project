#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_TRIES 6
void rps();
void rng();
void hang();
#define MAX_USERS 10
typedef struct {
    char username[20];
    char password[20];
    int isAdmin;
} User;
User users[MAX_USERS];
int addUser(char username[], char password[], int isAdmin) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].username[0] == '\0') {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            users[i].isAdmin = isAdmin;
            return 1; 
        }
    }
    return 0; 
}
int loginUser(char username[], char password[]) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].isAdmin; 
        }
    }
    return -1; 
}

int main(){
    int end=1,n;
    printf("##############################################\n");
    printf("-----------WELCOME TO THE GAMER PLAYER---------\n");
    printf("###############################################\n\n");
    for (int i = 0; i < MAX_USERS; i++) {
        users[i].username[0] = '\0';
    }
    addUser("admin", "admin123", 1); 
    addUser("user1", "password1", 0); 
    addUser("user2", "password2", 0); 
    char username[20], password[20];
    int isAdmin;
    printf("Login Page\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    isAdmin = loginUser(username, password);
    if (isAdmin == 1) {
        printf("Admin login successful!\n");
        start();
    } else if (isAdmin == 0) {
        printf("User login successful!\n");
        start();
    } else {
        printf("Login failed. Invalid username or password.\n");
    }
    return 0;

}
void start(){
     int end=1,n;
      while (end>0){
        printf("ENTER THE GAME U WANT TO PLAY\n");
        printf("1.GUESS THE NUMBER\n2.ROCK PAPER SCISSORS\n3.HANG-MAN\n4.EXIT\n");
        printf("\nENTER YOUR CHOICE:\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                rng();
                break;
            case 2:
                rps();
                break;
            case 3:
                hang();
                break;
            case 4:
                printf("THANK YOU FOR PLAYING!");
                end-=1;
                break;
            default:
                printf("PLEASE ENTER A VALID INPUT");
        }
        
    }
}

void rps(){
    srand(time(NULL));
    const char *choices[] = {"rock", "paper", "scissors"};
    int computerChoice = rand() % 3;
    char playerChoice[20];

    printf("Welcome to Rock Paper Scissors!\n");
    printf("Enter your choice (rock, paper, or scissors): ");
    scanf("%s", playerChoice);

    printf("Computer chose: %s\n", choices[computerChoice]);

    if (strcmp(playerChoice, choices[computerChoice]) == 0)
        printf("It's a tie!\n");
    else if (
        (strcmp(playerChoice, "rock") == 0 && strcmp(choices[computerChoice], "scissors") == 0) ||
        (strcmp(playerChoice, "paper") == 0 && strcmp(choices[computerChoice], "rock") == 0) ||
        (strcmp(playerChoice, "scissors") == 0 && strcmp(choices[computerChoice], "paper") == 0)
    )
        printf("You win!\n");
    else
        printf("Computer wins!\n");

}
void hang(){
    char *chooseRandomWord(char *words[], int wordCount) {
    srand(time(NULL));
    return words[rand() % wordCount];
    }

    char *wordList[] = {"apple", "banana", "cherry", "grape", "orange"};
    int wordCount = sizeof(wordList) / sizeof(wordList[0]);

    char *selectedWord = chooseRandomWord(wordList, wordCount);
    int wordLength = strlen(selectedWord);

    int incorrectGuesses = 0;
    int correctGuesses = 0;
    char guessedLetters[wordLength];
    for (int i = 0; i < wordLength; i++) {
        guessedLetters[i] = '_';
    }

    printf("Welcome to Hangman!\n");

    while (incorrectGuesses < MAX_TRIES && correctGuesses < wordLength) {
        printf("Guess the word: ");
        for (int i = 0; i < wordLength; i++) {
            printf("%c ", guessedLetters[i]);
        }
        printf("\n");

        char guess;
        printf("Enter your guess: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (selectedWord[i] == guess && guessedLetters[i] != guess) {
                guessedLetters[i] = guess;
                correctGuesses++;
                found = 1;
            }
        }

        if (!found) {
            incorrectGuesses++;
            printf("Incorrect guess! %d attempts left.\n", MAX_TRIES - incorrectGuesses);
        }
    }

    if (correctGuesses == wordLength) {
        printf("Congratulations! You guessed the word: %s\n", selectedWord);
    } else {
        printf("Sorry, you're out of attempts. The word was: %s\n", selectedWord);
    }


}

void rng(){
    srand(time(NULL));  
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("Choose a difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    
    int difficulty;
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &difficulty);
    
    int maxRange;
    if (difficulty == 1) {
        maxRange = 50;
    } else if (difficulty == 2) {
        maxRange = 100;
    } else if (difficulty == 3) {
        maxRange = 200;
    } else {
        printf("Invalid choice. Exiting...\n");
    }
    
    int secretNumber = rand() % maxRange + 1;
    int guess, attempts = 0;
    
    printf("Guess a number between 1 and %d\n", maxRange);
    
    do {
        attempts++;
        printf("Attempt %d: Enter your guess: ", attempts);
        scanf("%d", &guess);
        
        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", secretNumber, attempts);
            break;
        }
    } while (1);
    


}

