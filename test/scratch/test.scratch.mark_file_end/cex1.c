// test.scratch.mark_file_end.cpp : Defines the entry point for the console application.
//

#include <xcover/xcover.h>

/* ////////////////////////////////////////////////////////////////////// */

static void mark_file_start_(void);
static void mark_file_end_(void);

/* ////////////////////////////////////////////////////////////////////// */

static void mark_file_start_(void)
{
    XCOVER_CREATE_FILE_ALIAS("api.1.2.c");
    XCOVER_ASSOCIATE_FILE_WITH_GROUP("api1");
    XCOVER_MARK_FILE_START();
}

/* ////////////////////////////////////////////////////////////////////// */

//XCOVER_DECLARE_COMPUNIT_START_END_FUNCTIONS(cex1_mark_start_fn, cex1_end_fn);

int cex1_0_no_coverage()
{
    return __COUNTER__ + 1;
}

//XCOVER_DEFINE_COMPUNIT_START_FUNCTION(cex1_mark_start_fn);

void cex1_1()
{
    XCOVER_MARK_LINE();
}

void cex1_2()
{
    XCOVER_MARK_LINE();
}

void cex1_3()
{
    XCOVER_MARK_LINE();
}

void cex1_4()
{
    XCOVER_MARK_LINE();
}

void cex1_5()
{
    XCOVER_MARK_LINE();
}

void cex1_6()
{
    XCOVER_MARK_LINE();
}

void cex1_7()
{
    XCOVER_MARK_LINE();
}

void cex1_8()
{
    XCOVER_MARK_LINE();
}

void cex1_9()
{
    XCOVER_MARK_LINE();
}

//XCOVER_DEFINE_COMPUNIT_END_FUNCTION(cex1_mark_end_fn);

/* ////////////////////////////////////////////////////////////////////// */

static void mark_file_end_(void)
{
    XCOVER_MARK_FILE_END();
}

/* ///////////////////////////// end of file //////////////////////////// */
