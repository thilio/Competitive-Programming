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
int n;
ll v[100100];

struct trie{
	int cnt,wrd;
	map<ll,trie> m;

	trie(){
		cnt = wrd = 0;
		m.clear();
	}

	void add(ll n,ll i){
		cnt++;
		if(i < 0){
			wrd++;
			return;
		}
		ll aux;
		aux = n&(1ll<<i);
		if(aux != 0) aux = 1;

		if(!m.count(aux)){
			m[aux] = trie();
		}

		m[aux].add(n,i-1);

	}

	ll find(ll n,ll i){
		if(i < 0){
			return 0;
		}

		ll aux = (n&(1ll << i));

		if(aux == 0){
			if(m.count(1ll)){
				return (1ll << i) + m[1].find(n,i-1);
			}
			else{
				return m[0].find(n,i-1);
			}
		}

		if(aux != 0){
			if(m.count(0ll)){
				return (1ll << i) + m[0].find(n,i-1); 
			}
			else
				return m[1].find(n,i-1);
		}
	}
};

int main(){

	fastio;
	cin >> n;
	trie t = trie();
	t.add(0,62);
	fr(i,n) cin >> v[i];

	ll suf,pre;
	pre = suf = 0;
	fr(i,n) suf = suf^v[i];

	ll ans = 0;

	fr(i,n){
		ans = max(ans,t.find(suf,62));
		//dbg(ans);
		//dbg(suf);
		suf = suf^v[i];
		pre = pre^v[i];
		t.add(pre,62);		
	}

	ans =  max(ans,t.find(0ll,62));

	cout << ans << endl;

}
