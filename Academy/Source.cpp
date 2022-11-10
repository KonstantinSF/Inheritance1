#include<iostream>
#include<string>
using namespace std; 

#define delimiter "\n------------------------------------------------\n"
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
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
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age<< " years old\n"; 
	}
}; 
std::ostream& operator << (std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << "years old"; 
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
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attandance << endl; 
	}
};
std::ostream& operator << (std::ostream& os, const Student& obj)
{
	os << (Human&)obj << " ";
	return os<< obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << obj.get_attandance(); 
}

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
	void print()const
	{
		Human::print();
		cout << specialty << " " << experience << endl; 
	}
};
std::ostream& operator << (std::ostream& os, const Teacher& obj)
{
	os << (Human&)obj << " "; 
	return os << obj.get_specialty() << " "<< obj.get_experience() << "years. ";
}

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
	void print()const
	{
		Student::print();
		cout << "Diploma theme: " << topic << endl;
	}
};
std::ostream& operator << (std::ostream& os, const Undergrad& obj)
{
	return os<< (Student&)obj<<" " << obj.get_topic();
}
//#define INHERITANCE
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

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl; 
		cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Undergrad))cout << *dynamic_cast<Undergrad*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i]; 
	}
}