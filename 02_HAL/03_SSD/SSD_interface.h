/*  ssd_interface.h
    created on: 4NOV,2023
    author: yousef mosaad
*/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_COMMON_CATHODE 0
#define SSD_COMMON_ANODE 1



typedef struct{
    uint8_t type;         //common cathd or comon anode 
    uint8_t data_port ;   //PORT A | B | C| D FOR DATA PINS
    uint8_t enable_port;  //PORT A | B | C | D FOR COMMON PORT 
    uint8_t enable_pin;   //PIN 01234567 FOR COMMON PIN
}ssd_type;


void SSD_voidinitdataport   (ssd_type ssd_configration);
void SSD_voidsendnumber     (ssd_type ssd_configration ,uint8_t number);
void SSD_voidenabel         (ssd_type ssd_configration );
void SSD_voiddisabel        (ssd_type ssd_configration );

#endif