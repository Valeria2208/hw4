//
//  main.cpp
//  hw4
//
//  Created by Valeria Dudinova on 11.10.2024.
//

#include <iostream>
using namespace std;

class MyString
{
private:
    char* str;
    int length;

public:
    MyString() : str(nullptr), length(0) {}

    MyString(const char* input)
    {
        length = 0;
        while (input[length] != '\0')
        {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; ++i)
        {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    MyString(const MyString& source)
    {
        length = source.length;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i)
        {
            str[i] = source.str[i];
        }
        str[length] = '\0';
    }

    ~MyString()
    {
        delete[] str;
    }

    MyString& operator=(const MyString& right)
    {
        if (this != &right)
        {
            delete[] str;

            length = right.length;
            str = new char[length + 1];
            for (int i = 0; i < length; ++i)
            {
                str[i] = right.str[i];
            }
            str[length] = '\0';
        }
        return *this;
    }

    void input()
    {
        char buffer[1000];
        cout << "Enter string: ";
        cin >> buffer;

        delete[] str;
        length = 0;
        while (buffer[length] != '\0')
        {
            length++;
        }

        str = new char[length + 1];
        for (int i = 0; i < length; ++i)
        {
            str[i] = buffer[i];
        }
        str[length] = '\0';
    }

    // Метод для виведення рядка на екран
    void output() const
    {
        if (str != nullptr)
        {
            cout << str;
        }
    }

    // Аксесор (гетер) для отримання рядка
    const char* getString() const
    {
        return str;
    }
    // Аксесор (гетер) для отримання довжини рядка
    int getLength() const
    {
        return length;
    }
    // Метод для виведення рядка в потік
    ostream& print(ostream& os) const
    {
        if (str != nullptr)
        {
            os << str;
        }
        return os;
    }
    // Метод для введення рядка з потоку
    istream& read(istream& is)
    {
        char buffer[1000];
        is >> buffer;

        delete[] str;
        length = 0;
        while (buffer[length] != '\0')
        {
            length++;
        }

        str = new char[length + 1];
        for (int i = 0; i < length; ++i)
        {
            str[i] = buffer[i];
        }
        str[length] = '\0';

        return is;
    }
};
// Перевантаження оператора виведення
ostream& operator<<(ostream& os, const MyString& obj)
{
    return obj.print(os);
}

// Перегрузка оператора ввода
istream& operator>>(istream& is, MyString& obj)
{
    return obj.read(is);
}

int main() {
    MyString s1("Hello");
    MyString s2;

    cout << "Enter string: ";
    cin >> s2;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    s2 = s1;  // Оператор присвоєння
    cout << "After assignment s2 = s1: " << s2 << endl;

    return 0;
}

