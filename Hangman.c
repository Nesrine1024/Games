#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    const char*wordList[] = {"science", "writing", "reading"};
    int attempts=9;
    char guess;
    int guessedCorrectly[7]={0};
    int correctGuesses=0;
    srand(time(0));
    const char *word=wordList[rand()%3];
    printf("_ _ _ _ _ _ _\n");
    while(attempts>0 && correctGuesses<7){
        printf("Guess a letter: ");
        scanf("%c", &guess);
        int found=0;
        for(int i=0;i<7;i++) {
            if(word[i]==guess && guessedCorrectly[i]==0){
                guessedCorrectly[i]=1;
                correctGuesses++;
                found=1;
            }
        }
        if(!found) {
            attempts--;
            printf("Wrong guess! Attempts remaining: %d\n",attempts);
        }
        printf("Word: ");
        for(int i=0;i<7;i++) {
            if(guessedCorrectly[i]){
                printf("%c ",word[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");
    }

    if(correctGuesses==7){
        printf("Congratulations! You guessed the word: %s\n",word);
    }else{
        printf("Sorry, you've run out of attempts.The word was: %s\n",word);
    }
   return 0;
}