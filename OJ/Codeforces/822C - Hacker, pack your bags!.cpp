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
vector<pair<int,pii>> p;
vector<pair<int,pii>> q;
int n,d;

int main(){

	fastio;

	cin >> n;
	cin >> d;
	fr(i,n){
		int a,b,c;
		cin >> a >> b >> c;
		pii x;
		x = mp(c,b - a + 1);
		p.pb(mp(a,x));
		q.pb(mp(b,x));
	}

	sort(all(q));
	sort(all(p));

	int best[300300];
	ms(best,2*INF);




	int k = 0;
	int ans = 2*INF;
	int j = 0;
	while(k < n){
		pair<int,pii> x = p[k];

		while(j < n && q[j].fst < x.fst){
			best[q[j].snd.snd] = min(best[q[j].snd.snd],q[j].snd.fst);
			j++;
		}

		int dur = x.snd.snd;
		if(d - dur < 0){
			k++;
			continue;
		}
		if(best[d-dur] != 2*INF){
			ans = min(ans,x.snd.fst + best[d-dur]);
		}

		
		k++;

	}

	if(ans == 2*INF) ans = -1;
	cout << ans << endl;

}
