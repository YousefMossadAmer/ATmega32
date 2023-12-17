/*  ssd_program.h
    created on: 4NOV,2023
    author: yousef mosaad
*/
#include "types.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SSD_config.h"
#include "SSD_private.h"
#include "SSD_interface.h"

static uint8_t local_u8_ssdnumbers[10] = SSD_NUMBER_ARR;

void SSD_voidinitdataport (ssd_type ssd_configration)
{
    GPIO_enumset_PORT_DIRECTION(ssd_configration.data_port ,0xff);
}

void SSD_voidsendnumber (ssd_type ssd_configration ,uint8_t number)
{
    if(ssd_configration.type == SSD_COMMON_CATHODE)
    {
        GPIO_enumset_PORTVALUE(ssd_configration.data_port ,local_u8_ssdnumbers[number]);
    }
    else if (ssd_configration.type == SSD_COMMON_ANODE)
    {
        GPIO_enumset_PORTVALUE(ssd_configration.data_port ,~(local_u8_ssdnumbers[number]));
    }
}


void SSD_voidenabel (ssd_type ssd_configration )
{
    if(ssd_configration.type == SSD_COMMON_CATHODE)
    {
        GPIO_enumset_PIN_DIRECTION(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_OUTPT);
        GPIO_enumset_PINVALUE(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_LOW);//LOW!!!!!!

    }
    else if (ssd_configration.type == SSD_COMMON_ANODE)
    {

        GPIO_enumset_PIN_DIRECTION(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_INPUT);
        GPIO_enumset_PINVALUE(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_HIGH);//HIGH!!!!!!
    }
}


void SSD_voiddisabel (ssd_type ssd_configration )
{
    if(ssd_configration.type == SSD_COMMON_CATHODE)
    {
        GPIO_enumset_PIN_DIRECTION(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_OUTPT);
        GPIO_enumset_PINVALUE(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_HIGH);//high!!!!!!

    }
    else if (ssd_configration.type == SSD_COMMON_ANODE)
    {

        GPIO_enumset_PIN_DIRECTION(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_INPUT);
        GPIO_enumset_PINVALUE(ssd_configration.enable_port ,ssd_configration.enable_pin,GPIO_PTN_LOW);//low!!!!!!
    }
}