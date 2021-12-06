#include "os.h"
#include "login.h"

void login() {
	User usr[MAXUSERS];
	int i=0,j=0,cmp=0,anscmp=0;
    char userIn[MAXUNAME_LEN]={0},pwIn[MAXUPW_LEN]={0},ans[3];
	FILE* userDB = NULL;
    userDB = fopen("userdb","a+");

    for (i=0;i<MAXUSERS;i++) {
        fgets(usr[i].accName,MAXUNAME_LEN,userDB);
        usr[i].accName[strcspn(usr[i].accName, "\n")] = 0;
        //printf(" (%s) ",usr[i].accName);
        fgets(usr[i].accPW,MAXUPW_LEN,userDB);
        usr[i].accPW[strcspn(usr[i].accPW, "\n")] = 0;
        //printf(" (%s) ",usr[i].accPW);
    }

	printf("User:\n>>> ");
	fgets(userIn,MAXUNAME_LEN,stdin);

    for (i=0;i<MAXUSERS;i++) {
        cmp = strcmp(usr[i].accName,userIn);
        if (cmp==0) break;
        j++;
    }

    if (cmp!=0) {
        printf("New account spotted.\nDo you want to make a new account called '%s'? (yes/no)\n>>> ",userIn);
        printf("%s",userIn);
        scanf("%s",ans);
        anscmp=strcmp(ans,"yes");
        if (anscmp==0) {
            printf("Create a password for your new account:\n>>> ");
            scanf("%s",pwIn);
            fprintf(userDB,"%s",userIn);
        }
        else printf("ayo wtf");
    }

    else {
        do {
            printf("Password:\n>>> ");
            fgets(pwIn,MAXUPW_LEN,stdin);
            cmp=strcmp(usr[j].accPW,pwIn);
            if (cmp==0) break;
            printf("\nWrong password, please try again.\n");
        } while(1);
    }

    printf("Welcome!\n");
}
