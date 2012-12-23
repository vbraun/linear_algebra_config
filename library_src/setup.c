#include <string.h>
#include <unistd.h>
#include <stdio.h>

extern char **environ;

#include "setup.h"

const char* get_library_name()
{
  const char* config_name = "LINEAR_ALGEBRA_CONFIG";
  const int config_name_len = strlen(config_name);
  const char* config = NULL;
  for (char **env = environ; *env != NULL; env++) {
    if (strncmp(config_name, *env, config_name_len) == 0)
      config = *env;
  }
  return config + (config_name_len+1);
}

