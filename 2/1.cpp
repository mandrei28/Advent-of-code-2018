#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int freq2=0, freq3=0, i, ok1, ok2;
    ifstream f("in.txt");
    map<char,int> freq;
    while(f >> s)
    {
        ok1=0;
        ok2=0;
        for(i = 0 ; i < s.size() ; i++)
            ++freq[ s[i] ];
        for(i = 0 ; i < s.size() ; i++)
        {
            if(freq[ s[i] ] == 2 && !ok1)
            {
                ++freq2;
                freq[ s[i] ] = 0;
                ok1 = 1;
            }
            if(freq[ s[i] ] == 3 && !ok2)
            {
                ++freq3;
                freq[ s[i] ] = 0;
                ok2 = 1;
            }
        }
        freq.clear();
    }
    cout << freq2*freq3;
}
