#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f("in.txt");
    char s[50002], aux[50002];
    int i, ok, min=1000000, j, q;
    f >> s;
    j = 'a';
    while(j <= 'z')
    {
        strcpy(aux, s);
            for(q = 0 ; q < strlen(aux) ; q++)
            {
                if(aux[q] == j || aux[q] == j-32)
                {
                    strcpy(aux+q, aux+q+1);
                    q = q-1;
                }
            }
        while(1)
        {
        ok = 0;
            for(i = 0 ; i < strlen(aux)-1 ; i++)
            {
                if(abs(aux[i] - aux[i+1]) == 32)
                {
                    strcpy(aux+i, aux+i+2);
                    ok = 1;
                    i = i-2;
                }
            }
            if(ok == 0 && strlen(aux) < min)
            {
                min = strlen(aux);
                break;
            }
            else
                if(ok == 0)
                    break;
        }
        j++;
    }
    cout << min;
}

