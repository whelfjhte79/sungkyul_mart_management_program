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








// �ӽ��ڵ� �����ߵ�
void printUserInfo(USER_NODE *plist);
//�ӽ��ڵ� �����ߵ�




#endif //SCREEN_H