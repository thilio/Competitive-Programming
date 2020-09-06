#include <bits/stdc++.h>
using namespace std;

int v[222345];

int main(){
	int n,i;
	long long sum1,sum3,max=0;
	int p,q;
	cin >> n;
	for (i=0;i<n;i++){
		cin >> v[i];
	}
	p=0;
	q=n-1;
	sum1=0;
	sum3=0;
	while (p<q){
		if (sum1 == sum3){
			max=sum1;
			sum1+=v[p];
			sum3+=v[q];
			p++;q--;
		}
		else if(sum1>sum3){
			sum3+=v[q];
			q--;
		}
		else{
			sum1+=v[p];
			p++;
		} 
	}
	if (p==q){
		//cout << sum1 << sum3<<p<<q<<endl;
		if(sum1>sum3){
			sum3+=v[q];
			q--;
		}
		else if (sum3>sum1){
			sum1+=v[p];
			p++;
		} 
	}
	if (sum1==sum3) max=sum1;
	cout<<max<<endl;
	return(0);

}