 /* Trilet.h 采用动态分配的顺序存储结构 */
typedef int ElemType; /* 定义抽象数据类型ElemType在本程序中为整型 */ 
typedef ElemType *Triplet; /* 定义三元组类型Triplet类型，是ElemType类型的指针，存放ElemType类型的地址 */
 
 /* 三元组抽象数据类型基本操作的函数声明 */
Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3);
Status DestroyTriplet(Triplet &T);
Status Get(Triplet T,int i, ElemType &e);
Status Put(Triplet T,int i,ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T,ElemType &e);
Status Min(Triplet T,ElemType &e);
