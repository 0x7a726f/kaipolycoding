#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
public:
    Graph(int V){
        VertexList.resize(V);
        DistanceList.resize(V);
        size = V;
    }

    ~Graph(){
        for(int i = 0;i < VertexList.size(); i++){
            VertexList[i].clear();
        }
    }

    void addEdge(int u, int v, int d){
        VertexList[u].push_back(v);DistanceList[u].push_back(d);
        VertexList[v].push_back(u);DistanceList[v].push_back(d);
    }

    bool travel(int start, int finish, int range, vector<int>& path, vector<int>& distances) const {
        vector<bool> visited(size, false);
        vector<int> parent(size, -1);
        vector<int> distanceFromStart(size, 0);
        path.clear();
        distances.clear();
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == finish){
                int current = finish;
                while(current != -1){
                    path.push_back(current);
                    current = parent[current];
                }
                reverse(path.begin(), path.end());
                for(int vertex : path){distances.push_back(distanceFromStart[vertex]);}
                return true;
            }
            for(int i = 0;i < VertexList[u].size();i++){
                int v = VertexList[u][i];
                int distance = DistanceList[u][i];
                if(!visited[v] && distance <= range){
                    visited[v] = true;
                    parent[v] = u;
                    distanceFromStart[v] = distanceFromStart[u] + distance;
                    q.push(v);
                }
            }
        }
        return false;
    }
private:
    int size;
    vector<vector<int>> VertexList;
    vector<vector<int>> DistanceList;
};

int refill(vector<int>& distances, int range){
    int sum = 0;
    int counter = 1;
    int temprange = range;
    for(int i = distances.size()-1;i > 0;i--){distances[i] = distances[i]-distances[i-1];}
    for(int i = 1;i < distances.size();i++){  
        if(temprange < distances[i]){temprange = range - distances[i];counter++;}  
        else{temprange -= distances[i];}  
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, temp1, temp2, dist, set, start, finish, range;
    cin >> n >> m;
    Graph myGraph(n);
    for(int i = 0;i < m;i++){
        cin >> temp1 >> temp2 >> dist;
        myGraph.addEdge(temp1, temp2, dist);
    }
    cin >> set;
    for(int i = 0;i < set;i++){
        cin >> start >> finish >> range;
        vector<int> path,distances;
        if(myGraph.travel(start, finish, range, path, distances)){
            cout << "POSSIBLE: " << refill(distances,range) << " fill(s), ";  
            for(int i = 0;i < path.size()-1;i++){cout << path[i] << " ";} 
            cout << path[path.size()-1]; 
            cout << endl;
        }
        else {cout << "IMPOSSIBLE" << endl;}
    }
}