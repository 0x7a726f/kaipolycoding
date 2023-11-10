#include <iostream>
using namespace std;
int a1,a2,a3,a4,a5,a6,a7,a8;
int i,j,n;
int powermatrix[10] = {0,1,2,3,4,5,6,7,8,9};
int power(int x, int p) {
  int i = 1;
  for (int j = 1; j <= p; j++)  i *= x;
  return i;
}
int main(){
    cin >> n;
    for(i=0;i<=9;i++){
        powermatrix[i] = power(powermatrix[i],n);
    }
    for(a1=0;a1<=9;a1++){
        for(a2=0;a2<=9;a2++){
            for(a3=0;a3<=9;a3++){
                for(a4=0;a4<=9;a4++){
                    for(a5=0;a5<=9;a5++){
                        for(a6=0;a6<=9;a6++){
                            for(a7=0;a7<=9;a7++){
                                for(a8=0;a8<=9;a8++){
                                    long number = (a8+10*a7+100*a6+1000*a5+10000*a4+100000*a3+1000000*a2+10000000*a1);
                                    long sum = (powermatrix[a1]+powermatrix[a2]+powermatrix[a3]+powermatrix[a4]+powermatrix[a5]+powermatrix[a6]+powermatrix[a7]+powermatrix[a8]);
                                    if( number == sum){
                                        cout << number << endl;
                                    }  
                                }
                            }
                        }
                    }
                }
            } 
        } 
    }
}}
