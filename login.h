#define MAXUSERS 100
#define MAXUNAME_LEN 15
#define MAXUPW_LEN 30

typedef struct User User;

struct User {
	char accName[15];
	char accPW[30];
	int accType;
};
