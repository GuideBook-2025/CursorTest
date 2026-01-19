
// CursorTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "CursorTest.h"
#include "CursorTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CCursorTestDlg 대화 상자



CCursorTestDlg::CCursorTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CURSORTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCursorTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	// 컨트롤과 멤버 변수 연결
	DDX_Control(pDX, IDC_STATIC_TEXT, m_staticText);
	DDX_Control(pDX, IDC_BUTTON_TEST, m_buttonTest);
	DDX_Control(pDX, IDC_LIST_BOX, m_listBox);
	DDX_Control(pDX, IDC_COMBO_BOX, m_comboBox);
	DDX_Control(pDX, IDC_SCROLL_BAR, m_scrollBar);
	DDX_Control(pDX, IDC_STATIC_SCROLL_VALUE, m_staticScrollValue);
}

BEGIN_MESSAGE_MAP(CCursorTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CCursorTestDlg::OnBnClickedButtonTest)
	ON_BN_CLICKED(IDC_BUTTON_ADD_LIST, &CCursorTestDlg::OnBnClickedButtonAddList)
	ON_BN_CLICKED(IDC_BUTTON_ADD_COMBO, &CCursorTestDlg::OnBnClickedButtonAddCombo)
	ON_LBN_SELCHANGE(IDC_LIST_BOX, &CCursorTestDlg::OnLbnSelchangeListBox)
	ON_CBN_SELCHANGE(IDC_COMBO_BOX, &CCursorTestDlg::OnCbnSelchangeComboBox)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCursorTestDlg 메시지 처리기

BOOL CCursorTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	// CStatic 초기화 - 텍스트 설정
	m_staticText.SetWindowText(_T("초기 상태: 컨트롤이 준비되었습니다."));
	
	// CListBox 초기화 - 초기 항목 추가
	m_listBox.AddString(_T("항목 1"));
	m_listBox.AddString(_T("항목 2"));
	m_listBox.AddString(_T("항목 3"));
	
	// CComboBox 초기화 - 초기 항목 추가
	m_comboBox.AddString(_T("콤보 항목 1"));
	m_comboBox.AddString(_T("콤보 항목 2"));
	m_comboBox.AddString(_T("콤보 항목 3"));
	m_comboBox.SetCurSel(0);  // 첫 번째 항목 선택
	
	// CScrollBar 초기화 - 범위 설정 (0~100)
	m_scrollBar.SetScrollRange(0, 100);
	m_scrollBar.SetScrollPos(0);
	
	// 스크롤 값 표시 초기화
	CString strValue;
	strValue.Format(_T("%d"), 0);
	m_staticScrollValue.SetWindowText(strValue);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCursorTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCursorTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCursorTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// CButton 클릭 이벤트 핸들러
void CCursorTestDlg::OnBnClickedButtonTest()
{
	// CStatic의 텍스트 변경
	m_staticText.SetWindowText(_T("버튼이 클릭되었습니다!"));
	
	// MessageBox로 알림
	MessageBox(_T("CButton 예제: 버튼이 클릭되었습니다."), _T("알림"), MB_OK | MB_ICONINFORMATION);
}

// ListBox에 항목 추가 버튼 클릭 핸들러
void CCursorTestDlg::OnBnClickedButtonAddList()
{
	static int nCount = 4;
	CString strItem;
	strItem.Format(_T("새 항목 %d"), nCount);
	
	// CListBox에 항목 추가
	m_listBox.AddString(strItem);
	nCount++;
	
	m_staticText.SetWindowText(_T("ListBox에 항목이 추가되었습니다."));
}

// ComboBox에 항목 추가 버튼 클릭 핸들러
void CCursorTestDlg::OnBnClickedButtonAddCombo()
{
	static int nCount = 4;
	CString strItem;
	strItem.Format(_T("새 콤보 항목 %d"), nCount);
	
	// CComboBox에 항목 추가
	m_comboBox.AddString(strItem);
	nCount++;
	
	m_staticText.SetWindowText(_T("ComboBox에 항목이 추가되었습니다."));
}

// ListBox 선택 변경 이벤트 핸들러
void CCursorTestDlg::OnLbnSelchangeListBox()
{
	int nSel = m_listBox.GetCurSel();
	if (nSel != LB_ERR)
	{
		CString strItem;
		m_listBox.GetText(nSel, strItem);
		
		CString strText;
		strText.Format(_T("ListBox 선택: %s"), strItem);
		m_staticText.SetWindowText(strText);
	}
}

// ComboBox 선택 변경 이벤트 핸들러
void CCursorTestDlg::OnCbnSelchangeComboBox()
{
	int nSel = m_comboBox.GetCurSel();
	if (nSel != CB_ERR)
	{
		CString strItem;
		m_comboBox.GetLBText(nSel, strItem);
		
		CString strText;
		strText.Format(_T("ComboBox 선택: %s"), strItem);
		m_staticText.SetWindowText(strText);
	}
}

// ScrollBar 스크롤 이벤트 핸들러
void CCursorTestDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// 우리의 ScrollBar인지 확인
	if (pScrollBar == &m_scrollBar)
	{
		int nCurrentPos = m_scrollBar.GetScrollPos();
		int nMin = 0, nMax = 0;
		m_scrollBar.GetScrollRange(&nMin, &nMax);
		
		switch (nSBCode)
		{
		case SB_LEFT:			// 왼쪽 끝
			nCurrentPos = nMin;
			break;
		case SB_RIGHT:			// 오른쪽 끝
			nCurrentPos = nMax;
			break;
		case SB_LINELEFT:		// 왼쪽으로 한 칸
			if (nCurrentPos > nMin)
				nCurrentPos--;
			break;
		case SB_LINERIGHT:		// 오른쪽으로 한 칸
			if (nCurrentPos < nMax)
				nCurrentPos++;
			break;
		case SB_PAGELEFT:		// 왼쪽으로 한 페이지
			nCurrentPos -= 10;
			if (nCurrentPos < nMin)
				nCurrentPos = nMin;
			break;
		case SB_PAGERIGHT:		// 오른쪽으로 한 페이지
			nCurrentPos += 10;
			if (nCurrentPos > nMax)
				nCurrentPos = nMax;
			break;
		case SB_THUMBTRACK:		// 스크롤바 드래그
		case SB_THUMBPOSITION:
			nCurrentPos = nPos;
			break;
		}
		
		// 스크롤 위치 설정
		m_scrollBar.SetScrollPos(nCurrentPos);
		
		// CStatic에 현재 값 표시
		CString strValue;
		strValue.Format(_T("%d"), nCurrentPos);
		m_staticScrollValue.SetWindowText(strValue);
		
		// 메인 Static에도 표시
		CString strText;
		strText.Format(_T("ScrollBar 값: %d"), nCurrentPos);
		m_staticText.SetWindowText(strText);
	}
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
