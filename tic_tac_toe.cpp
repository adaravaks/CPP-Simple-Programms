#include <iostream>
#include <ctime>
using namespace std;

void draw_board(char *spaces);
void player_move(char *spaces, char player);
void computer_move(char *spaces, char computer);
string check_winner(char *spaces, char player, char computer);
bool check_tie(char *spaces);

int main(){
    char spaces[] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    char player = 'X';
    char computer = 'O';
    string winner;

    draw_board(spaces);

    while(true){
        player_move(spaces, player);
        draw_board(spaces);
        winner = check_winner(spaces, player, computer);
        if(winner != "No one"){
            cout << winner << " is winner. Congratulations!";
            break;
        }

        computer_move(spaces, computer);
        cout << "Computer has made a move:\n";
        draw_board(spaces);
        winner = check_winner(spaces, player, computer);
        if(winner != "No one"){
            cout << winner << " is winner. Congratulations!";
            break;
        }

        if(check_tie(spaces)){
            cout << "It's a tie! No one won this time.";
            break;
        }
    }

    return 0;
}

void draw_board(char *spaces){
    cout << spaces[0] << ' ' << spaces[1] << ' ' << spaces[2] << '\n';
    cout << spaces[3] << ' ' << spaces[4] << ' ' << spaces[5] << '\n';
    cout << spaces[6] << ' ' << spaces[7] << ' ' << spaces[8] << '\n';
}

void player_move(char *spaces, char player){
    int choice;
    cout << "Select a cell to place your mark at (1-9): ";
    cin >> choice;

    if(spaces[choice-1] == '*'){
        spaces[choice-1] = player;
    }
    else{
        cout << "This cell is unavailable.\n";
        player_move(spaces, player);
    }
    
}

void computer_move(char *spaces, char computer){
    srand(time(0));

    while(true){
        int choice = rand() % 9;
        if(spaces[choice] == '*'){
            spaces[choice] = 'O';
            break;
        }
        if(check_tie(spaces)){
            break;
        }
    }
}


string check_winner(char *spaces, char player, char computer){
    for(int cell = 0; cell < 9; cell+=3){  // Checks rows
        if(spaces[cell] == 'X' && spaces[cell+1] == 'X' && spaces[cell+2] == 'X'){
            return "Player";
        }
        else if(spaces[cell] == 'O' && spaces[cell+1] == 'O' && spaces[cell+2] == 'O'){
            return "Computer";
        }
    }

    for(int cell = 0; cell < 3; cell++){  // Checks columns
        if(spaces[cell] == 'X' && spaces[cell+3] == 'X' && spaces[cell+6] == 'X'){
            return "Player";
        }
        else if(spaces[cell] == 'O' && spaces[cell+3] == 'O' && spaces[cell+6] == 'O'){
            return "Computer";
        }
    }

    for(int cell = 0; cell < 3; cell+=2){  // Checks diagonals
        for(int step = 4; step >= 2; step-=2){
            if((cell == 0 && step == 2) || (cell == 2 && step == 4)){
                continue;
            }

            if(spaces[cell] == 'X' && spaces[cell + step] == 'X' && spaces[cell + (step * 2)] == 'X'){
                return "Player";
            }
            else if(spaces[cell] == 'O' && spaces[cell + step] == 'O' && spaces[cell + (step * 2)] == 'O'){
                return "Computer";
            }
        }
    }
    return "No one";
}

bool check_tie(char *spaces){
    for(int cell = 0; cell < 9; cell++){
        if(spaces[cell] != '*'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
