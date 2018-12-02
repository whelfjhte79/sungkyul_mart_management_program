#include"Product.h"
#include"account.h"
#include"ShoppingBasket.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"MacroCollection.h"

/*
     1. ����� : ��ǰ �� ���� * ����

	 2. ������� : ������.  

	 3. ���������� : ����� - �������    =  (��������)��ǰ �� ���� 30%

	 4. �Ǹź�� ������ : ��ǰ�� �뿪�� �Ǹ�Ȱ�� �Ǵ� ����� ������ �������� 
	            �߻��ϴ� ������� �޿�(�ӿ��޿�, �޷�, �ӱ� �� �� ������ �����Ѵ�), 
				�����޿�, ��������(���������� �밡�� �����ϴ� �μ�Ƽ�� ���� �����Ѵ�), 
				�����Ļ���, ������, �����, �����󰢺�, �����ڻ�󰢺�, ���ݰ�����, ��������, 
				������, ��󰳹ߺ�, ��ջ󰢺� �� ��������� ������ �ƴ��ϴ� ��� ��������� �����Ѵ�
				--����ǥ��   ���μ���
               2�� �� ����     10%
     2�� �� �ʰ� 200�� ����    20%
   200�� �ʰ� 3õ�� �� ����    22%
              3õ�� �� �ʰ�    25%

			  �޿�: 900���� (����3) 4�뺸��ݾ� : 584,573��(3��)
*/
enum{ NOTHING, REVENUE, COGS, GROSS_PROFIT, SG_AND_A, OPERATION_INCOME,OTHER_INCOME,NI,END};
INCOME* Calculation(INCOME* income, SG_And_A_details_Spec* SG_and_A, OIS* other_income, NIS* NI) {
	income->revenue = account_revenue.productSum;
	income->Cost_of_goods_sold= CostOfGoodsSold(income->revenue);
	income->gross_profit = Gross_Profit(income->revenue, income->Cost_of_goods_sold);
	income->SG_and_A = Selling_General_And_AdministrationExpense(income->gross_profit);
	income->operating_income = Operating_Income(income->gross_profit, income->SG_and_A->total);
	income->other_income = Other_Income();
	income->NI = NetIncome(income->operating_income, income->other_income->total);

	return income;
}
void typeInit() {
	income=(INCOME*)malloc(sizeof(INCOME));
	nis=(NIS*)malloc(sizeof(NIS));
	ois=(OIS*)malloc(sizeof(OIS));
	sg_and_a_details_spec=(SG_And_A_details_Spec*)malloc(sizeof(SG_And_A_details_Spec));
}
void freeInit() {
	free(income);
	free(nis);
	free(ois);
	free(sg_and_a_details_spec);
	income = NULL;
	nis = NULL;
	ois = NULL;
	sg_and_a_details_spec = NULL;
}
void account_display() {
	int ctrl;
	typeInit();
	income = Calculation(income,income->SG_and_A,income->other_income,income->NI);
	printf("\n\n\t��������������������������������������������������������������������������������������������������������������������������������������������������������������������\n\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t\t ---------------------------------\t\t\t ��\n");
	printf("\t��\t\t\t |   �� �� �� Ʈ �� �� �� �� ��  |\t\t\t ��\n");
	printf("\t��\t\t\t ---------------------------------\t\t\t ��\n\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t\t\t(0)����ȭ�����ΰ���\t\t\t\t ��\n\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t���͹ݿ����: ��� �ݿ�     �� �� �� : ���ḶƮ\t\t\t ��\n\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t                            ����ڵ�Ϲ�ȣ : 20180850\t\t ��\n\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t\t      |      �� �� �� ��       |\t\t\t ��\n\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t\t\t (1)��  ��  ��     : %d\t\t\t\t ��\n ", income->revenue);
	printf("\t��\t\t\t\t (2)�� �� �� ��    : %d\t\t\t\t ��\n ", income->Cost_of_goods_sold);
	printf("\t��\t\t\t\t (3)�� �� �� �� �� : %d\t\t\t\t ��\n", income->gross_profit);
	printf("\t��\t\t\t\t (4)�Ǹź�Ͱ����� : %d\t\t\t\t ��\n", income->SG_and_A->total);
	printf("\t��\t\t\t\t (5)�� �� �� ��    : %d\t\t\t\t ��\n", income->operating_income);
	printf("\t��\t\t\t\t (6)�� �� �� �� �� : %d\t\t\t\t ��\n", income->other_income->total);
	printf("\t��\t\t\t\t (7)�� �� �� �� �� : %d\t\t\t\t ��\n", income->NI->total);
	printf("\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��\t\t\t\t\t\t\t\t\t\t ��\n"); 
	printf("\t��\t\t\t\t\t\t\t\t   �̻���:�̻�� ��\n");
	printf("\t��\t\t\t\t\t\t\t\t\t\t ��\n");
	printf("\t��������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	scanf("%d", &ctrl);
	specification(ctrl, account_revenue.productSum);
}
void specification(int ctrl, int Revenue) {
	system("cls");
	if (ctrl<NOTHING || ctrl>END) {
		ctrl = NOTHING;
	}
	switch (ctrl) {
	case NOTHING:
		printf("����ȭ������ ���ư��ϴ�.");
		_getch();
		break;
	case REVENUE:
		income->revenue=Revenue_details(Revenue);
		Revenue_details_print(income->revenue);
		_getch();
		break;
	case COGS:
		income->Cost_of_goods_sold=CostOfGoodsSold(Revenue);
		CostOfGoodsSold_print(income->Cost_of_goods_sold);
		_getch();
		break;
	case GROSS_PROFIT:
		income->gross_profit=Gross_Profit(Revenue, income->Cost_of_goods_sold);
		Gross_Profit_print(income->gross_profit);
		_getch();
		break;
	case SG_AND_A:
		income->SG_and_A=Selling_General_And_AdministrationExpense(income->SG_and_A);
		Selling_General_And_AdministrationExpense_print();
		_getch();
		break;
	case OPERATION_INCOME:
		income->operating_income=Operating_Income(income->gross_profit, income->SG_and_A->total);
		Operating_Income_print(income->operating_income);
		_getch();
		break;
	case OTHER_INCOME:
		income->other_income = Other_Income();
		Other_Income_print(income->other_income->total,income->other_income);
		_getch();
		break;
	case NI:
		income->NI=NetIncome(income->operating_income, income->other_income->total);
		NetIncome_print(income->NI->total,income->NI);
		_getch();
		break;
	default:
		break;
	}
}
/*   
      ���� ���񺰷� �Լ����� ����ϰ� ���Լ��� ����ؼ� ����� ���������� ��� ���     

  
*/
int Revenue_details(int sales) {
	return sales;
}
int CostOfGoodsSold(int revenue) {
	double cost_of_sale_of_goods;
	cost_of_sale_of_goods = (double)revenue*0.62;
	return (int)cost_of_sale_of_goods;
}
int Gross_Profit(int revenue,int cost) {
	return revenue - cost;
}
SG_And_A_details_Spec* Selling_General_And_AdministrationExpense(SG_And_A_details_Spec* SG_A_A) {
	SG_And_A = Selling_General_And_AdministrationExpense_details();
	SG_A_A = SG_And_A;
	return SG_A_A;
}
SG_And_A_details_Spec* Selling_General_And_AdministrationExpense_details() {
	sg_and_a_details_spec->salary = 9000000;       
	sg_and_a_details_spec->insurance = 584573;
	sg_and_a_details_spec->traveling_expenses = 12000;
	sg_and_a_details_spec->depreciation_cost = 200000;
	sg_and_a_details_spec->rent = 30000000;
	sg_and_a_details_spec->tax_deduction_amount = 10000;
	sg_and_a_details_spec->vehicle_maintenance_costs = 50000;

	sg_and_a_details_spec->total = sg_and_a_details_spec->salary + sg_and_a_details_spec->insurance +
		sg_and_a_details_spec->traveling_expenses+
		sg_and_a_details_spec->depreciation_cost+sg_and_a_details_spec->rent+
		sg_and_a_details_spec->tax_deduction_amount+sg_and_a_details_spec->vehicle_maintenance_costs;
	
	return sg_and_a_details_spec;
}
int Operating_Income(int gross_profit, int selling_general_and_administration_expense) {
	return gross_profit - selling_general_and_administration_expense;
}

OIS* Other_Income() {
	int profit, loss;
	ois->dividend_income = 40000;
	ois->rent = 3000000;
	profit = (int)ois->dividend_income + ois->rent;
	ois->donation = 1000;
	ois->losses_on_disposition_of_property_and_plant_and_equipment = 1000000;
	loss = ois->donation + ois->losses_on_disposition_of_property_and_plant_and_equipment;
	ois->total = profit - loss;
	return ois; //total
}

NIS* NetIncome(int operating_income,int other_income) {
    nis->income_and_loss_before_income_taxes= operating_income+other_income; //���μ�������=��������+�����ܼ���;
	nis->net_income=(double)nis->income_and_loss_before_income_taxes*0.1;
	nis->total = nis->income_and_loss_before_income_taxes - (int)nis->net_income;
	return nis;
}


void Revenue_details_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
    printf("\t\t\t\t1. ��  ǰ  ��  �� : %d\n",sales);
    printf("\t\t\t\t2. ��  Ÿ  ��  �� : %d\n", 0);
}
void CostOfGoodsSold_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
	printf("\t\t\t\t1. ��ǰ ���� ���� : %d\n", sales);
}
void Gross_Profit_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
	printf("\t\t\t\t1. �� �� �� �� �� : %d\n", sales);
}

void Selling_General_And_AdministrationExpense_print() {
	SG_And_A_details_Spec* SG_And_A;
	SG_And_A = Selling_General_And_AdministrationExpense_details();
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
	printf("\t\t\t\t1. �Ǹź�� ������ : %d\n", SG_And_A->total);
	printf("\t\t\t\t -��   ��  : %d\n",SG_And_A->salary);
	printf("\t\t\t\t -�� �� �� : %d\n",SG_And_A->insurance);
	printf("\t\t\t\t -�������: %d\n", SG_And_A->traveling_expenses);
	printf("\t\t\t\t -�����󰢺�: %d\n", SG_And_A->depreciation_cost);
	printf("\t\t\t\t -�� �� �� : %d\n", SG_And_A->rent);
	printf("\t\t\t\t -���ݰ�������:%d\n", SG_And_A->tax_deduction_amount);
	printf("\t\t\t\t -���������� : %d\n", SG_And_A->vehicle_maintenance_costs);
}
void Operating_Income_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
	printf("\t\t\t\t1. ���� ���� : %d\n", sales);

}
void Other_Income_print(int sales,OIS* ois) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
	printf("\t\t\t\t[1] �����ܼ��� : %d\n", 1);
	printf("\t\t\t\t   1.���ݼ���: %d\n", (int)ois->dividend_income);
	printf("\t\t\t\t   2.�Ӵ��    : %d\n", ois->rent);
	printf("\t\t\t\t   3.��α�    : %d\n", ois->donation);
	printf("\t\t\t\t   4.�����ڻ�ó�мս�: %d\n", ois->losses_on_disposition_of_property_and_plant_and_equipment);
}
void NetIncome_print(int sales,NIS* nis) {
	nis->net_income =(double)nis->income_and_loss_before_income_taxes*0.1;
	nis->total = nis->income_and_loss_before_income_taxes - (int)nis->net_income;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  ��  ��\n");
    printf("\t\t\t\t1.���μ�������������:%d\n",nis->income_and_loss_before_income_taxes);
    printf("\t\t\t\t2.���μ����(2������10%):%d\n", (int)nis->net_income);
    printf("\t\t\t\t3. �� �� �� �� �� : %d\n\n\n\n\n", nis->total);
}