#ifndef MACROCOLLECTION_H
#define MACROCOLLECTION_H

// 시간되면 전처리로 바꿔보자

#define CLEAR() system("cls")
#define VAR_CLING(x,y) (x##y)
#define PRINT(x) printf(#x)
#define GET() _getch()
#define INT "%d"
#define CHAR "%c"
#define PCHAR "%s"
#define MALLOC(x) (x*)malloc(sizeof(x))
#define PRINT_TYPE(x,y) printf(x,y)
#define 에러(x) printf(#x"ERROR\n")
#define 출력에러(x) printf("출력에러 : %d\n",x)
#endif// MACROCOLLECTION_H