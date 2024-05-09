#include <iostream>
#include <vector>
using namespace std;

class UF {
    private:
        vector<int> parent;
        int numSets;
    public:
        UF(int size){
            parent.resize(size);
            numSets = size;
            for(int i = 0;i < size;i++){parent[i] = i;}
        }

        int find(int x){
            return (parent[x] == x) ? x : find(parent[x]);
        }

        void unify(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY){return;}
            parent[rootY] = rootX;
            numSets--;
        }

        int getNumSets() const {return numSets;}
};
int main(){
    ios_base::sync_with_stdio(false);
    int n,m,k,temp1,temp2;
    cin >> n >> m >> k;
    UF union1(n);
    for(int i = 0;i < m;i++){
        cin >> temp1 >> temp2;
        union1.unify(temp1,temp2);
    }
    union1.getNumSets()-k >= 1? cout << union1.getNumSets()-k << endl : cout << 1 << endl;
}
