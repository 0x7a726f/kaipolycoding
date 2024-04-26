#include <iostream>
#include <vector>
using namespace std;
class Graph {
    public:
        Graph(int V);
        ~Graph();
        void addEdge(int u, int v);
        bool cycle(vector<int> &path) const;
};