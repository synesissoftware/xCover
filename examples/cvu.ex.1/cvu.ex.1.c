/* file: cvu.ex.1.c */
#include <xcover/xcover.h>
#include <stdlib.h>
void fn1(int i) {}
void fn2(int i) {}
void process_int(int value, bool ignoreNeg)
{
  XCOVER_MARK_LINE();
  if( value > 0 ||
      ( ignoreNeg &&
        ((value = -value), true)))
  {
    XCOVER_MARK_LINE();
    fn1(value);
  }
  else if(value < 0)
  {
    XCOVER_MARK_LINE();
    fn2(value);
  }
  XCOVER_MARK_LINE();
}

int main(int argc, char** argv)
{
  int r = xcover_init();
  if(r < 0)
  {
    fprintf(stderr, "could not initialise xCover library: %s\n", xcover_getInitCodeString(r));
    return EXIT_FAILURE;
  }
  else
  {
    process_int(0, false);
    process_int(-1, false);
    XCOVER_REPORT_THIS_FILE_COVERAGE(NULL);
    xcover_uninit();
    return EXIT_SUCCESS;
  }
}
