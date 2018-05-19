#include <stdio.h>
#include <string.h>

#include <michet/elf.h>
#include <michet/write-asm.h>
#include <michet/michet.h>

int main(int argc, char **argv)
{
  michet_t *michet;
  char *pbuf;

  /* michet_parse_generator(argv[1]); */

  /* return 0; */

  if (argc < 3) {
    fprintf(stderr, "Syntax: %s input.mic output\n", argv[0]);
    return -1;
  }
  
  michet = michet_init(argv[2]);

  /* write_elf(michet); */
  /* pbuf = "Simple test 1234!\n"; */
  /* /\* write_print(michet, pbuf, strlen(pbuf) + 1); *\/ */

  michet_write_elf_header(michet);
  
  michet_terminate(michet);

  return 0;
}
