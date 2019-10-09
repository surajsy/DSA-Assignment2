#include<stdio.h>
#include "largeintpoly.h"

void main(){
	Node *result;
	Poly *poly1, *poly2, *q, *r;
	int digit,i;
	char c;
	
	printf("Large number expression evaluation:\n");
	printf("Input expression:\n");
	result = evalLarge();
	printNum(result);
	clearList(&result);
	
	poly1 = NULL;
	poly2 = NULL;
	
	printf("Polynomial divison: Input two polynomials\n");
	readPoly(&poly1);
	readPoly(&poly2);
	
	printf("A=");
	printPoly(poly1);
	printf("B=");
	printPoly(poly2);
	
	printf("Performing A/B:\n");
	r = divPoly(poly1,poly2,&q);
	
	printf("Quotient:");
	printPoly(q);
	printf("Remainder:");
	printPoly(r);
	
	delPoly(&poly1);
	delPoly(&poly2);
	delPoly(&q);
	delPoly(&r);
	
}