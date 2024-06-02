#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
    public:
        Graph(int V){VertexList = new vector<int>[V];size = V;}

        ~Graph(){
            for(int i = 0;i < VertexList->size();i++){VertexList[i].clear();}
            delete [] VertexList;
        }

        void addEdge(int u, int v){VertexList[u].push_back(v);}

        bool cycle(vector<int> &path) const{
            vector<bool> visited(size, false);
            vector<bool> recStack(size, false);
            stack<int> dfsStack;

            for(int i = 0; i < size; i++){
                if(dfs(i, visited, recStack, dfsStack, path)){return true;}
            }
            return false;
        }
    private:
        int size;
        vector<int>* VertexList;   
        bool dfs(int v, vector<bool>& visited, vector<bool>& recStack, stack<int>& dfsStack, vector<int>& path) const{
            if(!visited[v]){
                visited[v] = true;
                recStack[v] = true;
                dfsStack.push(v);
                for(int u : VertexList[v]){
                    if(!visited[u] && dfs(u, visited, recStack, dfsStack, path)){return true;} 
                    else if(recStack[u]){//back-edge wowow
                        while(!dfsStack.empty() && dfsStack.top() != u){
                            path.insert(path.begin(),dfsStack.top());
                            dfsStack.pop();
                        }
                        path.insert(path.begin(),u);
                        return true;
                    }
                }
            }
            recStack[v] = false;
            return false;
        }
};
