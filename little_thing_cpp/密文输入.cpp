//�����Ͽ���ͨ��������sequence�е����*��ʵ��
//�ٽ��getch()������������������������
//�����˸����ģ��ɾ������
string password;
	char pw[50], ch;
	cout << "���������룺";
	int i = 0;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b' && i > 0)
		{
			cout << "\b \b"; --i; pw[i] = '\0';//���������Ƿ��޸�pw[i]������
		}
		else {
			pw[i++] = ch;
			cout << "*";
		}
	}
	pw[i] = '\0';
	password = pw;