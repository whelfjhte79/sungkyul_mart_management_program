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
	printf("\t\t|        ��ٱ���             |\n");
	printf("\t\t------------------------------\n");
	printf("\n\n\n ��ǰ �̸��� �Է��Ͻðų� (0)�ڷΰ��⸦ �����ϼ��� : ");

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
	

	// �����ϰ� ����
	_getch();
}
PRODUCT* product_search(PRODUCT* plist,char *choose) { 
	//PRODUCT *shoppingList;
	
	while (plist != NULL) {
		if (strcmp(plist->productInfo.name,choose)==SUCCESS) {   //ã����ǰ ����Ҳ��� 
			
			shopping_list_head = AddProductNode(shopping_list_head, NULL, plist->productInfo);
			//shopping_list_head=shoppingList;
			//printf("ã�ҽ��ϴ�.");
			_getch();
			return shopping_list_head;  // ������ return --> plist TODO: �������� �ٽ� ����
		}
		else {		
			plist = plist->next;
		}
	}
	printf("��ǰ�� �� ã�ҽ��ϴ�.");
	_getch();
	return shopping_list_head;   //���� return --> plist
}