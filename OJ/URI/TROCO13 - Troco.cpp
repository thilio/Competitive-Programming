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
const ll llINF = 0x3f3f3f3f3f3f3f;

int v,m,ve[1123],memo[112345][1123];

bool dp(int custo,int j){
	if (custo==v) return (true);
	if (j==m || custo > v)
		return false;
	if (memo[custo][j] == -1){
		int &resp = memo[custo][j];
		resp = dp(custo + ve[j],j+1) ||dp(custo,j+1);
	}
	return (memo[custo][j]);
}

int main(){
	
	cin >> v; 
	cin >> m;
	ms(memo,-1);
	fr(i,m)
		cin >> ve[i];
	if (dp(0,0))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return(0);
}