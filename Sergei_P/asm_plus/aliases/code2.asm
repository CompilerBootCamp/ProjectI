alias operatorPlusIntFloat

operatorPlusIntFloat:
	cvtsi2ss xmm1, edi
	addss xmm0, xmm1
	ret
