#include <math.h>
#include <iostream>
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
    if(abs(v)>1E16){
        mess="������� �������� �� ������� � ������� -1�16 .. +1�16!";
        cout<<mess<<endl;
    }
    return v;
}

double q_calculation(double x, double y, double z){
    readv(x);
    readv(y);
    readv(z);
    if(checkx1(x,z)==false){
       cout<<mess;
        exit;
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
            cout<<(mess=="������� �������� �� ������� � ������� -1�16 .. +1�16!")<<endl<<endl;
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
    readv(y);
    readv(z);
    if(checkx2(x)==false){
        cout<<mess;
        exit;
    }
    if(checkval(x,y,z)==false){
        cout<<mess;
        exit;
    }
    return round((0.5*((y*y+2*z)/(sqrt(7*M_PI+x)))-sqrt(pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) )))*100)/100.0;
}

void test_task2_2(){
    double ts[4]={5961, 98492649485661515864.0 , -53868638465435485648.0 , -14159};//значення для тестування першої функції
    cout<<endl<<endl<<"�������� ����� �������"<<endl<<endl;
    for(short i=0; i<4; i++){
        cout<<i+1<<"  x = "<<ts[i]<<"   "<<readv(ts[i])<<"   ";//<<mess<<"  ";
        if(i==0 ||  i==3)
            cout<<(mess=="����� ������� ��������!")<<endl<<endl;
        else
            cout<<(mess=="������� �������� �� ������� � ������� -1�16 .. +1�16!")<<endl<<endl;
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
