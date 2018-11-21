#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> sentences;
int main()
{
    int N;
    cin>>N;
    cin.get();
    for(int i=0;i<N;i++)
    {
        string t;
        getline(cin,t);
        
        reverse(t.begin(),t.end());
        sentences.push_back(t);
    }
    int it=0;
    bool flag=true;
    string ans;
    while(1)
    {
        flag=true;
        for(auto iter=sentences.begin()+1;iter!=sentences.end();iter++)
        {
            if( it>=(*(iter-1)).size()||it>=(*iter).size() )
            {
                flag=false;break;
            }
            if( (*(iter-1))[it] != (*iter)[it] )
            {
                
                flag=false;
            }
        }
        if(flag==true)
        {
            ans.push_back( (*(sentences.begin()))[it] );
            it++;
        }
        else
        {
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    if(!ans.empty())
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"nai"<<endl;
    }
    return 0;
}