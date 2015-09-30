#include "common.h"

typedef int ElemType;
typedef ElemType *realimag;

Status AssignComplex(realimag &Z, ElemType v1,ElemType v2);
Status PrintComplex(realimag Z);
Status GetReal(realimag Z, ElemType &RealPart);
Status GetImag(realimag Z, ElemType &ImagPart);
Status AddComplex(realimag Z1, realimag Z2, realimag &Sum);
Status SubComplex(realimag Z1, realimag Z2, realimag &Sub);
Status MulComplex(realimag Z1, realimag Z2,realimag &Mul);