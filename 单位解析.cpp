#include<string>
#include<vector>
#include"Header_for_all.h"
using std::string;
using std::vector;

namespace FORMULA_RECOGNITION
{

string spilt_unit(const string &b,int* position_of_left_bracket,int* position_of_right_bracket);
vector<int> find_left_bracket(const string &a);   //找到左括号的位置
vector<int> find_right_bracket(const string &a);  //找到反括号的位置
vector<int> find_multiply(const string &a);
vector<int> find_devide(const string &a);
vector<int> find_plus(const string &a);
vector<int> find_minus(const string &a);
vector<int> find_index(const string &a);
void unit_analysis(const string &a);

void unit_analysis(const string &a)
{
    int size_of_a = a.size();
    int position_of_muitiple[size_of_a];
    int position_of_devide[size_of_a];
    int position_of_plus[size_of_a];
    int position_of_minus[size_of_a];
    int position_of_left_bracket[size_of_a];
    int position_of_right_bracket[size_of_a];
    int position_of_index[size_of_a];

}


vector<int> find_left_bracket(const string &a)
{
    static vector<int> position_of_left_bracket = {0,};
    //数组第0号元素储存总共有多少个左括号，后面第i个元素依次存放第i个左括号的位置，其余的同理
    int position = 1;//储存左括号的位置
    int now=0;//标识现在读取到a的哪一个字符了
    for(char t : a)
    {
        if(t == '(' || t == '（')
           {
               position_of_left_bracket.push_back(now);
               position++;
           }
           now++;
    }
    position_of_left_bracket[0] = position - 1;
    return position_of_left_bracket;
}

vector<int> find_right_bracket(const string &a)
{
    static vector<int> position_of_right_bracket = {0,};
    //数组第0号元素储存总共有多少个左括号，后面第i个元素依次存放第i个左括号的位置，其余的同理
    int position = 1;//储存左括号的位置
    int now=0;//标识现在读取到a的哪一个字符了
    for(char t : a)
    {
        if(t == ')' || t == '）')
           {
               position_of_right_bracket.push_back(now);
               position++;
           }
           now++;
    }
    position_of_right_bracket[0] = position - 1;
    return position_of_right_bracket;
}

vector<int> find_multiply(const string &a)
{
    static vector<int> position_of_multiply = {0,};
    int position = 1;
    int now=0;
    for(char t : a)
    {
        if(t == '*' )
           {
               position_of_multiply.push_back(now);
               position++;
           }
           now++;
    }
    position_of_multiply[0] = position - 1;
    return position_of_multiply;
}

vector<int> find_devide(const string &a)
{
    static vector<int> position_of_devide = {0,};
    int position = 1;
    int now=0;
    for(char t : a)
    {
        if(t == '/' )
           {
               position_of_devide.push_back(now);
               position++;
           }
           now++;
    }
    position_of_devide[0] = position - 1;
    return position_of_devide;
}

vector<int> find_plus(const string &a)
{
    static vector<int> position_of_plus = {0,};
    int position = 1;
    int now=0;
    for(char t : a)
    {
        if(t == '+' )
           {
               position_of_plus.push_back(now);
               position++;
           }
           now++;
    }
    position_of_plus[0] = position - 1;
    return position_of_plus;
}

vector<int> find_minus(const string &a)
{
    static vector<int> position_of_minus = {0,};
    int position = 1;
    int now=0;
    for(char t : a)
    {
        if(t == '-' )
           {
               position_of_minus.push_back(now);
               position++;
           }
           now++;
    }
    position_of_minus[0] = position - 1;
    return position_of_minus;
}

vector<int> find_index(const string &a)
{
    static vector<int> position_of_index = {0,};
    int position = 1;
    int now=0;
    for(char t : a)
    {
        if(t == '^' )
           {
               position_of_index.push_back(now);
               position++;
           }
           now++;
    }
    position_of_index[0] = position - 1;
    return position_of_index;
}
}
