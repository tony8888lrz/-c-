#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class BookInfo
{
    public:
        BookInfo();
        BookInfo(string b); // 1 parameter
        BookInfo(string a,string b):authername(a),bookname(b){}; // 1 parameter

        void output();

        friend ostream& operator<<(ostream &outs,const BookInfo &d); //只能写成友元函数形式，若成员函数
        friend istream& operator>>(istream &ins,BookInfo &d);
    
    private:
        std::string authername;
        std::string bookname;   
};

class UpdateBook:BookInfo
{
    public:
        UpdateBook(string a,string b,int c):BookInfo(a,b),edition(c){};
        int get_edition(const UpdateBook &A);
    private:
        int edition;
};

int main(void)
{
    string c = "Null";
    BookInfo Book("Tony","Gone with the wind"); //后面是
    BookInfo Book1;
    UpdateBook Book2("python","probility",9);
    //Book.output();
    cin >> Book1;
    
    cout << Book1 << endl;
    cout << "The "<<Book2.get_edition(Book2)<< " edition"<<endl;
    return 0;
}

BookInfo::BookInfo() //Default Constructors
{
    authername = "Tony";
    bookname = "Peaky Blinders";
}


void BookInfo::output(void)
{
    std::cout << "the authername: " << authername << ",the bookname: "<< bookname << endl;
}


ostream& operator<<(ostream &outs,const BookInfo &d)//只能写成友元函数形式，若成员函数
{
    string s = d.authername + "&" + d.bookname;
    outs << s;
    return outs;
}

istream& operator>>(istream &ins,BookInfo &d)
{
    cout << "use auther name + book name:" << endl;
    string s;
    ins >> s;
    int pos = s.find("+",0);
    string tem = s.substr(0,pos);
    d.authername = tem;
    tem = s.substr(pos+1,s.length()-pos-1);//分割出剩下的串
    d.bookname = tem;
    
    return ins;
}

int UpdateBook::get_edition(const UpdateBook &A)
{
    //return this->edition;为啥这段代码不行
    return A.edition;
}