#include"Product.h"
#include"account.h"
#include"ShoppingBasket.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"MacroCollection.h"

/*
     1. 매출액 : 상품 총 가격 * 수량

	 2. 매출원가 : 원재료비.  

	 3. 매출총이익 : 매출액 - 매출원가    =  (임의지정)상품 총 가격 30%

	 4. 판매비와 관리비 : 상품과 용역의 판매활동 또는 기업의 관리와 유지에서 
	            발생하는 비용으로 급여(임원급여, 급료, 임금 및 제 수당을 포함한다), 
				퇴직급여, 명예퇴직금(조기퇴직의 대가로 지급하는 인센티브 등을 포함한다), 
				복리후생비, 임차료, 접대비, 감가상각비, 무형자산상각비, 세금과공과, 광고선전비, 
				연구비, 경상개발비, 대손상각비 등 매출원가에 속하지 아니하는 모든 영업비용을 포함한다
				--과세표준   법인세율
               2억 원 이하     10%
     2억 원 초과 200억 이하    20%
   200억 초과 3천억 원 이하    22%
              3천억 원 초과    25%

			  급여: 900만원 (직원3) 4대보험금액 : 584,573원(3인)
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
	printf("\n\n\t┌────────────────────────────────────────────────────────────────────────────────┐\n\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t\t ---------------------------------\t\t\t │\n");
	printf("\t│\t\t\t |   성 결 마 트 손 익 계 산 서  |\t\t\t │\n");
	printf("\t│\t\t\t ---------------------------------\t\t\t │\n\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t\t\t(0)메인화면으로가기\t\t\t\t │\n\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t손익반영방식: 즉시 반영     법 인 명 : 성결마트\t\t\t │\n\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t                            사업자등록번호 : 20180850\t\t │\n\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t\t      |      계 정 과 목       |\t\t\t │\n\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t\t\t (1)매  출  액     : %d\t\t\t\t │\n ", income->revenue);
	printf("\t│\t\t\t\t (2)매 출 원 가    : %d\t\t\t\t │\n ", income->Cost_of_goods_sold);
	printf("\t│\t\t\t\t (3)매 출 총 이 익 : %d\t\t\t\t │\n", income->gross_profit);
	printf("\t│\t\t\t\t (4)판매비와관리비 : %d\t\t\t\t │\n", income->SG_and_A->total);
	printf("\t│\t\t\t\t (5)영 업 손 익    : %d\t\t\t\t │\n", income->operating_income);
	printf("\t│\t\t\t\t (6)영 업 외 수 익 : %d\t\t\t\t │\n", income->other_income->total);
	printf("\t│\t\t\t\t (7)당 기 순 이 익 : %d\t\t\t\t │\n", income->NI->total);
	printf("\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t│\t\t\t\t\t\t\t\t\t\t │\n"); 
	printf("\t│\t\t\t\t\t\t\t\t   이사장:이상민 │\n");
	printf("\t│\t\t\t\t\t\t\t\t\t\t │\n");
	printf("\t└────────────────────────────────────────────────────────────────────────────────┘\n");
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
		printf("메인화면으로 돌아갑니다.");
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
      각각 세목별로 함수마다 출력하고 그함수값 계산해서 매출액 매출총이익 등등 계산     

  
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
    nis->income_and_loss_before_income_taxes= operating_income+other_income; //법인세차감전=영업이익+영업외손익;
	nis->net_income=(double)nis->income_and_loss_before_income_taxes*0.1;
	nis->total = nis->income_and_loss_before_income_taxes - (int)nis->net_income;
	return nis;
}


void Revenue_details_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
    printf("\t\t\t\t1. 상  품  매  출 : %d\n",sales);
    printf("\t\t\t\t2. 기  타  매  출 : %d\n", 0);
}
void CostOfGoodsSold_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
	printf("\t\t\t\t1. 상품 매출 원가 : %d\n", sales);
}
void Gross_Profit_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
	printf("\t\t\t\t1. 매 출 총 이 익 : %d\n", sales);
}

void Selling_General_And_AdministrationExpense_print() {
	SG_And_A_details_Spec* SG_And_A;
	SG_And_A = Selling_General_And_AdministrationExpense_details();
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
	printf("\t\t\t\t1. 판매비와 관리비 : %d\n", SG_And_A->total);
	printf("\t\t\t\t -급   여  : %d\n",SG_And_A->salary);
	printf("\t\t\t\t -보 험 료 : %d\n",SG_And_A->insurance);
	printf("\t\t\t\t -여비교통비: %d\n", SG_And_A->traveling_expenses);
	printf("\t\t\t\t -감가상각비: %d\n", SG_And_A->depreciation_cost);
	printf("\t\t\t\t -임 차 료 : %d\n", SG_And_A->rent);
	printf("\t\t\t\t -세금과공과금:%d\n", SG_And_A->tax_deduction_amount);
	printf("\t\t\t\t -차량유지비 : %d\n", SG_And_A->vehicle_maintenance_costs);
}
void Operating_Income_print(int sales) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
	printf("\t\t\t\t1. 영업 손익 : %d\n", sales);

}
void Other_Income_print(int sales,OIS* ois) {
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
	printf("\t\t\t\t[1] 영업외손익 : %d\n", 1);
	printf("\t\t\t\t   1.배당금수익: %d\n", (int)ois->dividend_income);
	printf("\t\t\t\t   2.임대료    : %d\n", ois->rent);
	printf("\t\t\t\t   3.기부금    : %d\n", ois->donation);
	printf("\t\t\t\t   4.유형자산처분손실: %d\n", ois->losses_on_disposition_of_property_and_plant_and_equipment);
}
void NetIncome_print(int sales,NIS* nis) {
	nis->net_income =(double)nis->income_and_loss_before_income_taxes*0.1;
	nis->total = nis->income_and_loss_before_income_taxes - (int)nis->net_income;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t  세  목\n");
    printf("\t\t\t\t1.법인세차감전순손익:%d\n",nis->income_and_loss_before_income_taxes);
    printf("\t\t\t\t2.법인세비용(2억이하10%):%d\n", (int)nis->net_income);
    printf("\t\t\t\t3. 당 기 순 이 익 : %d\n\n\n\n\n", nis->total);
}