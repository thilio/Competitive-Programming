#include<bits/stdc++.h>
using namespace std;

int f(int rm,int* v,int n){
	int i,fr[n],a,b,c,ok=1;
	a=b=c=pow(10,6);
	fr[0]=1;
	for (i=1;i<n;i++){
		fr[i]=fr[i-1] -rm +v[i-1] - v[i];
		if (abs(fr[i]) >= 2){
			ok=0;
			break;
		}
	}
	if (ok){
		//cout << 'A' << endl;
		a=0;
		for(i=0;i<n;i++){
			if (fr[i]!=0)
				a++;
		}

	}
	ok=1;
		
	fr[0]=0;
	for (i=1;i<n;i++){
		fr[i]=fr[i-1] -rm -v[i] + v[i-1];
		if (abs(fr[i]) >= 2){
			ok=0;
			break;
		}
	}
	if (ok){
		b=0;
		for(i=0;i<n;i++){
			if (fr[i]!=0)
				b++;
		}
	}
	ok=1;
		
	fr[0]=-1;
	for (i=1;i<n;i++){
		fr[i]=fr[i-1] -rm +v[i-1] - v[i];
		if (abs(fr[i]) >= 2){
			ok=0;
			break;
		}
	}
	if (ok){
		c=0;
		for(i=0;i<n;i++){
			if (fr[i]!=0)
				c++;
		}
	}
		
	return (min(a,min(b,c)));
}

 
 int main(){
 	int i,n,v[112345],rm,x,min=pow (10,6);
 	cin >> n;
 	for (i=0;i<n;i++){
 		cin >> v[i];
 	}
 	if (n==1 || n==2)
 		cout << 0 << endl;
 	else{
 		rm = -v[n-1] + v[0];
 		for (i=-2;i<3;i++){
 			if ((rm + i)%(n-1) == 0){
 				x=f((rm+i)/(n-1),v,n);
 				if (x<min)
	 				min = x;
 			}
 		}
 		if (min == pow(10,6))
	 		cout << "-1" << endl;
	 	else
 			cout << min << endl;
 	}
 	
 	return (0);

 }