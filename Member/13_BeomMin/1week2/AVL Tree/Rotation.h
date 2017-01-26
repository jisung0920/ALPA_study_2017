#include "AVL.h"

#define Rotate_RR(x) \
	entry* y = L(x); \
	L(x) = R(y); \
	R(y) = x; \

#define Rotate_LL(x) \
	entry* y = R(x);\
	R(x) = L(y);\
	L(y) = x; \

#define Rotate_LR(x) \
	entry* y = L(x);\
	L(y) = R(y);\
	R(y) = NULL;\
	Rotate_RR(x)\

#define Rotate_RL(x) \
	entry* y = R(x);\
	R(y) = L(y);\
	L(y) = NULL;\
	Rotate_LL(x);\
