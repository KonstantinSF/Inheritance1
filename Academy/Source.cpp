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
	const unsigned int get_age()const
	{
		return age; 
	}
	//		constructors
	Human(HUMAN_TAKE_PARAMETERS) :
		last_name(last_name), first_name(first_name), age(age)
	{
		cout << "HConstrucror:\t" << this << endl; 
	}
	~Human()
	{
		cout << "HDestrucror:\t" << this << endl;
	}
	//  methods
	void print()const
	{
		cout << last_name << " " << first_name << " " << age<< " years old\n"; 
	}
}; 

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
		const std::string& specialty, 
		unsigned int experience
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

class Undergrad:public Student 
{
	bool specialist;
	bool master_dgr; 
	std::string name_thesis; 
	std::string supervisor; 
	std::string date_of_defence; 
	bool unemployed; 
	bool study_debt; 
	bool military_defence; 
public:

	////////GETS//////////
	const bool get_specialist() const
	{
		return specialist;
	}
	const bool get_master_dgr()const
	{
		return master_dgr; 
	}
	const std::string& get_name_thesis()const
	{
		return name_thesis; 
	}
	const std::string& get_superviser() const
	{
		return supervisor; 
	}
	const std::string& get_date_of_defence()const
	{
		return date_of_defence; 
	}
	const bool get_unemployed()const
	{
		return unemployed; 
	}
	const bool get_study_debt()const
	{
		return study_debt; 
	}
	const bool get_military_defence() const
	{
		return military_defence; 
	}
	////////SETS//////////
	void set_specialist(bool specialist)
	{
		this->specialist=specialist;
	}
	void set_master_dgr (bool master_dgr)
	{
		this->master_dgr = master_dgr;
	}
	void set_name_thesis (const std::string& name_thesis)
	{
		this->name_thesis = name_thesis;
	}
	void set_supervisor(const std::string& supervisor)
	{
		this->supervisor = supervisor;
	}
	void set_date_of_defence(const std::string& date_of_defence)
	{
		this->date_of_defence = date_of_defence; 
	}
	void set_unemployed(const bool unemployed)
	{
		this->unemployed = unemployed; 
	}
	void set_study_debt(const bool study_debt)
	{
		this->study_debt = study_debt; 
	}
	void set_military_defence(const bool military_defence)
	{
		this->military_defence = military_defence; 
	}
	///////////////constructor////////////////
	Undergrad
	(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, 
	const bool specialist,
	const bool master_dgr,
	const std::string& name_thesis,
	const std::string& supervisor,
	const std::string& date_of_defence,
	const bool unemployed,
	const bool study_debt,
	const bool military_defence
	):Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_specialist(specialist);
		set_master_dgr(master_dgr);
		set_name_thesis(name_thesis); 
		set_supervisor(supervisor);
		set_date_of_defence(date_of_defence); 
		set_unemployed(unemployed); 
		set_study_debt(study_debt);
		set_military_defence(military_defence); 
		cout << "UndergradConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "UDestrucror:\t" << this << endl;
	}
	///////METHODS////////
	void print()const
	{
		Student::print();
		if (specialist)cout << "Specialist/"; else cout << " ";  
		if (master_dgr)cout << "Master dgr/"; else cout << " ";
		cout<<"Thesis:"<< name_thesis << " Supervisor:" << supervisor << " Date of defence:" << date_of_defence << " " << endl;
		cout << "Job: "; if (unemployed)cout << "unemployed/ "; else cout << "have a job exp. " << " ";
		cout << "Study debt: "; if (study_debt)cout << "Alert! Srudy debt!NONE exam!"; else cout << "Exam admited"<<" ";
		cout << "Military defence: "; if (military_defence)cout << "Presence"; else cout<< "The army is waiting..."<< endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Human human("Montana", "Antonio", 25);
	//human.print(); 
	cout << delimiter << endl; 

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95); 
	//stud.print(); 
	cout << delimiter << endl; 

	Undergrad Semenoff("Semenof", "Sergey", 25, "Police rules in Russian Hunting", "PR_22", 75, 70, true, false, "... in advance", "Mihalich", "30/06", true, false, true);
	Semenoff.print(); 
	cout << delimiter << endl; 

	Teacher professor("White", "Walter", 50, "Chemistry", 20); 
	//professor.print(); 
}