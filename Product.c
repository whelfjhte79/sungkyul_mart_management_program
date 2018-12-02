#include"Product.h"
#include"Register.h"
#include<stdio.h>
#include<stdlib.h>


PRODUCTINFO initProduct() {
	PRODUCTINFO init;
	printf("바코드를 입력하세요(8자리):");
	scanf("%s",init.barcode);
	printf("상품명을 입력하세요:");
	scanf("%s", init.name);
	printf("상품 수량을 입력하세요:");
	scanf("%d", &init.quantity);
	printf("상품 가격을 입력하세요:");
	scanf("%d", &init.price);

	printf("%s %s %d %d", init.barcode, init.name, init.quantity, init.price);
	_getch();
	return init;
}
PRODUCT* registerProduct() {
	PRODUCT *p,*product;
	global_product_data = initProduct();
	product_head=AddProductNode(product_head, NULL, global_product_data);
	return product_head;
}

PRODUCT* AddProductNode(PRODUCT* product_head, PRODUCT *p, PRODUCTINFO newProduct) {// 임시 디버그용 함수
   PRODUCT *newInfo;
	newInfo = (PRODUCT*)malloc(sizeof(PRODUCT));
	if (newInfo == NULL) {
		printf("메모리 할당오류");
		return;
	}
	newInfo->productInfo = newProduct;
	if (p == NULL) {
		newInfo->next = product_head;
		product_head = newInfo;
	}
	else {
		newInfo->next = p->next;
		p->next = newInfo;
	}
	return product_head;
}
void printProduct(PRODUCT *plist) {
	PRODUCT *ptr;
	ptr = plist;

	while (ptr!=NULL) {
		printf("-------------------------------------\n");
		printf("상품명    : %s\n", ptr->productInfo.name);
		printf("상품 수량 : %d\n", ptr->productInfo.quantity);
		printf("상품 가격 : %d\n", ptr->productInfo.price);
		ptr = ptr->next;
	}
	printf("-------------------------------------\n");
	_getch();
}