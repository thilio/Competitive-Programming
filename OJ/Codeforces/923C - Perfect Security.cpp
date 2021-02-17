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

	void add(int n,int i){
		cnt++;
		if(i<0){
			wrd++;
			return;
		}

		int aux = n& (1ll << i);
		if(aux!=0) aux= 1;

		if(!m.count(aux))
			m[aux] = trie();

		m[aux].add(n,i-1);
	}

	void remove(int n,int i){
		cnt--;
		if(i < 0){
			wrd--;
			return;
		}

		int aux = n&(1ll << i);
		if(aux != 0) aux = 1;
		m[aux].remove(n,i-1);
	}

	ll find(int n,int i){
		if(i < 0) return 0;

		int aux = (1ll << i)&n;
		if(aux!=0) aux = 1;

		if(aux == 1){
			if(m.count(1) && m[1].cnt > 0){
				return (1ll << i) + m[1].find(n,i-1);
			}
			else
				return m[0].find(n,i-1);
		}

		else{
			if(m.count(0) && m[0].cnt > 0){
				return m[0].find(n,i-1);
			}
			else
				return (1ll << i) + m[1].find(n,i-1);
		}
	}
};

int main(){

	fastio;

	trie t =trie();

	int n;
	cin >> n;
	ll v[300300];
	fr(i,n) cin >> v[i];

	fr(i,n){
		int a;
		cin >> a;
		t.add(a,60);
	}

	fr(i,n){
		ll aux;
		aux = t.find(v[i],60);
		///dbg(aux);
		t.remove(aux,60);
		cout << (aux^v[i]) << ' ';
	}
	gnl;

}
