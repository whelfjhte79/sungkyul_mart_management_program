#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct ProductInfo {
	char barcode[8];       //���ڵ�
	//int productNo;  //productNo�� ��ǰ���� ex) 1:���� 2:��ä��
	char name[20];
	int quantity;      //��ǰ����
	int price;        //��ǰ����
}PRODUCTINFO;
typedef struct Product {
	PRODUCTINFO productInfo;
	struct Product *next;
}PRODUCT;
PRODUCT *product_head;   //

PRODUCTINFO global_product_data;


PRODUCTINFO initProduct();
PRODUCT* AddProductNode(PRODUCT *phead, PRODUCT *p, PRODUCTINFO newNode);
PRODUCT* registerProduct();
void printProduct(PRODUCT *plist);  //��ǰ��� productNo�� ��ǰ����


#endif//         