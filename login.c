#include "os.h"
#include "login.h"

char* login() {

    User usr[MAXUSERS];
    char userIn[MAXUNAME_LEN],pwIn[MAXUPW_LEN],ans[3]={0};
    static char crnt[MAXUNAME_LEN];
    int i=0,j=0,newacc=0;

    FILE* userDB = NULL;
    userDB = fopen("userdb","a+");

    for (i=0;i<MAXUSERS;i++) {
        fscanf(userDB,"%s %s",usr[i].accName,usr[i].accPW);
//         printf("usr=%s pw=%s\n",usr[i].accName,usr[i].accPW);
    }

    printf("User:\n>>> ");
    scanf("%s",userIn);

    for (i=0;i<MAXUSERS;i++) {
        if(strcmp(usr[i].accName,userIn)==0)
        {
            printf("Account found!\nPassword:\n>>> ");
            break;
        }
        j++;
        if (j==(MAXUSERS-1)) {
            newacc=1;
            printf("New account detected!\n");
//             printf("Do you want to make a new account named '%s'? (yes/no)\n",userIn);
//             scanf("%s",ans);
//             if (strcmp(ans,"yes")!=0) {
//                 printf(":(");
//                 newacc=2;
//             }
            break;
        }
    }

    if(newacc==0) {
        do {
            scanf("%s",pwIn);
            if(strcmp(usr[j].accPW,pwIn)==0) break;
            else {
                printf("Wrong password, try again:\n>>> ");
                continue;
            }
        } while(strcmp(usr[j].accPW,pwIn)!=0);
    }

    if(newacc==1) {
        printf("Enter a new password for the account '%s'\n>>> ",userIn);
        scanf("%s",pwIn);
        fprintf(userDB,"%s\n%s\n",userIn,pwIn);
        printf("New account %s made!\n",userIn);
    }
    fclose(userDB);

    strcpy(crnt,userIn);
    return crnt;
}
