#ifndef USER_DATA_H
#define USER_DATA_H



typedef struct USER_DATA {
	char name[20];
	char ID[20];
	char PW[2];
	int level;
	int money;
}USER_DATA;
typedef struct login_user_node {
	USER_DATA data;
	struct login_user_node *next;
	struct login_user_node *prev;
}USER_NODE;

USER_NODE *head;                         //��� ������
void saveUserIdentity(); //����ü��� �����ǰԽ���

#endif 