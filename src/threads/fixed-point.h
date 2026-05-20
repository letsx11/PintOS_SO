#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/* Define o tipo fixed_t como um inteiro de 32 bits */
typedef int fixed_t;

/* 14 bits para a parte fracionária (formato 17.14) */
#define FP_SHIFT 14
#define FP_F (1 << FP_SHIFT)

/* Conversões */
#define INT_TO_FP(n) ((n) * FP_F)
#define FP_TO_INT_TRUNC(x) ((x) / FP_F)
#define FP_TO_INT_ROUND(x) ((x) >= 0 ? ((x) + FP_F / 2) / FP_F : ((x) - FP_F / 2) / FP_F)

/* Operações aritméticas */
#define FP_ADD(x, y) ((x) + (y))
#define FP_SUB(x, y) ((x) - (y))
#define FP_ADD_INT(x, n) ((x) + INT_TO_FP(n))
#define FP_SUB_INT(x, n) ((x) - INT_TO_FP(n))

/* Multiplicação e Divisão (usando int64_t para evitar overflow temporário) */
#define FP_MUL(x, y) ((fixed_t)(((int64_t)(x)) * (y) / FP_F))
#define FP_DIV(x, y) ((fixed_t)(((int64_t)(x)) * FP_F / (y)))
#define FP_MUL_INT(x, n) ((x) * (n))
#define FP_DIV_INT(x, n) ((x) / (n))

#endif /* threads/fixed-point.h */