#include <stdio.h>

#include <michet/elf.h>

int main(int argc, char **argv)
{

  printf("sizeof Elf64_Addr:%ld\n", sizeof(Elf64_Addr));
  printf("sizeof Elf64_Half:%ld\n", sizeof(Elf64_Half));
  printf("sizeof Elf64_Off:%ld\n", sizeof(Elf64_Off));
  printf("sizeof Elf64_Sword:%ld\n", sizeof(Elf64_Sword));
  printf("sizeof Elf64_Word:%ld\n", sizeof(Elf64_Word));

  return 0;
}
