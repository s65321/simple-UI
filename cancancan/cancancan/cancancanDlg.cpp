
// cancancanDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "cancancan.h"
#include "cancancanDlg.h"
#include "afxdialogex.h"
#include "fstream"
#include <afx.h>
#include <afxwin.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcancancanDlg 對話方塊



CcancancanDlg::CcancancanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CANCANCAN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcancancanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, EditAge);
	DDX_Control(pDX, IDC_EDIT1, EditName);
	DDX_Control(pDX, IDOK, ButtonAdd);
	DDX_Control(pDX, IDOK2, ButtonDelete);
	DDX_Control(pDX, IDCANCEL, SystemTimeString);
	DDX_Control(pDX, IDC_LIST2, ListCtrl);
}

BEGIN_MESSAGE_MAP(CcancancanDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CcancancanDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CcancancanDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CcancancanDlg::OnBnClickedOk2)
	ON_EN_CHANGE(IDC_EDIT2, &CcancancanDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CcancancanDlg::OnEnChangeEdit1)
	ON_WM_TIMER()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CcancancanDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CcancancanDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcancancanDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CcancancanDlg 訊息處理常式

BOOL CcancancanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定, Timer
	SetTimer(1, 1000, NULL);
	CTime t = CTime::GetCurrentTime();
	CString strTime;
	strTime.Format(_T("%02d:%02d:%02d"), t.GetHour(), t.GetMinute(), t.GetSecond());
	SetDlgItemText(IDC_STATIC3, strTime);

	//設置checkbox和多選
	DWORD dwExStyle = ListCtrl.GetExtendedStyle();
	ListCtrl.SetExtendedStyle(dwExStyle | LVS_EX_CHECKBOXES | LVS_EX_BORDERSELECT);
	//設置這行column header才會出來
	ListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	ListCtrl.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 100);
	ListCtrl.InsertColumn(1, L"年齡" , LVCFMT_LEFT, 100);


	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CcancancanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CcancancanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CcancancanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//加入
void CcancancanDlg::OnBnClickedOk()
{
	CString StringName = L"";
	CString StringAge = L"";
	static int row = 0;
	//加入 ListBox
	EditName.GetWindowTextW(StringName);
	EditAge.GetWindowTextW(StringAge);

	EditName.SetWindowTextW(L"");
	EditAge.SetWindowTextW(L"");

	//加入ListCtrl
	ListCtrl.InsertItem(ListCtrl.GetItemCount(),L"23");
	ListCtrl.SetItemText(ListCtrl.GetItemCount() - 1, 0, StringName);
	ListCtrl.SetItemText(ListCtrl.GetItemCount() - 1, 1, StringAge);
	row++;
	
	ButtonAdd.EnableWindow(FALSE);
}

//關閉
void CcancancanDlg::OnBnClickedCancel()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CDialogEx::OnCancel();
}

//刪除
void CcancancanDlg::OnBnClickedOk2()
{

	//從listctrl
	int rowSelect = 0;
	for (int rowCount = ListCtrl.GetItemCount(); rowCount > 0; rowCount--) {
		/*if (ListCtrl.GetCheck(rowSelect) && (ListCtrl.GetNextItem(-1, LVNI_SELECTED) == -1)) {
			ListCtrl.DeleteItem(rowSelect);
			ListCtrl.DeleteItem(rowSelect);
		}*/
		if (ListCtrl.GetCheck(rowSelect)) {
			ListCtrl.DeleteItem(rowSelect);
		}
		else {
			rowSelect++;
		}
	}
	//關掉按鈕
	if (ListCtrl.GetItemCount() == 0) {
		ButtonDelete.EnableWindow(FALSE);
	}
}

//輸入名字
void CcancancanDlg::OnEnChangeEdit1()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	EditName.SetLimitText(10);
	CString StringName = L"";
	CString StringAge = L"";

	EditName.GetWindowTextW(StringName);
	EditAge.GetWindowTextW(StringAge);
	int AgeFlag = 0;
	int StringLen = StringAge.GetLength();
	switch (StringLen) {
	case 0:
		AgeFlag = 0;
		break;
	case 1:
		AgeFlag = iswdigit(StringAge[0]);
		break;
	case 2:
		AgeFlag = iswdigit(StringAge[0]) & iswdigit(StringAge[1]);
		break;
	case 3:
		AgeFlag = iswdigit(StringAge[0]) & iswdigit(StringAge[1]) & iswdigit(StringAge[2]);
		break;
	default:
		AgeFlag = 0;
	}


	if ((StringName != L"\0") && (AgeFlag != 0)) {
		ButtonAdd.EnableWindow(TRUE);
	}
	else {
		ButtonAdd.EnableWindow(FALSE);
	}
}

//輸入年齡
void CcancancanDlg::OnEnChangeEdit2()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	EditAge.SetLimitText(3);
	CString StringName = L"";
	CString StringAge = L"";

	EditName.GetWindowTextW(StringName);
	EditAge.GetWindowTextW(StringAge);

	int AgeFlag = 0;
	int StringLen = StringAge.GetLength();
	switch (StringLen){
	case 0:
		AgeFlag = 0;
		break;
	case 1:
		AgeFlag = iswdigit(StringAge[0]);
		break;
	case 2:
		AgeFlag = iswdigit(StringAge[0]) & iswdigit(StringAge[1]);
		break;
	case 3:
		AgeFlag = iswdigit(StringAge[0]) & iswdigit(StringAge[1]) & iswdigit(StringAge[2]);
		break;
	default:
		AgeFlag = 0;
	}


	if ((StringName != L"\0") && (AgeFlag != 0)) {
		ButtonAdd.EnableWindow(TRUE);
	}
	else {
		ButtonAdd.EnableWindow(FALSE);
	}
}

//更新系統時間的timer
void CcancancanDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
		//處理
	CTime t = CTime::GetCurrentTime();
	CString strTime;
	strTime.Format(_T("%02d:%02d:%02d"), t.GetHour(), t.GetMinute(), t.GetSecond());
	SetDlgItemText(IDC_STATIC3, strTime);
	CDialogEx::OnTimer(nIDEvent);
}

//點選ListCtrl 的checkbox時，判斷Delete是否亮起
void CcancancanDlg::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int rowCount = ListCtrl.GetItemCount();
	if (ListCtrl.GetItemCount() != 0) {
		ButtonDelete.EnableWindow(TRUE);
	}
}

//點按鈕將csv檔輸出
//這段Code很爛
//基本流程是將csv檔的內容存入read buffer
//將list ctrl的內容存入write buffer
//將read buffer的其中一個項目存入compare buffer，分成Name和Age
//比對compare buffer 和 writer buffer的所有內容，確定write的項目中沒有和csv的內容重疊再寫入

//name age的比對機制可優化，方便擴充
//compare buffer可省略，新增出來純粹是縮排版面
void CcancancanDlg::OnBnClickedButton1()
{
	CString Name = L"Name";
	CString plus = L",";
	CString Age = L"Age";
#if 1
	CStdioFile m_file;
	CString filePath = L"C:\\Users\\HNSD\\Desktop\\Can的工作內容\\新人作業\\HW3\\TEST.csv";
	//創建並寫入標題
	if (!m_file.Open((LPCTSTR)filePath, CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate)) {
		AfxMessageBox(L"文件開啟中，請關閉");
		return;
	}
	m_file.WriteString(Name + plus + Age);
	m_file.WriteString(L"\n");
	m_file.SeekToBegin(); // 後續才讀的到字串

	//讀取資料
	CString strRead;
	
	//比對用buffer
	CString readBuffer[100];
	readBuffer->Empty();
	CString CompareBuffer[2];
	int index;

	// 寫入用buffer
	CString writeBuffer[10][2] = {};
	int rowCount = ListCtrl.GetItemCount();
	for (int i = -rowCount; i < 0; i++) {
		Name = ListCtrl.GetItemText(0, 0);
		Age = ListCtrl.GetItemText(0, 1);
		writeBuffer[i + rowCount][0] = Name;
		writeBuffer[i + rowCount][1] = Age;
		ListCtrl.DeleteItem(0);
	}

	int num = 0;
	int writeFlag = 0;
	for (; m_file.ReadString(strRead); num++) {
		readBuffer[num] = strRead;
	}

	for (int i = 0; i < rowCount; i++) {
		CompareBuffer[0] = writeBuffer[i][0];
		CompareBuffer[1] = writeBuffer[i][1];
		for (int j = 0; j < num; j++) {
			index = readBuffer[j].Find(L",");
			if ((CompareBuffer[0] == readBuffer[j].Left(index)) && (CompareBuffer[1] == readBuffer[j].Right(readBuffer[j].GetLength() - index - 1))) {
				writeFlag = 0;
				break;
			}
			else {
				writeFlag = 1;
			}
		}
		if (writeFlag == 1) {
			m_file.SeekToEnd();//走到資料的最後一行
			m_file.WriteString(writeBuffer[i][0]);
			m_file.WriteString(plus);
			m_file.WriteString(writeBuffer[i][1]);
			m_file.WriteString(L"\n");
			writeFlag = 0;
		}
	}

	m_file.Close();

#endif

#if 0 //拿的到數值
	int n, m ;
	n = m = 0;
	AfxMessageBox(ListCtrl.GetItemText(n,m));
#endif
}

//點擊按鈕將csv檔匯入
void CcancancanDlg::OnBnClickedButton2()	
{
	CString tmpFile;
	CStdioFile openfile;
	CString strFilter = _T("worksheet Files (*.csv)|*.csv|");
	CFileDialog fileSelectedWindow(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter.GetBuffer(), this);
	if (fileSelectedWindow.DoModal() == IDOK) {
		tmpFile = fileSelectedWindow.GetPathName();
		if (openfile.Open(tmpFile, CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate, NULL)) {
			//讀取csv檔案內容並存在buffer內
			CString strRead;
			CString readBuffer[100];
			readBuffer->Empty();
			int csvNum = 0;
			for (; openfile.ReadString(strRead); csvNum++) {
				readBuffer[csvNum] = strRead;
			}

			//讀取listctrl內容並存在buffer內
			CString writeBuffer[10][2] = {};
			int rowCount = ListCtrl.GetItemCount();
			for (int i =0; i < rowCount; i++) {
				writeBuffer[i][0] = ListCtrl.GetItemText(i, 0);
				writeBuffer[i][1] = ListCtrl.GetItemText(i, 1);
			}

			//選擇一個Write，比對所有ReadBuffer內容，確定ListCtrl沒有該項目再將csv內容加入Listctrl
			CString CompareBuffer[2];
			int index;
			int writeFlag = 0;
			for (int j = 1; j < csvNum; j++) {
				index = readBuffer[j].Find(L",");
				CompareBuffer[0] = readBuffer[j].Left(index);
				CompareBuffer[1] = readBuffer[j].Right(readBuffer[j].GetLength() - index - 1);
				for (int i = 0; i < rowCount; i++) {
					if ((CompareBuffer[0] == writeBuffer[i][0]) && (CompareBuffer[1] == writeBuffer[i][1])) {
						writeFlag = 0;
						break;
					}
					else {
						writeFlag = 1;
					}
				}

				if ((writeFlag == 1) || rowCount == 0) {
					ListCtrl.InsertItem(0, L"23");
					ListCtrl.SetItemText(0, 0, CompareBuffer[0]);
					ListCtrl.SetItemText(0, 1, CompareBuffer[1]);
					writeFlag = 0;
				}
			}
		}
	}

}
