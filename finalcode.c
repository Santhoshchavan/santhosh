 #include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
typedef struct //USED FOR THE LOGIN
{
    char username[30];
    char password[30];
}log;
struct person
{
    char name[35];
    char address[50];
     char father_name[35];
     char nick_name[30];
    long int mble_no;
    char gender[8];
    char mail[100];
    char aadhar_no[20];

    }; //USED FOR THE ADDING OF THE DETAILS
int choice;
int o;
char iname[30]="admin"; //THIS IS THE DEFAULT PASSWORD
void main_menu();
void login_menu();
void menu3();
void menu4();
void n_user_menu();
void user_login_menu();
void admin_menu();
char admin_pass[10]="Admin123";
char pass[10];
void got();//main usecase part starting
void start();
void back();
void addrecord();
void listrecord();
void modify_the_contacts();
void deleterecord();
void searchrecord();
void view_users();

int main()
{
	system("color 5f");//THIS IS FOR THE PINK COLOR
	printf("process is starting");
	login_menu(); // CALLING THE LOGIN PAGE
	return 0;
}
void login_menu()
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t HOME\t\t\n\n");
    
    printf("\n\n\t\t\t CHOOSE AN OPTION(1/2/3):\t\t\t\n\n");
    
    printf("\t\t\t\n\n %c%c%c 1.NEW USER\t\t\n\n",176,176,176);
   
    printf("\t\t\t\n\n %c%c%c 2.LOGIN \t\t\n\n",176,176,176);

    printf("\t\t\t\n\n %c%c%c 3.ADMIN\t\t\n\n",176,176,176);
    
    printf("Enter : ");
    
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:n_user_menu();
               break;
        case 2:/*user_login_menu();*/menu3();
               break;
        case 3:admin_menu();
			   break;
//		case 4:login_menu();
//			   break;
		default:
                system("cls");
                printf("\nEnter 1 to 3 only");
                printf("\n Enter your key");
                getch();
//	 main_menu();

    }
}

void menu3()
{
    system("cls");
    // draw_rect();
    // draw_rect2();
    //head();
    // move(70,15);
    printf("\t\t\t\n\nCHOOSE AN OPTION(1/2):\t\t\t\n\n");
    // move(72,17);
    printf("\t\t\n%c%c%c Login\t\t\n",177,177,177);
    // move(72,19);
    printf("\t\t\n%c%c%c go back\t\t\n",177,177,177);
    int ch;
    // move(72,21);
    printf("Enter : ");
    // move(81,21);
    fflush(stdin);
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:fflush(stdin);
        user_login_menu();
        break;
        case 2:login_menu();
    }
}
void n_user_menu()
{
    system("cls");
    int value=1;
   
    log a;
    
    printf("\t\t\n\nUSER REGISTER");
    
    printf("\t\t\n\nEnter User_Id :\t\t\n ");
   
    printf("\t\t\n\nEnter Password :\t\t\n");
    
    fflush(stdin);
    scanf("%s",a.username);
   
    char ch;
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        a.password[i]=ch;
        printf("*");
        i++;
    }
    FILE *fp;
    if(value==1)
    {
       // fp=fopen("n_user_Login.bin","ab+");
	   fp=fopen("n_user_Login.txt","w+");

    }
  
    fwrite(&a,sizeof(log),1,fp);
    fclose(fp);
    printf("\t\t\t\n\nUSER REGISTERED SUCCESSFULLY");
    Sleep(2000);
    fflush(stdin);
    login_menu();
}
void user_login_menu()
{
    system("cls");
    
	// menu3(); // CONFORMING USER TO LOGIN OR GO BACK
     printf("\t\t\t\n\nUSER LOG_IN\t\t\t\n\n");
     log a;
     
     printf("\t\t\nEnter User_Id :\t\t\n ");
     
     printf("\t\t\nEnter Password : \t\t\n");
    
     fflush(stdin);
     scanf("%s",a.username);
    
     char ch;
     int i=0;
     while(1)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        a.password[i]=ch;
        printf("*");
        i++;
    }
    FILE *fp;
    log b;
    int k=0;
    if(k==0)
    {
        //fp=fopen("users_Login_data.bin","rb");
		fp=fopen("n_user_Login.txt","r+");
    }
  
    while(fread(&b,sizeof(log),1,fp))
    {
        if(!(strcmp(a.username,b.username))&&!(strcmp(a.password,b.password)))
        {
           
            printf("\t\t\t\n\nUser identified");
            fclose(fp);
            fflush(stdin);
            Sleep(1000);
            if(k==0)
            {
                menu4();
            return;
            }
         
        }
    }
   
    printf("\t\t\t\n\nUser unidentified");
    
    printf("Enter1 to re-try or 2 to goback");
    int ch1;
    
    printf("Enter : ");
   
    fflush(stdin);
    scanf("%d",&ch1);
    if(ch1==1)
    {
        login_menu();
    }
    else
    {
        menu3();
    }
}
void main_menu()
{
	printf(" LETS START WITH CONTACTZ MANAGEMENT OPENING MAIN MENU");
	  system("cls");
printf("\t\t**********WELCOME TO Contactz_Management*************");

printf("\n\n\t\t\t  HOME_MENU\t\t\n\n");
printf("\t 1.Add New contact  \t 2.List contacts   \t 3.Delete contact \n\t 4.Modify_the_contact \t 5.Search the contact\t 6.Exit to Home");

switch(getch())
{
    case '1': addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': deleterecord();
    break;
    case '4': modify_the_contacts();
    break;
    case '5': searchrecord();
    break;
    case '6': exit(0);
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

main_menu();  //AGAIN CALLING THE MAIN main_menu
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\n Enter name: ");
        got(p.name);
        printf("\nEnter the address: ");
        got(p.address);
        printf("\nEnter father name: ");
        got(p.father_name);
        printf("\nEnter nick name: ");
        got(p.nick_name);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("Enter gender:");
        got(p.gender);
        printf("\nEnter e-mail:");
         got(p.mail);
        printf("\n Enter Aadhar no:");
        got(p.aadhar_no);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\n Record saved");

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    main_menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAdress=%s\nFather name=%s\nnick name=%s\nMobile no=%ld\ngender=%s\nE-mail=%s\nAadhar no=%s",p.name,p.address,p.father_name,p.nick_name,p.mble_no,p.gender,p.mail,p.aadhar_no);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\n Enter any key");
 getch();
    system("cls");
main_menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of person to search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nnick name:%s\nMobile no:%ld\ngender:%s\nE-mail:%s\nCitision no:%s",p.name,p.address,p.father_name,p.nick_name,p.mble_no,p.gender,p.mail,p.aadhar_no);
    }
        else
        printf("file not found");

}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
main_menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opaning error");
		else

        {


		printf("Enter CONTACT'S NAME:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf(" RECORD DELETED SUCCESSFULLY... ");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
main_menu();
}

void modify_the_contacts()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO Modify_the_contacts:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter name:");
                    got(s.name);
                    printf("\nEnter the address:");
                    got(s.address);
                    printf("\nEnter father name:");
                    got(s.father_name);
                    printf("\nEnter nick name:");
                    got(s.nick_name);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter gender:");
                    got(s.gender);
                    printf("\nEnter e-mail:");
                    got(s.mail);
                    printf("\nEnter Aadhar__ no\n");
                    got(s.aadhar_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	main_menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
void admin_menu()
{
	printf("\t\t\t\n\nlaunching admin");
	printf("\t\t\nENTER YOUR ADMIN PASSWORD");
	scanf("%s",pass);
	//printf("%s is password",pass);
	if(strcmp(pass,admin_pass)==0)
	{
		printf("ADMIN LOGGED IN SUCESSFULLY");
		printf("\t\t\n1.REGISTER NEW USER:");
		printf("\t\t\n2.VIEW USERS AND THEIR PASSWORDS");
		printf("\t\t\n3.LOGIN AS USER:");
		//printf("\t\t\n4.Go Back");
		printf("\t\t\nENTER YOUR COMMAND:");
		scanf("%d",&o);
		switch(o)
		{
			case 1:n_user_menu();
			break;
			case 2:view_users();
			break;
			case 3:menu3();
			break;
			default:
			printf("enter numbers 1 to 3 only:");
		}

	}
	else
	{
		printf("NOT A REGISTERED USER");
	}
}
void menu4()
{
	printf("accessing all the project features");
	main_menu();
}
void view_users()
{
	printf("these are all the users");
}
