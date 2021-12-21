/* name : screenOut.c ver 1.3
* Content :  �ܼ� ����� ���� �Լ� ����
* Implementation : 201513352 ������
*
* Last modified 2021/12/10
*/
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "phoneData.h"

/*��		�� : void ShowMenu (void)
* ��		�� : ������ ���� �޴� ���
* ��		ȯ : void
*
*/
void ShowMenu(void)
{
	system("cls");		// stdlib.h
	printf("201513352������\n");
	printf("��������������	��		�� �������������� \n");
	printf(" 1. ��ȭ��ȣ �Է� \n");
	printf(" 2. ��ü ���� ��� \n");
	printf(" 3. ��ȭ��ȣ �˻� \n");
	printf(" 4. ��ȭ��ȣ ���� \n");
	printf(" 5. ��ȭ��ȣ ���� \n");
	printf(" 6. ���� \n");
	printf("���������������������������������������������������������������������� \n");
	printf(" ����>> ");
}

/*��		�� : void ShowPhoneInfo (phoneData phone)
* ��		�� : �̸��� ��ȭ��ȣ ���� ���
* ��		ȯ : void
*
*/
void ShowPhoneInfo(phoneData phone)
{
	printf("�Ǧ����������������������������������������������� \n");
	printf("�� �� �̸� : %s \n", phone.name);
	printf("�� �� ��ȭ��ȣ : %s \n", phone.phoneNum);
	printf("�������������������������������������������������� \n\n");
}
/*��		�� : void ShowPhoneInfoByPtr(phoneData* pPhone)
* ��		�� : �̸��� ��ȭ��ȣ ���� ���
* ��		ȯ : void
*
*/

void ShowPhoneInfoByPtr(phoneData* pPhone)
{
	printf("�Ǧ����������������������������������������������� \n");
	printf("�� �� �̸� : %s \n", pPhone->name);
	printf("�� �� ��ȭ��ȣ : %s \n", pPhone->phoneNum);
	printf("�������������������������������������������������� \n\n");
}
/* end of file */