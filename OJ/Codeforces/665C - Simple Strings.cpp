#include<bits/stdc++.h>
using namespace std;
string s;
char modifica (string s,int i,int t){
	char z='a';
	if (i==(t-1)){
		while (z==s[i-1])
			z=z+1;
	}
	else{
		while (z==s[i-1]||z==s[i+1])
			z=z+1;
	}
	return (z);
}
int main(){
	char k;
	int t,i;
	cin>>s;
	t=s.size();
	for (i=1;i<t;i++){
		if (s[i]==s[i-1]){
			k=modifica (s,i,t);
			s[i]=k;
		}
	}
	cout<<s<<endl;
	return (0);

}

