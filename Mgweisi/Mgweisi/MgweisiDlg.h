
// MgweisiDlg.h: 头文件
//

#pragma once


// CMgweisiDlg 对话框
class CMgweisiDlg : public CDialogEx
{
// 构造
public:
	CMgweisiDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MGWEISI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic wenzi;
	afx_msg void OnEnChangeEdit1();
	CStatic wenzi1;
	CStatic wenzi2;
	CStatic danwei;
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox xuanze;
	CStatic danwei2;
	afx_msg void OnBnClickedOk();
	bool IsNumeric(CString str);
	afx_msg void OnStnClickedWenzi();
	CStatic wenzi3;
	afx_msg void OnStnClickedDanwei3();
	CStatic wenzi4;
	CStatic wenzi5;
	CStatic jieguo;
	double X, Y, A, M; //X为蠕化参数，Y为线半径，A为Mg百分含量，M为铁水质量
	CStatic wenzi6;
	CStatic danwei5;
	CStatic TieShui;
	CStatic danwei6;
	CStatic tishi;
	CStatic tishijieguo;
};
