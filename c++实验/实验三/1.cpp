#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class BookInfo
{
    public:
        BookInfo();
        BookInfo(string b); // 1 parameter
        BookInfo(string a,string b);

        void connect(string &c);
        void output();

        friend ostream& operator<<(ostream &outs,BookInfo &d); //只能写成友元函数形式，若成员函数
        friend istream& operator>>(istream &ins,BookInfo &d);
    
    private:
        std::string authername;
        std::string bookname;   
};

class UpdatedBook: public BookInfo
{
    private:
        int edition;
    public:
        UpdatedBook(string a,string b,int e):BookInfo(a,b),edition(e)//析构函数
        {
            ;
        }
        int edi_return()
        {
            return edition;
        }
        ~UpdatedBook(){;}
};

int main(void)
{
    string c = "Null";
    BookInfo Book; //默认不能有括号
    BookInfo Book1("Gone with the wind"); //后面是
    BookInfo Book2;
    BookInfo Book3("abc","qwe");

    UpdatedBook Book4("tony","shock time",9);

    cout << "enter:(Please use a+b!) ";
    cin >> Book2;
    
    cout << Book2; // 题目1
    cout << Book3;
    
    int ed = Book4.edi_return();
    cout << "the edition:" <<ed;
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

BookInfo::BookInfo(string a,string b) //Constructors
{
    this ->authername = a;
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

ostream& operator<<(ostream &outs,BookInfo &d)//只能写成友元函数形式，若成员函数
{
    string s = d.authername + "&" + d.bookname;
    outs << "book:" << s <<endl;
    return outs;
}

istream& operator>>(istream &ins,BookInfo &d)
{
    string s;
    ins >> s;
    int pos = s.find("+",0);
    string tem = s.substr(0,pos);
    d.authername = tem; //作者串
    tem = s.substr(pos+1,s.length()-pos-1);//分割出剩下的串
    d.bookname = tem;//书名串
    
    return ins;
}