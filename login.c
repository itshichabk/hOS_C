/*
 * hOS LOGIN SYSTEM 0.1
 *
 * Checks input username in local users database file (userdb)
 * - If user exists in database, ask for user's password.
 * - If not, ask for a new password and add new account to database.
 * NOTE: userdb is nothing but a text file with usernames followed by their respective passwords for now, encryption will be added later on.
 *
 * Username is then returned in main program and gets displayed in the main menu.
*/

#include "os.h"
#include "login.h"

char* login() {

    User usr[MAXUSERS];     // User is a structure (see login.h)
    char userIn[MAXUNAME_LEN],pwIn[MAXUPW_LEN],ans[3]={0};     // ans is the answer to the "Make new account?" question, unused for now
    static char crnt[MAXUNAME_LEN];     // current user value that will be returned
    int i=0,newacc=0;   // if account is new, then newacc = 1, or else newacc = 0

    FILE* userDB = NULL;
    userDB = fopen("userdb","a+");     // opens userdb file

    for (i=0;i<MAXUSERS;i++) {
        fscanf(userDB,"%s %s",usr[i].accName,usr[i].accPW);     // adds each user and password from userdb to users array
    }

    printf("User:\n>>> ");      // asks for username
    scanf("%s",userIn);

    for (i=0;i<MAXUSERS;i++) {      // looks for input username in array to check if it already exists
        if(strcmp(usr[i].accName,userIn)==0)
        {
            printf("Account found!\nPassword:\n>>> ");
            break; //   as soon as input username is found, break and ask for password
        }
        if (i==(MAXUSERS-1)) {
            newacc=1;
            printf("New account detected!\n");  // This part below makes userIn's value empty for some reason after scanf line.
//             printf("Do you want to make a new account named '%s'? (yes/no)\n",userIn);
//             scanf("%s",ans);
//             if (strcmp(ans,"yes")!=0) {
//                 printf(":(");
//                 return(0);
//             }
            break;
        }
    }

    if(newacc==0) {     // if account already exists, keep asking for corresponding password until it's correct
        do {
            scanf("%s",pwIn);
            if(strcmp(usr[i].accPW,pwIn)==0) break;
            else {
                printf("Wrong password, try again:\n>>> ");
                continue;
            }
        } while(strcmp(usr[i].accPW,pwIn)!=0);
    }

    if(newacc==1) {     // if account is new, ask for new password, and save new username and password to userdb
        printf("Enter a new password for the account '%s'\n>>> ",userIn);
        scanf("%s",pwIn);
        fprintf(userDB,"%s\n%s\n",userIn,pwIn);
        printf("New account %s made!\n",userIn);
    }
    fclose(userDB);

    strcpy(crnt,userIn);    // copies current username userIn to static variable crnt so it doesn't return null
    return crnt;
}
