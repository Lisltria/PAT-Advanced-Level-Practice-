#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <set>
using namespace std;

map<string,set<int>> mTitle,mAuthor,mKey,mPub,mYear;

int search(map<string,set<int>> &m, string &str)
{
    if(m.find(str)==m.end())
    {
        printf("Not Found\n");
    }
    else
    {
        for(set<int>::iterator it=m[str].begin();it!=m[str].end();it++)
        {
            printf("%07d\n", *it);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int N,M,id,type;
    string title,author,key,pub,year;
    scanf("%d", &N);

    for(int i=0;i<N;i++)
    {
        char c_T;
        scanf("%d", &id);
        c_T = getchar();

        getline(cin,title);
        mTitle[title].insert(id);

        getline(cin,author);
        mAuthor[author].insert(id);//insert是set的方法

        while(cin>>key)
        {
            mKey[key].insert(id);
            c_T = getchar();
            if(c_T=='\n')
                break;
        }

        getline(cin,pub);
        mPub[pub].insert(id);

        getline(cin,year);
        mYear[year].insert(id);
    }
    scanf("%d", &M);
    for(int i=0;i<M;i++)
    {
        int type;
        char c_T;
        string str;
        scanf("%d: ", &type);

        getline(cin,str);
        cout<<type<<": "<<str<<endl;
        switch (type)
        {
            case 1:
                
                search(mTitle,str);
                break;
            case 2:
                
                search(mAuthor,str);
                break;
            case 3:
                
                search(mKey,str);
                break;
            case 4:
                
                search(mPub,str);
                break;
            case 5:
                
                search(mYear,str);
                break;

        }
    }

    return 0;
}
