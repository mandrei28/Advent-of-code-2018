#include<bits/stdc++.h>
using namespace std;
int Matrix[401][401];
map < char, int > infinity;
map < char, int > freq;
vector< pair<int, int> > coords;
int main()
{
    ifstream f("in.txt");
    char s1[10], currentVal = 'A';
    int x, y, i, j, dist, mini = 1000000;
    while(f >> s1 >> x)
    {
        strcpy(s1+strlen(s1)-1, s1+strlen(s1));
        y = atoi(s1);
        Matrix[x][y] = currentVal;
        coords.push_back(make_pair(x,y));
        currentVal++;
    }
    for(i = 0 ; i < 400 ; i++)
        for(j = 0 ; j < 400 ; j++)
        {
            if(Matrix[i][j] != 0)
                continue;
            mini = 1000000;
            for(auto it: coords)
            {
                dist = abs(i-it.first) + abs(j-it.second);
                if(dist < mini)
                {
                    mini = dist;
                    Matrix[i][j] = Matrix[it.first][it.second];
                }
                else if(dist == mini)
                {
                    Matrix[i][j] = -1;
                }
            }
            if(i == 0 || j == 0 || i == 399 || j == 399)
            {
                infinity[Matrix[i][j]] = 1000000;
            }
        }
    int maxi = 0;
    for(i = 0 ; i < 400 ; i++)
        for(j = 0 ; j < 400 ; j++)
        {
            if(infinity[Matrix[i][j]] == 1000000)
                continue;
            freq[Matrix[i][j]]++;
            if(freq[Matrix[i][j]] > maxi && Matrix[i][j] != -1 && Matrix[i][j] != 0)
                maxi = freq[Matrix[i][j]];
        }
    cout << maxi;
}
