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

	int t;
	cin >> t;

	fr(i,t){
		ll n,k,d1,d2;
		cin >> n >> k >> d1 >> d2;

		ll D1 = d1;
		ll D2 = d2;
		

		ll qnt = n - k;
		ll prec = d1 + d1 + d2;
		ll prec2 = d1 + d2 + d2;
		bool ok = true;

		if(prec > qnt) ok = false;
		if(prec2 > k) ok = false;
		if(((k - prec2)%3ll) != 0ll) ok = false;
		if(((qnt - prec)%3ll) != 0ll) ok = false;

		if(ok) cout << "yes\n";

		else {

			if(d2 <= d1){
				d1 = d1 - d2;
			}

			else{
				ll aux = d1;
				d1 = d2 - d1;
				d2 = aux;
			}

			ll qnt = n - k;
			ll prec = d1 + d1 + d2;
			ll prec2 = d1 + d2 + d2;
			bool ok = true;

			if(prec > qnt) ok = false;
			if(prec2 > k) ok = false;
			if(((k - prec2)%3ll) != 0ll) ok = false;
			if(((qnt - prec)%3ll) != 0ll) ok = false;

			if(ok) cout << "yes\n";

			else{
				d1 = D1;
				d2 = D2;
				swap(d1,d2);
				ll qnt = n - k;
				ll prec = d1 + d1 + d2;

				ll prec2 = d1 + d2 + d2;

				bool ok = true;

				if(prec > qnt) ok = false;
				if(prec2 > k) ok = false;
				if(((k - prec2)%3ll) != 0ll) ok = false;
				if(((qnt - prec)%3ll) != 0ll) ok = false;

				if(ok) cout << "yes\n";
				else{
					d1= D1;
					d2 = D2;
					if(d2 <= d1){
						ll aux = d1;
						d1 = d2;
						d2 = aux - d2;
					}

					else{
						d2 = d2 - d1;
					}
					
					ll qnt = n - k;
					ll prec = d1 + d1 + d2;

					ll prec2 = d1 + d2 + d2;

					bool ok = true;

					if(prec > qnt) ok = false;
					if(prec2 > k) ok = false;
					if(((k - prec2)%3ll) != 0ll) ok = false;
					if(((qnt - prec)%3ll) != 0ll) ok = false;

					if(ok) cout << "yes\n";
					else{
						cout << "no\n";
					}
				}
			}
		}
	}

}
