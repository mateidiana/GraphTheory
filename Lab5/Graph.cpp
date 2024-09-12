//
// Created by Diana on 29-May-2024.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(string s) {
    ifstream f;
    f.open(s);
    f >>n>>m;
    int x,y;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            matrix[i][j]=0;
    for(int i=0; i<m; i++){
        f>>x>>y;
        matrix[x][y]=1;
        matrix[y][x]=1;
    }
    int z;
    for (int i=0;i<3;i++)
    {
        f>>z;
        partition1.push_back(z);
    }
    for (int i=0;i<3;i++)
    {
        f>>z;
        partition2.push_back(z);
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

vector<pair<int,int>> Graph::ungAlgorithm(){
    vector<pair<int,int>> matching= randomMatching(0);
    int newMatrix[100][100];
    //1
    for (int i=0;i<matching.size();i++)
    {
        {
            int found=0;
            for (int j=0;j<partition1.size();j++)
                for (int k=0;k<partition2.size();k++)
                    if (matching[i].first==j&&matching[i].second==k||matching[i].first==k&&matching[i].second==j)
                    {
                        newMatrix[k][j]=1;
                        found=1;
                    }
            if (found==0)
            {
                for (int j=0;j<partition1.size();j++)
                    for (int k=0;k<partition2.size();k++)
                        if (matrix[j][k]==1)
                            newMatrix[j][k]=1;
            }

        }

    }
    //2
    vector<int> f1;
    vector<int> f2;
    for (int i=0;i<partition1.size();i++)
    {
        int found=0;
        for (int j=0;j<matching.size();j++)
            if (i==j)
                found=1;
        if (found==0)
            f1.push_back(i);
    }
    for (int i=0;i<partition2.size();i++)
    {
        int found=0;
        for (int j=0;j<matching.size();j++)
            if (i==j)
                found=1;
        if (found==0)
            f2.push_back(i);
    }

    //3
    vector<int> r2;
    for (int i=0;i<partition2.size();i++)
        if (weg(f1[0]).size()!=0)
            r2.push_back(i);

    //4
    vector<pair<int,int>>matching2;
    bool haveCommon=true;
    int v2;
    while(haveCommon)
    {
        int found=0;
        for (int i=0;i<r2.size();i++)
            for (int j=0;j<f2.size();j++)
                if (i==j)
                {
                    //5
                    found=1;
                    v2=i;
                }

        if (found==0)
            haveCommon=false;
        //6

        pair<int,int> pair2;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<partition2.size();k++)
                    if (i==k&&newMatrix[i][j]==1)
                    {
                        pair2= make_pair(i,j);
                        matching2.push_back(pair2);
                    }

    }
    return matching2;
};

vector<pair<int,int>> Graph::randomMatching(int knoten) {
    vector<int> used;
    for (int i=0;i<n;i++)
        used.push_back(0);
    vector<pair<int,int>> matching;
    pair<int,int> edge;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i==knoten && matrix[i][j]!=0)
            {
                edge= make_pair(i,j);
                matching.push_back(edge);
                used[i]=1;
                used[j]=1;
            }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=edge.first&&j!=edge.second&&i!=edge.second&&j!=edge.first&&used[i]==0&&used[j]==0)
            {
                edge= make_pair(i,j);
                matching.push_back(edge);
                used[i]=1;
                used[j]=1;
            }
    return matching;

}

vector<int> Graph::weg(int knoten1) {

    s[knoten1]=1;
    dfs.push_back(knoten1);
    for (int i=1;i<=n;i++)
        if (matrix[knoten1][i]==1&&s[i]==0)
        {
            dfs.push_back(i);
            weg(knoten1);
        }

    return dfs;
}
