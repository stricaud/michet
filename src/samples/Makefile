all: hello exit

hello: hello.s
	nasm -f elf hello.s -o hello.o
	ld -m elf_i386 -s -o hello hello.o

exit: exit.s
	nasm -f elf exit.s -o exit.o
	ld -m elf_i386 -s -o exit exit.o
