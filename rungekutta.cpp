#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 



float rungek4(float x_i, float t_i, float (*F)(float , float)){ 
    
    float dt = 0.01;    
    float k1 = dt*F(t_i, x_i);    
    float k2 = dt*F(t_i+dt/2 , x_i+k1/2);
    float k3 = dt*F(t_i+dt/2, x_i+k2/2 );
    float k4 = dt*F(t_i+dt/2 , x_i+k3);    
    
    float y = x_i + 1.0/6.0*(k1 + 2*k2 + 2*k3 + k4);
    
    return y;
    
    
}

float funcion (float t, float x ){
    float f = sin(t) - x;
    return f;
}
    
int main(){
    
    float dt = 0.01;
    float xnow = 1.0;  
    float xnew = 1.0;  
    float t = 0.0;
    
    while (t<20){
        xnew = rungek4(xnow, t, funcion);
        t += dt;
        cout<<t<<"\t"<<xnew<<endl;
        xnow = xnew;
       }       
    
       
          
    
    
    return 0;
}