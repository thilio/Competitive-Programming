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

vector<tuple<int,int,int>> v;
int ans[100100];
int resp;
int n;


int lb(int k){
	if(n == 1) return 0;
	if(k < get<0>(v[1])) return 0;

	if(k >= get<0>(v[n-1])) return n-1;

	int l = 0;
	int r = n -1;

	while( (r - l) > 1){

		int m = (l + r)/2;

		if(get<0>(v[m]) > k){
			r = m - 1;
		}

		if(get<0>(v[m]) == k) return m;

		if(get<0>(v[m]) < k){
			l = m;
		}
	}

	if(k >= get<0>(v[r])) return r;
	else return l;

}

bool esta(ll x,ll y,ll c,ll r){
	if((x-c)*(x-c) + y*y <= r*r) return true;
	return false;
}

int main(){

	fastio;
	
	cin >> n;
	fr(i,n){
		tuple<int,int,int> a;
		cin >> get<0>(a) >> get<1>(a);
		get<2>(a) = i;
		v.pb(a);
	}

	sort(all(v));

	int m;
	cin >> m;
	frr(i,m){
		int x,y;
		cin >> x >> y;
		//dbg(x);
		int l = lb(x);
		if(esta(x,y,get<0>(v[l]),get<1>(v[l])) && ans[get<2>(v[l])] == 0)
			ans[get<2>(v[l])] = i;
		if(l < n-1){
			if(esta(x,y,get<0>(v[l+1]),get<1>(v[l+1])) && ans[get<2>(v[l+1])] == 0)
			ans[get<2>(v[l+1])] = i;
		}
	}

	vi p;
	int pp = 0;

	fr(i,n){
		if(ans[i] != 0){
			p.pb(ans[i]);
			pp++;
		}
		
		else
			p.pb(-1);
		
	}

	cout << pp << endl;
	fr(i,p.size()){
		cout << p[i] << ' ';
	}

	gnl;


}
