#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


Graph::Graph(string filename) {
    ifstream f;
    f.open(filename);
    f>>n;
    f>>m;
    int x,y,z;
    for (int i=0;i<m;i++)
    {
        f>>x>>y>>z;
        vec.push_back(Edge{x,y,z});
    }
}

void Graph::printList() {
    for (int i=0;i<m;i++)
    {
        cout<<vec[i].v1<<" "<<vec[i].v2<<" "<<vec[i].c;
        cout<<"\n";
    }
}

void Graph::shortestPath(int knoten1, int knoten2) {
    vector<int>distance;
    vector<int>previous;
    int tempDistance;
    for (int i=0;i<n;i++)
    {
        distance.push_back(123456);
        previous.push_back(-1);
    }
    distance[knoten1]=0;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (vec[j].v2==i)
            {
                tempDistance=distance[vec[j].v1]+vec[j].c;
                if (tempDistance<distance[i])
                {
                    distance[i]=tempDistance;
                    previous[i]=vec[j].v1;
                }
            }

        }
    }
    for (int j=0;j<n;j++)
    {
        if (j==knoten2&&distance[j]==123456)
            cout<<"Kein Weg";
        if (j==knoten2&&distance[j]<0)
            cout<<"Negativer Zyklus";
        if (j==knoten2&&distance[j]>=0&&distance[j]!=123456)
        {
            cout<<distance[j];
            cout<<'\n';
            weg(previous,j);
        }

    }
}

void Graph::weg(vector<int> prev,int node) {
    if (prev[node]!=-1)
        weg(prev,prev[node]);
    cout<<node<<' ';
}
