#include "pch.h"
#include "CEditNumber.h"
BOOL CEditNumber::OnChar(MSG* pMsg) {
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->hwnd == GetSafeHwnd())
        {
            if (!isdigit(pMsg->wParam) && pMsg->wParam != VK_BACK)
            {
                return TRUE;
            }
            else
            {
                MessageBeep(0);
                return FALSE;
            }
        }
    }
}