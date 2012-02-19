#ifndef MALLOC
#include <stdlib.h>
#define MALLOC(x) malloc(x)
#define FREE(x)   free(x)
#define CALLOC(x) calloc(x)
#define STRDUP(x) strdup(x)
#endif
