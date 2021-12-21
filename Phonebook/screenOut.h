/* name : screenout.h ver 1.1
* Content : 콘솔 출력을 위한 함수 선언
* Implementation : 201513352하태훈
*
* Last modified 2021/11/30
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData *pPhone);		//추가 된 선언

#endif
/* end of file */