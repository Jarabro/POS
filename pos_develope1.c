/*
 * 제목 : POS 개발
 * 제작자 : 이정호 (LEE JUNG HO)
 * 버전 : 0.0.1 
 * 제작기간 : 2025-02-14 ~ ing
 * 최근 수정일자 : 2025-02-18
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
int paying_menu();

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

struct Product productlist[100];
int product_count = 0;
int num = 0;
int main()
{
	const char identification[10] = "admin";		//ID 설정 (초기 ID : admin)
	const char password[10] = "1234";				//Password설정 (초기 password : 1234)
	const char name_1[20] = "Lee Jung Ho";
	char check_name[20] = "확인";
	unsigned int balance = 1234000u;
	int select_menu = 0;
	char product_name[20], product_company[20], product_time_limit[20], product_check_adult[20];
	int product_price[20];
	login_check(identification, password);
	employee_confirmation(name_1, check_name);
	while(1){	
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
}
//메뉴 보여주기;
int show_menu()
{
	int select_menu = select_menu;
	printf("==================================== \n");
	printf("1.제품 입력\t2.제품 확인\t3.제품 입고\t4.계산\t5.종료 \n");
	printf("메뉴 선택(숫자 입력1~5): ");
	scanf("%d", &select_menu);
	printf("==================================== \n");
	return select_menu;
}	
//제품 입력 메뉴
void insert_menu()
{
	int product_plus = 0;
	if(num == 0)
	{
		if(product_count < 10)
		{
			printf("최소 제품입력은 10개입니다.");
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
		else if(product_count < 101 && product_count >= 10)
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
	}	
	else if(num != 0)
		{
			printf("몇개 입고하시겠습니까?: ");
			scanf("%d", &product_plus); //product_total
			productlist[num-1].product_total += product_plus;
			num = 0;
	
	}
	
}

void product_check_menu()
{
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
	printf("\n");
}

void product_receving_menu()
{
	
	printf("제품 목록 \n");
	for(int i = 0; i < product_count; i++)
	{
		printf("%d.이름: %s | 제조회사: %s | 유통기한:%s | 19금물품: %d | 가격: %d \n", 
		i+1, productlist[i].name, productlist[i].company, productlist[i].time, productlist[i].adult, productlist[i].price);
	}
	printf("어떤 상품을 입고하시겠습니까? 번호입력: ");
	scanf("%d", &(num));
	printf("==============================================");
	insert_menu();
}

int paying_menun(unsigned int balance)
{
	printf("번호\t|제품\t|가격\t|(1)성인물품\n");
	for(int i = 0; i < product_count; i++)
	{
		printf("%d\t| %s\t| %d\t| %d ", i+1, productlist[i].name, productlist[i].price, productlist[i].adult);
	}
	printf("어떤 제품을 구매하시겠습니까?");
}
