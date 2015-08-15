#include <iostream>
#include <math.h>

using namespace std;

//Ecuación - e^m/( e^m-1)
double eq(double x){
       return exp(x)/(exp(x)-1);
}
//Altura
double hx(double a, double b, double n){
       return (b - a) / n;
}
//Método de Simpson 1/3
double simpson13m(double a, double b, double s){
       //Resultado
       double resultado = 0.0;
       //Salto
       double j = (b - a) / s;
       //Calculo repetitivo por segmentos
       for i in(int i = 0; i < s; i++){
           //Intervalos
           double ai = a + j * i;
           double bi = ai + j;
           //Altura
           double h = hx(ai,bi,1);
           //F de x
           double fxi = eq(ai);
           double fxm = eq((ai+bi)/2);
           double fxf = eq(bi);
           //Guardamos el resultado
           resultado += h * (fxi + 4*fxm +fxf) / 6;
       }
       //Regresamos resultado
       return resultado;
}

int main(){
    //Variables iniciales
    float a;//Punto inicial
    float b;//Punto final
    int s;//Número de segmentos
    double result;//Resultado
    //Capturamos valores
    printf("Punto inicial A:");
    scanf("%f",&a);
    printf("Punto final B:");
    scanf("%f",&b);
    do{
        printf("Canditad de segmentos:");
        scanf("%d",&s);
    }while(s % 2 != 0);
    //Calculamos
    result = simpson13m(a,b,s);
    //Resultado
    printf("Resultado: %f \n",result);
    system("pause");
    return 0;
}