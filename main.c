#include <stdio.h>
#include <stdlib.h>// for the exit in the case 6.
#include <time.h>

char Username[20];
int deposit_amount, amount = 10000;
int account_number;
int With_amount;
int transfer_amount;

// Function declarations
void menu();
void deposit_money();
void WithDraw_money();
void Transfer_money();
void Account_detail();
void Transaction_detail();
void last_detail();
void Exit();

void divider()
 {
    for(int i = 0; i < 50; i++)
    {
       printf("-");
    }
     
 }


int main(void)
{
    int choice;

    printf("Enter your name:\n");
    fgets(Username, sizeof(Username), stdin);

    printf("\nEnter your Account Number :\n");
    scanf("%d", &account_number);

    while(1)
    {
       menu();
       printf("\nEnter your choice : \n");
       scanf("%d", &choice);
       switch (choice)
       {
       case 1:
          deposit_money();
          break;
       case 2:
          WithDraw_money();
          break;
       case 3:
          Transfer_money();
          break;
       case 4:
          Account_detail();
          break;
       case 5:
          Transaction_detail();
          break;
       case 6:
          last_detail();
          exit(0);
       default:
          printf("Invalid choice\n");
          break;
        }
    }
    return 0;
}

// Function definitions

void menu()
{
    divider();
    printf("\nMain Menu\n");
    divider();
    printf("\n1.Deposit money\n");
    printf("2. Withdraw money\n");
    printf("3. Transfer money\n");
    printf("4. Account detail\n");
    printf("5. Transaction detail\n");
    printf("6. Exit\n");
    divider();

}

void deposit_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr =fopen("Account.rtf", "a");
    printf("\nDepositing money\n");
    divider();
    printf("\nEnter the amount : ");
    scanf("%d", &deposit_amount);

    amount += deposit_amount;
    printf("Money deposited\n");
    printf("Current balance : %d\n", amount);
    // la file dans laquelle cette fonction va ecrire est la file ptr).
    fprintf(ptr, "Rs%d has been deposited to your account.\n ", deposit_amount);//pour ecrire des information dans la file en question est pas dans le terminale.
    fprintf(ptr, "Date / time of the transaction %s\n", ctime(&tm));

    //je ferme la file
    fclose(ptr);

    // Now the console will wait
    // for a key to be pressed
    getchar();
}


void WithDraw_money()
{
    time_t tm;
    time(&tm);
    FILE *fp =fopen("Account.rtf", "a");
    printf("\nWithdraw money\n");
    divider();
    printf("\nEnter the amount :\n"); // on ne met pas \n pour que le input soit collet a la premier phrase.
    scanf("%d", &With_amount);
    // on vient enlever la somme du with_amount au amount.
    amount -= With_amount;
    printf("Money WithDrawy\n");
    printf("Current balance %d\n", amount);
    // la file dans laquelle cette fonction va ecrire est la file ptr).
    fprintf(fp, "Rs%d has been  withdraw  to your account.\n ", With_amount);//pour ecrire des information dans la file en question est pas dans le terminale.
    fprintf(fp, "Date / time of the transaction %s\n", ctime(&tm));

    //je ferme la file
    fclose(fp);
    
    // Now the console will wait
    // for a key to be pressed
    getchar();
}

void Transfer_money()
{
    time_t tm;
    time(&tm);
    int ac_no;//account number.
    FILE *ptr =fopen("Account.rtf", "a");
    printf("\nTransfer money\n");
    divider();
    printf("\nEnter the amount : \n");
    scanf("%d", &transfer_amount);

    printf("Enter the account number in which you want to money\n");
    scanf("%d", &ac_no);

    //checking if there are enought money in the amount.
    if (amount < transfer_amount) {
        printf("You don't have sufficient balance.\n");
    } else {
        // Le bloc else est exécuté si la condition du if n'est pas satisfaite
        amount -= transfer_amount;
        printf("Money has been transferred\n");
        printf("Current balance : %d", amount);
        fprintf(ptr, "Rs%d has been  transferred from your account  to  %d.\n ", transfer_amount, ac_no);//pour ecrire des information dans la file en question est pas dans le terminale.
        fprintf(ptr, "Date / time of the transaction %s\n", ctime(&tm));
    }    
    //je ferme la file
    fclose(ptr);
    printf("Press any key to continue ......\n");

    // Now the console will wait
    // for a key to be pressed
    getchar();


}

void Account_detail()
{
    printf("\nACCOUNT DETAIL\n");
    divider();
    for(int i = 0; i < 50; i++)
    {
       printf("-");
    }
    printf("\nName : %s\n", Username);
    printf("Account No. : %d\n", account_number);
    printf("Total balance =  %d\n", amount);
    printf("Press any key.....");

    // Now the console will wait
    // for a key to be pressed
    getchar();

}

void Transaction_detail()
{
    printf("\nTransaction details\n");
    for(int i = 0; i < 50; i++)
    {
       printf("-");
    }
    FILE *ptr;
    ptr = fopen("Account.rtf", "r");

    char c = fgetc(ptr);
    if (c == EOF) {
        printf("\nNo recent transaction\n"); //the file reached end nothing to read.
    } else {
        printf("\nTransaction Details\n");
        while(c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
        
    }

    getchar();


}

void last_detail()
{
    printf("\nLast details\n");
    for(int i = 0; i < 50; i++)
    {
       printf("-");
    }
    printf("\nName : %s\n", Username);
    printf("Account No. : %d\n", account_number);
    printf("Total balance =  %d\n", amount);
    printf("Press any key.....");

    // Now the console will wait
    // for a key to be pressed
    getchar();

    
}



