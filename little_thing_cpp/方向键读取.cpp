//��ʵ�ϣ���ȡ�����������ֻ��Ҫincludeһ��ͷ�ļ�����
//��Ҫע����ǣ�Ҫ��getch��ȡ���Σ������ж�
#include<conio.h>
int ch;
while ((ch = _getch()) != 0x1B)//�ж�����esc�˳�
	{
		switch (ch) {
		case 0xE0:
			switch(ch = _getch())
		{
		case 75:cout << "left \n"; break;
		case 72:cout << "up \n"; break;
		case 77:cout << "right \n"; break;
		case 80:cout << "down \n"; break;
		default:break;
		}
		default:break;
		}
	}