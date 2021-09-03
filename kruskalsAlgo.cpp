#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:

    int source;
    int dest;
    int weight;
    int cost = 0;
};
int findByParent(int v,int *parent)
{
    if(v == parent[v])
        return v;
    else
        return findByParent(parent[v],parent);
}
void KruskalsAlgo(Edge *input, int v, int e)
{
        Edge currentEdge;
        Edge output[v-1];
        int parent[v];
        for(int i = 0; i<v; i++)
        {
            parent[i] = i;
        }
        int sourceParent,destParent;
        int i = 0, j = 0;
        while(j != v-1)
        {
            currentEdge = input[i];
            sourceParent = findByParent(currentEdge.source,parent);
            destParent   = findByParent(currentEdge.dest,parent);
            if(sourceParent!=destParent)
            {
                output[j] = currentEdge;
                j++;
            }
            parent[parent[destParent]] = parent[sourceParent];
            i++;
        }
        int cost = 0;
        cout << "\nOutput :\n\n";
        for(int i = 0; i<v-1; i++)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
            cost = cost+output[i].weight;
        }
        cout << "\nCost : " << cost;
}
int main()
{
    int v,e;
    cout << "vertex : ";
    cin >> v;
    cout << "edges : ";
    cin >> e;
    int from,to;
    Edge *input,s;
    input = new Edge[e];
    for(int i = 0; i<e; i++)
    {
        cin >> from >> to >> input[i].weight;
        input[i].source = from-1;
        input[i].dest = to-1;
    }
    for(int i = 0; i<e; i++)
    {
        for(int j = 0; j<e; j++)
        {
            if(input[i].weight<input[j].weight)
            {
                swap(input[i],input[j]);
            }
        }
    }
    KruskalsAlgo(input,v,e);
}
