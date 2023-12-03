#include <iostream>
using namespace std;
int fact(int x){
    if(x == 1 || x == 0){return 1;}
    else{return x*fact(x-1);}
}
int num;
int main(){
    cin >> num;
    for(int i = 0;1<2;i++){
        if(num < fact(i)){cout << i-1 << endl;break;}
    }
}