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

int v[200200];
bool used[200200];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		fr(i, n){
			if(s[i] == '0' && t[i] == '0') v[i] = 0;
			else if(s[i] == '1' && t[i] == '1') v[i] = 1;
			else v[i] = 2; 

			used[i] = false;
		}

		//gnl;
		//fr(i, n) cout << v[i];
		//gnl;

		int sum = 0;

		fr(i, n){
			if(v[i] == 2) sum += 2;
			if(v[i] == 0) sum++;

			if(v[i] == 1){
				if(i > 0 && v[i - 1] == 0 && used[i - 1] == false) sum++;
				else if(i < n - 1 && v[i + 1] == 0){
					sum++;
					used[i + 1] = true;
				}
			}
		}

		cout << sum << endl;

	}

}
