#include"String.h"
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