//
// Created by Diana on 15-May-2024.
//

#include "Graph.h"
#include <iostream>
#include<fstream>
using namespace std;

Graph::Graph(string filename) {
    ifstream f;
    f.open(filename);
    f>>n;
    f>>m;
    head=nullptr;
    int node1,node2;
    for (int i=0;i<m;i++)
    {
        f>>node1>>node2;
        if (head== nullptr)
            head=new Edge{node1,node2, nullptr};
        else
        {
            Edge* aux = new Edge{node1,node2, nullptr};
            aux->next=head;
            head=aux;
        }
    }
    for (int i=1;i<=n;i++)
        besucht.push_back(0);
}

void Graph::print()
{
    Edge *node=head;
    while(node!= nullptr)
    {
        cout<<node->x<<" "<<node->y<<"\n";
        node=node->next;
    }
}

void Graph::kantenzug() {
    vector<int> grade;
    for (int i=1;i<=n;i++)
        grade[i]=0;

    Edge *node=head;
    while(node!=nullptr)
    {
        grade[node->x]+=1;
        grade[node->y]+=1;
        node=node->next;
    }
    for (int i=1;i<=n;i++)
        if(grade[i]%2!=0 || grade[i]==0)
        {
            cout<<"Keinen moglichen eulerschen Kantenzug"; break;
        }


    dfs(1);
    int ok=0;
    for (int i=0;i<kantenzugGraph.size()-1;i++)
    {
        Edge *node=head;
        while(node!= nullptr)
        {
            if ((node->x==kantenzugGraph[i] && node->y==kantenzugGraph[i+1]) || (node->y==kantenzugGraph[i] && node->x==kantenzugGraph[i+1]))
                ok=1;
            node=node->next;
        }
        if (i==kantenzugGraph.size()-1)
        {
            Edge *node1=head;
            while(node1!= nullptr)
            {
                if (!(node1->x==kantenzugGraph[0] && node1->y==kantenzugGraph[i]) && !(node1->y==kantenzugGraph[i] && node1->x==kantenzugGraph[0]))
                    ok=0;
                node1=node1->next;
            }
        }
    }
    if (ok==1)
    {
        cout<<"Kantenzug gefunden";
        for (int i=0;i<kantenzugGraph.size();i++)
            cout<<kantenzugGraph[i];
    }
    else
    {
        vector<int> prevKantenzug;
        for (int i=0;i<kantenzugGraph.size();i++)
            prevKantenzug.push_back(kantenzugGraph[i]);

        for (int k=2;k<=n;k++)
        {
            for (int j=0;j<=k;j++)
            {
                kantenzugGraph[j]=0;
                besucht[j]=0;
            }
            dfs(k);
            ok=0;
            for (int i=0;i<kantenzugGraph.size()-1;i++)
            {
                Edge *node=head;
                while(node!= nullptr)
                {
                    if ((node->x==kantenzugGraph[i] && node->y==kantenzugGraph[i+1]) || (node->y==kantenzugGraph[i] && node->x==kantenzugGraph[i+1]))
                        ok=1;
                    node=node->next;
                }
                if (i==kantenzugGraph.size()-1)
                {
                    Edge *node1=head;
                    while(node1!= nullptr)
                    {
                        if (!(node1->x==kantenzugGraph[0] && node1->y==kantenzugGraph[i]) && !(node1->y==kantenzugGraph[i] && node1->x==kantenzugGraph[0]))
                            ok=0;
                        node1=node1->next;
                    }
                }
            }

            if (ok==1)
            {
                cout<<"Kantenzug gefunden";
                for (int i=0;i<kantenzugGraph.size();i++)
                    cout<<kantenzugGraph[i];
                break;
            }
            else{
                prevKantenzug=kantenzugGraph;
            }
        }
        cout<<"Keinen eulerschen Kantenzug";
    }

}

void Graph::dfs(int startNode) {
    besucht[startNode]=1;
    kantenzugGraph.push_back(startNode);
    for (int i=1;i<=n;i++)
    {
        Edge *node=head;
        while(node!= nullptr)
        {
            if (((node->x==startNode && node->y==i) || (node->x==i&&node->y==startNode))&&besucht[i]==0)
                dfs(i);
            node=node->next;
        }
    }
}