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

string s;
int n;
int ans[1000];

void rev(int k){
	char t[2000];
	fr(i,k+1){
		t[i] = s[k-i];
	}
	fr(i,k+1)
		s[i] = t[i];
}

int main(){

	fastio;
	
	getline(cin,s);
	n = s.size();
	int i = 1;
	ans[0] = 0;
	while(i<n-1){
		char at = s[0];
		if(at == 'a'){
			while(i<n-1){
				if(s[i] == 'b' && s[i+1] =='a') break;
				i++;
			}
			if(i == n-1)
				break;
			rev(i);
			ans[i] = 1;
		}
		if(at == 'b'){
			while(i<n-1){
				if(s[i] == 'a' && s[i+1] =='b') break;
				i++;
			}
			if(i == n-1)
				break;
			rev(i);
			ans[i] = 1;
		}
	}
	if(s[i] == 'a'){
		ans[i] = 1;
		rev(i);
	}

	//dbg(s);
	fr(i,n)
		cout<<ans[i]<<endl;
	

}
