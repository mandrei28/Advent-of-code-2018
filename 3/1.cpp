#include<bits/stdc++.h>
using namespace std;

int Matrix[1001][1001];
int v[1500], freq[1500];

int main()
{
    ifstream f("in.txt");
    char s1[15], s2[15], s3[15], s4[15], aux[15];
    int q, x, y, i, j, o, p, cnt=0;
    while(f >> s1 && f >> s2 && f >> s3 && f >> s4)
    {
        q = atoi(s1+1);
        i = 0;
        while(s3[i] != ',')
        {
            aux[i] = s3[i];
            i++;
        }
        aux[i] = NULL;
        x = atoi(aux);
        j = 0;
        i = i+1;
        while(s3[i] != ':')
        {
            aux[j] = s3[i];
            j++;
            i++;
        }
        aux[j] = NULL;
        y = atoi(aux);
        i = 0;
        while(s4[i] != 'x')
        {
            aux[i] = s4[i];
            i++;
        }
        aux[i] = NULL;
        o = atoi(aux);
        j = 0;
        i = i+1;
        while(s4[i] != NULL)
        {
            aux[j] = s4[i];
            j++;
            i++;
        }
        aux[j] = NULL;
        p = atoi(aux);
        for(i = y ; i < y+p ; i++)
            for(j = x ; j < x+o ; j++)
            {
                if(Matrix[i][j] == 0)
                    Matrix[i][j] = q;
                else
                    Matrix[i][j] = -1;
            }
    }
    for(i = 0 ; i < 1001 ; i++)
        for(j = 0 ; j < 1001 ; j++)
            if(Matrix[i][j] == -1)
                cnt++;
    cout << cnt;
    return 0;
}
