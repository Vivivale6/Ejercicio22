#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

void inic(double *u_viejo, double min, double delta_x, int xn,double sig, double med);
void imprime(double x, double delta_x, int xn, double *u_nuevo, double min);

double gauss(double x,double med, double sig);


double gauss(double x,double med, double sig){
  return exp(-(x-med)*(x-med)/sig*2.0);

}
void inic(double *u_viejo, double min, double delta_x, int xn,double sig, double med){
  double x;
  int i;
  for (i =0; i<xn; i++){
    x= min + i * delta_x;
    u_viejo[i]= gauss(x,med,sig);
      
    } 
  
    
}

void imprime(double x, double delta_x, int xn, double *u_nuevo, double min){
  int i ; 
  for (i=0; i < xn ; i++){
    
   x= min + i*delta_x;
   
   
    cout << x <<" " << u_nuevo[i]<< endl;

 } 



}

int main(){

  double d=1.0;
  double t=0.5;
  double delta_x=0.02;
  double delta_t=0.001;
  double med = 1;
  double sig = 0.1; 
  double *u_viejo;
  double *u_nuevo;
  double min = 0.0 , max = 2.0 ;
  double x=0;
  int xn = ((max-min)/delta_x) +1;
  int tn = (t/delta_t) +1;  
 
  int i ;
  int j; 

  u_viejo= new double[xn];
  u_nuevo= new double[xn];

  

  inic(u_viejo,min,delta_x,xn, med, sig);
 

 
  for(j=0; j<tn ; j++) {
   
    u_nuevo[0]=0;
   
   
    for (i=1; i< xn ; i++){
     
      u_nuevo[i]= u_viejo[i] - d*delta_t/(delta_x*delta_x)*(u_viejo[i+1]-2*u_viejo[i]+ u_viejo[i-1]);
     }
   
    for(i=0; i < xn ; i++){

	    u_viejo[i]= u_nuevo[i];

	  }
       
 }
   

  imprime(x,delta_x,xn,u_nuevo, min );
 
 
 
    
 return 0; 
}
