#include<stdio.h>
#include<stdlib.h>
char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char currentPlayer = 'O';

char switchPlayer(char currentPlayer){
    if (currentPlayer=='X') {
        return currentPlayer='O';  
    } else {
        return currentPlayer='X';
    }
}
void printBoard(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i<3){
                printf(" %c |",board[i][j]);
            }
        }
        if(i<2){
                printf("\n---|---|---\n");
        }
    }
}

int checkWin() {
    for (int i=0;i<3;i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return 1;
            }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
            } 
   
    }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            return 1;
            }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            return 1;
        }
        return 0;
}
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; 
            }
        }
    }
    return 1;
}
int main(){
    int gameEnd=0;
    while (!gameEnd){
        int row=0;
        int col=0;
        printBoard();
        printf("\nPlayer %c,enter your move by specifying row and column:",currentPlayer);
        scanf("%d %d",&row,&col);
        if (row<1 || row>3 || col<1 || col>3){
            printf("Invalid move. Try again.\n");
            continue;
        }
        row-=1;
        col-=1;
        if (board[row][col]=='X' || board[row][col]=='O') {
            printf("Spot already taken.Try again.\n");
            continue;
        }
        board[row][col]=currentPlayer;
        if (checkWin()) {
            printBoard();
            printf("\nPlayer %c wins!\n",currentPlayer);
            gameEnd=1;
        } else if (checkDraw()) {
            printBoard();
            printf("\nIt's a draw!\n");
            gameEnd=1;
        } else {
            currentPlayer=switchPlayer(currentPlayer);
        }
    }
    return 0;
}