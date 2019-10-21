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
#define mm(x,b) memset((x),(b),sizeof(x))
#define all(x) x.begin(),x.end()
typedef long long ll;
using namespace std;

struct cards{
	int rank;
	int val;
	char poker[5];
}card[5][15]={
0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,0,"",0,102,"$2",0,103,"$3",0,104,"$4",0,105,"$5",0,106,"$6",0,107,"$7",0,108,"$8",0,109,"$9",0,110,"$10",0,111,"$J",0,112,"$Q",0,113,"$K",0,114,"$A",0,0,"",0,0,"",0,202,"&2",0,203,"&3",0,204,"&4",0,205,"&5",0,206,"&6",0,207,"&7",0,208,"&8",0,209,"&9",0,210,"&10",0,211,"&J",0,212,"&Q",0,213,"&K",0,214,"&A",0,0,"",0,0,"",0,302,"*2",0,303,"*3",0,304,"*4",0,305,"*5",0,306,"*6",0,307,"*7",0,308,"*8",0,309,"*9",0,310,"*10",0,311,"*J",0,312,"*Q",0,313,"*K",0,314,"*A",0,0,"",0,0,"",0,402,"#2",0,403,"#3",0,404,"#4",0,405,"#5",0,406,"#6",0,407,"#7",0,408,"#8",0,409,"#9",0,410,"#10",0,411,"#J",0,412,"#Q",0,413,"#K",0,414,"#A"
};

struct pos{
	int a[15];
}_data[72080];
int num;
int flag[15];
void pro_work(){
	for(int i=1;i<=13;i++)
	for(int ii=i+1;ii<=13;ii++)
	for(int iii=ii+1;iii<=13;iii++)
	for(int iiii=iii+1;iiii<=13;iiii++)
	for(int iiiii=iiii+1;iiiii<=13;iiiii++){
		mm(flag, 0); 
		//for(int j=0;j<15;j++) flag[j]=0;
		flag[i]=flag[ii]=flag[iii]=flag[iiii]=flag[iiiii]=1;
		for(int x=1;x<=13;x++){
			if(!flag[x]){
				for(int y=x+1;y<=13;y++){
					if(!flag[y]){
						for(int z=y+1;z<=13;z++){
							if(!flag[z]) {
								flag[x]=1,flag[y]=1,flag[z]=1;
								_data[num].a[1]=x,_data[num].a[2]=y,_data[num].a[3]=z,_data[num].a[4]=i,_data[num].a[5]=ii,_data[num].a[6]=iii,_data[num].a[7]=iiii,_data[num].a[8]=iiiii;
								int ppos=9;
								for(int fl=1;fl<=13;fl++){
									if(!flag[fl]) _data[num].a[ppos++]=fl; 
								}
							    flag[x]=0,flag[y]=0,flag[z]=0;
								num++;
							}
						}
					}
				}
			}
		}
		//flag[i]=flag[ii]=flag[iii]=flag[iiii]=flag[iiiii]=0;
	}

}


int cmp_temp;

int in_card[15];




struct sel{
	int head[4];
	int mid[6];
	int tail[6];
	int kind[4]; //head mid tail
	int val[4];//val[0] total 1head 2mid 3tail
	int tolval;
}temp,aans;

bool operator <(sel xx,sel yy){
	return xx.tolval>yy.tolval;
}
priority_queue<sel> select;
int val_type[12]={
	0,1,2,3,4,5,8,12,16,20
};

void deal_head(){
	int aa[4];
	for(int i=1;i<=3;i++)
	aa[i]=temp.head[i]%100;
	sort(aa+1, aa+4);
	
	if(aa[1]==aa[2]&&aa[2]==aa[3])		
	temp.kind[1]=4,temp.val[1]=aa[1];
	
	else if(aa[1]!=aa[2]&&aa[2]!=aa[3]){
		temp.kind[1]=0, temp.val[1]=aa[3];
	}
	
	else{
		temp.kind[1]=1, temp.val[1]=aa[2];
	}
	
}

void deal_mid(){
	int aa[6];
	int ka[6];
	for(int i=1;i<=5;i++){
		aa[i]=temp.mid[i]%100;
		ka[i]=temp.mid[i]/100;
	}
	sort(aa+1, aa+6);
	sort(ka+1, ka+6);
	
	bool shunzi=true,tonghua=true;
	for(int i=1;i<=4;i++) if(aa[i+1]!=aa[i]+1) shunzi=false;
	for(int i=1;i<=4;i++) if(ka[i+1]!=ka[i]) tonghua=false;
	
/*	if(shunzi==true){
		cout<<"DF"<<endl;
		for(int i=1;i<=5;i++) cout<<aa[i]<<" "; cout<<endl;
	}
*/
	
	if(tonghua&&shunzi){
		temp.kind[2]=9; temp.val[2]=aa[5];
		return;
	}
	if(tonghua){
		temp.kind[2]=6; temp.val[2]=aa[5];
		return;
	}
	if(shunzi){
		temp.kind[2]=5; temp.val[2]=aa[5];
		return;
	}
	if(aa[1]==aa[4]||aa[2]==aa[5]){
		temp.kind[2]=8; temp.val[2]=aa[3];
		return;
	}
	
	
	if(aa[1]==aa[3]){
		if(aa[4]==aa[5]){
			temp.kind[2]=7; temp.val[2]=aa[1];
		}
		else{
			temp.kind[2]=4; temp.val[2]=aa[1];
		}
		return;
	}
	
	if(aa[3]==aa[5]){
		if(aa[1]==aa[2]){
			temp.kind[2]=7; temp.val[2]=aa[4];
		}
		else{
			temp.kind[2]=4; temp.val[2]=aa[4];
		}
		return;
	}
	
	if(aa[2]==aa[4]&&aa[3]==aa[4]){
		temp.kind[2]=4; 
		temp.val[2]=aa[3];
		return;
	}
	
	int cnt_pa=0;
	
	for(int i=2;i<=5;i++) if(aa[i]==aa[i-1]) cnt_pa++;
	
	if(cnt_pa==1){
		for(int i=2;i<=5;i++){
			if(aa[i]==aa[i-1]){
				temp.val[2]=aa[i];
				break;
			}
		}
		temp.kind[2]=1;
		return;
	}
	else if(cnt_pa==2){
		int xx=0,yy=0;
		for(int i=2;i<=5;i++)
		if(aa[i]==aa[i-1]){if(xx==0) xx=aa[i]; else yy=aa[i];}
		if(xx+1==yy)
			temp.kind[2]=3, temp.val[2]=yy;
			else temp.kind[2]=2,temp.val[2]=yy;
		return;
	}
	
	if(cnt_pa==0){
		temp.kind[2]=0,temp.val[2]=aa[5];
	}
	return;
}



void deal_tail(){
	int aa[6];
	int ka[6];
	for(int i=1;i<=5;i++){
		aa[i]=temp.tail[i]%100;
		ka[i]=temp.tail[i]/100;
	}
	sort(aa+1, aa+6);
	sort(ka+1, ka+6);
	
	bool shunzi=true,tonghua=true;
	for(int i=1;i<=4;i++) if(aa[i+1]!=aa[i]+1) shunzi=false;
	for(int i=1;i<=4;i++) if(ka[i+1]!=ka[i]) tonghua=false;
	if(tonghua&&shunzi){
		temp.kind[3]=9; temp.val[3]=aa[5];
		return;
	}
	if(tonghua){
		temp.kind[3]=6; temp.val[3]=aa[5];
		return;
	}
	if(shunzi){
		temp.kind[3]=6; temp.val[3]=aa[5];
		return;
	}
	if(aa[1]==aa[4]||aa[2]==aa[5]){
		temp.kind[3]=8; temp.val[3]=aa[3];
		return;
	}
	if(aa[1]==aa[3]){
		if(aa[4]==aa[5]){
			temp.kind[3]=7; temp.val[3]=aa[1];
		}
		else{
			temp.kind[3]=4; temp.val[3]=aa[1];
		}
		return;
	}
	if(aa[3]==aa[5]){
		if(aa[1]==aa[2]){
			temp.kind[3]=7; temp.val[3]=aa[4];
		}
		else{
			temp.kind[3]=4; temp.val[3]=aa[4];
		}
		return;
	}
	if(aa[2]==aa[3]&&aa[3]==aa[4]){
		temp.kind[3]=4; 
		temp.val[3]=aa[3];
		return;
	}
	int cnt_pa=0;
	for(int i=2;i<=5;i++) if(aa[i]==aa[i-1]) cnt_pa++;
	if(cnt_pa==1){
		for(int i=2;i<=5;i++){
			if(aa[i]==aa[i-1]){
				temp.val[3]=aa[i];
				break;
			}
		}
		temp.kind[3]=1;
		return;
	}
	else if(cnt_pa==2){
		int xx=0,yy=0;
		for(int i=2;i<=5;i++)
		if(aa[i]==aa[i-1]){if(xx==0) xx=aa[i]; else yy=aa[i];}
		if(xx+1==yy)
			temp.kind[3]=3, temp.val[3]=yy;
			else temp.kind[3]=2,temp.val[3]=yy;
		return;
	}
	
	
if(cnt_pa==0){
		temp.kind[3]=0,temp.val[3]=aa[5];
	}
	return;

}


void judge(int ppos){
	//	_data[pos].a[i];
	
	//getchar();
	//for(int i=1;i<=13;i++) cout<<in_card[_data[ppos].a[i]]<<" ";
	
	for(int i=1;i<=3;i++)
	temp.head[i]=in_card[_data[ppos].a[i]];
	for(int i=4;i<=8;i++)
	temp.mid[i-3]=in_card[_data[ppos].a[i]];
	for(int i=9;i<=13;i++)
	temp.tail[i-8]=in_card[_data[ppos].a[i]];
	
	
	deal_head();
	deal_mid();
	deal_tail();
	
	temp.tolval=val_type[temp.kind[1]]+val_type[temp.kind[2]]+val_type[temp.kind[3]];
	if(temp.kind[2]>=7) temp.tolval+=val_type[temp.kind[2]];//中 val*2
	
	if(temp.kind[1]<=temp.kind[2]){
		if(temp.kind[1]==temp.kind[2]){
			if(temp.val[1]>temp.val[2]) goto ending;
		}
		if(temp.kind[2]<=temp.kind[3]){
			if(temp.val[2]>temp.val[3]) goto ending;
			if(select.size()>=15){
				if(temp.tolval>select.top().tolval){
					select.pop();
					select.push(temp);
					if(temp.tolval>aans.tolval) aans=temp;
				}
			}
			else{
				select.push(temp);
				if(temp.tolval>aans.tolval) aans=temp;
			}
		}
	}
		
ending:	
	
	//getchar();
	//for(int i=1;i<=13;i++) cout<<in_card[_data[ppos].a[i]]<<" "; cout<<endl;
	//for(int i=1;i<=3;i++) cout<<temp.kind[i]<<" "; cout<<endl;
	//for(int i=1;i<=3;i++) cout<<temp.val[i]<<" "; cout<<endl;
	
	return;
}


//113 213 103 102 203 304 405 406 114 214 314 310 410

void data_in(){
	
	/*for(int i=1;i<=13;i++){ 
		cin>>in_card[i];
	}*/
	int t_flag=0;
	for(int ii=1;ii<=13;ii++){
		string xxxx;
		cin>>xxxx;
		t_flag=0;
		for(int i=1;i<=4;i++){
		for(int j=2;j<=14;j++)
		if(card[i][j].poker==xxxx){
			in_card[ii]=card[i][j].val;
			t_flag=1;
			break;
		}
		if(t_flag) break; 
		}
	}
	
}
vector<sel> vi;
int ans[50];

void cmp_all(){
	vi.clear();
	while(!select.empty()&&select.top().tolval<aans.tolval){
		select.pop();
	}
	
	while(!select.empty()){
		vi.push_back(select.top());
		select.pop();
	}
	
	int siz=vi.size();
	
	mm(ans, 0);
	int win;
	for(int i=0;i<siz;i++)
	for(int j=i+1;j<siz;j++){
		win=0;
		if(vi[i].kind[1]==vi[j].kind[1]){
			if(vi[i].val[1]!=vi[j].val[1]) {
				if(vi[i].val[1]<vi[j].val[1]) win--;
				else win++;
			}
		}
		else{
			if(vi[i].kind[1]<vi[j].kind[1]) win--;
			else win++;
		}
		int kind_pi=max(vi[i].kind[2],vi[j].kind[2]);
		if(kind_pi>=7){
			if(kind_pi==7) kind_pi=2;
			else kind_pi=(kind_pi-4)*2;
		}
		else kind_pi=1; 
		
		if(vi[i].kind[2]==vi[j].kind[2]){
			if(vi[i].val[2]!=vi[j].val[2]) {
				if(vi[i].val[2]<vi[j].val[2]) win-=kind_pi;
				else win+=kind_pi;
			}
		}
		else{
			if(vi[i].kind[2]<vi[j].kind[2]) win-=kind_pi;
			else win+=kind_pi;
		}
		kind_pi=max(vi[i].kind[3],vi[j].kind[3]);
		if(kind_pi>7){
			kind_pi=(kind_pi-4);
		}
		else kind_pi=1; 
		if(vi[i].kind[3]==vi[j].kind[3]){
			if(vi[i].val[3]!=vi[j].val[3]) {
				if(vi[i].val[3]<vi[j].val[3]) win-=kind_pi;
				else win+=kind_pi;
			}
		}
		else{
			if(vi[i].kind[3]<vi[j].kind[3]) win-=kind_pi;
			else win+=kind_pi;
		}
		
		if(win<0) ans[j]-=win;
		else ans[i]+=win;
	}
	int place_max=siz-1;
	for(int i=siz-1;i>=0;i--){
		if(vi[i].tolval!=vi[place_max].tolval) break;
		if(ans[i]>ans[place_max]) place_max=i;
	}
	temp=vi[place_max];
	
	//for(int i=1;i<=3;i++) cout<<temp.head[i]<<" "; cout<<endl;
	//for(int i=1;i<=5;i++) cout<<temp.mid[i]<<" "; cout<<endl;
	//for(int i=1;i<=5;i++) cout<<temp.tail[i]<<" "; cout<<endl;
	/*
	for(int j=0;j<siz;j++){
		temp=vi[j];
		for(int i=1;i<=3;i++)
		cout<<temp.head[i]<<" "; cout<<endl;
		for(int i=1;i<=5;i++)
		cout<<temp.mid[i]<<" "; cout<<endl;
		for(int i=1;i<=5;i++)
		cout<<temp.tail[i]<<" "; cout<<endl;
		cout<<ans[j]<<endl;

	}*/
}
void data_out(){
	/*
	magic:
	for(int j=vi.size()-1;j>=0;j--)	
	{
		if(vi[j].tolval!=vi[j-1].tolval) break;
		temp=vi[j];
	for(int i=1;i<=3;i++)
	cout<<temp.head[i]<<" "; cout<<endl;
	for(int i=1;i<=5;i++)
	cout<<temp.mid[i]<<" "; cout<<endl;
	for(int i=1;i<=5;i++)
	cout<<temp.tail[i]<<" "; cout<<endl;
	}
	*/
	
	/*
	for(int i=1;i<=3;i++)
	cout<<temp.head[i]<<" "; cout<<"\n";
	for(int i=1;i<=5;i++)
	cout<<temp.mid[i]<<" "; cout<<"\n";
	for(int i=1;i<=5;i++)
	cout<<temp.tail[i]<<" "; cout<<"\n";
	*/
	int be_pos;
	for(int i=1;i<=3;i++)
	{
		be_pos=temp.head[i]%100; if(be_pos==1) be_pos=14;
		cout<<card[int(temp.head[i]/100)][be_pos].poker<<" "; //cout<<"\n";
	}cout<<"\n";
	for(int i=1;i<=5;i++){
	//cout<<temp.mid[i]<<" ";
	be_pos=temp.mid[i]%100; if(be_pos==1) be_pos=14;
	cout<<card[int(temp.mid[i]/100)][be_pos].poker<<" "; //cout<<"\n";
	}cout<<"\n";
	for(int i=1;i<=5;i++){
	//cout<<temp.tail[i]<<" ";
	be_pos=temp.tail[i]%100; if(be_pos==1) be_pos=14;

	cout<<card[int(temp.tail[i]/100)][be_pos].poker<<" "; 
	}
	cout<<"\n";
	//cout<<"\n";
	
	
	//for(int i=1;i<=3;i++) cout<<temp.kind[i]<<" ";  cout<<endl;
}
void fun(){
	while(!select.empty()) select.pop();
	aans.tolval=0;
	data_in();
	
	//sort(in_card+1,in_card+14);
//	cout<<"x"<<endl;
	for(int i=0;i<num;i++) judge(i);
//	cout<<"y"<<endl;
	
	//cout<<select.size()<<endl;
	
	cmp_all();
	//cout<<"cend"<<endl;
	
	
	
	data_out();
	
	
}
int main(){	
	//std::ios::sync_with_stdio(false);
	
	pro_work();//	预处理出所有组合的下标情况
/*debug*/	
/*	cout<<num<<endl;
	for(int i=1;i<=num;i++){
		//getchar();
		for(int j=1;j<=13;j++)
		cout<<_data[i].a[j]<<" ";
		cout<<endl;
	}
	*/
//	freopen("temp.in","r",stdin);
	//freopen("temp.out","w",stdout);
	
	
	int cccnt=400;
	//while(cccnt--)
	fun();
	
	return 0;
}


/*113 213 103 102 203 304 405 406 114 214 314 310 410*/
//405 406 114 103 102 203 304 214 314 310 410 113 213 

/*

#8 &3 *A $5 #10 *8 &5 #2 $K #4 #Q #J *10 
&6 *4 *J *9 $K &2 $J $5 *6 #Q *3 &3 *8 
$7 &10 *5 #3 $2 &9 #2 $10 #4 #A &4 &8 #9 
&5 $9 $6 *2 &K #J *K &Q #10 #K *Q &J *10 
$A &7 *A #7 &A #8 $8 $3 #6 $Q #5 *7 $4 
&A $6 #3 *10 *9 *6 *J &K #9 $7 &10 &Q $10 
*K $4 &8 &4 $Q $5 *8 #2 &J &5 $9 $2 *Q 
$A #8 #6 #5 *4 &2 *7 *A #A #J #10 &3 &9 
#K *3 $J $K #Q $8 *2 &6 #4 &7 *5 $3 #7 
$3 *9 &3 &K $J $5 &Q *Q #K *10 #10 #9 #3 
&A $6 $K #2 *K *8 &5 $8 &4 *3 $10 *6 #5 
$9 *J *7 *5 $7 &10 &2 #6 #J &7 #4 &6 *4 
$Q #7 $2 &9 #8 #A *A $4 &J &8 *2 $A #Q 
$K $8 &A *8 #2 *10 *4 &3 $3 #J &7 $10 #K 

*/