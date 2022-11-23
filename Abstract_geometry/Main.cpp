#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std; 

namespace Geometry
{
	const double pi = 3.14;
	enum Color//набор целочисл-х констант
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000, 
		yellow = 0x0000FFFF,
		white=0x00FFFFFF,
		grey = 0x00AAAAAAAA,

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
		unsigned int start_x; 
		unsigned int start_y; 
		unsigned int line_width; 

	public:
		unsigned int get_start_x() const
		{
			return start_x; 
		}
		unsigned int get_start_y() const
		{
			return start_y;
		}
		unsigned int get_line_width() const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 800)start_x = 800;
			this->start_x = start_x; 
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 500)start_y = 500;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 30)line_width = 30; 
			this->line_width = line_width; 
		}
		Shape(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
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
		Square(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
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
			if (width < 30) width = 30;
			if (width > 300) width = 300;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < 20) length = 20;
			if (length > 200)length = 200;
			this->length = length;
		}
		///////// Constructor//////////:
		Rectangle(double width, double length, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
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
			//ѕолучаем контекст устройства дл€ окна консоли
			HDC hdc = GetDC(hwnd);//это то на чем мы будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, line_width, color); //создаем карандаш-то чем мы буддем рисовать
			HBRUSH hBrush = CreateSolidBrush(color); //создаем кисть, она рисует заливку замкнутой фигуры
			SelectObject(hdc, hPen); //выбираем чем и на чем мы будем рисовать
			SelectObject(hdc, hBrush); //выбираем чем и на чем мы будем рисовать
			
			::Rectangle(hdc, start_x, start_y, 500, 300); //рисуем пр€моугольник
			DeleteObject(hPen); 
			DeleteObject(hBrush); 
			
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
		double radius; 
	public:
		double get_radius()const
		{
			return radius; 
		}
		void set_radius(double radius)
		{
			if (radius < 20) radius=20; 
			if (radius > 220) radius=220; 
			this->radius = radius; 
		}
		/////////Constructor: //////////
		Circle(double radius, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius); 
		}
		~Circle() {};
		///////Methods: /////////
		double area()const override
		{
			return M_PI*radius*radius;
		}
		double perimeter()const override
		{
			return 2*M_PI*radius; 
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); 
			HDC hdc = GetDC(hwnd); 

			HPEN hPen = CreatePen(PS_SOLID, line_width, color); 
			HBRUSH hBrush = CreateSolidBrush(color); 
			SelectObject(hdc, hPen); 
			SelectObject(hdc, hBrush); 

			::Ellipse(hdc, start_x, start_y, start_x+radius*2, start_y+radius*2); //задаем параметры пр€моугольника в который вписан эллипс

			DeleteObject(hPen); 
			DeleteObject(hBrush); 
			ReleaseDC(hwnd, hdc); 
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl; 
			cout <<"radius: "<< radius << endl;
			Shape::info(); 
		}
	};


}

void main()
{
	setlocale(LC_ALL, ""); 
	//Shape shape; 
	Geometry::Square square(8,100, 100, 11, Geometry::Color::console_red); 
	square.info(); 

	Geometry::Rectangle rect(150, 70, 300, 100, 11, Geometry::Color::grey);
	rect.info(); 

	Geometry::Circle circ(200, 500, 200, 11, Geometry::Color::yellow);
	circ.info(); 

	/*Geometry::Triangle triang(15, 15, 15, Geometry::Color::console_blue); 
	triang.info(); */
}