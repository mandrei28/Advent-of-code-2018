#include<bits/stdc++.h>
using namespace std;
int freq[6000][61];
int total[6000];
int main()
{
    ifstream f("in.txt");
    set< pair<string,string> > s;
    char s1[15], s2[15], s3[15], s4[15], s5[15], s6[15];
    int asleep = 0, up = 0, last = 0, maxim = 0, maxid = 0, ok, maxfreq = -1, maxmin = -1, i, j;

    while(f >> s1 >> s2 >> s3 >> s4)
    {
        s1[11] = ' ';
        strcpy(s1 + 12, s2);
        if(s4[0] == '#')
            strcpy(s4, s4+1);
        s.insert(make_pair(s1,s4));
        if(strcmp(s3, "Guard") == 0)
            f >> s5 >> s6;
    }
    for(auto it:s)
    {
        if(it.second != "asleep" && it.second != "up")
        {
            last=0;
            for(i = 0 ; i < it.second.size() ; i++)
                last = last*10 + it.second[i]-'0';
        }
        else if(it.second == "asleep")
            asleep = ( it.first[15] - '0' ) * 10 + ( it.first[16] - '0' );
        else
            up = ( it.first[15] - '0' ) * 10 + ( it.first[16] - '0' );
        if(up != 0)
        {
            for(i = asleep ; i < up ; i++)
                freq[last][i]++;
            total[last] += up-asleep;
            asleep = up = 0;
        }
    }
    for(j = 0 ; j <= 5000 ; j++)
        for(i = 0 ; i <= 59 ; i++)
            if(freq[j][i] > maxfreq)
            {
                maxfreq = freq[j][i];
                maxmin = i;
                maxid = j;
            }
    cout << maxid * maxmin;
}

