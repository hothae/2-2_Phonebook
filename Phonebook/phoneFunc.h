/* name : phoneFunc.h ver 1.4
* Content : 전화번호 컨트롤 함수들의 선언
* Implementation : 201513352하태훈
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