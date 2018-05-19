#define _POSIC_C_SOURCE 201805L
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <michet/michet.h>

michet_t *michet_init(char *output_file)
{
  michet_t *michet;

  michet = malloc(sizeof(*michet));

  michet->filename = output_file;
  michet->fp = fopen(output_file, "wb");
  michet->offset = 0;
  
  return michet;
}

void michet_terminate(michet_t *michet)
{
  fchmod(fileno(michet->fp), S_IXUSR | S_IXGRP | S_IXOTH | S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
  fclose(michet->fp);
  free(michet);
}

