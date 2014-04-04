all: hello

hello: hello.s
	nasm -f elf hello.s -o hello.o
	ld -m elf_i386 -s -o hello hello.o