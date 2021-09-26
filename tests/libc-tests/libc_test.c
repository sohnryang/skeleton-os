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

static void test_kstrncpy(void **state) {
  char str1[11] = "skeletonOS";
  char str2[9];
  kstrncpy(str2, str1, 8);
  str2[8] = '\0';
  assert_string_equal(str2, "skeleton");
}

int main() {
  const struct CMUnitTest tests[] = {cmocka_unit_test(test_kstrlen),
                                     cmocka_unit_test(test_kstrcpy),
                                     cmocka_unit_test(test_kstrncpy)};
  return cmocka_run_group_tests(tests, NULL, NULL);
}
