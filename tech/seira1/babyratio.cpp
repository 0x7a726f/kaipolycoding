#ifndef CONTEST
#include "babyratio.hpp"
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

rational rational::add(rational r){
    int a = nom*r.den + r.nom*den;int b = den*r.den;
    int c = gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

rational rational::sub(rational r){
    int a = nom*r.den - r.nom*den;int b = den*r.den;
    int c = gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

rational rational::mul(rational r){
    int a = nom*r.nom;int b = den*r.den;
    int c = gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

rational rational::div(rational r){
    int a = nom*r.den;int b = den*r.nom;
    int c = gcd(abs(a),abs(b));
    return rational(a/c , b/c);
}

void rational::print(){
    if(nom*den >= 0){cout << abs(nom) << "/" << abs(den);}
    else{cout << -abs(nom) << "/" << abs(den);}
}
