#ifndef SHOPPINGBASKET_H
#define SHOPPINGBASKET_H

#include"LoginUser.h"  // userDisplay()
void shoppingBag_display();  // ��ٱ���ȭ�鿡 �׸��׸��׸��׸��׸�
void shoppingBag(const char *choose);
PRODUCT* product_search(PRODUCT* plist, char *choose);

//PRODUCT* makeShoppingList(PRODUCT* plist); //�� �������Ǵ��� Ȯ��
PRODUCT* shopping_list_head;




#endif