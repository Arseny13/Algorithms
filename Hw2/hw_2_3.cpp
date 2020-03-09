#include <stdio.h>
#include <vector>
using namespace std;
const int full_time  = 86400;

int main(){
    int n,x,a,b,c,x1;
    scanf("%d",&n);
    vector <int> w(full_time,0);
    for (int i=0;i<n;i++){
        scanf("%d:%d:%d",&a,&b,&c);
        x=a*3600 +b*60 +c;
        scanf("%d:%d:%d",&a,&b,&c);
        x1=a*3600 +b*60 +c+1;
        w[x]+=1;
        w[x1]-=1;
    }
    int max1=0;
    int sum=0;
    for(int j=0;j<=full_time;j++){
        sum+=w[j];
        if (sum>max1) {max1=sum;}
    }
    printf("%d",max1);
    return 0;
}
