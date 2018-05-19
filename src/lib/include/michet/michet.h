#ifndef _MICHET_MICHET_H_
#define _MICHET_MICHET_H_

#include <stdio.h>

typedef struct _michet_t michet_t;
struct _michet_t {
  const char *filename;
  size_t offset;
  FILE *fp;
};

michet_t *michet_init(char *output_file);
void michet_terminate(michet_t *michet);
int michet_parse_generator(char *genfile);

#endif	/* _MICHET_MICHET_H_ */

