#include<bits/stdc++.h>
using namespace std;
#define MAX_WEIGHT 87;
class sack
{
    public:
    int profit;
    int weight;
};
int main()
{
    sack ob[10];
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        ob[i].profit = rand()%100;
        ob[i].weight = rand()%100;
    }
    for(int i=0;i<10;i++)
    {
        cout << ob[i].profit << "\t" << ob[i].weight << endl;
    }
    for(int i=0;i<10;i++)
    {
        for(int j = 0; j<10 ;j++)
        {
            if(ob[i].weight<ob[j].weight)
            {
                swap(ob[i],ob[j]);
            }
        }
    }
    cout << "------------------------------------\n";
    for(int i=0;i<10;i++)
    {
        cout << ob[i].profit << "\t" << ob[i].weight << endl;
    }
    int tmpProfit = 0;
    int tmpWeight = MAX_WEIGHT;
    for(int i=0;i<10;i++)
    {
        if(ob[i].weight<=tmpWeight)
        {
            tmpProfit = tmpProfit+ob[i].profit;
            tmpWeight = tmpWeight-ob[i].weight;
        }
        else if(ob[i].weight>=tmpWeight)
        {
            cout <<"profit : " <<tmpProfit << endl;
            break;
        }
        //if(tmpWeight==0||tmpWeight<0)
        //{

        //}
    }
}
