#include <stdio.h>
#include <string.h>

#include <michet/elf.h>
#include <michet/write-asm.h>
#include <michet/michet.h>

int main(int argc, char **argv)
{
  michet_t *michet;
  char *pbuf;

  michet_parse_generator(argv[1]);

  return 0;
  
  michet = michet_init(argv[2]);

  write_elf(michet);
  pbuf = "Simple test 1234!\n";
  write_print(michet, pbuf, strlen(pbuf) + 1);

  michet_terminate(michet);

  return 0;
}
