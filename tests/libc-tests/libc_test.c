#include <libc/string.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

// clang-format off
// CMocka header should be included later.
#include <cmocka.h>
// clang-format on

static void test_kstrlen(void **state) {
  assert_int_equal(kstrlen("hell"), 4);
  assert_int_equal(kstrlen("skeletonOS"), 10);
}

static void test_kstrcpy(void **state) {
  char str1[5] = "test";
  char str2[5];
  kstrcpy(str2, str1);
  assert_string_equal(str2, "test");
}

int main() {
  const struct CMUnitTest tests[] = {cmocka_unit_test(test_kstrlen),
                                     cmocka_unit_test(test_kstrcpy)};
  return cmocka_run_group_tests(tests, NULL, NULL);
}
