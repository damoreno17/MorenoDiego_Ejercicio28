#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 



float x;
float y;
float v0_x = 10;
float v0_y = 10;
float t = 0.0;
float g = -9.8;
float k = 0.7;
float dt = 0.01;

float rungek4(float x_i, float z_i, float t_i, float (*F)(float , float, float)){ 
    
    float k1 = dt*F(t_i, x_i, z_i);    
    float k2 = dt*F(t_i+dt/2 , x_i+k1/2, z_i+k1/2);
    float k3 = dt*F(t_i+dt/2, x_i+k2/2, z_i+k2/2 );
    float k4 = dt*F(t_i+dt/2 , x_i+k3, z_i+k3);    
    
    float x = x_i + 1.0/6.0*(k1 + 2*k2 + 2*k3 + k4);
    
    
    return x;   
    
}
float f_x (float t, float x,float vx){    
    return vx;    
}

float f_vx (float t, float vx, float vy){
    
    float v = (-k*vx *(vx/(sqrt((vx*vx) + (vy*vy)))));    
    return  v;   
}

float f_y (float t,float y, float vy){    
    return vy;    
}

float f_vy (float t, float vy, float vx){
    
    float v = (g - (k*vy *(vy/(sqrt((vx*vx) + (vy*vy))))));    
    return  v;   
}

int main(){
    
float x;
float y;
float v0_x = 10;
float v0_y = 10;
float t = 0.0;
float g = -9.8;
float k = 0.7;
float dt = 0.01;
float (*F);
    
    while (t<3.0){
        
        cout << t  << "\t" << x << "\t" << y << "\t"<< v0_x  << "\t"<< v0_y  << "\t" <<endl;
        
        
        v0_y = rungek4( v0_y , v0_x , t, f_vy);
        v0_x = rungek4( v0_x , v0_y , t, f_vx);
    
        x = rungek4(x,v0_x , t, f_x);
        y = rungek4(y,v0_y , t, f_y);
        
        
        t+=dt;
    }
    
    
    return 0;
}