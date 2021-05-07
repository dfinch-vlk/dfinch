all: libft.a

libft.a: part1.o part2.o part3.o part4.o part5.o part6.o part7.o
	ar r libft.a *.o
part1.o: part1.c
	gcc -c part1.c
part2.o: part2.c
	gcc -c part2.c
part3.o: part3.c
	gcc -c part3.c
part4.o: part4.c
	gcc -c part4.c
part5.o: part5.c
	gcc -c part5.c
part6.o: part6.c
	gcc -c part6.c
part7.o: part7.c
	gcc -c part7.c
clean:
	rm -rf *.o