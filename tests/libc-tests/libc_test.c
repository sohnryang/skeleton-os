#include <libc/string.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

// clang-format off
// CMocka header should be included later.
#include <cmocka.h>
// clang-format on

static void test_strlen(void **state) {
  assert_int_equal(kstrlen("hell"), 4);
  assert_int_equal(kstrlen("skeletonOS"), 10);
}

int main() {
  const struct CMUnitTest tests[] = {cmocka_unit_test(test_strlen)};
  return cmocka_run_group_tests(tests, NULL, NULL);
}
