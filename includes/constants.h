#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
** GENERAL
*/

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR 1

/*
** DIRECTORY
*/

# define SEARCH_PATH "./"

/*
** FT_EXIT
*/

# define TOO_MANY_ARGUMENTS 1
# define NUMERIC_ARGUMENT_REQUIRED 2
# define ARG_OVERFLOWING 3
# define MAX_BIT 32
# define EIGHT_BIT 8
# define LLINT long long int
# define UINT unsigned int

/*
** FT_CD
*/

# define ENV_NOT_SET 1
# define DIR_NOT_FOUND 1
# define CHDIR_ERROR -1

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

#endif
