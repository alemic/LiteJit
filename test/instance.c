#include <assert.h>

#include "../src/core/instance.h"

int main(void)
{
    ljit_instance *test = NULL;

    test = ljit_new_instance();

    assert(test);

    ljit_free_instance(test);

    return 0;
}
