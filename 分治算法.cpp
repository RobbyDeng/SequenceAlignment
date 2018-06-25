#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

int M[15][15];
char s1[15];//此时序列长度为15，执行不同长度的序列时，需改变数组的大小
char s2[15];
int m=0,n=0;
int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}
int opt(int i,int j)
{
   int penalty;
   if(M[i][j]!=-1){
   	if(i==m)
       return M[i][j]=2*(n-j);
   else if(j==n)
       return M[i][j]=2*(m-i);
   else{
       if(s1[i]==s2[j])
           penalty=0;
       else
           penalty=1;
       return M[i][j]=min(opt(i+1,j+1)+penalty,min(opt(i+1,j)+2,opt(i,j+1)+2));
   }
	} 
	else{
		return M[i][j];
	}
   
}



int main()
{
	int i,numofs1,numofs2,s[15][15]={0};
	
    for(i=0;i<15;i++)//数组赋初值
	{
		s1[i]='\0';
		s2[i]='\0';
	}
	
    //开始文本的读入
    FILE *fp;

	if((fp=fopen ("h.txt","rt"))==NULL)
	{
		cout<<"Error!Cannot open file."<<endl;
		exit(1);
	}

    fgets(s1,15,fp);
	//将h.txt中的内容读入数组S1
    for(i=0;s1[i]!='\0';i++)
	{
		cout<<s1[i];
		numofs1=i+1;
	}

	cout<<endl;
	if((fp=fopen ("m.txt","rt"))==NULL)
	{
		cout<<"Error!Cannot open file."<<endl;
		exit(1);
	}
    fgets(s2,15,fp);
	//将m.txt中的内容读入数组S2
    for(i=0;s2[i]!='\0';i++)
	{
		cout<<s2[i];
		numofs2=i+1;
	}
    cout<<endl;
	fclose(fp);

    m=strlen(s1);
    n=strlen(s2);
    cout<<m<<" "<<n<<endl;
    clock_t startTime,endTime;
    startTime=clock();
    int op=opt(0,0);
    cout<<"opt(0,0)="<<op<<endl;
    endTime=clock();
    cout<<"Total Time : "<<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
  
    return 0;
}
