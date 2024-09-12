//
// Created by Diana on 15-May-2024.
//

#ifndef LAB6_GRAPH_H
#define LAB6_GRAPH_H
#include <vector>
#include <string>
using namespace std;

struct Edge {
    int x;
    int y;
    Edge *next;
};

class Graph {

private:
    int n,m;
    Edge *head;
    vector<int>besucht;
    vector<int> kantenzugGraph;

public:
    Graph(string filename);
    void print();
    void kantenzug();
    void dfs(int startNode);
};


#endif //LAB6_GRAPH_H
