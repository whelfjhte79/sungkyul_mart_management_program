#ifndef REGISTER_H
#define REGISTER_H
#include<stdio.h>
#include"User_data.h"

int userRegister();
// void saveUserIdentity();   ������ �Ǵ� �κ����� Ȯ��.
USER_NODE* AddUserNode(USER_NODE *phead, USER_NODE *p, USER_DATA newNode);

USER_DATA Make_newNode();

#endif//REGISTER_H