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

struct trie{
	int cnt,wrd;
	map<int,trie> m;

	trie(){
		cnt = wrd = 0;
		m.clear();
	}

	void add(ll n,ll i){
		cnt++;
		if(i<0){
			wrd++;
			return;
		}
		if(n&(1ll << i)){
			if(!m.count(1)){
				m[1] = trie();
			}
			m[1].add(n,i-1);
		}
		else{
			if(!m.count(0)) m[0] = trie();
			m[0].add(n,i-1);
		}
	}

	bool remove(ll n,int i){
		cnt--;
		if(i<0){
			wrd--;
			return true;
		}
		if(n&(1ll<<i)){
			m[1].remove(n,i-1);
		}
		else{
			m[0].remove(n,i-1);
		}

		return true;
	}

	ll find(ll n,ll i){
		//dbg(i);
		if(i < 0){
			return 0ll;
		}

		ll a = n&(1 << i);
		if(a && m[0].cnt > 0){
			return ((1ll<<i) + m[0].find(n,i-1));
		}
		if(a)
			return m[1].find(n,i-1);

		if(!a && m[1].cnt > 0){
			return (1ll << i) + m[1].find(n,i-1);
		}

		return m[0].find(n,i-1);
	}

};

int main(){

	fastio;
	int q;
	cin >> q;
	trie t = trie();
	//t.add(0,31);
	fr(i,q){
		//dbg(i);
		string s;
		cin >> s;
		ll a;
		cin >> a;
		if(s[0] == '+'){
			t.add(a,31);
		}
		if(s[0] == '-'){
			t.remove(a,31);
		}
		if(s[0] == '?')
			 cout << max(a,t.find(a,31)) << endl;
	}

}
