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

#include "p101_cli/p101_getopt.h"
#include "p101_cli/p101_stdlib.h"
#include "p101_cli/p101_unistd.h"
#include <p101_env/wrapper.h>

/*
 * Copyright 2022-2024 D'Arcy Smith.
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

int p101_getopt_long(const struct p101_env *env, int argc, char *const argv[], const char *optstring, const struct option *longopts, int *longindex)
{
    int ret_val;
    P101_TRACE(env);
    ret_val = getopt_long(argc, argv, optstring, longopts, longindex);
    P101_TRACE_EXIT(env);
    return ret_val;
}

int p101_getopt_long_only(const struct p101_env *env, int argc, char *const argv[], const char *optstring, const struct option *longopts, int *longindex)
{
    int ret_val;
    P101_TRACE(env);
    ret_val = getopt_long_only(argc, argv, optstring, longopts, longindex);
    P101_TRACE_EXIT(env);
    return ret_val;
}
