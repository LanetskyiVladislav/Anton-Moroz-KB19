#include <math.h>
#include <iostream>
using namespace std;

string mess;

bool checkx1(double x, double z){
    mess="Введено неправильне значення для x!";
    if(x<0)
        return false;
    if(z==0 && x!=floor(x))
        return false;
    mess="Значення x задовольняє вираз!";
    return true;
}

double readv(double v){
    mess="Число пройшло перевірку!";
    if(abs(v)>1E16){
        mess="Введене значення не входить в діапазон -1Е16 .. +1Е16!";
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
    double ts[6]={5, -10 , -1615951915651151962.0 , 5195126519321549565.0 , 4965.6 , -84.56};//Р·РЅР°С‡РµРЅРЅСЏ РґР»СЏ С‚РµСЃС‚СѓРІР°РЅРЅСЏ РїРµСЂС€РѕС— С„СѓРЅРєС†С–С—
    cout<<endl<<endl<<"Перевірка першої функції"<<endl<<endl;
    for(short i=0; i<6; i++){
        cout<<i+1<<"  x = "<<ts[i]<<"   "<<readv(ts[i])<<"   ";//<<mess<<"  ";
        if(i<2 ||  i>3)
            cout<<(mess=="Число пройшло перевірку!")<<endl<<endl;
        else
            cout<<(mess=="Введене значення не входить в діапазон -1Е16 .. +1Е16!")<<endl<<endl;
    }
    cout<<endl<<endl<<"Перевірка другої функції"<<endl<<endl;
    double ts2[3][2]={ {5 , 0}, {-7 , 9}, {8.4 , 0}};
    for(short i=0; i<3; i++){
        cout<<i+7<<"  x = "<<ts2[i][0]<<", z = "<<ts2[i][1]<<"   "<<checkx1(ts2[i][0], ts2[i][1])<<"   ";
        if(i==0)
            cout<<(mess=="Значення x задовольняє вираз!")<<endl<<endl;
        else
            cout<<(mess=="Введено неправильне значення для x!")<<endl<<endl;
    }
    cout<<endl<<endl<<"Перевірка третьої функції"<<endl<<endl;
    double x=2,y=5,z=10;
    cout<<12<<"  x = "<<x<<", y = "<<y<<", z = "<<z<<"   "<<q_calculation(x,y,z)<<"   ";
    if(q_calculation(x,y,z)==1765.67){
        mess="Обчислення пройшло успішно!";
        cout<<"Обчислення пройшло успішно!"<<"  "<<(mess=="Обчислення пройшло успішно!");
    }


}



/*double s_calculation(double x, double y, double z){
// ГѓВђГ‚ВІГѓВђГ‚В°ГѓВђГ‚В»ГѓвЂГўв‚¬вЂњГѓВђГ‚ВґГѓВђГ‚В°ГѓвЂГўв‚¬ЕЎГѓВђГ‚ВѕГѓвЂГўвЂљВ¬
    //x
    if( x < ( (-7) * M_PI )) {
        return "Г‚ГўГҐГ¤ГҐГ­Г® Г­ГҐГЇГ°Г ГўГЁГ«ГјГ­ГҐ Г§Г­Г Г·ГҐГ­Г­Гї Г¤Г«Гї x!";
    }

    //ГѓвЂГ‚ВЃГѓВђГ‚ВёГѓвЂГ‚ВЃГѓвЂГўв‚¬ЕЎГѓВђГ‚ВµГѓВђГ‚ВјГѓВђГ‚В° ГѓвЂГўвЂљВ¬ГѓвЂГўв‚¬вЂњГѓВђГ‚ВІГѓВђГ‚ВЅГѓВђГ‚ВѕГѓвЂГ‚ВЃГѓвЂГўв‚¬ЕЎГѓВђГ‚ВµГѓВђГ‚В№
    if( (( pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) ) ) <0)||( pow(M_E, abs(x)) < ( sqrt( abs( y-z ) ) )/( sin(z*y) ) )){
        return "Г‡Г­Г Г·ГҐГ­Г­Гї Г§Г¬ВіГ­Г­ГЁГµ Г­ГҐ Г§Г Г¤Г®ГўГ®Г«ГјГ­ГїГѕГІГј ГўГЁГ°Г Г§!";
    }

// ГѓВђГ‚ВѕГѓВђГ‚В±ГѓвЂГўв‚¬ВЎГѓВђГ‚ВёГѓвЂГ‚ВЃГѓВђГ‚В»ГѓВђГ‚ВµГѓВђГ‚ВЅГѓВђГ‚ВЅГѓвЂГ‚ВЏ
    return round((0.5*((y*y+2*z)/(sqrt(7*M_PI+x)))-sqrt(pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) )))*100)/100.0;
}*/
