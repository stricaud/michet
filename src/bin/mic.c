#include <stdio.h>

#include <michet/elf.h>
#include <michet/write-asm.h>
#include <michet/michet.h>

int main(int argc, char **argv)
{

  michet_t *michet;

  michet = michet_init(argv[2]);

  write_print(michet, "Simple test!\n", 13);

  michet_terminate(michet);

  return 0;
}
