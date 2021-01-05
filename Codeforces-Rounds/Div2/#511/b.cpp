#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >
#define gnl cout << endl
#define olar cout << "olar" << endl

const int INF = 0x3f3f3f3f;

int main(){
	int n,max = 0;
	cin >> n;
	int i;
	for( i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		if (x + y > max)
			max = x + y;
	}
	cout << max << endl;
}