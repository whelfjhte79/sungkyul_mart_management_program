#ifndef LOGINUSER_H
#define LOGINUSER_H

#include"Product.h"
#include"User_data.h"
/* TODO: 회사와 유저간 거래 내역 공유를 하는 폼을 만들지 고민해야됨
         아니라면 buying, refund는 무조건 공유해야함.
*/

#define INIT_USER_MONEY 100000
void userDisplay(USER_NODE* login);
void ctrlUserMenu(int button, USER_NODE *login);

 
PRODUCT* buying(PRODUCT *shopping_list_head,USER_NODE *login);             // 바로 살지 장바구니에 무조건 담을지 고민
void refund();  //환불 추가기능
void logout();       //    메인 화면으로 전환

void meet(PRODUCT *plist);
void vegetables(PRODUCT *plist);
void stationery(PRODUCT *plist);
void drinks(PRODUCT *plist);
void snacks(PRODUCT *plist);
void side_dishes(PRODUCT *plist);
////////////////////////////
char* Mid(char txt[], int start, int count);







#endif // LOGINUSER_H