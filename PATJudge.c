#include<stdio.h>
#define Radix 10
#define Max
struct key{
	int user_id;
	int problem_solve;
	int total_score;
};
typedef struct key Key;
struct user_score{
	int problem_id;
	int score_obtained;
};
typedef struct user_score User_score;
void gainScore(User_score Us[],int N,int K,int M);
void gainKey(User_score Us[],Key Uk[],int problem_score[],int N,int K);
void LSDRadixSort(int a[], int N );
void testGainScore(void);
void testGainKey(void);
void print1(User_score Us[],int K,int N);
void print2(Key Uk[],int N);
int main(void)
{
	/*@Test*/
	testGainScore();
	testGainKey();
	return 0;
}
void gainScore(User_score Us[],int N,int K,int M)
{
	int i;
	for(i=0;i<=N*K;i++){
		Us[i].problem_id=-1;
		Us[i].score_obtained=-1;
	}
	for(i=1;i<=M;i++){
		int ui,pi,pso;
		scanf("%d %d %d",&ui,&pi,&pso);
		Us[(ui-1)*K+pi].problem_id=pi;
		if(Us[(ui-1)*K+pi].score_obtained<pso)
		Us[(ui-1)*K+pi].score_obtained=pso;
	}
}
void gainKey(User_score Us[],Key Uk[],int problem_score[],int N,int K)
{
	int i,j;
	int cnt,sum,notsign;
	for(i=1;i<=N;i++){
		cnt=0;
		sum=0;
		notsign=-1;//not pass the compiler or no submission
		for(j=1;j<=K;j++){
			if(Us[(i-1)*K+j].score_obtained!=-1){
				notsign=1;
				sum=sum+Us[(i-1)*K+j].score_obtained;
<<<<<<< HEAD
				if(Us[(i-1)*K+j].score_obtained==problem_score[j])
=======
				if(Us[(i-1)*K+j].score_obtained==problem_score[j-1])
>>>>>>> 750406ab880a74ec84bfc74a3d20ece1a37aec86
					cnt++;
			} 
		}
		if(notsign==1){
			Uk[i].user_id=i;
			Uk[i].total_score=sum;
			Uk[i].problem_solve=cnt;
		} else{
			Uk[i].user_id=i;
			Uk[i].total_score=-1;
			Uk[i].problem_solve=-1;
		}
	}	
}
void testGainScore(void)
{
	int N,K,M;
	scanf("%d %d %d",&N,&K,&M);
	int problem_score[K];
	int i;
	for(i=0;i<K;i++){
		scanf("%d",&problem_score[i]);
	}
	User_score Us[N*K+1];
	gainScore(Us,N,K,M);
<<<<<<< HEAD
	print(Us,K,N);
	printf("Us[10]=%d",Us[10].score_obtained);
=======
	print1(Us,K,N);
}
void testGainKey(void)
{
	int N,K,M;
	scanf("%d %d %d",&N,&K,&M);
	int problem_score[K];
	int i;
	for(i=0;i<K;i++){
		scanf("%d",&problem_score[i]);
	}
	User_score Us[N*K+1];
	Key Uk[N+1];
	gainScore(Us,N,K,M);
	gainKey(Us,Uk,problem_score,N,K);
	print2(Uk,N);
>>>>>>> 750406ab880a74ec84bfc74a3d20ece1a37aec86
}
void LSDRadixSort(int a[], int N )
{
	
}
void print1(User_score Us[],const int K,const int N)
{
	int i,j;
	for(i=1;i<=N;i++){
		for(j=1;j<=K;j++){
			printf("User id: %d,Problem id: %d,Obtain score: %d\n",
					i,j,Us[(i-1)*K+j].score_obtained);
		}
	}
}
void print2(Key Uk[],int N)
{
	int i;
	for(i=1;i<=N;i++){
		printf("User id: %d,Problem solve: %d,Total score: %d\n"
				,Uk[i].user_id,Uk[i].problem_solve,Uk[i].total_score);
	}
}
