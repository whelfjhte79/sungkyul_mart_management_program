#ifndef LOGINUSER_H
#define LOGINUSER_H

#include"Product.h"
#include"User_data.h"
/* TODO: ȸ��� ������ �ŷ� ���� ������ �ϴ� ���� ������ ����ؾߵ�
         �ƴ϶�� buying, refund�� ������ �����ؾ���.
*/

#define INIT_USER_MONEY 100000
void userDisplay(USER_NODE* login);
void ctrlUserMenu(int button, USER_NODE *login);

 
PRODUCT* buying(PRODUCT *shopping_list_head,USER_NODE *login);             // �ٷ� ���� ��ٱ��Ͽ� ������ ������ ���
void refund();  //ȯ�� �߰����
void logout();       //    ���� ȭ������ ��ȯ

void meet(PRODUCT *plist);
void vegetables(PRODUCT *plist);
void stationery(PRODUCT *plist);
void drinks(PRODUCT *plist);
void snacks(PRODUCT *plist);
void side_dishes(PRODUCT *plist);
////////////////////////////
char* Mid(char txt[], int start, int count);







#endif // LOGINUSER_H