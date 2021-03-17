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
const int MAXN = 100100;

int n;
int p[MAXN], c[MAXN], lcp[MAXN], cnt[MAXN], p_new[MAXN], c_new[MAXN];
pair <char,int> a[MAXN];
string t;

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

void build(string &s){ // Build the SA in p, and the LCP in the array lcp. Complexity O(n logn)
	s.push_back('$'); // REMEMBER YOU ARE MODIFYING THE STRING
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

int comp(int m, string &s){
	int i = p[m];
	int j = 0;

	while(j < s.size()){
		if(s[j] == t[i]){
			i++;
			j++;
		}
		else if(s[j] < t[i]) return  1;
		else if(s[j] > t[i]) return -1;
	}

	return 0;
}

bool bb(string &s){
//	dbg(s);

	int l = 1;
	int r = n - 1;

	while(l <= r){
		int m = (l + r)/2;
		int x = comp(m , s);
		//dbg(p[m]);
		//dbg(x);
		if(x == 0) return true;
		if(x == -1) l = m + 1;
		if(x == 1) r = m - 1;
	}

	return false;
}

int main(){

	
	getline(cin,t);
	build(t);

	//fr(i, n) dbg(p[i]);
	int m;
	cin >> m;
	fr(i, m){
		string s;
		cin >> s;
		if(bb(s)) cout << "Y" << endl;
		else cout << "N" << endl;
	}

}

