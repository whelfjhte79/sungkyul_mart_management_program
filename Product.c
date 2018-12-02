#include"Product.h"
#include"Register.h"
#include<stdio.h>
#include<stdlib.h>


PRODUCTINFO initProduct() {
	PRODUCTINFO init;
	printf("���ڵ带 �Է��ϼ���(8�ڸ�):");
	scanf("%s",init.barcode);
	printf("��ǰ���� �Է��ϼ���:");
	scanf("%s", init.name);
	printf("��ǰ ������ �Է��ϼ���:");
	scanf("%d", &init.quantity);
	printf("��ǰ ������ �Է��ϼ���:");
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

PRODUCT* AddProductNode(PRODUCT* product_head, PRODUCT *p, PRODUCTINFO newProduct) {// �ӽ� ����׿� �Լ�
   PRODUCT *newInfo;
	newInfo = (PRODUCT*)malloc(sizeof(PRODUCT));
	if (newInfo == NULL) {
		printf("�޸� �Ҵ����");
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
		printf("��ǰ��    : %s\n", ptr->productInfo.name);
		printf("��ǰ ���� : %d\n", ptr->productInfo.quantity);
		printf("��ǰ ���� : %d\n", ptr->productInfo.price);
		ptr = ptr->next;
	}
	printf("-------------------------------------\n");
	_getch();
}