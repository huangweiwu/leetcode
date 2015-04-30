#include<iostream>
using namespace std;
//实现kmp算法

void getNext(char *p,int *next)
{
    int j,k;
    int lastIndex=strlen(p)-1;
    next[0]=-1;
    j=0;
    k=-1;
    while(j < lastIndex)
    {
        if(k==-1||p[j]==p[k])    //匹配的情况下,p[j]==p[k]
        {
            ++j;
            ++k;
             
            //求next数组的优化；若p[j]==p[k]，则需要修正
			//不该出现p[j] = p[ next[j] ]。
			//当p[j] != s[i] 时，下次匹配必然是p[ next [j]] 跟s[i]匹配，如果p[j] = p[ next[j] ]，必然导致后一步匹配失败
			//（因为p[j]已经跟s[i]失配，然后你还用跟p[j]等同的值p[next[j]]去跟s[i]匹配，很显然，必然失配），所以不能允许p[j] = p[ next[j ]]
            if(p[j]==p[k])  
                next[j]=next[k];
            else
                next[j]=k;
        }
        else                   //p[j]!=p[k]，递归找到最长前缀和后缀相同长度
            k=next[k];
    }
}

int KMPMatch(char *s,char *p)
{
    int next[100];
    int i,j;
    i=0;
    j=0;
    getNext(p,next);
    while(i<strlen(s))
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];       //消除了指针i的回溯
        }
        if(j==strlen(p))
            return i-strlen(p);
    }
    return -1;
}