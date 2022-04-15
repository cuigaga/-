#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数目结构体数组
//学生信息链表 
struct tushu{
	char number[200];
	char name [200];
	char writer[200];
	struct tushu *next;
};
struct xuesheng{
	char name[200];
	char book[200];
	struct xuesheng *next;
};
//定义函数 
//
int  guanliduan();
int  xueshengduan();
void search(struct tushu *q,FILE *fp);
int  chooseidentity ();
char* borrow(struct xuesheng *p,FILE *fp);
void printlist(struct xuesheng *p,FILE *fp);
void addbook(struct tushu *q,FILE *fp);
void del(struct tushu *q,FILE *fp,char del[100]) ;
void reback(struct xuesheng *p,FILE *fp,char del[200]);
void rebook(struct tushu *q,FILE *fp);
char* jieyue(struct tushu *q,FILE *fp,char name[200]); 
//主函数 
int main ()
{	
    struct tushu  *q;
	struct xuesheng *p;
	p=(struct xuesheng*)malloc(sizeof(struct xuesheng));
	q=(struct tushu*)malloc(sizeof(struct tushu));
	 //定义学生借阅信息链表+图书书目 
	FILE *fx,*ft;
	
	start4:
	int choose=chooseidentity();
	//学生操作 
	if(choose==1){                 
	int n=xueshengduan();	
	if(n==1){
		char sousuo[200];
		gets(sousuo);
		jieyue(q,ft,sousuo);
		printf("\n\n\n\n");
		printf("                    退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(n==2){
		char *delbook;
		delbook=borrow(p,fx);//返回书目名称
		char *num;
		num=jieyue(q,ft,delbook);//搜索图书 
	    del(q,ft,num);
	    printf("\n\n\n\n");
	    printf("                    退 出 请 输 入 0 !\n"); 
	    char select[100];
	    getchar();
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(n==3){
		char del[200]; 
		printf("             您的姓名是："); 
		scanf("%s",del);
		reback(p,fx,del);
		rebook(q,ft); 
		printf("\n\n\n\n");
		printf("                    退 出 请 输 入 0 !\n");
	    char select[100];
	    getchar();
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
		
	}
	else if(n==4){
	goto start4;
	}
}


	 //教师操作 
	else if (choose==0){
	int m=guanliduan();
	if(m==1){
		search(q,ft);
		printf("\n\n\n\n");
		printf("                    退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
		
	}
	else if(m==2)
	{
		addbook(q,ft);
		printf("\n\n\n\n");
	    printf("                    退 出 请 输 入 0 !\n"); 
	    char select[100];
	    getchar();
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(m==3)
	{
		char delnum[200];
		printf("                    请输入删除的书目编号:");  
		gets(delnum);
		del(q,ft,delnum);
		printf("\n\n\n\n");
		printf("                    退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(m==4)
	{
		printlist(p,fx);
		printf("\n\n\n\n");
		printf("                    退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(m==5)
	{
		goto start4;
	}	
}
     else if(choose==-1){
     	printf("****************************欢 迎 下 次 使 用 ！****************************"); 
     	return 0;
	 }


	return 0;
}
//                                              管理管理 
int  guanliduan()
{
	start3: 
	printf("                    1.查询图书\n"); 
	printf("                    2.增加图书\n"); 
	printf("                    3.删除图书\n"); 
	printf("                    4.查询借阅记录\n"); 
	printf("                    5.退出\n"); 
	char n[10];
	gets(n);
	if(n[0]=='1'){
			printf("————————————查询图书————————————\n"); 
			return 1; 
	}
	else if(n[0]=='2'){
	        printf("————————————增加图书————————————\n");
	        return 2;
	}
	else if(n[0]=='3'){
		    printf("————————————删除图书————————————\n"); 
		    return 3;
	}
	else if (n[0]=='4'){
		    printf("————————————查询借阅记录————————————\n");
			return 4; 
	}
	else if(n[0]=='5'){
	        return 5;
	}
	else {
		printf("————————————请重新输入————————————\n") ;
		goto start3; 
	}
	 
}
//                                学生学生！！！！ 
int  xueshengduan()
{
	start1:
	printf("                    1.查询图书\n"); 
	printf("                    2.借阅图书\n");
	printf("                    3.归还图书\n");
	printf("                    4.退出\n"); 
	char n[10];
	gets(n);
	if(n[0]=='1'){
		printf("————————————查询图书————————————\n");
		return 1;
	}
	else if(n[0]=='2'){
		printf("————————————借阅图书————————————\n"); 
		return 2; 
	}
	else if(n[0]=='3'){
		printf("————————————归还图书————————————\n");
		return 3;
	}
	else if(n[0]=='4'){
		return 4;
	}
	 else {
	 	printf("                              请重新输入！\n\n");
	 	goto start1;
	 }
 }
 int  chooseidentity ()
{
	char se[100]={"exit"};
	printf(          "********************欢 迎 来 到 图 书 借 阅 管 理 系 统********************\n\n");
	char choose[200];
start2:
	printf("            借阅人员请输入a,管理人员请输入b (按首位字符进行选择)      \n\n"); 
	printf("                             ----退出请输入exit---\n");
   gets(choose); 
   if(choose[0]=='a'){
   	printf("                您的身份为“借阅人员”\n");          //学生端
   	return 1;
   }
   else if(choose[0]=='b'){
   	printf("                您的身份为“管理人员”\n");
   	return 0; 
   }
   else if(strcmp(choose,se)==0)
   {
   	return -1;
   }
   else {
   	printf("                              请重新输入！\n\n"); 
   	goto start2;
   }
} 
char*  borrow(struct xuesheng *p,FILE *fp)
{
	static char ret[200];
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","a");
	struct xuesheng *s,*n;
	char judge[20];
	n=p;
	printf("                  是否进行借阅？(按y继续借阅，其他任意键退出)\n"); 
	while(scanf("%s",&judge),judge[0]=='y') 
	{
		s=(struct xuesheng*)malloc(sizeof (struct xuesheng));
		printf("                请输入借阅人姓名：\n"); 
		scanf("%s",&s->name);
		fprintf(fp,"%s   ",s->name);
		printf("                请输入借阅书目：\n");
		scanf("%s",&s->book);
		fprintf(fp,"%s",s->book);
		strcpy(ret,s->book);
		fprintf(fp,"\n");
		n->next=s;
		n=s;
			printf("                  是否进行借阅？(按y继续借阅，其他任意键退出)\n"); 
		}
	n->next=NULL;
	fclose(fp);
	return ret;
}
void printlist( struct xuesheng *p,FILE *fp)
{
	struct xuesheng *s;
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	char end;
	char tidai[200];
	s=(struct xuesheng*)malloc(sizeof(struct xuesheng));
		
	while(end=fscanf(fp,"%s %s",&s->name,&s->book),end!=EOF)
	{
     	printf("             借阅人：%s",s->name);
		printf("  借阅书目：%s\n",s->book); 	
	 } 
}
void addbook(struct tushu *q,FILE *fp)
{
	struct tushu *n,*s;
	n=q;
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","a");
	printf("             请输入图书信息\n");
	printf("        输入“ok”停止输入，是否继续输入？\n");
	char a[200]; 
	int i=0;
	while(scanf("%s",&a),a[0]!='o',a[1]!='k') 
	{
		s=(struct tushu*)malloc(sizeof(struct tushu));
		printf("                 图书名称为：");
		scanf("%s",s->name);
		fprintf(fp,"%s ",s->name);
		printf("                 作者为：");
		scanf("%s",s->writer);
		fprintf(fp,"%s ",s->writer);
		printf("                 图书编号为："); 
		scanf("%s",s->number);
		fprintf(fp,"%s",s->number); 
		fprintf(fp,"\n");
		n->next=s;
		n=s;
		printf("       输入“ok”停止输入，是否继续输入？\n");
	}
	n->next=NULL;
		fclose(fp);
}
void del(struct tushu *q,FILE *fp,char del[200]) 
{
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s,*m;
	char end,find[200];
	if(strcmp(q->number,del)==0){
		q=q->next;
	} 
	n=q;
	while(s=(struct tushu*)malloc(sizeof(struct tushu)),end=fscanf(fp,"%s %s %s",&s->name,s->writer,s->number),end!=EOF){
	
		if(strcmp(s->number,del)!=0){
		n->next=s;
		n=s;
		printf("%s %s %s\n",s->name,s->writer,s->number); 
		}
	}
	n->next=NULL;
	m=q->next;
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","w");
	fclose(fp); 
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	while(m!=NULL)
	{
	    fprintf(fp,"%s %s %s\n",m->name,m->writer,m->number);
		m=m->next;
	}
fclose(fp);
}
void search(struct tushu *q,FILE *fp)
{
		fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s;
	n=q;
	s=q->next;
	char end;
	printf("书名        作者        编号\n"); 
	s=(struct tushu*)malloc(sizeof(struct tushu));
	while(end=fscanf(fp,"%s %s %s",&s->name,s->writer,s->number),end!=EOF){
		printf("%-10s %-10s %-10s\n",s->name,s->writer,s->number);
		n->next=s;
		n=s;
	}
	n->next=NULL;
	fclose (fp);
}
void reback(struct xuesheng *p,FILE *fp,char del[200])
{
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	struct xuesheng *n,*s,*m;
	char end,find[200];
	if(strcmp(p->name,del)==0){
		p=p->next;
	} 
	n=p;
	m=p;
	s=(struct xuesheng*)malloc(sizeof(struct xuesheng));
	while(end=fscanf(fp,"%s %s",&s->name,s->book),end!=EOF){
		if(strcmp(s->name,del)!=0){
		n->next=s;
		n=s;
		}else s->next=NULL;
	}
	n->next=NULL;
	m=m->next;
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","w");
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	while(m!=NULL)
	{
	    fprintf(fp,"%s %s\n",m->name,m->book);
		m=m->next;
	}
	fclose(fp);
	
}
void rebook(struct tushu *q,FILE *fp)
{
	struct tushu *n,*s;
	n=q;
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","a");

	char a[200]; 
	int i=0;
	printf("       归还结束输入“ok”，是否还有图书需要归还？\n");
	while(scanf("%s",&a),a[0]!='o',a[1]!='k') 
	{
		printf("");
		s=(struct tushu*)malloc(sizeof(struct tushu));
		printf("                 请输入图书信息  \n") ;
		printf("                 图书名称为：");
		scanf("%s",s->name);
		fprintf(fp,"%s ",s->name);
		printf("                 作者为：");
		scanf("%s",s->writer);
		fprintf(fp,"%s ",s->writer);
		printf("                 图书编号为："); 
		scanf("%s",s->number);
		fprintf(fp,"%s",s->number); 
		fprintf(fp,"\n");
		n->next=s;
		n=s;
		printf("       归还结束输入“ok”，是否还有图书需要归还？\n");
	}
	n->next=NULL;
		fclose(fp);
}
char *jieyue(struct tushu *q,FILE *fp,char name[200])
{
	static char re[200];
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s;
	n=q;
	s=q->next;
	char end;
	printf("书名        作者        编号\n"); 
	s=(struct tushu*)malloc(sizeof(struct tushu));
	while(end=fscanf(fp,"%s %s %s",&s->name,s->writer,s->number),end!=EOF){
		if(strcmp(s->name,name)==0){
		printf("%-10s %-10s %-10s\n",s->name,s->writer,s->number);
	    strcpy(re,s->number);
	}
		n->next=s;
		n=s;
	}
	n->next=NULL;
	fclose (fp);
}














