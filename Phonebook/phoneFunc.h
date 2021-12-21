/* name : phoneFunc.h ver 1.4
* Content : ��ȭ��ȣ ��Ʈ�� �Լ����� ����
* Implementation : 201513352������
*
* Last modified 2021/12/10
*/
#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include "phoneData.h"

void InputPhoneData(void);
void ShowAllData(void);
void SearchPhoneData(void);
void DeletePhoneData(void);
void ChangePhoneData(void);

void StoreDataToFile(void);
void StoreDataToFileInstruct(void);
void LoadDataFromFile(void);
void LoadDataFromFileInstruct(void);

#endif
/* end of file */