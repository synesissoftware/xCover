

#include <xcover/xcover.h>

#include <stdio.h>

/* We'll simulate a full file here, by denoting the start and end
 * markers explicitly
 *
 */

/* Start of "file" */

static void mark_file_start_(void)
{
    XCOVER_MARK_FILE_START();
}
static void fn1(int i)
{
    if(i < 0)
    {
        XCOVER_MARK_LINE();
    }
    else if(i > 0)
    {
        XCOVER_MARK_LINE();
    }
    else
    {
        XCOVER_MARK_LINE();
    }
}


static void mark_file_end_(void)
{
    XCOVER_MARK_FILE_END();
}

/* End of "file" */


int main()
{
    /* Initialise xCover library */
    xcover_rc_t rc = xcover_init();

    if(XCOVER_RC_SUCCESS != rc)
    {
        fprintf(stderr, "failed to initialise xCover: %s\n", xcover_getApiCodeString(rc));
    }
    else
    {
        /* Mark start and end of "file" */
        mark_file_start_();
        mark_file_end_();

        /* Exercise functionality in "file" */
//      fn1(0);
        fn1(-1);
        fn1(+1);



        /* Report coverage of this file */
        XCOVER_REPORT_THIS_FILE_COVERAGE(NULL);

        /* Uninitialise xCover library */
        xcover_uninit();
    }

    return EXIT_SUCCESS;
}