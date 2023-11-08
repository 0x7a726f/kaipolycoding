#include <iostream>
#include <string>
#include <algorithm> 
#include <iomanip>
using namespace std;
int n,i;
float result = 0;
string palindrome = "";
int PalindromeLength;
int main(){
    int n;
    cin >> n;
    cin.sync();
    for(i=1;i<=n;i++){
        string palindrome = "";
        getline(cin,palindrome);
        if(palindrome.empty()){cout << "empty";continue;}
        PalindromeLength = palindrome.length();
        if(PalindromeLength > 20){
            cout << "error";
            continue;
        }
        string temp = palindrome;
        reverse(palindrome.begin(), palindrome.end()); 
        if(temp == palindrome){
            cout << "yes";
            result = result + 1.0;
            continue;
        }
        else{
            cout << "no";
            continue;
        }
    }
    float a = result/n;
    cout << fixed << setprecision(3) << a*100.000;

}
