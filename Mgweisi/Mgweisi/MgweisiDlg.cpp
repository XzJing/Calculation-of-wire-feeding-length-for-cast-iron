
// MgweisiDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Mgweisi.h"
#include "MgweisiDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <stdexcept>


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMgweisiDlg 对话框



CMgweisiDlg::CMgweisiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MGWEISI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMgweisiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_WENZI, wenzi);
	DDX_Control(pDX, IDC_WENZI1, wenzi1);
	DDX_Control(pDX, IDC_WENZI2, wenzi2);
	DDX_Control(pDX, IDC_DANWEI, danwei);
	DDX_Control(pDX, IDC_DANWEI2, danwei2);
	DDX_Control(pDX, IDC_WENZI3, wenzi3);
	DDX_Control(pDX, IDC_DANWEI4, wenzi4);
	DDX_Control(pDX, IDC_DANWEI3, wenzi5);
	DDX_Control(pDX, IDC_JIEGUO, jieguo);
	DDX_Control(pDX, IDCANCEL, wenzi6);
	DDX_Control(pDX, IDC_DANWEI5, danwei5);
	DDX_Control(pDX, IDC_WENZI4, TieShui);
	DDX_Control(pDX, IDC_DANWEI6, danwei6);
	DDX_Control(pDX, IDC_TISHI, tishi);
	DDX_Control(pDX, IDC_TISHIJIEGUO, tishijieguo);
}

BEGIN_MESSAGE_MAP(CMgweisiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMgweisiDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CMgweisiDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMgweisiDlg 消息处理程序

BOOL CMgweisiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 创建一个字体对象
	CFont font;
	font.CreateFont(
		24, // 字体大小，放大
		0, // 字体宽度
		0, // 字体倾斜度，斜体
		0, // 字体方向
		FW_BOLD, // 字体粗细，加粗
		FALSE, // 字体italic
		FALSE, // 字体underline
		FALSE, // 字体strikeout
		ANSI_CHARSET, // 字体字符集
		OUT_DEFAULT_PRECIS, // 输出精度
		CLIP_DEFAULT_PRECIS, // 剪辑精度
		DEFAULT_QUALITY, // 输出质量
		DEFAULT_PITCH | FF_DONTCARE, // 字体 pitch
		_T("宋体") // 字体名称
	);

	// 设置静态文本控件的字体
	wenzi.SetFont(&font);
	wenzi.ModifyStyle(0, SS_CENTER);
	wenzi.SetWindowTextW(TEXT("请输入铁水蠕化参数："));

	wenzi1.SetFont(&font);
	wenzi1.ModifyStyle(0, SS_CENTER);
	wenzi1.SetWindowTextW(TEXT("请输入蠕化线半径："));

	wenzi2.SetFont(&font);
	wenzi2.ModifyStyle(0, SS_CENTER);
	wenzi2.SetWindowTextW(TEXT("良好的喂丝长度应为："));

	wenzi3.SetFont(&font);
	wenzi3.ModifyStyle(0, SS_CENTER);
	wenzi3.SetWindowTextW(TEXT("请输入丝线中Mg含量："));

	TieShui.SetFont(&font);
	TieShui.ModifyStyle(0, SS_CENTER);
	TieShui.SetWindowTextW(TEXT("请输入铁水质量："));

	danwei5.ModifyStyle(0, SS_CENTER);
	danwei5.SetWindowTextW(TEXT("吨"));

	wenzi4.ModifyStyle(0, SS_CENTER);
	wenzi4.SetWindowTextW(TEXT("mol"));

	wenzi5.ModifyStyle(0, SS_CENTER);
	wenzi5.SetWindowTextW(TEXT("％"));

	danwei.ModifyStyle(0, SS_CENTER);
	danwei.SetWindowTextW(TEXT("单位"));

	danwei2.SetWindowTextW(TEXT("厘米"));

	jieguo.ModifyStyle(0, SS_CENTER);
	jieguo.SetWindowTextW(TEXT("N/A "));

	danwei6.ModifyStyle(0, SS_CENTER);
	danwei6.SetWindowTextW(TEXT("米"));

	tishi.SetFont(&font);
	tishi.ModifyStyle(0, SS_CENTER);
	tishi.SetWindowTextW(TEXT("石墨组织情况反馈:"));

	tishijieguo.ModifyStyle(0, SS_CENTER);
	tishijieguo.SetWindowTextW(TEXT(" "));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMgweisiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMgweisiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMgweisiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMgweisiDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMgweisiDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMgweisiDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strEdit1, strEdit2, strEdit3, strEdit4;

	GetDlgItemText(IDC_EDIT1, strEdit1);
	GetDlgItemText(IDC_EDIT2, strEdit2);
	GetDlgItemText(IDC_EDIT3, strEdit3);
	GetDlgItemText(IDC_EDIT4, strEdit4);

	if (strEdit1.IsEmpty() || strEdit2.IsEmpty() || strEdit3.IsEmpty() || strEdit4.IsEmpty())
	{
		AfxMessageBox(_T("输入不能为空"));
	}
	else if (!IsNumeric(strEdit1) || !IsNumeric(strEdit2) || !IsNumeric(strEdit3) || !IsNumeric(strEdit4))
	{
		AfxMessageBox(_T("输入必须为数字"));
	}
	else
	{
		X = _wtof(strEdit1);
		Y = _wtof(strEdit2);
		A = _wtof(strEdit3);
		M = _wtof(strEdit4);

		//球化倾向，不喂丝
		if (X < 0) {
			tishijieguo.ModifyStyle(0, SS_CENTER);
			tishijieguo.SetWindowTextW(TEXT("石墨球化倾向"));
			CString message;
			message.Format(_T("球化倾向值为 X=%.2f"), X);
			AfxMessageBox(message);
		}
		//蠕化正常，不喂丝
		else if (X >= 0 && X <= 0.5) {
			tishijieguo.ModifyStyle(0, SS_CENTER);
			tishijieguo.SetWindowTextW(TEXT("石墨蠕化正常"));
		}
		//片状石墨，需要喂丝
		else if(X > 0.5){
			tishijieguo.ModifyStyle(0, SS_CENTER);
			tishijieguo.SetWindowTextW(TEXT("石墨片状化"));

			//单位换算
			double Ychange = Y / 100;  //cm到m
			double CFe = 56; //Fe的相对原子质量
			double Mchange = (M * 1000000) / CFe; //吨到mol，把Fe的摩尔质量看为铁水的

			//逻辑计算部分
			double Bmax, Bmin; //中间变量喂线Mg的mol数
			Bmin = X / 17 * Mchange;
			Bmax = (X - 0.5) / 17 * Mchange;

			double Lmax, Lmin;
			double density = 10; // 丝线密度，单位g/mol    ！！！！！后续依据实际情况修改！！！！！
			double C = 24.305; //Mg的相对原子质量
			double PI = 3.14159265358979323846; //Π

			Lmax = (Bmax * Mchange * C) / (PI * A * Ychange * Ychange * density) * 1e-6;
			Lmin = (Bmin * Mchange * C) / (PI * A * Ychange * Ychange * density) * 1e-6;

			//结果输出展示部分
			wchar_t buf[256];
			double a = 0; //定义一个常量用于展示输出
			//根据实际情况，喂线长度只能输出大于等于0的情况
			if (Lmax >= 0 && Lmin >= 0) {
				swprintf_s(buf, L"%.2f ~ %.2f", Lmax, Lmin);
				jieguo.SetWindowTextW(buf);
			}
			else if (Lmax >= 0 && Lmin < 0) {
				swprintf_s(buf, L"%.2f ~ %.2f", Lmax, a);
				jieguo.SetWindowTextW(buf);
			}
			else if (Lmax < 0 && Lmin < 0) {
				swprintf_s(buf, L"%.2f ~ %.2f", a, a);
				jieguo.SetWindowTextW(buf);
			}
		}
		
	}

}

//自定义编写的函数用于判断输入值
bool CMgweisiDlg::IsNumeric(CString str)
{
	// 尝试将 CString 转换为 double
	double value;
	return (str.Trim().GetLength() > 0) && (swscanf_s(str, L"%lf", &value) == 1);

}