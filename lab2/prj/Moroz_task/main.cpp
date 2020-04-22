#include <iostream>,
#include <iomanip>
#include <windows.h>
#include <string>
#include <math.h>
#include "ModulesMoroz.h"
using namespace std;

string writedev(){
    string k ="јнтон ћороз";
    k+=char(169);
    return k;
}

bool writebool(char a,char b){
    return (a+5>b+2);
}

string cut(string v){
    while((v.rfind('.')<v.rfind('0') && v[v.size()-1]=='0') || v[v.size()-1]=='.')
        v.erase(v.size()-1, 1);
    return v;
}

string to_hex(double ch){
    stringstream ss;
    string s, v;
    if(ch<0){
        ch*=(-1);
        v="-";
    }
    int i=floor(ch);
    ss<<hex<<i;
    ss>>s;
    v+=s;
    string k;
    if(ch==floor(ch)){
        return v;
    }else{
        k=cut(to_string(ch-floor(ch)));
    }
    v+='.';
    for(short m=0;m<2; m++){
        ss.clear();
        i=floor(stod(k)*16);
        k=to_string(stod(k)*16-i);
        ss<<hex<<i;
        ss>>s;
        v+=s;
    }
    return v;
}

string write_dec(double x, double y, double z){
    string k = "Dec: ";
    k+="x="+cut(to_string(x))+" y="+cut(to_string(y))+" z="+cut(to_string(z));
    return k;
}



string write_hex(double x, double y, double z){
    string k = "Hex: ";
    k+="x="+cut(to_hex(x))+" y="+cut(to_hex(y))+" z="+cut(to_hex(z));
    return k;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x,y,z;
    char a,b;
    cout<<"¬вед≥ть x: ";
    cin>>x;
    cout<<"¬вед≥ть y: ";
    cin>>y;
    cout<<"¬вед≥ть z: ";
    cin>>z;
    cout<<"¬вед≥ть першу л≥теру: ";
    cin>>a;
    cout<<"Enter другу л≥теру: ";
    cin>>b;
    x=round(x*100)/100.0;
    y=round(y*100)/100.0;
    z=round(z*100)/100.0;
    if(abs(x)>100 || abs(y)>100 || abs(z)>100){
        cout<<"¬ведене значенн€ не входить в д≥апазон -100 .. +100!";
        return 0;
    }
    cout<<writedev()<<endl;
    cout<<boolalpha<<writebool(a, b)<<endl;
    cout<<endl<<write_dec(x, y, z)<<endl;
    cout<<write_hex(x,y,z)<<endl;
    cout<<endl<<fixed<<setprecision(2)<<"Q = "<<q_calculation(x, y, z)<<endl;
    cout<<fixed<<setprecision(2)<<"S = "<<s_calculation(x, y, z)<<endl;
    return 0;
}
