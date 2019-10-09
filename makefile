lintpoly.out: main.o largeint.o list.o poly.o
	gcc -g main.o largeint.o list.o poly.o -o lintpoly.out

main.o : main.c largeintpoly.h
	gcc -g -c main.c largeintpoly.h

largeint.o : largeint.c list.c largeintpoly.h
	gcc -g -c largeint.c list.c largeintpoly.h

list.o : list.c largeintpoly.h
	gcc -g -c list.c largeintpoly.h
	
poly.o : poly.c list.c largeintpoly.h
	gcc -g -c poly.c list.c largeintpoly.h