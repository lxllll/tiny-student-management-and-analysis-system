//  Created by 孙宇航 on 2020/3/11.

//  Copyright © 2020 孙宇航. All rights reserved.


#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int sum=0,i,j,b;
char c;
void shuoming();
void syzxx();
void glydl();
void zhuce();
void denglu();
void glcaidan();
void luru();
void chakan();
void xiugai();
void shanchu();
void zengjia();
void gai();
void ykcaidan();
void cxxx();
void dp();
void tp(); 
void sousuo();
void hbhao();
void qszhan();
void zdzhan();
void main(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	printf("\t\t\t\t\t****************************************\n\n");
	SetConsoleTextAttribute(color,FOREGROUND_INTENSITY|FOREGROUND_RED);
	printf("\t\t\t\t\t\t    欢迎使用订票系统\n\n");
	SetConsoleTextAttribute(color,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	printf("\t\t\t\t\t****************************************\n\n\n\n\n");
	SetConsoleTextAttribute(color,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
	syzxx();
}
void syzxx(int a){
	printf("\t\t\t\t\t***************使用者选项***************\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【01】管理员使用\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【02】顾客使用\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【03】程序说明\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【00】退出程序\n\n");
	Sleep(100);
	printf("\t\t\t\t\t***************使用者选项***************\n\n\n\n\n");
	Sleep(300);
	printf("请输入选项(对应菜单序号):");
	scanf("%d",&a);
	switch(a){
	case 1:
		{
			system("cls");
			glydl();
			break;
		}

	case 2:
		{
			printf("正在加载程序.....");
			Sleep(5000);
			system("cls");
			ykcaidan();
			break;
		}
	case 3:
		{
			system("cls");
			shuoming();
		}
	case 0:exit(0);break;
	default:
		{
			printf("没有该选项,请重新输入!");
			system("pause");
			syzxx();
			break;
		}
	}
}
void glydl(int a){
	printf("\t\t\t\t\t*************管理员登陆选项*************\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【01】管理员注册\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【02】管理员登陆\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【03】使用者选项\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【00】退出程序\n\n");
	Sleep(100);
	printf("\t\t\t\t\t*************管理员登陆选项*************\n\n\n\n\n");
	Sleep(300);
	printf("请输入选项(对应菜单序号):");
	scanf("%d",&a);
	switch(a){
	case 1:
		{	
			scanf("%c",&c);
			zhuce();
			break;
		}
	case 2:
		{
			scanf("%c",&c);
			denglu();
			break;
		}
	case 3:
		{
			scanf("%c",&c);
			system("cls");
			syzxx();
			break;

		}
	case 0:exit(0);break;
	default:
		{
			printf("没有该选项,请重新输入!");
			system("pause");
			scanf("%c",&c);
			glydl();
			break;
		}
	}
}
void zhuce(char c,char g){
	FILE *yh,*mm;
	char a[100],b[100];
	printf("*****************************注册界面******************************\n\n");
	yh=fopen("用户注册.dat","w");
	mm=fopen("用户密码.dat","w");
	printf("请输入你所要注册的用户名:");
	gets(a);
	fputs(a,yh);
	fclose(yh);
	printf("请输入你所要注册用的密码:");
	gets(b);
	fputs(b,mm);
	fclose(mm);
	printf("注册完毕!是否选择登陆(Y/N):");
	scanf("%c",&c);
	scanf("%c",&g);
	if(c=='y'||c=='Y')
		denglu();
	else system("pause");
}
void denglu(){
	FILE *p,*q;
	char yh[100];
	char mm[100];
	char c[100],d[100],e,f,g;
	if((p=fopen("用户注册.dat","r"))==NULL){
		printf("你还未注册!\n");
		printf("是否注册管理员(Y/N):");
		scanf("%c",&g);
		if(g=='y'||g=='Y'){
			system("cls");
			glydl();
		}
		else {
			system("pause");
			exit(0);
		}
	}
	if((q=fopen("用户密码.dat","r"))==NULL){
		printf("你还未注册!\n");
		printf("是否注册管理员(Y/N):");
		scanf("%c",&c);
		if(c=='y'||c=='Y'){
			system("cls");
			glydl();
		}
		else {
			system("pause");
			exit(0);
		}
	}
	fgets(yh,strlen(yh),p);
	fclose(p);
	fgets(mm,strlen(mm)-1,q);
	fclose(q);
	printf("*****************************登陆界面******************************\n\n");
	if(sum==3){
		printf("错误次数超过三次,是否找回用户名和密码(Y/N):");
		scanf("%c",&e);
		scanf("%c",&f);
		if(e=='y'||e=='Y'){
			printf("正在等待审核中....\n");
			Sleep(10000);
			printf("登陆用户名为:%s\n",yh);
			printf("登陆密码为:%s\n",mm);
			sum=0;
			denglu();
		}
		else system("pause");
	}
	printf("请输入用户名:");
	gets(c);
	printf("请输入密码:");
	gets(d);
	for(i=0;i<strlen(yh);i++){
		if(c[i]==yh[i])continue;
		else {
			printf("用户名错误,返回登陆界面!\n");
			sum++;
			denglu();
		}
	}
	for(j=0;j<strlen(mm);j++){
		if(d[j]==mm[j])continue;
		else {
			printf("密码错误,返回登陆界面!\n");
			sum++;
			denglu();
		}
	}
	if(i==strlen(yh)&&j==strlen(mm)){
		if(strlen(c)==strlen(yh)&&strlen(d)==strlen(mm)){
			printf("登陆成功!\n");
			printf("正在加载程序.....");
			Sleep(5000);
			system("cls");
			glcaidan();
		}
		else if(strlen(c)>strlen(yh)){
			printf("用户名错误,返回登陆界面!\n");
			sum++;
			denglu();
		}
		else if(strlen(d)>strlen(mm)){
			printf("密码错误,返回登陆界面!\n");
			sum++;
			denglu();
		}
	}
}
void glcaidan(int a,char c){
	printf("\t\t\t\t\t******************管理员菜单******************\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【01】录入航班信息\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【02】查看航班信息\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【03】修改航班内容\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【04】返回使用者选项\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【00】退出程序\n\n");
	Sleep(100);
	printf("\t\t\t\t\t******************管理员菜单******************\n\n\n\n\n");
	Sleep(300);
	printf("请输入选项(对应菜单序号):");
	scanf("%d",&a);
	switch(a){
	case 1:
		{	scanf("%c",&c);
			luru();
			break;
		}
	case 2:
		{	
			scanf("%c",&c);
			chakan();
			break;
		}
	case 3:
		{	
			scanf("%c",&c);
			system("cls");
			xiugai();
			break;
		}
	case 4:

		{

			scanf("%c",&c);

			system("cls");

			syzxx();

			break;

		}

	case 0:exit(0);break;
	default:
		{
			printf("没有该选项,请重新输入!");
			system("pause");
			scanf("%c",&c);
			glcaidan();
			break;
		}
	}
}

void xiugai(int a)

{
	printf("\t\t\t\t\t****************修改航班信息****************\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【01】增加航班信息\n\n");
	Sleep(100);
	printf("\t\t\t\t\t\t  【02】删除航班信息\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【03】修改航班信息\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【04】返回管理员选项\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【00】退出程序\n\n");

	Sleep(100);

	printf("\t\t\t\t\t****************修改航班信息****************\n\n\n\n\n");

	Sleep(300);

	printf("请输入选项(对应菜单序号):");

	scanf("%d",&a);

	switch(a)

	{

	case 1:

		{

			scanf("%c",&c);

		 	zengjia();

			break;

		}

	case 2:

		{

			scanf("%c",&c);

			shanchu();

			break;

		}

	case 3:

		{

			scanf("%c",&c);

			gai();

			break;

		}

	case 4:

		{

			scanf("%c",&c);

			system("cls");

			glcaidan();

			break;

		}

	case 0:exit(0);break;

	default:

		{

			printf("没有此选项,请重新选择!");

			system("pause");

			system("cls");

			xiugai();

		}

	}

}



void ykcaidan(int a,char c)

{

	printf("\t\t\t\t\t****************顾客菜单****************\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【01】查询航班信息\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【02】搜索\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【03】订票\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【04】退票\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【05】返回使用者选项\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【00】退出程序\n\n");

	Sleep(100);

	printf("\t\t\t\t\t****************顾客菜单****************\n\n\n\n\n");

	Sleep(300);

	printf("请输入选项(对应菜单序号):");

	scanf("%d",&a);

	switch(a)

	{

	case 1:cxxx();break;

	case 2:

	{

		system("cls");

		sousuo();

		break;

	}

	case 3:dp();break;

	case 4:tp();break;

	case 5:

		{

			system("cls");

			syzxx();

			break;

		}

	case 0:exit(0);break;

	default:

		{

			scanf("%c",&c);

			printf("没有该选项,请重新输入!");

			system("pause");

			ykcaidan();

			break;

		}

	}

}



void luru(char c)

{

	FILE *p;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r+"))!=NULL)

	{

		fread(&hangban[0],sizeof(struct hb),1,p);

		if(hangban[0].number==0)

		{

			printf("航班信息为空,请录入航班信息!\n");

			fclose(p);

			system("pause");

		}

		else

		{

			printf("已有航班信息,是否重新录入(Y/N):\n");

			scanf("%c",&c);

			if(c=='y'||c=='Y');

			else 

			{

				system("cls");

				glcaidan();

			}

		}

	}

	p=fopen("航班信息.dat","w");

	for(i=0;i<=99;i++)

	{

		printf("请录入航班号(数字)、起始站、终点站、登机时间、机票数(每个数据间用空格隔开):\n");

		scanf("%d%s%s%s%d",&hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,&hangban[i].tickey);

		hangban[i].xuhao=i+1;

		fwrite(&hangban[i],sizeof(struct hb),1,p);

		printf("是否继续录入(Y/N):");

		scanf(" %c",&c);

		if(c=='y'||c=='Y')continue;

		else 

		{

			system("cls");

			fclose(p);

			glcaidan();

		}

	}

}



void chakan(char c)

{

	FILE *p;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r"))==NULL)

	{

		printf("没有该文件,是否录入信息进该文件(Y/N):");

		scanf("%c",&c);

		if(c=='y'||c=='Y')luru();

		else 

		{

			system("cls");

			glcaidan();

		}

	}

	p=fopen("航班信息.dat","r+");

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	fclose(p);

	printf("\n\n");

	printf("是否返回管理员菜单(Y/N):");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')

	{

		system("cls");

		glcaidan();

	}

	else 

	{

		printf("即将退出程序!\n");

		system("pause");

		exit(0);

	}

}



void shanchu()

{

	FILE *p;

	int sign=-1;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r+"))==NULL)

	{

		printf("没有找到录入文件,是否录入航班信息(Y/N):");

		scanf("%c",&c);

		if(c=='y'||c=='Y')luru();

		else 

		{

			system("cls");

			fclose(p);

			glcaidan();

		}

	}

	p=fopen("航班信息.dat","r+");

	fread(&hangban[0],sizeof(struct hb),1,p);

	if(hangban[0].number==0)

	{

		printf("没有航班信息,无需修改!\n");

		printf("是否录入航班信息(Y/N):\n");

		scanf("%c",&c);

		if(c=='y'||c=='Y')luru();

		else 

		{

			system("cls");

			fclose(p);

			xiugai();

		}

	}

	fclose(p);

	p=fopen("航班信息.dat","r+");

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	fclose(p);

	printf("请输入要删除的航班信息(输入航班号):");

	scanf("%d",&j);

	p=fopen("航班信息.dat","r+");

	for(b=0;b<=99;b++)

	{

		fread(&hangban[b],sizeof(struct hb),1,p);

		if(hangban[b].number==0)break;

	}

	fclose(p);

	p=fopen("航班信息.dat","r+");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(j==hangban[i].number)

		{

			fseek(p,sign*sizeof(struct hb),1);

			for(j=i+1;j<=b;j++)

			{

				fwrite(&hangban[j],sizeof(struct hb),1,p);

			}

			fclose(p);

			break;

		}

		else if(i==99)

		{

			printf("航班信息中没有对应的航班号,请重新选择!\n\n");

			shanchu();

		}

	}

	printf("删除完毕,是否查看航班信息(Y/N):\n");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')chakan();

	else 

	{

		system("cls");

		xiugai();

	}

}



void zengjia()

{

	FILE *p;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","rb+"))==NULL)

	{

		printf("没有找到录入文件,是否录入航班信息(Y/N):");

		scanf("%c",&c);

		if(c=='y'||c=='Y')luru();

		else 

		{

			system("cls");

			xiugai();

		}

	}

	p=fopen("航班信息.dat","r+");

	fread(&hangban[0],sizeof(struct hb),1,p);

	if(hangban[0].number==0)

	{

		printf("没有航班信息,无需修改!\n");

		printf("是否增添航班信息(Y/N):\n");

		scanf("%c",&c);

		if(c=='y'||c=='Y');

		else 

		{

			system("cls");

			xiugai();

		}

	}

	fclose(p);

	p=fopen("航班信息.dat","r+");

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	printf("请添加新的航班号(数字)、起始站、终点站、登机时间、机票数(每个数据间空格隔开):\n");

	scanf("%d%s%s%s%d",&hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,&hangban[i].tickey);

	hangban[i].xuhao=i+1;

	fseek(p,(hangban[i].xuhao-1)*sizeof(struct hb),0);

	fwrite(&hangban[i],sizeof(struct hb),1,p);

	fclose(p);

	printf("增添完毕,是否查看航班信息(Y/N):\n");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')chakan();

	else 

	{

		system("cls");

		xiugai();

	}

}

	

void gai(char c)

{

	FILE *p;

	int sign=-1;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r+"))==NULL)

	{

		printf("没有找到录入文件,是否录入航班信息(Y/N):");

		scanf("%c",&c);

		if(c=='y'||c=='Y')luru();

		else 

		{

			system("cls");

			fclose(p);

			xiugai();

		}

	}

	p=fopen("航班信息.dat","r+");

	fread(&hangban[0],sizeof(struct hb),1,p);

	if(hangban[0].number==0)

	{

		printf("没有航班信息,无需修改!\n");

		printf("是否录入航班信息(Y/N):\n");

		scanf("%c",&c);

		if(c=='y'||c=='Y')luru();

		else 

		{

			system("cls");

			xiugai();

		}

	}

	fclose(p);

	p=fopen("航班信息.dat","r+");

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	fclose(p);

	printf("请输入要修改的航班(输入航班号):");

	scanf("%d",&j);

	p=fopen("航班信息.dat","r+");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(j==hangban[i].number)break;

		else if(i==99)

		{

			printf("航班信息中没有对应的航班号,请重新选择!\n");

			xiugai();

		}

	}

	fseek(p,sign*sizeof(struct hb),1);

	printf("请重新录入该行内容(航班号、起始站、终点站、登机时间、票数,各数据间用空格隔开):\n");

	scanf("%d%s%s%s%d",&hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,&hangban[i].tickey);

	fwrite(&hangban[i],sizeof(struct hb),1,p);

	fclose(p);

	printf("修改完毕,是否查看航班信息(Y/N):\n");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')chakan();

	else 

	{

		system("cls");

		xiugai();

	}

}



void cxxx(char c)

{

	FILE *p;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r"))==NULL)

	{

		printf("目前还未有航班信息,即将退出程序!\n");

		system("pause");

		exit(0);

	}

	p=fopen("航班信息.dat","r+");

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=100;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	fclose(p);

	printf("\n\n");

	printf("是否返回顾客菜单(Y/N):");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')

	{

		system("cls");

		ykcaidan();

	}

	else

	{

		printf("即将退出程序!\n");

		system("pause");

		exit(0);

	}

}



void dp(int a,char c)

{

	FILE *p;

	int sign=-1;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r+"))==NULL)

	{

		printf("目前还未有航班信息,即将返回顾客界面!\n");

		system("pause");

		ykcaidan();

		exit(0);

	}

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=100;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	fclose(p);

	p=fopen("航班信息.dat","r+");

	printf("请选择你订票所对应的航班号:");

	scanf("%d",&a);

	printf("\n\n");

	for(i=0;i<=99;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(a==hangban[i].number)break;

		else if(i==99||a==0)

		{

			printf("航班信息中没有对应的航班号,请重新订票!\n");

			dp();

		}

	}

	printf("付款方式:【01】支付宝\n         【02】微信\n         【03】银行卡\n         【00】取消付款\n\n");

	printf("请选择:");

	scanf("%d",&a);

	switch(a)

	{

	case 1:

		{

			printf("正在付款中.....\n");

			Sleep(3000);

			printf("使用支付宝付款成功!\n");

			break;

		}

	case 2:

		{

			printf("正在付款中.....\n");

			Sleep(3000);

			printf("使用微信付款成功!\n");

			break;

		}

	case 3:

		{

			printf("正在付款中.....\n");

			Sleep(3000);

			printf("使用银行卡付款成功!\n");

			break;

		}

	case 0:

		{

			printf("取消付款,是否返回顾客菜单(Y/N):\n");

			scanf("%c",&c);

			if(c=='y'||c=='Y')ykcaidan();

			else

			{

				printf("即将退出程序!\n");

				system("pause");

				exit(0);

			}

		}

	default:

		{

			printf("没有该付款方式,订单取消!\n");

			system("pause");

			dp();

		}

	}		

	hangban[i].tickey-=1;

	fseek(p,sign*sizeof(struct hb),1);

	fwrite(&hangban[i],sizeof(struct hb),1,p);

	fclose(p);

	printf("订票完毕,是否返回菜单(Y/N):");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')

	{

		system("cls");

		ykcaidan();

	}

	else 

	{

		printf("即将退出程序!\n");

		system("pause");

		exit(0);

	}

}



void tp(int a,char c)

{

	FILE *p;

	int sign=-1;

	struct hb

	{

		int number;

		char start[20];

		char end[20];

		char time[30];

		int tickey;

		int xuhao;

	}hangban[100]={0};

	if((p=fopen("航班信息.dat","r+"))==NULL)

	{

		printf("目前还未有航班信息,即将返回顾客界面!\n");

		system("pause");

		ykcaidan();

		exit(0);

	}

	printf("**************************航班信息**************************\n\n");

	for(i=0;i<=100;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(hangban[i].number==0)break;

		printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);

	}

	printf("**************************航班信息**************************\n\n");

	fclose(p);

	p=fopen("航班信息.dat","r+");

	printf("请选择你退票所对应的航班号:");

	scanf("%d",&a);

	for(i=0;i<=9;i++)

	{

		fread(&hangban[i],sizeof(struct hb),1,p);

		if(a==hangban[i].number)break;

		else if(i==99)

		{

			printf("航班信息中没有对应的航班号,请重新订票!\n");

			tp();

		}

	}

	++hangban[i].tickey;

	fseek(p,sign*sizeof(struct hb),1);

	fwrite(&hangban[i],sizeof(struct hb),1,p);

	fclose(p);

	printf("正在退票中.....\n");

	Sleep(3000);

	fclose(p);

	printf("退票完毕,退款将在至多15天内返还到你的银行卡内!\n");

	printf("是否返回菜单(Y/N)");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')

	{

		system("cls");

		ykcaidan();

	}

	else 

	{

		printf("即将退出程序!\n");

		system("pause");

		exit(0);

	}

}



void shuoming()

{

	printf("\t\t************************************程序说明************************************\n\n");

	Sleep(100);

	printf("\t\t\t   【1】请注意输入条件,不满足输入条件输入可能会导致程序崩溃!\n\n");

	Sleep(100);

	printf("\t\t\t   【2】航班信息的录入需要通过管理员登陆才能够进行(航班号不大于50000)\n\n");

	Sleep(100);

	printf("\t\t\t   【3】在使用顾客选项时,如果没有航班信息,选择任意选项都会退出程序!\n\n\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t\t\t\t     程序员:温子旋\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t\t\t\t     仅供参考,切勿抄袭!\n\n");

	Sleep(100);

	printf("\t\t************************************程序说明************************************\n\n\n\n\n");

	Sleep(300);

	printf("是否返回使用者选项界面(Y/N):");

	scanf(" %c",&c);

	if(c=='y'||c=='Y')

	{

		system("cls");

		syzxx();

	}

	else

	{

		printf("即将退出程序!\n");

		system("pause");

		exit(0);

	}

}



void sousuo(int a,char d[20])

{

	printf("\t\t\t\t\t******************搜索******************\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【01】航班号\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【02】起始站\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【03】终点站\n\n");

	Sleep(100);

	printf("\t\t\t\t\t\t  【00】返回顾客界面\n\n");

	Sleep(100);

	printf("\t\t\t\t\t****************************************\n\n\n\n\n");

	Sleep(300);

	printf("请选择搜索方式:");

	scanf("%d",&a);

	switch(a)

	{

	case 1:hbhao();break;

	case 2:qszhan();break;

	case 3:zdzhan();break;

	case 0:

		{

			system("cls");

			ykcaidan();

			break;

		}
	default:{
			printf("没有此选项,请重新选择!");
			gets(d);
			system("pause");
			system("cls");
			sousuo();
		}
	}
}
void hbhao(int a){
	FILE *p;
	struct hb{
		int number;
		char start[20];
		char end[20];
		char time[30];
		int tickey;
		int xuhao;
	}hangban[100]={0};
	if((p=fopen("航班信息.dat","r"))==NULL){
		printf("目前还未有航班信息,即将退出程序!\n");
		system("pause");
		exit(0);
	}
	p=fopen("航班信息.dat","r+");
	printf("请输入要找的航班号:");
	scanf("%d",&a);
	printf("\n");
	printf("**************************航班信息**************************\n\n");
	for(i=0;i<=99;i++){
		fread(&hangban[i],sizeof(struct hb),1,p);
		if(a==hangban[i].number){
			printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);
			printf("已列出所有搜索结果,是否返回搜索界面(Y/N):");
			scanf(" %c",&c);
			if(c=='y'||c=='Y'){
				fclose(p);
				system("cls");
				sousuo();
			}
			else{
				printf("即将退出程序!\n");
				system("pause");
				exit(0);
			}
		}
		else if(i==99){
			printf("已列出所有搜索结果,是否返回搜索界面(Y/N):");
			scanf(" %c",&c);
			if(c=='y'||c=='Y'){
				fclose(p);
				system("cls");
				sousuo();
			}
			else{
				printf("即将退出程序!\n");
				system("pause");
				exit(0);
			}
		}
	}
}

void qszhan(char a[20]){
	FILE *p;
	struct hb{
		int number;
		char start[20];
		char end[20];
		char time[30];
		int tickey;
		int xuhao;
	}hangban[100]={0};
	if((p=fopen("航班信息.dat","r"))==NULL)	{
		printf("目前还未有航班信息,即将退出程序!\n");
		system("pause");
		exit(0);
	}
	p=fopen("航班信息.dat","r+");
	printf("请输入要找的起始站:");
	scanf("%c",&c);
	gets(a);
	printf("\n");
	printf("**************************航班信息**************************\n\n");
	for(i=0;i<=99;i++){
		fread(&hangban[i],sizeof(struct hb),1,p);
		if(hangban[i].number==0){
			printf("已列出所有搜索结果,是否返回搜索界面(Y/N):");
			scanf("%c",&c);
			if(c=='y'||c=='Y'){
				fclose(p);
				system("cls");
				sousuo();
			}
			else{
				printf("即将退出程序!\n");
				system("pause");
				fclose(p);
				exit(0);
			}
		}
		for(j=0;j<20;j++)
		{
			if(a[j]==hangban[i].start[j]&&strlen(a)==strlen(hangban[i].start))
			{
				if(j==strlen(hangban[i].start)-1){
					printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);
					break;
				}
			}
		}
	}
}
void zdzhan(char a[20]){
	FILE *p;
	struct hb
	{
		int number;
		char start[20];
		char end[20];
		char time[30];
		int tickey;
		int xuhao;
	}hangban[100]={0};
	if((p=fopen("航班信息.dat","r"))==NULL){
		printf("目前还未有航班信息,即将退出程序!\n");
		system("pause");
		exit(0);
	}
	p=fopen("航班信息.dat","r+");
	printf("请输入要找的终点站:");
	scanf("%c",&c);
	gets(a);
	printf("\n");
	printf("**************************航班信息**************************\n\n");
	for(i=0;i<=99;i++){
		fread(&hangban[i],sizeof(struct hb),1,p);
		if(hangban[i].number==0){
			printf("已列出所有搜索结果,是否返回搜索界面(Y/N):");
			scanf("%c",&c);
			if(c=='y'||c=='Y'){
				fclose(p);
				system("cls");
				sousuo();
			}
			else{
				printf("即将退出程序!\n");
				system("pause");
				fclose(p);
				exit(0);
			}
		}
		for(j=0;j<20;j++){
			if(a[j]==hangban[i].end[j]&&strlen(a)==strlen(hangban[i].end)){
				if(j==strlen(hangban[i].end)-1){
					printf("%d:航班号:%5d 起始站:%5s 终点站:%5s 登机时间:%5s 机票数:%5d\n\n",i+1,hangban[i].number,hangban[i].start,hangban[i].end,hangban[i].time,hangban[i].tickey);
					break;
				}
			}
		}
	}
}
