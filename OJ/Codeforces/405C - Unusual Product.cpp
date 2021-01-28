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
	scanf("%d", &n);

	int mat[1010][1010];

	fr(i,n){
		fr(j,n){
			scanf("%d", &mat[i][j]);
		}
	}

	int ans = mat[0][0];

	for(int i = 1; i < n;i++){
		ans = ans^mat[i][i];
	}

	string s;

	int q;
	scanf("%d", &q);

	int ct = 0;
	fr(i,q){
		int op;
		scanf("%d", &op);
		if(op == 3){
			if(ans^(ct%2))
				s.pb('1');
			else 
				s.pb('0');

		}
		else{
			scanf("%d", &op);
			ct++;
		}

	}

	fr(i,s.size())
		printf("%c",s[i]);

	printf("\n");

}
