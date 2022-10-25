#ifndef HEADER_FOR_ALL_H_INCLUDED
#define HEADER_FOR_ALL_H_INCLUDED

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using std::string;
using std::vector;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::stoi;
namespace DATA_ANALYSIS
{


class Data_analysis
{
public:
    /*
    enum international_dimension {t,L,M,I,T,N,LV};//SI单位制的量纲

    enum unit_of_t  {s,minute,hour};
    enum unit_of_L  {pm,nm,wei_m,mm,cm,dm,m,km};
    enum unit_of_M  {mg,g,kg};
    enum unit_of_I  {A};
    enum unit_of_T  {k,C};
    enum unit_of_N  {mol};
    enum unit_of_LV {cd};
    //这上面是分别对应的常用单位
    union all_unit
    {
        unit_of_L unit_L;
        unit_of_T unit_t;
        unit_of_M unit_M;
        unit_of_I unit_I;
        unit_of_N unit_N;
        unit_of_T unit_T;
        unit_of_LV unit_LV;
    };
    */
    const string SI_units[19] = {"s","minute","hour","pm","nm","wei_m","mm","cm","dm","m","km","mg","g","kg","A","k","C","mol","cd"};
    const double accurate_confedence_coffecient[12] = {0,8.98,2.48,1.59,1.24,1.05,0.93,0.84,0.77,0.72,0.55,0.47};
    const double approximate_confedence_coffecient[12] = {0,9,1.5,1.6,1.2,1,1,1,1,1,0.55,0.47};
private:;
    string name; //最终要计算的结果是什么
    int data_num; //总共测了几类数据（物理量）
    vector<string> data_name; //这些测得物理量的名称
    vector<string> dimension ;//这些物理量的量纲，第一个量纲储存在0号位置
    vector<string> data_units;//这些物理量的单位，第一个单位储存在0号位置
    vector<double*> data_measured; //这些物理量的具体数据，第一组数据储存在0号位置
    vector<double> insturment_uncertanty;//仪器的不确定度
    vector<double*> data_calculated; //计算后的结果，如均值，实验标准差等。
public:
    Data_analysis();//默认构造函数
    ~Data_analysis();//析构函数
    void set_name(); //设置最终计算的变量的名称
    void set_data_num();//设置要测几类数据（物理量）
    void set_data_name();//设置测得的测得数据的名称
    void set_data_unit();//设置测得物理量的单位
    double* input_data(int i);//输入第i+1个物理量数据，第一组数据储存在0号位置
    void set_insturment_uncertanty();
    double* deal_data(int i);//处理输入的第i+1组数据,i从0开始
    void show();//展示结果
    void check_state(int);
    void modify(int);
    friend ostream & operator<<(ostream& os,Data_analysis &);//重构算符
};

}
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
}


#endif // HEADER_FOR_ALL_H_INCLUDED
