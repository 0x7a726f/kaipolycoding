#include <iostream>
#include <cmath>
using namespace std;
class Polynomial {
    protected:
        class Term {
            protected:
                int exponent;
                int coefficient;
                Term *next;
                Term(int exp, int coeff, Term *n) : exponent(exp) , coefficient(coeff) , next(n) {}
                friend class Polynomial;
                friend Polynomial operator + (const Polynomial &p, const Polynomial &q);  
                friend Polynomial operator * (const Polynomial &p, const Polynomial &q);  
                friend ostream & operator << (ostream &out, const Polynomial &p);
        };
        Term *front;

        void del(){
            if(front != nullptr){
                Term *j = front;
                while(j != nullptr){
                    Term *a = j;
                    j = j->next;
                    delete a;
                }
            }
            front = nullptr;
        }
        
        void push_back(int exp,int coeff){
            if(front == nullptr){
                front = new Term(exp,coeff,nullptr);
            }
            else{
                Term *p = front;
                while(p->next != nullptr){
                    p = p->next;
                }
                p->next = new Term(exp,coeff,nullptr);
            }
        }

        void copy(const Polynomial &p){  
            for(Term *j = p.front;j!= nullptr;j = j->next){  
                push_back(j->exponent, j->coefficient);  
            }  
        } 
    public:
        Polynomial(){front = nullptr;}

        Polynomial(const Polynomial &p){front = nullptr;copy(p);}

        ~Polynomial(){del();}

        Polynomial & operator = (const Polynomial &p){del();copy(p);return *this;}

        void addTerm(int expon, int coeff) {
            if(front == nullptr){push_back(expon, coeff);}
            else if(expon > front->exponent){
                Term *a = new Term(expon, coeff, front);
                front = a;
            }else{
                Term *p = front;
                while(p != nullptr){
                    if(p->exponent == expon){
                        p->coefficient += coeff;
                        return;
                    }else if(p->next == nullptr || p->next->exponent < expon){
                        Term *a = new Term(expon, coeff, p->next);
                        p->next = a;
                        return;
                    }
                    p = p->next;
                }
            }
        }

        double evaluate(double x){
            double sum = 0;
            if(front == nullptr){return 0;}
            else{
                Term *p = front;
                while(p != nullptr){
                    if(p->coefficient != 0){
                        if(p->exponent == 0){sum += p->coefficient;}
                        else{sum += pow(x,p->exponent)*p->coefficient;}
                    }
                    p = p->next;
                }
                return sum;
            }
        }

        friend Polynomial operator+ (const Polynomial &p, const Polynomial &q){
            Polynomial result = p;
            Term *j = q.front; 
            while(j != nullptr){
                result.addTerm(j->exponent,j->coefficient);
                j = j->next;
            }
            return result;
        }

        friend Polynomial operator* (const Polynomial &p, const Polynomial &q){
            Polynomial result;
            Term *j = p.front; 
            while(j != nullptr){
                Term *i = q.front;
                while(i != nullptr){
                    result.addTerm(j->exponent+i->exponent,j->coefficient*i->coefficient);
                    i = i->next;
                }
                j = j->next;
            }
            return result;
        }

        friend ostream & operator << (ostream &out, const Polynomial &p){
            if(p.front == nullptr){out << "0";return out;}
            Term *j = p.front;

            while(j->coefficient == 0 && j->next != nullptr){j = j->next;}
            if(j->coefficient == 0){out << 0;return out;}
            int coeff = j->coefficient;
            int expon = j->exponent;
            if(abs(coeff) == 1 && expon == 0){coeff == 1 ? out << "1" : out << "- 1";return out;}

            if(coeff > 0){coeff != 1 ? out << coeff : out << "";}
            else{{coeff != -1 ? out << "- " << -coeff : out << "- ";}}

            if(expon > 0){expon != 1 ? out << "x^" << expon : out << "x";}

            j = j->next;
            while(j != nullptr){
                int coeff = j->coefficient;
                int expon = j->exponent;
                if(abs(coeff) == 1 && expon == 0){coeff == 1 ? out << " + 1" : out << " - 1";return out;}
                if(coeff != 0){
                    if(coeff > 0){coeff != 1 ? out << " + " << coeff : out << " + ";}
                    else{{coeff != -1 ? out << " - " << -coeff : out << " - ";}}
                    
                    if(expon > 0){expon != 1 ? out << "x^" << expon : out << "x";}
                }
                j = j->next;
            }
            return out;
        }
};
