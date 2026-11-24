#include <iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void gameRPS(){
int rounds;
int player1_score=0, computer_score=0,draws=0;
srand(time(0));
cout<<"Enter the number of rounds you want to play: ";
cin>>rounds;
for(int round =1 ; round<=rounds;round++){
    int player_coice,computer_choice;

 cout << "\n===== Round " << round << " =====\n";

        cout << "Choose:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout<< "Enter your choice (1-3): ";
        cin >> player_coice;
        if(player_coice < 1 || player_coice > 3){
             cout << "Invalid choice! Try again.\n";
             round--;
             continue;
        }
        computer_choice = rand() % 3 + 1; // Random choice for computer (1-3)
        if(computer_choice==1){
            cout<<"Computer chose Rock"<<endl;
        }
        else if(computer_choice==2){
            cout<<"Computer chose Paper"<<endl;
        }
        else{
            cout<<"Computer chose Scissors"<<endl;
        }
if(player_coice==computer_choice){
    cout<<"It's a draw!"<<endl;
    draws++;
}
else if((player_coice==1 && computer_choice==3) || (player_coice==2 && computer_choice==1) || (player_coice==3 && computer_choice==2)){
    cout<<"You win this round!"<<endl;
    player1_score++;
}
else{
    cout<<"Computer wins this round!"<<endl;
    computer_score++;
}
if(round==rounds){
    cout<<"\n===== Game Over =====\n";
    cout<<"Your Score: "<<player1_score<<endl;
    cout<<"Computer Score: "<<computer_score<<endl;
    cout<<"Draws: "<<draws<<endl;
    if(player1_score>computer_score){
        cout<<"Congratulations! You won the game!"<<endl;
    }
    else if(player1_score<computer_score){
        cout<<"Computer won the game! Better luck next time."<<endl;
    }
    else{
        cout<<"The game is a Draw!"<<endl;
    }
}
}

}
int main ( ){
gameRPS();

    return 0 ;
}