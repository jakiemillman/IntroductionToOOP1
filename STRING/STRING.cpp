// STRING.cpp 

#include <iostream>
#include <Windows.h>
using namespace std;


class String
{
    char* str; //размер символов;
    int size; //размер строки
public:
    //Constructors
    explicit String(int size=256):size(size),str(new char[size] {})
    {
        //this->size = size;
        //this->str = new char[size] {};
        cout << "Default1ArgConstructor:\t" << this << endl;
    }
    String(const char* str):String(strlen(str)+1)
    {
        /*this->size = strlen(str)+1;
        this->str = new char[size] {};*/
        for (int i = 0; i < size; i++)this->str[i] = str[i];
        cout << "Default1ArgConstructor1:\t" << this << endl;
    }
    String(const String& other):String(other.str)
    {
        //deep copy
        /*this->size = other.size;
        this->str = new char [size]{};*/
        //for (int i = 0; i < this->size; i++) this->str[i] = other.str[i];
        cout << "CopyConstructor:\t" << this << endl;
    }
    String(String&& other)
    {
        //shalow copy
        this->size = other.size;
        this->str = other.str;
        other.size = NULL;
        other.str = nullptr;
        cout << "MoveConstructor:\t" << this << endl;

    }
    
    ~String()
    {
        delete[]str;
        cout << "DefaultDestructor:\t" << this << endl;
    }
    //Methods
    void Print()
    {
        cout << "Size: " << size << endl;
        cout << "Str: " << str << endl;
    }
    int get_size() const
    {
        return this->size;
    }
    char* get_array()
    {
        return this->str;
    }

    const char* get_array()const 
    {
        return this->str;
    }
    //Operators;
    String& operator=(String&& other)
    {
        if (this == &other)return*this;
        delete[]this->str;
        this->size = other.size;
        this->str = other.str;
        other.size = 0;
        other.str = nullptr;
        cout << "MoveAssignment:\t" << this << endl;


    }
    String& operator = (const String& other)
    {
        if (this == &other)return *this;
        delete[]this->str;
        this->size = other.size;
        this->str = new char[this->size];
        for (int i = 0; i < this->size; i++) this->str[i] = other.str[i];
        return *this;
    }
    char& operator[](int i)const
    {
        return str[i];
    }
   
};
String operator+(const String& left,const String& right)
{
    String cat (left.get_size() + right.get_size() - 1);
    for (int i = 0, j = 0; i < cat.get_size(); i++)
    {
        if (i < left[i]/*.get_size()-1*/)cat[i] = left/*.get_array()*/[i];
        else cat[i] = right/*get_array()*/[j++];
    }
    /*strcat(left.get_array(), right.get_array());*/
    return cat;
}
std::ostream& operator<<(std::ostream& os, String& obj)
{
    os << obj.get_array();
    return os;
}
std::istream& operator>>(std::istream& is, String& obj)
{
    const int SIZE = 1024000;
    char buffer[SIZE] = {};
    is>>buffer;
    obj=buffer;
    return is;
}
//#define CONSTRUCTORS_CHECK
#define HOME_WORK
int main()
{
    setlocale(LC_ALL,"rus");
#ifdef CONSTRUCTORS_CHECK
    String str1;
    str1.Print();
    String str2(16);//explicit constructor невозможно вызвать оператором присвоить, его можно вызвать только так;
    str2.Print();
    String str3="Hello";
#endif // 
#ifdef HOME_WORK
    String str1="Hello ";
    String str2="world";
   /* String str3 = str1 + str2;
    str3.Print();
    str1 = str2 + str3;
    cout << str1 << "+ " << str2 << " = " << str3 << endl;
    String str4;*/
    cout << "Введите строку: "; cin >> str1;
    cout << str1;
    cout << endl;


#endif
}

