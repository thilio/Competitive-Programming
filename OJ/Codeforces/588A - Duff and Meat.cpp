#include<bits/stdc++.h>
using namespace std;
int main (){
	int n,s=0,a,b=101,c,i;
	scanf ("%d",&n);
	for (i=0;i<n;i++){
		scanf ("%d",&a);
		scanf ("%d",&c);
		if (c<b)
			b=c;
		s+=a*b;
	}
	printf ("%d\n",s);
	return (0);
}