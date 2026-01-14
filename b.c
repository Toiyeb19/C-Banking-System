#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void clrscr() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct account{
    int accno, balance, withd, depo, citizen, phone;
    char name[30];
    char dob[20];
    char acc_type[15];
    char date[20];
    char pass[20];
    char dateofcreation[20];
}bank;

void menu(bank acc);
void new(bank acc);
void update(bank acc);
void view(bank acc);
void tran(bank acc);

int main(){
    bank acc;
    FILE *ptr;
    
    while(1)
    {   
        clrscr();
        printf("\n\nWelcome To The Bank \n\n");
        menu(acc);

    }
}

void menu(bank acc){
    int a;
    printf("MENU\n \ti. Create an account\n \tii. View your account details\n \tiii. Do transactions\n \tiv. Update your info\n\tv. EXIT\n Press 1 to open 'i', 2 to open 'ii', 3 to open 'iii', 4 to open 'iv', 5 to 'EXIT' : ");
    scanf("%d", &a);
    if(a==1){
        clrscr();
        new(acc);
    }
    else if(a==2){
        clrscr();
        view(acc);
    }
    else if(a==3){
        clrscr();
        tran(acc);
    }
    else if(a==4){
        clrscr();
        update(acc);
    }
    else if(a==5){
        exit(1);
    }
    else{
        printf("ERROR 303");
        exit(1);
    }
}

void new(bank acc){
    int b,phone;
    FILE *created;
    FILE *name;
    FILE *pass;
    FILE *dob;
    FILE *num;
    FILE *bal;
    FILE *cno;
    FILE *pno;
    FILE *tp;
    tp =  fopen("type.txt", "w");
    cno = fopen("citizenship_number.txt", "w");
    bal = fopen("balance.txt", "w");
    num = fopen("account_number.txt", "w");
    dob = fopen("date_of_birth.txt", "w");
    created = fopen("date.txt", "w");
    name = fopen("name.txt", "w");
    pass = fopen("password.txt", "w");
    pno = fopen("phone_number.txt", "w");
    printf("\n\n\tCreating A New Account");
    flush();
    printf("\n\nEnter today's date: ");
    gets(acc.date);
    fprintf(created, "%s", acc.date);
    fclose(created);
    flush();
    printf("\n\nPlease Enter Your Name(NO SPACES;e.g: abc_123): ");
    gets(acc.name);
    fprintf(name, "%s", acc.name);
    fclose(name);
    flush();
    printf("\nPlease Enter Your Date Of Birth: ");
    gets(acc.dob);
    fprintf(dob,"%s", acc.dob);
    fclose(dob);
    flush();
    printf("\nPlease Enter Your Account number: ");
    scanf("%d", &acc.accno);
    fprintf(num, "%d", acc.accno);
    fclose(num);
    flush();
    printf("\nPlease Enter The Amount To Deposit: $");
    scanf("%d", &acc.balance);
    fprintf(bal, "%d", acc.balance);
    fclose(bal);
    printf("\nPlease Enter Your Citizenship Number: ");
    scanf("%d", &acc.citizen);
    fprintf(cno, "%d", acc.citizen);
    fclose(cno);
    flush();
    printf("\nPlease Enter Your Phone Number: ");
    scanf("%d", &acc.phone);
    fprintf(pno, "%d", acc.phone);
    fclose(pno);
    flush();
    printf("\nType Of Account\n\t\t#Saving\n\t\t#Current\n\t\t#Fixed\n\n\tEnter Your Choice: ");
    scanf("%s", acc.acc_type);
    fprintf(tp, "%s", acc.acc_type);
    fclose(tp);
    flush();
    printf("\nMake a password for your account(NO SPACES): ");
    scanf("%s", acc.pass);
    flush();
    fprintf(pass ,"%s", acc.pass);
    fclose(pass);
    printf("\n\n\tAccount Created Successfully!");


    printf("\nEnter 1 to view your account || Enter 2 to go to menu: ");
    scanf("%d", &b);
    switch(b)
    {
        case 1:
            clrscr();
            view(acc);
        break;
        case 2:
            return;
        break;
    }
    
}


void view(bank acc){
    char password[20];
    char orpass[20];
    char  db[20], cr[20], ty[10];
    int accno, pn, cn;
    int a,w,q,x,bl;
    FILE *created;
    FILE *name;
    FILE *pass;
    FILE *dob;
    FILE *num;
    FILE *bal;
    FILE *cno;
    FILE *pno;
    FILE *tp;
    do{    
    printf("\n\n\tPlease Enter Your Password: ");
    scanf("%s", password);
    flush();
    pass = fopen("password.txt", "r");
    fscanf(pass, "%s", orpass);
    x = strcmp(password,orpass);
    fclose(pass);
    if(x == 0){
    tp =  fopen("type.txt", "r");
    cno = fopen("citizenship_number.txt", "r");
    bal = fopen("balance.txt", "r");
    num = fopen("account_number.txt", "r");
    dob = fopen("date_of_birth.txt", "r");
    created = fopen("date.txt", "r");
    name = fopen("name.txt", "r");
    pno = fopen("phone_number.txt", "r");


    printf("\n\n\tYour Account Details\n\n");
    fscanf(num, "%d", &accno);
    fclose(num);
    printf("Account number: %d\n", accno);
    fscanf(name, "%s", acc.name);
    fclose(name);
    printf("Name: %s\n", acc.name);
    fscanf(dob, "%s", db);
    fclose(dob);
    printf("Date of Birth: %s\n", db);
    fscanf(pno, "%d", &pn);
    fclose(pno);
    printf("Phone: %d\n", pn);
    fscanf(cno, "%d", &cn);
    fclose(cno);
    printf("Citizenship number: %d\n", cn);
    fscanf(created, "%s", cr);
    fclose(created);
    printf("Date on which account was created: %s\n", cr);
    fscanf(tp, "%s", acc.acc_type);
    fclose(tp);
    printf("Type of account: %s\n", acc.acc_type);
    fscanf(bal, "%d", &bl);
    fclose(bal);
    printf("Current Balance: $%d\n", bl);

    printf("Password: %s\n", orpass);
    }
    else if(x != 0){
        printf("\nPassword did not match\n");
        printf("Do you want to try again(Press 1 for yes || Press 2 for no)?\n");
        scanf("%d", &w);
        if(w!=1 && w!=2){
            printf("ERROR 505");
            exit(1);
        }

    }
    }while(w == 1);
    if(w == 2){
        printf("\nWe suggest you to make a new Account(Press 1 to make a new account || Press 2 to exit): ");
        scanf("%d", &q);
        if(q<=2 && q>0){
            switch(q){
            case 1:
                clrscr();
                new(acc);
            break;
            case 2:
                exit(1);
            break;
            }
        }
        else{
            printf("\nERROR 404");
            exit(1);
        }
    }
    printf("Press 1 to Go to menu || Press 2 to exit: ");
    scanf("%d", &a);
    if(a == 1){
        return;
    }
    else if(a == 2){
        exit(1);
    }
    else{
        printf("\n\nUNEXPECTED EXPRESSION!!");
        exit(1);
    }

}


void update(bank acc){
    FILE *pass;
    FILE *n;
    FILE *av;
    FILE *np;
    int c,x,w,p,xc,pl;
    char password[20];
    char orpass[20];
    char newname[20];
    char newpass[20];
    int pn;
    do{
        printf("\n\n\tPlease Enter Your Password: ");
        scanf("%s", password);
        flush();
        pass = fopen("password.txt", "r");
        fscanf(pass, "%s", orpass);
        x = strcmp(password,orpass);
        fclose(pass);
        if(x == 0){
            do{
                clrscr();
                printf("\n\nWhat do you want to update\n\ti.Name\n\tii.Phone Number\n\tiii.Password\nPress 1 to open 'i', 2 to open 'ii', 3 to open 'iii': ");
                scanf("%d", &c);
                if(c == 1){
                    n = fopen("name.txt", "w");
                    printf("\n\nEnter your new Name(NO SPACES): ");
                    scanf("%s", newname);
                    fprintf(n, "%s", newname);
                    fclose(n);
                    printf("\nName updated");
                    printf("\n\nPress 1 to go to menu||Press 2 to view your account||Press 3 to EXIT||Press 4 to go to update more: ");
                    scanf("%d", &xc);
                    flush();
                    switch (xc)
                    {
                        case 1:
                            return;
                        break;
                        case 2:
                            clrscr();
                            view(acc);
                        break;
                        case 3:
                            exit(1);
                        break;
                    }
                    if(xc <= 0 && xc > 4){
                        printf("\n\nERROR 404");
                        exit(1);
                    }
                }
                if(c == 2){
                    av = fopen("phone_number.txt", "w");
                    printf("\n\nEnter the new Phone Number: ");
                    scanf("%d", &pn);
                    fprintf(av, "%d", pn);
                    fclose(av);
                    printf("\n\nPress 1 to go to menu||Press 2 to view your account||Press 3 to EXIT||Press 4 to update more: ");
                    scanf("%d", &xc);
                    switch (xc)
                    {
                        case 1:
                            return;
                        break;
                        case 2:
                            clrscr();
                            view(acc);
                        break;
                        case 3:
                            exit(1);
                        break;
                    }
                    if(xc != 1 && xc != 2 && xc != 3 && xc != 4){
                        printf("\n\nERROR 404");
                        exit(1);
                    }

                }
                if(c == 3){
                    np = fopen("password.txt", "w");
                    printf("\n\nEnter the new password: ");
                    scanf("%s", newpass);
                    fprintf(np, "%s", newpass);
                    fclose(np);
                    printf("\n\nPress 1 to go to menu||Press 2 to view your account||Press 3 to EXIT||Press 4 to update more: ");
                    scanf("%d", &xc);
                    switch (xc)
                    {
                        case 1:
                            return;
                        break;
                        case 2:
                            clrscr();
                            view(acc);
                        break;
                        case 3:
                            exit(1);
                        break;
                    }
                    if(xc != 1 && xc != 2 && xc != 3 && xc != 4){
                        printf("\n\nERROR 404");
                        exit(1);
                    }
                }
            }while(xc == 4);

        }
        if(x != 0){
            printf("\n\nPASSWORD DID NOT MATCH!\n");
            printf("Do you want to try again YES/NO(Press 1 for yes||Press 2 for no): ");
            scanf("%d", &w);
            if(w != 1 && w != 2){
                printf("\n\nERROR 404");
                exit(1);
            }
        }
    }while(w==1);
    if(w == 2){
        printf("\nWe suggest you to make a new Account(Press 1 to make a new account || Press 2 to exit): ");
        scanf("%d", &p);
        switch (p)
        {
            case 1:
                clrscr();
                new(acc);
            break;
            case 2:
                exit(1);    
            break;    
        }
        if(p != 1 && p != 2){
            printf("\n\nERROR 404");
            exit(1);
        }
    }        
}



void tran(bank acc){
    char npass[20];
    char orpass[20];
    char con[20];
    int a,b,c,olbal,shbal,xc,ny,p,w;
    int zx = 0;
    int wdraw,withd;
    FILE *ptr;
    FILE *bal;
    FILE *nbal;
    FILE *bbal;
    FILE *wd;
    FILE *abc;
    FILE *qwe;
    do{
    printf("\n\n\tEnter Your Password: ");
    scanf("%s", &npass);
    flush();
    ptr = fopen("password.txt", "r");
    fscanf(ptr, "%s", orpass);
    a = strcmp(npass,orpass);
    fclose(ptr);
    do{
        if(a == 0){
            clrscr();
            printf("\n\nWhat do you want to do\n\ti.Deposit Money\n\tii.Withdraw Money\n(Press 1 for 'i'||Press 2 for 'ii'): ");
            scanf("%d", &b);
            flush();
            if(b != 1 && b != 2){
                printf("\n\nERROR 404");
                exit(1);
            }
            else if(b == 1){
                clrscr();
                printf("\n\nDeposit\n\tEnter the amount you want to Deposit: $");
                scanf("%d", &c);
                flush();
                printf("\n\nAmount Deposited");
                bal = fopen("balance.txt", "r");
                fscanf(bal, "%d", &olbal);
                fclose(bal);
                nbal = fopen("balance.txt", "w");
                fprintf(nbal, "%d", c + olbal);
                fclose(nbal);
                bbal = fopen("balance.txt", "r");
                fscanf(bbal, "%d", &shbal);
                fclose(bbal);
                printf("\n\tCurrent Balance: $%d", shbal);
                printf("\n\nPress 1 to go to menu||Press 2 to view your account||Press 3 to EXIT||Press 4 to update your info: ");
                scanf("%d", &xc);
                    switch (xc)
                    {
                        case 1:
                            return;
                        break;
                        case 2:
                            clrscr();
                            view(acc);
                        break;
                        case 3:
                            exit(1);
                        break;
                    }
                    if(xc != 1 && xc != 2 && xc != 3 && xc != 4){
                        printf("\n\nERROR 404");
                        exit(1);
                    }
            }
            else if(b==2){
                do{
                    clrscr();
                    zx = 2;
                    wd = fopen("balance.txt","r");
                    fscanf(wd, "%d", &withd);
                    fclose(wd);
                    printf("\n\nWithdraw\n\tEnter the amount you want to withdraw: $");
                    scanf("%d", &wdraw);
                    flush();    
                    if(wdraw > withd){
                        printf("\nINSUFFICIENT BALANCE");
                        zx = 1;
                        printf("\nPress Any Key To Continue: ");
                        scanf("%s", con);
                        flush();
                    }
                }while(zx == 1);
                if(wdraw <= withd){
                    qwe = fopen("balance.txt", "w");
                    fprintf(qwe, "%d", withd - wdraw);
                    fclose(qwe);
                    abc = fopen("balance.txt", "r");
                    fscanf(abc, "%d", &ny);
                    fclose(abc);
                    printf("\n\tCurrent Balance: $%d", ny);
                     printf("\n\nPress 1 to go to menu||Press 2 to view your account||Press 3 to EXIT||Press 4 to update you info: ");
                    scanf("%d", &xc);
                    switch (xc)
                    {
                        case 1:
                            return;
                        break;
                        case 2:
                            clrscr();
                            view(acc);
                        break;
                        case 3:
                            exit(1);
                        break;
                    }
                    if(xc != 1 && xc != 2 && xc != 3 && xc != 4){
                        printf("\n\nERROR 404");
                        exit(1);
                    }

                }
            }

        }
        
    }while(xc==4);
    if(a != 0){
            printf("\n\nPASSWORD DID NOT MATCH!\n");
            printf("Do you want to try again YES/NO(Press 1 for yes||Press 2 for no): ");
            scanf("%d", &w);
            if(w != 1 && w != 2){
                printf("\n\nERROR 404");
                exit(1);
            }
        }
    }while(w == 1);
    if(w == 2){
        printf("\nWe suggest you to make a new Account(Press 1 to make a new account || Press 2 to exit): ");
        scanf("%d", &p);
        switch (p)
        {
            case 1:
                clrscr();
                new(acc);
            break;
            case 2:
                exit(1);    
            break;    
        }
        if(p != 1 && p != 2){
            printf("\n\nERROR 404");
            exit(1);
        }
    }
}