#include<bits/stdc++.h>

using namespace std;

map <char, int> internaldegree;
vector<char> parent[256];
map <char,int> visited;
map <char,int> visited2;
int ok[256];
char order[100][100];

int main()
{

    ifstream f("in.txt");
    char s1[15],s3[15],s4[15],s5[15],s6[15],s7[15],x[15],y[15],s9[15],s10[15];
    char i,j,last;
    int k,cnt=0,verify;
    while(f>>s1>>x>>s3>>s4>>s5>>s6>>s7>>y>>s9>>s10)
    {
        internaldegree[y[0]]++;
        parent[y[0]].push_back(x[0]);
        ok[x[0]]++;
        ok[y[0]]++;
        cnt++;
    }
    int q=1;
    int count0=0;
    int count1=0;
    while(q!=cnt)
    {
        verify=0;
        for(i='A';i<='Z';i++)
        {
            if(internaldegree[i]==0&&ok[i]>0&&visited2[i] == 0)
            {
                for(j=0;j<(i-64);j++)
                    if(((order[count0+j][0]==0&&verify==0))||((order[count0+j][0]=='.'&&verify==0)))
                    {
                        order[count0++][0]=i;
                        count1++;
                        visited2[i] = 1;
                        last = i;
                    }
                if(verify==1)
                {
                    count1=count1-(last-64);
                    for(j=0;j<(i-64);j++)
                    {
                        if(order[count1+j][1]==0)
                        {
                            order[count1++][1]=i;
                            visited2[i] = 1;
                        }
                        else
                            if(order[count1+j][0]==0&&order[count1+j][1]!=0)
                                order[count1++][0]=i;
                    }
                    count1=count0;
                }
                verify=1;
                order[count0][0]='.';
            }
        }
        for(i='A';i<='Z';i++)
        {
            if(internaldegree[i]==0&&visited[i]==0&&ok[i]>0)
            {
                visited[i] = 1;
                for(j='A';j<='Z';j++)
                {
                    for(k=0;k<parent[j].size();k++)
                    {
                        if(parent[j][k]==i)
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
    for(i=0;i<=100;i++)
    {
        for(j = 0 ; j < 2 ; j++)
            cout<<order[i][j]<<" ";
        cout<<endl;
    }
}
