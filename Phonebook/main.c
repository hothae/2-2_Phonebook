/* name : main.c ver 1.4
* Content :  main �Լ�
* Implementation : 201513352 ������
*
* Last modified 2021/12/10
*/
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT=1,SHOWALL,SEARCH,DELETE,CHANGE,QUIT};

/*��		�� : int main (void)
* ��		�� : ����� ���� ó��
* ��		ȯ : ���� ����� 0
* 
*/
int main(void)
{
	int inputMenu = 0;

	/* ���α׷� ���۰� ���ÿ� ������ Load! */
	//LoadDataFromFile();
	LoadDataFromFileInstruct();

	while (1)
	{
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
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
			/* ���α׷� ���� �� ������ Store! */
			StoreDataToFileInstruct();
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	return 0;
}
/* end of file */