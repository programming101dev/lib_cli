#include <p101_cli/cli.h>
#include <p101_env/env.h>
#include <p101_error/error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

static int failures;

#define EXPECT(condition)                                                                                                                                                                                                                                          \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        if(!(condition))                                                                                                                                                                                                                                           \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);                                                                                                                                                                                   \
            failures++;                                                                                                                                                                                                                                            \
        }                                                                                                                                                                                                                                                          \
    } while(0)

static int run_parser(const struct p101_env *env, int which)
{
    char          short_option[] = "-a";
    char          long_option[]  = "--alpha";
    char          long_only[]    = "-alpha";
    char          program[]      = "test";
    char         *short_argv[]   = {program, short_option, NULL};
    char         *long_argv[]    = {program, long_option, NULL};
    char         *only_argv[]    = {program, long_only, NULL};
    struct option options[]      = {
        {"alpha", no_argument, NULL, 'a'},
        {NULL,    0,           NULL, 0  }
    };
    int index = -1;
    int result;

    optind = 1;
    switch(which)
    {
        case 0:
            /* P101_TEST_CASE(p101_getopt) */
            result = p101_getopt(env, 2, short_argv, "a");
            return result == 'a' ? EXIT_SUCCESS : EXIT_FAILURE;
        case 1:
            /* P101_TEST_CASE(p101_getopt_long) */
            result = p101_getopt_long(env, 2, long_argv, "", options, &index);
            return result == 'a' && index == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
        case 2:
            /* P101_TEST_CASE(p101_getopt_long_only) */
            result = p101_getopt_long_only(env, 2, only_argv, "", options, &index);
            return result == 'a' && index == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
        default:
            return EXIT_FAILURE;
    }
}

static void test_option_parsers(const struct p101_env *env)
{
    int status;

    for(int which = 0; which < 3; which++)
    {
        pid_t child = fork();

        EXPECT(child >= 0);
        if(child == 0)
        {
            _exit(run_parser(env, which));
        }
        if(child > 0)
        {
            EXPECT(waitpid(child, &status, 0) == child);
            EXPECT(WIFEXITED(status));
            EXPECT(WEXITSTATUS(status) == EXIT_SUCCESS);
        }
    }
}

static void test_suboptions(struct p101_env *env)
{
    char  suboptions[] = "mode=fast";
    char *suboption    = suboptions;
    char  key[]        = "mode";
    char *keys[]       = {key, NULL};
    char *value        = NULL;

    /* P101_TEST_CASE(p101_getsubopt) */
    EXPECT(p101_getsubopt(env, &suboption, keys, &value) == 0);
    EXPECT(value != NULL && strcmp(value, "fast") == 0);
}

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;

    err = p101_error_create(false);
    if(err == NULL)
    {
        return EXIT_FAILURE;
    }
    env = p101_env_create(err, NULL);
    if(env == NULL)
    {
        p101_error_destroy(err);
        return EXIT_FAILURE;
    }
    test_option_parsers(env);
    test_suboptions(env);
    p101_env_destroy(env);
    p101_error_destroy(err);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
