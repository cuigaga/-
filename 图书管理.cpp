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
int  guanliduan();
int  xueshengduan();
void search(struct tushu *q,FILE *fp);
int  chooseidentity ();
char* borrow(struct xuesheng *p,FILE *fp,char num[200],char xuename[200]);
void printlist(struct xuesheng *p,FILE *fp);
void addbook(struct tushu *q,FILE *fp,FILE *ft);
char *del(struct tushu *q,FILE *fp,char del[100],char find[200]);
int  reback(struct xuesheng *p,FILE *fp,char num[200],char yonghu[200],int jude );
int  reback1(struct xuesheng *p,FILE *fp,char num[200],char yonghu[200],int jude );
void rebook(FILE *fp,FILE *ft,char num[200],char name[200]);
int jie(struct tushu *q,FILE *fp,char name[200]); 
void yanzheng(struct jieyue *q,FILE *ft,char num[200],char name[200]);
int judge(FILE *ft ,char num[200],char name[200]);
void delnum(struct jieyue *l,FILE *fp,char dell[200],char deln[200]);
void change(struct tushu *p,FILE *ft,FILE *fp,char findname[200],char findnum[200]) ;
int  denglu (struct jiaoshi *j,FILE *fp,char name[200],char pass[200] );
int  xueshengdenglu (struct jiaoshi *j,FILE *fp,char name[200],char pass[200] );
int findplus (FILE *fp,char find[200],int sum);
void choosefind(FILE *ft,struct tushu *q);
int findn(struct tushu *q,FILE *fp,char name[200]);
char * retname(struct tushu *q,FILE *fp,char name[200],char ret[200]);
int findstudent(struct xuesheng *p,FILE *fp,char name[200]);
void zhuce(FILE *fp);
void insert (char *p,FILE *fp1);
void regret (char find[200]);
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
	fp=fopen("C:\\Users\\1\\Desktop\\学生用户.txt","a+");
	fclose(fp);
	//创建文件，以免使用“r+”打开文件时报错 
	start4:
	int choose=chooseidentity();
	//学生操作 
	if(choose==1){       
		printf("                            请输入用户名：");
		char xueyong[200];
		gets(xueyong);
		printf("                              请输入密码：");
		char pass[200];
		gets(pass); 
		int pan=xueshengdenglu(k,fp,xueyong,pass);
		if(pan!=1){
			printf("\n\n\n                         用户名或密码错误！！！\n\n\n\n");
			goto start4; 
	}
	else printf("\n\n                             登录成功！\n\n\n");           
	int n=xueshengduan();	
	if(n==1){
		char sousuo[200],ret[200];
		int judg=0,jud=0,judu=0;
		printf("                当前为精确检索，输入plus进入模糊检索:") ;
		char plus[200];
		gets(plus);
		if(strcmp(plus,"plus")==0)
		{
				printf("               您已进入模糊检索 ！！ 请最少输入两个字节：\n");
		    printf("                           请输入需要检索的信息:");
		    gets(sousuo);
		    printf("\n\n\n\n");
		    int n;
		    findplus(fp,sousuo,n);
		    judu=findn(q,ft,sousuo);
		}
		else{ 
		printf("                  请输入需要检索的信息:");
		gets(sousuo);
		jud=jie(q,ft,sousuo);
	}
		if(jud!=-1||judu!=-1){
		printf("\n\n");
		printf("                  请输入需要借阅的图书编号:(取消借阅输入esc)");
		char num [200];
		gets(num);
		if(strcmp(num,"esc")!=0){ 
		int panduantushu=findn(q,fp,num);
		if(panduantushu!=-1){
		borrow(p,fx,num,xueyong);
		del(q,ft,num,ret);
		yanzheng(l,ft,num,ret);
		judg++;
	}else printf("                               请重新确认信息！ \n");	
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
		printf("               需要归还的图书编号为：");
		char backnum[200];
		gets(backnum); 
		printf("               需要归还的图书名称为：");
		gets(name); 
		int n=0;
		n=judge(ft,backnum,name); 
		if(n==1){
			int jude=0;
			jude=reback1(p,fx,backnum,xueyong,jude);
			if(jude!=0){
			reback(p,fx,backnum,xueyong,jude);
		    rebook(fp,ft,backnum,name); 
		    delnum(l,ft,backnum,name);
		    printf("\n\n\n\n");
		    judg++;
		}else printf("\n\n\n                   归 还 信 息 错 误！!\n\n\n\n");
	}else printf("\n\n\n                   归 还 信 息 错 误！\n\n\n\n"); 
	printf("                         退 出 请 输 入 0 !\n");
	 char select[100];
		if(judg!=0)
		{
			getchar();
		}
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
	else printf("\n\n                             登录成功！\n\n\n");
	start2: 
	int m=guanliduan();
	if(m==1){
		choosefind(fp,q);
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start2;
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
			goto start2;
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
			goto start2;
		}
	}
	else if(m==4)
	{
		int jud=0;
		char findname[200];
		char findnum[200];
		printf("请输入需要修改的图书信息：");
		gets(findname);
		int judg=jie(q,ft,findname); 
		if(judg!=-1){
		printf("请输入图书编号：");
		gets(findnum);
		char ret1[200];
		retname(q,ft,findnum,ret1);
		change(q,ft,fp,ret1,findnum);
		jud++;
	}
	 	printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
		if(jud!=0){
			getchar();
		}
	    gets(select);
		if(select[0]=='0'){
			goto start2;
		}
}
	else if(m==5)
	{
		printlist(p,fx);
		printf("                             请输入查询的信息：");
		char find[200];
		gets(find); 
		findstudent(p,fp,find);
		printf("\n\n\n\n");
		printf("                             退 出 请 输 入 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start2;
		}
	}
	else if(m==0)
	{
		printf("                 导入教师账户输入1，学生账户输入2:");
		char get[200];
		gets(get);
		if(strcmp(get,"2")==0){
		zhuce(fp);
	}else if(strcmp(get,"1")==0){
		printf("                      请输入绝对路径：");
		char path[200];
		gets(path); 
		char *p;
		p=path;
		insert(p,fp);
	}
		goto start2;
	 } 
	else if(m==7)
	{
		goto start4;
	}	
	else if(m==6)
	{
		printf("                     请输入需要重新导入的图书信息：");
		char findpp[200];
		gets(findpp); 
		regret(findpp);
		goto start2;
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
	printf("                            0.注册账号\n"); 
	printf("                            1.查询图书\n"); 
	printf("                            2.增加图书\n"); 
	printf("                            3.删除图书\n");
	printf("                            4.查改图书\n");
	printf("                            5.查询借阅记录\n"); 
	printf("                            6.重新导入图书\n"); 
	printf("                            7.退出\n"); 
	char n[10];
	gets(n);
	if(n[0]=='0'){
			printf("——————————————注册账号————————————\n"); 
			return 0; 
	}
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
	else if (n[0]=='6'){
		    printf("—————————————重新导入图书————————————\n");
			return 6; 
	}
	else if(n[0]=='7'){
		
	        return 7;
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
char*  borrow(struct xuesheng *p,FILE *fp,char num[200],char xuename[200])
{
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","a");
		printf("                请输入借阅人姓名："); 
		char name[200];
		scanf("%s",name);
		char xueshengnum[200];
		getchar();
		fprintf(fp,"%s ",name);
		fprintf(fp,"%s ",xuename);
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
	char end,panduan[200];
	int i=0;
	end=fscanf(fp,"%s",panduan);
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
		fprintf(fp,"%s\n",s->number); 
		fprintf(ft,"%s\n",s->number);
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
int  reback(struct xuesheng *p,FILE *fp,char num[200],char yonghu[200],int jude )
{
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	struct xuesheng *n,*s,*m;
	char end;
	n=p;
	while(s=(struct xuesheng*)malloc(sizeof(struct xuesheng)),end=fscanf(fp,"%s %s %s",s->name,s->num,s->book),end!=EOF){
		if(strcmp(s->book,num)!=0){
		n->next=s;
		n=s;
		printf("%s %s %s\n",s->name,s->book,s->num);
	}else if(strcmp(s->book,num)==0&&strcmp(s->num,yonghu)==0)jude++;
		
	}
	n->next=NULL;
	m=p->next;
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
int  reback1(struct xuesheng *p,FILE *fp,char num[200],char yonghu[200],int jude )
{
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r");
	struct xuesheng *n,*s,*m;
	char end;
	n=p;
	while(s=(struct xuesheng*)malloc(sizeof(struct xuesheng)),end=fscanf(fp,"%s %s %s",s->name,s->num,s->book),end!=EOF){
		if(strcmp(s->book,num)!=0){
		n->next=s;
		n=s;
	}else if(strcmp(s->book,num)==0&&strcmp(s->num,yonghu)==0)jude++;
		
	}
	n->next=NULL;
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
		if(strcmp(s->name,name)==0||strcmp(s->number,name)==0||strcmp(s->writer,name)==0){
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
int findn(struct tushu *q,FILE *fp,char name[200])
{
	static char re[200];
	int jud=0; 
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s;
	n=q;
	s=q->next;
	char end;
	s=(struct tushu*)malloc(sizeof(struct tushu));
	while(end=fscanf(fp,"%s %s %s",s->name,s->writer,s->number),end!=EOF){
		if(strcmp(s->name,name)==0||strcmp(s->number,name)==0||strcmp(s->writer,name)==0){
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
	fclose(ft);
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
void change(struct tushu *p,FILE *ft,FILE *fp,char findname[200],char findnum[200]) 
{
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	fp=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","r+");
	struct tushu *n1,*s1,*m1,*s2;
	n1=p;
	char end;
	while(s1=(struct tushu*)malloc(sizeof(struct tushu)),end=fscanf(ft,"%s %s %s",s1->name,s1->writer,s1->number ),end!=EOF){
		if(strcmp(s1->name,findname)==0&&strcmp(s1->number,findnum)==0){
			printf("请输入需要修改的图书信息：\n"); 
			printf("图书名称为：");
		    scanf("%s",s1->name); 
		    printf("图书编号为：");
		    scanf("%s",s1->number); 
		    printf("图书作者为：");
			scanf("%s",s1->writer); 
		} 
		n1->next=s1;
		n1=s1;	
	}
	n1->next=NULL;
	m1=p->next;
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","w");
	fp=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","w");
	fclose(ft);
	fclose(fp); 
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	fp=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","r+");
	while(m1!=NULL)
	{
	    fprintf(ft,"%s %s %s\n",m1->name,m1->writer,m1->number);
	    fprintf(fp,"%s %s %s\n",m1->name,m1->writer,m1->number); 
		m1=m1->next;
	}
	fclose(ft);
	fclose(fp); 
}
int  denglu (struct jiaoshi *k,FILE *fp,char name[200],char pass[200] )
{
	struct jiaoshi *n,*s,*m;
	fp=fopen("C:\\Users\\1\\Desktop\\教师信息.txt","r+");
	n=k;
	char end;
	int c=0;
	while(s=(struct jiaoshi*)malloc(sizeof(struct jiaoshi)),end=fscanf(fp,"%s %s",s->yonghu,s->password),end!=EOF)
	{
		if((strcmp(name,s->yonghu)==0&&strcmp(pass,s->password)==0))
		{
			return 1;
		}
		c++;
		n->next=s;
		n=s;
	}
	fclose(fp);	
	if(c==0&&(strcmp(name,"123456789")==0&&strcmp(pass,"000000")==0))
	{
		return 1;
	}
}
int  xueshengdenglu (struct jiaoshi *k,FILE *fp,char name[200],char pass[200] )
{
	struct jiaoshi *n,*s,*m;
	fp=fopen("C:\\Users\\1\\Desktop\\学生用户.txt","r+");
	n=k;
	char end,xingming[200];
	while(s=(struct jiaoshi*)malloc(sizeof(struct jiaoshi)),end=fscanf(fp,"%s %s %s",s->yonghu,s->password,xingming),end!=EOF)
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
int findplus (FILE *fp,char find[200],int sum)
{
	sum=0;
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	char name[200],num[200],writer[200],end;
	int m;
	m=strlen(find)/2;
	int m2=strlen(find);  
		printf("  请选择查询的信息类型：1为中文(中文只可搜索书名与作者)，2为数字（只可搜索书编号），3为英文:"); 
		char jude[200];
		gets(jude);
	while(end=fscanf(fp,"%s %s %s",name,writer,num),end!=EOF)
	{
		int namelen=strlen(name)/2;
		int wordlen=strlen(name); 
		int k=strlen(writer)/2;
		int klen=strlen(writer);
		int s=strlen(num);
		int num1=0,num2=0,num3=0,num4=0,num5=0;	
		 if(strcmp(jude,"1")==0){
		for(int i=0;i<namelen*2-2;i=i+2)
		{
			for(int j=0;j<m*2;j+=2){
			if ((name[i]==find[j])&&(name[i+2]==find[j+2])){
						num1++;
		}
	}
}
if(num1==m-1)
{
	printf("书名：%-15s 作者：%-15s 编号：%-15s\n",name,writer,num);
	sum++;
}

        	for(int i=0;i<k*2-2;i=i+2)
		{
			int c=0;
			for(int j=0;j<m*2;j+=2){
			if (writer[i]==find[j]&&writer[i+2]==find[j+2]){
					num2++;
		}
	}
}
if(num2==m-1)
{
			printf("书名：%-15s 作者：%-15s 编号：%-15s\n",name,writer,num);
			sum++;
}


//搜索数字 



}else if(strcmp(jude,"2")==0) {
        	for(int i=0;i<s-1;i++)
		{
			int c=0;
			for(int j=0;j<m2-1;j++){
			if (num[i]==find[j]&&num[i+1]==find[j+1]){
					num3++;
		}
	}
}
if(num3==m2-1){
		printf("书名：%-15s 作者：%-15s 编号：%-15s\n",name,writer,num);
		sum++;
}
  }
  else if(strcmp(jude,"3")==0){
  		for(int i=0;i<wordlen-1;i=i+1)
		{
			for(int j=0;j<m2-1;j+=1){
			if ((name[i]==find[j])&&(name[i+1]==find[j+1])){
						num4++;
		}
	}
}
if(num4==m2-1)
{
	printf("书名：%-15s 作者：%-15s 编号：%-15s\n",name,writer,num);
	sum++;
}

        	for(int i=0;i<klen-1;i=i+1)
		{
			int c=0;
			for(int j=0;j<m2-1;j+=1){
			if (writer[i]==find[j]&&writer[i+1]==find[j+1]){
					num5++;
		}
	}
}
if(num5==m2-1)
{
			printf("书名：%-15s 作者：%-15s 编号：%-15s\n",name,writer,num);
			sum++;
}
  }
}
	fclose(fp);
	return sum;
}
void choosefind(FILE *ft,struct tushu *q)
{
	
	printf("\n\n        模糊选择请输入1，普通检索请输入2,遍历书库请输入3\n"); 
	printf("                          直接输入回车退出 \n"); 
	char num[200];
	gets(num);
	if(strcmp(num,"\n")!=0){
	char name[200]; 
	if(strcmp(num,"1")==0)
	{
			printf("                            请最少输入两个字符：\n");
			printf("                            请输入需要检索的信息：");
			gets(name);
		    printf("\n\n\n");
		    int sum;
			sum=findplus(ft,name,sum);
		    printf("\n\n                          库存有%d本 ",sum);
		    printf("\n\n\n");
	}
	else if(strcmp(num,"2")==0)
	{
			printf("                             请输入需要检索的信息：");
			gets(name);
			jie(q,ft,name); 
		    printf("\n\n\n");
	}
	else if(strcmp(num,"3")==0)
	{
		search(q,ft);
	 } 
}
}
char* retname(struct tushu *q,FILE *fp,char name[200],char ret[200])
{
	static char re[200];
	int jud=0; 
	fp=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *n,*s;
	n=q;
	char end;
	while(s=(struct tushu*)malloc(sizeof(struct tushu)),end=fscanf(fp,"%s %s %s",&s->name,s->writer,s->number),end!=EOF){
		if(strcmp(s->number,name)==0){
			strcpy(ret,s->name);
			break;
	}
		n->next=s;
		n=s;
	}
	fclose (fp);
}
int findstudent(struct xuesheng *q,FILE *fp,char name[200])
{
	static char re[200];
	int jud=0; 
	fp=fopen("C:\\Users\\1\\Desktop\\学生信息.txt","r+");
	struct xuesheng *n,*s;
	n=q;
	s=q->next;
	char end;
	printf("学生        学号        编号\n"); 
	s=(struct xuesheng*)malloc(sizeof(struct xuesheng));
	while(end=fscanf(fp,"%s %s %s",&s->name,s->book,s->num),end!=EOF){
		if(strcmp(s->book,name)==0||strcmp(s->name,name)==0||strcmp(s->num,name)==0){
		printf("%-10s %-10s %-10s\n",s->name,s->book,s->num);
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
void zhuce(FILE *fp){
	fp=fopen("C:\\Users\\1\\Desktop\\学生用户.txt","a+");
	char name[200],pass[200],xingming[200];
	printf("学生的信息为：\n");
	printf("学生的学号为：");
	gets(name);
	printf("学生的密码为："); 
	gets(pass);
	printf("学生的姓名为: ");
	gets(xingming);
	fprintf(fp,"%s %s %s\n",name,pass,xingming); 
	printf("                            注册成功！\n\n\n\n"); 
	fclose(fp);
}
void insert (char *p,FILE *fp1)   
{
	fp1=fopen("C:\\Users\\1\\Desktop\\教师信息.txt","a+");
	FILE *fp2;
	fp2=fopen(p,"r");
	char name[200],pass[200],end;
	while(end=fscanf(fp2,"%s %s",name,pass),end!=EOF)
	{
		fprintf(fp1,"% s %s\n",name,pass);
	}
	fclose(fp1);
	fclose(fp2);
	printf("                               导入成功！\n\n\n");
}
void regret (char find[200])
{
	FILE *fp;
	FILE *ft;
	fp=fopen("C:\\Users\\1\\Desktop\\总图书信息.txt","r");
	ft=fopen("C:\\Users\\1\\Desktop\\图书信息.txt","r+");
	struct tushu *q,*n,*s,*m;
	q=(struct tushu *)malloc(sizeof(struct tushu));
	n=q;
		int c=0;
			while(m=(struct tushu *)malloc(sizeof(struct tushu)),fscanf(ft,"%s %s %s",m->name,m->writer,m->number)!=EOF)
		{
			if(strcmp(m->number,find)==0)
			c++;
		}
		if(c==0){
			int d=0;
	while(s=(struct tushu *)malloc(sizeof(struct tushu)),fscanf(fp,"%s %s %s",s->name,s->writer,s->number)!=EOF)
	{
		if(strcmp(s->name,find)==0||strcmp(s->writer,find)==0||strcmp(s->number,find)==0&&c==0)
		{
			d++;
			printf("书名：%-15s 作者：%-15s 编号：%-15s\n",s->name,s->writer,s->number);
			printf("                 输入1重新导入此书（其他键则继续搜索下一本）：");
			char j[200];
			gets(j);
			if(strcmp(j,"1")==0)
			{
				fprintf(ft,"%s %s %s\n",s->name,s->writer,s->number);
				printf("                           导入成功！\n"); 
			 } 
		}
	}
	if(d==0)
	{
		 printf("                           未查找到该图书！！！\n"); 
	}
	printf("\n\n\n\n");
}else printf("                        已经存在此图书！！！\n\n\n\n"); 
	fclose(fp);
	fclose(ft);
}
