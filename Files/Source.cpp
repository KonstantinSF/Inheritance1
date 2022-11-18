#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//#define WRITE_TO_FILE
#define READ_TO_FILE
#define delimiter "\n------------------------------------------------\n"


void main() 
{
	setlocale(LC_ALL, ""); 
#ifdef WRITE_TO_FILE
	std::ofstream fout;//������� �����
	fout.open("File.txt", std::ios::app); //��������� �����, app ��� ������� ������������� � ���� ��� ��������

	fout << "Hello Files!" << endl; //����� � �����
	fout.close(); //��������� �����

	system("notepad File.txt"); //������� ������ ��������� ����� ���������, � ������� ���� path � Windows. system �. ��������� ������ ������ ��, ������� ���� ���������� string �� ��������� ����� .c_str() � ���

#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	ifstream fin("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 1024; //������ � ������ 1��
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			//fin >> buffer; 
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}//����� ������ ����
		cout << fin.tellg() << "\n";//���������� ������� �������
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
#endif // READ_TO_FILE

}