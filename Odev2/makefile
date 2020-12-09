hepsi: soru1 soru2
soru1:
	gcc -g -I include -c soru1.c -o obj/soru1.o
	gcc -g -o soru1 obj/soru1.o

soru2:
	cd include/ &&make
	gcc -g -I include -c soru2.c -o obj/soru2.o
	gcc -g -o soru2 obj/soru2.o include/libfdr.a

calistirsoru1:
	./soru1
calistirsoru2:
	./soru2
