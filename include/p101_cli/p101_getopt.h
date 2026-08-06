#ifndef LIBP101_CLI_P101_GETOPT_H
#define LIBP101_CLI_P101_GETOPT_H

/*
 * Copyright 2026 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBP101_CLI_SHARED_DECLARATIONS
    #define LIBP101_CLI_SHARED_DECLARATIONS
    #include <getopt.h>
    #include <p101_env/env.h>
    #include <p101_error/attributes.h>
    #include <unistd.h>
#endif    // LIBP101_CLI_SHARED_DECLARATIONS

#ifdef __cplusplus
extern "C"
{
#endif

    int p101_getopt_long(const struct p101_env *env, int argc, char *const argv[], const char *optstring, const struct option *longopts, int *longindex);
    int p101_getopt_long_only(const struct p101_env *env, int argc, char *const argv[], const char *optstring, const struct option *longopts, int *longindex);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_CLI_P101_GETOPT_H
