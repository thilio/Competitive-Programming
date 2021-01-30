#include<bits/stdc++.h>
using namespace std;
vector<int> V[10000];
int n,v[10000],fr[10000];
typedef struct{
	int a;
	int b;
	int c;
	int d;
}quadri;

int f(quadri q){
	return (q.a*1000 + q.b*100 + q.c*10 + q.d);
}

quadri g(int i){
	quadri q;
	q.a = i/1000;
	q.b = (i%1000)/100;
	q.c = (i%100)/10;
	q.d = i%10;

	return (q);
}

int isvalid(int k){
	int i;
	for (i=0;i<n;i++){
		if (v[i]==k)
			return (1);
	}
	return (0);
}

int BFS (int pi,int pf){
	queue<int> f;
	int i,x;
	if (pi==pf)
		return (0);
	f.push (pi);
	fr[pi] = 0;
	while(!f.empty()){
		x=f.front();
		f.pop();
		for(i=0;i<V[x].size();i++){
			if (!isvalid(V[x][i]) && fr[V[x][i]] == -1 ){
				fr[V[x][i]] = fr[x] + 1;
				f.push (V[x][i]);
				if (V[x][i] == pf)
					return  (fr[V[x][i]]);
			}

		}

	}
	return (-1);

}

int main(){
	int i,a,j,te,t,pi,pf,x;
	quadri q;
	cin >> t;	
	for (i=0;i<10000;i++){
		q = g(i);
		q.d = (q.d + 1)%10;
		a=f(q);
		V[i].push_back(a);
		q = g(i);
		q.d = (q.d + 9)%10;
		a=f(q);
		V[i].push_back(a);


		q = g(i);
		q.c = (q.c + 1)%10;
		a=f(q);
		V[i].push_back(a);
		q = g(i);
		q.c = (q.c + 9)%10;
		a=f(q);
		V[i].push_back(a);


		q = g(i);	
		q.b = (q.b + 1)%10;
		a=f(q);
		V[i].push_back(a);
		q = g(i);
		q.b = (q.b + 9)%10;
		a=f(q);
		V[i].push_back(a);

		q = g(i);
		q.a = (q.a + 1)%10;
		a=f(q);
		V[i].push_back(a);
		q = g(i);
		q.a = (q.a + 9)%10;
		a=f(q);
		V[i].push_back(a);	
	}


	for (te=0;te<t;te++){
		x=1;

		cin >> q.a;
		cin >> q.b;
		cin >> q.c;
		cin >> q.d;
		pi = f(q);
		cin >> q.a;
		cin >> q.b;
		cin >> q.c;
		cin >> q.d;
		pf = f(q);

		cin >> n;
		for (i=0;i<n;i++){
			cin >> q.a;
			cin >> q.b;
			cin >> q.c;
			cin >> q.d;
			v[i] = f(q);
			if(pf==v[i] || pi == v[i])
				x=-1;

		}

		for (i=0;i<10000;i++){
			fr[i] = -1;
		}

		if (x) x = BFS (pi,pf);
		cout << x << endl;
	}
	


	return (0);

}