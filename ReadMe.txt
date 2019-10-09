Readme for Assignment2: Large integer addition and Polynomial divison

Source file		Functions defined		Desciption
main.c			main				Driver function

list.c			createNode			Creates a node, allocates memory for large intger list
			clearList			Deletes large integer linked list
			reverseList			Reverses a given list
			createPoly			Creates a node, allocates memory for polynomial list
			delPolyNode			Deletes a single polynomial node at the given pointer location
			delPoly				Deletes a given polynomial list
			reversePoly			Reverses a given polynomial list

largeint.c		readNum				Reads a large integer list as comma separted digits terminated by $
			printNum			Prints a large integer list as comma separted digits terminated by $
			appendDigit			Appends a digit (base 10000) to the list
			prependDigit			Prepends a digit (base 10000) to the list
			addLarge			Adds two large integers and returns the sum
			mulLarge			Multiplies two large integers and returns the product
			readOp				Reads an operator in expression
			evalLarge			Evaluates an expression of large integers containing operators + and *

poly.c			readPoly			Reads a polynomial list as comma separted tuples (index,coeff) terminated by \n
			printPoly			Prints a polynomial list as comma separted tuples (index,coeff) terminated by \n
			appendPoly			Appends a polynomial coefficient to the list
			prependPoly			Prepends a polynomial coefficient to the list
			copyPoly			Copies a polynomial list to another list
			abs				Returns the absolute value of coefficient
			divPoly				Divides two polynomials and returns quotient and remainder lists (quotient pointer is passed as argument)

Header: largeintpoly.h

Note: Doubly linked list is implemented for both large integers and polynomials

Program flow:(Follow the prompts)
1) Input an expression of large integers to evalute. Observe the output value.
2) Input two polynomial expressions separated by \n. Observe the quotient and remainder.

Memcheck Summary:
==6509== HEAP SUMMARY:
==6509==     in use at exit: 0 bytes in 0 blocks
==6509==   total heap usage: 32 allocs, 32 frees, 2,768 bytes allocated
==6509== 
==6509== All heap blocks were freed -- no leaks are possible
==6509== 
==6509== For counts of detected and suppressed errors, rerun with: -v
==6509== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)






