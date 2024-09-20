#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void create();
void display();
void append();
void noofrec();
void search();
void update();
void del();
int main()
{
int ch,i=0;
char username[20],password[20],c;
clrscr();
printf("\n*******************Admin login*******************\n");
printf("\tUsername:");
scanf("%s",&username);
printf("\n\tPassword:");
while(1)
{
c=getch();
if(c==13)
{
password[i]='\0';
break;
}
else
{
password[i]=c;
i++;
printf("*");
}
}
if(strcmp(username,"shivani")==0)
{
if(strcmp(password,"12345")==0)
{
printf("\n\n\t\tLogin success....\n\n");
printf("\n\t\t*****************\n");
printf("\t\tWelcome %s",username);
printf("\n\t\t*****************\n");
printf("\nWhat would you like to do?...\n") ;

do
{
printf("\n1-->Create student info");
printf("\n2-->Display student info");
printf("\n3-->Append student info");
printf("\n4-->check No of records");
printf("\n5-->Search a record");
printf("\n6-->Update student info");
printf("\n7-->Remove student info");
printf("\n0-->Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
display();
break;
case 3:
append();
break;
case 4:
noofrec();
break;
case 5:
search();
break;
case 6:
update();
break;
case 7:
del();
break;
}
}while(ch!=0);
}
else
printf("\n\tInvalid password...");
}
else
printf("\n\tInvalid Username..");

getch();
return 0;
}
typedef struct student
{
int rno;
char name[30];
float per,att_cls,tot_cls;
}student;
void create()
{
student *s;
FILE *fp;
int n,i,j;
printf("\nEnter the no of students:");
scanf("%d",&n);
s=(student*)calloc(n,sizeof(student));
fp=fopen("stud.txt","w");
for(i=0;i<n;i++)
{
printf("\nEnter the Roll no:");
scanf("%d",&s[i].rno);
printf("\nEnter Name:");
scanf("%s",&s[i].name);
printf("\nNo of classes attended:");
scanf("%f",&s[i].att_cls);
printf("\nNo of classes held:");
scanf("%f",&s[i].tot_cls);
s[i].per=(s[i].att_cls/s[i].tot_cls)*100;
printf("\nAttendeance percentage:%f",s[i].per);
fwrite(&s[i],sizeof(student),1,fp);
}
fclose(fp);
}
void display()
{
student s1;
FILE *fp;
fp=fopen("stud.txt","r");
printf("\n*****************************Student info**************************\n");
while(fread(&s1,sizeof(student),1,fp))
{
printf("\n\tStudent Roll no\t\tStudent name\tStudent %");
printf("\n\t%d\t\t\t%s\t\t%f\n\n",s1.rno,s1.name,s1.per);
}
printf("\n********************************************************************\n");
fclose(fp);
}
void append()
{
student *s;
FILE *fp;
int n,i,j,att_cls,tot_cls;
printf("\nEnter the no of students:");
scanf("%d",&n);
s=(student*)calloc(n,sizeof(student));
fp=fopen("stud.txt","a");
for(i=0;i<n;i++)
{
printf("\nEnter the Roll no:");
scanf("%d",&s[i].rno);
printf("\nEnter Name:");
scanf("%s",&s[i].name);
printf("\nNo of classes attended:");
scanf("%f",&s[i].att_cls);
printf("\nNo of classes held:");
scanf("%f",&s[i].tot_cls);
s[i].per=(s[i].att_cls/s[i].tot_cls)*100;
printf("\nAttendeance percentage:%f",s[i].per);
fwrite(&s[i],sizeof(student),1,fp);
}
fclose(fp);
}
void noofrec()
{
student s1;
int n;
FILE *fp;
fp=fopen("stud.txt","r");
fseek(fp,0,SEEK_END);
n=ftell(fp)/sizeof(student);
printf("\n\nNo of records =%d\n",n);
fclose(fp);
}
void search()
{
student s1;
FILE *fp;
int j,rno,found=0;
fp=fopen("stud.txt","r");
printf("\nEnter the Roll no to search:");
scanf("%d",&rno);
while(fread(&s1,sizeof(student),1,fp))
{
if(s1.rno==rno)
{
found=1;
printf("\nStudent Roll no:%d\nStudent name:%s",s1.rno,s1.name);
printf("\nStudent attendance : %f%",s1.per);
}
}
if(!found)
printf("\nRecord not found\n");

fclose(fp);
}
void update()
{
student s1;
FILE *fp,*fp1;
int j,rno,found=0,att_cls,tot_cls;
fp=fopen("stud.txt","r");
fp1=fopen("temp.txt","w");
printf("\nEnter the Roll no to update:");
scanf("%d",&rno);
while(fread(&s1,sizeof(student),1,fp))
{
if(s1.rno==rno)
{
found=1;
printf("\nEnter new name:");
scanf("%s",&s1.name);
printf("\nNo of classes attended:");
scanf("%f",&s1.att_cls);
printf("\nNo of classes held:");
scanf("%f",&s1.tot_cls);
s1.per=(s1.att_cls/s1.tot_cls)*100;
printf("\nAttendeance percentage:%f",s1.per);

}
fwrite(&s1,sizeof(student),1,fp1);
}
fclose(fp);
fclose(fp1);

if(found)
{
fp1=fopen("temp.txt","r");
fp=fopen("stud.txt","w");
while(fread(&s1,sizeof(student),1,fp1))
{
fwrite(&s1,sizeof(student),1,fp);
}
fclose(fp);
fclose(fp1);
}
else
printf("\nRecord not found\n");
}
void del()
{
student s1;
FILE *fp,*fp1;
int j,rno,found=0;
fp=fopen("stud.txt","r");
fp1=fopen("temp.txt","w");
printf("\nEnter the Roll no to remove:");
scanf("%d",&rno);
while(fread(&s1,sizeof(student),1,fp))
{
if(s1.rno==rno)
{
found=1;
}
else

fwrite(&s1,sizeof(student),1,fp1);
}
fclose(fp);
fclose(fp1);

if(found)
{
fp1=fopen("temp.txt","r");
fp=fopen("stud.txt","w");
while(fread(&s1,sizeof(student),1,fp1))
{
fwrite(&s1,sizeof(student),1,fp);
}
fclose(fp);
fclose(fp1);
}
else
printf("\nRecord not found\n");
}



