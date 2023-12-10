#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> lista,listb,listc;
    int temp;
    for(int i = 0;i<n;i++){
        cin >> temp;
        lista.push_back(temp);
    }
    for(int i = 0;i<n;i++){
        cin >> temp;
        listb.push_back(temp);
    }
    sort(lista.begin(),lista.end());
    sort(listb.begin(),listb.end());
    bool same = true;
    for(int i = 0;i<n;i++){
        if(lista[i] != listb[i]){
            listc.push_back(lista[i]);
            listc.push_back(listb[i]);
            same = false;
        }
    }
    sort(listc.begin(),listc.end());
    if(same){cout << "yes" << endl;}
    else{
        cout << "no " << listc[0] << " " << listc[listc.size()-1] << endl;
    }
}