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
        cout<<"\n��ȷ���Ƿ������������������У�������ڼ����������󣬲����»س���Ȼ��������������ţ����û�У�����0���˳�\n";
        cin>>state;
        real_data.check_state(state);
    }
    return 0;
    system("pause");
}
