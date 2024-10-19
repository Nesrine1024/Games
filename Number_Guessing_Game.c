#include<stdio.h>
#include<time.h>
int main(){
    int N;
    srand(time(0));
    int random_number=(rand()%100)+1;
    int k=0;
    do{
    printf("Guess a number between 1 and 100: ");
    scanf("%d",&N);
        if (N<random_number){
            printf("the guess is too low ,try again!.\n");
            k++;
        }
        else if (N>random_number){
            printf("the guess is too high ,try again!.\n");
            k++;
        }
        else{
            printf("the guess is correct!.\n");
        }
    }while (random_number!=N);
    printf("the number of attempts is: %d",k);
    return 0;
}