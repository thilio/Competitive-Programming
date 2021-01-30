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

typedef struct {
	int x;
	int y;
} par;

int memo[100][1500],C,F;
par v[50];

int dp (int i,int j){
	if (j>C) return -INF;
	if (i==F || j==C) return 0;
	int &resp = memo[i][j];
	if (resp == -1){
		resp = max(v[i].y + dp(i+1,j+v[i].x),dp(i+1,j));
	}
	return (resp);
}


int main(){
	int g=1;

	cin >> C;
	cin >> F;

	while (C!=0){
		ms(v,0);
		ms(memo,-1);
		fr(i,F)
			cin >> v[i].x >> v[i].y;

		cout << "Teste " << g << endl;
		g++;
		cout << dp(0,0) << endl;
		cout << endl;
		cin >> C;
		cin >> F;

	}


	return 0;
}