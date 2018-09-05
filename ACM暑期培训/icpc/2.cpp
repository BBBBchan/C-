#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
    char a[505];
    int n,len,begin,maxBegin,i,j;
    scanf("%s",a);
    n=strlen(a);
    for(len=1;len<=n;len++)//枚举子串的所有可能的长度
    {
        maxBegin=n-len;
        for(begin=0;begin<=maxBegin;begin++)//枚举子串的开始点 
        {
            j=begin+len-1;
            for(i=begin;i<j;i++,j--) //遍历当前子串（a[i]~a[begin+len-1]）,判断是否回文串 
            {
                if(a[i]!=a[j]) break;
            }
            if(i>=j)//是回文串
            {
                j=begin+len-1;
                for(i=begin;i<=j;i++) printf("%c",a[i]);
                printf("\n");
            }
        }
    } 
    return 0;
}