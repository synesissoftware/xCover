
#define _STLSOFT_NO_NAMESPACES
#define XCOVER_NO_NAMESPACE

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
    /* Mark start and end of "file" */
    mark_file_start_();
    mark_file_end_();

    /* Exercise functionality in "file" */
//  fn1(0);
    fn1(-1);
    fn1(+1);



    /* Report coverage of this file */
    XCOVER_REPORT_THIS_FILE_COVERAGE(NULL);

    return EXIT_SUCCESS;
}