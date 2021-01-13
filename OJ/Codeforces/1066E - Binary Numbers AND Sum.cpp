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
const int MOD = 998244353;

int acum[212345],s[212345],t[212345];
vector<int> ans;

ll expr(ll base,ll exp){
	if (exp == 0) return (1);

	ll aux = expr(base,exp/2);
	aux = aux%MOD;
	ll ans;
	ans = aux*aux;
	ans = ans%MOD;
	
	if(exp%2 == 1){
		ans*=base;
	}
	
	ans = ans%MOD;
	return(ans);
}

int main(){

	fastio;
	int n,m;
	string a,b;
	
	cin >> n;
	cin >> m;

	
	getline (cin,a);
	getline (cin,a);
	getline (cin,b);

	fr(i,n){
		s[i] = a[i] - '0';
	}

	fr(i,m)
		t[i] = b[i] - '0';

	fr(i,m){
		if (i == 0) acum[0] = t[0];
		else{
			acum [i] = t[i] + acum[i-1];
		}
//		dbg(acum[i]);
	}

	for (int i = 0;i< n;i++){	
		if (i<m)
			ans.pb(s[n - 1- i]*acum[m - 1 -i]);
	}

//	fr(i,ans.size()){
//		dbg(ans[i]);
//	}
	ll resp = 0;
	ll aux;

	fr(i,ans.size()){
		if (ans[i]!=0){
			aux = expr((ll)2,ll(i));
			aux = aux%MOD;
			aux = aux*ans[i];
			aux = aux%MOD;
			resp += aux;
			resp = resp%MOD;
		}
	}

	resp = resp%MOD;
	cout << resp << endl;
	
}
