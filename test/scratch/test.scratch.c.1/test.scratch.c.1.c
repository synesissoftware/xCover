
#include <xcover/xcover.h>

#include <stdio.h>
#include <stdlib.h>

/* API to test */
extern int api1_init(void);
extern void api1_uninit(void);
extern int api1_add(int, int);
extern int api1_subtract(int, int);
extern int api1_multiply(int, int);



int main_(int argc, char** argv)
{
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);

    XCOVER_START_GROUP_COVERAGE("api1");

    {
        int res = api1_init();

        if(res < 0)
        {
        }
        else
        {
            api1_add(10, 10);
            api1_multiply(10, 10);
            api1_add(10, 10);

            api1_uninit();
        }
    }

    XCOVER_END_GROUP_COVERAGE("api1");
    XCOVER_REPORT_GROUP_COVERAGE("api1", NULL);

    return EXIT_SUCCESS;
}


int main(int argc, char** argv)
{
    int res = xcover_init();

    if(res < 0)
    {
        fprintf(stderr, "failed to initialise xCover library: %d\n", res);
    }
    else
    {
        res = main_(argc, argv);

        xcover_uninit();

        return res;
    }

    return EXIT_FAILURE;
}
