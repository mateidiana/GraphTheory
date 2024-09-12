#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;
int main() {
    Graph g("data.in");
    g.print();
    //g.kantenzug();
    return 0;
}
