
#include<check.h>
#include<stdio.h>
#include <signal.h>
#include<string.h>
#include "s21_string.h"




//MARK: - STRLEN

START_TEST (STRLENTest1)
{
    
    char str[] = "Hello";
    
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
    
    
}
END_TEST

START_TEST (STRLENTest2)
{
     
    char str[] = "Hegd    llo";
    
    
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 11");
    
}
END_TEST

START_TEST (STRLENTest3)
{
    
    char str[] = "";
    
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 0");
}
END_TEST

START_TEST (STRLENTest4)
{
    
    char *str = NULL;
    
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed: Str == NULL");
}
END_TEST


//MARK: - STRCHR

START_TEST (STRCHRTest1)
{
    
    char str[] = "Hello world";
    int ch = 'w';
    ck_assert_str_eq(s_21Strchr(str, ch),strchr(str,ch));
    //    ck_assert_msg((s_21Strchr(str, ch) == ), "Failed: Str == NULL");
}

END_TEST


START_TEST (STRCHRTest2)
{
    
    char str[] = "Hello world";
    
    int ch = 'e';
    ck_assert_str_eq(s_21Strchr(str, ch),strchr(str,ch));
    
}
END_TEST



START_TEST (STRCHRTest3)
{
    
//        char str[] = "Hello world";
//
//        int ch = 'c';
//        ck_assert_str_eq(s_21Strchr(str, ch),strchr(str,ch));
    
}
END_TEST

START_TEST (STRCHRTest4)
{
    
    char str[] = "Hello world";
    
    int ch = 'H';
    ck_assert_str_eq(s_21Strchr(str, ch),strchr(str,ch));
    
}
END_TEST





//MARK:- STRSPN

START_TEST (STRSPNTest1)
{
    
    char *str1 = "12345";
    char *str2 = "123";
    
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 3");
}
END_TEST

START_TEST (STRSPNTest2)
{
    
    char *str1 = "12345";
    char *str2 = "12sd34";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 4");
    
}
END_TEST


START_TEST (STRSPNTest3)
{
    
    char *str1 = "12345";
    char *str2 = "12sdf4";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 2");
    
}
END_TEST

START_TEST (STRSPNTest4)
{
    
    char *str1 = "12345";
    char *str2 = "kbf";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
    
}
END_TEST

START_TEST (STRSPNTest5)
{
    
    char *str1 = "12345";
    char *str2 = "54321";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2) , "Failed on 5");
    
}
END_TEST

START_TEST (STRSPNTest6)
{
    
    char *str1 = "12345";
    char *str2 = "5qw4w3qwe2qweqw1";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 5");
    
}
END_TEST

START_TEST (STRSPNTest7)
{
    
    char *str1 = "12345";
    char *str2 = " ";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
    
}
END_TEST

START_TEST (STRSPNTest8)
{
    
    char *str1 = "12345";
    char *str2 = " 1";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 1");
    
}
END_TEST

START_TEST (STRSPNTest9)
{
    
    char *str1 = NULL;
    char *str2 = " 1";
    ck_assert_msg(s_21Strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
    
}
END_TEST


//MARK: - STRCSPN

START_TEST (STRCSPNTest1)
{
    
    char *src = "0123456789";
    char *str = "54";
    ck_assert_msg(s_21Strcspn(src, str) == strcspn(src,str), "Failed on 4");
    
}
END_TEST

START_TEST (STRCSPNTest2)
{
    
    char *src = "0123456789";
    char *str = "e";
    ck_assert_msg(s_21Strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST


START_TEST (STRCSPNTest3)
{
    
    char *src = NULL;
    char *str = "123";
    ck_assert_msg(s_21Strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST

START_TEST (STRCSPNTest4)
{
    
    char *src = "46";
    char *str = "123";
    ck_assert_msg(s_21Strcspn(src, str) == strcspn(src,str), "Failed on 2");
    
}
END_TEST

START_TEST (STRCSPNTest5)
{
    
    char *src = "HELLO";
    char *str = "HELLO";
    ck_assert_msg(s_21Strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST

//MARK:- MEMCPY

START_TEST (MEMCPYTest1)
{

    char *src = "HELLO WORLD";
    char *dest[15];
    char *dest2[15];
   
    ck_assert_mem_eq(s21_memcpy(dest,src,11), memcpy(dest2,src,11),0);

}
END_TEST











//MARK: - BUSERROR
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
    Suite *s1 = suite_create("Core");
    
    
    // Runner
    SRunner *runner = srunner_create(s1);
    
    
    int number_failed;
    TCase *StrLenTest = tcase_create("STRLEN");
    TCase *StrChrTest = tcase_create("STRCHR");
    TCase *StrSpnTest = tcase_create("STRSPN");
    TCase *StrсSpnTest = tcase_create("STRСSPN");
        TCase *MemCpyTest = tcase_create("MEMCPY");
    
    
    
    suite_add_tcase(s1, StrLenTest);
    tcase_add_test(StrLenTest, STRLENTest1);
    tcase_add_test(StrLenTest, STRLENTest2);
    tcase_add_test(StrLenTest, STRLENTest3);
    tcase_add_test(StrLenTest, STRLENTest4);
    
    suite_add_tcase(s1, StrChrTest);
    tcase_add_test(StrChrTest, STRCHRTest1);
    tcase_add_test(StrChrTest, STRCHRTest2);
    tcase_add_test(StrChrTest, STRCHRTest3);
    tcase_add_test(StrChrTest, STRCHRTest4);
    
    suite_add_tcase(s1, StrSpnTest);
    tcase_add_test(StrSpnTest,STRSPNTest1);
    tcase_add_test(StrSpnTest,STRSPNTest2);
    tcase_add_test(StrSpnTest,STRSPNTest3);
    tcase_add_test(StrSpnTest,STRSPNTest4);
    tcase_add_test(StrSpnTest,STRSPNTest5);
    tcase_add_test(StrSpnTest,STRSPNTest6);
    tcase_add_test(StrSpnTest,STRSPNTest7);
    tcase_add_test(StrSpnTest,STRSPNTest8);
    tcase_add_test(StrSpnTest,STRSPNTest9);
    
    suite_add_tcase(s1, StrсSpnTest);
    tcase_add_test(StrсSpnTest,STRCSPNTest1);
    tcase_add_test(StrсSpnTest,STRCSPNTest2);
    tcase_add_test(StrсSpnTest,STRCSPNTest3);
    tcase_add_test(StrсSpnTest,STRCSPNTest4);
    tcase_add_test(StrсSpnTest,STRCSPNTest5);
    
        suite_add_tcase(s1, MemCpyTest);
        tcase_add_test(MemCpyTest,MEMCPYTest1);
    
    
    
    srunner_run_all(runner, CK_NORMAL );
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return number_failed == 0 ? 0 : 1;
}
