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
        cout<<"���������� ������� ������!"<<"  "<<(mess=="���������� ������� ������!");
    }


}



/*double s_calculation(double x, double y, double z){
// ÃÂ²ÃÂ°ÃÂ»Ã‘â€“ÃÂ´ÃÂ°Ã‘â€šÃÂ¾Ã‘â‚¬
    //x
    if( x < ( (-7) * M_PI )) {
        return "Ââåäåíî íåïðàâèëüíå çíà÷åííÿ äëÿ x!";
    }

    //Ã‘ÂÃÂ¸Ã‘ÂÃ‘â€šÃÂµÃÂ¼ÃÂ° Ã‘â‚¬Ã‘â€“ÃÂ²ÃÂ½ÃÂ¾Ã‘ÂÃ‘â€šÃÂµÃÂ¹
    if( (( pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) ) ) <0)||( pow(M_E, abs(x)) < ( sqrt( abs( y-z ) ) )/( sin(z*y) ) )){
        return "Çíà÷åííÿ çì³ííèõ íå çàäîâîëüíÿþòü âèðàç!";
    }

// ÃÂ¾ÃÂ±Ã‘â€¡ÃÂ¸Ã‘ÂÃÂ»ÃÂµÃÂ½ÃÂ½Ã‘Â
    return round((0.5*((y*y+2*z)/(sqrt(7*M_PI+x)))-sqrt(pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) )))*100)/100.0;
}*/
