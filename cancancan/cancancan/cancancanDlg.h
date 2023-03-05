
// cancancanDlg.h: 標頭檔
//

#pragma once
#include "CEditNumber.h" 

// CcancancanDlg 對話方塊
class CcancancanDlg : public CDialogEx
{
// 建構
public:
	CcancancanDlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CANCANCAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk2();
	CEditNumber EditAge;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CEdit EditName;
	CButton ButtonAdd;
	CButton ButtonDelete;
	CStatic SystemTimeString;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CListCtrl ListCtrl;
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
