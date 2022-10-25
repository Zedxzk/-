#include"Header_for_all.h"
namespace DATA_ANALYSIS
{
Data_analysis::Data_analysis()
{
    set_name();
    set_data_num();
    set_data_name();
    for(int i = 0;i<data_num;i++)
    {
        data_measured.push_back(input_data(i));
        set_insturment_uncertanty();
    }
    for(int i = 0;i<data_num;i++)
    {
        data_calculated.push_back(deal_data(i));
    }
}

Data_analysis::~Data_analysis()
{
    for(double* pd : data_measured) delete [] pd;
    for(double* pd : data_calculated) delete [] pd;
}

void Data_analysis::set_name()
{
    cout<<"请输入实验最终计算的物理量名称(这个步骤目前没什么用，走一个形式)：";
    cin>>name;
}

void Data_analysis::set_data_num()
{
    cout<<"这个过程中测量的数据有几种（也就是有几竖列,暂不支持超过10种的物理量）？";
    char c;
    cin>>c;
    if(isdigit(c) != 0) data_num = stoi(&c);
    else
    {
        cout<<"你瞅瞅你输入的是数字么？重输！"<<endl;
        int tmp = 0;
        while ((tmp = getchar()) != '\n');
        set_data_num();
    }
}

void Data_analysis::set_data_name()
{
    string temp;
    for(int i = 0;i < data_num;i++)
    {
        cout<<"请输入第"<<i+1<<"个物理量的名称:";
        cin>>temp;
        data_name.push_back(temp);
        cout<<"请输入"<<temp<<"的单位:";
        cin>>temp;
        data_units.push_back(temp);
    }
}



double* Data_analysis::input_data(int i) //输入第i+1组数据，以数组形式储存，这个数组中，0号元素储存测量的次数，后面依次对应第j次测量。
{
    int temp;
    cout<<"物理量"<<data_name[i]<<"测了几次？";
    cin>>temp;
    double *pd = new double [temp+1];
    pd[0] = temp;//用以储存测量的次数
    for(int j = 1;j < temp+1;j++)
    {
        cout<<"请输入"<<data_name[i]<<"的第"<<j<<"项数据:";
        cin>>pd[j];
    }
    return pd;
}
void Data_analysis::set_insturment_uncertanty()
{
    cout<<"请输入测量仪器的不确定度Δ仪（注意保持单位一致）:";
    double temp;
    cin>>temp;
    insturment_uncertanty.push_back(temp);
}

double* Data_analysis::deal_data(int i)//处理第i+1组数据
{
    double ave=0,var=0,exp_var=0,sum=0;
    for(int k = 1;k <= data_measured[i][0];k++)
    {
        sum += data_measured[i][k];
    }
    int j = int(data_measured[i][0]);
    ave =sum/j;
    for(int k = 1;k <= data_measured[i][0];k++)
    {
        double x = data_measured[i][k];
        var += (x - ave)*(x - ave);
        exp_var += (x - ave)*(x - ave);
    }
    var = sqrt(var/j);
    exp_var = sqrt(exp_var/(j-1));
    double* pd =new double [10];
    pd[0] = ave;
    pd[1] = var;
    pd[2] = exp_var;
    int time = int(data_measured[i][0]); //测量的次数
    if(time >= 2 && time <=10 )
    {
        pd[3] = exp_var * accurate_confedence_coffecient[time-1];
        pd[4] = exp_var * approximate_confedence_coffecient[time-1];
    }
    else if(time >=11 && time <= 15)
    {
        pd[3] = exp_var * accurate_confedence_coffecient[10];
        pd[4] = exp_var * approximate_confedence_coffecient[10];
    }
    else if(time >=15 && time <= 20)
    {
        pd[3] = exp_var * accurate_confedence_coffecient[11];
        pd[4] = exp_var * approximate_confedence_coffecient[11];
    }
    else
    {
        pd[3] = 0;
        pd[4] = 0;
    }
    pd[5] = insturment_uncertanty[i];
    pd[6] = sqrt(pd[3] * pd[3] + pd[5] * pd[5]);
    pd[7] = sqrt(pd[4] * pd[4] + pd[5] * pd[5]);
    pd[8] = pd[6]/ave;
    pd[9] = pd[7]/ave;
    return pd;
}

void Data_analysis::show()
{
    int order=0;
    for(string x : data_name)
    {
        cout<<"********************"<<x<<"的数据"<<"********************"<<endl;
        int i=1;
        cout<<"序号"<<"             "<<"数据"<<endl;
        for(int j = 1;j <= data_measured[order][0];j++)
        {
            cout<<" "<<i<<"               "<<data_measured[order][j]<<data_units[order]<<endl;
            i++;
        }

        cout<<"均值="<<data_calculated[order][0]<<data_units[order]<<endl;
        cout<<"标准差="<<data_calculated[order][1]<<data_units[order]<<endl;
        cout<<"实验标准差="<<data_calculated[order][2]<<data_units[order]<<endl;
        if(data_calculated[order][3] >= 0)
        {
        cout<<"uA(精确)="<<data_calculated[order][3]<<data_units[order]<<endl;
        cout<<"uA(近似)="<<data_calculated[order][4]<<data_units[order]<<endl;
        cout<<"Δ仪(仪器的不确定度,也即uB)="<<data_calculated[order][5]<<data_units[order]<<endl;
        cout<<"u(不确定度,精确)=sqrt(uA(精确)^2 + Δ仪^2)="<<data_calculated[order][6]<<data_units[order]<<endl;
        cout<<"u(不确定度,近似)=sqrt(uA(近似)^2 + Δ仪^2)="<<data_calculated[order][7]<<data_units[order]<<endl;
        cout<<"E(相对不确定度,精确)=u(精确)/均值="<<data_calculated[order][8]<<endl;
        cout<<"E(相对不确定度,近似)=u(近似)/均值="<<data_calculated[order][9]<<endl;
        }
        cout<<"********************"<<x<<"的数据"<<"********************"<<endl<<endl;
        order++;
    }
}

void Data_analysis::check_state(int state)
{

    if(state == 0)
    {
        exit(0);
    }

    else if(state > 0 && state <= data_num)
    {
        modify(state);
    }

}

void Data_analysis::modify(int state)
{
    int temp;
    cout<<"物理量"<<data_name[state-1]<<"(也就是第"<<state<<"组数据）的第几个数据输入有误？";
    cin>>temp;
    cout<<"请更正第"<<temp<<"个数据：";
    cin>>data_measured[state-1][temp];
    cout<<"成功修改，下面是更正后的数据"<<endl<<endl;
    deal_data(state-1);
    show();
}

ostream &operator<<(ostream &os,Data_analysis &data)
{
    data.show();
    return os;
}
}
