#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int N,M,K;
typedef struct nodes{
    int realse_time;
    int table_num;
    int avaliable;
    bool vip;
    bool operator <(const nodes &a) const
    {
        if(this->realse_time==a.realse_time)
        {
            return this->table_num > a.table_num;
        }
        else return this->realse_time > a.realse_time;
    }
}table;

int table_usrs[101];
int table_vip[101];

typedef struct node{
    int sum_time;
    int arrive_hour;
    int arrive_min;
    int arrive_sec;
    int play_time;
    bool vip;
    bool operator < (const node &a)const
    {
        return this->sum_time > a.sum_time;
    }
    
}record;

record pairs[10002];

priority_queue<record> vip_wait_queue,novip_wait_queue;
priority_queue<table> table_wait,temp,table_vip_wait;

int check(bool X,int realse_time)
{
    
    if(X)
    {
        if(!vip_wait_queue.empty()&&novip_wait_queue.empty())
        {
            if(vip_wait_queue.top().sum_time<=realse_time)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else if(vip_wait_queue.empty()&&!novip_wait_queue.empty())
        {
            if(novip_wait_queue.top().sum_time<=realse_time)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
        else if(!vip_wait_queue.empty()&&!novip_wait_queue.empty())
        {
            if(vip_wait_queue.top().sum_time<novip_wait_queue.top().sum_time)
            {
                if(realse_time<=vip_wait_queue.top().sum_time)
                {
                    return 7;
                }
                else if(novip_wait_queue.top().sum_time<=realse_time)
                {
                    return 6;
                }
                else
                {
                    return 5;
                }
            }
            else
            {
                if(realse_time<=novip_wait_queue.top().sum_time)
                {
                    return 10;
                }
                else if(vip_wait_queue.top().sum_time<=realse_time)
                {
                    return 9;
                }
                else
                {
                    return 8;
                }
            }
        }
            
    }
    else
    {
        if(!vip_wait_queue.empty()&&novip_wait_queue.empty())
        {
            if(vip_wait_queue.top().sum_time<=realse_time)
            {
                return 11;
            }
            else
            {
                return 12;
            }
        }
        else if(vip_wait_queue.empty()&&!novip_wait_queue.empty())
        {
            if(novip_wait_queue.top().sum_time<=realse_time)
            {
                return 13;
            }
            else
            {
                return 14;
            }
        }
        else if(!vip_wait_queue.empty()&&!novip_wait_queue.empty())
        {
            if(vip_wait_queue.top().sum_time<novip_wait_queue.top().sum_time)
            {
                if(realse_time<=vip_wait_queue.top().sum_time)
                {
                    return 17;
                }
                else if(novip_wait_queue.top().sum_time<=realse_time)
                {
                    return 16;
                }
                else
                {
                    return 15;
                }
            }
            else
            {
                if(realse_time<=novip_wait_queue.top().sum_time)
                {
                    return 20;
                }
                else if(vip_wait_queue.top().sum_time<=realse_time)
                {
                    return 19;
                }
                else
                {
                    return 18;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int hur,min,sec,tim,vip;
        scanf("%d:%d:%d %d %d",&hur,&min,&sec,&tim,&vip);
        pairs[i].arrive_hour=hur;
        pairs[i].arrive_min=min;
        pairs[i].arrive_sec=sec;
        pairs[i].play_time=tim;
        pairs[i].sum_time=pairs[i].arrive_hour*10000+pairs[i].arrive_min*100+pairs[i].arrive_sec;
        pairs[i].vip= (vip == 1) ? true:false;
        if(hur>=21)continue;
        
        if(!pairs[i].vip)novip_wait_queue.push(pairs[i]);
        else vip_wait_queue.push(pairs[i]);
    }
    
    cin>>M>>K;
    for(int i=1;i<=K;i++)
    {
        int t;
        cin>>t;
        table_vip[t]=true;
    }
    for(int i=1;i<=M;i++)
    {
        table t;
        t.realse_time=80000;
        t.table_num=i;
        t.vip=table_vip[i];
        t.avaliable=1;
        if(t.vip)table_vip_wait.push(t);
        else table_wait.push(t);
    }
    while(!vip_wait_queue.empty()||!novip_wait_queue.empty())
    {
        int type;
        int h,m,s;
        int min_time=240000;
        int max_time=0;

        min_time=240000;
        max_time=0;
        table avaliable_table,t;
        record players;

        if(!vip_wait_queue.empty())
        {
            if(vip_wait_queue.top().sum_time<min_time)
            {
                min_time=vip_wait_queue.top().sum_time;
            }
        }
        if(!novip_wait_queue.empty())
        {
            if(novip_wait_queue.top().sum_time<min_time)
            {
                min_time=novip_wait_queue.top().sum_time;
            }
        }

        while(!table_wait.empty())
        {
            if(table_wait.top().realse_time<min_time)
            {
                if(table_wait.top().realse_time>max_time)
                {
                    max_time=table_wait.top().realse_time;
                }
                temp.push(table_wait.top());
                table_wait.pop();
            }
            else break;
        }
        while(!table_vip_wait.empty())
        {
            if(table_vip_wait.top().realse_time<min_time)
            {
                if(table_vip_wait.top().realse_time>max_time)
                {
                    max_time=table_vip_wait.top().realse_time;
                }
                temp.push(table_vip_wait.top());
                table_vip_wait.pop();
            }
            else break;
        }


        while(!temp.empty())
        {
            t=temp.top();
            t.realse_time=max_time;
            if(t.vip)
                table_vip_wait.push( t);
            else
                table_wait.push( t);
            temp.pop();
        }

        bool vip_flag;
        vip_flag=false;
        if(!vip_wait_queue.empty()&&min_time==vip_wait_queue.top().sum_time)
        {
            if(  table_vip_wait.top().realse_time<=min_time
               || (table_vip_wait.top().realse_time>min_time&&table_vip_wait.top().realse_time== table_wait.top().realse_time)
            )
            {
                avaliable_table=table_vip_wait.top();
                table_vip_wait.pop();
                vip_flag=true;
            }
        }
        if(!vip_flag)
        {
            if(table_wait.empty())
            {
                avaliable_table=table_vip_wait.top();
                table_vip_wait.pop();
            }
            else if(table_vip_wait.empty())
            {
                avaliable_table=table_wait.top();
                table_wait.pop();
            }
            else if(table_wait.top().realse_time<table_vip_wait.top().realse_time)
            {
                avaliable_table=table_wait.top();
                table_wait.pop();
            }    
            else if(table_wait.top().realse_time>table_vip_wait.top().realse_time)
            {
                avaliable_table=table_vip_wait.top();
                table_vip_wait.pop();
            }
            else
            {
                if(table_wait.top().table_num<table_vip_wait.top().table_num)
                {
                    avaliable_table=table_wait.top();
                    table_wait.pop();
                } 
                else if(table_wait.top().table_num>table_vip_wait.top().table_num)
                {
                    avaliable_table=table_vip_wait.top();
                    table_vip_wait.pop();
                }
            }
        }
        
        if(avaliable_table.realse_time>=210000)
        {
            break;
        }
        table_usrs[avaliable_table.table_num]++;
        type=check(avaliable_table.vip,avaliable_table.realse_time);
        if(type==1||type==5||type==6||type==9||type==11||type==15||type==16)
        {
            
            players=vip_wait_queue.top();
            vip_wait_queue.pop();
           
            h=avaliable_table.realse_time/10000;
            m=(avaliable_table.realse_time%10000)/100;
            s=avaliable_table.realse_time%100;
        }
        else if(type==3||type==8||type==13||type==18||type==19)
        {
            
            players=novip_wait_queue.top();
            novip_wait_queue.pop();
            
            h=avaliable_table.realse_time/10000;
            m=(avaliable_table.realse_time%10000)/100;
            s=avaliable_table.realse_time%100;
        }
        else if(type==2||type==7||type==12||type==17)
        {
            
            players=vip_wait_queue.top();
            vip_wait_queue.pop();
            
            h=players.arrive_hour;
            m=players.arrive_min;
            s=players.arrive_sec;
           
        }
        else if(type==4||type==10||type==14||type==20)
        {
           
            players=novip_wait_queue.top();
            novip_wait_queue.pop();
          
            h=players.arrive_hour;
            m=players.arrive_min;
            s=players.arrive_sec;
            
        }
        
        
        int wait_hours=0,wait_min=0,wait_sec=0,wait_time=0;
        int sAdd=0,mAdd=0,hAdd=0;
        wait_sec=s-players.arrive_sec;
        sAdd=0;
        if(wait_sec<0)
        {
            wait_sec+=60;
            sAdd=1;
        }
        wait_min=m-players.arrive_min-sAdd;
        mAdd=0;
        if(wait_min<0)
        {
            wait_min+=60;
            mAdd=1;
        }
        wait_hours=h-players.arrive_hour-mAdd;

        if(wait_hours<0)
        {
            wait_time=0;
        }
        else
        {
            wait_time=wait_hours*60+wait_min;
            if(wait_sec>=30)wait_time++;
        }

        printf("%02d:%02d:%02d ",players.arrive_hour,players.arrive_min,players.arrive_sec);
        printf("%02d:%02d:%02d ",h,m,s);
        printf("%d\n",wait_time);


        t=avaliable_table;
        if(players.play_time>120)
            m+=120;
        else m+=players.play_time;
        
        if(m>=60){m-=60;h++;}
        if(m>=60){m-=60;h++;}
        if(m>=60){m-=60;h++;}
        if(m>=60){m-=60;h++;}
        t.realse_time=h*10000+m*100+s;
        //printf(" %d\n",t.realse_time);
        if(t.vip)
            table_vip_wait.push( t);
        else
            table_wait.push( t);
       
        
    }
    cout<<table_usrs[1];
    for(int i=2;i<=M;i++)
    {
        cout<<" "<<table_usrs[i];
    }
    cout<<endl;
 
    return 0;
}
