#include <afxwin.h>
class MyApp:public CWinApp //CWinApp 应用程序类
{
public:
	MyApp();
	~MyApp();

	//程序入口
	virtual BOOL InitInstance();
private:

};

class MyFrame:public CFrameWnd  //窗口框架类
{
public:
	MyFrame();
	~MyFrame();
	//声明在一个类中使用消息映射，把消息映射到函数，必须用在类的声明中.h
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
private:

};
