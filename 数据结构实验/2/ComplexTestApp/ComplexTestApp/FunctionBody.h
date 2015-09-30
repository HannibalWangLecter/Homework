#include "common.h"
#include "ComplexTestApp.h"

Status AssignComplex(realimag &Z, ElemType v1, ElemType v2)
{
	Z = (ElemType *)malloc(2*sizeof(ElemType));
	if (!Z)
		exit(OVERFLOW);
	Z[0] = v1; Z[1] = v2;
	return OK;
}
Status PrintComplex(realimag Z)
{
		printf("%d+%di", Z[0], Z[1]);
		return OK;
}
Status GetReal(realimag Z, ElemType &RealPart)
{
	RealPart = Z[0];
	return OK;
}
Status GetImag(realimag Z, ElemType &ImagPart)
{
	ImagPart = Z[1];
	return OK;
}
Status AddComplex(realimag Z1, realimag Z2, realimag &Sum)
{
	Sum = (ElemType *)malloc(2 * sizeof(ElemType));
	Sum[0]= Z1[0] + Z2[0];
    Sum[1]= Z1[1] + Z2[1];
	return OK;
}
Status SubComplex(realimag Z1, realimag Z2, realimag &Sub)
{
	Sub= (ElemType *)malloc(2 * sizeof(ElemType));
	Sub[0] = Z1[0] + Z2[1];
	Sub[1] = Z1[1] + Z2[1];
	return OK;
}
Status MulComplex(realimag Z1, realimag Z2, realimag &Mul)
{
	Mul= (ElemType *)malloc(2 * sizeof(ElemType));
	Mul[0] = (Z1[0] * Z2[0]) - (Z1[1] * Z2[1]);
    Mul[1] = (Z1[0] * Z2[1]) + (Z1[1] * Z2[0]);
	return OK;
}
