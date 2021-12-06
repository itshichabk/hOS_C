#include "os.h"
#include "login.h"
#include "programs/programs.h"

int mainMenu(char* currentUser) {
    int choice=0;
    titleBar("MAIN MENU");
    showVer();
    printf("Current user session: %s\n", currentUser);
    printf("\nWhere do you want to go today?\n");
    printf("1) halculator\n2) hotepad\n3) hommand line\n\n4) Logout\n5) Shutdown\n\n>>> ");
    while(1) {
        scanf("%i",&choice);
        if (choice>0 && choice<=(NB_PROGRAMS+2)) break;
        printf("wtf\n>>> ");
    }
    switch (choice) {
        case 1: halc(); break;
        case 2: hotepad(); break;
        case 3: hmd(); break;
        case 4: return 2;
        case 5: exit(0);
    }
}

void titleBar(char *titleName) {
    clearSc();
    printf("==========================%s==========================\n\n",titleName);
}
