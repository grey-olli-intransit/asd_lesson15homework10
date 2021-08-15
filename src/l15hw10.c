#include <stdio.h>
#include <string.h>
#include "print_1d_array.h"

// Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.


// принимает на вход '\0'-terminated string
// на выходе сумма кодов символов,
// коллизии никак не обрабатываются.
unsigned long int strToULongIntHash(char * str) {
    unsigned long int result=0;
    const size_t len=strlen(str);
    if (len==0)
        return 0;
    size_t i=0;
    while(i < len) {
     result+=(unsigned char)str[i];
     ++i;
    }
    return result;
}

// Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.
//
int cs[5]={50,10,5,2,1}; // coins sorted
int cn[5]={};            // coins needed

void get_98() {
    int summ_required=98;
    int summ=0;
    int j=0;
    for(int formula_index=0;formula_index<5;++formula_index) {
      int coin_index=formula_index;
      for(int i=1;i<=8;++i) {
	      switch(formula_index) {
	       case 0:
	          summ=cs[0]*i;
              j=0;
		      break;
	       case 1:
	          summ=cs[0]*cn[0]+cs[1]*i;
              j=1;
		      break;
	       case 2:
	          summ=cs[0]*cn[0]+cs[1]*cn[1]+cs[2]*i;
              j=2;
		      break;
	       case 3:
	          summ=cs[0]*cn[0]+cs[1]*cn[1]+cs[2]*cn[2]+cs[3]*i;
              j=3;
		      break;
	       case 4:
	          summ=cs[0]*cn[0]+cs[1]*cn[1]+cs[2]*cn[2]+cs[3]*cn[3]+cs[4]*i;
              j=4;
		      break;
          }
          if (summ > summ_required)
            continue;
	      cn[j]=i;
          //printf("i: %i, j: %i, summ: %i, cn[%i]=%i\n",i,j,summ,j,cn[j]);
          if ((summ_required - summ) > 0 && (summ_required - summ) % cs[coin_index] ==0) {
            cn[j] = (summ_required - summ) / cs[coin_index];
            break;
          }
      } // for i
      summ=cs[0]*cn[0]+cs[1]*cn[1]+cs[2]*cn[2]+cs[3]*cn[3]+cs[4]*cn[4];
      if (summ == summ_required)
          break;
    } // for formula_index
	printf("coins present:\n");
    print_1d_array(5,cs);
	printf("related count needed to get %i summary:\n", summ_required);
    print_1d_array(5,cn);

}

int main(int argc, char ** argv) {
    char * str1=" ";
    char * str2="  ";
    char * str3="р"; //utf-8: 209128
    char * str4="qwerty";
    printf("Space:%lu\n",strToULongIntHash(str1));
    printf("Two spaces:%lu\n",strToULongIntHash(str2));
    printf("Russian utf-8 'p': %lu\n",strToULongIntHash(str3));
    printf("len of str w/ single 'р' char: %li\n",strlen(str3));
    printf("'qwerty': %lu\n",strToULongIntHash(str4));

    get_98();

    return 0;
}
