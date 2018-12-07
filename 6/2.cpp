#include<bits/stdc++.h>
using namespace std;
int Matrix[401][401];
vector< pair<int, int> > coords;
int main()
{
    ifstream f("in.txt");
    char s1[10], currentVal = 'A';
    int x, y, i, j, dist, maxsum = 10000, sum = 0, cnt = 0;;
    while(f >> s1 >> x)
    {
        strcpy(s1 + strlen(s1) - 1, s1 + strlen(s1));
        y = atoi(s1);
        Matrix[x][y] = currentVal;
        coords.push_back(make_pair(x, y));
        currentVal++;
    }
    for(i = 0; i < 400 ; i++)
        for(j = 0 ; j < 400 ; j++)
        {
            if(Matrix[i][j] == 1)
                continue;
            sum = 0;
            for(auto it:coords)
            {
                dist = abs(i - it.first) + abs(j - it.second);
                sum = sum + dist;
            }
            if(sum < maxsum)
            {
                Matrix[i][j] = 1;
            }
        }
    for(i = 0; i < 400 ; i++)
        for(j = 0 ; j < 400 ; j++)
            if(Matrix[i][j] == 1)
                cnt++;
    cout << cnt;
}

