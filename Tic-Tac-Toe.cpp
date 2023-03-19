#include<iostream>
#include<stdlib.h>
using namespace std;
char b[3][3];
char turn;
int row,col;
void showb();
void resetb(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            b[i][j] = ' ';
        }
    }
}
void update_turn(){
    turn = (turn == 'x')?'o':'x';
}
int gameover(){
    //check rows and col
    for(int i=0;i<3;i++){
        if((b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != ' ') || (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != ' '))
        return 1;
    }
    //check for both diagnols
    if((b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0]!=' ') || (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != ' ')){
        return 1;
    }
   for(int i=0;i<3;i++){
        for(int j=0;i<3;j++){
            if( b[i][j] == ' ')
                return 0;
        }
    }
return 2;
}
void take_inp(){
    int inp;
    showb();
    cout<<"\n\nPlayer "<<turn<<" 's turn\n\nEnter your move(1-9):- ";
    cin>>inp;
    if(inp < 1 || inp > 9 ){
        cout<<"\n Invalid Position....\n";
        return;
    }
    else{
    switch(inp){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
    }
    if(turn == 'x' && (b[row][col] != 'o' && b[row][col]==' ')){
         b[row][col] = turn;
        update_turn();
        return;
    }
    else if(turn == 'o' && (b[row][col] != 'x' && b[row][col]==' ')){
        b[row][col] = turn;
        update_turn();
        return;
    }
    else {
        cout<<"\nBox already filled!\n\nPlease choose another!!";
        return;
    }
    }
}
void showb(){
    cout<<"\n\n";
    cout<<b[0][0]<<"    |"<<b[0][1]<<"    |"<<b[0][2];
    cout<<" \n-----|-----|----\n";
    cout<< b[1][0]<<"    |"<<b[1][1]<<"    |"<<b[1][2];
    cout<<" \n-----|-----|----\n";
    cout<< b[2][0]<<"    |"<<b[2][1]<<"    |"<<b[2][2];
    }
int main(){
    system("cls");
    cout<<"\nEnter your choice [X] or [O]:- \n";
    cin>>turn;
    resetb();
    while(gameover()==0)
    {
    take_inp();
    }
    update_turn();
if(gameover() == 2)
        cout<<"\nDraw......\n";
     else cout<<"\n\nPlayer "<<turn<<" Won!!!!!!\n";
        showb();
    }
    






/*#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board

void display_board(){

    //Rander Game Board LAYOUT

    cout<<"PLAYER - 1 [X]t PLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"ntPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"ntPlayer - 2 [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another!!nn";
        player_turn();
    }
    /* Ends */
 /*   display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"tttT I C K -- T A C -- T O E -- G A M Ettt";
    cout<<"nttttFOR 2 PLAYERSnttt";
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"nnCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"nnCongratulations!Player with 'O' has won the game";
    }
    else
    cout<<"nnGAME DRAW!!!nn";
} 
*/




/*bool check_win(){
    return (diagnol_cross(b) || row_crossed(b) || col_crossed(b));
}
bool diagnol_cross(char b[3][3]){
    //chk diagnol
    if((b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0]!=' ') || (b[0][2] == b[1][1] && b[1][1] == b[2][1] && b[0][2] != ' '))
        return true;
    
    return false;
}
bool row_crossed(char b[][3]){
    for(int i=0;i<3;i++){
        if(b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != ' ')
        return true;
    }
    return false;
}
bool col_crossed(char b[][3]){
    for(int i=0;i<3;i++){
        if(b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != ' ')
        return true;
    }
    return false;
}*/
//bool game_over