#include"LoginCompany.h"
#include"Product.h"
#include"User_data.h"
#include"Screen.h"
#include<stdio.h>

// ��ǰ ��� �� ������ �ʿ伺
enum{NOTHING,REG_PRODUCT,CHECK_USER_INFO,PRODUCT_AMOUNT,LOGOUT,END};

void companyDisplay(int *level)
{
	int ctrl;
	system("cls");
	printf("\n__");
	printf("\n\n\n\t       /|                                       /|     ��");
	printf("\n\t      / |                                      / |     ��");
	printf("\n\n\t\t ----------------------------------------      ��");
	printf("\n\t\t��                                      ��     ��                 1) ��ǰ ���");
	printf("\n\t\t��           ȸ          ��             ��     ��                 2) ���� ���� Ȯ��");
	printf("\n\t\t��           ��          ��             ��     ��                 3) ��ǰ ���");
	printf("\n\t\t��                                      ��     ��                 4) �α׾ƿ�");
	printf("\t\t\t\t\t\t ----------------------------------------      ��               -------------");
	printf("\n\t                             ��                        ��             /             /");
	printf("\n                                                                             /             /");
	printf("\n---------------------------------------------------------------/            /             /");
	printf("\n            ��                                  ��                         /             /");
	printf("\n--------------------------------------------------------------------------/             /");
	scanf("%d", &ctrl);
	ctrlCompanyMenu(ctrl,level);
}

void ctrlCompanyMenu(int ctrl, int *level) {
	if (ctrl <= NOTHING || ctrl > END) {
		ctrl = NOTHING;
	}
	switch (ctrl) {
	case REG_PRODUCT:
		product_head=registerProduct();
		break;
	case CHECK_USER_INFO:
		printUserInfo(head); // Screen.h
		break;
	case PRODUCT_AMOUNT: //product_head�� �޾ƿ����.
		printProduct(product_head);//Product.c���� ���� �޾ƿ�.
		break;
	case LOGOUT:
		*level = 0;
		break;
	default:
		break;
	}
}