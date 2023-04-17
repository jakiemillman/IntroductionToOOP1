#pragma once
#include <iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Class decloration - объ€вление класса
///////////////////////////////////////////////////////////////////////////////////////////////////
class String;
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);

class String
{
    char* str; //размер символов;
    int size; //размер строки
public:
    int get_size() const;
    char* get_array();
    const char* get_array()const;
    //Constructors
    explicit String(int size = 256);
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();
    //Operators;
    String& operator=(String&& other)noexcept;
    String& operator =(const String& other)noexcept;
    const char& operator[](int i)const;
    char& operator[](int i);
    //Methods
    void Print()const;
};
///////////////////////////////////////////////////////////////////////////////////////////////////
/// Class decloration end - конец объ€влени€ класса
///////////////////////////////////////////////////////////////////////////////////////////////////
