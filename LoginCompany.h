#ifndef LOGINCOMPANY_H
#define LOGINCOMPANY_H

#include"Product.h"

void register_goods();           
void register_account();             //유저의 상품데이터 전체공유할 필요성있음.
void blacklist();               // 탐색 구현. 유저데이터 삭제 구현.
void classification_goods(); // 등록할때 사용자가 직접 선택, 야채 고기 등등.
void companyDisplay(int *level);         //회사 화면
void logout();
void ctrlCompanyMenu(int ctrl,int *level);
/* LoginUser.h의 상품 진열 칸과 데이터 공유해야함. */



#endif //LOGINCOMPANY_H