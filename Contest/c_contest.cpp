#include <stdio.h>
#include <vector>
using namespace std;
using  ll = long long;
 //#define ll long long плохо так как можно назвать переменую ll например int ll;

int main()
{
    int n;
    scanf("%d",&n);
    /*int w[n]; // плохой способ  так как  иногда не хватает размера стека иззза многопоточности;
     обычно размре стека 1-2M
    */
    /* int *w = new int[n] проблема надо будет в конец удалять delete []w  */
    vector <int> w(n); // не надо будет удалять так как автоматически
    ll sum=0;
    for (int i=0;i<n;i++){
        scanf("%d",&w[i]);
        sum +=w[i];
    }
    ll min = sum+1;/*или 100000000000000; // плохо писать 1e15*/

    for (unsigned g=(1u<<n)-1;g>0;g--) /* 1u безнаковая 1*/
    {
       ll c=0;
       unsigned mask = g;
       for (int i=0;mask!=0;i++)
       {
          /*if ((g&(1<<i))!=0) c+=w[i]; плохо так как сдвиг в цикле время =0.85*/
         // if(mask&1) c+=w[i];  /* время 0.66 , плохо так как логическая операция*/
          c+=(mask&1)*w[i]; /* время 0.228*/

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
