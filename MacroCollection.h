#ifndef MACROCOLLECTION_H
#define MACROCOLLECTION_H

// �ð��Ǹ� ��ó���� �ٲ㺸��

#define CLEAR() system("cls")
#define VAR_CLING(x,y) (x##y)
#define PRINT(x) printf(#x)
#define GET() _getch()
#define INT "%d"
#define CHAR "%c"
#define PCHAR "%s"
#define MALLOC(x) (x*)malloc(sizeof(x))
#define PRINT_TYPE(x,y) printf(x,y)
#define ����(x) printf(#x"ERROR\n")
#define ��¿���(x) printf("��¿��� : %d\n",x)
#endif// MACROCOLLECTION_H