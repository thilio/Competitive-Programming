#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> m;
 	long long x,t,n,i,sum=0,tot=0,ct;
 	scanf("%lld",&t);
 	for(ct=0;ct<t;ct++){
 		scanf ("%lld",&n);
 		sum=0;tot=0;m.clear();
 		for (i=0;i<n;i++){
 			scanf("%lld",&x);
 			sum+=x;
 			tot+=m[sum];
 			m[sum]++;
 		}
 		printf ("%lld\n",tot + m[0]);
 	}
 	return (0);
}