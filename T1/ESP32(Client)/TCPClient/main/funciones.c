#include <stdlib.h>
#include <math.h>


//Simulación Sensores




// Acelerometro

float float_rand(float min,float max)
{
    return min + (float)rand()/(float)(RAND_MAX/(max-min));
}


float * acceloremeter_sensor_x(){
    
    float* arr = malloc(1600 * sizeof(float));
    for(int i = 0; i < 1600;i++){
        arr[i] = 2*sin(2*3.14*0.000*i);
    }
    return arr;    
}
float * acceloremeter_sensor_y(){
    float* arr = malloc(1600 * sizeof(float));
    for(int i = 0; i < 1600;i++){
        arr[i] = 2*cos(3*3.14*0.000*i);
    }    
    return arr;

}
float * acceloremeter_sensor_z(){
    float* arr = malloc(1600 * sizeof(float));
    for(int i = 0; i < 1600;i++){
        arr[i] = 2*sin(10*3.14*0.000*i);
    }   
    return arr; 
}

//THCP_Sensor



float thcp_temp_sensor(){
    return floatrand(5,30);
}

float thcp_hum_sensor(){
   return floatrand(30,80);
}

float thcp_pres_sensor(){
   return floatrand(1000,1200);
}

float thcp_CO_sensor(){
    return floatrand(30,200);
}

float batt_sensor() {
    return floatrand(1,100);
}


float accelerometer_kpi_amp_x() {
    return floatrand(0.0059,0.12);
}

float accelerometer_kpi_frec_x() {
    return floatrand(29.0,31.0);
}

float accelerometer_kpi_amp_y() {
    return floatrand(0.0041,0.12);
}

float accelerometer_kpi_frec_y() {
    return floatrand(59.0,61.0);
}

float accelerometer_kpi_amp_z() {
    return floatrand(0.008,0.15);
}

float accelerometer_kpi_frec_z() {
    return floatrand(89.0,91.0);
}


float rms(float a , float b, float c){
    float sq = pow(a,2)+ pow(b,2)+pow(c,2);
    return pow(sq,0.5); 
}







//Crear paquete






