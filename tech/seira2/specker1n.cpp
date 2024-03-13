#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Move {
    public:
        // Take sc coins from heap sh and put tc coins to heap th.
        Move(int sh, int sc, int th, int tc) : SourceHeap(sh) , SourceCoins(sc) , TargetHeap(th) , TargetCoins(tc) {};

        int getSource() const {return SourceHeap;}

        int getSourceCoins() const {return SourceCoins;}

        int getTarget() const {return TargetHeap;}

        int getTargetCoins() const {return TargetCoins;}

        friend ostream & operator << (ostream &out, const Move &move){
            out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts ";
            move.getTargetCoins() != 0 ? out << move.getTargetCoins() << " coins to heap " << move.getTarget() : out << "nothing";
            return out;
        }
    private:
        int SourceHeap , SourceCoins , TargetHeap , TargetCoins;
};

class State {
    public:
        // State with h heaps, where the i-th heap starts with c[i] coins.
        // A total of n players are in the game, numbered from 0 to n-1,
        // and player 0 is the first to play.
        State(int h, const int c[], int n){
            HeapTotal = h;
            HeapList = new int[h];
            for(int i = 0;i < h;i++){HeapList[i] = c[i];}
            PlayerTotal = n;
            Playing = 0;
        }

        ~State(){delete[] HeapList;}

        void next(const Move &move) throw(logic_error){
            if((move.getSource() < 0 || move.getSource() >= HeapTotal) || (move.getTarget() < 0 || move.getTarget() >= HeapTotal)){
                throw logic_error("Invalid Heap ");
            }
            else if(move.getSourceCoins() <= 0 || move.getTargetCoins() < 0){
                throw logic_error("Invalid move");
            }
            else if(move.getSourceCoins() > getCoins(move.getSource()) || move.getSourceCoins() <= move.getTargetCoins()){
                throw logic_error("Invalid coins");
            }
            else{
                HeapList[move.getSource()] -= move.getSourceCoins();
                HeapList[move.getTarget()] += move.getTargetCoins();
                Play();
            }
        }

        bool winning() const {
            for(int i = 0;i < HeapTotal;i++){
                if(HeapList[i] > 0){return false;}
            }
            return true;
        }

        int getHeaps() const {return HeapTotal;}

        int getCoins(int h) const throw(logic_error){
            if(h < 0 || h >= HeapTotal){throw logic_error("Invalid heap");}
            else{return HeapList[h];}
        }

        int getPlayers() const{return PlayerTotal;}

        int getPlaying() const{return Playing;}

        friend ostream & operator << (ostream &out, const State &state){
            string res = "";
            for(int i = 0;i < state.HeapTotal;i++){res = res + to_string(state.HeapList[i]) + ", ";}
            res.pop_back();
            res.pop_back();
            res = res + " with " + to_string(state.Playing) + "/" + to_string(state.PlayerTotal) + " playing next";
            out << res;
            return out;
        }
    private:
        int HeapTotal;
        int *HeapList;
        int PlayerTotal;
        int Playing;
        void Play(){Playing == PlayerTotal - 1 ? Playing = 0 : Playing++;}
};
