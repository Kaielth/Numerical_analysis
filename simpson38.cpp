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
//Método de Simpson 3/8
double simpson38(double a, double b, double s){
       //Resultado
       double resultado = 0.0;
       //Salto
       double j = (b - a) / s;
       for(int i = 0; i < s; i++){
           //Intervalos
           double ai = a + j * i;
           double bi = ai + j;
           //Separación
           double x = (bi - ai)/3;
           //Valores
           double x0 = ai;
           double x1 = ai + x;
           double x2 = bi - x;
           double x3 = bi;
           //F de x
           double fx0 = eq(x0);
           double fx1 = eq(x1);
           double fx2 = eq(x2);
           double fx3 = eq(x3);
           //Guardamos lo que va del resultado
           resultado += 3 * hx(ai,bi,3) * (fx0 + 3*fx1 + 3*fx2 + fx3) / 8;
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
    result = simpson38(a,b,s);
    //Resultado
    printf("Resultado: %f \n",result);
    system("pause");
    return 0;
}