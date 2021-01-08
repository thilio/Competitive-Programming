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

ll esp(ll a){

	for(int i = 2;i*i<=a;i++){
		if(a%i == 0) return (a/i);
	}
	return 1;
}

void solvei(ll a){
	ll aux = 1;
	while(aux < a) aux *=2;
	aux--;

	ll res = aux^a;

	if(res == 0){
		cout << esp(a) << endl;
		return;
	}
	else
		cout << __gcd(a&res,a^res)<< endl;
}

int main(){

	fastio;
	int q;
	cin >> q;
	while(q--){
		ll a;
		cin >> a;
		if(a%2){
			solvei(a);
			continue;
		}
		ll aux = 1;
		while(aux <= a) aux *=2;
		aux--;
		cout << aux << endl;

		
	}

}
