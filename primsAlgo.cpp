#include<bits/stdc++.h>
using namespace std;
#define infinity 1000000
#define v 7
class prims
{
    int adjMat[v][v];
    int near[v];
    int mincost;
    int output[v-1][2];

public:

    prims()
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                adjMat[i][j] = infinity;
            }
        }
        adjMat[0][1] = 28;
        adjMat[1][0] = 28;
        adjMat[0][5] = 10;
        adjMat[5][0] = 10;
        adjMat[1][2] = 16;
        adjMat[2][1] = 16;
        adjMat[1][6] = 14;
        adjMat[6][1] = 14;
        adjMat[2][3] = 12;
        adjMat[3][2] = 12;
        adjMat[3][4] = 22;
        adjMat[4][3] = 22;
        adjMat[3][6] = 18;
        adjMat[6][3] = 18;
        adjMat[4][5] = 25;
        adjMat[5][4] = 25;
        adjMat[4][6] = 24;
        adjMat[6][4] = 24;

        mincost = 0;

    }
    int generateMST()
    {
        return MST();
    }
    int MST()
    {
        int minimum = adjMat[0][0];
        int k,l;
        for(int i = 0; i<v; i++)
        {
            for(int j = 0; j<v; j++)
            {
                if(adjMat[i][j]<minimum)
                {
                    k = i;
                    l = j;
                    minimum = adjMat[i][j];
                }
            }
        }
        output[0][0] = k;
        output[0][1] = l;
        mincost = mincost+minimum;
        //handling near
        for(int i = 0; i<v; i++)
        {
            if(adjMat[i][k]<adjMat[i][l])
                near[i] = k;
            else
                near[i] = l;
        }
        near[k] = near[l] = -1;
        for(int i = 1; i<v-1 ; i++)
        {
            int m = infinity;
            int newVertex;
            for(int j = 0; j<v; j++)
            {
                if(near[j]!=-1&&adjMat[j][near[j]]<m)
                {
                    newVertex = j;
                    m = adjMat[j][near[j]];
                }
            }
            output[i][0] = newVertex;
            output[i][1] = near[newVertex];
            mincost = mincost+adjMat[newVertex][near[newVertex]];
            near[newVertex] = -1;

            for(int c = 0; c<v; c++)
            {
                if(near[c]!=-1 && adjMat[c][near[c]]>adjMat[c][newVertex])
                {
                    near[c] = newVertex;
                }
            }
        }
        return mincost;
    }
    void printer()
    {
        for(int i = 0; i<v-1; i++)
        {
            for(int j = 0; j<2; j++)
            {
                cout << output[i][j] << "\t" ;
            }
            cout << endl;
        }
        cout << "mincost : " << mincost << endl;
    }
};
int main()
{
    prims ob;
    ob.generateMST();
    ob.printer();
}
