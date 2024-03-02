#ifndef CONTEST
#include "fullratio.hpp"
#endif
#include <iostream>
using namespace std;

int rational::gcd(int a , int b){
    int R;
    while((a % b) > 0){
        R = a % b;a = b;b = R;
    }  
    return b;
}

rational::rational(int n, int d){
    int e = gcd(abs(n),abs(d));
    if(n*d >= 0){nom = abs(n/e);den = abs(d/e);}
    else{nom = -abs(n/e);den = abs(d/e);}
}

rational operator +(const rational &x, const rational &y){
    int a = x.nom*y.den + y.nom*x.den;int b = x.den*y.den;
    int c = rational::gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

rational operator -(const rational &x, const rational &y){
    int a = x.nom*y.den - y.nom*x.den;int b = x.den*y.den;
    int c = rational::gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

rational operator *(const rational &x, const rational &y){
    int a = x.nom*y.nom;int b = x.den*y.den;
    int c = rational::gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

rational operator /(const rational &x, const rational &y){
    int a = x.nom*y.den;int b = x.den*y.nom;
    int c = rational::gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

ostream& operator<<(ostream &out,const rational &x){
    if(x.nom*x.den >= 0){out << abs(x.nom) << "/" << abs(x.den);}
    else{out << -abs(x.nom) << "/" << abs(x.den);}
    return out;
}