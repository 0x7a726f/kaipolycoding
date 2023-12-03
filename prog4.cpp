#include <iostream>
#include <string>
using namespace std;
int main(){
    int num;
    cin >> num;
    num *= num;
    string numstr = to_string(num);
    if(numstr[numstr.length()-2]=='2' && numstr[numstr.length()-1]=='4'){cout << "yes" << endl;}
    else{cout << "no" << endl;}
}