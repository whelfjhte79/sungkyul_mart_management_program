#include"ShoppingBasket.h"
#include"Product.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>
enum{SUCCESS, FAILURE};
void shoppingBag_display() {
	char choose[20];
	system("cls");
	printf("\n\t\t-------------------------------\n");
	printf("\t\t------------------------------\n");
	printf("\t\t|        장바구니             |\n");
	printf("\t\t------------------------------\n");
	printf("\n\n\n 상품 이름을 입력하시거나 (0)뒤로가기를 선택하세요 : ");

	scanf("%s", choose);
	if (choose[0] == '0') {
		printf("%c", choose[0]);
		return;
	}
	shoppingBag(choose);
	_getch();
}
void shoppingBag(const char *choose) {
	PRODUCT *plist;
    plist=product_search(product_head,choose);
	
	while (plist != NULL) { //buying

		printf("%s ", plist->productInfo.name);
		plist = plist->next;
	}
	

	// 가격하고 구현
	_getch();
}
PRODUCT* product_search(PRODUCT* plist,char *choose) { 
	//PRODUCT *shoppingList;
	
	while (plist != NULL) {
		if (strcmp(plist->productInfo.name,choose)==SUCCESS) {   //찾은상품 어떻게할껀지 
			
			shopping_list_head = AddProductNode(shopping_list_head, NULL, plist->productInfo);
			//shopping_list_head=shoppingList;
			//printf("찾았습니다.");
			_getch();
			return shopping_list_head;  // 원래는 return --> plist TODO: 에러나면 다시 수정
		}
		else {		
			plist = plist->next;
		}
	}
	printf("상품을 못 찾았습니다.");
	_getch();
	return shopping_list_head;   //원래 return --> plist
}