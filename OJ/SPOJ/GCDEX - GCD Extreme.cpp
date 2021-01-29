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

ll p[1000100];
ll f[1000100];
ll ans[1000100];

void phi(){
	fr(i,1000100){
		p[i] = i;
	}
	for(int i = 2;i<= 1000000;i++){
		if(p[i]==i){
			for(int j = i; j<= 1000000;j+=i){
				p[j] /= i;
				p[j] *= (i-1);
			}
		}
	}

}

void fn(){
	for(int i = 1;i<=1000000;i++){
		for(int j = i; j <= 1000000;j+=i){
			f[j] += i*p[j/i];
		}
	}

	ans[2] = f[2] - 2;

	for(int i = 3;i <= 1000000;i++){
		ans[i] = ans[i-1];
		ans[i] += f[i] - i;
	}

}

int main(){

	fastio;

	phi();
	fn();


	ll n;
	cin >> n;


	while(n != 0){
		cout << ans[n] << endl;
		cin >> n;
	}

}
