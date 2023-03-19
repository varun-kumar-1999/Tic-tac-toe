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
   



