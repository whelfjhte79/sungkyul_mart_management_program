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
	int count = 0; //ERROR 체크
	system("cls");
	printf("\n\t\t\t\t현재 재산 : %d", login->data.money);
	printf("\n\n\t\t\t\t                    |ㅡㅡㅡㅡㅡㅡㅡㅡ|\n");
	printf("\t\t\t\t ___________________|    상품진열    |__________________\n");
	printf("\t\t\t\t|_______________________________________________________|\n");
	printf("\t\t\t\t|                           |                           |\n");
	printf("\t\t\t\t|        (1)고기류          |        (2)채소류          |\n");
	printf("\t\t\t\t|___________________________|___________________________|\n");
	printf("\t\t\t\t _______________________________________________________\n");
	printf("\t\t\t\t|                           |                           |\n");
	printf("\t\t\t\t|        (3)문구류          |        (4)주 류           |\n");
	printf("\t\t\t\t|___________________________|___________________________|\n");
	printf("\t\t\t\t _______________________________________________________\n");
	printf("\t\t\t\t|                           |                           |\n");
	printf("\t\t\t\t|        (5)과자류          |        (6)반찬류          |\n");
	printf("\t\t\t\t|___________________________|___________________________|\n");
	printf("\n\t\t|(0)로그아웃|(7)장바구니|(8)물건사기(장바구니)\n");
	printf("\n\n\n\t\t\t해당 버튼을 입력하세요.\n");
	printf("\t\t\t입력 : ");
	scanf("%d", &button);
	ctrlUserMenu(button, login);
	_getch();
	//printf("\n에러카운트: %d\n", count++);
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
             회계정보 여기서 끌어다가져가야됨. 회계정보에 구조체만들기.	
	}*/
		break;
	default: 
		break;
	}
}

/*
마트 상품 분류
            20181100 고기류
            20181200 채소류
			20181300 문구류
			20181400 주류
			20181500 과자류
			20181600 반찬류

*/
void meet(PRODUCT *plist) {
	printf("\t고기 : ");
	
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "11") == SUCCESS)
		   printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void vegetables(PRODUCT *plist) {
	printf("\t채소 : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "12") == SUCCESS)
		    printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void stationery(PRODUCT *plist) {
	printf("\t문구 : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "13") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void drinks(PRODUCT *plist) {
	printf("\t주류 : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "14") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}

void snacks(PRODUCT *plist) {
	printf("\t과자 : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "15") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
void side_dishes(PRODUCT *plist) {
	printf("\t반찬 : ");
	while (plist != NULL) {
		if (strcmp(Mid(plist->productInfo.barcode, 5, 2), "16") == SUCCESS)
			printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
}
PRODUCT* buying(PRODUCT* shoppingList,USER_NODE *userList) {        // TODO : 물건 살 때 돈과 수량 둘 다 체크 고려.
	SALES sales = { 0,0,0 };
	const int buyingProductQuantity = 1;
	if (shoppingList == NULL) {
		printf("\t\t\t장바구니에 상품이 없습니다.");
		return shoppingList;
	}
	while (shoppingList != NULL) {
		sales.productMoney+=shoppingList->productInfo.price;
		sales.productQuantity += buyingProductQuantity;
		sales.productSum = sales.productMoney;
		shoppingList = shoppingList->next;
	}
	if ((userList->data.money - sales.productMoney) < 0) {
		printf("\t\t\t현금이 부족해 상품을 살 수 없습니다.");
		sales.productSum = 0;
	}
	else {
		while (shoppingList != NULL) {
			if (shoppingList->productInfo.quantity - buyingProductQuantity < 0) {
				printf("\t\t\t상품이 부족하여 구매할 수 없습니다.");
				sales.productSum = 0;
				return shoppingList;
			}
			shoppingList->productInfo.quantity -= buyingProductQuantity;
		}
		userList->data.money -= sales.productMoney;
		printf("\t\t물건을 구입하셨습니다.");
		
		account_revenue=Revenue(sales); //총매출액
	}
	return shoppingList;
}
char* Mid(char barcode[], int start, int count){ //출처: 지나가던강아지의블로그(네이버블로그) https://blog.naver.com/qwerty6621/220440796082
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