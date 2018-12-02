#ifndef ACCOUNT_H
#define ACCOUNT_H

#include"Product.h"

typedef struct sales_volume {
	int productMoney;
	int productQuantity;
	int productSum;
}SALES;
typedef struct Selling_General_And_AdministrationExpense_details_Specifications {
	int salary;
	int insurance;
	int traveling_expenses;
	int depreciation_cost;
	int rent;
	int tax_deduction_amount;
	int vehicle_maintenance_costs;
	int total;
}SG_And_A_details_Spec;
SG_And_A_details_Spec* sg_and_a_details_spec;
SG_And_A_details_Spec* SG_And_A;
typedef struct OtherIncomeSpecifications {
	double dividend_income;
	int rent;
	int donation;
	int losses_on_disposition_of_property_and_plant_and_equipment;
	int total;
}OIS;
OIS* ois;
typedef struct NetIncomeSpecifications {
	int income_and_loss_before_income_taxes;
	double net_income;
	int total;
}NIS;
NIS* nis;
typedef struct Income_statement{ //손익계산서
	int revenue;              //매출액
	int Cost_of_goods_sold;//매출원가 Cost_of_goods_sold
	int gross_profit;        //매출총이익
	SG_And_A_details_Spec* SG_and_A; //판관비
	int	operating_income;// 영업이익
	OIS* other_income; //영업외수익
	NIS* NI;         // 당기순이익
}INCOME;
INCOME *income;


SALES account_revenue;
void specification(int ctrl,int revenue);
SALES Revenue(SALES sales);
int Revenue_details(int sales);
int CostOfGoodsSold(int sales);
int Gross_Profit(int sales,int cost);

SG_And_A_details_Spec* Selling_General_And_AdministrationExpense(SG_And_A_details_Spec* SG_A_A);
SG_And_A_details_Spec* Selling_General_And_AdministrationExpense_details(); // 판관비 계정과목
int Operating_Income(int sales,int sell);
OIS* Other_Income();
NIS* NetIncome(int sales,int other);

void account_display();

void Revenue_details_print(int sales);
void CostOfGoodsSold_print(int sales);
void Gross_Profit_print(int sales);
void Selling_General_And_AdministrationExpense_print();
void Operating_Income_print(int sales);
void Other_Income_print(int sales, OIS* ois);
void NetIncome_print(int sales, NIS* nis);

void typeInit();
void freeInit();
#endif //ACCOUNT_H