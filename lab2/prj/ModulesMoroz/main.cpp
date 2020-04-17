#include <string>
#include <iostream>
#include <math.h>

using namespace std;

// змінна для виведення результату або помилок
// спільна для двох функцій
static string message;

static string check_l(string a){
    if(a.find(',') != 0){
        while(a.find(',') != 0){
            a[a.find(',')] = '.';
        }
    };
    if(a.find('.')!=a.rfind('.')){
        exit;
    }
    return a;
}

static void showmess(bool rx, bool ry, bool rz){
    message="Введено неправильн";
    if(rx==0){
        if(ry==0 || rz==0){
            message+="і значення для x";
            if(ry==0){
            message+=", y";
            }
            if(rz==0){
                message+=", z";
            }
        }else{
            message+="е значення для x";
        }
        message+="!";
    }else if(ry==0){
        if(rz==0){
            message+="і значення для y, z";
        }else{
            message+="е значення для y";
        }
        message+="!";
    }else{
        message+="е значення для z!";
    }
    cout<<message<<endl;
    exit;
}

static void q_calculation(string x1, string y1, string z1){
    bool rx = 1, ry = 1, rz = 1;

//перевірка формата введених значень
    try{
        check_l(x1);
    }catch(exception e){
        rx=0;
    }
    try{
        check_l(y1);
    }catch(exception e){
        ry=0;
    }
    try{
        check_l(z1);
    }catch(exception e){
        rz=0;
    }
    showmess(rx, ry, rz);

//перевірка можливості перевести значення рядкових змінних у числові
    float x, y, z;
    try{
        x=stof(x1);
    }catch(exception e){
        rx=0;
    }
    try{
        y=stof(y1);
    }catch(exception e){
        ry=0;
    }
    try{
        z=stof(z1);
    }catch(exception e){
        rz=0;
    }
    showmess(rx, ry, rz);
    ry=1;
    rz=1;
// валідатор
    //x
    if( ( x < 0 ) || ( ( z = 0 ) && (x!=floor(x)) ) ){
        rx = 0;
    }
    showmess(rx, ry, rz);

// обчислення
    cout<<"Q = "<<abs( sin( abs( y - pow(z, x) ) ) + sqrt(x) - sqrt( 0.5 * pow( y*z, 4 ) + 2 * M_PI) )<<endl;
}

static void s_calculation(string x1, string y1, string z1){
    bool rx = 1, ry = 1, rz = 1;

//перевірка формата введених значень
    try{
        check_l(x1);
    }catch(exception e){
        rx=0;
    }
    try{
        check_l(y1);
    }catch(exception e){
        ry=0;
    }
    try{
        check_l(z1);
    }catch(exception e){
        rz=0;
    }
    showmess(rx, ry, rz);

//перевірка можливості перевести значення рядкових змінних у числові
    float x, y, z;
    try{
        x=stof(x1);
    }catch(exception e){
        rx=0;
    }
    try{
        y=stof(y1);
    }catch(exception e){
        ry=0;
    }
    try{
        z=stof(z1);
    }catch(exception e){
        rz=0;
    }
    showmess(rx, ry, rz);
    ry=1;
    rz=1;
// валідатор
    //x
    if( x < ( (-7) * M_PI )) {
        rx = 0;
    }
    showmess(rx, ry, rz);

    //система рівностей
    if( (( pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) ) ) <0)||( pow(M_E, abs(x)) < ( sqrt( abs( y-z ) ) )/( sin(z*y) ) )){
        cout<<"Значення змінних не задовольняє вираз!"<<endl;
    }

// обчислення
    cout<<"S = "<< 0.5*((y*y+2*z)/(sqrt(7*M_PI+x)))-sqrt(pow(M_E, abs(x)) + ( sqrt( abs( y-z ) ) )/( sin(z*y) ))<<endl;
}

