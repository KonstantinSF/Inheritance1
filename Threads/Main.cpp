#include<iostream>
#include<thread>
using namespace std; 
using namespace std::chrono_literals; 

bool finish = false; 

void Plus()
{
	while (!finish)
	{
		cout << "+ ";
		std::this_thread::sleep_for(1s); 
	}
}
void Minus()
{
	while (!finish)
	{
		cout << "- ";
		std::this_thread::sleep_for(1s); 
	}
}

void main()
{
	//Plus(); 
	//Minus(); 
	std::thread plus_thread(Plus); 
	std::thread minus_thread(Minus); 

	cin.get(); //метод get() ожидает нажатие энтер
	finish = true; 
 
	//метод джоин останавливает поток и синхр-ет его с основным потоком, в котором вып-ся ф-ия Main 
	minus_thread.join();
	plus_thread.join(); 
}