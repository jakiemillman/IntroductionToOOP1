// STRING.cpp 

#include <iostream>

using namespace std;


class String
{
    char* str; //размер символов;
    int size; //размер строки
public:
    //Constructors
    explicit String(int size=256)
    {
        this->size = size;
        this->str = new char[size] {};
        cout << "Default1ArgConstructor:\t" << this << endl;
    }
    explicit String(const char* str)
    {
        this->size = strlen(str)+1;
        this->str = new char[size] {};
        for (int i = 0; i < size; i++)this->str[i] = str[i];
    }
    String(const String& other)
    {
        this->size = other.size;
        this->str = new char [size]{};
        for (int i = 0; i < this->size; i++) this->str[i] = other.str[i];
        cout << "CopyConstructor:\t" << this << endl;
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
    int Get_Size()
    {
        return this->size;
    }
    char* get_array()
    {
        return this->str;
    }
    
   
};
String operator+(String left, String right)
{
    int size = left.Get_Size() + right.Get_Size() - 1;
    char* str = new char[size] {};
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i < left.Get_Size()-1)str[i] = left.get_array()[i];
        else str[i] = right.get_array()[j++];
    }
    /*strcat(left.get_array(), right.get_array());*/
    return String(str);
}
std::ostream& operator<<(std::ostream& os, String& obj)
{
    os << obj.get_array();
    return os;
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
    String str1("Hello ");
    String str2("world");
    String str3 = str1 + str2;
    str3.Print();
    cout << str1 << " + " << str2 << " = " << str3 << endl;



#endif
}

