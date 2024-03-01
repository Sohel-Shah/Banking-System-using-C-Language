#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Info
{
    char name;
    long mbl;
    long amt;
    int ourPS;
};
void main()
{
    FILE *p;
    char file_name[10];
    struct Info obj1;
    long damt, wamt;
    int ps;
    int choice;
    clrscr();
    printf("1 For New Account :");
    printf("\n2 For Old Account :");
    printf("\n\n Enter : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
	printf("\nFor New Account :\n\n");
	printf("Enter your name : ");
	getch();
	getch();
	// scanf("%c",&obj.name);
	obj1.name = getchar();
	obj1.name = getchar();
	printf("\nEnter Your Mobile number : ");
        scanf("%ld", &obj1.mbl);
        printf("\nHow many amount you want to deposite at Account : ");
        scanf("%ld", &obj1.amt);
        printf("\nSet your password : ");
        scanf("%d", &obj1.ourPS);
        getch();
        clrscr();
        printf("Registation Done Successfully...");
        getch();
        clrscr();
        file_name[0] = obj1.name;
        strcat(file_name, ".txt");
        p = fopen(file_name, "w");
        fwrite(&obj1, sizeof(obj1), 1, p);
        fclose(p);
        printf("\nThan You...!!!\n");
        break;

    case 2:
        printf("Enter Your Name as per Account Form :");
        getch();
        getch();
        // scanf("%c", &obj.name);
        file_name[0] = getchar();
        file_name[0] = getchar();

        strcat(file_name, ".txt");

        p = fopen(file_name, "r");
        printf("\n\nOpend file is %s", file_name);
        fread(&obj1, sizeof(obj1), 1, p);
        fclose(p);
        printf("\n\n Data are : \nName\t:\t%c \tMobile\t:\t%ld\nAmount\t:\t%ld \nPW\t:\t%d\n\n", obj1.name, obj1.mbl, obj1.amt, obj1.ourPS);
        break;
    }
    getch();
    clrscr();
    printf("Welcome to Your Bank Mr./Mrs. : %c", obj1.name);
    printf("\n\nNow you are Ready for Banking !");

l1:
l3:
    getch();
    clrscr();
    printf("Enter Your Password :");
    scanf("%d", &ps);
    clrscr();

    if (ps == obj1.ourPS)
    {
        printf("\n\nSelect one of the option :");
        printf("\n1 for Balance check");
        printf("\n2 for Deposite");
        printf("\n3 for withdrawl");
        printf("\n4 for Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getch();
        clrscr();

        switch (choice)
        {
        case 1:

            printf("\nYou select balance check :");
            printf("\n\nYour Bank Balance is %ld", obj1.amt);
            break;

        case 2:
            printf("\nYou Select Deposite Option : ");
            printf("\n\nHow many amount you want to deposit :");
            scanf("%ld", &damt);
            obj1.amt = obj1.amt + damt;
            getch();
            clrscr();
            printf("Deposite Successfully");
            break;
        case 3:
            printf("\nYou select withdrawl option : ");

        l2:
            printf("\n\nHow many amount you want to withdrawl :");
            scanf("%ld", &wamt);

            if (wamt > obj1.amt)
            {
                            printf("sufficient fund not available!....");
                            getch(); 
                            clrscr();
                            goto l2;
            }

            obj1.amt = obj1.amt - wamt;
            getch();
            clrscr();
            printf("Successfully withdrawl...");
            break;

        case 4:

            printf("Thank You...!!!");
            goto l5;
        }
        getch();
        clrscr();
        printf("\n\nDo want to continue the banking!... ");
        printf("\n1 for Yes\n2 for No\nEnter: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            goto l3;
        }
        else if (choice == 2)
        {
            goto l4;
        }
    }
    else
    {
        printf("\n\nIn-Valid Password !");
        goto l1;
    }
l4:
l5:
    printf("\n\nThank you for banking with us!... ");

    p = fopen(file_name, "w");
    fwrite(&obj1, sizeof(obj1), 1, p);
    fclose(p);
    getch();
}
