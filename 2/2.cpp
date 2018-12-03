#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int freq2=0, freq3=0, differences, i, pos;
    ifstream f("in.txt");
    vector<string> boxes;
    while(f >> s)
        boxes.push_back(s);
    for(vector<string>::iterator it1=boxes.begin() ; it1!=boxes.end() ; ++it1)
        for(vector<string>::iterator it2=boxes.begin() ; it2!=boxes.end() ; ++it2)
        {
            differences = 0;
            for(i = 0 ; i < (*it1).size() ; i++)
                if( (*it1)[i] != (*it2)[i] )
                {
                    differences++;
                    pos = i;
                }
                if(differences == 1)
                {
                    for(i = 0 ; i < (*it1).size() ; i++)
                        if(i!=pos)
                            cout<<(*it1)[i];
                    return 0;
                }
        }
}

