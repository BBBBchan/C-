#include <cstdio>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m, x1, y1, kase=0,countx=1, county=1;
	scanf("%d %d",&n,&m);
	char a[120][120];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(!kase&&a[i][j]=='B'){
				x1 = i;
				y1 = j;
				kase = 1;
			}
			cin >> a[i][j];
		}
	printf("%d %d", x1, y1);
	for(int i = y1+1; i < m; i++){
		if(a[x1][i] == 'B')
			countx++;
		else break;
	}
	for(int j = x1+1; j<n; j++){
		if(a[j][y1] == 'B')
			county++;
		else break;
	}
	printf("%d %d\n", x1+1+(countx+1)/2, y1+1+(county+1)/2);
	return 0;
}
