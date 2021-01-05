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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){	
	int n,a,b;
	cin >> n >> a >> b;
	int v[100];
	fr(i,n)
		cin >> v[i];
	bool ok =true;
	int c = 0;
	fr(i,n/2){
		if (v[i] == 2 && v[n -i -1] == 1)
			c += b;
		else if (v[i] == 2 && v[n -i -1] == 0)
			c+=a;
		else if (v[i] == 0 && v[n -i -1] == 2)
			c += a;
		else if (v[i] == 1 && v[n -i -1] == 2)
			c+=b;
		else if (v[i] == 2 && v[n-i-1] == 2)
			c+= 2*min(a,b);
		else if (v[i] != v[n-1-i])
			ok = false;

	}

	if (n%2 == 1){
		if (v[n/2] == 2)
			c+= min(a,b);
	}

	if (!ok) cout << -1 << endl;
	else cout << c << endl;
	return (0);

}