#include <iostream>
#include <cstring>
using namespace std;
///
typedef struct time{
    int min,hour,sec;
    bool operator < (const time a)const
    {
        if(this->hour == a.hour)
        {
            if(this->min == a.min)
            {
                return this->sec < a.sec;
            }
            else
                return this->min < a.min;
        }
        else
            return this->hour < a.hour;
    }

}time;

int main(int argc, char const *argv[])
{
    /* code */
   
    int N;
    char c;
    char Open_door[20],Close_door[20];
    time earliset,least;
    earliset.sec=61;
    earliset.hour=25;
    earliset.min=61;
    least.sec=-1;
    least.hour=-1;
    least.min=-1;

    cin>>N;
    for(int i=0;i<N;i++)
    {
        char s[20];
        time t;
        cin>>s;
        cin>>t.hour;cin>>c;cin>>t.min;cin>>c;cin>>t.sec;
        if(t<earliset)
        {
            earliset=t;
            strcpy(Open_door,s);
        }
        cin>>t.hour;cin>>c;cin>>t.min;cin>>c;cin>>t.sec;
   
        if(least<t)
        {
            least=t;
            strcpy(Close_door,s);

        }
    }
    cout<<Open_door<<" "<<Close_door<<endl; 
    
    return 0;
}
