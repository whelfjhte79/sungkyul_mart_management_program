#include"Register.h"
#include"User_data.h"
#include<stdlib.h>
#include<string.h>
USER_DATA Make_newNode() { //완료
	USER_DATA input_data;

	printf("\n이름:");
	scanf(" %s", input_data.name);
	printf("아이디:");
	scanf(" %s", input_data.ID);
	printf("비번:");
	scanf(" %s", input_data.PW);
	
	return input_data;
}
USER_NODE* AddUserNode(USER_NODE *phead, USER_NODE *p,USER_DATA newNode) {
	USER_NODE *newInfo;
	newInfo = (USER_NODE*)malloc(sizeof(USER_NODE));
	if (newInfo == NULL) {
		printf("메모리 할당오류");
		return;
	}
	newInfo->data = newNode;
	if (p == NULL) {
		newInfo->next = phead;
		phead = newInfo;
	}
	else {
		newInfo->next = p->next;
		p->next = newInfo;
	}
	return phead;
}