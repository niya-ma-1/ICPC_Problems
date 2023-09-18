#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"
using namespace std;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    vector< list<int> > players(2);

    string card;
    int val;

    int turn = 0;
    for(int i=0; i < 52; ++i){
        cin >> card;

        if (card[1] == 'J'){
            val = 1;
        }
        else if (card[1] == 'Q'){
            val = 2;
        }
        else if (card[1] == 'K'){
            val = 3;
        }
        else if (card[1] == 'A'){
            val = 4;
        }
        else{
            val = 0;
        }
        
        if (turn){
            players[turn].push_front(val); 
        }
        else{
             players[turn].push_front(val);
        }
        
        turn = !turn;
    }

    list<int> game;

    bool cycle = false;

    while (!players[turn].empty()){

        int currCard = players[turn].front();
        players[turn].pop_front();

        game.push_back(currCard);

        turn = !turn;

        while(currCard){
            if (players[turn].empty()){
                cycle = false;
                break;
            }
            else{
                cycle = true;
            }

            int card = players[turn].front();
            players[turn].pop_front();

            game.push_back(card);

            if (card){
                turn = !turn;
                currCard = card;
            }
            else{
                --currCard;
            }
        }

        if (cycle){
            cycle = false;

            turn = !turn;

            while (!game.empty()){
                players[turn].push_back(game.front());
                game.pop_front();
            }
        }

    }

    if(players[0].empty()){
		cout << "1 " << setw(2) << players[1].size() << "\n"; 
    }
		// If the nondealer is not empty tenh the winner is the nondealer. 
    else{
		cout << "2 " << setw(2) << players[0].size() << "\n";
    }
    return 0;
}
