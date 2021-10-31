
#include<check.h>
#include<stdio.h>
#include <signal.h>
#include "s21_string.h"






//MARK: - STRLEN

START_TEST (STRLEN)
{
    char str[] = "zalupa";
    ck_assert_int_eq(s21_strlen(str), 6);
    ck_assert_int_eq(s21_strlen(str), 7);
    ck_assert_int_eq(s21_strlen(str), 5);
}
END_TEST


//MARK: - STRSPN

START_TEST (STRSPN)
{
    char str[] = "zalupa";
    char str1[] = "zalu";
    ck_assert_int_eq(s_21Strspn(str, str1), 4);
    ck_assert_int_eq(s_21Strspn(str, str1), 5);
}
END_TEST


//START_TEST(busError)
//{
//int a = busE();
//}
//END_TEST



//START_TEST (sample_test2)
//{
//    char str[] = "zalupa";
//    ck_assert_int_eq(s21_strlen(str), 5);
//}
//END_TEST
//
//
//START_TEST (sample_test3)
//{
//    char str[] = "zalupa";
//    ck_assert_int_eq(s21_strlen(str), 6);
//}
//END_TEST







int main()
{
    // Suites
    Suite *s1 = suite_create("Test");
  
  
    // Runner
    SRunner *runner = srunner_create(s1);
 
    int number_failed;
    
    
    TCase *eqCase = tcase_create("sumBaseTest");
   
    suite_add_tcase(s1, eqCase);
    
//    tcase_add_test(eqCase, sample_test);
    tcase_add_test(eqCase, STRLEN);
    tcase_add_test(eqCase, STRSPN);
//    tcase_add_test(eqCase, sample_test3);
    
    
//    TCase *busECase = tcase_create("busErrorTest");
//    tcase_add_test_raise_signal(busECase, busError, SIGBUS);
//    tcase_add_test_raise_signal(busECase, busError, 11);
//    suite_add_tcase(s1, busECase);
    
    srunner_run_all(runner, CK_ENV);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return number_failed == 0 ? 0 : 1;
}
