#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
struct cards{
	int rank;
	int val;
	char a[5];
}card[60]={
};
int main(){	
	for(int i=1;i<=13;i++){
		char tt[5]; memset(tt,0,sizeof(tt));
		if(i==1) tt[1]='A';
		else if(i==10) tt[1]='1',tt[2]='0';
		else if(i==11) tt[1]='J';
		else if(i==12) tt[1]='Q';
		else if(i==13) tt[1]='K';
		else tt[1]=char(i+'0');
		tt[0]='$';
		printf("{%d,%d,\"%s\"},",0,100+i,tt);
	}
	cout<<endl;
	for(int i=1;i<=13;i++){
		char tt[5]; memset(tt,0,sizeof(tt));
		if(i==1) tt[1]='A';
		else if(i==10) tt[1]='1',tt[2]='0';
		else if(i==11) tt[1]='J';
		else if(i==12) tt[1]='Q';
		else if(i==13) tt[1]='K';
		else tt[1]=char(i+'0');
		tt[0]='&';
		printf("{%d,%d,\"%s\"},",0,200+i,tt);
	}
	cout<<endl;
	for(int i=1;i<=13;i++){
		char tt[5]; memset(tt,0,sizeof(tt));
		if(i==1) tt[1]='A';
		else if(i==10) tt[1]='1',tt[2]='0';
		else if(i==11) tt[1]='J';
		else if(i==12) tt[1]='Q';
		else if(i==13) tt[1]='K';
		else tt[1]=char(i+'0');
		tt[0]='*';
		printf("{%d,%d,\"%s\"},",0,300+i,tt);
	}
	cout<<endl;
	for(int i=1;i<=13;i++){
		char tt[5]; memset(tt,0,sizeof(tt));
		if(i==1) tt[1]='A';
		else if(i==10) tt[1]='1',tt[2]='0';
		else if(i==11) tt[1]='J';
		else if(i==12) tt[1]='Q';
		else if(i==13) tt[1]='K';
		else tt[1]=char(i+'0');
		tt[0]='#';
		printf("{%d,%d,\"%s\"},",0,400+i,tt);
	}
	return 0;
}
/*
$ & * #
*/

