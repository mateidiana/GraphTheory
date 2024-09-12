#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(string s) {
    ifstream f;
    f.open(s);
    f >> n;
    int x,y;
    for(int i=0; i<n; i++){
        for (int j=0;j<n;j++)
            f>>matrix[i][j];
    }
}

void Graph::printGraph() {
    for(int i=0; i<n; i++){
        for (int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void Graph::Gradfolge() {
    int grad;
    for (int i=0;i<n;i++)
    {
        grad=0;
        for (int j=0;j<n;j++)
        {
            grad+=matrix[i][j];
        }
        gradfolge[i]=grad;
    }
}

void Graph::printGrade() {
    int aux;
    Gradfolge();
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (gradfolge[i]<gradfolge[j])
            {
                aux=gradfolge[i];
                gradfolge[i]=gradfolge[j];
                gradfolge[j]=aux;
            }
    for (int i=0;i<n;i++)
        cout<<gradfolge[i]<<" ";
}

void Graph::kreis(int x,string filename) {
    ofstream g(filename);
    int cnt=0;

    vector<int>adjList[100];

    for (int i=0;i<n;i++)
        if (matrix[x][i]==1)
        {
            adjList[cnt].push_back(i);
            cnt+=1;
        }

    for (int j=0;j<cnt;j++)
        for (int i=0;i<n;i++)
            if (matrix[i][adjList[j][0]]==1)
                adjList[j].push_back(i);

    for (int i=0;i<cnt;i++)
        for (int j=1;j<adjList[i].size();j++)
            if (adjList[i][j]!=x && matrix[adjList[i][j]][x]==1 && adjList[i][0]<adjList[i][j])
                g<<x<<" "<<adjList[i][0]<<" "<<adjList[i][j]<<"\n";

}


