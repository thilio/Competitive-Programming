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
	int v[1123456];
	cin >> n;
	fr(i,n)
		cin >> v[i];
	sort (v,v+n);
	if (n == 1){
		cout << v[0] << endl;
		return (0);
	}

	if (v[0] >= 0){
		long long sum = 0;
		sum -= v[0];
		for(int i=1;i<n;i++)
			sum += v[i];
		cout << sum << endl;
	}

	else {
		long long sum = 0;
		fr(i,n){
			if (v[i] < 0 && i != n-1) sum -= v[i];
			else sum += v[i];
		}

		cout << sum << endl;
	}

	return (0);
}