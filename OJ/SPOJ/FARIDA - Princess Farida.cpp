#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define kara cout << "karadola" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;

int n,v[11234];
long long memo[11234][2];

long long dp (int i,int j){
	if (i==n) return 0;
	long long &resp = memo[i][j];
	if (resp == -1){
		resp = dp (i+1,0);
		if (j==0)
			resp = max(resp, v[i] + dp(i+1,1));
		
	}

	return (resp);
}


int main(){
	int T,g=1;
	cin >> T;
	while(T--){
		cin >>  n;
		fr(i,n)
			cin >> v[i];

		ms(memo,-1);		
		cout << "Case " << g << ": ";
		cout << dp (0,0) << endl;
		g++;
		//fr(i,n)
		//	cout << memo[i] << endl;
	}


	return 0;
}