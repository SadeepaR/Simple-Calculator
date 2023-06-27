
// CALCULATORDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CALCULATOR.h"
#include "CALCULATORDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CCALCULATORDlg dialog



CCALCULATORDlg::CCALCULATORDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCALCULATORDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, output);
	DDX_Control(pDX, IDC_0, button0);
	DDX_Control(pDX, IDC_1, button1);
	DDX_Control(pDX, IDC_2, button2);
	DDX_Control(pDX, IDC_3, button3);
	DDX_Control(pDX, IDC_4, button4);
	DDX_Control(pDX, IDC_5, button5);
	DDX_Control(pDX, IDC_6, button6);
	DDX_Control(pDX, IDC_7, button7);
	DDX_Control(pDX, IDC_8, button8);
	DDX_Control(pDX, IDC_9, button9);

	DDX_Control(pDX, IDC_ADDITION, buttonPlus);
	DDX_Control(pDX, IDC_SUBSTRACTTION, buttonMin);
	DDX_Control(pDX, IDC_REMAINDER, buttonRem);
	DDX_Control(pDX, IDC_POWER, buttonPwr);
	DDX_Control(pDX, IDC_MULTIPLICATION, buttonMul);
	DDX_Control(pDX, IDC_DIVISION, buttonDiv);
	DDX_Control(pDX, IDC_ANSWER, buttonAns);
	DDX_Control(pDX, IDC_EQUAL, buttonEq);
	DDX_Control(pDX, IDC_CLR, buttonClr);
	DDX_Control(pDX, IDC_EDIT1, editResult);
	DDX_Control(pDX, IDC_DOT, buttonPoint);
}

BEGIN_MESSAGE_MAP(CCALCULATORDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_EN_CHANGE(IDC_EDIT1, &CCALCULATORDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_0, &CCALCULATORDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CCALCULATORDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CCALCULATORDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CCALCULATORDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CCALCULATORDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_6, &CCALCULATORDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_8, &CCALCULATORDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CCALCULATORDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_5, &CCALCULATORDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_7, &CCALCULATORDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_EQUAL, &CCALCULATORDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_ADDITION, &CCALCULATORDlg::OnBnClickedAddition)
	ON_BN_CLICKED(IDC_CLR, &CCALCULATORDlg::OnBnClickedClr)
	ON_BN_CLICKED(IDC_MULTIPLICATION, &CCALCULATORDlg::OnBnClickedMultiplication)
	ON_BN_CLICKED(IDC_DIVISION, &CCALCULATORDlg::OnBnClickedDivision)
	ON_BN_CLICKED(IDC_SUBSTRACTTION, &CCALCULATORDlg::OnBnClickedSubstracttion)
	ON_BN_CLICKED(IDC_DOT, &CCALCULATORDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_POWER, &CCALCULATORDlg::OnBnClickedPower)
	ON_BN_CLICKED(IDC_ANSWER, &CCALCULATORDlg::OnBnClickedAnswer)
	ON_BN_CLICKED(IDC_REMAINDER, &CCALCULATORDlg::OnBnClickedRemainder)
END_MESSAGE_MAP()


// CCALCULATORDlg message handlers

BOOL CCALCULATORDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	font.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCALCULATORDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCALCULATORDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCALCULATORDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCALCULATORDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CCALCULATORDlg::addDigit(char digit)
{
	if (output == "0" || newOperation == 1)
	{
		input1.clear();
		decimal1.clear();
		input2.clear();
		decimal2.clear();
		operation1 = 0;
		operation2 = 0;
		operation3 = 0;
		num = 0;
		num1 = 0;
		num2 = 0;
		num3 = 0;
		output = " ";
		UpdateData(FALSE);
		newOperation = 0;
	}
	output += digit;
	UpdateData(FALSE);
}

void CCALCULATORDlg::addResult(float data)
{
	output.Format(_T("%f"), data);
	UpdateData(FALSE);
}

void CCALCULATORDlg::OnBnClicked0()
{
	addDigit('0');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(0);
		else
			decimal1.push_back(0);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(0);
		else
			decimal2.push_back(0);
	}
}


void CCALCULATORDlg::OnBnClicked1()
{
	addDigit('1');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(1);
		else
			decimal1.push_back(1);
		operation2 = 0;
	}
	else{
		if (operation2 != 1)
			input2.push_back(1);
		else
			decimal2.push_back(1);
	}
	
}

void CCALCULATORDlg::OnBnClicked2()
{
	addDigit('2');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(2);
		else
			decimal1.push_back(2);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(2);
		else
			decimal2.push_back(2);
	}
}

void CCALCULATORDlg::OnBnClicked3()
{
	addDigit('3');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(3);
		else
			decimal1.push_back(3);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(3);
		else
			decimal2.push_back(3);
	}
}


void CCALCULATORDlg::OnBnClicked4()
{
	addDigit('4');
	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(4);
		else
			decimal1.push_back(4);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(4);
		else
			decimal2.push_back(4);
	}
}

void CCALCULATORDlg::OnBnClicked5()
{
	addDigit('5');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(5);
		else
			decimal1.push_back(5);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(5);
		else
			decimal2.push_back(5);
	}
}

void CCALCULATORDlg::OnBnClicked6()
{
	addDigit('6');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(6);
		else
			decimal1.push_back(6);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(6);
		else
			decimal2.push_back(6);
	}
}

void CCALCULATORDlg::OnBnClicked7()
{
	addDigit('7');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(7);
		else
			decimal1.push_back(7);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(7);
		else
			decimal2.push_back(7);
	}
}

void CCALCULATORDlg::OnBnClicked8()
{
	addDigit('8');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(8);
		else
			decimal1.push_back(8);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(8);
		else
			decimal2.push_back(8);
	}
}


void CCALCULATORDlg::OnBnClicked9()
{
	addDigit('9');

	if (operation1 != 1) {
		if (operation2 != 1)
			input1.push_back(9);
		else
			decimal1.push_back(9);
		operation2 = 0;
	}
	else {
		if (operation2 != 1)
			input2.push_back(9);
		else
			decimal2.push_back(9);
	}
}



void CCALCULATORDlg::OnBnClickedClr()
{
	output = "0";
	UpdateData(FALSE);

}

void CCALCULATORDlg::OnBnClickedAddition()
{
	newOperation = 0;
	addDigit('+');
	operation1 = 1;
	operation3++;
	Operation();
	oper = 1;
	Print();

}
void CCALCULATORDlg::OnBnClickedSubstracttion()
{
	newOperation = 0;
	addDigit('-');
	operation1 = 1;
	operation3++;
	Operation();
	oper = 2;
	Print();
}


void CCALCULATORDlg::OnBnClickedMultiplication()
{
	newOperation = 0;
	addDigit('*');
	operation1 = 1;
	operation3++;
	Operation();
	oper = 3;
	Print();
}


void CCALCULATORDlg::OnBnClickedDivision()
{
	newOperation = 0;
	addDigit('/');
	operation1 = 1;
	operation3++;
	Operation();
	oper = 4;
	Print();
}




void CCALCULATORDlg::OnBnClickedPower()
{
	newOperation = 0;
	addDigit('^');
	operation1 = 1;
	operation3++;
	Operation();
	oper = 5;
	Print();
}

void CCALCULATORDlg::OnBnClickedRemainder()
{
	newOperation = 0;
	addDigit('%');
	operation1 = 1;
	operation3++;
	Operation();
	oper = 6;
	Print();
}


void CCALCULATORDlg::OnBnClickedDot()
{
	addDigit('.');
	operation2 = 1;
}

void CCALCULATORDlg::Print()
{
	if (operation3 > 1)
	{
		switch (oper)
		{
		case 1: addDigit('+');
			break;
		case 2: addDigit('-');
			break;
		case 3: addDigit('*');
			break;
		case 4: addDigit('/');
			break;
		case 5: addDigit('^');
			break;
		case 6: addDigit('%');
			break;
		default:; break;
		}
	}
	
}

void CCALCULATORDlg::Operation()
{
	if (operation3 == 2)
	{

		int size1 = input1.size();
		int n1 = size1;
		for (int i = 0; i < n1; size1--) {
			num1 = num1 + (input1[i] * pow(10, (size1 - 1)));
			i++;
		}

		int size12 = decimal1.size();
		int n12 = size12;
		for (int i = 0; i < n12; i++) {
			num1 = num1 + (decimal1[i] * pow(10, -(i + 1)));
		}

		int size2 = input2.size();
		int n2 = size2;
		for (int i = 0; i < n2; size2--) {
			num2 = num2 + (input2[i] * pow(10, (size2 - 1)));
			i++;
		}

		int size22 = decimal2.size();
		int n22 = size22;
		for (int i = 0; i < n22; i++) {
			num2 = num2 + (decimal2[i] * pow(10, -(i + 1)));
		}



		switch (oper)
		{
		case 1:num3 = num1 + num2; addResult(num3);
			break;
		case 2: num3 = num1 - num2; addResult(num3); 
			break;
		case 3: num3 = num1 * num2; addResult(num3);
			break;
		case 4: num3 = num1 / num2; addResult(num3); 
			break;
		case 5: num3 = pow(num1,num2); addResult(num3); 
			break;
		case 6: num3 = int(num1) % int(num2); addResult(num3);
			break;
		default: ; break;
		}
		input2.clear();
		decimal2.clear();
		num1 = num3;
		num2 = 0;
		operation3 = 2;
		
	}

	else if (operation3 == 3)
	{
		
		int size2 = input2.size();
		int n2 = size2;
		for (int i = 0; i < n2; size2--) {
			num2 = num2 + (input2[i] * pow(10, (size2 - 1)));
			i++;
		}

		int size22 = decimal2.size();
		int n22 = size22;
		for (int i = 0; i < n22; i++) {
			num2 = num2 + (decimal2[i] * pow(10, -(i + 1)));
		}

		/*num1 = num1 + num2;
		input2.clear();
		decimal2.clear();
		operation3 = 2;
		num2 = 0;*/

		switch (oper)
		{
		case 1:num1 = num1 + num2;addResult(num1); 
			break;
		case 2: num1 = num1 - num2; addResult(num1); 
			break;
		case 3: num1 = num1 * num2; addResult(num1); 
			break;
		case 4: num1 = num1 / num2; addResult(num1); 
			break;
		case 5: num1 = pow(num1,num2); addResult(num1); 
			break;
		case 6: num1 = int(num1)%int(num2); addResult(num1);
			break;
		default:; break;
		}
		input2.clear();
		decimal2.clear();
		operation3 = 2;
		num2 = 0;

	}
}

void CCALCULATORDlg::OnBnClickedEqual()
{
	addResult(operation3);
	if (operation3 == 1)
	{

		int size1 = input1.size();
		int n1 = size1;
		for (int i = 0; i < n1; size1--) {
			num1 = num1 + (input1[i] * pow(10, (size1 - 1)));
			i++;
		}

		int size12 = decimal1.size();
		int n12 = size12;
		for (int i = 0; i < n12; i++) {
			num1 = num1 + (decimal1[i] * pow(10, -(i + 1)));
		}

		int size2 = input2.size();
		int n2 = size2;
		for (int i = 0; i < n2; size2--) {
			num2 = num2 + (input2[i] * pow(10, (size2 - 1)));
			i++;
		}

		int size22 = decimal2.size();
		int n22 = size22;
		for (int i = 0; i < n22; i++) {
			num2 = num2 + (decimal2[i] * pow(10, -(i + 1)));
		}

		switch (oper)
		{
		case 1:num = num1 + num2;
			break;
		case 2: num = num1 - num2;
			break;
		case 3: num = num1 * num2;
			break;
		case 4: num = num1 / num2;
			break;
		case 5: num = pow(num1, num2);
			break;
		case 6: num = int(num1) % int(num2);
			break;
		default:; break;
		}
		addResult(num);
	}
	else if (operation3 == 2)
	{
		int size2 = input2.size();
		int n2 = size2;
		for (int i = 0; i < n2; size2--) {
			num2 = num2 + (input2[i] * pow(10, (size2 - 1)));
			i++;
		}

		int size22 = decimal2.size();
		int n22 = size22;
		for (int i = 0; i < n22; i++) {
			num2 = num2 + (decimal2[i] * pow(10, -(i + 1)));
		}
		switch (oper)
		{
		case 1:num = num1 + num2;
	
			break;
		case 2: num = num1 - num2;
			break;
		case 3: num = num1 * num2;
			break;
		case 4: num = num1 / num2;
			break;
		case 5: num = pow(num1, num2);
			break;
		case 6: num = int(num1) % int(num2);
			break;
		default:; break;
		}
		addResult(num);
		operation3 = 0;
		/*num = num1 + num2;
		operation3 = 0;
		addResult(num);*/
	}
	operation3 = 2;
	input2.clear();
	decimal2.clear();

	newOperation = 1;

}

void CCALCULATORDlg::OnBnClickedAnswer()
{
	OnBnClickedEqual();
}