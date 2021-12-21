/* name : phoneFunc.c ver 1.7
* Content :  ��ȭ��ȣ ��Ʈ�� �Լ�
* Implementation : 201513352 ������
*
* Last modified 2021/12/10
*/
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

/*��		�� : void StoreDataToFileInstruct(void)
* ��		�� : ��� ������ ���Ͽ� ����ü ���� ������ ����
* ��		ȯ : void
*
*/
void StoreDataToFileInstruct(void)
{
	int i;
	FILE* fp = fopen("phoneDataStruct.dat", "wb");

	fwrite(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		/* ����ü ���� ��°�� ���� */
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
	}
	fclose(fp);
}

/*��		�� : void LoadDataFromFileInstruct(void)
* ��		�� : ��� ������ ���Ϸκ��� ����ü ���� ������ ����
* ��		ȯ : void
*
*/
void LoadDataFromFileInstruct(void)
{
	int i;
	FILE* fp = fopen("phoneDataStruct.dat", "rb");

	if (fp == NULL) return;

	fread(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));

		/* ����ü ���� ��°�� ���� */
		fread(phoneList[i], sizeof(phoneData), 1, fp);
	}
	fclose(fp);
}

/*��		�� : void InputphoneData (void)
* ��		�� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
* ��		ȯ : void
*
*/
void InputPhoneData(void)
{
	phoneData* pData;

	if (numOfData >= LIST_NUM) 
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}
	
	pData = (phoneData*)malloc(sizeof(phoneData));	//���� �߰�

	fputs("�̸� �Է� : ", stdout);
	gets_s(pData->name, NAME_LEN);

	fputs("��ȭ��ȣ �Է� : ", stdout);
	gets_s(pData->phoneNum, PHONE_LEN);

	for (int i = 0; i < numOfData; i++) 
	{
		if (!strcmp(phoneList[i]->name, pData->name) && !strcmp(phoneList[i]->phoneNum, pData->phoneNum))
		{
			puts("�̹� �Էµ� ������ �Դϴ�.");
			free(pData);
			getchar();
			return;
		}
	}

	phoneList[numOfData] = pData;
	numOfData++;

	StoreDataToFileInstruct();

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/*��		�� : void ShowAllData (void)
* ��		�� : ����� ������ ��ü ���
* ��		ȯ : void
*
*/
void ShowAlldata(void)
{
	int i;
	for (i = 0; i < numOfData; i++) 
	{
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/*��		�� : void SearchphoneData (void)
* ��		�� : �̸��� ���� ������ �˻�
* ��		ȯ : void
*
*/
void SearchPhoneData(void) 
{
	int i;
	int searchSte = 0;
	char searchName[NAME_LEN] = { 0, };

	fputs("ã�� �̸���? ", stdout);
	gets(searchName);

	for(i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, searchName))
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			searchSte = 1;
		}
	}
		if (searchSte == 0) puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
		else puts("�˻��� �Ϸ�Ǿ����ϴ�.");
		getchar();
}

/*��		�� : void DeletephoneData (void)
* ��		�� : �̸��� �����Ͽ� ������ ����
* ��		ȯ : void
*
*/

void DeletePhoneData(void)
{
	int i;
	char delName[NAME_LEN] = {0,};

	int  idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("ã�� �̸���? ", stdout);
	gets(delName);

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, delName))
			idxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0)
	{
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	else if (matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for (i = 0; i < matchedCount; i++)
		{
			printf("NUM. %d \n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		fputs("���� : ", stdout);
		scanf("%d", &selection);
		while (getchar() != '\n') continue;

		delIdx = idxOfMatchingData[selection - 1];
	}
		free(phoneList[delIdx]);

		for (i = delIdx; i < numOfData - 1; i++)
		{
			phoneList[i] = phoneList[i + 1];
		}
		numOfData--;

		StoreDataToFileInstruct();

		puts("������ �Ϸ�Ǿ����ϴ�.");
		getchar();
}

/*��		�� : void StoreDataToFile(void)
* ��		�� : ��� ������ ���Ͽ� ����
* ��		ȯ : void
*
*/
void StoreDataToFile(void)
{
	int i;
	FILE* fp = fopen("phoneData.dat", "w");

	fwrite(&numOfData, sizeof(int), 1, fp);
	for (i = 0; i < numOfData; i++)
	{
		/* ���ڿ��� ���� ���� ���� \n�� ���� �߿�! */
		fprintf(fp, "%s\n%s\n", phoneList[i]->name, phoneList[i]->phoneNum);
		free(phoneList[i]);
	}
	fclose(fp);
}

/*��		�� : void LoadDataFromFile(void)
* ��		�� : ��� ������ ���Ϸκ��� ����
* ��		ȯ : void
*
*/

void LoadDataFromFile(void)
{
	int i, sLen;
	FILE* fp = fopen("phoneData.dat", "r");
	if (fp == NULL) return;

	fread(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);

		/* ���ڿ� ������ ���� �Էµ� \n ���� ����*/
		sLen = strlen(phoneList[i]->name);
		phoneList[i]->name[sLen - 1] = 0;

		fgets(phoneList[i]->phoneNum,PHONE_LEN,fp);

		sLen = strlen(phoneList[i]->phoneNum);
		phoneList[i]->phoneNum[sLen - 1] = 0;
	}
	fclose(fp);
}

/*��		�� : void ChangePhoneData (void)
* ��		�� : �̸��� �����Ͽ� ��ȭ��ȣ ����
* ��		ȯ : void
*
*/

void ChangePhoneData(void)
{
	int i;
	char searchName[NAME_LEN];
	char newPhoneNumber[PHONE_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("���� ����� �̸���? ", stdout);
	gets(searchName);

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, searchName)) idxOfMatchingData[matchedCount++] = i;
	}
		if (matchedCount == 0)
		{
			puts("���� ��� �̸��� �������� �ʽ��ϴ�.");
			getchar();

			return;
		}
		else if (matchedCount == 1)
		{
			delIdx = idxOfMatchingData[0];
		}
		else
		{
			for (i = 0; i < matchedCount; i++)
			{
				printf("NUM. %d \n", i + 1);
				ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
			}
			fputs("���� : ", stdout);
			scanf("%d", &selection);
			while (getchar() != '\n') continue;

			delIdx = idxOfMatchingData[selection - 1];
		}

		fputs("������ ��ȭ��ȣ��? ", stdout);
		gets(newPhoneNumber);
		strcpy(phoneList[delIdx]->phoneNum, newPhoneNumber);

		StoreDataToFileInstruct();

		puts("������ �Ϸ�Ǿ����ϴ�.");
		getchar();
}
/* end of file */