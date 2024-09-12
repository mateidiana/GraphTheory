#include <iostream>
#include "Graph.h"
int main() {
    GewichteterGraph g("data.in");
    g.printMatrix();
    cout<<"\n\n";
    cout<<g.gesamtkosten();
    cout<<"\n\n";
    g.minimalerSpannbaum();
    return 0;
}

