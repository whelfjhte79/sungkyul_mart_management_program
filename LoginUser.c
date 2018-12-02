#include"LoginUser.h"
#include"LoginCompany.h"
#include"ShoppingBasket.h"
#include"User_data.h"
#include"Product.h"
#include"account.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/////////////////////////////////////
#include"MacroCollection.h"
//////////////////////////////////

enum { SUCCESS, FAILURE };
enum{LOGOUT,MEET,VEGETABLES,STATIONERY,DRINKS,SNACKS,SIDE_DISHES,SHOPPING_BASKET,BUYING_SHOPPING_BASKET,NOTHING}; 

void userDisplay(USER_NODE *login){
	int button;
	int count = 0; //ERROR üũ
	system("cls");
	printf("\n\t\t\t\t���� ��� : %d", login->data.money);
	printf("\n\n\t\t\t\t                    |�ѤѤѤѤѤѤѤ�|\n");
	printf("\t\t\t\t ___________________|    ��ǰ����    |__________________\n");
	printf("\t\t\t\t|_______________________________________________________|\n");
	printf("\t\t\t\t|                           |                           |\n");
	printf("\t\t\t\t|        (1)����          |        (2)ä�ҷ�          |\n");
	printf("\t\t\t\t|___________________________|___________________________|\n");
	printf("\t\t\t\t _______________________________________________________\n");
	printf("\t\t\t\t|                           |                           |\n");
	printf("\t\t\t\t|        (3)������          |        (4)�� ��           |\n");
	printf("\t\t\t\t|___________________________|___________________________|\n");
	printf("\t\t\t\t _______________________________________________________\n");
	printf("\t\t\t\t|                           |                           |\n");
	printf("\t\t\t\t|        (5)���ڷ�          |        (6)������          |\n");
	printf("\t\t\t\t|___________________________|___________________________|\n");
	printf("\n\t\t|(0)�α׾ƿ�|(7)��ٱ���|(8)���ǻ��(��ٱ���)\n");
	printf("\n\n\n\t\t\t�ش� ��ư�� �Է��ϼ���.\n");
	printf("\t\t\t�Է� : ");
	scanf("%d", &button);
	ctrlUserMenu(button, login);
	_getch();
	//printf("\n����ī��Ʈ: %d\n", count++);
}
void ctrlUserMenu(int button, USER_NODE *login) {
	
	PRODUCT *plist = product_head;
	PRODUCT *shoppingList=NULL;
	PRODUCT *shoppingTest = shopping_list_head;
	USER_NODE *userList = head;
	if (button < LOGOUT || button > NOTHING) {
		button = NOTHING;
	}
	switch (button) {
	case LOGOUT:
		login->data.level = 0;
		//return;
		break;
	case MEET:
		meet(plist);
		_getch();
		break;
	case VEGETABLES:
		vegetables(plist);
		_getch();
		break;
	case STATIONERY:
		stationery(plist);
		_getch();
		break;
	case DRINKS:
		drinks(plist);
		_getch();
		break;
	case SNACKS:
		snacks(plist);
		_getch();
		break;
	case SIDE_DISHES:
		side_dishes(plist);
		_getch();
		break;
	case SHOPPING_BASKET:
		shoppingBag_display();
		_getch();
		break;
	case BUYING_SHOPPING_BASKET:
		shoppingList=buying(shoppingTest,login);
		free(shopping_list_head);
		shopping_list_head = NULL;
		_getch();
	/*
             ȸ������ ���⼭ ����ٰ������ߵ�. ȸ�������� ����ü�����.	
	}*/
		break;
	default: 
		break;
	}
}

/*
��Ʈ ��ǰ �з�
            20181100 ����
            20181200 ä�ҷ�
			20181300 ������
			20181400 �ַ�
			20181500 ���ڷ�
			20181600 ������

*/
void meet(PRODUCT *plist) {
	printf("\t��� : ");
	
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "11") == SUCCESS)
		   printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void vegetables(PRODUCT *plist) {
	printf("\tä�� : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "12") == SUCCESS)
		    printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void stationery(PRODUCT *plist) {
	printf("\t���� : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "13") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void drinks(PRODUCT *plist) {
	printf("\t�ַ� : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "14") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}

void snacks(PRODUCT *plist) {
	printf("\t���� : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "15") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void side_dishes(PRODUCT *plist) {
	printf("\t���� : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "16") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
PRODUCT* buying(PRODUCT* shoppingList,USER_NODE *userList) {        // TODO : ���� �� �� ���� ���� �� �� üũ ���.
	SALES sales = { 0,0,0 };
	const int buyingProductQuantity = 1;
	if (shoppingList == NULL) {
		printf("\t\t\t��ٱ��Ͽ� ��ǰ�� �����ϴ�.");
		return shoppingList;
	}
	while (shoppingList != NULL) {
		sales.productMoney+=shoppingList->productInfo.price;
		sales.productQuantity += buyingProductQuantity;
		sales.productSum = sales.productMoney;
		shoppingList = shoppingList->next;
	}
	if ((userList->data.money - sales.productMoney) < 0) {
		printf("\t\t\t������ ������ ��ǰ�� �� �� �����ϴ�.");
		sales.productSum = 0;
	}
	else {
		while (shoppingList != NULL) {
			if (shoppingList->productInfo.quantity - buyingProductQuantity < 0) {
				printf("\t\t\t��ǰ�� �����Ͽ� ������ �� �����ϴ�.");
				sales.productSum = 0;
				return shoppingList;
			}
			shoppingList->productInfo.quantity -= buyingProductQuantity;
		}
		userList->data.money -= sales.productMoney;
		printf("\t\t������ �����ϼ̽��ϴ�.");
		
		account_revenue=Revenue(sales); //�Ѹ����
	}
	return shoppingList;
}
char* Mid(char barcode[], int start, int count){ //��ó: ���������������Ǻ�α�(���̹���α�) https://blog.naver.com/qwerty6621/220440796082
	char *obj;
	int len = 0;

	if ((len = strlen(barcode)) < start || (len - start) < count - 1) return NULL;
	obj = (char*)malloc(count);
	strncpy(obj, (barcode + (start - 1)), count);
	obj[count] = '\0';
	return obj;
}
SALES Revenue(SALES sales) {
	static SALES sumRevenue = { 0,0,0 };
	sumRevenue.productMoney += sales.productMoney;
	sumRevenue.productQuantity += sales.productQuantity;
	sumRevenue.productSum += sales.productSum;
	return sumRevenue;
}