#include<bits/stdc++.h>
using namespace std;
class TreeVertexSplitting
{
    int parent[10] = {-1, 0, 0, 1, 2, 2, 3, 3, 5,  5};
    int node[10]   = { 1, 2, 3 ,4, 5, 6, 7, 8, 9, 10};
    int left[10]   = { 1,-1, 4, 6,-1, 8,-1,-1,-1, -1};
    int right[10]  = { 2, 3, 5, 7,-1, 9,-1,-1,-1, -1};
    int weight[10][10];
    int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> vctr;
    int track[10];
    int start;
public:
    TreeVertexSplitting()
    {
        start = 0;
        for(int i = 0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                weight[i][j] = 0;
            }
        }
        weight[1][2] = 4;
        weight[1][3] = 2;
        weight[2][4] = 2;
        weight[4][7] = 1;
        weight[4][8] = 4;
        weight[3][5] = 1;
        weight[3][6] = 3;
        weight[6][9] = 2;
        weight[6][10] = 3;
    }
    void TVScaller()
    {
        TVS(0,5);
    }
    void printer()
    {
        for(int i = 0; i < vctr.size(); i++)
            cout << vctr[i] << endl;
    }
private:
    int TVS(int root,int tol)
    {
        int ld = 0,rd = 0;
        if(left[root] == -1 && right[root] == -1)
        {
            d[root] = 0;
            return d[root];
        }
        if(left[root] != -1)
            ld = TVS(left[root],tol);
        if(right[root] != -1)
            rd = TVS(right[root],tol);
        d[root] = max(
                        (ld + weight[node[root]][node[left[root]]]),
                        (rd + weight[node[root]][node[right[root]]])
                     );
        if(root != start && d[root] + weight[node[parent[root]]][node[root]] > tol)
        {

            vctr.push_back(node[root]);
            d[root] = 0;
            return d[root];

        }
        return d[root];
    }
};

int main()
{
    TreeVertexSplitting ob;
    ob.TVScaller();
    cout << "vertex to be splited :" << endl;
    ob.printer();
}
