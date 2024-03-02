#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
string matrix[1000];
int results[1000];
int n;
float result = 0;
string palindrome;
int main(){
    cin >> n; 
    cin.ignore();
    for(int i = 0;i<n;i++){
        getline(cin,matrix[i]);
        if(matrix[i].empty()){results[i] = 2;}
    }
    for(int j = 0;j<n;j++){
        palindrome = matrix[j];
        int palindromeLength = palindrome.length();
        if(palindromeLength > 20){
            results[j] = 3;
        }
        if(palindromeLength>0 && palindromeLength<21){
            string temp = palindrome;
            reverse(palindrome.begin(), palindrome.end()); 
            if(temp == palindrome){
                results[j] = 1;
                result = result + 1.0;
                continue;
            }
            else{results[j] = 0;}
        }
    }
    for(int k = 0;k<n;k++){
        if(results[k]==0){cout << "no\n";continue;}
        if(results[k]==1){cout << "yes\n";continue;}
        if(results[k]==2){cout << "empty\n";continue;}
        if(results[k]==3){cout << "error\n";continue;}
    }
    float a = result/n;
    cout << fixed << setprecision(3) << a*100;
}
