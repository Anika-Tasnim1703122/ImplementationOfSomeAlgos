#include<bits/stdc++.h>
using namespace std;
#define V 6
#define infinity 1000000
int mindist(int dist[],bool flag[])
{
    int min = infinity, min_indx;
    for(int v = 0; v < V; v++)
    {
        if(dist[v]<= min && flag[v]==false)

           {
                min = dist[v],min_indx = v;
           }
    }
    return min_indx;
}
int getPath(int v,int parent[])
{
    if(parent[v]==v)
        return v;
    else
        {
            cout << v << " ";
            getPath(parent[v],parent);
    //cout << v << "\t";
        }
}
void dijkstra(int src, int adjmat[V][V])
{
    int dist[V];
    bool flag[V];
    int parent[V];
    for(int v = 0; v < V; v++)
    {
        dist[v] = infinity;
        flag[v] = false;
        parent[v] = -1;
    }
    parent[0] = 0;
    dist[src] = 0;
    for(int c = 0; c < V-1; c++)
    {
        int u = mindist(dist,flag);
        flag[u] = true;
        for(int v = 0;v < V; v++)
        {
            if (!flag[v] && adjmat[u][v] && dist[u] != infinity
				&& dist[u] + adjmat[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u]+adjmat[u][v];
            }
        }
    }
    cout << "------vertexAndDistance--------"<< endl;
    for(int i = 0; i<V; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
    cout << "---------------------------------"<< endl;
    cout <<"------PATH--------"<<endl;
    for(int i = 0; i<V; i++)
    {
        cout << getPath(i,parent) << endl;
    }
    //printSolution(dist,parent);
}
int main()
{
    int adjmat[V][V];

    for(int i = 0; i<V; i++)
    {
        for(int j = 0;j<V; j++)
        {
            adjmat[i][j] = 0;
        }
    }
    adjmat[0][1] = 1;
    adjmat[1][0] = 1;
    adjmat[0][2] = 2;
    adjmat[2][0] = 2;
    adjmat[1][2] = 4;
    adjmat[2][1] = 4;
    adjmat[1][3] = 6;
    adjmat[3][1] = 6;
    adjmat[2][4] = 3;
    adjmat[4][2] = 3;
    adjmat[3][4] = 1;
    adjmat[4][3] = 1;
    adjmat[3][5] = 2;
    adjmat[5][3] = 2;
    adjmat[4][5] = 1;
    adjmat[5][4] = 1;
    dijkstra(0,adjmat);

}
