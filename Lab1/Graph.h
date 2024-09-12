
#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H
#include<vector>
#include<bits/stdc++.h>
#include<utility>
using namespace std;

class Graph {
private:

    int n;
    int m;
    int matrix[100][100];
    vector<int>adjList[100];
    vector<int>edgeList[100];
    vector<pair<int,int>> edgeList2[100];

public:

    Graph();

    void addEdge(int x, int y);

    void addList(int x, int y);

    void addEdgeList(int i, int x, int y);

    bool isEdge(int x, int y);

    void maximGrad();

    void minimGrad();

    void printGraph();

    void printGraphList();

    void printGraphEdgeList();


};

#endif //LAB1_GRAPH_H
