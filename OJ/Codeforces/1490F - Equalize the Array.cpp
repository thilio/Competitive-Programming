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

map<ll, ll> m;

vector<ll> freq;
ll sumfreq[200100];
ll sumfreq_pre[200100];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		m.clear();
		freq.clear();
		int n;
		cin >> n;

		frr(i, n){
			ll x;
			cin >> x;
			m[x]++;
		}

		for(auto x: m) freq.pb(x.snd);

		sort(all(freq));

		int k = freq.size();
		fr(i, k + 3) sumfreq[i] = 0;
		fr(i, k + 3) sumfreq_pre[i] = 0;


		for(int i = k - 1; i>=0; i--){
			sumfreq[i] = sumfreq[i + 1];
			sumfreq[i] += freq[i];
		}

		for(int i = 0; i < k; i++){
			if(i != 0) sumfreq_pre[i] = sumfreq_pre[i - 1];
			sumfreq_pre[i] += freq[i];
		}

		int ans = n;

		int l = 0;
		int r = 0;
		int at = 0;
		while(l < k){
			while(r < k && freq[r] == freq[l]) r++;
			at = 0;
			if(l != 0) at += sumfreq_pre[l - 1];
			at += sumfreq[r] - (k - r)*freq[l];
			ans = min(ans, at);
			l = r;
		} 

		cout << ans << endl;

	}

}
