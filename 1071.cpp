#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

map<string,int>words;
int main()
{
    char c;
    string word;
    while((cin.get(c),c)!='\n')
    {
        
        if((c>='a'&&c<='z')||(c>='0'&&c<'9'))
        {
            word.push_back(c);
        }
        else if(c>='A'&&c<='Z')
        {
            c=c+('a'-'A');
            word.push_back(c);
        }
        else 
        {
            if(!word.empty())
            {
                if(words.find(word)==words.end())
                {
                    words[word]=1;
                }
                else
                {
                    words[word]++;
                }
            }
            word.clear();
        }
    }
    if(!word.empty())//Íü¼ÇÁË
    {
        if(words.find(word)==words.end())
        {
            words[word]=1;
        }
        else
        {
            words[word]++;
        }
    }
    string ans;
    int max=0;
    for(auto iter=words.begin();iter!=words.end();iter++)
    {
        if(iter->second>max)
        {
            max=iter->second;
            ans=iter->first;
        }
        else if(iter->second==max)
        {
            if(iter->first<ans)
            {
                ans=iter->first;
            }
        }
    }
    cout<<ans<<" "<<max<<endl;
    return 0;
}