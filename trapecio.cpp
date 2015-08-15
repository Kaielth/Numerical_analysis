#include<stdio.h>
#include<math.h>
#include<conio.h>

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
	 //Sumatoria 2F
     double sumatoria = 0.0;
     //Salto
     double j = (b - a) / s;
	 //Calculo repetitivo por segmentos
	 for(float i = a+j; i <= b-j; i+=j){
	     sumatoria += 2 * (5*pow(i,3) - 8*pow(i,2) + 2*(i)-7);
	 }
	 //Calculamos con la formula del trapecio
	 result = (b - a) * ( (5*pow(a,3) - 8*pow(a,2) + 2*(a)-7) + sumatoria + (5*pow(b,3) - 8*pow(b,2) + 2*(b)-7) ) / ( 2 * s);
	 //Resultado
	 printf("Resultado: %f \n",result);
	 getch();
}