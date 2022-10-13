#include <sensors.c>
#include <math.h>
#include <stdlib.h>
#include "esp_system.h"
#include "esp_mac.h"
#include "esp_log.h"

//Genera el header de un mensaje, con la MAC, el protocolo, status, y el largo del mensaje.
char* header(char protocol, char transportLayer){
	char* head = malloc(12);

    char * ID = "D1"; // WARNING
    memcpy((void*) &(head[0]), (void*) ID, 2);
	uint8_t* MACaddrs = malloc(6);
	esp_efuse_mac_get_default(MACaddrs);
	memcpy((void*) &(head[2]), (void*) MACaddrs, 6);
    head[8]= transportLayer;
	head[9]= protocol;
	unsigned short dataLen = dataLength(protocol);
	memcpy((void*) &(head[10]), (void*) &dataLen, 2);
	free(MACaddrs);
	return head;
}

unsigned short lengmsg[6] = {6, 16, 20, 44, 24016};

//Entrega el largo de la data según el protocolo
unsigned short dataLength(char protocol){
    return lengmsg[ (unsigned int) protocol]-1;
}

unsigned short messageLength(char protocol){
    return 1+12+dataLength(protocol);
}


char* mensaje (char protocol, char transportLayer){
	char* mnsj = malloc(messageLength(protocol));
	mnsj[messageLength(protocol)-1]= '\0';
	char* hdr = header(protocol, transportLayer);
	char* data;
	switch (protocol) {
		case -1:
			data = dataprotocol00();
			break;
		case 0:
			data = dataprotocol0();
			break;
		case 1:
			data = dataprotocol1();
			break;
		case 2:
			data = dataprotocol2();
			break;
        case 3:
			data = dataprotocol3();
			break;
        case 4:
			data = dataprotocol4();
			break;
		default:
			data = dataprotocol0();
			break;
	}
	memcpy((void*) mnsj, (void*) hdr, 12);
	memcpy((void*) &(mnsj[12]), (void*) data, dataLength(protocol));
	free(hdr);
	free(data);
	return mnsj;
}

// Arma un paquete para el protocolo de inicio, que busca solo respuesta
char* dataprotocol00(){
    char* msg = malloc(dataLength(0));
    msg[0] = 1;
    return msg;
}

// Arma un paquete para el protocolo 0, con la bateria
char* dataprotocol0(){
    
    char* msg = malloc(dataLength(0));
    char batt = batt_sensor();
    
	msg[0] = '1'; // Val
	msg[1] = batt;
	
    long t = 0;
    memcpy((void*) &(msg[2]), (void*) &t, 4);
    return msg;
}


char* dataprotocol1(){
    
    char* msg = malloc(dataLength(1));

    char batt = batt_sensor();
    msg[0] = '1'; // Val
    msg[1] = batt;
    
    int t = 0;
    memcpy((void*) &(msg[2]), (void*) &t, 4);
    
    char temp = thcp_temp_sensor();
    msg[6] = temp;

    float press = thcp_pres_sensor();
    memcpy((void*) &(msg[7]), (void*) &press, 4);
    
    char hum = thcp_hum_sensor();
    msg[11] = hum;

    char co = thcp_CO_sensor();
    memcpy((void*) &(msg[12]), (void*) &co, 4);

    return msg;
}

char* dataprotocol2(){
    
    char* msg = malloc(dataLength(2));

    char batt = batt_sensor();
    msg[0] = '1'; // Val
    msg[1] = batt;
    
    int t = 0;
    memcpy((void*) &(msg[2]), (void*) &t, 4);
    
    char temp = thcp_temp_sensor();
    msg[6] = temp;

    float press = thcp_pres_sensor();
    memcpy((void*) &(msg[7]), (void*) &press, 4);
    
    char hum = thcp_hum_sensor();
    msg[11] = hum;

    char co = thcp_CO_sensor();
    memcpy((void*) &(msg[12]), (void*) &co, 4);

    char rms = rms();
    memcpy((void*) &(msg[16]), (void*) &rms, 4);

    return msg;
}

char* dataprotocol3() {
       
    char* msg = malloc(dataLength(3));

    char batt = batt_sensor();
    msg[0] = '1'; // Val
    msg[1] = batt;
    
    int t = 0;
    memcpy((void*) &(msg[2]), (void*) &t, 4);
    
    char temp = thcp_temp_sensor();
    msg[6] = temp;

    float press = thcp_pres_sensor();
    memcpy((void*) &(msg[7]), (void*) &press, 4);
    
    char hum = thcp_hum_sensor();
    msg[11] = hum;

    char co = thcp_CO_sensor();
    memcpy((void*) &(msg[12]), (void*) &co, 4);

    char rms = rms();
    memcpy((void*) &(msg[16]), (void*) &rms, 4);

    float ampx = accelerometer_kpi_amp_x();
    memcpy((void*) &(msg[20]), (void*) &ampx, 4);

    float frecx = accelerometer_kpi_frec_x();
    memcpy((void*) &(msg[24]), (void*) &frecx, 4);

    float ampy = ampaccelerometer_kpi_amp_y();
    memcpy((void*) &(msg[28]), (void*) &ampy, 4);

    float frecy = accelerometer_kpi_frec_y();
    memcpy((void*) &(msg[32]), (void*) &frecy, 4);

    float ampz = accelerometer_kpi_amp_z();
    memcpy((void*) &(msg[36]), (void*) &ampz, 4);

    float frecz =accelerometer_kpi_frec_z();
    memcpy((void*) &(msg[40]), (void*) &frecz, 4);

    return msg; 
    
}
char * dataprotocol4(){
           
    char* msg = malloc(dataLength(3));

    char batt = batt_sensor();
    msg[0] = '1'; // Val
    msg[1] = batt;
    
    int t = 0;
    memcpy((void*) &(msg[2]), (void*) &t, 4);
    
    char temp = thcp_temp_sensor();
    msg[6] = temp;

    float press = thcp_pres_sensor();
    memcpy((void*) &(msg[7]), (void*) &press, 4);
    
    char hum = thcp_hum_sensor();
    msg[11] = hum;

    char co = thcp_CO_sensor();
    memcpy((void*) &(msg[12]), (void*) &co, 4);

    float * accx = acceloremeter_sensor_x();
    memcpy((void*) &(msg[6412]), (void*) &accx, 6400);

    float * accy = acceloremeter_sensor_y();
    memcpy((void*) &(msg[12812]), (void*) &accy, 6400);

    float * accz = acceloremeter_sensor_z();
    memcpy((void*) &(msg[19212]), (void*) &accz, 6400);

}