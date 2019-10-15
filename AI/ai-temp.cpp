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
	for(int i=1;i<=13;i++) cin>>in_card[i];
	
}
vector<sel> vi;
int ans[50];

void cmp_all(){
	
	while(select.top().tolval<aans.tolval){
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
	
	
	for(int i=1;i<=3;i++)
	cout<<temp.head[i]<<" "; cout<<endl;
	for(int i=1;i<=5;i++)
	cout<<temp.mid[i]<<" "; cout<<endl;
	for(int i=1;i<=5;i++)
	cout<<temp.tail[i]<<" "; cout<<endl;
	
	//for(int i=1;i<=3;i++) cout<<temp.kind[i]<<" ";  cout<<endl;
}
void fun(){
	while(!select.empty()) select.pop();
	aans.tolval=0;
	data_in();
	
	//sort(in_card+1,in_card+14);
	
	for(int i=0;i<num;i++) judge(i);
	
	//cout<<select.size()<<endl;
	
	cmp_all();
	
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
	
	fun();
	
	return 0;
}

/*113 213 103 102 203 304 405 406 114 214 314 310 410*/
//405 406 114 103 102 203 304 214 314 310 410 113 213 