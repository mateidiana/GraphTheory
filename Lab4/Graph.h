#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H
#include <vector>
#include <string>
using namespace std;

struct Edge{
    int v1;
    int v2;
    int c;
};

class Graph {
private:
    int n;
    int m;
    vector<Edge> vec;

public:
    Graph(string filename);
    void shortestPath(int knoten1,int knoten2);
    void weg(vector<int>prev,int node);
    void printList();
};


#endif //LAB4_GRAPH_H
