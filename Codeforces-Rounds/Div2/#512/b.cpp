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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
 	int n,d;
 	cin >> n >> d;
 	int q;
 	cin >> q;
 	fr(i,q){
 		int x,y;
 		bool boo = true;
 		cin >> x >> y;
 		if (x > n || y > n) boo = false;
 		if (y - x > d) boo = false;
 		if (x - y > d) boo = false;
 		if (x + y < d) boo = false;
 		if(x + y > 2*n - d) boo = false;

 		if (boo) cout << "YES" << endl;
 		else cout <<"NO"<<endl; 
 	}   

}