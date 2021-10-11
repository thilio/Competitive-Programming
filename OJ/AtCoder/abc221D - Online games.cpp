#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

int ans[200100];

int main(){

	fastio;

	int n;
	cin >> n;


	vector<pii> v;

	fr(i, n){
		int a, b;
		cin >> a >> b;

		v.pb({a, 1});
		v.pb({a + b, -1});
	}

	sort(all(v));

	int last = 0;
	int p = 0;

	for(int i = 0; i < v.size();){
		int day = v[i].fst;
		int event = v[i].snd;

		ans[p] += day - last;
		last = day;
		
		while(i < v.size() && v[i].fst == day){
			p += v[i].snd;
			i++;	
		}
	}

	frr(i, n){
		cout << ans[i] << ' ';
	}
	gnl;




}
