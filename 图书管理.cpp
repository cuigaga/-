#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��Ŀ�ṹ������
//ѧ����Ϣ���� 
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
//���庯�� 
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
//������ 
int main ()
{	
    struct tushu  *q;
	struct xuesheng *p;
	p=(struct xuesheng*)malloc(sizeof(struct xuesheng));
	q=(struct tushu*)malloc(sizeof(struct tushu));
	 //����ѧ��������Ϣ����+ͼ����Ŀ 
	FILE *fx,*ft;
	
	start4:
	int choose=chooseidentity();
	//ѧ������ 
	if(choose==1){                 
	int n=xueshengduan();	
	if(n==1){
		char sousuo[200];
		gets(sousuo);
		jieyue(q,ft,sousuo);
		printf("\n\n\n\n");
		printf("                    �� �� �� �� �� 0 !\n"); 
		char select[100];
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(n==2){
		char *delbook;
		delbook=borrow(p,fx);//������Ŀ����
		char *num;
		num=jieyue(q,ft,delbook);//����ͼ�� 
	    del(q,ft,num);
	    printf("\n\n\n\n");
	    printf("                    �� �� �� �� �� 0 !\n"); 
	    char select[100];
	    getchar();
	    gets(select);
		if(select[0]=='0'){
			goto start4;
		}
	}
	else if(n==3){
		char del[200]; 
		printf("             ���������ǣ�"); 
		scanf("%s",del);
		reback(p,fx,del);
		rebook(q,ft); 
		printf("\n\n\n\n");
		printf("                    �� �� �� �� �� 0 !\n");
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


	 //��ʦ���� 
	else if (choose==0){
	int m=guanliduan();
	if(m==1){
		search(q,ft);
		printf("\n\n\n\n");
		printf("                    �� �� �� �� �� 0 !\n"); 
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
	    printf("                    �� �� �� �� �� 0 !\n"); 
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
		printf("                    ������ɾ������Ŀ���:");  
		gets(delnum);
		del(q,ft,delnum);
		printf("\n\n\n\n");
		printf("                    �� �� �� �� �� 0 !\n"); 
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
		printf("                    �� �� �� �� �� 0 !\n"); 
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
     	printf("****************************�� ӭ �� �� ʹ �� ��****************************"); 
     	return 0;
	 }


	return 0;
}
//                                              ������� 
int  guanliduan()
{
	start3: 
	printf("                    1.��ѯͼ��\n"); 
	printf("                    2.����ͼ��\n"); 
	printf("                    3.ɾ��ͼ��\n"); 
	printf("                    4.��ѯ���ļ�¼\n"); 
	printf("                    5.�˳�\n"); 
	char n[10];
	gets(n);
	if(n[0]=='1'){
			printf("��������������������������ѯͼ�顪����������������������\n"); 
			return 1; 
	}
	else if(n[0]=='2'){
	        printf("����������������������������ͼ�顪����������������������\n");
	        return 2;
	}
	else if(n[0]=='3'){
		    printf("������������������������ɾ��ͼ�顪����������������������\n"); 
		    return 3;
	}
	else if (n[0]=='4'){
		    printf("��������������������������ѯ���ļ�¼������������������������\n");
			return 4; 
	}
	else if(n[0]=='5'){
	        return 5;
	}
	else {
		printf("���������������������������������롪����������������������\n") ;
		goto start3; 
	}
	 
}
//                                ѧ��ѧ���������� 
int  xueshengduan()
{
	start1:
	printf("                    1.��ѯͼ��\n"); 
	printf("                    2.����ͼ��\n");
	printf("                    3.�黹ͼ��\n");
	printf("                    4.�˳�\n"); 
	char n[10];
	gets(n);
	if(n[0]=='1'){
		printf("��������������������������ѯͼ�顪����������������������\n");
		return 1;
	}
	else if(n[0]=='2'){
		printf("����������������������������ͼ�顪����������������������\n"); 
		return 2; 
	}
	else if(n[0]=='3'){
		printf("�������������������������黹ͼ�顪����������������������\n");
		return 3;
	}
	else if(n[0]=='4'){
		return 4;
	}
	 else {
	 	printf("                              ���������룡\n\n");
	 	goto start1;
	 }
 }
 int  chooseidentity ()
{
	char se[100]={"exit"};
	printf(          "********************�� ӭ �� �� ͼ �� �� �� �� �� ϵ ͳ********************\n\n");
	char choose[200];
start2:
	printf("            ������Ա������a,������Ա������b (����λ�ַ�����ѡ��)      \n\n"); 
	printf("                             ----�˳�������exit---\n");
   gets(choose); 
   if(choose[0]=='a'){
   	printf("                �������Ϊ��������Ա��\n");          //ѧ����
   	return 1;
   }
   else if(choose[0]=='b'){
   	printf("                �������Ϊ��������Ա��\n");
   	return 0; 
   }
   else if(strcmp(choose,se)==0)
   {
   	return -1;
   }
   else {
   	printf("                              ���������룡\n\n"); 
   	goto start2;
   }
} 
char*  borrow(struct xuesheng *p,FILE *fp)
{
	static char ret[200];
	fp=fopen("C:\\Users\\1\\Desktop\\ѧ����Ϣ.txt","a");
	struct xuesheng *s,*n;
	char judge[20];
	n=p;
	printf("                  �Ƿ���н��ģ�(��y�������ģ�����������˳�)\n"); 
	while(scanf("%s",&judge),judge[0]=='y') 
	{
		s=(struct xuesheng*)malloc(sizeof (struct xuesheng));
		printf("                �����������������\n"); 
		scanf("%s",&s->name);
		fprintf(fp,"%s   ",s->name);
		printf("                �����������Ŀ��\n");
		scanf("%s",&s->book);
		fprintf(fp,"%s",s->book);
		strcpy(ret,s->book);
		fprintf(fp,"\n");
		n->next=s;
		n=s;
			printf("                  �Ƿ���н��ģ�(��y�������ģ�����������˳�)\n"); 
		}
	n->next=NULL;
	fclose(fp);
	return ret;
}
void printlist( struct xuesheng *p,FILE *fp)
{
	struct xuesheng *s;
	fp=fopen("C:\\Users\\1\\Desktop\\ѧ����Ϣ.txt","r+");
	char end;
	char tidai[200];
	s=(struct xuesheng*)malloc(sizeof(struct xuesheng));
		
	while(end=fscanf(fp,"%s %s",&s->name,&s->book),end!=EOF)
	{
     	printf("             �����ˣ�%s",s->name);
		printf("  ������Ŀ��%s\n",s->book); 	
	 } 
}
void addbook(struct tushu *q,FILE *fp)
{
	struct tushu *n,*s;
	n=q;
	fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","a");
	printf("             ������ͼ����Ϣ\n");
	printf("        ���롰ok��ֹͣ���룬�Ƿ�������룿\n");
	char a[200]; 
	int i=0;
	while(scanf("%s",&a),a[0]!='o',a[1]!='k') 
	{
		s=(struct tushu*)malloc(sizeof(struct tushu));
		printf("                 ͼ������Ϊ��");
		scanf("%s",s->name);
		fprintf(fp,"%s ",s->name);
		printf("                 ����Ϊ��");
		scanf("%s",s->writer);
		fprintf(fp,"%s ",s->writer);
		printf("                 ͼ����Ϊ��"); 
		scanf("%s",s->number);
		fprintf(fp,"%s",s->number); 
		fprintf(fp,"\n");
		n->next=s;
		n=s;
		printf("       ���롰ok��ֹͣ���룬�Ƿ�������룿\n");
	}
	n->next=NULL;
		fclose(fp);
}
void del(struct tushu *q,FILE *fp,char del[200]) 
{
	fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","r+");
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
	fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","w");
	fclose(fp); 
	fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","r+");
	while(m!=NULL)
	{
	    fprintf(fp,"%s %s %s\n",m->name,m->writer,m->number);
		m=m->next;
	}
fclose(fp);
}
void search(struct tushu *q,FILE *fp)
{
		fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","r+");
	struct tushu *n,*s;
	n=q;
	s=q->next;
	char end;
	printf("����        ����        ���\n"); 
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
	fp=fopen("C:\\Users\\1\\Desktop\\ѧ����Ϣ.txt","r+");
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
	fp=fopen("C:\\Users\\1\\Desktop\\ѧ����Ϣ.txt","w");
	fp=fopen("C:\\Users\\1\\Desktop\\ѧ����Ϣ.txt","r+");
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
	fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","a");

	char a[200]; 
	int i=0;
	printf("       �黹�������롰ok�����Ƿ���ͼ����Ҫ�黹��\n");
	while(scanf("%s",&a),a[0]!='o',a[1]!='k') 
	{
		printf("");
		s=(struct tushu*)malloc(sizeof(struct tushu));
		printf("                 ������ͼ����Ϣ  \n") ;
		printf("                 ͼ������Ϊ��");
		scanf("%s",s->name);
		fprintf(fp,"%s ",s->name);
		printf("                 ����Ϊ��");
		scanf("%s",s->writer);
		fprintf(fp,"%s ",s->writer);
		printf("                 ͼ����Ϊ��"); 
		scanf("%s",s->number);
		fprintf(fp,"%s",s->number); 
		fprintf(fp,"\n");
		n->next=s;
		n=s;
		printf("       �黹�������롰ok�����Ƿ���ͼ����Ҫ�黹��\n");
	}
	n->next=NULL;
		fclose(fp);
}
char *jieyue(struct tushu *q,FILE *fp,char name[200])
{
	static char re[200];
	fp=fopen("C:\\Users\\1\\Desktop\\ͼ����Ϣ.txt","r+");
	struct tushu *n,*s;
	n=q;
	s=q->next;
	char end;
	printf("����        ����        ���\n"); 
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














