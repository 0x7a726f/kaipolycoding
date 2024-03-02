#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string word = "";
    string result = "";
    vector <string> wordlist;
    char c;
    c = getchar();
    while(c != EOF){
        if(c != '\n'){
            if(c != ' ' && c != '\n'){word += c;}
            else{
                if(word != ""){wordlist.push_back(word);}
                word = "";
            }
        }
        else{
            wordlist.push_back(word);
            word = "";
            reverse(wordlist.begin(),wordlist.end());
            for(int i =0;i< (int)wordlist.size()-1;i++){
                result = result + wordlist[i] + " ";
            }
            result = result + wordlist[(int)wordlist.size()-1];
            result = result + '\n';
            wordlist.erase(wordlist.begin(),wordlist.end());
        }
        c = getchar();
    }
    cout << result;
}
