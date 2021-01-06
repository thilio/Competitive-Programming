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
string s;
int v[1000];
int g = 1;

int main(){

	fastio;

	int T;
	cin >> T;
	getline(cin,s);
	while(T--){
		getline(cin,s);

		cout << "Case #" << g++ <<": ";

		int x = 0;
		int n = s.size();
		fr(i,n) v[i] = s[i] - '0';

		v[n] = 0;

		fr(i,n+1){
			int dif = v[i] - x;
			if(dif > 0){
				while(dif){
					cout << "(";
					dif--;
				}
			}
			if(dif < 0){
				while(dif!=0){
					cout <<  ")";
					dif++;
				}
			}

			if(i==n) break;
			cout << v[i];
			x = v[i];

		}

		cout << endl;



	}

}
