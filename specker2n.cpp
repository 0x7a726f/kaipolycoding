#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Player {
    public:
        Player(const string &n) : name(n) {}

        virtual ~Player(){name.clear();}

        virtual const string & getType() const = 0;

        virtual Move play(const State &s) = 0;

        friend ostream & operator << (ostream &out, const Player &player){
            out << player.getType() << " player " << player.name;  
            return out; 
        }
    protected:
        string name;
};

class GreedyPlayer : public Player {
    public:
        GreedyPlayer(const string &n) : Player(n) , type("Greedy"){}

        virtual const string & getType() const override{return type;}

        virtual Move play(const State &s){
            int select = s.getCoins(0);
            int res = 0;
            for(int i = 1;i<s.getHeaps();i++){
                if(s.getCoins(i)>select){select = s.getCoins(i);res = i;}
            }
            Move a(res,s.getCoins(res),0,0);
            return a;
        }
    private:
        string type;
};

class SpartanPlayer : public Player {
    public:
        SpartanPlayer(const string &n) : Player(n) , type("Spartan"){}

        virtual const string & getType() const override{return type;}

        virtual Move play(const State &s){
            int select = s.getCoins(0);
            int res = 0;
            for(int i = 1;i<s.getHeaps();i++){
                if(s.getCoins(i)>select){select = s.getCoins(i);res = i;}
            }
            Move a(res,1,0,0);
            return a;
        }
    private:
        string type;
};

class SneakyPlayer : public Player {
    public:
        SneakyPlayer(const string &n) : Player(n) , type("Sneaky"){}

        virtual const string & getType() const override{return type;}

        virtual Move play(const State &s){
            int select = 1000000000;
            int res = 0;
            for(int i = 0;i<s.getHeaps();i++){
                if(s.getCoins(i)<select && s.getCoins(i)!=0){select = s.getCoins(i);res = i;}
            }
            Move a(res,s.getCoins(res),0,0);
            return a;
        }
        private:
            string type;
};

class RighteousPlayer : public Player {
    public:
        RighteousPlayer(const string &n) : Player(n) , type("Righteous"){}
        
        virtual const string & getType() const override{return type;}

        virtual Move play(const State &s){
            int select = s.getCoins(0);
            int res = 0;int trg = 0;
            for(int i = 1;i<s.getHeaps();i++){
                if(s.getCoins(i)>select){select = s.getCoins(i);res = i;}
            }
            select = s.getCoins(0);
            for(int i = 1;i<s.getHeaps();i++){
                if(s.getCoins(i)<select){select = s.getCoins(i);trg = i;}
            }
            int c = s.getCoins(res);
            Move a(res,ceil(1.0*c/2),trg,ceil(1.0*c/2)-1);
            return a;
        }
        private:
            string type;
};
