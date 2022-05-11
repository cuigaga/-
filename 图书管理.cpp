#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数目结构体数组
//学生信息链表 
struct jieyue{
	char num[200];
	char name[200]; 
	struct jieyue *next;
}; 
struct tushu{
	char number[200];
	char name [200];
	char writer[200];
	struct tushu *next;
};
struct xuesheng{
	char name[200];
	char book[200];
	char num[200]; 
	struct xuesheng *next;
};
struct jiaoshi{
	char yonghu[200];
	char password[200];
	struct jiaoshi *next;
};
//定义函数 
//
int  guanliduan();
int  xueshengduan();
void search(struct tushu *q,FILE *fp);
int  chooseidentity ();
char* borrow(struct xuesheng *p,FILE *fp,char num[200]);
void printlist(struct xuesheng *p,FILE *fp);
void addbook(struct tushu *q,FILE *fp,FILE *ft);
char *del(struct tushu *q,FILE *fp,char del[100],char find[200]) ;
int  reback(struct xuesheng *p,FILE *fp,char del[200],int jude ) ;
void rebook(FILE *fp,FILE *ft,char num[200],char name[200]);
int jie(struct tushu *q,FILE *fp,char name[200]); 
void yanzheng(struct jieyue *q,FILE *ft,char num[200],char name[200]);
int judge(FILE *ft ,char num[200],char name[200]);
void delnum(struct jieyue *l,FILE *fp,char dell[200],char deln[200]);
void change(struct tushu *p,FILE *ft,char findname[200],char findnum[200]) ;
int  denglu (struct jiaoshi *j,FILE *fp,char name[200],char pass[200] );
//主函数 
int main ()
{	
    struct tushu  *q;
    struct jieyue *l;
	struct xuesheng *p;
	struct jiaoshi *k;
	l=(struct jieyue*)malloc(sizeof(struct jieyue));
	p=(struct xuesheng*)malloc(sizeof(struct xuesheng));
	q=(struct tushu*)malloc(sizeof(struct tushu));
	k=(struct jiaoshi*)malloc(sizeof(struct jiaoshi));
	//防止指针报错 
	 //定义学生借阅信息链表+图书书目 
	FILE *fx,*ft,*fp;
	
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","a+");
	fclose (fp);
	fp=fopen("C:\\Users\\1\\Desktop\\借阅信息.txt","a+");
	fclose (fp);
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","a+");
	fclose (fp);
	fp=fopen("C:\\Users\\1\\Desktop\\教师信息.txt","a+");
	fclose(fp);
	fp=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","a+");
	fclose(fp); 
	//创建文件，以免使用“r+”打开文件时报错 
	start4:
	int choose=chooseidentity();
	//学生操作 
	if(choose==1){                 
	int n=xueshengduan();	
	if(n==1){
		int judg=0;
		char sousuo[200],ret[200];
		printf("                  请输入需要检索的图书名称:");
		gets(sousuo);
		int jud=jie(q,ft,sousuo);
		if(jud!=-1){
		printf("\n\n");
		printf("                  请输入需要借阅的图书编号:(取消借阅输入esc)");
		char num [200];
		gets(num);
		if(strcmp(num,"esc")!=0){ 
		borrow(p,fx,num);
		del(q,ft,num,ret);
		yanzheng(l,ft,num,sousuo);
		judg++;
	} 
	}
	if(jud==-1){
		printf("\n\n\n                               未查询到图书!!!"); 
	}
		printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	
	else if(n==2){
		int judg=0;
		char del[200],name[200]; 
		printf("                         您的学号是："); 
		scanf("%s",del);
		printf("               需要归还的图书编号为：");
		char backnum[200];
		getchar();
		gets(backnum); 
		printf("               需要归还的图书名称为：");
		gets(name); 
		int n=0;
		n=judge(ft,backnum,name); 
		if(n==1){
			int jude=0;
			jude=reback(p,fx,del,jude);
			if(jude!=0){
		    rebook(fp,ft,backnum,name); 
		    delnum(l,ft,backnum,name);
		    printf("\n\n\n\n");
		}else printf("\n\n\n                   归 还 信 息 错 误！\n\n\n\n");
	}else printf("\n\n\n                   归 还 信 息 错 误！\n\n\n\n"); 
	printf("                         退 出 请 输 入 0 !\n");
	 char select[100];
		getchar();
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(n==3){
	goto start4;
	}
}


	 //教师操作 
	else if (choose==0){
		printf("                            请输入用户名：");
		char yong[200];
		gets(yong);
		printf("                              请输入密码：");
		char pass[200];
		gets(pass); 
		int pan=denglu(k,fp,yong,pass);
		if(pan!=1){
			printf("\n\n\n                         用户名或密码错误！！！\n\n\n\n");
			goto start4; 
	}
	else printf("\n\n                                  登录成功！\n\n\n")	; 
	int m=guanliduan();
	if(m==1){
		search(q,ft);
		printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
		
	}
	else if(m==2)
	{
		addbook(q,ft,ft);
		printf("\n\n\n\n");
	    printf("                             退 出 请 输 入 0 !\n"); 
	    char select[100];
	    getchar();
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(m==3)
	{
		printf("                    请输入删除书目的名称:(退出请输入esc)");
		char name[200]; 
		gets(name); 
			if(strcmp(name,"esc")!=0){
		int check=jie(q,ft,name);
		if(check==-1){
			printf("\n\n\n                        未找到此图书\n");
		}else{
	    char delnum[200];
		printf("                    请输入删除的书目编号:");  
		gets(delnum);
		del(q,ft,delnum,name);
		}
}
		printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(m==4)
	{
		char findname[200];
		char findnum[200];
		printf("请输入需要修改的图书名称：");
		gets(findname);
		int judg=jie(q,ft,findname); 
		if(judg!=-1){
		printf("请输入图书编号：");
		gets(findnum);
		change(q,ft,findname,findnum);
	}
	 	printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	

}
	else if(m==5)
	{
		printlist(p,fx);
		printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(m==6)
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
	printf("                            1.查询图书\n"); 
	printf("                            2.增加图书\n"); 
	printf("                            3.删除图书\n");
	printf("                            4.查改图书\n");
	printf("                            5.查询借阅记录\n"); 
	printf("                            6.退出\n"); 
	char n[10];
	gets(n);
	if(n[0]=='1'){
			printf("——————————————查询图书————————————\n"); 
			return 1; 
	}
	else if(n[0]=='2'){
	        printf("——————————————增加图书————————————\n");
	        return 2;
	}
	else if(n[0]=='3'){
		    printf("——————————————删除图书————————————\n"); 
		    return 3;
	}
	else if(n[0]=='4'){
		    printf("——————————————查改图书——————————————\n");
		    return 4;
	}
	else if (n[0]=='5'){
		    printf("—————————————查询借阅记录————————————\n");
			return 5; 
	}
	else if(n[0]=='6'){
	        return 6;
	}
	else {
		printf("——————————————请重新输入————————————\n") ;
		goto start3; 
	}
	 
}
//                                学生学生！！！！ 
int  xueshengduan()
{
	start1:
	printf("                            1.借阅图书\n"); 
	printf("                            2.归还图书\n");
	printf("                            3.退出\n"); 
	char n[10];
	gets(n);
	if(n[0]=='1'){
		printf("——————————————借阅图书————————————\n");
		return 1;
	}
	else if(n[0]=='2'){
		printf("——————————————归还图书————————————\n"); 
		return 2; 
	}
	else if(n[0]=='3'){
		return 3;
	}
	 else {
	 	printf("                                 请重新输入！\n\n");
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
	printf("                        ----退出请输入exit---\n");
   gets(choose); 
   if(strcmp(choose,"a")==0){
   	printf("                        您的身份为“借阅人员”\n");          //学生端
   	return 1;
   }
   else if(strcmp(choose,"b")==0){
   	printf("                        您的身份为“管理人员”\n");
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
char*  borrow(struct xuesheng *p,FILE *fp,char num[200])
{
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","a");
		printf("                请输入借阅人姓名："); 
		char name[200];
		scanf("%s",name);
		char xueshengnum[200];
		printf("                   请输入学号：") ;
		getchar();
		gets(xueshengnum); 
		fprintf(fp,"%s ",name);
		fprintf(fp,"%s ",xueshengnum);
		fprintf(fp,"%s",num);
		fprintf(fp,"\n");
	fclose(fp);
}
void printlist( struct xuesheng *p,FILE *fp)
{
	struct xuesheng *s;
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	char end;
	char tidai[200];
	s=(struct xuesheng*)malloc(sizeof(struct xuesheng));
		
	while(end=fscanf(fp,"%s %s %s",&s->name,&s->num,&s->book),end!=EOF)
	{
     	printf("             借阅人：%s ",s->name);
     	printf("学号：%s ",s->num) ;	
		printf("   借阅书籍编号：%s\n",s->book);
		
	 } 
}
void addbook(struct tushu *q,FILE *fp,FILE *ft)
{
	struct tushu *n,*s;
	n=q;
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","a");
	ft=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","a");
	printf("                         请输入图书信息\n");
	printf("               输入“ok”停止输入，是否继续输入？\n");
	char a[200]; 
	int i=0;
	while(scanf("%s",&a),a[0]!='o',a[1]!='k') 
	{
		s=(struct tushu*)malloc(sizeof(struct tushu));
		printf("                         图书名称为：");
		scanf("%s",s->name);
		fprintf(fp,"%s ",s->name);
		fprintf(ft,"%s ",s->name);
		printf("                          作者为：");
		scanf("%s",s->writer);
		fprintf(fp,"%s ",s->writer);
		fprintf(ft,"%s ",s->writer);
		printf("                        图书编号为："); 
		scanf("%s",s->number);
		fprintf(fp,"%s",s->number); 
		fprintf(ft,"%s",s->number);
		fprintf(fp,"\n");
		fprintf(ft,"\n");
		n->next=s;
		n=s;
		printf("               输入“ok”停止输入，是否继续输入？\n");
	}
	n->next=NULL;
		fclose(fp);
		fclose(ft);
}
char* del(struct tushu *q,FILE *fp,char del[200],char find[200]) 
{
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s,*m;
	char end;
	n=q;
	while(s=(struct tushu*)malloc(sizeof(struct tushu)),end=fscanf(fp,"%s %s %s",&s->name,s->writer,s->number),end!=EOF){
	
		if(strcmp(s->number,del)!=0){
		n->next=s;
		n=s;
		}
		else strcpy(find,s->name);
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
return find;
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
int reback(struct xuesheng *p,FILE *fp,char del[200],int jude)
{
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	struct xuesheng *n,*s,*m;
	char end;
	n=p;
	m=p;
	s=(struct xuesheng*)malloc(sizeof(struct xuesheng));
	while(end=fscanf(fp,"%s %s %s",&s->name,s->num,s->book),end!=EOF){
		if(strcmp(s->num,del)!=0){
		n->next=s;
		n=s;
		}
		else jude++;
	}
	n->next=NULL;
	m=m->next;
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","w");
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	while(m!=NULL)
	{
	    fprintf(fp,"%s %s %s\n",m->name,m->num,m->book);
		m=m->next;
	}
	fclose(fp);
	return jude;
}
void rebook(FILE *fp,FILE *ft,char num[200],char name[200])
{
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","a");
	ft=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","r+");
	char a[200];
	char end; 
	char sname[200],swriter[200],snum[200];
	while(end=fscanf(ft,"%s %s %s",&sname,swriter,snum),end!=EOF)
	{
		if(strcmp(num,snum)==0&&strcmp(name,sname)==0)
		{
			break;
		}
	}
	fclose(ft);
	a[0]='s';
	a[1]='s';
	while(strcmp(a,"ok")!=0) 
	{
		printf("");
		fprintf(fp,"%s ",sname);
		fprintf(fp,"%s ",swriter);
		fprintf(fp,"%s",snum); 
		fprintf(fp,"\n");
		printf(" \n\n                   归还结束输入“ok”\n");
		scanf("%s",&a);
	}
		fclose(fp);
}
int jie(struct tushu *q,FILE *fp,char name[200])
{
	static char re[200];
	int jud=0; 
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
		jud++;
	}
		n->next=s;
		n=s;
	}
	n->next=NULL;
	fclose (fp);
	if(jud==0){
		return -1;
	}
}
void yanzheng(struct jieyue *q,FILE *ft,char num[200],char name[200])
{
	ft=fopen("C:\\Users\\1\\Desktop\\借阅信息.txt","a+");
	fprintf(ft,"%s ",num);
	fprintf(ft,"%s\n",name);
	fclose (ft);
 } 
int judge(FILE *ft ,char num[200],char name[200])
{
	ft=fopen("C:\\Users\\1\\Desktop\\借阅信息.txt","r+");
	char a[200],b[200],end;
	int c=0;
	while(end=fscanf(ft,"%s %s",a,b),end!=EOF)
	{
		if(strcmp(a,num)==0&&strcmp(b,name)==0)
		{
			c++;
		}
	}
	if(c==0){
		return -1;
	}
	else return 1;
}
void delnum(struct jieyue *l,FILE *fp,char dell[200],char deln[200]) 
{
	fp=fopen("C:\\Users\\1\\Desktop\\借阅信息.txt","r+");
	struct jieyue *n,*s,*m;
	char end;
	n=l;
	while(s=(struct jieyue*)malloc(sizeof(struct jieyue)),end=fscanf(fp,"%s %s",s->num,s->name),end!=EOF){
		if(strcmp(s->num,dell)!=0&&strcmp(s->name,deln)!=0){
		n->next=s;
		n=s;
		}
	}
	n->next=NULL;
	m=l->next;
	fp=fopen("C:\\Users\\1\\Desktop\\借阅信息.txt","w");
	fclose(fp);
	fp=fopen("C:\\Users\\1\\Desktop\\借阅信息.txt","r+");
	while(m!=NULL)
	{
	    fprintf(fp,"%s %s\n",m->num,m->name);
		m=m->next;
	}
fclose(fp);
}
void change(struct tushu *p,FILE *ft,char findname[200],char findnum[200]) 
{
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s,*m;
	n=p;
	char end;
	while(s=(struct tushu*)malloc(sizeof(struct tushu)),end=fscanf(ft,"%s %s %s",s->name,s->writer,s->number ),end!=EOF){
		if(strcmp(s->name,findname)==0&&strcmp(s->number,findnum)==0){
			printf("请输入需要修改的图书信息：\n"); 
			printf("图书名称为：");
		    scanf("%s",s->name); 
		    printf("图书编号为：");
		    scanf("%s",s->number); 
		    printf("图书作者为：");
			scanf("%s",s->writer); 
		} 
		n->next=s;
		n=s;	
	}
	n->next=NULL;
	m=p->next;
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","w");
	fclose(ft);
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	while(m!=NULL)
	{
	    fprintf(ft,"%s %s %s\n",m->name,m->writer,m->number);
		m=m->next;
	}
	fclose(ft); 
}
int  denglu (struct jiaoshi *k,FILE *fp,char name[200],char pass[200] )
{
	struct jiaoshi *n,*s,*m;
	fp=fopen("C:\\Users\\1\\Desktop\\教师信息.txt","r+");
	n=k;
	char end;
	while(s=(struct jiaoshi*)malloc(sizeof(struct jiaoshi)),end=fscanf(fp,"%s %s",s->yonghu,s->password),end!=EOF)
	{
		if(strcmp(name,s->yonghu)==0&&strcmp(pass,s->password)==0)
		{
			return 1;
		}
		n->next=s;
		n=s;
	}
	fclose(fp);	
}
