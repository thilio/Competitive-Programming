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
const int MAXN = 300100;

const int N = 300100;
const int LOGN = 20;

int lg[N];
int st[N][LOGN];

int n;
int m, k;
int p[MAXN], c[MAXN], lcp[MAXN], cnt[MAXN], p_new[MAXN], c_new[MAXN];
int tipo[MAXN];
ll tam[MAXN];
int freq[MAXN];
ll ans[MAXN];
pair <int ,int> a[MAXN];

int lim[MAXN];

vi v;

void build_st(){
	lg[1] = 0;
	for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

	for(int i = 0; i < n; i++) st[i][0] = lcp[i];

	for(int j = 1; j <= lg[n]; j++){
		for(int i = 0; i + (1 << j) <= n; i++){
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query_st(int l, int r){ // minimum element in v[l, ..., r] 
	if(l > r) return INF;
	int j = lg[r - l + 1];
	return min(st[l][j], st[r - (1 << j) + 1][j]);
}

void count_sort(){
	fill(cnt, cnt + n + 1, 0);

	for(int i = 0; i < n; i++) cnt[c[i] + 1]++;

	cnt[0] = 0;
	for(int i = 1; i < n; i++){
		cnt[i] += cnt[i-1];
	}

	for(int i =0; i < n; i++){
		int j = c[p[i]];
		p_new[cnt[j]] = p[i];
		cnt[j]++;
	}

	for(int i = 0; i < n; i++){
		p[i] = p_new[i];
	}
}

void build(vi &s){ // Build the SA in p, and the LCP in the array lcp. Complexity O(n logn)
	//s.push_back('!'); // REMEMBER YOU ARE MODIFYING THE STRING
	n = s.size();

	for(int i = 0; i < n; i++) a[i] = {s[i],i};
	sort(a, a + n);

	p[0] = n - 1;
	c[p[0]] = 0;

	for(int i = 1; i < n; i++){
		p[i] = a[i].second;
		c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	int k = 0;
	while((1 << k) < n){
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - (1 << k) + n)%n;
		}

		count_sort();

		c_new[p[0]] = 0;
		for(int i = 1; i < n; i++){
			pair<int,int> at = {c[p[i]], c[(p[i] + (1 << k))%n]};
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k))%n]};
			c_new[p[i]] = c_new[p[i-1]] + (at != prev);
		}
		for(int i =0; i < n; i++) c[i] = c_new[i];
		k++;	
	}

	k = 0;
	for(int i = 0; i < n-1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i + k] == s[j + k]) k++;
		lcp[pi] = k;
		k = max(0,k - 1);
	}
}

bool ok (int ind, int sz){
	int lo = -1;
	int l = 0;
	int r = ind;

	while(l <= r){
		int m = (l + r)/2;
		if(query_st(m + 1, ind) >= sz){
			r = m - 1;
			lo = m;
		}
		else l = m + 1;
	}

	int hi = -1;
	l = ind;
	r = v.size() - 1;

	while(l <= r){
		int m = (l + r)/2;
		if(query_st(ind + 1, m) >= sz){
			l = m + 1;
			hi = m;
		}
		else r = m - 1;
	}

	if(lo <= lim[hi]) return true;
	return false;
}

int main(){

	cin >> m >> k;

	
	frr(i, m){
		string t;
		cin >> t;
		for(auto x: t) v.pb(x - 'a');
			v.pb(-i);
		tam[i] = t.size();
	}

	if(k > m){
		fr(i, m) cout << 0 << ' ';
		gnl;
		return 0;
	}

	if(k == 1){
		ll resp = 0;
		frr(i, m) cout << (tam[i]*(tam[i] + 1))/2 << ' ';
		gnl;
		return 0;
	}
	

//	dbg(v.size());

	int ct = 1;
	fr(i, v.size()){
		tipo[i] = ct;
		if(v[i] < 0) ct++;
	}

	build(v);
	build_st();

	int f = 0;

	int l = 0;
	int r = m - 1;

	for(int i = l; i < r; i++){
		freq[tipo[p[i]]]++;
		if(freq[tipo[p[i]]] == 1) f++;
	}

	ms(lim, -1);

	while(r < v.size()){
		freq[tipo[p[r]]]++;
		if(freq[tipo[p[r]]] == 1) f++;
		while(l <= r && (f > k || freq[tipo[p[l]]] != 1)){
			freq[tipo[p[l]]]--;
			if(freq[tipo[p[l]]] == 0) f--;
			l++;
		}

		lim[r] = l;
		r++;
	}

	for(int i = m; i < n; i++){
 		int l = 1;
 		int r = n;
 		int best = 0;

 		while(l <= r){
 			int m = (l + r)/2;

 			if(ok(i, m)){
 				l = m  + 1;
 				best = m;
 			}
 			else{
 				r = m - 1;
 			}
 		}
 		ans[tipo[p[i]]] += best;
	}

	frr(i, m) cout << ans[i] << ' ';
	gnl;








}

