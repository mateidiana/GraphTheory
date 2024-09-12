//
// Created by Diana on 27-Mar-2024.
//

#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class GewichteterGraph {
private:

    int n; //Anzahl Knoten
    int m;  // Anzahl Kanten
    std::vector<std::vector<int>> kostenmatrix;


public:

    GewichteterGraph();

    GewichteterGraph(std::string filename);

    void addEdge(int x, int y, int c);

    bool isEdge(int x, int y);

    int gesamtkosten();

    GewichteterGraph minimalerSpannbaum();

    void printMatrix();


};


#endif //LAB3_GRAPH_H

