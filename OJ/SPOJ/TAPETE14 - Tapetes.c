#include<stdio.h>
int main(){
  long long m,n,res;
  scanf("%lld",&m);
  scanf("%lld",&n);
  n=n-1;
  res=(m-n)*(m-n) + n;
  printf("%lld\n",res);
  return(0);
}
     