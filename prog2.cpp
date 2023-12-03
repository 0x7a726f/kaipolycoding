#include <iostream>
using namespace std;
int main(){
    int num;
    cin >> num;
    if(((num % 6) != 0 ) && ((num % 7 ) == 0)){cout << "yes" << endl;}
    else{cout << "no" << endl;}
}