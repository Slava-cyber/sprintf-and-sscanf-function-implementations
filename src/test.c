#include<check.h>
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
//    //char *str = NULL;
//    ck_assert_msg(s21_strlen(NULL) == strlen(NULL), "Failed: Str == NULL");
}
END_TEST
START_TEST (STRLENTest5)
{
    char str[] = "lorem\\tipsum\\tdolor\\nsit\\namet\\n";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 32");
}
END_TEST
START_TEST (STRLENTest6)
{
    char str[] = "\n\n\f\r\t";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST
START_TEST (STRLENTest7)
{
    char str[] = "     ";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
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
    int ch = 'o';
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
}
END_TEST


START_TEST (STRCHRTest3)
{
    char str[] = "Hello world";
    int ch = 'c';
    ck_assert_ptr_eq(s21_strchr(str, ch),strchr(str,ch));
}
END_TEST

START_TEST (STRCHRTest4)
{
    char str[] = "Hello world";
    int ch = 'H';
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
}
END_TEST

START_TEST (STRCHRTest5)
{
    char str[] = "Hello world";
    int ch = '\0';
    ck_assert_str_eq(s21_strchr(str, ch),strchr(str,ch));
}
END_TEST

START_TEST (STRCHRTest6)
{
    char str[] = "";
    int ch = '\0';
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
//    char *str1 = NULL;
//    char *str2 = "1";
//    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1,str2), "Failed on 0");
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
//    char *src = NULL;
//    char *str = "123";
//    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 0");
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

START_TEST (STRCSPNTest6)
{
    char *src = "";
    char *str = "hi";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src,str), "Failed on 0");
}
END_TEST
START_TEST (STRCSPNTest7)
{
    char *src = "\0";
    char *str = "\0";
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

START_TEST (MEMCPYTest3)
{
    char *src = "HELLO";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest,src,5),memcpy(dest2,src,5),0);
}
END_TEST

START_TEST (MEMCPYTest4)
{
    char *src = "zy\0xw";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest,src,5),memcpy(dest2,src,5),0);
}
END_TEST
START_TEST (MEMCPYTest5)
{
    char *src = "zy\0xw";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest,src,5),memcpy(dest2,src,5),0);
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

START_TEST (STRCATTest5)
{
    char app[1024]="\0";
    char dst[1024]="\n\0";
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

START_TEST (MEMMOVETest2) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[5] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1, src, 0), memmove(dest2, src, 0), 0);
}
END_TEST

START_TEST (MEMMOVETest3) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[5] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1, src, 10), memmove(dest2, src, 10), 0);
}
END_TEST
START_TEST (MEMMOVETest4) {
    char dest1[10] = "";
    char dest2[10] = "";
    char src[5] = "so\0";
    ck_assert_mem_eq(s21_memmove(dest1, src, 10), memmove(dest2, src, 10), 0);
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

START_TEST (STRSTRTest4) {
    char str1[10] = "hello";
    char str2[10] = "hellp";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST (STRSTRTest5) {
    char str1[1024] = "hello sweet hello";
    char str2[10] = "hello";
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
    char str1[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1,'l', 5), memchr(str1, 'l', 5), 3);
}
END_TEST

START_TEST (MEMCHRTest5) {
    char str1[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1,'l', 0), memchr(str1, 'l', 0), 0);
}
END_TEST

START_TEST (MEMCHRTest6) {
    // char *str1= NULL;
    // ck_assert_msg(  s21_memchr(str1,'h', 5) == NULL, "Failed: Str == NULL");
}
END_TEST

//MARK: - STRCPY

START_TEST (STRCPYTest1) {
    char str[] = "Hello";
    char str1[15];
    char str2[15];
    s21_strcpy(str1,str);
    strcpy(str2,str);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST (STRCPYTest2) {

    char str[] = "";
    char str1[15];
    char str2[15];
    s21_strcpy(str1,str);
    strcpy(str2,str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST (STRCPYTest3) {

    char str[] = "";
    char str1[15] = "test";
    char str2[15] = "test";
    s21_strcpy(str1,str);
    strcpy(str2,str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST (STRCPYTest4) {

    char str[] = "Test";
    char str1[1024];
    char str2[1024];
    s21_strcpy(str1,str);
    strcpy(str2,str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

//MARK: - STRPBRK

START_TEST (STRPBRKTest1) {

    char *str = "this is a test";
    char *str1 = "this is a test";
    str1 = strpbrk(str1,"this");
    str = s21_strpbrk(str,"this");
    ck_assert_str_eq(str, str1);
}
END_TEST


START_TEST (STRPBRKTest2) {

    char *str = "this is a test";
    char *str1 = "this is a test";
    str1 = strpbrk(str1," ");
    str = s21_strpbrk(str," ");
    ck_assert_str_eq(str, str1);
}
END_TEST


START_TEST (STRPBRKTest3) {

    //    char *str = "this is a test";
    //    char *str1 = "this is a test";
    //    str1 = strpbrk(str1,"");
    //    str = s21_strpbrk(str,"");
    //    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST (STRPBRKTest4) {

    char *str = "this is a test, this is ...";
    char *str1 = "this is a test, this is ...";
    str1 = strpbrk(str1,"this");
    str = s21_strpbrk(str,"this");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST (STRPBRKTest5) {

    char *str = "this is a test, this is ...";
    char *str1 = "this is a test, this is ...";
    ck_assert_ptr_eq(s21_strpbrk(str,"prom"), strpbrk(str1,"prom"));
}
END_TEST

//MARK: - STRNCMP

START_TEST (STRNCMPTest1)
{
    char *str1 = "1234567890";
    char *str2 = "1234567890";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 1");
}
END_TEST

START_TEST (STRNCMPTest2)
{
    char *str1 = "1234567890";
    char *str2 = "1224567890";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 2");
}
END_TEST

START_TEST (STRNCMPTest3)
{
    char *str1 = "1224567890";
    char *str2 = "1234567890";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 3");
}
END_TEST

START_TEST (STRNCMPTest4)
{
    char *str1 = "";
    char *str2 = "";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 4");
}
END_TEST

START_TEST (STRNCMPTest5)
{
    char *str1 = "1224567890";
    char *str2 = "";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 5");
}
END_TEST

START_TEST (STRNCMPTest6)
{
    char *str1 = "122";
    char *str2 = "345";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 6");
}
END_TEST

START_TEST (STRNCMPTest7)
{
    char *str1 = "test\200";
    char *str2 = "test\0";
    ck_assert_msg(s21_strncmp(str1, str2, 6) == strncmp(str1, str2, 6), "Failed on 7");
}
END_TEST
START_TEST (STRNCMPTest8)
{
    char *str1 = "1224567890";
    char *str2 = "02";
    ck_assert_msg(s21_strncmp(str1, str2, 0) == strncmp(str1, str2, 0), "Failed on 8");
}
END_TEST

//MARK: - MEMSET

START_TEST (MEMSETTest1)
{
    char str1[15] = "1234567890";
    char str2[15] = "1234567890";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST (MEMSETTest2)
{
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST (MEMSETTest3)
{
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = 'q';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST (MEMSETTest4)
{
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = '1';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 5);
}
END_TEST

START_TEST (MEMSETTest5)
{
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "ewqewqewqewq";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST (MEMSETTest6)
{
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "qweqweqweqwe";
    int c = '\0';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST (MEMSETTest7)
{
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "qweqweqweqwe";
    int c = '\n';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

//MARK: -STRTOK

START_TEST (STRTOKTest1)
{
    char str[30] = "test1/test2/test3/test4";
    char delim = '/';

    ck_assert_msg(s21_strtok(str, &delim) == strtok(str, &delim), "Failed on 1");

}
END_TEST

START_TEST (STRTOKTest2)
{
    char str[30] = "test1/test2/test3/test4";
    char delim = ',';

    ck_assert_msg(s21_strtok(str, &delim) == strtok(str, &delim), "Failed on 2");

}
END_TEST

START_TEST (STRTOKTest3)
{
    char str[30] = "test1/test2/test3/test4";
    char delim = 'e';

    ck_assert_msg(s21_strtok(str, &delim) == strtok(str, &delim), "Failed on 3");

}
END_TEST

START_TEST (STRTOKTest4)
{
    char str[30] = "AadacAdxa";
    char delim = 'a';
    ck_assert_msg(s21_strtok(str, &delim) == strtok(str, &delim), "Failed on 4");
}
END_TEST

START_TEST (STRTOKTest5)
{
    char str[30] = "ased dse c sze wsew";
    char delim = 'e';
    ck_assert_msg(s21_strtok(str, &delim) == strtok(str, &delim), "Failed on 5");
}
END_TEST

START_TEST (STRTOKTest6)
{
    char str[30] = "test1,test2/test3.test4";
    char delim[] = ",/.";
    ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 6");
}
END_TEST


//MARK: - STRERROR
START_TEST (STRERRORTest1) {
    for (int i = -123; i < 0; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST (STRERRORTest2) {
    for (int i = 0; i <= 106; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST (STRERRORTest3) {
    for (int i = 107; i <= 234; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

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
    TCase *strpbrktest = tcase_create("STRPBRK");
    TCase *StrnCmpTest = tcase_create("STRNCMP");
    TCase *MemSetTest = tcase_create("MEMSET");
    TCase *StrTokTest = tcase_create("STRTOK");
    TCase *strerrortest = tcase_create("STRERROR");


    suite_add_tcase(s1, StrLenTest);
    tcase_add_test(StrLenTest, STRLENTest1);
    tcase_add_test(StrLenTest, STRLENTest2);
    tcase_add_test(StrLenTest, STRLENTest3);
    tcase_add_test(StrLenTest, STRLENTest4);
    tcase_add_test(StrLenTest, STRLENTest5);
    tcase_add_test(StrLenTest, STRLENTest6);
    tcase_add_test(StrLenTest, STRLENTest7);

    suite_add_tcase(s1, StrChrTest);
    tcase_add_test(StrChrTest, STRCHRTest1);
    tcase_add_test(StrChrTest, STRCHRTest2);
    tcase_add_test(StrChrTest, STRCHRTest3);
    tcase_add_test(StrChrTest, STRCHRTest4);
    tcase_add_test(StrChrTest, STRCHRTest5);
    tcase_add_test(StrChrTest, STRCHRTest6);


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
    tcase_add_test(StrсSpnTest,STRCSPNTest6);
    tcase_add_test(StrсSpnTest,STRCSPNTest7);

    suite_add_tcase(s1, MemCpyTest);
    tcase_add_test(MemCpyTest,MEMCPYTest1);
    tcase_add_test(MemCpyTest,MEMCPYTest2);
    tcase_add_test(MemCpyTest,MEMCPYTest3);
    tcase_add_test(MemCpyTest,MEMCPYTest4);
    tcase_add_test(MemCpyTest,MEMCPYTest5);

    suite_add_tcase(s1, StrCatTest);
    tcase_add_test(StrCatTest,STRCATTest1);
    tcase_add_test(StrCatTest,STRCATTest2);
    tcase_add_test(StrCatTest,STRCATTest3);
    tcase_add_test(StrCatTest,STRCATTest4);
    tcase_add_test(StrCatTest,STRCATTest5);

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
    tcase_add_test(memmovetest, MEMMOVETest2);
    tcase_add_test(memmovetest, MEMMOVETest3);
    tcase_add_test(memmovetest, MEMMOVETest4);

    suite_add_tcase(s1, strstrtest);
    tcase_add_test(strstrtest, STRSTRTest1);
    tcase_add_test(strstrtest, STRSTRTest2);
    tcase_add_test(strstrtest, STRSTRTest3);
    tcase_add_test(strstrtest, STRSTRTest4);
    tcase_add_test(strstrtest, STRSTRTest5);

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
    tcase_add_test(memchrtest, MEMCHRTest5);
    tcase_add_test(memchrtest, MEMCHRTest6);

    suite_add_tcase(s1, strcpytest);
    tcase_add_test(strcpytest, STRCPYTest1);
    tcase_add_test(strcpytest, STRCPYTest2);
    tcase_add_test(strcpytest, STRCPYTest3);
    tcase_add_test(strcpytest, STRCPYTest4);

    suite_add_tcase(s1, strpbrktest);
    tcase_add_test(strpbrktest, STRPBRKTest1);
    tcase_add_test(strpbrktest, STRPBRKTest2);
    tcase_add_test(strpbrktest, STRPBRKTest3);
    tcase_add_test(strpbrktest, STRPBRKTest4);
    tcase_add_test(strpbrktest, STRPBRKTest5);

    suite_add_tcase(s1, StrnCmpTest);
    tcase_add_test(StrnCmpTest, STRNCMPTest1);
    tcase_add_test(StrnCmpTest, STRNCMPTest2);
    tcase_add_test(StrnCmpTest, STRNCMPTest3);
    tcase_add_test(StrnCmpTest, STRNCMPTest4);
    tcase_add_test(StrnCmpTest, STRNCMPTest5);
    tcase_add_test(StrnCmpTest, STRNCMPTest6);
    tcase_add_test(StrnCmpTest, STRNCMPTest7);
    tcase_add_test(StrnCmpTest, STRNCMPTest8);

    suite_add_tcase(s1, MemSetTest);
    tcase_add_test(MemSetTest, MEMSETTest1);
    tcase_add_test(MemSetTest, MEMSETTest2);
    tcase_add_test(MemSetTest, MEMSETTest3);
    tcase_add_test(MemSetTest, MEMSETTest4);
    tcase_add_test(MemSetTest, MEMSETTest5);
    tcase_add_test(MemSetTest, MEMSETTest6);
    tcase_add_test(MemSetTest, MEMSETTest7);

    suite_add_tcase(s1, StrTokTest);
    tcase_add_test(StrTokTest, STRTOKTest1);
    tcase_add_test(StrTokTest, STRTOKTest2);
    tcase_add_test(StrTokTest, STRTOKTest3);
    tcase_add_test(StrTokTest, STRTOKTest4);
    tcase_add_test(StrTokTest, STRTOKTest5);
    tcase_add_test(StrTokTest, STRTOKTest6);

    suite_add_tcase(s1, strerrortest);
    tcase_add_test(strerrortest, STRERRORTest1);
    tcase_add_test(strerrortest, STRERRORTest2);
    tcase_add_test(strerrortest, STRERRORTest3);


    srunner_run_all(runner, CK_NORMAL );
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed == 0 ? 0 : 1;
}



