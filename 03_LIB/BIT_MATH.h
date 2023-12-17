/*  BIT_MATH.h
	creatd on: 19oct,2023
	author: yousef mosaad

*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)    REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)    REG&=~((1<<BIT))
#define TOG_BIE(REG,BIT)    REG^=(1<<BIT)
#define GET_BIT(REG,BIT)    (REG&(1<<BIT))>>BIT
#endif  