#include<iostream>
#include<Windows.h>
using namespace std; 

namespace Geometry
{
	const double pi = 3.14;
	enum Color//набор целочисл-х констант
	{
		console_default = 0x07,
		console_blue = 0x99, //цвет фона 9 цвет текста 9
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE
	};

	class Shape
	{
	protected:
		Color color;//только при наследовании
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}
		virtual double area() const = 0; //clear virtual method
		virtual double perimeter() const = 0;
		virtual void draw()const = 0;
		virtual void info() const
		{
			cout << "square fig.: " << area() << endl;
			cout << "perimeter: " << perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 5) side = 5;
			if (side > 20) side = 20;
			this->side = side;
		}
		////////	Constructors://////////
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		double area() const override
		{
			return side * side;
		}
		double perimeter()const override
		{
			return side * 4;
		}
		void draw() const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "length of side of square: " << side << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		void set_width(double width)
		{
			if (width < 8) width = 8;
			if (width > 30) width = 30;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < 3) length = 3;
			if (length > 20)length = 20;
			this->length = length;
		}
		///////// Constructor//////////:
		Rectangle(double width, double length, Color color) :Shape(color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {};
		double area() const override
		{
			return width * length;
		}
		double perimeter() const override
		{
			return (width + length) * 2;
		}
		void draw() const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/
		
			HWND hwnd = GetConsoleWindow(); //получаем окно консоли
			//Получаем контекст устройства для окна консоли
			HDC hdc = GetDC(hwnd);//это то на чем мы будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, color); //создаем карандаш-то чем мы буддем рисовать
			HBRUSH hBrush = CreateSolidBrush(color); //создаем кисть, она рисует заливку замкнутой фигуры
			SelectObject(hdc, hPen); //выбираем чем и на чем мы будем рисовать
			SelectObject(hdc, hBrush); //выбираем чем и на чем мы будем рисовать
			
			::Rectangle(hdc, 100, 100, 500, 300); //рисуем прямоугольник
			DeleteObject(hPen); 
			
			ReleaseDC(hwnd, hdc);//осовбождаем контекст устройства
		
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Width: " << width << endl;
			cout << "Length: " << length << endl;
			Shape::info();
		}
	};
	class Circle :public Shape
	{
		double diameter; 
	public:
		double get_diameter()const
		{
			return diameter; 
		}
		void set_diameter(double diameter)
		{
			if (diameter < 3) diameter=3; 
			if (diameter > 50) diameter=50; 
			this->diameter = diameter; 
		}
		/////////Constructor: //////////
		Circle(double diameter, Color color):Shape(color)
		{
			set_diameter(diameter); 
		}
		~Circle() {};
		///////Methods: /////////
		double area()const override
		{
			return pi * pow(diameter, 2) / 4; 
		}
		double perimeter()const override
		{
			return pi * diameter; 
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); 
			HDC hdc = GetDC(hwnd); 
			HPEN hPen = CreatePen(PS_SOLID, 5, color); 
			HBRUSH hBrush = CreateSolidBrush(color); 
			SelectObject(hdc, hPen); 
			Ellipse(hdc, 300, 300, 500, 500); 
			DeleteObject(hPen); 
			DeleteObject(hBrush); 
			ReleaseDC(hwnd, hdc); 
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl; 
			cout <<"Diameter: "<< diameter << endl;
			Shape::info(); 
		}
	};
}

void main()
{
	setlocale(LC_ALL, ""); 
	//Shape shape; 
	/*Geometry::Square square(8, Geometry::Color::console_red); 
	square.info(); 

	Geometry::Rectangle rect(15, 7, Geometry::Color::console_yellow);
	rect.info(); */

	Geometry::Circle circ(30, Geometry::Color::console_green); 
	circ.info(); 
}