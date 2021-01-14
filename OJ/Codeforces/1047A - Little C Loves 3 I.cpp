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
	int n;
	cin >> n;
	if (n%3 == 0)
		cout << '1' << " 1" <<' ' << n - 2 << endl;
	else
		cout << '2' << " 1" << ' ' << n-3 << endl;
	return(0);

}