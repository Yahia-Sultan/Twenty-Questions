#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Yahia Sultan
// CEG 3310 Lab 5

//Reads in input and returns it
char *read()
{
    static char str[1000];
    fgets(str,1000, stdin);
    return str;
}

int main()
{
    int current = 0; //iteration counter
    int playAgain = 1;
    int qLen = 0; // sets counter for question array
    int aLen = 1; //sets counter for animal array
    char questions[20][100]; //initializes question array
    int qArr[20]; // question answer array
    char animals[20][10]; //initializes animal array
    strcpy(animals[0], "dog"); //adds dogs as the first animal

    while(playAgain == 1){

        //Asks identifying questions about that would lead to guessing the animal
        int guess = current;
        if(qLen >= 1){
            for(int i = 0; i < qLen; ++i){
                char *answer;
                printf("%s \n > ", questions[i]);
                answer = read();
                if(strcmp("yes", strlwr(answer)) == -1){
                    guess = qArr[i];
                    break;
                }
                if(current < 2){
                    guess--;
                }
            }
        }

        // Guesses the animal
        char *correct;
        printf("Is it a %s?\n > ", animals[guess]);
        correct = read();
        if(strcmp("yes", strlwr(correct)) == -1){
            printf("I won!\n");
            // Asks user if they would like to play once again
            printf("Would you like to play again?\n > ");
            correct = read();
            if(strcmp("yes", strlwr(correct)) == 1){ //if answer is "yes", the value of the comparison would be '-1'
                playAgain = 0;
                break;
            }
            else {
                continue;
            }
        }

        // Adds the animal you thought of to the array
        char *newAnimal;
        printf("I lose! what animal were you thinking of?\n > ");
        newAnimal = read();
        strcpy(animals[aLen], strtok(strlwr(newAnimal), "\n"));
        aLen++;

        // Adds an identifying question to the list
        printf("Please give me a yes/no question that distinguishes between a %s and a %s\n > "
               , animals[guess], animals[current+1]);
        char *ans;
        ans = read();
        strcpy(questions[qLen], strtok(ans, "\n"));
        qLen++;

        // Saves the animal who's answer is yes, to the question array
        printf("Would the answer to this question be a yes or no for a %s?\n > ", strtok(animals[guess], "\n"));
        correct = read();
        if(strcmp("yes", strlwr(correct)) == -1){
            qArr[qLen-1] = guess;
        }else{
            qArr[qLen-1] = current+1;
        }

        // Asks user if they would like to play once again
        printf("Would you like to play again?\n > ");
        correct = read();
        if(strcmp("yes", strlwr(correct)) == 1){ //if answer is "yes", the value of the comparison would be '-1'
            playAgain = 0;
            break;
        }


        current++;
    }

    printf("Thanks for playing!\n");

    // Printing Cleaning node's for each animal and question
    for(int i = 0; i < aLen; ++i){
        printf("Cleaning node: %s\n", animals[i]);
    }
    for(int i = 0; i < qLen; ++i){
        printf("Cleaning node: %s\n", questions[i]);
    }

    // Resets question and animal arrays and counters
    memset(questions, 0, sizeof(questions));
    memset(animals, 0, sizeof(animals));
    qLen = 0;
    aLen = 1;

    //End
    return 0;
}


