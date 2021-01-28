#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define endl '\n'

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

int v[2010];
int freq[2001000];
vii par;
int n;
bool tent(int val){
	fr(i,n) freq[v[i]]++;
	int at = val;
	bool deu = true;

	for(int j = n-1; j >= 0; j--){
		if(freq[v[j]] == 0) continue;
		if(v[j] >= at){
			deu = false;
			break;
		}
		if(freq[at - v[j]] == 0){
			deu = false;
			break;
		}
		else{
			par.pb(mp(v[j], at - v[j]));
			freq[v[j]]--;
			freq[at - v[j]]--;
			if(freq[v[j]] < 0){
				deu = false;
				break;
			} 
			at = v[j]; 
		}
	}

	fr(i,n) freq[v[i]] = 0;

	if(deu){
		cout << "YES" << endl;
		cout << val << endl;
		fr(i,par.size()){
			cout << par[i].fst << ' ' << par[i].snd << endl;
		}
		par.clear();
		return true;
	}

	par.clear();
	return false;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		n *= 2;
		fr(i,n) cin >> v[i];
		sort(v, v + n);
		bool x = false;
		for(int i = 0; i < n - 1; i++){
			x = tent(v[n - 1] + v[i]);
			if(x) break;
		}

		if(!x){
			cout << "NO" << endl;
		}
	}

}
