#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

void insertbook()
{
    int bookid,bookid1,price,price1,quantity=1,quantity1=1,flag=0,z,clag=0;
    char title[50],title1[50],author[50],author1[50];
    FILE *fp,*fp1,*fp2;
    fp=fopen("booksinfo.txt","a+");

    cout<<"enter bookid,title,author,price\n";
    cin>>bookid>>title>>author>>price;

    while(fscanf(fp,"%d %s %s %d %d",&bookid1,title1,author1,&price1,&quantity)!=EOF)
    {
        if(bookid==bookid1&&strcmp(author,author1)==0&&strcmp(title,title1)==0&&price==price1)
        {
            cout<<"similar book record already exist.\n";
            cout<<"then also you want to insert it?\n";
            cout<<"1.Yes\n";
            cout<<"2.No\n";
            cout<<"enter your choice:\n";
            cin>>z;
            if(z==1)
            {
                quantity1=quantity+1;
                clag=1;

            }
            else if(z==2){
                return;
            }
        }
       else if(bookid==bookid1)
        {
           cout<<"bookid already exist enter other bookid\n";
           return;
        }

    }
    fclose(fp);
    fp=fopen("booksinfo.txt","a+");
    fp1=fopen("book1.txt","w");
    fp2=fopen("book2.txt","w");
    while(fscanf(fp,"%d %s %s %d %d",&bookid1,title1,author1,&price1,&quantity)!=EOF)
    {
        flag=1;
        if(bookid>bookid1)
            {
               fprintf(fp1,"%d %s %s %d %d\n",bookid1,title1,author1,price1,quantity);


            }
            else if(bookid<bookid1){
                fprintf(fp2,"%d %s %s %d %d\n",bookid1,title1,author1,price1,quantity);
            }
    }

    if(flag==0)
    {
        fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity1);
    }
    fclose(fp1);
    fclose(fp2);
    fp1=fopen("book1.txt","r");
    fp2=fopen("book2.txt","r");
    fclose(fp);
    fp=fopen("booksinfo.txt","w");
    while(fscanf(fp1,"%d %s %s %d %d",&bookid1,title1,author1,&price1,&quantity)!=EOF)
    {
        fprintf(fp,"%d %s %s %d %d\n",bookid1,title1,author1,price1,quantity);

    }
    if(clag==1)
    {
        fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity1);
    }
    else{
    fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity1);
    }
   while(fscanf(fp2,"%d %s %s %d %d",&bookid1,title1,author1,&price1,&quantity)!=EOF)
    {
        fprintf(fp,"%d %s %s %d %d\n",bookid1,title1,author1,price1,quantity);

    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("book1.txt");
    remove("book2.txt");
    cout<<"book inserted successfully\n";
}

void ViewbookRecord()
{
    int bookid,price,quantity,flag=0;
    char title[50],author[50];

    FILE *fp;
    fp=fopen("booksinfo.txt","r");
    cout<<"******************************************************\n";
    cout<<"bookid"<<" "<<"title"<<" "<<"author"<<"   "<<"price"<<"   "<<"quantity"<<"\n";
    while(fscanf(fp,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
    {
        flag=1;
    printf("%3d %7s %7s %7d %7d\n",bookid,title,author,price,quantity);
    }
    if(flag==0)
    {
    cout<<"LIST IS EMPTY\n";
    }
    cout<<"******************************************************\n";

}
void DeleteBookRecord(int bid)
{
    int bookid,price,quantity1,quantity,clag=0,flag=0;
    char title[50],author[50];
    FILE *fp,*fp1;
    fp=fopen("booksinfo.txt","r");
    fp1=fopen("bookcopy.txt","w");
    while(fscanf(fp,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
    {

            /*if(bookid==bid&&quantity>1)
             {
                quantity1=quantity-1;
                clag=1;
                break;
             }*/
            if(bookid==bid)
             {
                 flag=1;
             }

    }
    fclose(fp);
    if(flag==1)
    {
        fp=fopen("booksinfo.txt","r");
        while(fscanf(fp,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
        {
            if(bid==bookid&&quantity>1)
            {
                quantity1=quantity-1;
             fprintf(fp1,"%d %s %s %d %d\n",bookid,title,author,price,quantity1);
            }
            else if(bid==bookid&&quantity==1);
            else
            {
                fprintf(fp1,"%d %s %s %d %d\n",bookid,title,author,price,quantity);
            }
        }
        fclose(fp);
        fp=fopen("booksinfo.txt","w");
        fclose(fp1);
        fp1=fopen("bookcopy.txt","r");
        while(fscanf(fp1,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
        {
          fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity);
        }
    }
    else
    {
        cout<<"invalid bookid\n\n";
    }

fclose(fp);
fclose(fp1);
remove("bookcopy.txt");
cout<<"deleted successfully\n";
}
void updateBookRecord(int bid)
{
    int bookid,price,flag=0,clag=0,price2,price3=0,x,y=0,quantity1=1,quantity=0,quantity3=0;
    char title[50],author[50],title2[50],author2[50],title3[50]={'\0'},athor3[50]={'\0'};
    FILE *fp,*fp1,*fp2;
    fp=fopen("booksinfo.txt","r");
    fp1=fopen("bookcopy.txt","w");
    while(fscanf(fp,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
    {
        if(bid==bookid)
        {clag=1;
         break;
        }
    }
    fclose(fp);
    if(clag==1)
        {
       fp=fopen("booksinfo.txt","r");
        while(fscanf(fp,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
        {
            if(bid==bookid)
            {

                strcpy(title2,title);
                strcpy(author2,author);
                price2=price;
                quantity1=quantity;

            }
            else
            {
                fprintf(fp1,"%d %s %s %d %d\n",bookid,title,author,price,quantity);
            }
        }

        fclose(fp);
        fp=fopen("booksinfo.txt","w");
        fclose(fp1);
        fp1=fopen("bookcopy.txt","r");
        while(fscanf(fp1,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
        {
          fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity);
        }
    }
    else
    {
        cout<<"invalid bookid\n\n";
        return;
    }

    fclose(fp);
    fclose(fp1);
    remove("bookcopy.txt");

    cout<<"which data you want to change:\n";
    cout<<"1.bookid\n";
    cout<<"2.title\n";
    cout<<"3.author\n";
    cout<<"4.price\n";
    cout<<"5.quantity\n";
    cout<<"enter your choice:\n";
    cin>>x;
    if(x==1)
    {
       cout<<"enter new bookid\n";
       cin>>y;
    }
    else if(x==2)
    {
        cout<<"enter new title name\n";
        cin>>title3;

    }
    else if(x==3)
    {
        cout<<"enter new author\n";
        cin>>athor3;
    }
    else if(x==4)
    {
        cout<<"enter new price\n";
        cin>>price3;
    }
    else if(x==5)
    {
        cout<<"enter new quantity\n";
        cin>>quantity3;
    }
    fp=fopen("booksinfo.txt","a+");
    fp1=fopen("book1.txt","w");
    fp2=fopen("book2.txt","w");
    while(fscanf(fp,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
    {
        flag=1;
        if(y!=0)
        {

        if(y>bookid)
            {
               fprintf(fp1,"%d %s %s %d %d\n",bookid,title,author,price,quantity);

            }
            else {
                fprintf(fp2,"%d %s %s %d %d\n",bookid,title,author,price,quantity);
            }
        }
        else
        {

        if(bid>bookid)
            {
               fprintf(fp1,"%d %s %s %d %d\n",bookid,title,author,price,quantity);

            }
            else if(bid<bookid){
                fprintf(fp2,"%d %s %s %d %d\n",bookid,title,author,price,quantity);
            }

        }

    }

    fclose(fp1);
    fclose(fp2);
    fp1=fopen("book1.txt","r");
    fp2=fopen("book2.txt","r");
    fclose(fp);
    fp=fopen("booksinfo.txt","w");
    while(fscanf(fp1,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
    {
        fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity);

    }

    if(y!=0)
    {
    fprintf(fp,"%d %s %s %d %d\n",y,title2,author2,price2,quantity);
    }

    else if(title3[0]!='\0')
    {

        fprintf(fp,"%d %s %s %d\n",bid,title3,author2,price2,quantity1);

    }

    else if(athor3[0]!='\0')
    {
        fprintf(fp,"%d %s %s %d %d\n",bid,title2,athor3,price2,quantity1);
    }
   else if(price3!=0)
    {
        fprintf(fp,"%d %s %s %d %d\n",bid,title2,author2,price3,quantity1);
    }
    else if(quantity3!=0)
    {
        fprintf(fp,"%d %s %s %d %d\n",bid,title2,author2,price2,quantity3);
    }

   while(fscanf(fp2,"%d %s %s %d %d",&bookid,title,author,&price,&quantity)!=EOF)
    {
        fprintf(fp,"%d %s %s %d %d\n",bookid,title,author,price,quantity);

    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("book1.txt");
    remove("book2.txt");
    cout<<"book record updated successfully\n";
}

int main()
{
    int x,y;
    while(1)
    {
    system("cls");
    cout<<"BOOK RECORD MANAGEMENT\n\n";
    cout<<"*****************************\n";
    cout<<"1.insert book\n";
    cout<<"2.view book record\n";
    cout<<"3.update book record\n";
    cout<<"4.Delete book record\n";
    cout<<"5.exit\n";
    cout<<"*****************************\n";
    cout<<"enter your choice:\n";
    cin>>x;
    switch(x)
    {
    case 1:
        insertbook();
        getch();
        break;

    case 2:
        ViewbookRecord();
        getch();
        break;
    case 3:
        cout<<"enter book id to be updated:\n";
        cin>>y;
        updateBookRecord(y);
        getch();
        break;
    case 4:
        cout<<"enter book id to be deleted:\n";
        cin>>y;
        DeleteBookRecord(y);
        getch();
        break;
    case 5:
        exit(0);
        break;

    default:
        cout<<"invalid choice Enter right choice\n";
        getch();

    }
    }


}
