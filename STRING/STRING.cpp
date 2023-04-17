// STRING.cpp 
#include "String.h"

//--------------------------------------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////
/// Class defenition - определение класса
///////////////////////////////////////////////////////////////////////////////////////////////////
String::String(int size) :size(size), str(new char[size] {})
{
    //this->size = size;
    //this->str = new char[size] {};
    cout << "Default1ArgConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
    /*this->size = strlen(str)+1;
    this->str = new char[size] {};*/
    for (int i = 0; i < size; i++)this->str[i] = str[i];
    cout << "Default1ArgConstructor1:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
    //deep copy
    /*this->size = other.size;
    this->str = new char [size]{};*/
    //for (int i = 0; i < this->size; i++) this->str[i] = other.str[i];
    cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other)
{
    //shalow copy
    this->size = other.size;
    this->str = other.str;
    other.size = NULL;
    other.str = nullptr;
    cout << "MoveConstructor:\t" << this << endl;
}

String::~String()
{
    delete[]str;
    cout << "DefaultDestructor:\t" << this << endl;
}
int String::get_size() const
{
    return this->size;
}
char* String::get_array()
{
    return this->str;
}

const char* String::get_array()const
{
    return this->str;
}
//Operators;
String& String::operator=(String&& other)noexcept
{
    if (this == &other)return*this;
    delete[]this->str;
    this->size = other.size;
    this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    cout << "MoveAssignment:\t" << this << endl;


}
String& String::operator=(const String& other)noexcept
{
    if (this == &other)return *this;
    delete[]this->str;
    this->size = other.size;
    this->str = new char[this->size];
    for (int i = 0; i < this->size; i++) this->str[i] = other.str[i];
    return *this;
}
const char& String::operator[](int i)const
{
    return str[i];
}
char& String::operator[](int i)
{
    return str[i];
}

String operator+(const String& left, const String& right)
{
    String cat(left.get_size() + right.get_size() - 1);
    for (int i = 0, j = 0; i < cat.get_size(); i++)
    {
        if (i < left.get_size()-1)cat[i] = left[i];
        else cat[i] = right[j++];
    }
    /*strcat(left.get_array(), right.get_array());*/
    return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
    os << obj.get_array();
    return os;
}
std::istream& operator>>(std::istream& is, String& obj)
{
    const int SIZE = 102400;
    char buffer[SIZE] = {};
    is >> buffer;
    obj = buffer;
    return is;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
/// Class defenition end - конец определения класса
///////////////////////////////////////////////////////////////////////////////////////////////////