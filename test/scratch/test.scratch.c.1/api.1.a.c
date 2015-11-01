
#include <xcover/xcover.h>

extern int api1_init(void);
extern void api1_uninit(void);
extern int api1_add(int, int);
extern int api1_subtract(int, int);
extern int api1_multiply(int, int);

static void mark_file_start_(void);
static void mark_file_end_(void);

/* ////////////////////////////////////////////////////////////////////// */

static void mark_file_start_(void)
{
    XCOVER_CREATE_FILE_ALIAS("api.1.a.c");
    XCOVER_ASSOCIATE_FILE_WITH_GROUP("api1");
    XCOVER_MARK_FILE_START();
}

/* /////////////////////////////////////////////////////////////////////////
 * API 
 */

int api1_init(void)
{
    mark_file_start_();
    mark_file_end_();

    XCOVER_MARK_LINE();

    return 0;
}

int api1_add(int lhs, int rhs)
{
    XCOVER_MARK_LINE();

    return lhs + rhs;
}

int api1_subtract(int lhs, int rhs)
{
    XCOVER_MARK_LINE();

    return lhs - rhs;
}

/* ////////////////////////////////////////////////////////////////////// */

static void mark_file_end_(void)
{
    XCOVER_MARK_FILE_END();
}

/* ///////////////////////////// end of file //////////////////////////// */
