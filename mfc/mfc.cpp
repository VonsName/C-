#include "mfc.h"

MyApp app;//全局应用程序对象

MyApp::MyApp()
{

}

MyApp::~MyApp()
{

}

BOOL MyApp::InitInstance()
{
	//创建窗口
	MyFrame *frame = new MyFrame;
	//显示窗口
	frame->ShowWindow(SW_SHOWNORMAL);
	//更新窗口
	frame->UpdateWindow();
	m_pMainWnd = frame;//保存指向应用程序的主窗口指针；
	return TRUE;
}

//分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)//第一个参数是需要给哪个类使用消息机制，第二个是它的父类
	ON_WM_LBUTTONDOWN() //鼠标左键按下
	ON_WM_CHAR()//键盘
	ON_WM_PAINT()//绘图
END_MESSAGE_MAP();
MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
}

MyFrame::~MyFrame()
{

}

//鼠标按下完成
void MyFrame::OnLButtonDown(UINT, CPoint point )
{
	/*TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(buf);*/
	CString str;
	str.Format(TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(str);
}

//键盘实现
void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str;
	//TEXT 自适应编码的转换
	str.Format(TEXT("按下了%c键"), nChar);
	MessageBox(str);

	//多字节转为宽字节L"aaa" VS默认使用unicode字符编码集，是宽字节，而英文字母为多字节，一个字母一个字节
	MessageBox(L"aaa");
}

//绘图
void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.TextOutW(100, 100, TEXT("你好啊"));
	dc.Ellipse(10, 10, 100, 100);

	const	char *p = "aaa"; //多字节字符串
	int num = strlen(p);

	//宽字节字符串长度
	const wchar_t *p2 = L"ccc";
	int num = wcslen(p2);

	//char* 与CString转换
	const char *p3 = "aacc";
	CString str = CString(p3);
	//CString转为char*
	CStringA tmp;
	tmp = str;
	char *p5 = tmp.GetBuffer();
}
