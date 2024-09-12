#include "Graph.h"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(){

    Graph g;
    cout<<g.isEdge(0,1)<<endl;

    g.printGraph();
    g.printGraphList();
    g.printGraphEdgeList();

    g.maximGrad();
    g.minimGrad();
}
