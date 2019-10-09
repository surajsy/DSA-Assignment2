#include<stdio.h>
#include "largeintpoly.h"

void appendDigit(Node** header, int digit){
	Node* temp = *header;
	if(*header == NULL){
		*header = createNode();
		(*header)->digit = digit;
	}
	else {
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = createNode();
		temp->next->prev = temp;
		temp->next->digit = digit;
	}
}

void prependDigit(Node** header, int digit){
	Node *temp;
	temp = createNode();
	temp->digit = digit;
	
	if(*header == NULL)
		*header = temp;
	else{
		temp->next = *header;
		(*header)->prev = temp;
		*header = temp;
	}
//	printf("prepending\n");
}

void printNum(Node* header){
	Node *temp = header;
	
	if(temp == NULL){
		printf("$\n");
		return;
	}
//	printf("wow\n");
	while(temp->next!=NULL)
		temp = temp->next;
	
//	printf("wow\n");
	while(temp->prev!=NULL){
		printf("%04d,",temp->digit);
		temp = temp->prev;
	}
	
//	printf("wow\n");
	printf("%04d$\n",temp->digit);
//	printf("wow\n");
	return;
}

void readNum(Node** header){
	int digit,n;
	do{
		n=scanf("%04d",&digit);
		if(n==0){
			printf("error reading input\n");
			exit(0);
		}
		if(digit/BASE !=0){
			printf("invalid digit ... exiting\n");
			exit(0);
		}
		prependDigit(header,digit);
	}while(getchar()!='$');
}

/*void readNum(Node **header){
	char i;
	int digit,count;
	
	digit = 0;
	count = 0;
	i = '@';
	
	do{
		i = getc(stdin);
	}while(i==' ');
	
	if((int)i>=OFFSET && (int)i<OFFSET+10){
		digit = 10*digit + (int)i - OFFSET;
		count++;
	}
	else if(i!='$'){
		printf("invalid number\n");
		return;
	}
	
	while(i!='$'){
		i = getc(stdin);
		if(i!=',' && (int)i>=OFFSET && (int)i<OFFSET+10){
			digit = 10*digit + (int)i - OFFSET;
			count++;
//			printf("%d\n",count);
		}
		else if(i==',' || i == '$' && count<5){
			prependDigit(header,digit);
			digit = 0;
			count = 0;
		}
		
		else{
			printf("invalid number\n");
			return;
		}
	}
}*/

char readOp(){
	char c;
	do{
		c = getc(stdin);
	}while(c==' ');
	
	return c;
}

Node* evalLarge(){
	Node *num1, *num2, *num3, *result;
	char op;
	
	result = NULL;
	num1 = NULL;
	num2 = NULL;
	
	while(1){
		if(result == NULL){
			readNum(&num1);
			op = readOp();
			if(op == '=') break;

			readNum(&num2);
//			printNum(num1);
//			printNum(num2);
			switch(op){
				case '+':
					result = addLarge(num1,num2);
					break;
				case '*':
					result = mulLarge(num1,num2);
					break;
				default:
					printf("invalid operator\n");
					return NULL;
			}
			
//			printNum(result);
		}
		else{
			op = readOp();
			if(op == '=') break;
			
			readNum(&num2);
			num1 = result;
			
//			printNum(num1);
//			printNum(num2);
			
			switch(op){
				case '+':
					result = addLarge(num1,num2);
					break;
				case '*':
					result = mulLarge(num1,num2);
					break;
				default:
					printf("invalid operator\n");
					return NULL;
			}
			
		}
		
		clearList(&num1);
		clearList(&num2);
	}
	op = getc(stdin);
//	printNum(result);
	return result;
}

Node* addLarge(Node* num1,Node* num2){
	Node *temp1, *temp2;
	Node *num3;
	int tempDigit,tempCarry;
	
	temp1 = num1;
	temp2 = num2;
	num3 = NULL;
	
	tempCarry = 0;
	
	while(temp1!=NULL && temp2!=NULL){
		tempDigit = (temp1->digit + temp2->digit)%BASE + tempCarry;
		tempCarry = (temp1->digit + temp2->digit)/BASE;
		prependDigit(&num3,tempDigit);
		temp1 = temp1->next;
		temp2 = temp2->next;
//		printf("yay!\n");
	}
	
//	printf("yolo\n");
	if(temp1==NULL && temp2==NULL && tempCarry!=0){
		prependDigit(&num3,tempCarry); 
	}
	
//	printf("yolo\n");
	while(temp1!=NULL){
		prependDigit(&num3,temp1->digit + tempCarry);
		temp1 = temp1->next;
		tempCarry = 0;
	}
	
//	printf("yolo\n");
	while(temp2!=NULL){
		prependDigit(&num3,temp2->digit + tempCarry);
		temp2 = temp2->next;
		tempCarry = 0;
	}
	
//	printf("yolo\n");
	reverseList(&num3);
	return num3;
}

Node* mulLarge(Node* num1, Node* num2){
	Node *temp1, *temp2, *temp3, *temp4;
	Node *num3;
	int tempDigit, tempCarry;
	int i,digCount = 0;
	
	if(num1==NULL || num2==NULL){
		printf("One of the parameters is NULL");
		return NULL;
	}
	
	temp1 = num1;
	temp2 = num2;
	num3 = NULL;
	temp3 = NULL;
	temp4 = NULL;
	
	while(temp2!=NULL){
		tempCarry = 0;
		temp1 = num1;
		while(temp1!=NULL){
			tempDigit = ((temp1->digit)*(temp2->digit))%BASE + tempCarry;
			tempCarry = ((temp1->digit)*(temp2->digit))/BASE;
			
			if(temp2->prev == NULL) appendDigit(&temp3,tempDigit);
			else appendDigit(&temp4,tempDigit);
			
			temp1 = temp1->next;
		}
		
		
		if(tempCarry!=0 && temp2->prev == NULL) appendDigit(&temp3,tempCarry);
		else if(tempCarry!=0) appendDigit(&temp4,tempCarry);
		
		digCount++;
		for(i=1;i<digCount;i++){ 
			prependDigit(&temp4,0);
		}
		
		num3 = addLarge(temp3,temp4);
/*		printf("%d\n",num3->digit);
		printNum(num3);*/
		clearList(&temp3);
		clearList(&temp4);

		temp3 = num3;
		temp2 = temp2->next;
	}
	
	return num3;
}