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
	int n;
	int v[222344];
	cin >> n;
	fr(i,n)
		cin >> v[i];
	int max = 0;
	if (n==1){
		cout << 1 << endl;
		return (0);
	}


	fr(i,n-1){
		int at = 1;
		while (v[i+1] <= 2*v[i]){
			i++;
			at++;
			if (i==n-1)
				break;
		}
		if (at > max)
			max = at;
	}

	cout << max << endl;
	return (0);
    
}
