#include <stdio.h>
struct s_option {
  char logdir[BUFSIZ];
  char defshell[BUFSIZ];
  char fdl;
  int priority;
  int facility;
  int clearenvironment;
  int immutable_recordings;
  char argallow[BUFSIZ];
};

typedef struct s_option option;
