#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Game {
    public:
        Game(int heaps, int players){
            HeapTotal = heaps;HeapCounter = 0;
            PlayerTotal = players;PlayerCounter = 0;
            HeapList = new int[HeapTotal];
            PlayerList = new Player*[PlayerTotal];
        }

        ~Game(){delete[] HeapList;delete [] PlayerList;}

        void addHeap(int coins) throw(logic_error){
            if(coins < 0){throw logic_error("Negative coins!");}
            else if(HeapCounter >= HeapTotal){throw logic_error("All heaps are already added!");}
            else{HeapList[HeapCounter++] = coins;}
        }

        void addPlayer(Player *player) throw(logic_error){
            if(PlayerCounter >= PlayerTotal){throw logic_error("All players are already added!");}
            else{PlayerList[PlayerCounter++] = player;}
        }

        void play(ostream &out) throw(logic_error){
            if((HeapCounter != HeapTotal) ||(PlayerCounter!= PlayerTotal)){throw logic_error("Add players and heaps correctly!");}
            else{
                State Gameplay(HeapTotal,HeapList,PlayerTotal);
                while(!Gameplay.winning()){
                    out << "State: " << Gameplay << endl;
                    Move PlayerMove = PlayerList[Gameplay.getPlaying()]->play(Gameplay);
                    out << *PlayerList[Gameplay.getPlaying()] << " " << PlayerMove << endl;
                    Gameplay.next(PlayerMove);
                }
                out << "State: " << Gameplay << endl;
                if(Gameplay.getPlaying()==0){out << *PlayerList[PlayerCounter-1] << " wins" << endl;}
                else{out << *PlayerList[Gameplay.getPlaying()-1] << " wins" << endl;}
            }
        }

        int getPlayers() const {return PlayerTotal;}

        const Player *getPlayer(int p) const throw(logic_error){
            if(p < 0 || p > PlayerTotal){throw logic_error("Wrong index");}
            else{return PlayerList[p];}
        }
    private:
        int HeapTotal;
        int HeapCounter;
        int PlayerTotal;
        int PlayerCounter;
        int *HeapList;
        Player **PlayerList;
};
