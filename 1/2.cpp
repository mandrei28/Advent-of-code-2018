#include<bits/stdc++.h>

using namespace std;

char input[10];

int main()
{
    ifstream f("in.txt");
    int sum = 0;

    map <int, int> freq;

    ++freq[sum];
    while(1)
    {
        while(f >> input)
        {
            if(input[0] == '+')
                sum = sum + atoi(input+1);
            else
                sum = sum - atoi(input+1);
            ++freq[ sum ];
            if(freq[sum]>1)
            {
                cout<<sum;
                return 0;
            }
        }
        f.clear();
        f.seekg(0, ios::beg);
    }
}
