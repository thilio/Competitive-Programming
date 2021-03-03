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

int resp[200200];

int solve(vi &a, vi& b){
	if(a.empty() || b.empty()) return 0;

	int j = 0;
	fr(i, a.size() + 2) resp[i] = 0;

	for(int i = 0; i < a.size(); i++){
		while(b[j] < a[i] && j < b.size()) j++;
		if(j < b.size() && a[i] == b[j]) resp[i] = 1;
	}
	for(int i = a.size() - 1; i >=0; i--){
		resp[i] += resp[i + 1];
	}

	int ans = 0;

	j = 0;
	while(j < b.size() && b[j] < a[0]) j++;

	int i = 1;
	int ct = 1;

	while(j < b.size()){
		while(i < a.size() && a[i] < b[j] + ct){
			i++;
			ct++;
		}

		auto l = upper_bound(all(b), b[j]);
		l--;
		auto r = upper_bound(all(b), b[j] + ct - 1);
		r--;

		int tent = (int)(r - l + 1);
		tent += resp[i];

		ans = max(ans,tent); 
		j++;
	}

	return ans;
}

vi bpos,bneg,spos,sneg;
void clear(){
	bpos.clear();
	bneg.clear();
	spos.clear();
	sneg.clear();
}
	
int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n,m;
		clear();
		cin >> n >> m;
		fr(i,n){
			int x;
			cin >> x;
			if(x < 0) bneg.pb(-x);
			else bpos.pb(x);
		}
		fr(i,m){
			int x;
			cin >> x;
			if(x < 0) sneg.pb(-x);
			else spos.pb(x);
		}

		reverse(all(sneg));
		reverse(all(bneg));

		int ans = solve(bpos,spos);
		ans += solve(bneg, sneg);

		cout << ans << endl;

	}

}
