/*
 * 제목 : POS 개발
 * 제작자 : 이정호 (LEE JUNG HO)
 * 버전 : 0.0.1 
 * 제작기간 : 2025-02-14 ~ ing
 * 최근 수정일자 : 2025-02-17
 * Project First
 */

#include <stdio.h>		//	입출력 헤더 호출
#include <string.h>		//	스트링 헤더 호출
#include <time.h>		//	타임 헤더 호출
#include <stdlib.h>
						
void login_check();		// 로그인 함수 선언
void employee_confirmation();
int show_menu();
int insert_menu();

int main()
{
	char identification[10] = "admin";		//ID 설정 (초기 ID : admin)
	char password[10] = "1234";				//Password설정 (초기 password : 1234)
	char name_1[20] = "Lee Jung Ho";
	char check_name[20] = "확인";
	unsigned int balance = 1234000u;
	int select_menu = 0;

	login_check(identification, password);
	employee_confirmation(name_1, check_name);
	select_menu = show_menu();
	if(select_menu == 1)
	{
		insert_menu();
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
//메뉴 보여주기
int show_menu()
{
	int select_menu = select_menu;
	printf("1.제품 입력\t2.제품 확인\t3.제품 입고\t4.계산\t5.종료 \n");
	printf("메뉴 선택(숫자 입력1~5): ");
	scanf("%d", &select_menu);
	return select_menu;
}	

int insert_menu()
{
	char product_insert [20] = {};
	char product_company [20] = {};
	char product_time_limit [20] = {};
	char product_adult [20] = {};
	int product_price [20] = {};
	printf("제품메뉴구성 \n");
	printf("1.제품명입력:");
	scanf("%c", &product_insert[i]);
	printf("2.제조회사입력:");
	scanf("");
	printf("3.유통기한입력:");
	scanf("");
	printf("4.19금물품유무");
	scanf("");
	printf("5.가격");
	scanf("");
}

