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
	int n;
	cin >> n;
	string s;
	getline(cin,s);

	char x;int id;int freq[212345];

	int p,q;

	cin >> x;cin >> id; 

	freq[id] = 0;
	p = 0;
	q = 0;

	for (int i =1;i<n;i++){
		cin >> x;
		cin >> id;
		if (x=='L'){
			p--;
			freq[id] = p;
		}

		if (x=='R'){
			q++;
			freq[id] = q;
		}

		if (x == '?'){
			cout << min(q - freq[id],freq[id] - p) <<endl;
		}
	}
}
