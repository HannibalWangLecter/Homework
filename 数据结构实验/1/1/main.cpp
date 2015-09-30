#include <stdio.h>

int main(void) 
{
            int Sum, X;   
          char operator='+'; 
    scanf("%d%c", &Sum, &operator);     
    /* 输入第一个操作数以及操作符；由于输入无空格，故无需特别处理 */    
 while(operator != '=') { 
        scanf("%d", &X);    
    /* 输入下一个操作数 */         switch(operator) { 
            case '+':            /* 根据操作符进行相应运算 */                 Sum += X;                 break;          
   case '-': 
                Sum -= X;                 break;            
 case '*': 
                Sum *= X;                 break;           
  case '/': 
                if ( X==0 ) { 
                    printf("Divided by zero!\n");                     return 0;                 } 
                Sum /= X;                 break;            
 default: 
                printf("Illegal!\n");                 return 0;         } 
        scanf("%c", &operator);        /* 输入下一个操作符 */     } 
    printf("%d\n", Sum);        /* 打印输出 */  
}
  

