/* TriletTestApp.c是测试三元组类型定义和基本操作的应用程序 */
#include"Common.h" 
#include"Trilet.h" 

void main()
{
	Triplet T;
	ElemType m;
	Status i;
	
	i=InitTriplet(T,5,7,9); 
	printf("调用初始化函数后，i=%d(1:成功) T的三个值为：%d %d %d\n",i,T[0],T[1],T[2]); /* 当ElemType的类型变化时，要相应改变printf()的格式符。 */
	
	i=Get(T,2,m);
	if(i==OK)
		printf("T的第2个值为：%d\n",m);
	
	i=Put(T,2,6);
	if(i==OK)
		printf("将T的第2个值改为6后，T的三个值为：%d %d %d\n",T[0],T[1],T[2]);
	
	i=IsAscending(T); /* 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变 */
	printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
	
	i=IsDescending(T);
	printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
	
	if((i=Max(T,m))==OK) /* 先赋值再比较 */
		printf("T中的最大值为：%d\n",m);
	
	if((i=Min(T,m))==OK)
		printf("T中的最小值为：%d\n",m);
	
	DestroyTriplet(T); /* 函数也可以不带回返回值 */
	printf("销毁T后，T=%u(NULL)\n",T);
	
 }