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
ll v[212345];
ll freq[1123456];

int main(){

	fastio;


	int n;
	cin >> n;

	ll sum = 0;
	fr(i,n){
		cin >> v[i];
		freq[v[i]]++;
		sum+=v[i];
	}

	//olar;

	vector<ll> ans;
	int ct = 0;

	//dbg(sum);

	fr(i,n){
		
		///dbg(i);
		ll ss = sum - v[i];
		
		if (ss > 2000002 ) continue;

		if (ss%2 == 1)
			continue;
				
		if(v[i] == (ss/2) && freq[v[i]] > 1ll){
			ct++;
			ans.pb(i);
			continue;
		}

		if(v[i] != (ss/2) && freq[(ss/2)] != 0ll){
			ct++;
			ans.pb(i);

		}
	}

	//olar;

	cout << ct << endl;

	fr(i,ans.size())
		cout << ans[i] + 1<< ' ';
	gnl;


}
