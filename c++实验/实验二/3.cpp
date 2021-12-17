#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class BookInfo
{
    public:
        BookInfo();
        BookInfo(string b); // 1 parameter

        void connect(string &c);
        void output();

        friend ostream& operator<<(ostream &outs,const BookInfo &d); //只能写成友元函数形式，若成员函数
        friend istream& operator>>(istream &ins,BookInfo &d);
    
    private:
        std::string authername;
        std::string bookname;   
};

int main(void)
{
    string c = "Null";
    BookInfo Book; //默认不能有括号
    BookInfo Book1("Gone with the wind"); //后面是
    Book.output();
    Book1.output();
    Book1.connect(c);
    cout << "After connecting:" << c;
}

BookInfo::BookInfo() //Default Constructors
{
    authername = "Tony";
    bookname = "Peaky Blinders";
}

BookInfo::BookInfo(string b) //Constructors
{
    this ->authername = "unknown";
    this ->bookname = b;
}

void BookInfo::output(void)
{
    std::cout << "the authername: " << authername << ",the bookname: "<< bookname << endl;
}

void BookInfo::connect(string &c)
{
    c = this -> authername + " "+ this ->bookname; //通过this指针直接访问 private
}

friend ostream& operator<<(ostream &outs,const BookInfo &d)//只能写成友元函数形式，若成员函数
{
    string s = d.authername + "&" + d.bookname;
    outs << s;
    return outs;
}

friend istream& operator>>(istream &ins,BookInfo &d)
{
    string s;
    ins << s;
    int pos = s.find("+",0);
    string tem = s.substr(0,pos);
    d.bookname = tem;
    tem = s.substr(pos+1,s.length()-pos-2);//分割出剩下的串
    d.authername = tem;
}