#include "s21_string.h"

int main() {
    Suite *s1 = example_suite_create();
    Suite *s4 = example_suite_create2();
    Suite *s2 = f_example_suite_create();
    Suite *s3 = sscanf_suite_create();
    // Runner
    SRunner *runner = srunner_create(s1);
    SRunner *runner2 = srunner_create(s4);
    SRunner *f_runner = srunner_create(s2);
    SRunner *s_runner = srunner_create(s3);
    int number_failed;
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    srunner_run_all(runner2, CK_NORMAL);
    number_failed = number_failed + srunner_ntests_failed(runner2);
    srunner_free(runner2);
    srunner_run_all(f_runner, CK_NORMAL);
    number_failed = number_failed + srunner_ntests_failed(f_runner);
    srunner_free(f_runner);
    srunner_run_all(s_runner, CK_NORMAL);
    number_failed = number_failed + srunner_ntests_failed(s_runner);
    srunner_free(s_runner);
    return number_failed == 0 ? 0 : 1;
}
