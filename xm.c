#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<getch.h>
#include<ctype.h>

static int count=0;

typedef struct xx{
static char name[100][20];
static char sex[100];
static char tel[100][12];
};

void add_t(void);
void del_t(void);
void re_t(void);
void sel_t(void);
void show_t(void);
char menu(void);

void anykey_continue(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	puts("任意键继续...");
	getch();
}


void show_msg(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}


void add_t(void)
{
	struct xx a;
	
	if(count>=100)
	{
		puts("系统正在升级，请等待...");
		return;
	}
	int i=0;
	while(a.sex[i]) i++;
	
	printf("请输入姓名，性别，电话：\n");
	scanf("%s %c %s",a.name[i],a.sex+i,a.tel[i]);
	count++;
	
	show_msg("添加联系人成功！\n",0.5);
}


void del_t(void)
{
	struct xx d;
	char key[20]={};
	char i=0;
	
	printf("按姓名或电话删除(n/t):");
	scanf("%s",d.key);
	
	do
	{
		if(d.sex[i])
			{
				if(isdigit(key[0]))
				{
					if(0==strcmp(d.tel[i],key))
						break;	
				}
				else
				{
					if(0==strcmp(d.name[i],key))
						break;
				}
			}
	}while(++i<100);
	
	if(i<100)
		{
			printf("删除 %s %s %s 联系人成功!\n",d.name[i],'w'==d.sex[i]?"女":"男",d.tel[i]);
			d.sex[i]=0;
			count--;
		}
	else
	{
		printf("没有找到该联系人，请检查查询条件:%s\n",key);
	}
	show_msg("",1.5);
}


void re_t(void)
{
`	struct xx r;
	char i=0;
	char key[20]={};
	printf("请要修改的联系人名字：\n");
	scanf("%s",key);
	for(i=0;i<100;i++)
	{
		if(r.sex[i] && 0 == strcmp(r.name[i],key))
		{
			printf("请重新输入联系人的姓名，性别，电话：\n");
			scanf("%s %c %s",r.name[i],r.sex+i,r.tel[i]);
			show_msg("修改联系人成功!\n",1.5);
		return;
		}
	}	
	show_msg("未找到该联系人\n",1.5);
}


//查询
void sel_t(void)
{
	struct xx s;
	char i=0;
	char key[20]={};
	printf("请要查询的关键字：\n");
	scanf("%s",s.key);
	for(i=0;i<100;i++)
	{
		if(s.sex[i]&& (strstr(s.name[i],key)||strstr(s.tel[i],key)))
		{
			printf("%s %s %s\n",s.name[i],'w'==s.sex[i]?"女":"男",s.tel[i]);
		}
	}
	anykey_continue();
}


void show_t(void)
{
struct xx sh;
	int i=0;
	for(i=0;i<100;i++)
	{
		if(sh.sex[i])
		{
			printf("%s %s %s\n",sh.name[i],'w'==sh.sex[i]?"女":"男",sh.tel[i]);	
		}	
	}
	anykey_continue();
}

char menu(void)
{
	system("clear");
	puts("***欢迎使用指针通讯录***");
	puts("1，添加联系人");
	puts("2，删除联系人");
	puts("3，修改联系人");
	puts("4，查询联系人");
	puts("5，遍历联系人");
	puts("6，退出程序");
	puts("-------------");
	printf("请输入指令：\n");
	char cmd=getch();
	printf("%c\n",cmd);
	return cmd;
}

int main(int argc,const char* argv[])
{
	for(;;)
	{
		switch(menu())
		{
			case '1': add_t(); break;
			case '2': del_t(); break;
			case '3': re_t(); break;
			case '4': sel_t(); break;
			case '5': show_t(); break;
			case '6': return 0;
		}
	}
}

