
#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

Graph::Graph(){

    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdge(x,y);
        addList(x,y);
        addEdgeList(i,x,y);

    }

}

void Graph::addEdge(int x, int y){
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

void Graph::addList(int x, int y) {
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

void Graph::addEdgeList(int i, int x, int y) {
    edgeList[i].push_back(x);
    edgeList[i].push_back(y);
//    edgeList2[i].push_back(make_pair(x,y));
    edgeList2[i].emplace_back(x,y);
}

bool Graph::isEdge(int x, int y){
    return matrix[x][y] == 1;
}

void Graph::maximGrad() {
    int max=0,s;
    for (int i=0;i<m;i++)
    {
        s=0;
        for (int j=0;j<m;j++)
        {
            s+=matrix[i][j];
        }
        if (s>max)
            max=s;

    }
    cout<<"Der maximale Grad im Graph ist: "<<max<<endl;
}

void Graph::minimGrad() {
    int max=10000,s;
    for (int i=0;i<m;i++)
    {
        s=0;
        for (int j=0;j<m;j++)
        {
            s+=matrix[i][j];
        }
        if (s<max)
            max=s;

    }
    cout<<"Der minimale Grad im Graph ist: "<<max<<endl;
}

void Graph::printGraph(){
    cout<<"Adjazenzmatrix:"<<endl;
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Graph::printGraphList() {
    cout<<"Adjazenzliste:"<<endl;
    for (int i=0;i<m;i++)
    {
        cout<<i<<":"<<" "<<"[ ";
        for (int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
}

void Graph::printGraphEdgeList() {
    cout<<endl<<"Kantenvektor:"<<endl;
    for (int i=0;i<m;i++)
    {
        cout<<"[ ";
        for (int j=0;j<edgeList[i].size();j++)
        {
            cout<<edgeList[i][j]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    cout<<endl;


    cout<<endl<<"Kantenvektor als Pairs:"<<endl;

    for(int i=0;i<m;i++)
        for (int j=0;j<edgeList2[i].size();j++){
            cout<<edgeList2[i][j].first<<" ";
            cout<<edgeList2[i][j].second<<"\n";
        }

}

