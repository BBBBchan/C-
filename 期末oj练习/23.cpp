#include <stdio.h>
#include <string.h>
#define maxn 100
void sum(char *a, char *b,char *aws,int n,int m){	//�ӷ����ⲿ������ֻ֧���������
	int c[maxn],d[maxn];
	memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));  
	for(int i = 0; i < n; i++)
		c[i] = a[n-i-1]-'0';
	for(int i = 0; i < m; i++)
		d[i] = b[m-i-1]-'0';
	for(int i = 0; i < m || i < n; i++)
		aws[i] = c[i] + d[i];
	for(int i = 0; i < m || i < n; i++)
		while(aws[i] >= 10){
			aws[i] -= 10;
			aws[i+1] += 1;
		}
}
void minus(char *a,char *b,char *aws,int n,int m){		//�������ⲿ������ֻ�ܴ�����С����Ϊ����
	int c[maxn],d[maxn];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i = 0;i < n ; i++)
		c[i] = a[n-i-1]-'0';
	for(int i = 0; i < m; i++)
		d[i] = b[m-i-1]-'0';
	for(int i = 0; i < n; i++)
		aws[i] = c[i] - d[i];
	for(int i = 0;i < n; i++)
		while(aws[i] < 0){
			aws[i]+=10;
			aws[i+1]-=1;
		}
}
void mult(char *a,char*b,char*aws,int n,int m){		//�˷��ⲿ������ֻ֧���������
		int c[maxn],d[maxn];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i = 0; i < n; i++)
		c[i] = a[n-i-1]-'0';
	for(int i = 0; i < m; i++)
		d[i] = b[m-i-1]-'0';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			aws[j+i] += c[i] * d[j];
			}
		for(int i = 0; i < m+n; i++)
			while(aws[i] >= 10){
				aws[i] -= 10;
				aws[i+1] +=1;
			}
	}
}
int jianfa(char *a,char *b,char*aws,int x,int y){		//Ϊ��������˳��ʹ�������������ʱ�����Ǵ�����С��
	int kase =0,k=0;
	if(x > y){					//������С��
		minus(a,b,aws,x,y);		//�ڴ˵��ü������ⲿ�������ں�������ú�����
	}
	else if(x < y){
		minus(b,a,aws,y,x);
		kase = 1;			//С��������
	}
	else {					//������λ����ͬʱ���Ƚϴ�С������
		k = strcmp(a,b);
		if(k == 0)
			kase = -1;
		else if(k > 0)
			minus(a,b,aws,x,y);
		else{
			kase = 1;
			minus(b,a,aws,y,x);
		}					
	}
	return kase;
}
int main(){
	char a[maxn],b[maxn];
	int n = maxn-1,kase =0,k=0,p = 0,q = 0;
	char aws[205];
/*�ӷ�*/
	memset(aws,0,sizeof(aws));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%s %s",&a,&b);
	int x = strlen(a);
	int y = strlen(b);
	if(a[0] == '-'){				//��ȡ����
		for(int i = 1; i < x;i++)
			a[i-1] = a[i];
		a[x-1] = 0;					//ǰ��һλ
		x--;
		p = 1;						//��Ǹ���
	}
	if(b[0] == '-'){				//��ȡ����
		for(int i = 1; i < y;i++)
			b[i-1] = b[i];
		b[y-1] = 0;					//ǰ��һλ
		y--;
		q = 1;						//��Ǹ���
	}
	if(p == 0&&q == 0){			//�ӷ�����¶Գ��ָ��ŵ�������д�����ͬ��ͬ��Ϊ�ӣ�һ��һ��Ϊ��
		sum(a,b,aws,x,y);
	}
	else if(p == 0)
		kase = jianfa(a,b,aws,x,y);
	else if(q == 0)
		kase = jianfa(b,a,aws,y,x);
	else{
		printf("-");
		sum(a,b,aws,x,y);
	}
	while(aws[n] == 0){				//ȥ������ǰ�治��Ҫ��0
		n--;
	}
	if(n == -1)
		kase = -1;
	if(kase == 1)
		printf("-");			//������������
	if(kase == -1)
		printf("0");			//������ó�0
	for(;n>=0;n--)
	printf("%d", aws[n]);		//������
	return 0;
} 



