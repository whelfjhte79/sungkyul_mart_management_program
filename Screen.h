#ifndef SCREEN_H
#define SCREEN_H
#include"User_data.h"

typedef struct Identity {
	char ID[20];
	char PW[20];
}IDENTITY;
void Screen_display();
typedef struct login_user_node;
int login_check();
USER_NODE* _register();//const USER_NODE user_data
void ctrlScreen(int a);
IDENTITY login_display();
USER_NODE* search(USER_NODE *head, char* ID, char* PW);

USER_DATA global_user_data;








// 임시코드 지워야됨
void printUserInfo(USER_NODE *plist);
//임시코드 지워야됨




#endif //SCREEN_H