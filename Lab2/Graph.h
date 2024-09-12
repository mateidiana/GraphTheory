#ifndef LAB2_GRAPH_H
#define LAB2_GRAPH_H
#include <vector>
#include <utility>
#include <string>
using namespace std;

class Graph {
private:
    int n;
    int matrix[100][100];
    int gradfolge[100];

public:
    Graph(string s);
    void Gradfolge();
    void printGraph();
    void printGrade();
    void kreis(int x, string filename);

};

#endif //LAB2_GRAPH_H
