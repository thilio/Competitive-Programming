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

vector<int> p, c, lcp;
ll seg[16000000];

ll resp[400400];

void update(int node,int l,int r,int pos,int val){
	if(pos < l || pos > r) return;
	if(l == r && l == pos){
		seg[node] = val;
		return;
	}
	int m = (l + r)/2;
	update(2*node,l,m,pos,val);
	update(2*node + 1,m + 1,r,pos,val);

	seg[node] = max(seg[2*node], seg[2*node + 1]); 
}

ll query(int node,int l,int r,int a,int b){
	if(l > b || r < a) return -1;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;

	return max(query(2*node,l,m,a,b),query(2*node + 1,m+1,r,a,b));
}

void count_sort(){
	int n = p.size();

	vector<int> cnt(n);

	for(auto x : c) cnt[x]++;

	vector<int> pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; i++){
		pos[i] = pos[i-1] + cnt[i-1];
	}

	vector<int> p_new(n);
	for(auto x : p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}

	p = p_new;
}

void build(string &s){
	s.pb('$');
	int n = s.size();

	p.resize(n);c.resize(n);

	vector<pair<char,int>> a(n);
	for(int i = 0; i < n; i++) a[i] = {s[i],i};
	sort(all(a));

	for(int i = 0; i < n; i++) p[i] = a[i].snd;
	c[p[0]] = 0;

	for(int i = 1; i < n; i++){
		c[p[i]] = c[p[i - 1]];
		if(a[i].fst != a[i-1].fst) c[p[i]]++;
	}

	int k = 0;
	while((1 << k) < n){
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - (1 << k) + n)%n;
		}

		count_sort();

		vector<int> c_new(n);
		c_new[p[0]] = 0;

		for(int i = 1; i < n; i++){
			pii at = {c[p[i]], c[(p[i] + (1 << k))%n]};
			pii prev = {c[p[i-1]], c[(p[i-1] + (1 << k))%n]};
			c_new[p[i]] = c_new[p[i-1]];
			if(at != prev) c_new[p[i]]++; 
		}

		c = c_new;
		k++;
	}
}

void build_lcp(string &s){
	int n = s.size();
	lcp.resize(n);

	int k = 0;
	for(int i = 0; i < n-1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i + k] == s[j + k]) k++;

		lcp[pi] = k;
		k = max(0,k - 1);
	}
}


int main(){

	fastio;
	string t;
	getline(cin,t);
	build(t);
	build_lcp(t);

	ms(seg,-1);
	ll n = t.size();
	ll ans = (n*(n -1))/2;

	update(1,0,n-1,0,1);
	for(ll i = 2; i < n; i++){
		ll k = lcp[i];
		if(k == 0){
			update(1,0,n-1,k,i);
			continue;
		}

		ll j = query(1,0,n-1,0,k-1);
		update(1,0,n-1,k,i);
		resp[i] = k*(i - j);
		resp[i] += resp[j];
	}

	frr(i,n-1) ans += resp[i];

	cout << ans << endl;



}
