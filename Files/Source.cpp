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
	std::ofstream fout;//создаем поток
	fout.open("File.txt", std::ios::app); //открываем поток, app это функция дозаписывания в файл при открытии

	fout << "Hello Files!" << endl; //пишем в поток
	fout.close(); //закрываем поток

	system("notepad File.txt"); //функция систем запускает любую программу, к которой есть path в Windows. system м. прочитать только строку Си, поэтому если засовываем string то применяем метод .c_str() к ней

#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	ifstream fin("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 1024; //размер в байтах 1Мб
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			//fin >> buffer; 
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}//будем читать файл
		cout << fin.tellg() << "\n";//показывает позицию курсора
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
#endif // READ_TO_FILE

}