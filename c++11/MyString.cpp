#include <bits/stdc++.h>
using namespace std;
class MyString
{
public:
private:
    char *_data;
    size_t _len;
    void _init_data(const char *s)
    {
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }

public:
    MyString() : _data(nullptr), _len(0) {}
    MyString(const char *p) : _len(strlen(p))
    {
        _init_data(p);
    }
    MyString(const MyString &s) : _len(s._len)
    {
        _init_data(s._data);
        // s._data=nullptr;
        // s._len=0;
    }
    MyString(MyString &&str) noexcept : _data(str._data), _len(str._len)
    {
        str._len = 0;
        str._data = nullptr;
    }
    MyString &operator=(const MyString &str)
    {
        if (this != &str)
        {
            if (_data)
                delete _data;
            _len = str._len;
            _init_data(str._data);
        }
        return *this;
    }
    MyString &operator=(MyString &&str)
    {
        if (this != &str)
        {
            if (_data)
                delete _data;
            _len = str._len;
            _init_data(str._data);
            str._len = 0;
            str._data = nullptr;
        }
        return *this;
    }
    virtual ~MyString()
    {
        if (_data)
        {
            delete _data;
        }
    }
    bool operator<(const MyString &str)
    {
        return strcmp(_data, str._data);
    }
    bool operator==(const MyString &str)
    {
        return strcmp(_data, str._data) == 0;
    }
    void print()
    {
        if (_data != nullptr)
        {
            printf("data addr: %p\n", _data);
            cout << _data << " len=" << _len << endl;
        }
    }
};
int main()
{
    MyString str1("hello");
    MyString str2(str1);
    cout << "str1" << endl;
    str1.print();
    cout << "str2" << endl;
    str2.print();
}
