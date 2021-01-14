#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int main(){

	fastio;
	string s;
	getline(cin,s);
	int n = s.size();
	
	
	
	if(n<=20){
		cout <<"1 " <<n << endl;
		cout << s << endl;
		
	}
	else if(n<=40){
		cout <<"2 "<< (n+1)/2 <<endl;
		if(n%2) cout <<"*";
		for(int i = 0;i<n/2;i++){
			cout <<s[i];
		}
		gnl;
		for(int i = n/2;i<n;i++){
			cout<<s[i];
		}
		gnl;
	}
	else if(n<=60){
		cout <<"3 ";
		int col;
		if(n%3 == 0) col =  n/3;
		else col = (n/3 + 1);
		cout << col; 
		gnl;

		int ct = 0;
		
		if(n%3!=0){
			cout << "*";
			ct++;
		}
		int i = 0;
		while(ct<col){
			cout <<s[i];
			i++;ct++;
		}
		gnl;

		ct = 0;
		
		if(n%3==1){
			cout << "*";
			ct++;
		}

		while(ct<col){
			cout <<s[i];
			i++;ct++;
		}
		gnl;

		ct = 0;

		while(ct<(col)){
			cout <<s[i];
			i++;ct++;
		}
		gnl;
	}

	else if(n<=80){
		int r = n%4;
		cout <<"4 ";
		int col = n/4;
		if(r!=0) col++;
		cout << col <<endl;

		r = (4-r)%4;

		int i = 0;
		while(i<n){
			bool ok = false;
			if(r>0){
				cout <<"*";
				r--;
				ok = true;
			}

			int j = (int)ok;
			while(j<col){
				cout <<s[i];
				i++;j++;
			}
			gnl;
		}

	}

	else{

		int r = n%5;
		cout <<"5 ";
		int col = n/5;
		if(r!=0) col++;
		cout << col<<endl;

		r = (5 -r)%5;

		int i = 0;
		while(i<n){
			bool ok = 0;
			if(r>0){
				cout <<"*";
				r--;
				ok = 1;
			}

			int j = ok;
			while(j<col){
				cout <<s[i];
				i++;j++;
			}
			gnl;
		}

	}
	

}
