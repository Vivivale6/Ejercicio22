#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;




double gauss(double x,double med, double sig);


double gauss(double x1,double med, double sig){
   
  return exp(-pow((x1-1.0)/0.25,2)*0.5);

}



int main(){

  double d=1.0;
  double t=0.5;
  double *u;
  double delta_x=0.1;
  double delta_t=0.00001;
  
  double *u_viejo;
  double *u_nuevo;
  double min = 0.0 , max = 2.0 ;
  double x =0.0;
  double y;
  int xn = ((max-min)/delta_x) +1;
  int tn = xn* 0.5;  
 
  int i ;
  int j; 
  u = new double[xn];
  u_viejo= new double[xn];
  u_nuevo= new double[xn];
  

  
  for (i =0; i<xn; i++){
   
    
    u_viejo[i]= gauss(i * delta_x,0.0,0.1);
      
    }
 
  while(u_viejo[tn]> 0.5){
    u_nuevo[0]=0;
    u_viejo[xn-1]=0;

    for (i=0; i< xn ; i++){
     
      u_nuevo[i]= u_viejo[i] + d*delta_t/(delta_x*delta_x)*(u_viejo[i+1]-2*u_viejo[i]+ u_viejo[i-1]);
     }
   
    for(i=0; i < xn ; i++){

      u_viejo[i]= u_nuevo[i];

    }


  }
   for(i=0;i<xn;i++){

    cout << i * delta_x << " " << u_nuevo[i] << endl;
  }
 
    
 return 0; 
}