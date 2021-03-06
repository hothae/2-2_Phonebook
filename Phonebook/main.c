/* name : main.c ver 1.4
* Content :  main 함수
* Implementation : 201513352 하태훈
*
* Last modified 2021/12/10
*/
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT=1,SHOWALL,SEARCH,DELETE,CHANGE,QUIT};

/*함		수 : int main (void)
* 기		능 : 사용자 선택 처리
* 반		환 : 정상 종료시 0
* 
*/
int main(void)
{
	int inputMenu = 0;

	/* 프로그램 시작과 동시에 데이터 Load! */
	//LoadDataFromFile();
	LoadDataFromFileInstruct();

	while (1)
	{
		ShowMenu();
		fputs("선택하세요 : ", stdout);
		scanf("%d", &inputMenu);
		while (getchar() != '\n') continue;

		switch (inputMenu)
		{
		case INPUT:
			InputPhoneData();
			break;

		case SHOWALL:
			ShowAlldata();
			break;

		case SEARCH:
			SearchPhoneData();
			break;

		case DELETE:
			DeletePhoneData();
			break;

		case CHANGE:
			ChangePhoneData();
			break;
		}

		if (inputMenu == QUIT)
		{
			/* 프로그램 종료 시 데이터 Store! */
			StoreDataToFileInstruct();
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	return 0;
}
/* end of file */