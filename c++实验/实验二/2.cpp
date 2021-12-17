#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
    string input;
    cout<<"Enter a sentence: ";
    getline(cin,input); //语法是输入流和字符串
    int count[26] = {0},i,wordCount=0; //定义字母，读取的位数，单词数目
    for(i = 0; i< input.size();i++)
    {
        if(((input[i]>='a' && input[i] <= 'z')||(input[i]>='A' && input[i] <= 'Z'))&&(input[i+1]=='.'||input[i+1]
        ==','||input[i+1]==' '))//通过分割判断单词的个数
            wordCount++;
        //鲁棒性，大小写转化成相同的
        if(input[i]>='a' && input[i] <= 'z') // 记录每个字母存了多少个，大写
            count[input[i]-'a']++; 
        if(input[i]>='A' && input[i] <= 'Z') // 小写
            count[input[i]-'A']++;
    }

    cout<<endl<<wordCount+1<<" words "<<endl; //单词数目输出

    for(i=0; i<26; i++) // 每个字母数目输出
    {
        if(count[i]>0)
        cout<<count[i]<<" "<<(char)('a'+i)<<endl; //通过转化ASCii0~26输出字符
    }

}