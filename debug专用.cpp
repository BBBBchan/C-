#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void game(int s)
{
	unsigned int b, c;                               //�趨��Ϸ�²�ֵ
	printf("������һ��һ�����ڵ�������\n");
	while (1)
	{
		c = scanf("%u", &b);
		if (c != 1)                                  //ʶ��Ƿ��ַ�
		{
			printf("�����������������\n");
			fflush(stdin);
			break;
		}
		else {
			if (s > b)                               //ͨ���²�ֵ��ϵͳ���ֵ�Ƚϣ��Բ²����ṩ����
				printf("guess small\n");
			if (s < b)
				printf("guess big\n");
			if (s == b)
			{
				printf("right������\n");
				break;                             //�²���ȷʱ����ѭ��
			}
		}


	}
	printf("��Ϸ����\n\n\n\n");

}

void meun()
{
	printf("********************************************************\n");
	printf("**********************   1.play   **********************\n");
	printf("**********************   0.exit   **********************\n");
	printf("********************************************************\n");
}
int main(){
	int a;                                //����һ��������ѡ����Ϸ�˵�
	do
	{
		meun();                           //��ʾ��Ϸ�˵�
		srand((unsigned)time(NULL));      //��ʼ�����������
		int s = rand() % 101;             //�����������%101����100�����������
		scanf("%d", &a);
		printf("%d \n", a);
		if (a == 1)                       //������aΪ1ʱ������game����
		{
			//printf("%d", s);
			game(s);
		}
	} while (a != 0);                     //����ѭ��ֻҪa��Ϊ0������ʼ�����е�����aΪ1ʱ��Ϊ0�˳�����

	return 0;
}
