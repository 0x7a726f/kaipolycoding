#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string word = "";
    vector <string> wordlist,wordline;
    char c;
    c = getchar(); 
    while(c != EOF){
        if(c != ' ' && c != '\n'){word += c;}
        else{
            if(word != ""){wordlist.push_back(word);}
            word = "";
        }
        c = getchar();
    }
    string text;
    int i = 0;
    for(i;i<(int)wordlist.size()-1;i++){text += wordlist[i] + " ";}
    text += wordlist[i];
    if(text.length()<61){
        cout << text << endl;
    }
    else{
        i = 0;
        string linetext = "";
        int sum = 0;
        while(wordlist.empty() != 1){
            for(i = 0;(linetext.length() + wordlist[i].length() < 61) && (i < wordlist.size());i++){
                linetext = linetext + wordlist[i] + " ";
                sum = sum + (int)wordlist[i].length() + 1;
                wordline.push_back(wordlist[i]);
            }
            if(linetext.length()<60-i-1 && wordlist.size() < 10){
                for(int z = 0;z < (int)wordline.size() - 1;z++){cout << wordline[z] << " ";}
                cout << wordline[(int)wordline.size()-1];
            }
            else{
                int availableSpaces = (int)wordline.size() - 1;
                int spaces = 61 - sum;
                string space = " ";
                int x;
                if(availableSpaces !=0)
                    if(spaces%availableSpaces == 0){
                        x = spaces/availableSpaces;
                        for(int y = 0;y<x;y++){space += " ";}
                        for(int z = 0;z < (int)wordline.size() - 1;z++){cout << wordline[z] << space;}
                        cout << wordline[(int)wordline.size()-1];
                    }
                    else{
                        int atleast = 0;
                        while(spaces- (atleast+1)*availableSpaces>0){atleast++;}
                        int morespace = spaces- atleast*availableSpaces;
                        string space = " ";
                        for(int m = 0;m<atleast;m++){space += " ";}
                        for(int n = 0;n<(int)wordline.size()-1;n++){
                            if((int)wordline.size()-1-n>morespace){
                                cout << wordline[n] << space;
                            }
                            else{cout << wordline[n] << space << " ";}
                        }
                        cout << wordline[(int)wordline.size()-1];
                    }
                }
                wordline.erase(wordline.begin(),wordline.end());
                wordlist.erase(wordlist.begin(),wordlist.begin()+i);
                cout << endl;
                i = 0;
                linetext = "";
                sum = 0;

        }

    }
}