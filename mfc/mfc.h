#include <afxwin.h>
class MyApp:public CWinApp //CWinApp Ӧ�ó�����
{
public:
	MyApp();
	~MyApp();

	//�������
	virtual BOOL InitInstance();
private:

};

class MyFrame:public CFrameWnd  //���ڿ����
{
public:
	MyFrame();
	~MyFrame();
	//������һ������ʹ����Ϣӳ�䣬����Ϣӳ�䵽�����������������������.h
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
private:

};
