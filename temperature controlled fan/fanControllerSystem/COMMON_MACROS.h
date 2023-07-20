/***************************************************
 * File Name: common_macros.h
 *
 * Description: Commonly used Macros
 *
 * Module: Common - Macros
 *
 * Created on: Jun 13, 2023
 *
 * Author: Ahmed Dwidar
 ****************************************************/


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT)    (REG |= (1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT)  (REG &= (~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG ^= (1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR (REG,num)  ((REG>>num) | (REG <<(8 - num)))

/* Rotate left the register value with specific number of rotates */
#define ROL (REG,num)  ((REG<<num) | (REG >>(8 - num)))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) (REG & (1<<BIT))

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

/* get the value of a bit (1 or 0) */
#define GET_BIT(REG,BIT) (( REG & (1<<BIT) ) >> BIT )

#endif /* COMMON_MACROS_H_ */
