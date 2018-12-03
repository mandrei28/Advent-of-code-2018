#include<bits/stdc++.h>
using namespace std;
int main()
{
    long sum = 0;
    char input[10];
    ifstream f("in.txt");
    while(f >> input)
    {
        if(input[0] == '+')
            sum += atoi(input+1);
        else
            sum -= atoi(input+1);
    }
    cout << sum;
    return 0;
}
