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
	while(t--){
		int n,k;
		cin >> n>>k;
		string s;
		s.clear();
		getline(cin,s);
		getline(cin,s);

		sort(all(s));
		set<int> S;
		S.clear();
		fr(i,n){
			S.insert(s[i]);
		}
		int dif = S.size();

		int ct = 0;
		fr(i,n){
			if(s[i] == s[0]) ct++;
		}

		if(ct < k){
			cout << s[k-1] << endl;
		}
		else{

			if(dif == 1){
				fr(i,(n + k - 1)/k) cout << s[0];
				gnl;
				continue;
			}
			if(dif == 2 && ct == k){
				int l = n - k;
				int delta = (l + k -1)/k;

				cout << s[0];
				fr(i,delta) cout << s[n-1];
				gnl;
				continue;

			}
			cout << s[0];
			for(int i = k; i < n; i++){
				cout << s[i];
			}
			gnl;
		}

	}

}
