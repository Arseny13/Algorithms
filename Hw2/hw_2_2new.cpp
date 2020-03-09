#include <stdio.h>
 #include <vector>
 using namespace std;

 int main(){
 int r,n;
 scanf("%d%d",&n,&r);
 vector <int> w(r,0);
 long sum=0;
 int a;
 for (int i=0;i<n;i++){
    scanf("%d",&a);
    w[a]+=1;
    sum+=r-a;
 }
 long x=sum;
long min1=0;
long sum1=0;
for (int i=1;i<r;i++){
    sum1=x-w[i]*(r-1)+n-w[i];
    x=sum1;
     if (sum1<sum) {sum=sum1; min1=i;}

}
printf("%d",min1);
 return 0 ;


 }
