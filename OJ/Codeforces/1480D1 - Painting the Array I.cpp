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

int v[100100];
int p[100100];
int pr[100100];
int nxt[100100];

int main(){

	fastio;

	int n;
	cin >> n;
	fr(i,n) cin >> v[i];

	for(int i = n - 1; i>= 0; i--){
		if(i == n - 1){
			p[i] = 1;
			continue;
		}
		if(v[i] == v[i + 1]) p[i] = 1 + p[i + 1];
		else p[i] = 1;
	}

	int nx = n + 1;
	for(int i = n - 1; i>= 0; i--){
		nxt[i] =  nx;
		if(p[i] >= 2) nx = v[i];
	}

	int ans = 0;
	int i = 0;
	int la,lb;
	
	la = -1;
	lb = -1;

	while(i < n){
		if(p[i] >= 2){
			if(la != v[i] && lb != v[i]){
				ans += 2;
				la = v[i];
				lb = v[i];
			}
			if(la != v[i] && lb == v[i]){
				ans++;
				la = v[i];
			}
			if(la == v[i] && lb != v[i]){
				ans++;
				lb = v[i];
			}
		}
		else{
			if(la == v[i]){
				lb = v[i];
				ans++;
			}
			else if(lb == v[i]){
				la = v[i];
				ans++;
			}
			else if(la == nxt[i]){
				la = v[i];
				ans++;
			}
			else{
				lb = v[i];
				ans++;
			}
		}
		i += p[i];
	}

	cout << ans << endl;

}
