#include<iostream>
#include<string>
#include<fstream>
using namespace std; 

#define delimiter "\n------------------------------------------------\n"
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
//#define PRINT_TO_CONSOLE

class Human
{
	static const int FULL_NAME_LENGTH=20; 
	static const int AGE_LENGTH=5; 
	std::string last_name; 
	std::string first_name; 
	unsigned int age; 
public:
	const std::string& get_last_name()const
	{
		return last_name; 
	}
	const std::string& get_first_name()const
	{
		return first_name; 
	}
	unsigned int get_age()const
	{
		return age; 
	}
	//		constructors
	Human(HUMAN_TAKE_PARAMETERS) :
		last_name(last_name), first_name(first_name), age(age)
	{
		cout << "HConstrucror:\t" << this << endl; 
	}
	virtual~Human()
	{
		cout << "HDestrucror:\t" << this << endl;
	}
	//  methods
	virtual std::ostream& print(std:: ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age<< " лет."; 
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		//ofs << last_name << " " << first_name << " " << age;
		ofs.width(FULL_NAME_LENGTH); //выравнивает по прав краю, 20знакопозиций ИМЯ занимает. Ширина поля вывода
		ofs << std::left; //выравниваем по лев борту
		ofs << last_name+ " " +first_name; //у класса String все перегружено по умолчанию, в т.ч. и +
		ofs.width(AGE_LENGTH);
		ofs << std::right; 
		ofs << age; 
		return ofs; 
	}
	virtual std::ifstream& scan (std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age; 
		return ifs; 
	}
}; 

std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator << (std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs); 
}

std::ifstream& operator >> (std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs); 
}
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attandance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attandance

class Student :public Human
{
	static const int SPECIALTY_LENGTH=25; 
	static const int GROUP_LENGTH=10; 
	static const int RATING_LENGTH=8; 
	static const int ATTENDANCE_LENGTH=8; 
	std::string speciality; 
	std::string group; 
	double rating; 
	double attandance; 
public:
	const std::string& get_speciality()const
	{
		return speciality; 
	}
	const std::string& get_group()const
	{
		return group; 
	}
	double get_rating()const
	{
		return rating; 
	}
	double get_attandance()const
	{
		return attandance; 
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality; 
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating; 
	}
	void set_attandance(double attandance)
	{
		this->attandance = attandance; 
	}
	//			constructors
	Student(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human (HUMAN_GIVE_PARAMETERS)
	{
		this->speciality = speciality; 
		this->group = group; 
		this->rating = rating; 
		this->attandance = attandance; 
		cout << "SConstructor:\t" << this << endl; 
	}
	~Student()
	{
		cout << "SDestrucror:\t" << this << endl; 
	}

	//		Methods:
	std::ostream& print(std::ostream&os)const override//как передаем в консоль
	{
		return Human::print(os)<< ", " << speciality << " " << group << " " << rating << " " << attandance;
	}
	std::ofstream& print(std::ofstream& ofs) const override//как записываем в файл
	{
		Human::print(ofs)<<" ";
		ofs.width(SPECIALTY_LENGTH);//идет к первому значению в потоке 
		ofs << std::left; 
		ofs << speciality;
		ofs.width(GROUP_LENGTH); 
		ofs << group; 
		ofs.width(RATING_LENGTH); 
		ofs << std::right; 
		ofs << rating; 
		ofs.width(ATTENDANCE_LENGTH); 
		ofs << attandance;
		return ofs; 
	}
	std::ifstream& scan(std::ifstream& ifs) override//перегрузка потока ввода для студента
	{
		Human::scan(ifs); 
		const int SIZE = SPECIALTY_LENGTH; 
		char buffer[SIZE]{}; 
		ifs.read(buffer, SIZE-1); 
		for (int i = SIZE - 2; buffer[i] == ' '; i--)buffer[i] = 0; //убираем пробелы с конца
		while (buffer[0] == ' ')//убираем пробелы сначала
		{
			for (int i = 0; buffer[i]; i++) buffer[i] = buffer[i + 1]; 
		}
		speciality = buffer; 
		ifs >> group; //т.к. пробел является основным разделителем
		ifs >> rating; 
		ifs >> attandance; 
		return ifs; 
	}
};

class Teacher : public Human
{
	static const int SPECIALTY_LENGTH=25;
	static const int EXPERIENCE_LENGTH=5;
	std::string specialty; 
	unsigned int experience; 
public:
	const std::string& get_specialty()const
	{
		return specialty; 
	}
	unsigned int get_experience()const
	{
		return experience; 
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty; 
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience; 
	}
	//			constructor

	Teacher(HUMAN_TAKE_PARAMETERS,
	const std::string& specialty, unsigned int experience
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_experience(experience); 
		cout << "TConstructor:\t" << this << endl; 
	}
	~Teacher()
	{
		cout << "TDestrucror:\t" << this << endl; 
	}
	//		methods
std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os)<<", " << specialty << " " << experience;
	}
std::ofstream& print(std::ofstream& ofs) const override
{
	Human::print(ofs) << " ";
	ofs.width(SPECIALTY_LENGTH);
	ofs << std::left; 
	ofs << specialty; 
	ofs.width(EXPERIENCE_LENGTH); 
	ofs << right; 
	ofs << experience;
	return ofs; 
}
std::ifstream& scan(std::ifstream& ifs)override
{
	Human::scan(ifs);
	const int SIZE = SPECIALTY_LENGTH;
	char buffer[SIZE]{};
	ifs.read(buffer, SIZE - 1);
	for (int i = SIZE - 2; buffer[i] == ' '; i--)buffer[i] = 0;
	while (buffer[0] == ' ')
	{
		for (int i = 0; buffer[i]; i++)buffer[i] = buffer[i + 1]; 
	}
	specialty = buffer; 
	ifs >> experience;
	return ifs;
}
};

class Undergrad :public Student
{
	std::string topic;
public:
	const std::string& get_topic()const
	{
		return topic;
	}
	void set_topic(const std::string& topic)
	{
		this->topic = topic;
	}
	//				Constructors:
	Undergrad(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& topic) :
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//				Methods:
	std::ostream&  print(std::ostream& os)const override
	{
		
		return Student::print(os)<< ", Diploma theme: " << topic;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Student::print(ofs) << " "<< topic;
		return ofs; 
	}
	std::ifstream& scan(std::ifstream& ifs) override
	{
		Student::scan(ifs);
		std::getline(ifs, topic);
		return ifs;
	}
};

//#define INHERITANCE
//#define PRINT_TO_FILE
//#define READ_FROM_FILE

Human* HumanFactory(const std::string& type)
{//этот метод создает объекты в динамич памяти, нет конструктора по умолч., поэтому руками. npos возвращает, если find() не нашел
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0); 
	if (type.find("Undergrad") != std::string::npos)return new Undergrad("", "", 0, "", "", 0, 0,"");
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0); 
}
void print(Human* group[], const int n)//для массива указателей типа Human
{
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;//write in a stream
		cout << delimiter << endl;
	}
}
void save(Human*group[], const int n,const std::string& filename)
{
	//std::string filename = "Group.txt";
	std::ofstream fout(filename); //cteate a stream
	//open stream с ф-ей дописывания в конец файла, а не перезаписывания
	for (int i = 0; i < n; i++)
	{
		fout.width(15);//выделили 15 знакопозиций 
		fout << std::left; //выровняли по лев краю
		fout << typeid(*group[i]).name() << ":\t"; //название группы==название класса
		fout << *group[i] << endl;//write in a file
		//fout << delimiter << endl; 
	}
	fout.close(); //close the stream
	std::string command = "notepad " + filename;//sum the strings in one
	system(command.c_str());
}
Human** load(const std::string& filename, int& n)
{
	
	std::ifstream fin(filename); //create a stream
	if (fin.is_open())
	{
		std::string buffer; 
		for  (n=0; !fin.eof(); n++)//считаем размер массива and after we'll be in the end of file
		{
			std::getline(fin, buffer); 
		}
		n--; //одна пустая строк в конце
	}
	Human** group = new Human * [n] {}; //2 Выдел память под динамич массив указателей
	
		fin.clear(); 
		fin.seekg(0);//3 возвращ в нач файла, чтобы прочитать строки и загрузить и их в объекты
	
		if (fin.is_open())//4 загружаем объекты из файла
		{
			std::string type; //создали строку тип, в нее задаем тип объекта(все, что до двоеточия)
			for (int i = 0; i < n; i++)
			{
				std::getline(fin, type, ':'); //читаем до двоеточия, это делимитер
				//cout << buffer << endl; 
				group[i] = HumanFactory(type);//возвращает нам пустой объект нужного класса
				fin >> *group[i]; //передаем в поток собранную из текста группу
			}
		}
	
	return group; 
}

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	//human.print(); 
	cout << delimiter << endl;

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95);
	//stud.print(); 
	cout << delimiter << endl;

	Undergrad hank("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg");
	hank.print();
	cout << delimiter << endl;

	Teacher professor("White", "Walter", 50, "Chemistry", 20);
	//professor.print();   
#endif // INHERITANCE
	/*Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 15),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 120)
	};*/
#ifdef PRINT_TO_CONSOLE
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i];
		cout << delimiter << endl;
	}
#endif // PRINT_TO_CONSOLE

#ifdef PRINT_TO_FILE
	std::string filename = "Group.txt";
	std::fstream fout; //cteate a stream
	fout.open("Group.txt");//open stream с ф-ей дописывания в конец файла, а не перезаписывания
	for (int i = 0; i < sizeof(group) / sizeof(Student*); i++) fout << *group[i] << endl;//write in a stream
	fout.close(); //close the stream
	std::string command = "notepad" + filename; 
	system(command.c_str());//c_str() переводит строку в язык из С++ в С
#endif // PRINT_TO_FILE


#ifdef READ_FROM_FILE
	fstream fin("Academy_group.txt");
	if (fin.is_open())
	{
		const int SIZE = 1024;
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			fin.getline(buffer, SIZE);
			cout << fin.tellg() << "\t";
			cout << buffer << endl;
		}
		fin.close();
	}
	else cerr << "File is not found:(" << endl;
#endif // READ_FROM_FILE

	/*print(group, sizeof(group) / sizeof(group[0])); 
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");*/
	int n = 0; 
	Human** group = load("group.txt", n); //загружаем массив из файла, формируем его оттуда
	print(group, n); 

	for (int i = 0; i < n; i++)
	{
		delete group[i]; 
	}
	
}