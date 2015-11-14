
#include <xcover/xcover.h>

#include <platformstl/performance/performance_counter.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

#include <list>
#include <thread>

#include <stdlib.h>

#if _DEBUG
const int NUM_THREADS   =   1;
const int NUM_REPEATS   =   100;
#else
const int NUM_THREADS   =   20;
const int NUM_REPEATS   =   1000000/*0*/;
#endif

XCOVER_FILE_ALIAS_ASSOCIATOR("test.performance.threads.component");
XCOVER_DEFINE_FILE_STARTER();

static
void
fn(
    int n
)
{
    XCOVER_MARK_LINE();

    for(int i = 0; i != NUM_REPEATS; ++i)
    {
        XCOVER_MARK_LINE();
        if (0 == ::GetTickCount())
        {
            XCOVER_MARK_LINE();
        }
        XCOVER_MARK_LINE();
    }

    XCOVER_MARK_LINE();
}

XCOVER_DEFINE_FILE_ENDER();


int main(int argc, char* argv[])
{
    xcover::rc_t const r = xcover::init();

    if (0 != r)
    {
        fprintf(stderr, "xCover library could not be initialised: %s\n", ::stlsoft::c_str_ptr_a(r));

        return EXIT_FAILURE;
    }
    else
    {
        stlsoft::scoped_handle<void>        scoper(::xcover::uninit);

        std::list<std::thread>              threads;
        platformstl::performance_counter    counter;

        counter.start();

        for (int i = 0; i != NUM_THREADS; ++i)
        {
            threads.push_back(std::thread(fn, i));
        }

        for(auto& t : threads)
        {
            t.join();
        }

        counter.stop();

        fprintf(stdout, "completed in %lums\n", static_cast<unsigned long>(counter.get_milliseconds()));

        XCOVER_REPORT_ALIAS_COVERAGE("test.performance.threads.component", NULL);

        return EXIT_SUCCESS;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
