//
// Created by Diana on 27-Mar-2024.
//

#include "Graph.h"
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

GewichteterGraph::GewichteterGraph() {

}

GewichteterGraph::GewichteterGraph(string filename) {

    ifstream f;
    f.open(filename);
    f>>n;
    f>>m;


    for (int i=0;i<n;i++)
    {
        vector<int> aux;
        for (int j=0;j<n;j++)
            aux.push_back(0);
        kostenmatrix.push_back(aux);
    }
    int x,y,c;
    for (int i=0;i<m;i++)
    {
        f>>x>>y>>c;
        addEdge(x,y,c);
    }
}

void GewichteterGraph::addEdge(int x, int y, int c) {
    kostenmatrix[x][y]=c;
    kostenmatrix[y][x]=c;
}

bool GewichteterGraph::isEdge(int x, int y) {
    return kostenmatrix[x][y]!=0;
}

void GewichteterGraph::printMatrix() {
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<kostenmatrix[i][j]<<" ";
        cout<<"\n";
    }
}

int GewichteterGraph::gesamtkosten() {
    int kosten=0;
    int mini,lin=0,col=0;
    int S[50];
    for (int i=0;i<n;i++)
        S[i]=0;
    S[0]=1;
    for (int k=0;k<n-1;k++)
    {
        mini=2147483647;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (S[i]==1&&S[j]==0&&mini>kostenmatrix[i][j]&&kostenmatrix[i][j]!=0)
                {
                    mini=kostenmatrix[i][j];
                    lin=i;
                    col=j;
                }
        kosten+=mini;
//        cout<<lin<<' '<<col<<' '<<mini<<"\n";
        S[col]=1;
    }
    return kosten;
}

GewichteterGraph GewichteterGraph::minimalerSpannbaum() {
    GewichteterGraph g1;
    for (int i=0;i<n;i++)
    {
        vector<int> aux;
        for (int j=0;j<n;j++)
            aux.push_back(0);
        g1.kostenmatrix.push_back(aux);
    }

    int kosten=0;
    int mini,lin=0,col=0;
    int S[50];
    for (int i=0;i<n;i++)
        S[i]=0;
    S[0]=1;
    for (int k=0;k<n-1;k++)
    {
        mini=2147483647;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (S[i]==1&&S[j]==0&&mini>kostenmatrix[i][j]&&kostenmatrix[i][j]!=0)
                {
                    mini=kostenmatrix[i][j];
                    lin=i;
                    col=j;
                }
        kosten+=mini;
        g1.kostenmatrix[lin][col]=mini;
        g1.kostenmatrix[col][lin]=mini;
        //cout<<lin<<' '<<col<<' '<<mini<<"\n";
        S[col]=1;
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<g1.kostenmatrix[i][j]<<" ";
        cout<<"\n";
    }
    return g1;
}
