#include <stdio.h>
#include <vector>
using namespace std;
using  ll = long long;
 //#define ll long long ����� ��� ��� ����� ������� ��������� ll �������� int ll;

int main()
{
    int n;
    scanf("%d",&n);
    /*int w[n]; // ������ ������  ��� ���  ������ �� ������� ������� ����� ����� ���������������;
     ������ ������ ����� 1-2M
    */
    /* int *w = new int[n] �������� ���� ����� � ����� ������� delete []w  */
    vector <int> w(n); // �� ���� ����� ������� ��� ��� �������������
    ll sum=0;
    for (int i=0;i<n;i++){
        scanf("%d",&w[i]);
        sum +=w[i];
    }
    ll min = sum+1;/*��� 100000000000000; // ����� ������ 1e15*/

    for (unsigned g=(1u<<n)-1;g>0;g--) /* 1u ���������� 1*/
    {
       ll c=0;
       unsigned mask = g;
       for (int i=0;mask!=0;i++)
       {
          /*if ((g&(1<<i))!=0) c+=w[i]; ����� ��� ��� ����� � ����� ����� =0.85*/
         // if(mask&1) c+=w[i];  /* ����� 0.66 , ����� ��� ��� ���������� ��������*/
          c+=(mask&1)*w[i]; /* ����� 0.228*/

          mask>>=1;
       }

      // for(unsigned mask =g;mask!=0;mask>>=1)
      // {
      //     c+=(mask&1)*w[i]
      // }
       c= sum -c-c;
       if (c<0) c=-c;
       if (c<min) min=c;

    }


    printf("%lld\n",min);

return 0;


}
