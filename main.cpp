#include"Header_for_all.h"
#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using DATA_ANALYSIS::Data_analysis;
extern void show_info();

int main()
{
    show_info();
    Data_analysis real_data;
    cout<<real_data;
    int  state;
    while(true)
    {
        cout<<"\n请确认是否有数据输入错误，如果有，请输入第几组数据有误，并按下回车，然后再输入错误的序号，如果没有，输入0以退出\n";
        cin>>state;
        real_data.check_state(state);
    }
    return 0;
    system("pause");
}
