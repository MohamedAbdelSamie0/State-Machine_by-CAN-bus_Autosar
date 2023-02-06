/*
 * BitMath.h
 *
 * Created: 12/17/2022
*/ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define	SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &= ~(1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo) & 1)

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

//if bit is set return true
#define BIT_IS_SET(Reg,BitNo) (Reg & (1<<BitNo))
//if bit is clear return true
#define BIT_IS_CLEAR(Reg, BitNo) ( !(Reg & (1<<BitNo)) )

#endif /* BITMATH_H_ */