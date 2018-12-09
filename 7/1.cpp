#include<bits/stdc++.h>

using namespace std;

map <char, int> internaldegree;
vector<char> parent[256];
map <char, int> visited;
int ok[256];
vector <char> order;

int main()
{

    ifstream f("in.txt");
    char s1[15], s3[15], s4[15], s5[15], s6[15], s7[15], x[15], y[15], s9[15], s10[15];
    char i, j;
    int k, cnt = 0;
    while(f >> s1 >> x >> s3 >> s4 >> s5 >> s6 >> s7 >> y >> s9 >> s10)
    {
        internaldegree[y[0]]++;
        parent[ y[0] ].push_back(x[0]);
        ok[ x[0] ]++;
        ok[ y[0] ]++;
        cnt++;
    }
    int q = 1;
    while(q != cnt)
    {
        for(i = 'A' ; i <= 'Z' ; i++)
        {
            if(internaldegree[i] == 0 && visited[i] == 0 && ok[i] > 0)
            {
                visited[i] = 1;
                order.push_back(i);
                for(j = 'A' ; j <= 'Z' ; j++)
                {
                    for(k = 0 ; k < parent[j].size() ; k++)
                    {
                        if(parent[j][k] == i)
                        {
                            internaldegree[j]--;
                        }
                    }
                }
                break;
            }
        }
        q++;
    }
    for(auto it: order)
        cout << it;
}
