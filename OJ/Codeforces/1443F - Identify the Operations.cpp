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
const int MOD = 998244353;

int n,k;
int a[200200], b[200200], pre[200200], pos[200200];

int mapa[200200];
int fut[200200];

void init(){
	for(int i = 1; i <= n; i++){
		pre[i] = i - 1;
		pos[i] = i + 1;
		mapa[i] = 0;
		fut[i] = 0;
	}
}

void del(int i){
	pos[pre[i]] = pos[i];
	pre[pos[i]] = pre[i];
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		init();
		frr(i,n) cin >> a[i];
		frr(i,n) mapa[a[i]] = i;
		frr(i,k) cin >> b[i];
		frr(i,k) fut[b[i]]++;

		

		ll ans = 1;

		frr(i,k){
			ll aux = 0;
			int j = mapa[b[i]];
			if(pre[j] != 0 && fut[a[pre[j]]] == 0){
				del(pre[j]);
				aux++;				
			}

			if(pos[j] <= n && fut[a[pos[j]]] == 0){
				aux++;
				if(aux == 1) del(pos[j]);
			}

			ans *= aux;
			ans %= MOD;
			//dbg(aux);
			fut[b[i]]--;
		}

		cout << ans << endl;
	}

}
