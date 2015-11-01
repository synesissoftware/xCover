// test.scratch.mark_file_end.cpp : Defines the entry point for the console application.
//

#include <xcover/xcover.h>

extern "C"
{

void cex1_1();
void cex1_2();
void cex1_3();
void cex1_4();
void cex1_5();
void cex1_6();
void cex1_7();
void cex1_8();
void cex1_9();

} // extern "C"

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

void f1()
{
    XCOVER_MARK_LINE();
}

int main(int /* argc */, char** /* argv */)
{
    mark_file_start_();
    mark_file_end_();

    XCOVER_MARK_LINE();

    f1();

    cex1_1();
    cex1_4();

    XCOVER_REPORT_THIS_FILE_COVERAGE(NULL);

    return 0;
}

void f2()
{
    XCOVER_MARK_LINE();
}

/* ////////////////////////////////////////////////////////////////////// */

static void mark_file_end_(void)
{
    XCOVER_MARK_FILE_END();
}

/* ///////////////////////////// end of file //////////////////////////// */
