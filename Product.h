#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct ProductInfo {
	char barcode[8];       //바코드
	//int productNo;  //productNo로 상품구분 ex) 1:고기류 2:야채류
	char name[20];
	int quantity;      //상품수량
	int price;        //상품가격
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
void printProduct(PRODUCT *plist);  //상품출력 productNo로 상품구분


#endif//         