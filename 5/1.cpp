#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f("in.txt");
    char s[50002];
    int i, ok;
    f >> s;
    while(1)
    {
        ok = 0;
        for(i = 0 ; i < strlen(s)-1 ; i++)
        {
            if(abs(s[i] - s[i+1]) == 32)
            {
                strcpy(s+i, s+i+2);
                ok = 1;
                i = i-2;
            }
        }
        if(ok == 0)
            break;
    }
    cout << strlen(s);
}
