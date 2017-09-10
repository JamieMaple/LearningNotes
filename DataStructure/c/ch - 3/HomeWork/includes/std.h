#ifndef _std_h_
#define _std_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Error(str) fprintf(stderr, ""%s\n, str), exit(1);
#define FatalError(str) Error(str)


#endif