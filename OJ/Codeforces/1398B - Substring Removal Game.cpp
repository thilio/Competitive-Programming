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

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;

		vector<int> v;
		v.clear();

		int i = 0;
		
		while(i < s.size()){
			if(s[i] == '0'){
				i++; continue;
			}
			else{
				int ct = 0;
				while(i < s.size() && s[i] == '1'){
					ct++;
					i++;
				}
				v.pb(ct);
			}
		}

		sort(all(v));
		reverse(all(v));	
		int sum = 0;
		for(int i = 0; i < v.size(); i += 2) sum += v[i];

		cout << sum << endl;
	}

}
