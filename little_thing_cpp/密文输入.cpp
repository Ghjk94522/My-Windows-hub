//理论上可以通过储存在sequence中但输出*来实现
//再结合getch()的密文输入可以完成上述功能
//两次退格可以模拟删除功能
string password;
	char pw[50], ch;
	cout << "请输入密码：";
	int i = 0;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b' && i > 0)
		{
			cout << "\b \b"; --i; pw[i] = '\0';//经过测试是否修改pw[i]都可以
		}
		else {
			pw[i++] = ch;
			cout << "*";
		}
	}
	pw[i] = '\0';
	password = pw;