#include<stdio.h>
#include<string.h>
//#include<color.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
typedef struct train          //火车票的具体信息
{
	char num[10];             //火车号
	char startcity[10];        //起始站
	char reachcity[10];        //终点站
	char takeofftime[10];     //起始时间
	char arrivetime[10];      //到达时间
	int surticket;            //剩余的票数
	int price;                //票价
	struct train *next;       //保存下一个火车结点的地址
}TRAIN; 

                     
typedef struct man            //订票人的信息
{
	char ticketnum[10];       //订购的火车号
	char name[10];            //订票人姓名
	int booknum;              //订的票数
	char id[20];              //订票人的票数
	struct man *next;         //保存下一个订票人的结点地址
}MAN;  
                        //订票人的具体信息
int z=0,k=0;        //火车信息，订票人当前的个数

void regi()                                            //登陆系统，需要准确的账号和密码
{
	char account[6]="abcdef",password[8]="04131094";
	char acc[6],pass[9];
	int i,j;
	printf("\n\n\n\n\n\t\t\t|-----------------------------------------|\n");
	for(i=0;i<3;i++)                          //共有三次机会进行登录
	{
		//system("color 3e");
		
		printf("\t\t\t\t\t登陆账号:");
	    gets(acc);
	    printf("\n\t\t\t\t\t登陆密码:");
	  for(j=0;j<8;j++)                       // 隐式密码的输入
	  {
	 	 pass[j]=getch();
		 printf("*");
	  }
	  pass[8]='\0';
	  getch();
	  printf("\n");
	  if(((strcmp(acc,"abcdef"))==0)&&((strcmp(pass,"04131094"))==0))
	  {
		  printf("\n\n\n\t\t\t\t系统正在登陆,请稍候.........");
		  Sleep(2000);                                                   //暂停2000ms
		  system("cls");                                                      //清屏
		  printf("\n\n\n\n\n\n\n\n\n\n");
		  printf("ww        ww         ww   eeeeeeee   ll       ccccccc   oooooooo        mm         mm       eeeeeeee\n");
		  printf(" ww      ww ww      ww    ee    ee   ll       cc        oo    oo      mm  mm     mm  mm     ee    ee\n");
	          printf("  ww    ww   ww    ww     ee  eeee   ll       cc        oo    oo     mm    mm   mm    mm    ee  eeee\n");
		  printf("   ww  ww     ww  ww      ee         ll       cc        oo    oo    mm      mm mm      mm   ee\n");
		  printf("     ww         ww        eeeeeeee   lllllll  ccccccc   oooooooo   mm        mm         mm  eeeeeeee\n");
		  break;
	  }
	  else
		  printf("\n\n\t\t\t\t\t账号与密码不符!\n");
    }
	if(i==3)
	{
	   printf("没机会啦!\n");
	   exit(0);
	}
	printf("\n\n\n\t\t\t\t正在进入系统,请稍候.........");
	Sleep(2000);                                       //暂停2000ms
	system("cls");                                       //清屏
}


void opfile()                                     //对保存订票人信息的文件进行读取
{
	FILE *fp;
	MAN *head,*p1;
	head=NULL;
	    printf("\n\n\n\n\t\t\t文件中现有的订票人数据:\n\n\n");
	    printf("\t\t\t----------------------MAN  INFORMATION-------------------\n");
	    printf("\t\t\t| name     |         id         |ticketnumber|booknum   |\n");
	    printf("\t\t\t|----------|--------------------|------------|----------|\n");
	fp=fopen("E:\\man.dat","rb");
    if(fp==NULL)
	{
		fp=fopen("E:\\man.dat","wb+");
	    return;
	}   
    p1=(MAN *)malloc(sizeof(MAN));                         //打开文件进行读取时创建链表并输出
	while(fread(p1,sizeof(MAN),1,fp))                   //条件语句做判断
	{
		p1->next=head;
		head=p1;
		printf("\t\t\t|%-10s|%-20s|%-12s|%-10d|\n",p1->name,p1->id,p1->ticketnum,p1->booknum);
		p1=(MAN *)malloc(sizeof(MAN));
		k++;
	}
	free(p1);
	if(k==0)   
		printf("\t\t\t文件中无数据!\n");             //文件中此时不存在数据
	fclose(fp);
	getch();
}

TRAIN *openfile()                                     //对保存火车票信息的文件进行读取
{
	FILE *fp;
	TRAIN *head,*p1;
	head=NULL;
	system("cls");
	    printf("\n\n\n\n\t\t\t文件中现有的火车信息数据:\n\n\n");
	    printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
	fp=fopen("E:\\train.dat","rb");
    if(fp==NULL)
	{
		fp=fopen("E:\\train.dat","wb+");            //只读方式打不开时新建一个文件
		return NULL;
		//printf("打开文件错误!\n");
		//exit(0);
	}   
	p1=(TRAIN *)malloc(sizeof(TRAIN));
	while(fread(p1,sizeof(TRAIN),1,fp))
	{
		p1->next=head;
		head=p1;
		printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p1->num,p1->startcity,p1->reachcity,p1->takeofftime,p1->arrivetime,p1->price,p1->surticket);
		p1=(TRAIN *)malloc(sizeof(TRAIN));
		z++;
	}
	free(p1);
	if(z==0)   printf("文件中无数据!\n");
	fclose(fp);
	return head;
}


void menu()                      //菜单函数，可以选择具体操作
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t|-----------------------菜单---------------------|\n\n");
    printf("\t\t\t                     0>退出系统                 \n\n");
	printf("\t\t\t                     1>录入信息                 \n\n");
	printf("\t\t\t                     2>查找信息                 \n\n");
	printf("\t\t\t                     3>修改信息                 \n\n");
	printf("\t\t\t                     4>添加信息                 \n\n");
	printf("\t\t\t                     5>删除信息                 \n\n");
	printf("\t\t\t                     6>订票信息                 \n\n");
	printf("\t\t\t                     7>信息排序                 \n\n");
	printf("\t\t\t                     8>信息显示                 \n\n");
	printf("\t\t\t                   9>订票人信息显示             \n\n");
    printf("\t\t\t|------------------------------------------------|\n");
	printf("                  请选择(0--9):");
}


void saveman(MAN head)               // 将订票人的信息页保存到文件里
{
	FILE *fp;
	MAN *p;
	p=&head;
	fp=fopen("E:\\man.dat","ab+");
	if(fp==NULL)
	{
		printf("打开文件错误!\n");
		exit(0);
	}
	else
	{
		  fwrite(p,sizeof(MAN),1,fp);
	}
	fclose(fp);
}


void savetrain(TRAIN *head)        //将火车信息保存到文件里
{
	FILE *fp;
	TRAIN *p;int j;
	p=head;
	fp=fopen("E:\\train.dat","wb");
	if(fp==NULL)
	{
		printf("打开文件错误!\n");
		exit(0);
	}
	else
	{
		for(j=0;j<z;j++)
		{
		  fwrite(p,sizeof(TRAIN),1,fp);
		  p=p->next;
		}
	}
	fclose(fp);
}

TRAIN *intrain(TRAIN *head)                     // 录入火车信息
{
	TRAIN *p1; 
	int i=0;
	char num[10];
	p1=head;
	while(1)
	{
		p1=(TRAIN *)malloc(sizeof(TRAIN));
		fflush(stdin);
		printf("请输入火车号(000代表返回):");
		scanf("%s",num);
	    if((strcmp(num,"000"))==0)
		{
			free(p1);
			break;                             //如果输入的火车号为00，退出该被调函数
		}
		else
		{  
		    strcpy(p1->num,num);
			fflush(stdin);
		    printf("请输入火车始发站:");
		    scanf("%s",p1->startcity);
			fflush(stdin);
		    printf("请输入火车终点站:");
		    scanf("%s",p1->reachcity);
			fflush(stdin);
		    printf("请输入火车起始时间:");
		    scanf("%s",p1->takeofftime);
			fflush(stdin);
	    	printf("请输入火车到站时间:");
	    	scanf("%s",p1->arrivetime);
			fflush(stdin);
	    	printf("请输入剩余票数:");
	    	scanf("%d",&p1->surticket);
			fflush(stdin);
	    	printf("请输入票价:");
			scanf("%d",&p1->price);
			printf("\n");
            z++;
		    p1->next=head;
	     	head=p1;
		}
	}	
	savetrain(head);//将录入的信息保存到相应的文件中
	getch();
	return head;
}


void showtrain(TRAIN *head)      // 显示当前的所有火车信息
{
	TRAIN *p;int i=0;
	 p=head;
	    printf("\n\n\t\t\t当前共有%d个火车信息\n\n",z);
	    printf("\n\n\n");
	    printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
	while(p!=NULL)                          //遍历整个链表并输出
	{
        printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
	    i++;
		p=p->next;
	}
	
	if(i==0)
	{
		printf("没有信息\n");
		getch();
		return;
	}
    getch();
	return;
}


void seatrain(TRAIN *head)           //查找某个火车的信息
{
	TRAIN *p1,*h;
    char snum[10],ad[10];
	int ch,i=0;
	p1=h=head;
	printf("1>按火车号查询\n");
    printf("2>按终点站查询\n");
	printf("请选择查询方式:");
	scanf("%d",&ch);
	if(ch==1)                       //按火车号进行查询                        
	{
	   printf("请输入你想要查找的火车号:");
	   scanf("%s",snum);
	   printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	   printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	   printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
	   while(p1!=NULL)
	   {
		  if((strcmp(p1->num,snum))==0)
		  {
		    printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p1->num,p1->startcity,p1->reachcity,p1->takeofftime,p1->arrivetime,p1->price,p1->surticket);
			i++;                                          // 输出该火车信息
		  }
		  p1=p1->next;
	   }
	   if(i==0)
		   printf("没找到相关信息!\n");
	}
	else                                               //按火车终点站进行查询
	{
		printf("请输入你想要查找的火车终点站:");
		scanf("%s",ad);
		printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		while(p1!=NULL)
		{
		  if((strcmp(p1->reachcity,ad))==0)
		  {
		     printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p1->num,p1->startcity,p1->reachcity,p1->takeofftime,p1->arrivetime,p1->price,p1->surticket);
			 i++;                                      //输出链表中所有到达该终点站的火车信息
		  }
		  p1=p1->next;
		}
		if(i==0)
		   printf("没找到相关信息!\n");
	}
	getch();
}


TRAIN *modtrain(TRAIN *head)               //修改某个火车信息
{
	TRAIN *p;
	char mnum[10];
	int i=0;
	p=head;
	printf("请输入你想要修改的火车号:");
	scanf("%s",mnum);
	while(p!=NULL)
	{
        if((strcmp(p->num,mnum))==0)
		{
		   printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");     //首先输出该火车信息
	       printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");    
	       printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		   printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
		     i++;break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("没找到该车号的火车!\n");
		getch();
		return NULL;
	}
	else                                      //然后进行修改
	{
		strcpy(p->num,mnum);
		fflush(stdin);
		printf("请输入火车始发站:");
		scanf("%s",p->startcity);
	    fflush(stdin);
		printf("请输入火车终点站:");
		scanf("%s",p->reachcity);
		fflush(stdin);
	    printf("请输入火车起始时间:");
		scanf("%s",p->takeofftime);
		fflush(stdin);
	    printf("请输入火车到站时间:");
	    scanf("%s",p->arrivetime);
		fflush(stdin);
	    printf("请输入剩余票数:");
	    scanf("%d",&p->surticket);
		fflush(stdin);
	    printf("请输入票价:");
		scanf("%d",&p->price);
	}
	savetrain(head);                   //将修改后的信息保存
	getch();
	return head;
}


TRAIN *addtrain(TRAIN *head)              //添加一个火车信息
{
	TRAIN *p,*q;
    char anum[10];
	int flag=1;
	q=head;
	printf("\t\t\t请输入你想添加的火车信息:\n\n\n");
	printf("请输入火车号:");
	scanf("%s",anum);
	while(q!=NULL)
	{
		if((strcmp(q->num,anum))==0)                //查看是否已经存在该火车
		{
			printf("该火车已经存在，不能进行添加");
			flag=0;
		break;
		}
		q=q->next;
	}
	if(flag==1)                                         //不存在则可进行添加
	{
		p=(TRAIN *)malloc(sizeof(TRAIN));
		strcpy(p->num,anum);
		fflush(stdin);
		printf("请输入火车始发站:");
		scanf("%s",p->startcity);
		fflush(stdin);
		printf("请输入火车终点站:");
		scanf("%s",p->reachcity);
		fflush(stdin);
		printf("请输入火车起始时间:");
		scanf("%s",p->takeofftime);
		fflush(stdin);
	    printf("请输入火车到站时间:");
	    scanf("%s",p->arrivetime);
		fflush(stdin);
	    printf("请输入剩余票数:");
	    scanf("%d",&p->surticket);
		fflush(stdin);
	    printf("请输入票价:");
		scanf("%d",&p->price);
		printf("\n");
	    p->next=head;
		head=p;
		z++;
		printf("\n\n\n\t\t\t添加成功!\n");
	}
	savetrain(head);                //添加后的信息保存
	getch();
	return head;
}


TRAIN *deltrain(TRAIN *head)                 //删除某个火车信息
{
   TRAIN *p,*q;
   char dnum[10];
   int flag=0;
   printf("请输入你想要删除的火车号:");
   scanf("%s",dnum);
   for(p=head;p!=NULL&&(strcmp(p->num,dnum)!=0);q=p,p=p->next);

   if(p==NULL)
	   printf("\t\t\t没找到该火车信息!\n");
   else                           //对该火车进行删除
   {
	   if(p==head)
	   {
		   head=head->next;
		   free(p);
	   }
	   else
	   {
		   q->next=p->next;
		   free(p);
	   }
	   z--;
	   printf("\t\t\t删除成功!\n");         //删除成功
	   printf("\t\t\t可以点击  8>信息显示  进行火车信息查询");
   }
   savetrain(head);                     //保存删除后的信息
   getch();
   return head;
}


TRAIN *booktrain(TRAIN *head)        //火车订票两种订票方式 
{
	MAN h;
	TRAIN *p;
	char tac[10];
	int ch,flag=0;
	p=head;
    printf("\t\t\t请选择订票的方式:\n");
    printf("\n1>按火车号订票\n");
	printf("\n2>按终点站订票\n");
	scanf("%d",&ch);
	if(ch==1)                          //   按火车号进行订票
	{
        
		printf("请输入订票的火车号:");
		scanf("%s",h.ticketnum);
		        printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	            printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	            printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		while(p!=NULL)
		{
			if((strcmp(p->num,h.ticketnum))==0)
			{
				printf("找到了!\n");
				printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
				if(p->surticket<1)
				{
					printf("\n抱歉,没票了\n");
					getch();
					return head;
				}
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag)
		{
			printf("请输入您的姓名:");
			scanf("%s",h.name);
			printf("请输入您的身份证号:");
			scanf("%s",h.id);
			printf("请问你需要订几张票:");
			scanf("%d",&h.booknum);
			p->surticket=(p->surticket)-(h.booknum);
			k++;

		}
		else
		{
			printf("暂时没有该火车信息!\n");
		}
	}
	else                                 //按火车终点站进行订票
	{
		printf("请输入订票的终点站:");
		scanf("%s",tac);
		printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		
        while(p!=NULL)
		{
			if((strcmp(p->reachcity,tac))==0)
			{
				printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
				flag=1;
			}
			p=p->next;                //将所有到达该终点站的火车信息显示出来
		}          
	
		if(flag)
		{
			p=head;
			printf("请输入订票的火车号:");                //选择你订票的火车号
		    scanf("%s",h.ticketnum);
			while(p!=NULL)
			{
			   if((strcmp(p->num,h.ticketnum))==0)
			   {
				  printf("找到了!\n");
				  printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
				  if(p->surticket<1)
				{
					printf("\n抱歉,没票了\n"); 
					getch();
					return head;
				}
				  flag=1;
				  break;
			   }
			   p=p->next;
			}
			printf("请输入您的姓名:");
			scanf("%s",h.name);
			printf("请输入您的身份证号:");
			scanf("%s",h.id);
			printf("请问你需要订几张票:");
			scanf("%d",&h.booknum);
			p->surticket=(p->surticket)-(h.booknum);
			k++;
		}
		else
		{
			printf("暂时没有该火车信息!\n");
		}
	}
    if(flag==1)
	{
		printf("\n\n\n\t\t\t订票成功!\n");
		saveman(h);
	}
	savetrain(head);
	
	getch();
	return head;
}


TRAIN *sorttrain(TRAIN *head)           //对火车信息按火车号大小进行排序
{
	TRAIN *p,*q,*t,*m,*n,a;
	for(p=head;p;t=p,p=p->next);
	for(p=head;p;p=p->next)
	{
		for(q=p->next;q;q=q->next)
		{
			if(strcmp(p->num,q->num)>0)
			{
				m=p->next;
				n=q->next;
				a=*p;
				*p=*q;
				p->next=m;
				*q=a;
				q->next=n;
			}
		}
	}
	printf("\n\n\t\t\t已成功排序  可选择 8>信息显示 进行查看!\n\n");
	savetrain(head);            //排好序的保存到文件中
	getch();
	return head;	
}


int main(void)
{
	int sel;
    TRAIN *head;
	regi();                          //登录系统
	head=openfile();//打开文件查看文件里面是否有数据
	getch();
	menu();
	scanf("%d",&sel);
	while(sel)
	{
	  switch(sel)
	  {
	    case 1:head=intrain(head);break;
        case 2:seatrain(head);break;
        case 3:head=modtrain(head);break;
        case 4:head=addtrain(head);break;
        case 5:head=deltrain(head);break;
        case 6:head=booktrain(head);break;
        case 7:head=sorttrain(head);break;
		case 8:showtrain(head);break;
		case 9:opfile();break;
	   default:break;
	  }
	  menu();
	scanf("%d",&sel);
	}
}
