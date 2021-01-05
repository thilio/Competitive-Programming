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
	int n,k;
	int x;
	int m;

	cin >> n >> k;
	m = k;
	k = 2*k + 1;

	if (n%k == 0)
		x = n/k;
	else
		x = n/k + 1;

	cout << x << endl;
	k= m;
	int l = 1;
	while(l < n - 2*(x-1)*k - (x -1) - k)
		l++;
	fr(i,x){
		cout << l << ' ';
		l+=2*k + 1;
	}
	gnl;

	return (0);



	
}