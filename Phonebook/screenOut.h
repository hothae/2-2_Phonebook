/* name : screenout.h ver 1.1
* Content : �ܼ� ����� ���� �Լ� ����
* Implementation : 201513352������
*
* Last modified 2021/11/30
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData *pPhone);		//�߰� �� ����

#endif
/* end of file */