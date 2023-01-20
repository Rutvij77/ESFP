#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int page()
{
    printf("====================================================================================================\n");
    printf("                                         GANPAT UNIVERTSITY\n");
    printf("                           BRANCH - COMPUTER SCIENCE AND ENGINEERING (CBA)\n");
    printf("                                             BATCH - 11\n");
    printf("                                       ENROLLMENT NO. - CBA01\n");
    printf("                                       PROJECT TITLE - PID403\n");
    printf("                                           ESFP-I PROJECT\n");
    printf("====================================================================================================");
}

char rutvij[6], qwertyuiop[10];

//functions declaration
int login();
int print_menu();

int main()
{
    page();
    login();
    print_menu();
    return 0;
}

//login function
int login()
{
    printf("\n\nEnter Username: ");
    scanf("%s", rutvij);

    printf("Enter Password: ");
    scanf("%s", qwertyuiop);
 
    if(strcmp(rutvij, "rutvij") == 0 && strcmp(qwertyuiop, "qwertyuiop") == 0)
    {
        printf("\nLogin Successful!\n\n");
    }
    else
    {
        printf("\nWrong username or password!\n\n");
        login();
    }
}

char stuName[20][30];
int presentAttendance[20]={0};
int absentAttendance[20]={0};
int indexNumber=0;
void checkAttendance()
{
    int i;
    printf("\n         Total Present | Total Absent\n");   
    for ( i = 0; i < indexNumber; i++)
    {        
        printf("%s",stuName[i]);
        printf("              %d             %d\n",presentAttendance[i],absentAttendance[i]);                           
    }    
}
void addStudent()
{
    int i,num,add;   
    if (indexNumber==0)
    {
        printf("Enter how many employee you want to add: ");
        fflush(stdin);
        scanf("%d",&num);
        for ( i = 0; i < num; i++)
        {        
            printf("\nEnter %d employee name to add in attendance ragister: ",i+1);    
            fflush(stdin);
            gets(stuName[i]);  
            indexNumber++;              
        }           
    }
    else
    {        
        printf("Enter how many employees you want to add: ");
        fflush(stdin);
        scanf("%d",&num);
        add=indexNumber+num;
        for ( i = indexNumber; i < add; i++)
        {        
            printf("\nEnter %d employee name to add in attendance register: ",i+1);    
            fflush(stdin);
            gets(stuName[i]);  
            indexNumber++;              
        }
    }            
}
void removeStudent()
{
    char name[30];
    printf("Enter employee name to remove: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < indexNumber; i++)
    {
        if (strcmp(name,stuName[i])==0)
        {          
            for (int j = i; j < indexNumber; j++)
            {
                strcpy(stuName[j],stuName[j+1]);  
                presentAttendance[i]=presentAttendance[i+1];
                absentAttendance[i]=absentAttendance[i+1];
            }     
            indexNumber--;
            printf("\n%s employee is removed\n",name);
            break;                    
        }
        else if(i==indexNumber-1)
        {
            printf("This name is not exits\n");
        }       
    }        
}
void takeAttendance()
{
    int i;
    char ch;
    printf("\nEnter Y for present and N for absent\n");
    for ( i = 0; i < indexNumber; i++)
    {
        repeate:
        printf("%d. %s is present: ",i+1,stuName[i]);
        fflush(stdin);
        scanf("%c",&ch);
        if (ch=='Y'||ch=='y')
        {
            presentAttendance[i]+=1;
        }
        else if (ch=='N'||ch=='n')
        {            
            absentAttendance[i]+=1;                                                    
        } 
        else
        {
            printf("Invalid character Try again\n");
            goto repeate;
        }              
    }    
}
int print_menu()
{
    int choose;
    do
    {
        printf("\n**********Main Menu***********\n");
        printf("Enter 1 for add employee\n");
        printf("Enter 2 for take attendance\n");
        printf("Enter 3 for check attendance\n");
        printf("Enter 4 for remove employee\n");
        printf("Enter 5 for exit\n");
        printf("Please choose any menu: ");
        fflush(stdin);
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            addStudent();
            break;        
        case 2:
            takeAttendance();
            break;        
        case 3:
            checkAttendance();
            break;        
        case 4:
            removeStudent();
            break;        
        case 5:
            exit(0);
            break;        
        }
    } while (choose!=5);
    
}