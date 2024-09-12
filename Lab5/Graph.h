//
// Created by Diana on 29-May-2024.
//

#ifndef LAB5_GRAPH_H
#define LAB5_GRAPH_H


#include <vector>
#include <utility>
#include <string>
using namespace std;

class Graph {
private:
    int n,m;
    int matrix[100][100];
    vector<int> partition1;
    vector<int> partition2;
    vector<int>s;
    vector<int>dfs;

public:
    Graph(string s);
    void printGraph();
    vector<pair<int,int>> randomMatching(int knoten);
    vector<pair<int,int>> ungAlgorithm();
    vector<int> weg(int knoten1);
};


#endif //LAB5_GRAPH_H
