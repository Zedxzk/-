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
    cout<<"������ʵ�����ռ��������������(�������Ŀǰûʲô�ã���һ����ʽ)��";
    cin>>name;
}

void Data_analysis::set_data_num()
{
    cout<<"��������в����������м��֣�Ҳ�����м�����,�ݲ�֧�ֳ���10�ֵ�����������";
    char c;
    cin>>c;
    if(isdigit(c) != 0) data_num = stoi(&c);
    else
    {
        cout<<"�����������������ô�����䣡"<<endl;
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
        cout<<"�������"<<i+1<<"��������������:";
        cin>>temp;
        data_name.push_back(temp);
        cout<<"������"<<temp<<"�ĵ�λ:";
        cin>>temp;
        data_units.push_back(temp);
    }
}



double* Data_analysis::input_data(int i) //�����i+1�����ݣ���������ʽ���棬��������У�0��Ԫ�ش�������Ĵ������������ζ�Ӧ��j�β�����
{
    int temp;
    cout<<"������"<<data_name[i]<<"���˼��Σ�";
    cin>>temp;
    double *pd = new double [temp+1];
    pd[0] = temp;//���Դ�������Ĵ���
    for(int j = 1;j < temp+1;j++)
    {
        cout<<"������"<<data_name[i]<<"�ĵ�"<<j<<"������:";
        cin>>pd[j];
    }
    return pd;
}
void Data_analysis::set_insturment_uncertanty()
{
    cout<<"��������������Ĳ�ȷ���Ȧ��ǣ�ע�Ᵽ�ֵ�λһ�£�:";
    double temp;
    cin>>temp;
    insturment_uncertanty.push_back(temp);
}

double* Data_analysis::deal_data(int i)//�����i+1������
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
    int time = int(data_measured[i][0]); //�����Ĵ���
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
        cout<<"********************"<<x<<"������"<<"********************"<<endl;
        int i=1;
        cout<<"���"<<"             "<<"����"<<endl;
        for(int j = 1;j <= data_measured[order][0];j++)
        {
            cout<<" "<<i<<"               "<<data_measured[order][j]<<data_units[order]<<endl;
            i++;
        }

        cout<<"��ֵ="<<data_calculated[order][0]<<data_units[order]<<endl;
        cout<<"��׼��="<<data_calculated[order][1]<<data_units[order]<<endl;
        cout<<"ʵ���׼��="<<data_calculated[order][2]<<data_units[order]<<endl;
        if(data_calculated[order][3] >= 0)
        {
        cout<<"uA(��ȷ)="<<data_calculated[order][3]<<data_units[order]<<endl;
        cout<<"uA(����)="<<data_calculated[order][4]<<data_units[order]<<endl;
        cout<<"����(�����Ĳ�ȷ����,Ҳ��uB)="<<data_calculated[order][5]<<data_units[order]<<endl;
        cout<<"u(��ȷ����,��ȷ)=sqrt(uA(��ȷ)^2 + ����^2)="<<data_calculated[order][6]<<data_units[order]<<endl;
        cout<<"u(��ȷ����,����)=sqrt(uA(����)^2 + ����^2)="<<data_calculated[order][7]<<data_units[order]<<endl;
        cout<<"E(��Բ�ȷ����,��ȷ)=u(��ȷ)/��ֵ="<<data_calculated[order][8]<<endl;
        cout<<"E(��Բ�ȷ����,����)=u(����)/��ֵ="<<data_calculated[order][9]<<endl;
        }
        cout<<"********************"<<x<<"������"<<"********************"<<endl<<endl;
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
    cout<<"������"<<data_name[state-1]<<"(Ҳ���ǵ�"<<state<<"�����ݣ��ĵڼ���������������";
    cin>>temp;
    cout<<"�������"<<temp<<"�����ݣ�";
    cin>>data_measured[state-1][temp];
    cout<<"�ɹ��޸ģ������Ǹ����������"<<endl<<endl;
    deal_data(state-1);
    show();
}

ostream &operator<<(ostream &os,Data_analysis &data)
{
    data.show();
    return os;
}
}
