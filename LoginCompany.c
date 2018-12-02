#include"LoginCompany.h"
#include"Product.h"
#include"User_data.h"
#include"Screen.h"
#include<stdio.h>

// 상품 등록 폼 제작할 필요성
enum{NOTHING,REG_PRODUCT,CHECK_USER_INFO,PRODUCT_AMOUNT,LOGOUT,END};

void companyDisplay(int *level)
{
	int ctrl;
	system("cls");
	printf("\n__");
	printf("\n\n\n\t       /|                                       /|     ㅣ");
	printf("\n\t      / |                                      / |     ㅣ");
	printf("\n\n\t\t ----------------------------------------      ㅣ");
	printf("\n\t\tㅣ                                      ㅣ     ㅣ                 1) 상품 등록");
	printf("\n\t\tㅣ           회          사             ㅣ     ㅣ                 2) 유저 정보 확인");
	printf("\n\t\tㅣ           메          뉴             ㅣ     ㅣ                 3) 상품 재고");
	printf("\n\t\tㅣ                                      ㅣ     ㅣ                 4) 로그아웃");
	printf("\t\t\t\t\t\t ----------------------------------------      ㅣ               -------------");
	printf("\n\t                             ∇                        ㅣ             /             /");
	printf("\n                                                                             /             /");
	printf("\n---------------------------------------------------------------/            /             /");
	printf("\n            ㅣ                                  ㅣ                         /             /");
	printf("\n--------------------------------------------------------------------------/             /");
	scanf("%d", &ctrl);
	ctrlCompanyMenu(ctrl,level);
}

void ctrlCompanyMenu(int ctrl, int *level) {
	if (ctrl <= NOTHING || ctrl > END) {
		ctrl = NOTHING;
	}
	switch (ctrl) {
	case REG_PRODUCT:
		product_head=registerProduct();
		break;
	case CHECK_USER_INFO:
		printUserInfo(head); // Screen.h
		break;
	case PRODUCT_AMOUNT: //product_head로 받아오면됨.
		printProduct(product_head);//Product.c에서 수량 받아옴.
		break;
	case LOGOUT:
		*level = 0;
		break;
	default:
		break;
	}
}