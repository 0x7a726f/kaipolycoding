#include <iostream>
#include <vector>
using namespace std;
class Graph {
    public:
        Graph(int V){
            size = V;
            VertexList = new node*[V];
            for(int i = 0;i < V;i++){
                VertexList[i] = new node;
            }
        }

        ~Graph(){
            for(int i = 0;i < size;i++){
                delete VertexList[i];
            }
            delete [] VertexList;
        }

        void addEdge(int u, int v){
            VertexList[u]->AdjList.push_back(v);
        }

        //bool cycle(vector<int> &path) const;
    private:
        int size;
        struct node{
            vector<int> AdjList;
        };
        node** VertexList;   
};
