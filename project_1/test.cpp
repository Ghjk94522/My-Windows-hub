#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//��ȡָ��������
void ReadLineData(const char *_filename, int linenum, char* data) {
	ifstream in;
	in.open(_filename);

	int line = 1;
	while (in.getline(data, 1024)) {
		if (linenum == line)
			break;
		line++;
	}

	in.close();
}

//�ַ���תstring��
string CharToStr(const char *contentchar) {
	string tempstr;
	for (int i = 0; contentchar[i] != '\0'; i++)
		tempstr += contentchar[i];
	return tempstr;
}

//ɾ��ָ����
void DelLineData(const char *_filename, int linenum) {
	ifstream in;
	in.open(_filename);

	string strfiledata = "";
	int line = 1;
	char linedata[1024] = { 0 };
	while (in.getline(linedata, sizeof(linedata))) {
		if (line == linenum)
			strfiledata += "\n";
		else {
			strfiledata += CharToStr(linedata);
			strfiledata += "\n";
		}
		line++;
	}
	in.close();

	ofstream out;
	out.open(_filename);
	out.flush();
	out << strfiledata;
	out.close();
}

//�޸�������
void ModifyLineData(const char *_filename, int linenum, char *linedata) {
	ifstream in;
	in.open(_filename);

	string strfiledata = "";
	int line = 1;
	char templinedata[1024] = { 0 };
	while (in.getline(templinedata, sizeof(templinedata))) {
		if (line == linenum)
		{
			strfiledata += CharToStr(linedata);
			strfiledata += "\n";
		}
		else
		{
			strfiledata += CharToStr(templinedata);
			strfiledata += "\n";
		}
		line++;
	}

	in.close();

	ofstream out;
	out.open(_filename);
	out.flush();
	out << strfiledata;
	out.close();
}


/*int main()
{
	char putout[1024] = { 0 };
	char abc[1024] = "01 ɳĮ���� ������ smlt wms 90 85";

	ModifyLineData("output.txt", 2, abc);

	ReadLineData("output.txt", 1, putout);
	cout << putout << endl;
	//DelLineData("out.txt", 1);
	ReadLineData("output.txt", 2, putout);
	cout << putout << endl;

	return 0;
}*/