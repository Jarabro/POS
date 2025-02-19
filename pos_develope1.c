/*
 * 제목 : POS 개발
 * 제작자 : 이정호 (LEE JUNG HO)
 * 버전 : 0.0.1 
 * 제작기간 : 2025-02-14 ~ ing
 * 최근 수정일자 : 2025-02-19
 * Project POS
 */

#include <stdio.h>		//	입출력 헤더 호출
#include <string.h>		//	스트링 헤더 호출
#include <time.h>		//	타임 헤더 호출
#include <stdlib.h>
		
#define NAME_LENGTH 50
void login_check();		// 로그인 함수 선언
void employee_confirmation();
int show_menu();
void insert_menu();
void product_check_menu();
void product_receving_menu();
void paying_menu();
void product_buy();
int adult_checking();

struct Product
{
	char name[NAME_LENGTH];
	char company[NAME_LENGTH];
	char time[NAME_LENGTH];
	int adult;
	int price;
	int product_total;
};
//전역변수들




int product_buy_num = 0;
struct Product productlist[100];
int product_count = 0;
int num = 0;
unsigned int balance = 1234000u;
int main()
{
	const char identification[10] = "admin";		//ID 설정 (초기 ID : admin)
	const char password[10] = "1234";				//Password설정 (초기 password : 1234)
	const char name_1[20] = "Lee Jung Ho";
	char check_name[20] = "확인";
	int select_menu = 0;
	char product_name[20], product_company[20], product_time_limit[20], product_check_adult[20];
	int product_price[20];
	int time_pay = 9200;
	int time_min = 0;
	int day_money = 0;
	time_t start = time(NULL);
	

	login_check(identification, password);
	employee_confirmation(name_1, check_name);
	while(1){	
		printf("잔고 : %d\n", balance);
	select_menu = show_menu();
		if(select_menu == 1)
		{
			insert_menu();
		}
		else if(select_menu == 2)
		{
			product_check_menu();
		}
		else if(select_menu == 3)
		{
			product_receving_menu();
		}
		else if(select_menu == 4)
		{
			paying_menu();
		}
		else if(select_menu == 5)
		{
			time_t end = time(NULL);
			time_min = (double)(end - start) / 60;
			day_money = time_pay * time_min;
			printf("총 %d분 일했습니다 오늘 일당은: %d\n", time_min, day_money);
			break;
		}
		else
		{
			printf("잘못입력하셨습니다. 1~5번 입력해주세요");
		}
	}
	return 0;
}

//로그인 함수 선언 (아이디와 비밀번호가 맞는지 확인하는 함수)
void login_check(char arr1[10], char arr2[10])	//admin과 1234를 arr1, arr2에 받는다
{
	char check_identification[10];			//아이디를 확인하기위한 문자형 배열 선언
	char check_password[10];				//비밀번호를 확인하기위한 문자형 배열 선언
	while(1){
	printf("============Login Menu================ \n");
	printf("insert id: ");					
	scanf("%s", check_identification);		//check_identification에 입력받기
	
	printf("insert password: ");
	scanf("%s", check_password);			//check_password에 입력받기
	printf("====================================== \n");
	if(!strcmp(arr1, check_identification) && !strcmp(arr2, check_password))	// 아이디와 비밀번호가 둘다 맞는경우 login access 출력
	{
		printf("login access\n");
		break;
	}
	else																		//아이디 혹은 비밀번호가 둘중 하나라도 틀리면 login default 출력
	{
		printf("login default try again\n");
	}
	}
	system("clear");
}
//사원 확인 하기
void employee_confirmation(char name[20], char check_name[20])
{	
	char check_employee[20];
	
	printf("===================================== \n");
	printf("사원 : %s", name);
	printf("사원이 맞습니까? 맞다면 ""확인"" 을입력하세요: ");
	scanf("%s", check_employee);
	
	if(!strcmp(check_name, check_employee)) //확인 입력시 메인함수 다음 구문  진행
	{
		printf("확인되었습니다 \n");	
	}
	else									//확인외 다른거 입력시 종료
	{
		printf("다시실행하세요\n");
		exit(0);
	}			
	system("clear");
}
//메뉴 보여주기;
int show_menu()
{
	int select_menu = select_menu;
	printf("==================================== \n");
	printf("1.제품 입력\t2.제품 확인(제품 찾기)\t3.제품 입고\t4.계산\t5.종료 \n");
	printf("메뉴 선택(숫자 입력1~5): ");
	scanf("%d", &select_menu);
	printf("==================================== \n");
	system("clear");
	return select_menu;
}	
//제품 입력 메뉴
void insert_menu()
{
	int product_plus = 0;
	if(num == 0) //이건 입고가 아닐시 출력하는거
	{
		if(product_count < 10)
		{
			printf("최소 제품입력은 10개입니다.");			//처음실행시 제품입력 10개하기
			for(int i = 0; i < 10; i++){
				printf("현재 제품입력수 [%d 개]\n", product_count);
				printf("제품명입력: "); scanf("%s", productlist[product_count].name);
				printf("제조회사입력: "); scanf("%s", productlist[product_count].company);
				printf("유통기한입력: "); scanf("%s", productlist[product_count].time);
				printf("19금물품유무(0or1(19)입력하세요): "); scanf("%d", &(productlist[product_count].adult));
				printf("가격: "); scanf("%d", &(productlist[product_count].price));
				printf("제품 추가 완료\n");
				product_count++;
			}
		}
		else if(product_count < 101 && product_count >= 10)			//제품이 10개이상이면 무조건 1개씩 제품추가
		{
			printf("제품명입력: "); scanf("%s", productlist[product_count].name);
			printf("제조회사입력: "); scanf("%s", productlist[product_count].company);
			printf("유통기한입력: "); scanf("%s", productlist[product_count].time);
			printf("19금물품유무(0or1(19)입력하세요):"); scanf("%d", &(productlist[product_count].adult));
			printf("가격: "); scanf("%d", &(productlist[product_count].price));
			printf("제품 추가 완료\n");
			product_count++;
		}
		else
		{
			printf("제품을 추가할 수 없습니다. \n");
		}
		
		system("clear");
}	

	else if(num != 0)					//제품 입고시 출력하는것
		{
			printf("몇개 입고하시겠습니까?: ");
			scanf("%d", &product_plus); //product_total
			productlist[num-1].product_total += product_plus;
			num = 0;
	
	}
	
}
//제품확인메뉴
void product_check_menu()
{
	char product_find[50];
	for(int i = 0; i < product_count; i++)
	{
		printf("%s ", productlist[i].name);

		for(int j = 0; j < productlist[i].product_total; j++)
		{
			printf("* ");
		}

		printf("(%d개)", productlist[i].product_total);
		printf("\n");
	}
	printf("찾으실 제품을 입력하세요: ");
	scanf("%s", product_find);
	for(int i = 0; i < product_count; i++)
	{
		if(!strcmp(productlist[i].name, product_find))
		{
			printf("이름:%s |제조회사: %s|유통기한: %s|19금물품: %d|가격: %d \n", 
					productlist[i].name, productlist[i].company, productlist[i].time, productlist[i].adult, productlist[i].price);
		}
	}
	printf("\n");

}
//제품 입고 메뉴
void product_receving_menu()
{
	
	printf("제품 목록 \n");
	for(int i = 0; i < product_count; i++)
	{
		printf("%d.이름: %s | 제조회사: %s | 유통기한:%s | 19금물품: %d | 가격: %d \n", 
		i+1, productlist[i].name, productlist[i].company, productlist[i].time, productlist[i].adult, productlist[i].price);
	}
	printf("어떤 상품을 입고하시겠습니까? 번호입력: ");		//상품 입고 번호 입력
	scanf("%d", &(num));	//전역변수 num에다가 받음
	printf("==============================================\n");
	insert_menu();		//그후 인서트 메뉴로 진행
	
}
//제품 구매 메뉴
void paying_menu()
{
	int adult_check = 0;					//성인인증 리턴값 받을 변수
	char productname[50];
	for(int i=0; i < product_count; i++)	//제품목록을 보여준다
	{
		printf("%d. 제품이름:%s \t|제조회사:%s \t|유통기한:%s \t|성인물품:%d \t|가격:%d \t|남은갯수:%d |\n",
				i+1, productlist[i].name, productlist[i].company, productlist[i].time, productlist[i].adult, productlist[i].price, productlist[i].product_total);
	}

	printf("어떤 제품을 구입하시겠습니까?(제품이름 입력): ");
	scanf("%s", productname);	//제품구매 이름  입력받음 productname에 저장;
	for(int i = 0; i < product_count; i++)
	{	
		if(!strcmp(productlist[i].name, productname)) //제품이름 확인
		{
			if(productlist[i].product_total > 0) //제품개수가 1개이상이면 실행
			{
				if(productlist[i].adult > 0)//성인물품일시
				{
					printf("성인물품입니다.\n");
					printf("성인인증을 진행하겠습니다.");
					adult_check = adult_checking();
					//유통기한 체크함수만들기
					if(adult_check == 1) // 리턴값이 1일시 성인인증 통과
					{
						product_buy(productlist[i].price,productlist[i].product_total); //계산진행함수 call
						if(product_buy_num > 0) //구매개수가 1개이상일때만 진행
						{
							productlist[i].product_total -= product_buy_num; //재고갯수 제거
						}
					}
					else//리턴값이 1이 아닐시 성인인증 실패 !
					{
						printf("미성년자입니다. 따끔하게 혼내세요!");
					}
					break;
				}
				else//성인물품이 아닐시 
				{
					//유통기한 체크함수 만들기
					product_buy(productlist[i].price,productlist[i].product_total);
					if(product_buy_num > 0) //구매개수가 1개이상일때만 진행
					{
						productlist[i].product_total -= product_buy_num;
					}
					break;
				}
			}
		}
	}//for문종료
}
//제품 구매 함수
void product_buy(int price, int total)
{
	int card_cash = 0;
	int card = 0;
	unsigned int cash = 0u;
	printf("몇개 구입?: ");
	scanf("%d", &(product_buy_num));
	if(product_buy_num > 0 && product_buy_num <= total)
	{
		printf("카드or현금?(카드1현금2):");
		scanf("%d", &card_cash);
		if(card_cash == 1)
		{
			
			printf("카드결제금액을 입력하세요: ");
			scanf("%d", &card);
			balance += price * product_buy_num; // 물건값 * 사는갯수를 잔고에서 차감
			printf("결제금액: %d 입니다. \n", price*product_buy_num);
		}
		else if(card_cash == 2)
		{
			printf("얼마를 내시겠습니까?: ");
			scanf("%d", &cash);
			if(price * product_buy_num < cash) // 낸 현금이 물건값보다 많을시 진행
			{
				balance +=  price * product_buy_num; // 물건값 * 사는갯수를 잔고에서 차감
				cash = cash - price * product_buy_num;
				printf("결제금액: %d 입니다. 거스름돈: %d\n", price*product_buy_num, cash);
			}
			if(price * product_buy_num > cash) //낸 현금이 물건값보다 적을시 진행
			{
				printf("현금이 부족합니다.\n");
				product_buy_num = 0;		//구매개수를 0으로 초기화
			}
		}
		else
		{
			printf("1개이상 구매하셔야합니다.\n");
		}
	}
	else
	{
		printf("구매취소하셨습니다\n");
	}
}

int adult_checking()
{
	int year = 2025;
	int birthyear = 0;
	printf("태어난 연도를 적어주세요: ");
	scanf("%d", &birthyear);
	
	year = year - birthyear;
	
	if(year >= 19)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


