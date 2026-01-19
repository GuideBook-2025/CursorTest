
// CursorTestDlg.h: 헤더 파일
//

#pragma once


// CCursorTestDlg 대화 상자
class CCursorTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CCursorTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURSORTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 컨트롤 멤버 변수
	CStatic m_staticText;		// CStatic 텍스트 표시
	CButton m_buttonTest;		// CButton 버튼
	CListBox m_listBox;			// CListBox 리스트박스
	CComboBox m_comboBox;		// CComboBox 콤보박스
	CScrollBar m_scrollBar;		// CScrollBar 스크롤바
	CStatic m_staticScrollValue;	// 스크롤 값 표시용 Static

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	// 컨트롤 메시지 핸들러
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnBnClickedButtonAddList();
	afx_msg void OnBnClickedButtonAddCombo();
	afx_msg void OnLbnSelchangeListBox();
	afx_msg void OnCbnSelchangeComboBox();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	DECLARE_MESSAGE_MAP()
};
