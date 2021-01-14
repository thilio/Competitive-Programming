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

int main(){

	fastio;
	string t;
	getline(cin,t);
	vector<pair<char,char>> v;
	pair<char,char> pp;
	pp.fst = t[0];
	pp.snd = t[1];
	v.pb(pp);
	pp.fst = t[3];
	pp.snd = t[4];
	v.pb(pp);
	pp.fst = t[6];
	pp.snd = t[7];
	v.pb(pp);

	sort(all(v));

	int ans = -1;

	if(v[0] == v[1] && v[1] == v[2])
		ans = 0;
	if(v[0].snd == v[1].snd && v[1].snd == v[2].snd){
		if(v[1].fst == v[0].fst + 1 && v[2].fst == v[0].fst + 2){
			ans = 0;
		}
	}

	if(ans != -1){
		cout << ans << endl;
		return 0;
	}

	if(v[1] == v[0] || v[1] == v[2] || v[0] == v[2]) ans = 1;

	if(v[1].snd == v[0].snd && (v[1].fst == v[0].fst + 1 || v[1].fst == v[0].fst + 2)) ans = 1;

	if(v[1].snd == v[2].snd && (v[1].fst == v[2].fst - 1 || v[1].fst == v[2].fst - 2)) ans = 1;

	if(v[0].snd == v[2].snd && (v[0].fst == v[2].fst -1 || v[0].fst == v[2].fst - 2 )) ans = 1;

	if(ans == -1) ans = 2;

	cout << ans <<endl;

}
