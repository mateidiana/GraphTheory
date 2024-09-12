#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g("data.in");
    g.printGraph();
    g.printGrade();
    cout<<"\n";
    g.kreis(0,"data.out");
    return 0;
}
