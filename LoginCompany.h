#ifndef LOGINCOMPANY_H
#define LOGINCOMPANY_H

#include"Product.h"

void register_goods();           
void register_account();             //������ ��ǰ������ ��ü������ �ʿ伺����.
void blacklist();               // Ž�� ����. ���������� ���� ����.
void classification_goods(); // ����Ҷ� ����ڰ� ���� ����, ��ä ��� ���.
void companyDisplay(int *level);         //ȸ�� ȭ��
void logout();
void ctrlCompanyMenu(int ctrl,int *level);
/* LoginUser.h�� ��ǰ ���� ĭ�� ������ �����ؾ���. */



#endif //LOGINCOMPANY_H