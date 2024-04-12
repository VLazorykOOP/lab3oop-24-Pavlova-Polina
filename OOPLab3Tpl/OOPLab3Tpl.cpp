// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//
#include <iostream>
#include <locale>
using namespace std;

class Date {
private:
    int m_day;
    int m_month;
    int m_year;
public:
    Date() {
        m_day = 1;
        m_month = 1;
        m_year = 2000;
    }

    void set_day(int day) {
        if (day > 31) {
            cout << "Day isn't correct!" << endl;
        }
        else {
            m_day = day;
        }
    }
    Date(int day, int month) {
        m_day = day;
        m_month = month;
        m_year = 2024;
    }
    void set_month(int month) {
        if (month > 12) {
            cout << "Month isn't correct!" << endl;
        }
        else {
            m_month = month;
        }
    }
    void set_year(int year) {
        m_year = year;
    }

    void print_date() {
        cout << m_day << "/" << m_month << "/" << m_year << endl;
    }

    void char_date() {
        setlocale(LC_CTYPE, "ukr");
        switch (m_month) {
        case 1: cout << m_day << " Сiчня " << m_year << " Року " << endl; break;
        case 2: cout << m_day << " Лютого " << m_year << " Року " << endl; break;
        case 3: cout << m_day << " Березня " << m_year << " Року " << endl; break;
        case 4: cout << m_day << " Квiтня " << m_year << " Року " << endl; break;
        case 5: cout << m_day << " Травня " << m_year << " Року " << endl; break;
        case 6: cout << m_day << " Червня " << m_year << " Року " << endl; break;
        case 7: cout << m_day << " Липня " << m_year << " Року " << endl; break;
        case 8: cout << m_day << " Серпня " << m_year << " Року " << endl; break;
        case 9: cout << m_day << " Вересня " << m_year << " Року " << endl; break;
        case 10: cout << m_day << " Жовтня " << m_year << " Року " << endl; break;
        case 11: cout << m_day << " Листопада " << m_year << " Року " << endl; break;
        case 12: cout << m_day << " Грудня " << m_year << " Року " << endl; break;
        }
    }

};

void task1() {
    int day, month, year;
    Date object, object2(2, 4);
    cout << "Enter date" << endl;
    cin >> day;
    cin >> month;
    cin >> year;
    object.set_day(day);
    object.set_month(month);
    object.set_year(year);
    object.print_date();
    object.char_date();
    object2.print_date();
    object2.char_date();

}
#include <iostream>
using namespace std;
class Vector {
private:
    int* data;
    int size;
    int& state;

public:
    Vector() : data(new int[1]), size(1), state(count) {                  //конструктор без параметрів
        data[0] = 0;
        ++count;
    }
    Vector(int s);             // Конструктор з одним параметром
    Vector(int s, int init_value);  // Конструктор з двома параметрами
    Vector(const Vector& other); // Конструктор копіювання
    Vector& operator=(const Vector& other); // Оператор присвоєння
    ~Vector() {                            //деструктор
       if(data!=nullptr) delete[] data;
        --count;
    }
    void Output();  // Виведення вектора на екран
    void Input();   // Введення вектора з клавіатури
    Vector Add(const Vector& other); // Додавання двох векторів
    Vector substract(const Vector& other); //Віднімання
    Vector multiply(short factor); // Множення
    void setElement(int index, int value = 0); //Присвоєння значення елементу
    void setElement(int index, int value = 0); //Присвоєння значення елементу
    void print(); //друк
    static int count;


    int getElement(int index) const {                                //функція яка одержує деякий елемент масиву
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            state = -1;                                            //помилка
            return 0;
        }
    }

    bool operator>(const Vector& other) const {                                    //ф-ція порівняння більше, менше або рівно
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] <= other.data[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator<(const Vector& other) const ;
    bool operator==(const Vector& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
};
int Vector::count = 0;                           //скидання лічильника 
bool Vector::operator<(const Vector& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] >= other.data[i]) {
                return false;
            }
        }
        return true;
    }

Vector::Vector(int s) : data(new int[s]), size(s), state(count) {                 //конструктор з одним параметром ( розмір вектора)
    ++count;
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

Vector::Vector(int s, int init_value) : data(new int[s]), size(s), state(count) {            //конструктор з двома параметрами 
    ++count;
    for (int i = 0; i < size; ++i) {
        data[i] = init_value;
    }
}

Vector::Vector(const Vector& other) : data(new int[other.size]), size(other.size), state(count) {          //конструктор копій
    ++count;
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Vector& Vector::operator=(const Vector& other) {                //операція присвоєння
    if (this == &other)
        return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

Vector Vector::Add(const Vector& other) {                                         //ф-ція додавання
    if (size != other.size) {
        Vector result;
        result.state = -2;                                                     //помилка
        return result;
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

Vector Vector::substract(const Vector& other) {                                     //ф-ція віднімання
    if (size != other.size) {
        Vector result;
        result.state = -2;                                          //помилка
        return result;
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

Vector Vector::multiply(short factor) {                                 //множення типу short
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] * factor;
    }
    return result;
}

void Vector::setElement(int index, int value = 0) {                       //функція, яка присвоює елементу  деяке значення
    if (index >= 0 && index < size) {
        data[index] = value;
    }
    else {
        state = -1; // помилка
    }
}
void Vector::print() {                                              //ф-ція друку
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << data[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


int task2() {
    setlocale(LC_CTYPE, "Ukr");
    //тест класу "Вектор"
    Vector vec1;                                             // використання конструктора без параметрів
    vec1.print();

    Vector vec2(5);                                           // використання конструктора з одним параметром
    vec2.print();

    Vector vec3(3, 7);                                        // використання конструктора з двома параметрами(створює три ел. із значенням 7)
    vec3.print();

    Vector vec4 = vec3;                                       // використання конструктора копій(створює копію vec3)
    vec4.print();

    Vector vec5;
    vec5 = vec2;                                               // використання операції присвоєння(присвоює vec5 = vec2)
    vec5.print();

    cout << "Кількість об*єктів класу Vector: " << Vector::count << endl;
    return 0;
}
int main()
{
    int choice;
    cout << "Choose task" << endl;
    cout << "1.Task 1 (with class Date)" << endl;
    cout << "2.Task 2 (with class Vector)" << endl;
    cout << "3.Exit" << endl;

    cin >> choice;

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: return 0;
    default: cout << "Error" << endl;
    }
}


