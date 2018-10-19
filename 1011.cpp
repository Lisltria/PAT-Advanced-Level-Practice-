#include<iostream> 
#include<iomanip>
using namespace std; 
#define TiMes 3
int main()
{
  int index,i;
  char sign[3] = { 'W', 'T', 'L' };
  double num[TiMes],sum,temp;
  int tag[TiMes];
  for (index = 0,sum=1.0; index < TiMes; index++)
  {
    cin >> num[index];
    tag[index] = 0;
    for (i = 1; i < TiMes; i++)
    {
      cin >> temp;
      if (temp>num[index])
      {
        num[index] = temp;
        tag[index]= i;
      }
    }
    sum = sum*num[index]; 
  }
  sum = (sum*0.65 - 1) * 2;
  for (index = 0; index < TiMes; index++)
    cout << sign[tag[index]]<<" ";
  cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;

  return 0;
}
