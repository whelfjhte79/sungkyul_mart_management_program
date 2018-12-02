#ifndef SHOPPINGBASKET_H
#define SHOPPINGBASKET_H

#include"LoginUser.h"  // userDisplay()
void shoppingBag_display();  // 장바구니화면에 그림그림그림그림그림
void shoppingBag(const char *choose);
PRODUCT* product_search(PRODUCT* plist, char *choose);

//PRODUCT* makeShoppingList(PRODUCT* plist); //얘 지워도되는지 확인
PRODUCT* shopping_list_head;




#endif