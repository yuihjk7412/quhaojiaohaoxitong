
// LiningSystemDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "LiningSystem.h"
#include "LiningSystemDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

wstring string2wstring(string str);
// CLiningSystemDlg 对话框



CLiningSystemDlg::CLiningSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LININGSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLiningSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mEdita);
	DDX_Control(pDX, IDC_EDIT2, mEditb);
	DDX_Control(pDX, IDC_EDIT3, mEditc);
	DDX_Control(pDX, IDC_EDIT4, mEditac);
	DDX_Control(pDX, IDC_EDIT5, mEditbc);
	DDX_Control(pDX, IDC_EDIT6, mEditcc);
	DDX_Control(pDX, IDC_EDIT7, mEditCaptiona);
	DDX_Control(pDX, IDC_EDIT8, mEditCaptionb);
	DDX_Control(pDX, IDC_EDIT9, mEditCaptionc);
}

BEGIN_MESSAGE_MAP(CLiningSystemDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLiningSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLiningSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CLiningSystemDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT7, &CLiningSystemDlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON4, &CLiningSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CLiningSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CLiningSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CLiningSystemDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CLiningSystemDlg 消息处理程序

BOOL CLiningSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	mEditCaptiona.SetWindowText((CA2T)"a部门叫号");
	mEditCaptionb.SetWindowText((CA2T)"b部门叫号");
	mEditCaptionc.SetWindowText((CA2T)"c部门叫号");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLiningSystemDlg::OnPaint()
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
HCURSOR CLiningSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLiningSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	LineSystem.quhao('a');
	LPCTSTR result = LineSystem.aDepartmentWaitingList;
	mEdita.SetWindowText(result);
}


void CLiningSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	LineSystem.quhao('b');
	LPCTSTR result = LineSystem.bDepartmentWaitingList;;
	mEditb.SetWindowText(result);
}


void CLiningSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	LineSystem.quhao('c');
	LPCTSTR result = LineSystem.cDepartmentWaitingList;;
	mEditc.SetWindowText(result);
	
}


void CLiningSystemDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CLiningSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	LineSystem.jiaohao('a');
	LPCTSTR showstring = LineSystem.aDepartmentWaitingList;;
	mEdita.SetWindowText(showstring);
	showstring = LineSystem.aDepartmentCalling;
	mEditac.SetWindowText(showstring);
}


void CLiningSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	LineSystem.jiaohao('b');
	LPCTSTR result = LineSystem.bDepartmentWaitingList;
	mEditb.SetWindowText(result);
	result = LineSystem.bDepartmentCalling;
	mEditbc.SetWindowText(result);
}


void CLiningSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	LineSystem.jiaohao('c');
	LPCTSTR result = LineSystem.cDepartmentWaitingList;
	mEditc.SetWindowText(result);
	result = LineSystem.cDepartmentCalling;
	mEditcc.SetWindowText(result);
}


//将string转换成wstring  
wstring string2wstring(string str)
{
	wstring result;
	//获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//多字节编码转换成宽字节编码  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //添加字符串结尾  
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}


void CLiningSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
