#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#include <string>
#include<Windows.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
	

#endif
using namespace std;

//class Date {
//private:
//	int day;
//	int month;
//	int year;
//
//public:
//	Date() : day(1), month(1), year(2000) {}
//
//	Date(int d, int m, int y) {
//		if (isValidDate(d, m, y)) {
//			day = d;
//			month = m;
//			year = y;
//		}
//		else {
//			cout << "Некоректна дата. Буде застосовано значення за замовчуванням.\n";
//			day = 1;
//			month = 1;
//			year = 2000;
//		}
//	}
//
//	bool isValidDate(int d, int m, int y) {
//		if (m < 1 || m>12) return false;
//		if (d < 1 || d>31) return false;
//		if (m == 4 || m == 6 || m == 9 || m == 11) {
//			return(d <= 30);
//		}
//		else if (m == 2) {
//			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
//				return (d <= 29);
//			}
//			else {
//				return (d <= 28);
//			}
//		}
//		return true;
//	}
//	void setDay(int d) {
//		if (isValidDate(d, month, year)) {
//			day = d;
//		}
//		else {
//			cout << "Некоректний день.Значення за замовченням.\n";
//		}
//	}
//	void setMonth(int m) {
//		if (isValidDate(day, m, year)) {
//			month = m;
//		}
//		else {
//			cout << "Некоректний місяць. Значення за замовченням.\n";
//		}
//	}
//	void setYear(int y) {
//		if (isValidDate(day, month, y)) {
//			year = y;
//		}
//		else {
//			cout << "Некоректний рік. Значення за замовченням.\n";
//		}
//	}
//
//	int getDay() const {
//		return day;
//	}
//
//	int getMonth() const {
//		return month;
//	}
//
//	int getYear() const {
//		return year;
//	}
//
//	void printformat1() const {
//		string months[12] = { "січня","лютого","березня","квітня","травня","червня","липня","серпня","вересня","жовтня","листопада","грудня" };
//		cout << day << " " << months[month - 1] << " " << year << " року\n";
//	}
//	void printformat2() const {
//		cout << (day < 10 ? "0" : "") << day << "." << (month < 10 ? "0" : "") << month << "." << year << endl;
//	}
//};
//int mainExample1()
//{
//	SetConsoleOutputCP(1251);
//	Date date1;
//	date1.printformat1();
//	date1.printformat2();
//
//	Date date2(5, 1, 2019);
//	date2.printformat1();
//	date2.printformat2();
//
//	date2.setDay(32);
//	date2.setMonth(13);
//	date2.setYear(1900);
//
//	date2.printformat1();
//	date2.printformat2();
//
//	return 0;
//
//}
//

// Ключове слово static 

class foo
{
private:
	static int count; // загальне поле всім об'єктів
	// (У сенсі "оголошення")
public:
	foo() { incObj(); } // інкрементування під час створення об'єкта
	static int incObj() { return ++count; }
	int getcount() { return count; }
};
int  foo::count = 0;
// Ключове слово static ставиться перед типом способу.В основному використовуються
//для роботи зі статичними полями класу.

/*  Example 3
Створити тип даних - клас вектор, який має поля x, y типу double і змінну стану. У класі визначити
o	конструктор без параметрів(інінціалізує поля в нуль);
o	конструктор з одним параметром типу double (інінціалізує поля);
o	конструктор з одним параметром вказівник на тип double (інінціалізує поля x, y значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити код помилки);
o	деструктор із виведенням інформації про стан вектора;
o	визначити функції друку, додавання, віднімання, векторний добуток які здійснюють ці арифметичні операції з даними цього класу;
o	функцію ділення на ціле типу double(при діленні на 0 змінити стан, а ділення не виконувати);
o	визначити функцію порівняння менше які повертають true або false.
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/
enum STATE {
	OK, BAD_INIT, BAD_DIV
};

class Vec2
{
	double  x, y;
	int state;
	static int count;
public:
	Vec2() : x(0), y(0) {
		state = OK; count++;
	}   // 	 конструктор без параметрів
	Vec2(double iv) : x(iv), y(iv) {
		state = OK; count++;
	}
	Vec2(double ix, double iy);
	Vec2(double* v);
	~Vec2() {
		count--;
		cout << " state Vec " << state;
		cout << " Vec delete \n";
	}
	Vec2(const Vec2&);
	Vec2 Add(Vec2& d);
	Vec2 Sub(Vec2& d);
	Vec2 Mul(double d);
	Vec2 Div(double d);
	void Input();   //  !!! Без первантаження операцій    
	void Output();  //  !!! Без первантаження операцій
	bool CompLessAll(Vec2& s);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів Vec2 ";
		return count;
	}
	int getState() { return state; }
};
int Vec2::count = 0;
Vec2::Vec2(double ix, double iy) {
	x = ix; y = iy;
	state = OK;
	count++;
}
Vec2::Vec2(const Vec2& s) {
	//if (this == &s) return; //  // the expression is used in the old standard
	x = s.x; y = s.y; state = OK;
	count++;
};
Vec2::Vec2(double* v) {
	if (v == nullptr) {
		state = BAD_INIT; x = 0; y = 0;
	}
	else {
		x = v[0]; y = v[1];
		state = OK;
	}
	count++;
}
void Vec2::Input() {
	cout << " Input  x y ";
	cin >> x >> y;
}
void Vec2::Output() {
	cout << " x =" << x << " y = " << y << " state  " << state << endl;
}

Vec2 Vec2::Add(Vec2& s) {
	Vec2 tmp;
	tmp.x = x + s.x;
	tmp.y = y + s.y;
	return tmp;
}

Vec2 Vec2::Sub(Vec2& s) {
	Vec2 tmp;
	tmp.x = x - s.x;
	tmp.y = y - s.y;
	return tmp;
}
Vec2 Vec2::Div(double d) {
	Vec2 tmp;
	if (fabs(d) < 1.e-25) {
		tmp.state = BAD_DIV;
		cout << " Error div \n";
		return *this;
	}
	tmp.x = x / d;
	tmp.y = y / d;
	return tmp;
}
Vec2 Vec2::Mul(double d) {
	Vec2 tmp;
	tmp.x = x * d;
	tmp.y = y * d;
	return tmp;
}

bool Vec2::CompLessAll(Vec2& s) {

	if (x < s.x && y < s.y) return true;
	return false;
}

int mainExample3()
{
#if !defined(CODING_VS_CODE)
	setlocale(LC_CTYPE, "ukr");
	cout << "Тестування створенного класу \n";
	cout << "Тестування конструкторiв \n"; 
#else 
	cout << "Testing create class  \n";
	cout << "Testing crot's  \n";
#endif
	Vec2 ObjCDef;
	ObjCDef.Output();
	Vec2 ObjP1(10.0);
	ObjP1.Output();
	double  a = 1.0, b = 2.0;
	Vec2  ObjP2(a, b);
	ObjP2.Output();
	Vec2 ObjCopy(ObjP2);
	double* v = nullptr, v2[] = { 1.2, 3.3 };
	Vec2  ObjP3(v2);
	if (ObjP3.getState() != OK) cout << " ObjP3  x= 0  y= 0  \n";
	Vec2  ObjP4(v2);
	if (ObjP4.getState() != OK) cout << " ObjP4 x= 0  y= 0  \n";
#if !defined(CODING_VS_CODE)
	cout << " Кiлькiсть створених об'єктiв Vec2 " << Vec2::getCount() << endl;
	cout << "Тестування введення \n";
	ObjCDef.Input();
	cout << "Тестування функцiй \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Кiлькiсть створених об'єктiв Vec2 до Sub " << Vec2::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n Кiлькiсть створених об'єктiв Vec2 пiсля Sub " << Vec2::getCount() << endl;
#else 
	cout << "Testing input \n";
	ObjCDef.Input();
	cout << "Testing gunction \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Counts create objects Vec2 before  Sub " << Vec2::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n  Counts create objects Vec2 after Sub  " << Vec2::getCount() << endl;
#endif

	ObjCDef.Output();
	ObjCDef = ObjCDef.Mul(5);
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(1.3);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();

	ObjCDef = ObjCDef.Div(0.0);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	cout << "ObjCopy state " << ObjCopy.getState() << endl;
	if (ObjCopy.CompLessAll(ObjCDef))  cout << "ObjCopy less ObjDef  " << endl;

	
#if !defined(CODING_VS_CODE)
	cout << "Завершення  тестування  \n";
#else 
	cout << "Completion of testing  \n";
#endif
	return 1;

}
/*example  4
Створити тип даних - клас вектор, який має вказівник на int, число елементів і змінну стану. У класі визначити
o	 конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
o	конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
o	конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу).
o	конструктор копій та операцію присвоєння; // !!!
o	деструктор звільняє пам'ять;
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/

#include <iostream>

class IntVector {
	int* v;     // Вказівник на масив int
	int num;    // Кількість елементів вектора
public:
	IntVector() : IntVector(2) {} // Конструктор без параметрів
	IntVector(int n);             // Конструктор з одним параметром
	IntVector(int n, int value);  // Конструктор з двома параметрами
	IntVector(const IntVector& s); // Конструктор копіювання
	IntVector& operator=(const IntVector& s); // Оператор присвоєння
	~IntVector(); // Деструктор

	void Output();  // Виведення вектора на екран
	void Input();   // Введення вектора з клавіатури
	IntVector Add(IntVector& b); // Додавання двох векторів
};

// Определення конструктора з одним параметром
IntVector::IntVector(int n) {
	if (n <= 0) n = 2;  // За замовчуванням, якщо n від'ємне або 0
	num = n;
	v = new int[n];     // Виділення пам'яті для масиву int
	for (int i = 0; i < n; ++i) {
		v[i] = 0;       // Ініціалізація елементів вектора нулями
	}
}

// Определення конструктора з двома параметрами
IntVector::IntVector(int n, int value) {
	if (n <= 0) n = 2;
	num = n;
	v = new int[n];
	for (int i = 0; i < n; ++i) {
		v[i] = value;   // Ініціалізація елементів вектора значенням value
	}
}

// Определення конструктора копіювання
IntVector::IntVector(const IntVector& s) {
	num = s.num;
	v = new int[num];
	for (int i = 0; i < num; ++i) {
		v[i] = s.v[i];  // Копіювання значень елементів з одного вектора в інший
	}
}

// Определення оператора присвоєння
IntVector& IntVector::operator=(const IntVector& s) {
	if (this != &s) {  // Перевірка на самоприсвоєння
		if (num != s.num) {
			delete[] v; // Звільнення пам'яті попереднього масиву
			num = s.num;
			v = new int[num]; // Виділення нової пам'яті для копіювання
		}
		for (int i = 0; i < num; ++i) {
			v[i] = s.v[i]; // Копіювання значень елементів
		}
	}
	return *this;
}

// деструктор
IntVector::~IntVector() {
	if (v) delete[] v; // Звільнення виділеної пам'яті
}

// метод виведення вектора на екран
void IntVector::Output() {
	for (int i = 0; i < num; ++i) {
		std::cout << " v [ " << i << " ]   " << v[i] << '\t' << std::endl;
	}
}

// метод введення вектора з клавіатури
void IntVector::Input() {
	std::cout << "Input size of the vector: ";
	std::cin >> num;
	if (num <= 0) num = 2;
	if (v) delete[] v;
	v = new int[num];
	for (int i = 0; i < num; ++i) {
		std::cout << "Enter value for v[" << i << "]: ";
		std::cin >> v[i];
	}
}

// метод додавання двох векторів
IntVector IntVector::Add(IntVector& b) {
	int tnum = (num < b.num) ? num : b.num;
	IntVector tmp(tnum);
	for (int i = 0; i < tnum; ++i) {
		tmp.v[i] = v[i] + b.v[i]; // Додавання відповідних елементів
	}
	return tmp;
}

int mainExample4()
{
	IntVector VecObj, VecObj1(10); // Створення об'єктів IntVector
	VecObj.Output(); // Виведення вектора VecObj на екран
	VecObj1.Output(); // Виведення вектора VecObj1 на екран
	VecObj.Input(); // Введення вектора VecObj з клавіатури
	VecObj.Output(); // Виведення вектора VecObj на екран
	VecObj1 = VecObj.Add(VecObj1); // Додавання двох векторів
	VecObj1.Output(); // Виведення результату додавання на екран
	return 0;
}

/// 

