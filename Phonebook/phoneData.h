/* name : phoneData.h ver 1.0
* Content : ����ü phoneData�� ���� �� ����
* Implementation : 201513352������
*
* Last modified 2021/11/22
*/

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __phoneData
{
	char name[NAME_LEN];		//�̸�
	char phoneNum[PHONE_LEN];		//��ȭ��ȣ
}phoneData;

#endif
/* end of file */