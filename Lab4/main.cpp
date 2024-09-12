#include <iostream>
#include "Graph.h"
#include <vector>
using namespace std;
int main() {
    Graph g("data.in");
    g.printList();
    cout<<"\n";
    g.shortestPath(0,4);

    return 0;
}
