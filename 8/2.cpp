// 2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2
// 2 3 . . .  .  .  1 1 0 1 99  2 1 1 2
// 1 3 . . .  .  .  1 1 0 1 99  2 1 1 2
// 1 3 . . .  .  .  1 1 . . .  2 1 1 2
// 1 3 . . .  .  .  0 1 . . .  2 1 1 2
// 1 3 . . .  .  .  . . . . .  . 1 1 2
// 0 3 . . .  .  .  . . . . .  . 1 1 2
// 0 3 . . .  .  .  . . . . .  . 1 1 2
// . . . . .  .  .  . . . . .  . . . .
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes[37000];
    vector<int> metadata[20000];
    vector<int> child[20000];
    ifstream f("in.txt");
    int x, ok = 1, i , j, sum=0, noe=0, k, u = 0;
    while(f >> x)
        nodes[noe++] = x;
    while(ok)
    {
        ok = 0;
        for(i = 0 ; i < noe ; i++)
        {
            if(nodes[i] == 0)
            {
                sum=0;
                k = i + 2 ;
                while(nodes[k] == -1)
                    k++;
                ok = 1;
                for(j = k ; j < k + nodes[i+1] ; j++)
                {
                   // cout<<nodes[j]<<endl;
                    sum = sum + nodes[j];
                    nodes[j] = -1;
                }
                metadata[u++].push_back(sum);
                nodes[i] = -1;
                nodes[i+1] = -1;
                k = i - 1;
                while(nodes[k] == -1)
                    k--;
                nodes[k - 1]--;
            }
        }
    }
    for(i=0;i<u;i++)
    {
        for(auto it: metadata[i])
            cout<<it<<" ";
        cout<<endl;
    }
    //for(i=0;i<noe;i++)
      //  cout<<nodes[i]<<" ";
    //cout<<endl;
    cout << sum;
}
