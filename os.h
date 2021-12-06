#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OSVER_MAJ "0"
#define OSVER_MIN "1"
#define OSVER_BUILDDATE ""__DATE__" "__TIME__""

void showVer();
void clearSc();
char* login();
int mainMenu(char* currentUser);
