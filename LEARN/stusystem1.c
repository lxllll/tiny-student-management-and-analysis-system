//zhihu

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#define time 10
struct student 
{
    char number[11];
	char name[10];
    int age;
	char sex[5];
    int score;
};
typedef struct student student;
char putout[5][12]={"学号","姓名","年龄","性别","成绩"};
int count=0;

//--------------------------------------------函数申明

int menu();
void create();
void add();
void show();
void de();
void correct();
int judge();
void del();
void search();
void about();
void cls();
void close();
void window(char *message);
void recreate();
void clss();
void prepare();
int compg(const void *s1,const void *s2);
int comph(const void *s1,const void *s2);
int compi(const void *s1,const void *s2);
void sort(int);
void help();

//---------------------------------------------主函数

int main()
{
	int choice;
	puts("\t\t\t 欢迎使用学生信息管理系统");
	puts("\t\t\n\n------初次使用请您务必先阅读帮助信息");
	while(1)
		switch(choice=menu())
		{
			case 0:create();break;	
			case 1:add();break;
			case 2:search();break;	
			case 3:correct();break;	
			case 4:del();break;	
			case 5:show();break;	
			case 6:recreate();break;
			case 7:help();break;
			case 8:close();break;
			case 9:about();break;
		}
	return 0; 
}

//-----------------------------------------------菜单选项

int menu()
{
	prepare();
	char choice,temp='\0';
	puts("");
	puts("-----功能菜单");
	puts("");
	puts("         --------------------------    -------------------------");
	puts("           *   0.创建学生信息           *  1.增加学生信息       ");
	puts("           *   2.查询学生信息           *  3.修改学生信息       ");
	puts("           *   4.删除学生信息           *  5.展示当前学生信息   ");
	puts("           *   6.重建学生信息           *  7.帮助               ");
	puts("           *   8.退出系统               *  9.关于               ");
	puts("         --------------------------    -------------------------");
	printf("\n     请选择菜单编号:");
	
	do{
		fflush(stdin);
		choice=getchar()-48;
		temp=getchar();
		fflush(stdin);
			if(temp!='\0'&&temp!='\n')
			{
				printf("输入有误,请重新输入:");
				continue;
			}
		if(choice<=9&&choice>=0)
			break;
	}while(1);
	return choice;
}

//-----------------------------------------创建学生信息

void create()
{
	FILE *fp=NULL;
	char temp;
	if(judge()==1||judge()==2)
	{
		cls();
		printf("\n\n\n------已经存在学生信息,是否重新创建并覆盖？\n\n输入y创建,其他值取消创建并返回:");
		fflush(stdin);
		scanf("%c",&temp);
		if(temp=='y'||temp=='Y')
			cls();
		else 
		{
			cls();
			printf("\n\n\n------已取消创建.\n\n");
			return;
		}
	}
	fp=fopen("C:\\Student.txt","wb");
	if(fp==NULL)
		puts("\n\n\n------创建学生信息失败!");
	else
	{
		cls();
		puts("\n\n\n------创建成功!");	
	}
	fclose(fp);
}

//-----------------------------------------增加学生信息

void add()
{
	int i=0,flag=0;
	char t='y',q=(char)NULL;
	student temp,studentArray[100];
	FILE *fp=NULL;

	if(judge()==0)
	{
		cls();
		fflush(stdin);
		printf("\n\n\n------还没有建立学生信息哦\n");
		printf("\n\n是否创建学生信息并添加？输入y继续,其他值返回:");	
		scanf("%c",&q);
		if(q=='y'||q=='Y')
		{
			create();
			if(judge()!=0)
				add();
			else 
			{
				printf("\n********未知异常情况,操作无效.\n");
				return;
			}
		}
		else 
		{
			cls();
			puts("\n\n\n------已取消创建！");
			return;
		}
	}

	fp=fopen("C:\\Student.txt","a+");
	if(fp==NULL)
	{
		printf("\n********未知异常情况,操作无效.\n");
		return;
	}
	cls();
	printf("\n\n学生的信息分别为学号,姓名,年龄,性别,成绩\n输入时各项之间用空格隔开,回车结束.示例:2013041678 zhangsan 18 boy 60\n");
	while(t=='y'||t=='Y')
	{
		flag=0;
		rewind(fp);
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++)
			count=i+1;//--------------------------------------------------------------------------获取现有人数----------------------------
		fflush(stdin);
		printf("请输入学生的信息:");
		scanf("%s%s%d%s%d",temp.number,temp.name,&temp.age,temp.sex,&temp.score);
		for(i=0;i<count;i++)//==============================================================================================================
		{
			if(strcmp(studentArray[i].number,temp.number)==0)
			{
				flag=1;
				puts("\n\n------该生已经存在,请勿重复添加.\n");
				break;
			}
		}
		if(flag==0)
		{
			fwrite(&temp,sizeof(struct student),1,fp);
			fflush(fp);
			count=++i;//============================================================================================================================================
		}	
		fflush(stdin);
		printf("如需继续添加其他学生信息请输入y,其他值退出:");
		scanf("%c",&t);
	}
	fclose(fp);
	cls();
	puts("\n\n\n------已成功更新所有学生信息.");
	return;
}

//------------------------------------------查询学生信息

void search()
{
	char t='y';
	FILE *fp=NULL;
	student studentArray[100];
	cls();
	while(t=='y'||t=='Y')
	{
		int i;
		int a=-1;
		char temp[10];
		if(judge()!=2)
		{
			if(judge()==1)
			{
				char *p="已创建学生信息,但没有任何数据.";
				window(p);
				return;
			}
			else
			{
				char *p="还没有创建学生信息.";
				window(p);
				return;
			}
		}
		fp=fopen("C:\\Student.txt","rb");
		if(fp==NULL)
		{
			printf("\n****<查询>****未知异常情况,操作无效.\n");
			return;
		}
		fflush(stdin);
		printf("\n\n请输入要查询的学生的学号或者姓名:");	
		scanf("%s",temp);
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++)
			count=i+1;//=============================================================================================================================================
		for(i=0;i<count;i++)//=======================================================================================================================================
		{
			if(strcmp(studentArray[i].name,temp)==0||strcmp(studentArray[i].number,temp)==0)
			{
				a=i;
				printf("该生信息如下:\n\n");
				puts("\t   学号     姓名     年龄  性别  成绩");
				printf("\t%-12s%-10s%-5d%-7s%-3d\n",studentArray[a].number,studentArray[a].name,studentArray[a].age,studentArray[a].sex,studentArray[a].score);
				break;
			}
		}
		if(a==-1)
			puts("\n\n------没有找到该学生.\n");	
		fflush(stdin);	
		printf("\n如您想查询其他学生信息,请输入y,其他键退出:");
		scanf("%c",&t);
	}
	cls();
}

//----------------------------------------修改学生信息
void correct()
{
	FILE *fp=NULL;
	char t='y';
	student studentArray[100];
	cls();
	while(t=='y'||t=='Y')
	{
		FILE *fp1;
		int i,a=-1;
		char e,temp[10];
		student cor;

		if(judge()!=2)
		{
			char *p="没有学生信息可以修改.";
			window(p);
			return;
		}
		fp1=fopen("C:\\test.txt","wb");
		if(fp1==NULL)
		{
			char *p="获取访问权限失败,请稍后再次尝试.";
			window(p);	
			return;
		}
		fp=fopen("C:\\Student.txt","rb");
		if(fp==NULL)
		{
			printf("********<修改>****未知情况");
			return;
		}
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++);//==============================================================
			count=i;//======================================================================================================================
		fflush(stdin);
		printf("\n\n请输入要修改的学生的学号或者姓名:");
		scanf("%s",temp);
		for(i=0;i<count;i++)//==============================================================================================================
		{
			if(strcmp(studentArray[i].name,temp)==0||strcmp(studentArray[i].number,temp)==0)
				a=i;
		}
		if(a==-1)
		{
			fflush(stdin);
			printf("\n------没有找到该学生.是否添加？\n输入y确认添加,其他键退出:");
		    scanf("%c",&e);
			if(e=='y'||e=='Y')
			{
				add();
				return;
			}
			else
			{
				cls();
				printf("\n\n------已取消操作\n");
				return;
			}
		}
		rewind(fp);
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++)//============================================================
		{
			if(!strcmp(studentArray[i].number,temp)||!strcmp(studentArray[i].name,temp))
			{
				printf("\n将要要修改的学生信息:\n\n");
				puts("\t   学号     姓名     年龄  性别  成绩");
				printf("\t%-12s%-10s%-5d%-7s%-3d\n",studentArray[i].number,studentArray[i].name,studentArray[i].age,studentArray[i].sex,studentArray[i].score);
				fflush(stdin);
				printf("\n请输入该学生的真实信息，依次为学号,姓名,年龄,性别,成绩\n中间用空格隔开,回车结束示例:2013041678 zhangsan 18 boy 60\n");
				scanf("%s%s%d%s%d",cor.number,cor.name,&cor.age,cor.sex,&cor.score);
				fwrite(&cor,sizeof(struct student),1,fp1);
			}
			else
				fwrite(&studentArray[i],sizeof(struct student),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		fp=fopen("C:\\Student.txt","wb");
		fp1=fopen("C:\\test.txt","rb");
		if(fp==NULL||fp1==NULL)
		{
			printf("*****************未知错误****");
			return;
		}
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp1)==1;i++)
			fwrite(&studentArray[i],sizeof(struct student),1,fp);
		printf("\n");
		fclose(fp);
		fclose(fp1);
		if(remove("C:\\test.txt")!=0)
		{
			printf("***************缓存文件移除失败********");
			return;
		}
		fflush(stdin);
		printf("已成功修改该学生信息,输入y继续修改其他学生信息,其他键退出:");
		scanf("%c",&t);
	}
	cls();
}


//---------------------------------------------删除学生信息
void del()
{	
	FILE *fp=NULL;
	char q,t='y';
	student studentArray[100];
	while(t=='y'||t=='Y')
	{
		FILE *fp1;
		int i;
		int a=-1;
		char temp[10];
		if(judge()!=2)
		{
			char *p="没有学生信息可以删除.";
			window(p);
			return;
		}
		fp1=fopen("C:\\test.txt","wb");
		if(fp1==NULL)
		{
			char *p="获取访问权限失败,请稍后再次尝试.";
			window(p);
			return;
		}
		fp=fopen("C:\\Student.txt","rb");
		if(fp==NULL)
		{
			printf("************未知情况*******");
			return;
		}
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++);//==============================================================
				count=i;//==================================================================================================================
		fflush(stdin);
		cls();
		printf("\n\n输入要删除的学生的学号或者姓名:");
		scanf("%s",temp);
		for(i=0;i<count;i++)//==============================================================================================================
		{
			if(strcmp(studentArray[i].name,temp)==0||strcmp(studentArray[i].number,temp)==0)
				a=i;
		}
		if(a==-1)
		{
			char *p="没有找到该学生.";
			window(p);
			return;
		}
		rewind(fp);
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++)//===============================================================
		{
			if(!strcmp(studentArray[i].number,temp)||!strcmp(studentArray[i].name,temp))
			{
				printf("将要删除的学生信息:\n\n");
				puts("\t   学号     姓名     年龄  性别  成绩");
				printf("\t%-12s%-10s%-5d%-7s%-3d\n",studentArray[i].number,studentArray[i].name,studentArray[i].age,studentArray[i].sex,studentArray[i].score);
				fflush(stdin);
				printf("\n确定删除请输入y,其他键取消:");
				scanf("%c",&q);
				if(q=='y'||q=='Y')
				{
					//cls();
					printf("\n\n------已删除该生信息.");
				}
				else
				{ 
					//cls();
					printf("\n\n------已取消该操作。");
					fwrite(&studentArray[i],sizeof(struct student),1,fp1);
					continue;
				}
			}
			else
				fwrite(&studentArray[i],sizeof(struct student),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		fp=fopen("C:\\Student.txt","wb");
		fp1=fopen("C:\\test.txt","rb");
		if(fp==NULL||fp1==NULL)
		{
			printf("******未知错误*****");
			return;
		}
		for(i=0;fread(&studentArray[i],sizeof(struct student),1,fp1)==1;i++)
			fwrite(&studentArray[i],sizeof(struct student),1,fp);
		printf("\n\n");
		fclose(fp);
		fclose(fp1);
		fflush(stdin);
		printf("如您想删除其他学生信息,请输入y,其他键退出:");
		scanf("%c",&t);
	}
}

//-----------------------------------展示已有学生信息

void show()
{
	FILE *fp=NULL;
	char g='\0';
	if(judge()!=2)
	{
		char *p="没有学生信息.";
		window(p);
		return;
	}
	fp=fopen("C:\\Student.txt","rb");
	if(fp==NULL)
	{
		printf("未知异常*********");
		return;
	}
	fflush(stdin);
	cls();
	printf("\n\n\n------请选择显示方式:\n\t\b 1.按姓名排序\n\t\b2.按学号排序\n\t\b3.按成绩排序\n\t\b# 默认为按姓名排序\n\n\t\b请输入您的选择:");
	g=getchar();
	switch(g-48)
	{
		case 1:sort(1);break;
		case 2:sort(2);break;
		case 3:sort(3);break;
		default:sort(1);break;
	}
	fclose(fp);
	puts("\n");
	printf("   ");
	system("pause");
	cls();
	return;
}

//----------------------------------------------清屏

void cls()
{
	system("CLS");
}

//----------------------------------------------删除文件

void de()
{
	if(remove("C:\\Student.txt")==0)
		printf("------已经删除文件-----\n");
	else
		printf("------没有足够访问权限------\n");
	return;
}

//-----------------------------------------------判断

int judge()
{
	FILE *fp=NULL;
	int i=0;
	student studentArray[100];
	fp=fopen("C:\\Student.txt","rb");
	if(fp==NULL)
		return 0;//没有创建学生信息
	for(;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++);
	if(i==0)
	{
		fclose(fp);
		return 1;//已经创建，但没有信息
	}
	fclose(fp);
	return 2;//已创建，有信息
}

//------------------------------------------------重建

void recreate()
{
	char t;
	cls();
	fflush(stdin);
	printf("\n\n\n确认重建？输入y确认,其他值取消:");
	scanf("%c",&t);
	if(t=='y'||t=='Y')
	{
		FILE *fp;
		fp=fopen("C:\\Student.txt","wb");
		if(fp==NULL)
			puts("\n\n\n------创建学生信息失败!");
		else
		{
			cls();
			puts("\n\n\n------创建成功!");	
		}
		fclose(fp);
	}
	else
	{
		cls();
		puts("\n\n\n------已取消重建操作.");
		return;
	}
}

//--------------------------------------------------退出

void close()
{
	char t;
	cls();
	fflush(stdin);
	printf("\n\n\n确认退出？输入y确认,其他值返回:");
	scanf("%c",&t);
	if(t=='y'||t=='Y')
		exit(0);
	else
	{
		cls();
		puts("\n\n------已返回,您可继续操作.");
		return;
	}
}

//--------------------------------------------------关于

void about()
{
	int i=1;
	for(;i<20;i++)
	{
		cls();
		puts("\n\n");
		printf("\t\t   ");
		int t=1;
		for(;t<i+1;t++)
			printf("* ");
		puts("\n\n\t\t\t     感谢您使用本软件\n");
		printf("\t\t   ");
		int q=1;
		for(;q<i+1;q++)
			printf("* ");
		Sleep(100);
	}
	char *p="若您对本程序有任何意见或建议,又或者您需要帮助\n      请联系作者:\n      发送邮件至\"xxx@yyy.com\".";
	window(p);
}

//-------------------------------------------------信息展示窗口设计

void window(char message[])
{
	int e,seconds=time;
	for(;seconds>0;seconds--)
	{
		e=10-seconds;
		cls();
		printf("\n\n\n------%s",message);
		for(;e<10;e++)
			puts("");
		printf("\n\n%-2d秒后系统将自动返回.",seconds);	
		Sleep(1000);	
	}
	cls();
}

//---------------------------------------------------准备阶段

void prepare()
{	
	FILE *fp=NULL;
	student studentArray[100];
	if(judge()==0)
		return;
	else
	{
		fp=fopen("C:\\Student.txt","rb");
		int i=0;
		for(;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++);//======================================================
			count=i;//==================================================================================================================
	}
}

//-------------------------------------------------------排序

void sort(int g)//1 2 3分别为按姓名 学号 分数
{
	FILE *fp=NULL;
	fp=fopen("C:\\Student.txt","rb");
	{
		if(fp==NULL)
			printf("********未知错误");
	}
	student studentArray[100];
	int i=0;
	for(;fread(&studentArray[i],sizeof(struct student),1,fp)==1;i++);//======================================================
		count=i;
	if(g==1)
		qsort(studentArray,count,sizeof(struct student),compg);
	else if(g==2)
		qsort(studentArray,count,sizeof(struct student),comph);
	else if(g==3)
		qsort(studentArray,count,sizeof(struct student),compi);
	cls();	
	printf("\n\n\n------一共有%d名学生:\n\n",count);
	if(g!=1)
	{
		puts("\t   学号     姓名     年龄  性别  成绩");
		rewind(fp);
		for(i=0;i<count;i++)
			printf("\t%-12s%-10s%-5d%-7s%-3d\n",studentArray[i].number,studentArray[i].name,studentArray[i].age,studentArray[i].sex,studentArray[i].score);
	}
	else
	{
		puts("\t   姓名     学号     年龄  性别  成绩");
		rewind(fp);
		for(i=0;i<count;i++)
			printf("\t%-10s%-12s%-5d%-7s%-3d\n",studentArray[i].name,studentArray[i].number,studentArray[i].age,studentArray[i].sex,studentArray[i].score);
	}
	fclose(fp);
}

//----------------------------------------------------比较器

int compg(const void *s1,const void *s2)
{	return (strcmp((*((struct student*)s1)).name,(*((struct student*)s2)).name));}
int comph(const void *s1,const void *s2)
{	return (strcmp((*((struct student*)s1)).number,(*((struct student*)s2)).number));}
int compi(const void *s1,const void *s2)
{	return ((*((struct student*)s1)).score-(*((struct student*)s2)).score);}

//--------------------------------------------帮助

void help()
{
	cls();
	char *p="* 初次使用本程序应先创建学生信息,然后方可添加学生的信息;\n\t\b* 重新创建学生信息会将之前已有的学生信息全部删除,请谨慎操作;\n\t\b* 建立的学生信息默认储存文件为:c:\\Student.txt";
	window(p);	
}
