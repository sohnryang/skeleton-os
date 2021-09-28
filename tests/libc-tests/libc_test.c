#include <libc/string.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

// clang-format off
// CMocka header must be included later.
#include <cmocka.h>
// clang-format on

static void test_kstrlen(__attribute__((unused)) void **state) {
  assert_int_equal(kstrlen("hell"), 4);
  assert_int_equal(kstrlen("skeletonOS"), 10);
}

static void test_kstrcpy(__attribute__((unused)) void **state) {
  char str1[5] = "test";
  char str2[5];
  kstrcpy(str2, str1);
  assert_string_equal(str2, "test");
}

static void test_kstrncpy(__attribute__((unused)) void **state) {
  char str1[11] = "skeletonOS";
  char str2[9];
  kstrncpy(str2, str1, 8);
  str2[8] = '\0';
  assert_string_equal(str2, "skeleton");
}

static void test_kmemmove(__attribute__((unused)) void **state) {
  unsigned int arr1[] = {0xffff0001, 0xffff0002, 0xffff0003, 0xffff0004};
  unsigned int arr2[2];
  kmemmove(arr2, arr1, 8);
  assert_int_equal(arr2[0], arr1[0]);
  assert_int_equal(arr2[1], arr1[1]);

  kmemmove(arr1 + 2, arr1, 8);
  assert_int_equal(arr1[0], 0xffff0001);
  assert_int_equal(arr1[1], 0xffff0002);
  assert_int_equal(arr1[2], arr1[0]);
  assert_int_equal(arr1[3], arr1[1]);
}

static void test_kitoa(__attribute__((unused)) void **state) {
  int num1 = 1234567890;
  char str1[11];
  kitoa(num1, str1);
  assert_string_equal(str1, "1234567890");
  int num2 = -1234567890;
  char str2[12];
  kitoa(num2, str2);
  assert_string_equal(str2, "-1234567890");
  int num3 = 0;
  char str3[2];
  kitoa(num3, str3);
  assert_string_equal(str3, "0");
}

static void test_kitoa_hex(__attribute__((unused)) void **state) {
  int num1 = 0xc0ffee;
  char str1[9];
  kitoa_hex(num1, str1);
  assert_string_equal(str1, "c0ffee");
  int num2 = -0xdeadbeef;
  char str2[9];
  kitoa_hex(num2, str2);
  assert_string_equal(str2, "21524111");
  int num3 = 0;
  char str3[2];
  kitoa_hex(num3, str3);
  assert_string_equal(str3, "0");
}

int main() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_kstrlen),   cmocka_unit_test(test_kstrcpy),
      cmocka_unit_test(test_kstrncpy),  cmocka_unit_test(test_kitoa),
      cmocka_unit_test(test_kitoa_hex), cmocka_unit_test(test_kmemmove)};
  return cmocka_run_group_tests(tests, NULL, NULL);
}
