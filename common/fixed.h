//
// Created by maxim on 1/9/21.
//

#ifndef FIXED_H
#define FIXED_H

#include <stdint.h>

#ifdef __GNUC__
#pragma interface "fixed.h"
#endif

typedef uint32_t fixed_t;

#define F(i, f) (((((uint32_t)(i)) << 16U)) | (((uint16_t)(f)) & 0xFFFFU))
#define I(fixed) ((uint16_t)((fixed_t)(fixed) >> 16U))
#define D(fixed) ((uint16_t)((fixed_t)(fixed) & 0xFFFFU))

#define FF_OP(n1, n2, op) ((n1) op (n2))
#define FI_OP(n1, n2, op) F((((fixed_t)n1 >> 16U) op (n2)), (fixed_t)n1 & 0xFFFFU)
#define IF_OP(n1, n2, op) F(((n1) op ((fixed_t)n2 >> 16U)), (fixed_t)n2 & 0xFFFFU)
#define II_OP(n1, n2, op) F((n1) op (n2), 0)

#define FF_ADD(n1, n2) FF_OP(n1, n2, +)
#define FI_ADD(n1, n2) FI_OP(n1, n2, +)
#define IF_ADD(n1, n2) IF_OP(n1, n2, +)
#define II_ADD(n1, n2) II_OP(n1, n2, +)

#define FF_SUB(n1, n2) FF_OP(n1, n2, -)
#define FI_SUB(n1, n2) FI_OP(n1, n2, -)
#define IF_SUB(n1, n2) IF_OP(n1, n2, -)
#define II_SUB(n1, n2) II_OP(n1, n2, -)

#define FF_MUL(n1, n2) FF_OP(n1, n2, *)
#define FI_MUL(n1, n2) FI_OP(n1, n2, *)
#define IF_MUL(n1, n2) IF_OP(n1, n2, *)
#define II_MUL(n1, n2) II_OP(n1, n2, *)

#define FF_DIV(n1, n2) FF_OP(n1, n2, /)
#define FI_DIV(n1, n2) FI_OP(n1, n2, /)
#define IF_DIV(n1, n2) IF_OP(n1, n2, /)
#define II_DIV(n1, n2) II_OP(n1, n2, /)

// #undef FF_OP
// #undef FI_OP
// #undef IF_OP
// #undef II_OP

#endif //FIXED_H
