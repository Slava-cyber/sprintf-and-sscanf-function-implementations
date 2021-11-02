#include<check.h>
//#include<stdio.h>
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
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 4");
    
}
END_TEST

START_TEST (STRCSPNTest2)
{
    
    char *src = "0123456789";
    char *str = "e";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST


START_TEST (STRCSPNTest3)
{
    
    char *src = NULL;
    char *str = "123";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
}
END_TEST

START_TEST (STRCSPNTest4)
{
    
    char *src = "46";
    char *str = "123";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 2");
    
}
END_TEST

START_TEST (STRCSPNTest5)
{
    
    char *src = "HELLO";
    char *str = "HELLO";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 0");
    
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



//MARK: MEMCMP
START_TEST(MEMCMPTest1)
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    int n = 6;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest2)
{
    char str1[] = "Hello";
    char str2[] = "Help";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
    //    ck_assert_int_eq(s21_memcmp(str4,str3,n), 4);
    //    printf("[PASS] Test: str1 = Help; str2 = Hello; Result: 4\n\n");
}
END_TEST
START_TEST(MEMCMPTest3)
{
    char str1[] = "Help";
    char str2[] = "Hello";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest4)
{
    char str1[] = "Help";
    char str2[] = "Hello";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest5)
{
    char str1[] = "Hello";
    char str2[] = "";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest6)
{
    char str1[] = "";
    char str2[] = "";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest7)
{
    char str1[] = "gsafh";
    char str2[] = "dhkjfhs";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest8)
{
    char str1[] = "test\0test";
    char str2[] = "test";
    int n = 10;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest9)
{
    char str1[] = "test";
    char str2[] = "teSt";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(MEMCMPTest10)
{
    char str1[] = "t\200";
    char str2[] = "t\0";
    int n = 2;
    ck_assert_int_eq(s21_memcmp(str1,str2,n), memcmp(str1,str2,n));
}
END_TEST
START_TEST(STRNCATTest1)
{
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 6;
    ck_assert_str_eq(s21_strncat(str1,str2,n), strncat(str1,str2,n));
}
END_TEST

//MARK: STRNCAT
START_TEST(STRNCATTest2)
{
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 4;
    ck_assert_str_eq(s21_strncat(str1,str2,n), strncat(str1,str2,n));
}
END_TEST
START_TEST(STRNCATTest3)
{
    char str1[1024] = "";
    char str2[] = " HELLO";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1,str2,n), strncat(str1,str2,n));
}
END_TEST
START_TEST(STRNCATTest4)
{
    char str1[1024] = "HI, ";
    char str2[] = "HELL\0O";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1,str2,n), strncat(str1,str2,n));
}
END_TEST
START_TEST(STRNCATTest5)
{
    char str1[1024] = "\0";
    char str2[] = "H";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1,str2,n), strncat(str1,str2,n));
}
END_TEST

//MARK: STRNCPY

START_TEST(STRNCPYTest1)
{
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 6;
    ck_assert_str_eq(s21_strncpy(str1,str2,n), strncpy(str1,str2,n));
}
END_TEST
START_TEST(STRNCPYTest2)
{
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 4;
    ck_assert_str_eq(s21_strncpy(str1,str2,n), strncpy(str1,str2,n));
}
END_TEST
START_TEST(STRNCPYTest3)
{
    char str1[1024] = "";
    char str2[] = " HELLO";
    int n = 5;
    ck_assert_str_eq(s21_strncpy(str1,str2,n), strncpy(str1,str2,n));
    //    char s3[15] = "HI, ";
    //    char s4[] = "HELL\0O";
    //    size = 5;
    //    ck_assert_str_eq(s21_strncpy(s3,s4,size), "HELL");
    //    printf("[PASS] Test: str1 = HI, ; str2 = HELL\\0O; size = 5; Result: HELL\n\n");
}
END_TEST
START_TEST(STRNCPYTest4)
{
    char str1[1024] = "HI, ";
    char str2[] = " HELL\0O";
    int n = 5;
    ck_assert_str_eq(s21_strncpy(str1,str2,n), strncpy(str1,str2,n));
}
END_TEST
START_TEST(STRNCPYTest5)
{
    char str1[1024] = "HI, ";
    char str2[] = " HELLO";
    int n = 20;
    ck_assert_str_eq(s21_strncpy(str1,str2,n), strncpy(str1,str2,n));
}
END_TEST

//MARK: -STRRCHR
START_TEST(STRRCHRTest1)
{
    char str1[] = "Hello, Mel";
    int c = 'e';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest2)
{
    char str1[] = "Hello, Mel";
    int c = 'p';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest3)
{
    char str1[] = "";
    int c = 'l';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest4)
{
    char str1[] = "Hello";
    int c = 0;
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest5)
{
    char str1[] = "Hello";
    int c = 'o';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

//MARK:MEMMOVE
START_TEST (MEMMOVETest1) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[5] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1+2, src+2, 3), memmove(dest2, src+2, 3), 5);
}
END_TEST

// MARK:STRSTR
START_TEST (STRSTRTest1) {
    char str1[10] = "hello";
    char str2[10] = "he";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST (STRSTRTest2) {
    char str1[10] = "hello";
    char str2[10] = "";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST (STRSTRTest3) {
    char str1[10] = "hello";
    char str2[10] = "qw";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

//MARK: STRCMP
START_TEST (STRCMPTest1) {
    char str1[10] = "hello";
    char str2[10] = "hello";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST (STRCMPTest2) {
    char str1[10] = "hello";
    char str2[10] = "hellq";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST (STRCMPTest3) {
    char str1[10] = "hello";
    char str2[10] = "helle";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST (STRCMPTest4) {
    char str1[10] = "hello";
    char str2[10] = "";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST (STRCMPTest5) {
    char str1[10] = "";
    char str2[10] = "hello";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST (STRCMPTest6) {
    char str1[10] = "";
    char str2[10] = "";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

// MARK: STRERROR
//START_TEST (STRERRORTest1) {
//    int i = -1;
//    ck_assert_str_eq(s21_strerror(i), strerror(i));
//}
//END_TEST
//
//START_TEST (STRERRORTest2) {
//    for (int i = 0; i <= 106; i++) {
//        ck_assert_str_eq(s21_strerror(i), strerror(i));
//    }
//}
//END_TEST
//
//START_TEST (STRERRORTest3) {
//    int i = 2120;
//    ck_assert_str_eq(s21_strerror(i), strerror(i));
//}
//END_TEST


//MARK: - MEMCHR

START_TEST (MEMCHRTest1) {
    char str1[10] = "Hello";
    
    ck_assert_mem_eq(s21_memchr(str1,'H', 5), memchr(str1, 'H', 5), 5);
}
END_TEST


START_TEST (MEMCHRTest2) {
    char str1[10] = "Hello";
    
    ck_assert_msg(  s21_memchr(str1,'h', 5) == NULL, "Failed: Str == NULL");
}
END_TEST


START_TEST (MEMCHRTest3) {
    char str1[10] = "Hellosdsfq";
    
    ck_assert_msg(  s21_memchr(str1,'h', 5) == NULL, "Failed: Str == NULL");
}
END_TEST


START_TEST (MEMCHRTest4) {
    char *str1= NULL;
    
    ck_assert_msg(  s21_memchr(str1,'h', 5) == NULL, "Failed: Str == NULL");
}
END_TEST





//MARK: - STRCPY

START_TEST (STRCPYTest1) {
    char str[] = "Hello";
    char str1[15];
    char str2[15];
    
    ck_assert_str_eq(s21_strcpy(str1,str), strcpy(str2,str));
}
END_TEST


START_TEST (STRCPYTest2) {
//    char str[] = "Hello";
//    char str2[] = "GGG";
//
//    ck_assert_msg(s21_strcpy(str2,str),strcpy(str2,str), "Failed: Str == NULL");
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
    TCase *MemcmpTest = tcase_create("MEMCMP");
    TCase *StrncatTest = tcase_create("STRNCAT");
    TCase *StrncpyTest = tcase_create("STRNCPY");
    TCase *StrrchrTest = tcase_create("STRRCHR");
    TCase *memmovetest = tcase_create("MEMMOVE");
    TCase *strstrtest = tcase_create("STRSTR");
    TCase *strcmptest = tcase_create("STRCMP");
    TCase *memchrtest = tcase_create("MEMCHR");
    TCase *strcpytest = tcase_create("STRCPY");
//    TCase *strerrortest = tcase_create("STRERROR");
    
    
    
    
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
    
    
    suite_add_tcase(s1, MemcmpTest);
    tcase_add_test(MemcmpTest, MEMCMPTest1);
    tcase_add_test(MemcmpTest, MEMCMPTest2);
    tcase_add_test(MemcmpTest, MEMCMPTest3);
    tcase_add_test(MemcmpTest, MEMCMPTest4);
    tcase_add_test(MemcmpTest, MEMCMPTest5);
    tcase_add_test(MemcmpTest, MEMCMPTest6);
    tcase_add_test(MemcmpTest, MEMCMPTest7);
    tcase_add_test(MemcmpTest, MEMCMPTest8);
    tcase_add_test(MemcmpTest, MEMCMPTest9);
    tcase_add_test(MemcmpTest, MEMCMPTest10);
    
    suite_add_tcase(s1, StrncatTest);
    tcase_add_test(StrncatTest, STRNCATTest1);
    tcase_add_test(StrncatTest, STRNCATTest2);
    tcase_add_test(StrncatTest, STRNCATTest3);
    tcase_add_test(StrncatTest, STRNCATTest4);
    tcase_add_test(StrncatTest, STRNCATTest5);
    
    suite_add_tcase(s1, StrncpyTest);
    tcase_add_test(StrncpyTest, STRNCPYTest1);
    tcase_add_test(StrncpyTest, STRNCPYTest2);
    tcase_add_test(StrncpyTest, STRNCPYTest3);
    tcase_add_test(StrncpyTest, STRNCPYTest4);
    tcase_add_test(StrncpyTest, STRNCPYTest5);
    
    suite_add_tcase(s1, StrrchrTest);
    tcase_add_test(StrrchrTest, STRRCHRTest1);
    tcase_add_test(StrrchrTest, STRRCHRTest2);
    tcase_add_test(StrrchrTest, STRRCHRTest3);
    tcase_add_test(StrrchrTest, STRRCHRTest4);
    tcase_add_test(StrrchrTest, STRRCHRTest5);
    
    suite_add_tcase(s1, memmovetest);
    tcase_add_test(memmovetest, MEMMOVETest1);
    
    suite_add_tcase(s1, strstrtest);
    tcase_add_test(strstrtest, STRSTRTest1);
    tcase_add_test(strstrtest, STRSTRTest2);
    tcase_add_test(strstrtest, STRSTRTest3);
    
    suite_add_tcase(s1, strcmptest);
    tcase_add_test(strcmptest, STRCMPTest1);
    tcase_add_test(strcmptest, STRCMPTest2);
    tcase_add_test(strcmptest, STRCMPTest3);
    tcase_add_test(strcmptest, STRCMPTest4);
    tcase_add_test(strcmptest, STRCMPTest5);
    tcase_add_test(strcmptest, STRCMPTest6);
    
    suite_add_tcase(s1, memchrtest);
    tcase_add_test(memchrtest, MEMCHRTest1);
    tcase_add_test(memchrtest, MEMCHRTest2);
    tcase_add_test(memchrtest, MEMCHRTest3);
    tcase_add_test(memchrtest, MEMCHRTest4);
    
    
    
    suite_add_tcase(s1, strcpytest);
    tcase_add_test(strcpytest, STRCPYTest1);
    tcase_add_test(strcpytest, STRCPYTest2);
//    suite_add_tcase(s1, strerrortest);
//    tcase_add_test(strerrortest, STRERRORTest1);
//    tcase_add_test(strerrortest, STRERRORTest2);
//    tcase_add_test(strerrortest, STRERRORTest3);
//
    
    
    
    srunner_run_all(runner, CK_NORMAL );
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return number_failed == 0 ? 0 : 1;
}
