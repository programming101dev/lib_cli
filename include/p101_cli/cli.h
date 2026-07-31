#ifndef LIBP101_CLI_CLI_H
#define LIBP101_CLI_CLI_H

/*
 * Copyright 2026 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 */

#include <getopt.h>
#include <p101_env/env.h>
#include <p101_error/attributes.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int p101_getopt(const struct p101_env *env, int argc, char *const argv[], const char *optstring);
    int p101_getopt_long(const struct p101_env *env, int argc, char *const argv[], const char *optstring, const struct option *longopts, int *longindex);
    int p101_getopt_long_only(const struct p101_env *env, int argc, char *const argv[], const char *optstring, const struct option *longopts, int *longindex);
    int p101_getsubopt(const struct p101_env *env, char **optionp, char *const *keylistp, char **valuep);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_CLI_CLI_H
