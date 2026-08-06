/*
 * Copyright 2021-2024 D'Arcy Smith.
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

#include "p101_cli/cli.h"
#include <p101_env/wrapper.h>
#include <stdlib.h>

#ifdef __APPLE__
    #include <unistd.h>
#endif

int p101_getsubopt(const struct p101_env *env, char **optionp, char *const *keylistp, char **valuep)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getsubopt(optionp, keylistp, valuep);

    P101_TRACE_EXIT(env);
    return ret_val;
}

/*
 * Copyright 2021-2024 D'Arcy Smith.
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

int p101_getopt(const struct p101_env *env, int argc, char *const argv[], const char *optstring)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getopt(argc, argv, optstring);

    P101_TRACE_EXIT(env);
    return ret_val;
}

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
