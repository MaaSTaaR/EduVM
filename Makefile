main: cpu.o vm.o
	gcc -o eduvm cpu.o vm.o

cpu.o: cpu.c cpu.h
	gcc -o cpu.o -c cpu.c

vm.o: vm.c
	gcc -o vm.o -c vm.c
