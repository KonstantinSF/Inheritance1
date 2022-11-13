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
		return os << last_name << " " << first_name << " " << age<< " years old\n"; 
	}
}; 
std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attandance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attandance

class Student :public Human
{
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
	Student
	(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS
	):Human (HUMAN_GIVE_PARAMETERS)
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
	std::ostream& print(std::ostream&os)const override
	{
		
		return Human::print(os) << speciality << " " << group << " " << rating << " " << attandance << endl;
	}
};

class Teacher : public Human
{
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

	Teacher(
		HUMAN_TAKE_PARAMETERS,
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
		return Human::print(os) << specialty << " " << experience << endl;
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
		
		return Student::print(os) << "Diploma theme: " << topic << endl;
	}
};
//#define INHERITANCE
//#define PRINT_TO_FILE
#define READ_FROM_FILE
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
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 15),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 120)
	};
#ifdef PRINT_TO_CONSOLE
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i];
		cout << delimiter << endl;
	}
#endif // PRINT_TO_CONSOLE

#ifdef PRINT_TO_FILE
	std::fstream fout; //cteate a stream
	fout.open("Academy_group.txt", std::ios::app);//open stream
	for (int i = 0; i < sizeof(group) / sizeof(Student*); i++) fout << *group[i] << endl;//write in a stream
	fout.close(); //close the stream
	system("notepad Academy_group.txt");
#endif // PRINT_TO_FILE


#ifdef READ_FROM_FILE
	ifstream fin("Academy_group.txt");
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

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i]; 
	}
	
}