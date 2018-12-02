#include"Screen.h"
#include"User_data.h"
#include"LoginCompany.h"
#include"LoginUser.h"
#include"Register.h"
#include"account.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/////////////////////////////////////
#include"MacroCollection.h"
//////////////////////////////////

enum{SUCCESS,FAILURE};
enum{TRUE,FALSE};
enum{NOTHING,REGISTER,LOGIN,ACCOUNT,PRINT,END}; // PRINT�� �ӽ�

void Screen_display() {
	int ctrl;
	system("cls");
	printf("\n\n\n\n\t    =================================================================\n");
	printf("\t   /\t\t\t\t\t\t\t\t   / |\n");
	printf("\t /\t\t\t\t\t\t\t\t /   |\n");
	printf("\t=================================================================    |\n");
	printf("\t|\t                                           \t\t|    |\n");
	printf("\t|\t                                           \t\t|    |\n");
	printf("\t|\t --------------------------------------------\t\t\|    |\n");
	printf("\t|\t |                                          |\t\t|    |\n");
	printf("\t|\t |     ��         ��         ��       Ʈ    |\t\t|    |\n");
	printf("\t|\t |                                          |\t\t|    |\n");
	printf("\t|\t --------------------------------------------\t\t|    |\n");
	printf("\t|\t                  o----o                     \t\t|    |\n");
	printf("\t|                         | |  |             \t\t\t|   /\n");
	printf("\t|                         | |  |             \t\t\t| /\n");
	printf("\t=================================================================\n");
	printf("\n\n\t\t     -----------------------------------\n");
	printf("\t\t     |(1)ȸ����� (2)�α��� (3)�繫��ǥ|\n");
	printf("\t\t     -----------------------------------\n");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t$20180846 ������\n ");
	printf("\t\t\t\t\t\t\t\t\t\t$20180850 �̻�� \n");
	printf("\t\t\t\t\t\t\t\t\t\t$20180848 ��â��\n\n");
	printf("\t\t\t   ��ȣ�� �����ϼ���:");
	scanf("%d", &ctrl);
	ctrlScreen(ctrl);
	_getch();
}
void ctrlScreen(int a) {    //  a= ������Է�
	system("cls");
	if (a <= NOTHING || a >= END) {
		a = NOTHING;
	}
	switch (a) {
	case REGISTER:
		head=_register();
		break;
	case LOGIN:
		login_check(head);
		_getch();
		break;
	case ACCOUNT:
		account_display();
		freeInit();
		break;
	case PRINT:
		printUserInfo(head);
		break;
	case NOTHING:
		printf("1�� 4������ ���ڸ� �Է����ּ���.");
		break;
	default:
		break;
	}
}
USER_NODE* _register() {
	//USER_NODE *p;
	//p = (USER_NODE*)malloc(sizeof(USER_NODE)); 
	global_user_data = Make_newNode();
	global_user_data.money = INIT_USER_MONEY;
	head = AddUserNode(head,NULL, global_user_data);
	return head;
}

int login_check() { 
	//   (�� �������� ���� ������� ���) 
	IDENTITY Identity = { 0,0 };
	USER_NODE *login = NULL;
	Identity=login_display();
	login = search(head, Identity.ID, Identity.PW);
	if (strcmp(Identity.ID, login->data.ID) == SUCCESS && strcmp(Identity.PW, login->data.PW) == SUCCESS) {
		login->data.level = 1;
		while (login->data.level != 0) {
			if (strcmp(login->data.ID, "admin") == TRUE) {
				login->data.level = 4;
				companyDisplay(&login->data.level);
			}
			else {
				userDisplay(login);
			}
		}
		printf("\t\t�α׾ƿ� �ϼ̽��ϴ�.");
		return 0;
	}
	else {
		printf("\t\t�α��� ����");
	}
	
	return 0;
}
void printUserInfo(USER_NODE *plist){
	USER_NODE *ptr;
	
	ptr = plist;
	while (ptr!=NULL){
		printf("-------------------------------------\n");
		printf("��   �� : %s\n", ptr->data.name);
		printf("���̵�  : %s\n", ptr->data.ID);
		printf("���    : %s\n", ptr->data.PW);
		ptr = ptr->next;
	}
	printf("-------------------------------------\n");
	_getch();
}

USER_NODE* search(USER_NODE *head, char* ID, char* PW){ 
	USER_NODE *p;
	p = head;
	while (p != NULL) {
		if (strcmp(p->data.ID, ID) == SUCCESS && strcmp(p->data.PW, PW) == SUCCESS) { //ID,PWüũ
			return p;
		}
		p = p->next;
	}
	_getch();
	return head;
}
IDENTITY login_display() {
	IDENTITY Identity;
	system("cls");
	printf("\n\n\n");
	printf("\t������   ��      ��    ������   ������   ��    ��   ��      ��  ��      ��    ��\n");
	printf("\t�ᡡ����   ����      ��    ��      ��   ��      ��   ��  ��       ��  ��    ��      ��    ��\n");
	printf("\t������   ��      ��    ��      ��   ������   ���           ��      ��      ��    ��\n");
	printf("\t        ��   ��      ��    ��      ��           ��   ��  ��         ��      ��      ��    ��\n");
	printf("\t������   ������    ��      ��   ������   ��    ��       ��      ������    ��\n");
	printf("\n\n\t\t\t\t--------------------------------------------\n");
	printf("\t\t\t\t   (��)      (��)      (��)     (Ʈ)\n");
	printf("\t\t\t\t--------------------------------------------\n");
	printf("\t\t\t\t\t---------------------------\n");
	printf("\t\t\t\t\t|         �α���          |\n");
	printf("\t\t\t\t\t|   ���̵� :              |\n");
	printf("\t\t\t\t\t| �н����� :              |\n");
	printf("\t\t\t\t\t---------------------------\n");
	printf("\r\b\r\b\r\b\r\t\t\t\t\t\t\t\b\b\b");
	scanf("%s", Identity.ID);
	printf("\t\t\t\t\t\t\t\b\b\b");
	scanf("%s", Identity.PW);
	return Identity;
}
