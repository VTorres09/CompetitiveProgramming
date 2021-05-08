#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double converter(string x){
    int hh, mm, ss;
    if (sscanf(x.c_str(), "%d:%d:%d", &hh, &mm, &ss) >= 2)
    {
        return (hh *3600 + mm*60 + ss);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string hora, horas;
    double hour = 0, distancia = 0, ulth =0, ultv = 0;
    string delimiter = " ";
    double velocidade;

    while(getline(cin, hora)){
        if(hora.length() > 8) {
            horas = hora.substr(0, hora.find(delimiter));
            velocidade = stold(hora.substr(hora.find(delimiter), hora.length()));

            hour = converter(horas) / 3600;
            if (ulth != 0) {
            distancia += (hour - ulth) * ultv;
            }
            ulth = hour;
            ultv = velocidade;
        } else {
            cout<<setprecision(2)<<fixed;
            hour = converter(hora) / 3600;
            distancia += (hour-ulth) * ultv;
            ulth = hour;
            cout<< hora << " " << distancia << " km" <<endl;
        }
    }

    return 0;
}