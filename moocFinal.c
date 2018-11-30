#include<stdio.h>
void print(int a[],int N);
void getpre(int mid[],int pre[],int post[],int start,int N,int pres);
int main(void)
{
	int N;
	scanf("%d",&N);
	int post[N];
	int mid[N];
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&mid[i]);
	}
	int pre[N];
	//printf("%d",post[2]);
	getpre(mid,pre,post,0,N,0);
	print(pre,N);
 }
void print(int a[],int N)
{
	int i;
	for(i=0;i<N;i++){
		printf("%d",a[i]);
		if(i!=(N-1)) printf(" ");
	}
 }
 void getpre(int mid[],int pre[],int post[],int start,int N,int pres)
 {
 	if(N<=0) return;
 	int postroot=post[start+N-1];
 	pre[pres]=postroot; 
 	int i,midroot;
 	for(i=start;i<start+N;i++){
 		if(mid[i]==postroot){
 		midroot=i;
 		break;
 	}
	 } 
 	getpre(mid,pre,post,start,midroot-start,pres+1);
 	getpre(mid,pre,post,midroot+1,N-midroot-1,pres+N-midroot);
  } 
