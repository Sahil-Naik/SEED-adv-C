#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_USERNAME 20
#define MAX_PASSWORD 20

typedef struct{
    char USERNAME[MAX_USERNAME];
    char PASSWORD[MAX_PASSWORD];
} USER;

int main(){
    int N;
    int flag;
    USER user[5];
    char username[MAX_USERNAME], password[MAX_PASSWORD];

    int choice;
    choice=0;
    N=0;
    flag=0;

    do {
        printf("\nChoose an Option:");
        printf("\n1 = Register");
        printf("\n2 = Login");
        printf("\n3 = Exit");
        printf("\nChoose: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter new username: ");
                scanf("%s", user[N].USERNAME);
                fflush(stdin);

                printf("Enter new password: ");
                scanf("%s", user[N].PASSWORD);
                fflush(stdin);

                N=N+1;
                break;

            case 2:
                flag = 0;
                printf("\nEnter username: ");
                scanf("%s", username);
                fflush(stdin);

                printf("Enter password: ");
                scanf("%s", password);
                fflush(stdin);

                for (int i=0; i<=N; i++){
                    if (strcmp(user[i].USERNAME, username) == 0 && strcmp(user[i].PASSWORD, password) == 0){
                        flag=1;
                        break;
                    }
                }

                if (flag==1){
                    printf("\nSuccessful login!\n");
                } else {
                    printf("\nLogin failed!\n");
                }

                break;

            case 3:
                printf("\nExiting...");
                choice=3;
                break;
        }

    } while(choice!=3);

    return 0;
}
