#include "mfc.h"

MyApp app;//ȫ��Ӧ�ó������

MyApp::MyApp()
{

}

MyApp::~MyApp()
{

}

BOOL MyApp::InitInstance()
{
	//��������
	MyFrame *frame = new MyFrame;
	//��ʾ����
	frame->ShowWindow(SW_SHOWNORMAL);
	//���´���
	frame->UpdateWindow();
	m_pMainWnd = frame;//����ָ��Ӧ�ó����������ָ�룻
	return TRUE;
}

//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)//��һ����������Ҫ���ĸ���ʹ����Ϣ���ƣ��ڶ��������ĸ���
	ON_WM_LBUTTONDOWN() //����������
	ON_WM_CHAR()//����
	ON_WM_PAINT()//��ͼ
END_MESSAGE_MAP();
MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
}

MyFrame::~MyFrame()
{

}

//��갴�����
void MyFrame::OnLButtonDown(UINT, CPoint point )
{
	/*TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(buf);*/
	CString str;
	str.Format(TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(str);
}

//����ʵ��
void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str;
	//TEXT ����Ӧ�����ת��
	str.Format(TEXT("������%c��"), nChar);
	MessageBox(str);

	//���ֽ�תΪ���ֽ�L"aaa" VSĬ��ʹ��unicode�ַ����뼯���ǿ��ֽڣ���Ӣ����ĸΪ���ֽڣ�һ����ĸһ���ֽ�
	MessageBox(L"aaa");
}

//��ͼ
void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.TextOutW(100, 100, TEXT("��ð�"));
	dc.Ellipse(10, 10, 100, 100);

	const	char *p = "aaa"; //���ֽ��ַ���
	int num = strlen(p);

	//���ֽ��ַ�������
	const wchar_t *p2 = L"ccc";
	int num = wcslen(p2);

	//char* ��CStringת��
	const char *p3 = "aacc";
	CString str = CString(p3);
	//CStringתΪchar*
	CStringA tmp;
	tmp = str;
	char *p5 = tmp.GetBuffer();
}
