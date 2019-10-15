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
	char poker[5];
}card[60]={
	{},
	{0,101,"$A"},
	{0,102,"$2"},
	{0,103,"$3"},
	{0,104,"$4"},
	{0,105,"$5"},
	{0,106,"$6"},
	{0,107,"$7"},
	{0,108,"$8"},
	{0,109,"$9"},
	{0,110,"$10"},
	{0,111,"$J"},
	{0,112,"$Q"},
	{0,113,"$K"},
	{0,201,"&A"},
	{0,202,"&2"},
	{0,203,"&3"},
	{0,204,"&4"},
	{0,205,"&5"},
	{0,206,"&6"},
	{0,207,"&7"},
	{0,208,"&8"},
	{0,209,"&9"},
	{0,210,"&10"},
	{0,211,"&J"},
	{0,212,"&Q"},
	{0,213,"&K"},
	{0,301,"*A"},
	{0,302,"*2"},
	{0,303,"*3"},
	{0,304,"*4"},
	{0,305,"*5"},
	{0,306,"*6"},
	{0,307,"*7"},
	{0,308,"*8"},
	{0,309,"*9"},
	{0,310,"*10"},
	{0,311,"*J"},
	{0,312,"*Q"},
	{0,313,"*K"},
	{0,401,"#A"},
	{0,402,"#2"},
	{0,403,"#3"},
	{0,404,"#4"},
	{0,405,"#5"},
	{0,406,"#6"},
	{0,407,"#7"},
	{0,408,"#8"},
	{0,409,"#9"},
	{0,410,"#10"},
	{0,411,"#J"},
	{0,412,"#Q"},
	{0,413,"#K"}
};
bool cmp(cards xx,cards yy){
	return xx.val<yy.val;
}
int main(){
	while(getchar()){
	for(int i=1;i<=52;i++){
		card[i].val=int(random()%233233233);
		//cout<<card[i].val<<endl;
	}
	sort(card+1,card+53,cmp);
	int num=0;
	for(int i=1;i<=52;i++){
		num++;
		printf("%s ",card[i].poker);
		if(num==13) num=0,printf("\n");
	}
	}
	return 0;
}
/*
$ & * #
*/

