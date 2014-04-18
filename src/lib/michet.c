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
  
  return michet;
}

void michet_terminate(michet_t *michet)
{
  chmod(michet->filename, S_IXUSR | S_IXGRP | S_IXOTH);
  fclose(michet->fp);
  free(michet);
}

