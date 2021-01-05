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

int n,a[1200],resp[1200];

bool testa(int k){
	fr(i,n){
		if(resp[i] != resp[i%k])
			return false;
	}
	return true;
}

int main(){

	fastio;
	
	cin >> n;
	fr(i,n)
		cin >> a[i];
	resp[0] = a[0];
	frr(i,n-1)
		resp[i] = a[i] - a[i-1];

//	fr(i,n)
//		dbg(resp[i]);

	vi ans;
	frr(i,n){
		bool ok = testa(i);
		if(ok)
			ans.pb(i);
	}

	cout<<ans.size()<<endl;

	fr(i,ans.size())
		cout<<ans[i]<<' ';

	gnl;

}
