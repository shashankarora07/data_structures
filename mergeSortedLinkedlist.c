#include<stdio.h>
#include<stdlib.h>
#include "singly_linkedlist.h"




int main()
{
    Node *a = NULL;
    Node *b = NULL;
    int dataA = 0;
    int dataB = 1;
    for (int i = 1; i < 6; i++) {
		dataA = dataA + 2;
        if (i == 1)
            Insert_linkedlist(&a,dataA,1);
        else
            Insert_linkedlist(&a,dataA,2);
    }

    Display_linkedlist(a);
    
	for (int i = 1; i <= 7; i++) {
		dataB = dataB + 2;
        if (i == 1)
            Insert_linkedlist(&b,dataB,1);
        else
            Insert_linkedlist(&b,dataB,2);
    }

    Display_linkedlist(b);

    return 0;
}

