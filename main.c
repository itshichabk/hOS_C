#include "os.h"
#include "login.h"

int main() {
	start:
        clearSc();
        showVer();
        char* currentUser = login();

    if (mainMenu(currentUser) == 2) goto start;
}

void showVer() {
        printf("hOS version "OSVER_MAJ"."OSVER_MIN" ("OSVER_BUILDDATE")\n");
}

void clearSc() {
        printf("\e[1;1H\e[2J");
}
