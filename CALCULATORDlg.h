
// CALCULATORDlg.h : header file
//

#pragma once
#include <string>
#include <vector>

// CCALCULATORDlg dialog
class CCALCULATORDlg : public CDialogEx
{
// Construction
public:
	CCALCULATORDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	
private:
	CString output;
	CString output2;
	CFont font;
	float num1 = 0;
	float num2 = 0; 
	float num3;
	void addDigit(char digit);
	void addResult(float data);
	std::vector<float> input1;
	std::vector<float> input2;
	std::vector<float> decimal1;
	std::vector<float> decimal2;

public:
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked7();
private:
	bool m_errorInput = false;

	CButton button0;
	CButton button1;
	CButton button2;
	CButton button3;
	CButton button4;
	CButton button5;
	CButton button6;
	CButton button7;
	CButton button8;
	CButton button9;
	CButton buttonPlus;
	CButton buttonMin;
	CButton buttonRem;
	CButton buttonPwr;
	CButton buttonMul;
	CButton buttonDiv;
	CButton buttonAns;
	CButton buttonEq;
	CButton buttonClr;
	CEdit editResult;

	bool operation1 = 0;
	bool operation2 = 0;
	int operation3 = 0;
	int oper;
	float num;
	bool newOperation = 0;

public:
	afx_msg void OnBnClickedEqual();


	afx_msg void OnBnClickedAddition();
	afx_msg void OnBnClickedClr();
	afx_msg void OnBnClickedMultiplication();
	afx_msg void OnBnClickedDivision();
	afx_msg void OnBnClickedSubstracttion();
	void Operation();
	void Print();

private:
	CButton buttonPoint;
public:
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPower();
	afx_msg void OnBnClickedAnswer();
	afx_msg void OnBnClickedRemainder();
};
