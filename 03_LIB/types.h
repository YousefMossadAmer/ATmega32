/*  types.h
    created on: 19oct,2023
    author: yousef mosaad
*/

#ifndef TYPES_H_
#define TYPES_H_
#include <stdint.h>


typedef  unsigned char                  uint8_t;
typedef  char                           int8_t;
typedef  unsigned short int             uint16_t;
typedef  short int                      int16_t;
typedef  unsigned long int              uint32_t;   
typedef  long int                       int32_t;
typedef  unsigned long long int         uint64_t;
typedef  long long int                  int64_t;
typedef  float                          float32_t;
typedef  double                         float64_t;


typedef volatile uint8_t                vuint8_t;
typedef volatile  int8_t                vint8_t;
typedef volatile uint16_t               vuint16_t;
typedef volatile  int16_t               vint16_t;
typedef volatile   uint32_t             vuint32_t;   
typedef volatile int32_t                vint32_t;
typedef volatile uint64_t               vuint64_t;
typedef volatile int64_t                vint64_t;
typedef volatile float32_t              vfloat32_t;
typedef volatile float64_t              vfloat64_t;
#endif
