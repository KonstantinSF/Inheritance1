#include<iostream>
using namespace std; 


class Animal
{
	std::string name; 
public:
	virtual void sound()const = 0; //clear virtual method
};

class Cat :public Animal
{

};
class Tiger :public Cat
{
public:
	void sound()const override
	{
		cout << "Pppppppp" << endl; 
	}
};
class Lion :public Cat
{
public:
	void sound()const override
	{
		cout << "i'm eating u!" << endl; 
	}
};
class Dog:public Animal{};
class Wolf :public Dog
{
public:
	void sound()const override
	{
		cout << "Ayyyyyyy" << endl; 
	}
};

void main()
{
	setlocale(LC_ALL, ""); 
	//Animal slonohobotan; forbidden to create
	//Cat tom; 
	Tiger tiger; 
	tiger.sound(); 
	Lion killer; 
	killer.sound(); 
	Wolf heart; 
	Animal* zoo[] =
	{
		new Tiger,
		new Lion,
		new Wolf
	}; 
	for (int i = 0;  i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound(); 
	}
}