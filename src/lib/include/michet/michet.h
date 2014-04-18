#ifndef _MICHET_MICHET_H_
#define _MICHET_MICHET_H_

#include <stdio.h>

typedef struct _michet_t michet_t;
struct _michet_t {
  const char *filename;
  FILE *fp;
};

michet_t *michet_init(char *output_file);
void michet_terminate(michet_t *michet);

#endif	/* _MICHET_MICHET_H_ */

