#include <math.h>
#include <iostream>
#include <string>
using namespace std;

string mess;

bool checkx1(double x, double z){
    mess="������� ����������� �������� ��� x!";
    if(x<0)
        return false;
    if(z==0 && x!=floor(x))
        return false;
    mess="�������� x ����������� �����!";
    return true;
}

double readv(double v){
    mess="����� ������� ��������!";
    if(abs(v)>100){
        mess="������� �������� �� ������� � ������� -100 .. +100!";
        cout<<mess<<endl;
    }
    return v;
}

double q_calculation(double x, double y, double z){
    readv(x);
    if(mess=="������� �������� �� ������� � ������� -100 .. +100!")
        return 0;
    readv(y);
    if(mess=="������� �������� �� ������� � ������� -100 .. +100!")
        return 0;
    readv(z);
    if(mess=="������� �������� �� ������� � ������� -100 .. +100!")
        return 0;
    if(checkx1(x,z)==false){
       cout<<mess;
        return 0;
    }
    return round((abs( sin( abs( y - pow(z, x) ) ) + sqrt(x) - sqrt( 0.5 * pow( y*z, 4 ) + 2 * M_PI) ))*100)/100.0;
}


void test_task2_1(){
    double ts[6]={5, -10 , -1615951915651151962.0 , 5195126519321549565.0 , 4965.6 , -84.56};//значення для тестування першої функції
    cout<<endl<<endl<<"�������� ����� �������"<<endl<<endl;
    for(short i=0; i<6; i++){
        cout<<i+1<<"  x = "<<ts[i]<<"   "<<readv(ts[i])<<"   ";//<<mess<<"  ";
        if(i<2 ||  i>3)
            cout<<(mess=="����� ������� ��������!")<<endl<<endl;
        else
            cout<<(mess=="������� �������� �� ������� � ������� -100 .. +100!")<<endl<<endl;
    }
    cout<<endl<<endl<<"�������� ����� �������"<<endl<<endl;
    double ts2[3][2]={ {5 , 0}, {-7 , 9}, {8.4 , 0}};
    for(short i=0; i<3; i++){
        cout<<i+7<<"  x = "<<ts2[i][0]<<", z = "<<ts2[i][1]<<"   "<<checkx1(ts2[i][0], ts2[i][1])<<"   ";
        if(i==0)
            cout<<(mess=="�������� x ����������� �����!")<<endl<<endl;
        else
            cout<<(mess=="������� ����������� �������� ��� x!")<<endl<<endl;
    }
    cout<<endl<<endl<<"�������� ������ �������"<<endl<<endl;
    double x=2,y=5,z=10;
    cout<<12<<"  x = "<<x<<", y = "<<y<<", z = "<<z<<"   "<<q_calculation(x,y,z)<<"   ";
    if(q_calculation(x,y,z)==1765.67){
        mess="���������� ������� ������!";
        cout<<"���������� ������� ������!"<<"  "<<(mess=="���������� ������� ������!")<<endl;
    }
}


bool checkx2(double x){
    mess="������� ����������� �������� ��� x!";
    if(x<M_PI*(-7)){
        cout<<mess<<endl;
        return false;
    }
    mess="�������� x ����������� �����!";
    return true;
}

bool checkval(double x, double y, double z){
    mess="��� �������� �� ������������� �����!";
    if( (( pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) ) ) <0)||( pow(M_E, abs(x)) < ( sqrt( abs( y-z ) ) )/( sin(z*y) ) )){
        cout<<mess<<endl;
        return false;
    }
    mess="��� �������� ������������� �����!";
    return true;
}

double s_calculation(double x, double y, double z){
    readv(x);
    if(mess=="������� �������� �� ������� � ������� -100 .. +100!")
        return 0;
    readv(y);
    if(mess=="������� �������� �� ������� � ������� -100 .. +100!")
        return 0;
    readv(z);
    if(mess=="������� �������� �� ������� � ������� -100 .. +100!")
        return 0;
    if(checkx2(x)==false){
        cout<<mess;
        return 0;
    }
    if(checkval(x,y,z)==false){
        cout<<mess;
        return 0;
    }
    return round((0.5*((y*y+2*z)/(sqrt(7*M_PI+x)))-sqrt(pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) )))*100)/100.0;
}

void test_task2_2(){
    double ts[4]={59, 98492649485661515864.0 , -53868638465435485648.0 , -14};//значення для тестування першої функції
    cout<<endl<<endl<<"�������� ����� �������"<<endl<<endl;
    for(short i=0; i<4; i++){
        cout<<i+1<<"  x = "<<ts[i]<<"   "<<readv(ts[i])<<"   ";//<<mess<<"  ";
        if(i==0 ||  i==3)
            cout<<(mess=="����� ������� ��������!")<<endl<<endl;
        else
            cout<<(mess=="������� �������� �� ������� � ������� -100 .. +100!")<<endl<<endl;
    }
    cout<<endl<<endl<<"�������� ����� �������"<<endl<<endl;
    double ts2[2]={-23 , 15};
    for(short i=0; i<2; i++){
        cout<<i+5<<"  x = "<<ts2[i]<<"   "<<checkx2(ts2[i])<<"   ";
        if(i==1)
            cout<<(mess=="�������� x ����������� �����!")<<endl<<endl;
        else
            cout<<(mess=="������� ����������� �������� ��� x!")<<endl<<endl;
    }
	cout<<endl<<endl<<"�������� ������ �������"<<endl<<endl;
    double ts3[2][3]={{1 , 90 , 3},{15 , 3 , 8}};
    for(short i=0; i<2; i++){
        cout<<i+7<<"  x = "<<ts3[i][0]<<",  y = "<<ts3[i][1]<<",  z = "<<ts3[i][2]<<"   "<<checkval(ts3[i][0], ts3[i][1], ts3[i][2])<<"   ";
        if(i==1)
            cout<<(mess=="��� �������� ������������� �����!")<<endl<<endl;
        else
            cout<<(mess=="��� �������� �� ������������� �����!")<<endl<<endl;
    }
    cout<<endl<<endl<<"�������� �������� �������"<<endl<<endl;
    double x=15,y=3,z=-17;
    cout<<9<<"  x = "<<x<<", y = "<<y<<", z = "<<z<<"   "<<s_calculation(x,y,z)<<"   ";
    if(s_calculation(x,y,z)==-1810,1){
        mess="���������� ������� ������!";
        cout<<"���������� ������� ������!"<<"  "<<(mess=="���������� ������� ������!")<<endl;
    }
}
string cut(string v){
    while((v.rfind('.')<v.rfind('0') && v[v.size()-1]=='0') || v[v.size()-1]=='.')
        v.erase(v.size()-1, 1);
    return v;
}

string check_speed(double s){
    if(s<0)
        return "������� ����� ����� 0!";
    if(s>10000)
        return "������� ����� ��������!";
    if(s>=0 && s<117){
        return "�������� F0, ������� - 38,9%";
    }else if(s>=117 && s<181){
        return "�������� F1, ������� - 35,6%";
    }else if(s>=181 && s<254){
        return "�������� F2, ������� - 19,4%";
    }else if(s>=254 && s<333){
        return "�������� F3, ������� - 4,9%";
    }else if(s>=333 && s<419){
        return "�������� F4, ������� - 1,1%";
    }else{
        return "�������� F5, ������� - ����� 0,1% ";
    }
}

int count_sym(string s, char a){
    int n=0;
    for(int i=0; i<s.length(); i++)
        s[i]==a ? n++ : n+=0; ;
    return n;
}

string calc_temp(short temp[6]){
    double m=0;
    for(short i=0; i<6; i++){
        m+=temp[i];
    }
    m=(round(m/6)*10)/10;
    return "�������������� �����������: \n �� ������ ������ - "+cut(to_string((round(m/6)*10)/10))+"\n�� ������ ���������� - "+cut(to_string(32+9*((round(m/6)*10)/10)/5));
}

string calc_num(int a){
    if(a<0){
        return "����� ����� 0";
    }
    if(a>65535){
        return "����� ����� 65535";
    }
    string bin_res, res;
    do{
        bin_res= char('0'+ (a%2)) + bin_res;
        a=a/2;
    }while(a>0);
    if(bin_res[bin_res.length()-1]=='0'){
        return "ʳ������ ���� = "+cut(to_string(count_sym(bin_res, '0')));
    }else{
        return "ʳ������ ������� = "+cut(to_string(count_sym(bin_res, '1')));
    }
}












