#include <iostream>
#include <string>
using namespace std;
char cipher(char gramma , int distance){return gramma + distance;}
char decipher(char gramma , int distance){return gramma - distance;}
char lower(char ch) {return ch - 'A' + 'a';}
char upper(char ch){return ch + 'A' - 'a';}
int distancelist[26];
char cipherlist[26];
int i,j;
char c;
string text = "";string result = "";
int main(){
    for(i=0;i<26;i++){
        char temp;
        cin >> temp;
        cipherlist[i] = temp;
        distancelist[i] = -(int)'a'-i+(int)temp;
    }
    int skip = 0;
    for(i=0;i<26;i++){
        if((int)cipherlist[i] < 'a' || (int)cipherlist[i] > 'z'){skip = 1;}
    }
    for(i=0;i<26;i++){
        int count = 0;
        for(j=0;j<26;j++){
            if((int)cipherlist[j]-(int)'a'-i == 0){count+=1;}
        }
        if(count>1){skip=1;break;}
    }
    if(skip == 1){cout<< "error" << endl;}
    else{
        cin.ignore();
        char choice = getchar();
        cin.ignore(256,'\n');
        c = getchar();
        while(c != EOF){
            text += c;
            c = getchar();
        }
        int N = text.length();
        if(choice != 'd'){
            for(i=0;i<N;i++){
                if(text[i] >= 'a' && text[i] <= 'z'){result += cipher(text[i],distancelist[abs((int)('a'- text[i]))]);}
                else if(text[i] >= 'A' && text[i] <= 'Z'){result += cipher(text[i],distancelist[abs((int)('a'- lower(text[i])))]);}
                else{result += text[i];}
            }
            cout << result;
        }
        else{
            for(i=0;i<N;i++){
                char keepletter; 
                if(text[i] >= 'a' && text[i] <= 'z'){
                    for(j=0;j<26;j++){if((int)'a'+j+distancelist[j]==(int)text[i]){keepletter = 'a'+j;}}
                    result += keepletter;
                }
                else if(text[i] >= 'A' && text[i] <= 'Z'){
                    for(j=0;j<26;j++){if((int)'a'+j+distancelist[j]==lower(text[i])){keepletter = 'a'+j;}}
                    result += upper(keepletter);
                }
                else{result += text[i];}
            }
            cout << result;
        }
    }
}
