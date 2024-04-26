#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int vertex;
    int edge;
    cin >> vertex >> edge;
    vector<int> matrix(vertex,0);
    for(int i = 0;i<edge;i++){
        int temp;
        cin >> temp;
        matrix[temp]++;
        cin >> temp;
        matrix[temp]++;
    }
    int res1 = -1;
    int res2 = -1;
    int counter = 0;
    for(int i = 0;i<vertex;i++){
        if(matrix[i]%2 == 1){
            if(counter < 2){res1 == -1 ? res1 = i : res2 = i;counter++;}
            else{counter = 10;break;}
        }
    }
    if(counter>2 || counter == 1){cout << "IMPOSSIBLE\n";}
    else if(counter == 0){cout << "CYCLE\n";}
    else{cout << "PATH ";res1 < res2 ? cout << res1 << " " << res2 : cout << res2 << " " << res1;cout << endl;}
}
