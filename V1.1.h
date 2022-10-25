#ifndef V1_1_H_INCLUDED
#define V1_1_H_INCLUDED

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

namespace DATA_ANALYSIS
{


class Data_analysis
{
public:
    /*
    enum international_dimension {t,L,M,I,T,N,LV};//SI��λ�Ƶ�����

    enum unit_of_t  {s,minute,hour};
    enum unit_of_L  {pm,nm,wei_m,mm,cm,dm,m,km};
    enum unit_of_M  {mg,g,kg};
    enum unit_of_I  {A};
    enum unit_of_T  {k,C};
    enum unit_of_N  {mol};
    enum unit_of_LV {cd};
    //�������Ƿֱ��Ӧ�ĳ��õ�λ
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
private:
    string name; //����Ҫ����Ľ����ʲô
    int data_num; //�ܹ����˼������ݣ���������
    vector<string> data_name; //��Щ���������������
    vector<string> dimension ;//��Щ�����������٣���һ�����ٴ�����0��λ��
    vector<string> data_units;//��Щ�������ĵ�λ����һ����λ������0��λ��
    vector<double*> data_measured; //��Щ�������ľ������ݣ���һ�����ݴ�����0��λ��
    vector<double*> data_calculated; //�����Ľ�������ֵ��ʵ���׼��ȡ�
public:
    Data_analysis();//Ĭ�Ϲ��캯��
    ~Data_analysis();//��������
    void set_name(); //�������ռ���ı���������
    void set_data_num();//����Ҫ�⼸�����ݣ���������
    void set_data_name();//���ò�õĲ�����ݵ�����
    void set_data_unit();//���ò���������ĵ�λ
    double* input_data(int i);//�����i+1�����������ݣ���һ�����ݴ�����0��λ��
    double* deal_data(int i);//��������ĵ�i+1������,i��0��ʼ
    void show();//չʾ���
    void check_state(int);
    void modify(int);
    friend ostream & operator<<(ostream& os,Data_analysis &);//�ع����
};

}
namespace FORMULA_RECOGNITION
{

string spilt_unit(const string &b,int* position_of_left_bracket,int* position_of_right_bracket);
vector<int> find_left_bracket(const string &a);   //�ҵ������ŵ�λ��
vector<int> find_right_bracket(const string &a);  //�ҵ������ŵ�λ��
vector<int> find_multiply(const string &a);
vector<int> find_devide(const string &a);
vector<int> find_plus(const string &a);
vector<int> find_minus(const string &a);
vector<int> find_index(const string &a);
void unit_analysis(const string &a);
}


#endif // V1_1_H_INCLUDED
