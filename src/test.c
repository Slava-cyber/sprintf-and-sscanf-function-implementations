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
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
    
}

END_TEST


START_TEST (STRCHRTest2)
{
    
    char str[] = "Hello world";
    
    int ch = 'e';
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
    
}
END_TEST



START_TEST (STRCHRTest3)
{
    
    char str[] = "Hello world";
    
    int ch = 'c';
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
    
}
END_TEST

START_TEST (STRCHRTest4)
{
    
    char str[] = "Hello world";
    
    int ch = 'H';
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
    
}
END_TEST


//MARK:- STRSPN

START_TEST (STRSPNTest1)
{
    
    char *str1 = "12345";
    char *str2 = "123";
    
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 3");
}
END_TEST

START_TEST (STRSPNTest2)
{
    
    char *str1 = "12345";
    char *str2 = "12sd34";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 4");
    
}
END_TEST


START_TEST (STRSPNTest3)
{
    
    char *str1 = "12345";
    char *str2 = "12sdf4";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 2");
    
}
END_TEST

START_TEST (STRSPNTest4)
{
    
    char *str1 = "12345";
    char *str2 = "kbf";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
    
}
END_TEST

START_TEST (STRSPNTest5)
{
    
    char *str1 = "12345";
    char *str2 = "54321";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2) , "Failed on 5");
    
}
END_TEST

START_TEST (STRSPNTest6)
{
    
    char *str1 = "12345";
    char *str2 = "5qw4w3qwe2qweqw1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 5");
    
}
END_TEST

START_TEST (STRSPNTest7)
{
    
    char *str1 = "12345";
    char *str2 = " ";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
    
}
END_TEST

START_TEST (STRSPNTest8)
{
    
    char *str1 = "12345";
    char *str2 = " 1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 1");
    
}
END_TEST

START_TEST (STRSPNTest9)
{
    
    char *str1 = NULL;
    char *str2 = "1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
    
}
END_TEST


//MARK: - STRCSPN

START_TEST (STRCSPNTest1)
{
    
    char *src = "0123456789";
    char *str = "54";
    ck_assert_msg(s_21strcspn(src, str) == strcspn(src,str), "Failed on 4");
    
}
END_TEST

START_TEST (STRCSPNTest2)
{
    
    char *src = "0123456789";
    char *str = "e";
    ck_assert_msg(s_21strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST


START_TEST (STRCSPNTest3)
{
    
    char *src = NULL;
    char *str = "123";
    ck_assert_msg(s_21strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST

START_TEST (STRCSPNTest4)
{
    
    char *src = "46";
    char *str = "123";
    ck_assert_msg(s_21strcspn(src, str) == strcspn(src,str), "Failed on 2");
    
}
END_TEST

START_TEST (STRCSPNTest5)
{
    
    char *src = "HELLO";
    char *str = "HELLO";
    ck_assert_msg(s_21strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST

//MARK:- MEMCPY

START_TEST (MEMCPYTest1)
{
    
    char *src = "HELLO WORLD";
    char dest[15];
    char dest2[15];
    
    ck_assert_mem_eq(s21_memcpy(dest,src,11),memcpy(dest2,src,11),11);
}
END_TEST

START_TEST (MEMCPYTest2)
{
    
    char *src = "HELLO";
    char dest[5];
    char dest2[5];
    
    ck_assert_mem_eq(s21_memcpy(dest,src,5),memcpy(dest2,src,5),5);
}
END_TEST

//MARK:- STRCAT
START_TEST (STRCATTest1)
{
    
    char app[1024]="вторая строка ";
    char dst[1024]="первая строка ";
    
    
    ck_assert_str_eq( s21_strcat(dst,app),strcat(dst,app));
}
END_TEST


START_TEST (STRCATTest2)
{
    
    char app[1024]=" ";
    char dst[1024]="   ";
    
    
    ck_assert_str_eq( s21_strcat(dst,app),strcat(dst,app));
}
END_TEST

START_TEST (STRCATTest3)
{
    
    char app[1024]="s s d";
    char dst[1024]=" s  s  s  sd aff   ";
    
    
    ck_assert_str_eq( s21_strcat(dst,app),strcat(dst,app));
}
END_TEST


START_TEST (STRCATTest4)
{
    
    char app[1024]="sdddadasdsa";
    char dst[1024]="s                              ";
    
    
    ck_assert_str_eq( s21_strcat(dst,app),strcat(dst,app));
}
END_TEST





//MARK: - BUSERROR
//START_TEST(busError)
//{
//int a = busE();
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
    TCase *StrCatTest = tcase_create("STRCAT");
    
    
    
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
    tcase_add_test(MemCpyTest,MEMCPYTest2);
    
    
    
    suite_add_tcase(s1, StrCatTest);
    tcase_add_test(StrCatTest,STRCATTest1);
    tcase_add_test(StrCatTest,STRCATTest2);
    tcase_add_test(StrCatTest,STRCATTest3);
    tcase_add_test(StrCatTest,STRCATTest4);
    
    
    srunner_run_all(runner, CK_NORMAL );
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return number_failed == 0 ? 0 : 1;
}
