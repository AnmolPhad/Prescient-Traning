#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    char *str;
    int length;

public:
    MyString(const char *s = "")
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    MyString(const MyString &other)
    {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    ~MyString()
    {
        delete[] str;
    }

    MyString operator+(const MyString &other)
    {
        MyString temp;
        delete[] temp.str;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        temp.str = new char[temp.length + 1];

        strcpy(temp.str, str);
        strcat(temp.str, other.str);

        return temp;
    }

    bool operator==(const MyString &other)
    {
        return strcmp(str, other.str) == 0;
    }

    void reverse()
    {
        int start = 0;
        int end = length - 1;

        while (start < end)
        {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;

            start++;
            end--;
        }
    }
    int search(const char *word)
    {
        char *result = strstr(str, word);

        if (result != nullptr)
        {
            return result - str;
        }

        return -1;
    }

    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    MyString s1("Hello");
    MyString s2(" World");

    // Concatenation
    MyString s3 = s1 + s2;

    cout << "Concatenation: ";
    s3.display();

    // Comparison
    if (s1 == s2)
        cout << "Strings are equal\n";
    else
        cout << "Strings are not equal\n";

    // Search
    MyString s4("Hello Worl");

    int position = s4.search("World");

    if (position >= 0)
    {
        cout << "World found at index: "
             << position << endl;
    }
    else
    {
        cout << "World not fount" << endl;
    }

    

    // Reverse
    s4.reverse();

    cout << "After reverse: ";
    s4.display();

    return 0;
}