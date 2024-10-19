#include<stdio.h>
#include<time.h>
#include <string.h>
#include <stdlib.h>
int main(){
    const char *word[3]={"rock","paper","scissors"};
    srand(time(0));
    int computer_choice=rand()%3;
    int user_choice,try_again;
    do
    {
        printf("choose one: 1-rock, 2-paper, or 3-scissors:\n");
        scanf("%d",&user_choice);
        user_choice--;
        if (user_choice == computer_choice){
            printf("Drow.");
            printf("Wanna try again?.\n1.yes 2.no\n");
            scanf("%d",&try_again);
        }
        else if ((user_choice==0 && computer_choice==2) || (user_choice==1 && computer_choice==0) || (user_choice==2 && computer_choice==1))
        {
            printf("You win!!.\n");
            printf("The computer choose:%s.\n",word[computer_choice]);
            printf("Wanna try again?.\n1.yes 2.no\n");
            scanf("%d",&try_again);
        }
        else{
            printf("You lose :( \n");
            printf("The computer choose:%s.\n",word[computer_choice]);
            printf("Wanna try again?.\n1.yes 2.no\n");
            scanf("%d",&try_again);
        }
    } while (try_again==1);
    return 0;
}