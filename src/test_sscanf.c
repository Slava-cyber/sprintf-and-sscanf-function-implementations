#include <check.h>
#include <string.h>
#include <stdio.h>
#include "s21_string.h"


// MARK: - lashlyn
START_TEST(SSCANFTestLashlyn1) {
    int num1;
    int num2;
    s21_sscanf("123", "%d", &num1);
    sscanf("123", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn2) {
    int num1;
    int num2;
    s21_sscanf("123", "%10d", &num1);
    sscanf("123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn3) {
    int num1;
    int num2;
    s21_sscanf("-123", "%10d", &num1);
    sscanf("-123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn4) {
    int num1;
    int num2;
    s21_sscanf("-123", "%10d", &num1);
    sscanf("-123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn5) {
    int num1;
    int num2;
    s21_sscanf("-123", "%d", &num1);
    sscanf("-123", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST


START_TEST(SSCANFTestLashlyn6) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("-123", "%1d", &num1);
    sscanf("-123", "%1d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST




START_TEST(SSCANFTestLashlyn7) {
    int num1;
    int num2;
    s21_sscanf("123", "%1d", &num1);
    sscanf("123", "%1d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn8) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("||||||123|||---dqwdsc23;;;alq.vmfj", "%d", &num1);
    sscanf("||||||123|||---dqwdsc23;;;alq.vmfj", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST


START_TEST(SSCANFTestLashlyn9) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("qwe|||---dqwdsc23;;;alq.vmfj", "%d", &num1);
    sscanf("qwe|||---dqwdsc23;;;alq.vmfj", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn10) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("        'ds;fsdlsdfks;df", "%4d", &num1);
    sscanf("        'ds;fsdlsdfks;df", "%4d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn11) {
    int num1;
    int num2;
    char a, b;
    s21_sscanf("123 qwe", "%4d%c", &num1, &a);
    sscanf("123 qwe", "%4d%c", &num2, &b);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn12) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("123 123", "%*d%d", &num1);
    sscanf("123 123", "%*d%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn13) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("as q12", "%*d%d", &num1);
    sscanf("fd qwe", "%*d%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn14) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("as q12", "%*i%i", &num1);
    sscanf("fd qwe", "%*i%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn15) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123214214 q12", "%*i%i", &num1);
    sscanf("123214214 qwe", "%*i%i", &num2);
    ck_assert_int_eq(num1, num2);
}

END_TEST


START_TEST(SSCANFTestLashlyn16) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123214214", "%i", &num1);
    sscanf("123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn17) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-123214214", "%i", &num1);
    sscanf("-123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn18) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("-123214214", "%i", &num1);
    sscanf("-123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn19) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("qwdwq wef 123", "%i", &num1);
    sscanf("qwdwq wef 123", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLashlyn20) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST


START_TEST(SSCANFTestLashlyn21) {
    int num1 = 0;
    int num2 = 0;
    int c = s21_sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    int b =  sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(c, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn22) {
    int num1 = 0;
    int num2 = 0;
    int c = s21_sscanf("  -0124214124 jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    int b =  sscanf("  -0124214124 jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(c, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn23) {
    char a;
    char b;
    s21_sscanf("qwd", "%c", &a);
    sscanf("qwd", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn24) {
    char a;
    char b;
    s21_sscanf("qwd", "%c", &a);
    sscanf("qwd", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLashlyn25) {
    char a;
    char b;
    s21_sscanf("f", "%c", &a);
    sscanf("f", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn26) {
    char a;
    char b;
    s21_sscanf(" ", "%c", &a);
    sscanf(" ", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn27) {
    char a;
    char b;
    s21_sscanf("123", "%1c", &a);
    sscanf("123", "%1c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn28) {
    char a;
    char b;
    s21_sscanf(" 1", "%1c", &a);
    sscanf(" 1", "%1c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn29) {
    char a[1024] = "HEllo";
    char b[1024] = "HEllo";
    s21_sscanf("HEllo", "%s", a);
    sscanf("HEllo", "%s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn30) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf("HEllo", "%2s", a);
    sscanf("HEllo", "%2s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn31) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf("123 123", "%2s", a);
    sscanf("123 123", "%2s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn32) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn33) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn34) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn35) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn36) {
    //
    float a = 0;
    float b = 0;
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10f", &a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn37) {
    float a = 0;
    float b = 0;
    s21_sscanf("12.213213123", "%1f", &a);
    sscanf("12.213213123", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn38) {
    //
    float a = 0;
    float b = 0;
    s21_sscanf("-12.213213123", "%1f", &a);
    sscanf("-12.213213123", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn39) {
    float a = 0;
    float b = 0;
    s21_sscanf("-12.2132131231qwd", "%1f", &a);
    sscanf("-12.2132131231qwd", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn40) {
    //
    float a = 0;
    float b = 0;
    s21_sscanf("0.00000000000001", "%1f", &a);
    sscanf("0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn41) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.00000000000001", "%1f", &a);
    sscanf("0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn42) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000000001", "%1f", &a);
    sscanf("-0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn43) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%1f", &a);
    sscanf("-0.0000000000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn44) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%10f", &a);
    sscanf("-0.0000000000000000001", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn45) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%10f", &a);
    sscanf("-0.0000000000000000001", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn46) {
    float a = 0;
    float b = 0;
    s21_sscanf("1123.2332", "%10e", &a);
    sscanf("1123.2332", "%10e", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn47) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%10e", &a);
    sscanf("-1123.2332", "%10e", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn48) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%E", &a);
    sscanf("-1123.2332", "%E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn49) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000000001", "%15E", &a);
    sscanf("0.0000000000000001", "%15E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLashlyn50) {
    float a = 0;
    float b = 0;
    s21_sscanf("1E42", "%E", &a);
    sscanf("1E42", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn51) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%E", &a);
    sscanf("1e42", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn52) {
    float a = 0;
    float b = 0;
    s21_sscanf("1123.2332", "%10E", &a);
    sscanf("1123.2332", "%10E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn53) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%10E", &a);
    sscanf("-1123.2332", "%10E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn54) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%E", &a);
    sscanf("-1123.2332", "%E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn55) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000000001", "%15E", &a);
    sscanf("0.0000000000000001", "%15E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLashlyn56) {
    float a = 0;
    float b = 0;
    s21_sscanf("1E42", "%e", &a);
    sscanf("1E42", "%e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn57) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%e", &a);
    sscanf("1e42", "%e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn58) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%g", &a);
    sscanf("1e42", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn59) {
    float a = 0;
    float b = 0;
    s21_sscanf("_+)-=p//./.?>./[p=.['1e42", "%g", &a);
    sscanf("_+)-=p//./.?>./[p=.['1e42", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLashlyn60) {
    float a = 0;
    float b = 0;
    s21_sscanf("3.141592653589793238462643383279502 _+)-=p//./.?>./[p=.['1e42", "%g", &a);
    sscanf("3.141592653589793238462643383279502 _+)-=p//./.?>./[p=.['1e42", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLashlyn61) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000001", "%g", &a);
    sscanf("0.0000000000001", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn62) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%g", &a);
    sscanf("-0.0000000000000001", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn63) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%15g", &a);
    sscanf("-0.0000000000000001", "%15g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn64) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%1g", &a);
    sscanf("-0.0000000000000001", "%1g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn65) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000001", "%G", &a);
    sscanf("-0.00000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn66) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000001", "%G", &a);
    sscanf("0.0000000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn67) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%G", &a);
    sscanf("-0.0000000000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn68) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%15G", &a);
    sscanf("-0.0000000000000001", "%15G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn69) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%1G", &a);
    sscanf("-0.0000000000000001", "%1G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn70) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000001", "%G", &a);
    sscanf("-0.00000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn71) {
    int a = 0;
    int b = 0;
    s21_sscanf("124", "%o", &a);
    sscanf("124", "%o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn72) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%o", &a);
    sscanf("-124", "%o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLashlyn73) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%10o", &a);
    sscanf("-124", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn74) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%10o", &a);
    sscanf("-124", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn75) {
    int a = 0;
    int b = 0;
    s21_sscanf("1", "%10o", &a);
    sscanf("1", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn76) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf("1", "%u", &a);
    sscanf("1", "%u", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTestLashlyn77) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf(" +123", "%u", &a);
    sscanf(" +123", "%u", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLashlyn78) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf("123", "%n", &a);
    sscanf("123", "%n", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

// MARK: - Laerion

START_TEST(SSCANFTestLaerion1) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123", "%x", &num1);
    sscanf("123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion2) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%3x", &num1);
    sscanf("123123", "%3x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion3) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%10x", &num1);
    sscanf("123123", "%10x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion4) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*x%x", &num1);
    sscanf("123 123", "%*x%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion5) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*x%d", &num1);
    sscanf("123 123", "%*x%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion6) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0x123 123", "%x", &num1);
    sscanf("0x123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion7) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0123 123", "%x", &num1);
    sscanf("0123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion8) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0X123 123", "%x", &num1);
    sscanf("0X123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion9) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-0X123 123", "%x", &num1);
    sscanf("-0X123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion10) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("qwe 123", "%x", &num1);
    sscanf("qwe 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion11) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCDEF 123", "%x", &num1);
    sscanf("ABCDEF 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion12) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCQADEF 123", "%x", &num1);
    sscanf("ABCQADEF 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion13) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("ABCDEF -A123", "%x%x", &num1, &num3);
    sscanf("ABCDEF -A123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion14) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("228228228 -A123", "%x%x", &num1, &num3);
    sscanf("228228228 -A123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion15) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+000123ABC -0123", "%x%x", &num1, &num3);
    sscanf("+000123ABC -0123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion16) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+0001§../23ABC -0mxzcmmz123q", "%x%x", &num1, &num3);
    sscanf("+0001§../23ABC -0mxzcmmz123q", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion17) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+123", "%x%x", &num1, &num3);
    sscanf("+123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion18) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("  000  000   ", "%x%x", &num1, &num3);
    sscanf("  000  000   ", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion19) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("120x211 0x", "%x%x", &num1, &num3);
    sscanf("120x211 0x", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion20) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("120x211 0x", "%x%s", &num1, s1);
    sscanf("120x211 0x", "%x%s", &num2, s2);
    ck_assert_int_eq(num1, num2);
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTestLaerion21) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("x120x211 0x", "%x", &num1);
    sscanf("x120x211 0x", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion22) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x211. 29", "%x%f", &num1, &f1);
    sscanf("x120x211. 29", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion23) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x21.1 2.9", "%x%f", &num1, &f1);
    sscanf("x120x21.1 2.9", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion24) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x-120x.21 12.9", "%x%f", &num1, &f1);
    sscanf("x-120x.21 12.9", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion25) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("2.9 020abxC21.1", "%x%f", &num1, &f1);
    sscanf("2.9 020abxC21.1", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion26) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123", "%X", &num1);
    sscanf("123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion27) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%3X", &num1);
    sscanf("123123", "%3X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion28) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%10X", &num1);
    sscanf("123123", "%10X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion29) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*X%X", &num1);
    sscanf("123 123", "%*X%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion30) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*X%d", &num1);
    sscanf("123 123", "%*X%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion31) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0x123 123", "%X", &num1);
    sscanf("0x123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion32) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0123 123", "%X", &num1);
    sscanf("0123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion33) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0X123 123", "%X", &num1);
    sscanf("0X123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion34) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-0X123 123", "%X", &num1);
    sscanf("-0X123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion35) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("qwe 123", "%X", &num1);
    sscanf("qwe 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion36) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCDEF 123", "%X", &num1);
    sscanf("ABCDEF 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion37) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCQADEF 123", "%X", &num1);
    sscanf("ABCQADEF 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion38) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("ABCDEF -A123", "%X%X", &num1, &num3);
    sscanf("ABCDEF -A123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion39) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("228228228 -A123", "%X%X", &num1, &num3);
    sscanf("228228228 -A123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion40) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+000123ABC -0123", "%X%X", &num1, &num3);
    sscanf("+000123ABC -0123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion41) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+0001§../23ABC -0mxzcmmz123q", "%X%X", &num1, &num3);
    sscanf("+0001§../23ABC -0mxzcmmz123q", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion42) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+123", "%X%X", &num1, &num3);
    sscanf("+123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion43) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("  000  000   ", "%X%X", &num1, &num3);
    sscanf("  000  000   ", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion44) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("120x211 0x", "%X%X", &num1, &num3);
    sscanf("120x211 0x", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTestLaerion45) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("120x211 0x", "%X%s", &num1, s1);
    sscanf("120x211 0x", "%X%s", &num2, s2);
    ck_assert_int_eq(num1, num2);
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTestLaerion46) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("x120x211 0x", "%X", &num1);
    sscanf("x120x211 0x", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion47) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x211. 29", "%X%f", &num1, &f1);
    sscanf("x120x211. 29", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion48) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x21.1 2.9", "%X%f", &num1, &f1);
    sscanf("x120x21.1 2.9", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion49) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x-120x.21 12.9", "%X%f", &num1, &f1);
    sscanf("x-120x.21 12.9", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion50) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("2.9 020abxC21.1", "%X%f", &num1, &f1);
    sscanf("2.9 020abxC21.1", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTestLaerion51) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("123", "%p", &p1);
    sscanf("123", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion52) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%p", &p1);
    sscanf("abc12g3", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion53) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%3p", &p1);
    sscanf("abc12g3", "%3p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion54) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3 abc22", "%*p%p", &p1);
    sscanf("abc12g3 abc22", "%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion55) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf(" abc12g3 abc22", " %*p%p", &p1);
    sscanf(" abc12g3 abc22", " %*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion56) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf(" abc12g3 abc22", "-%*p%p", &p1);
    sscanf(" abc12g3 abc22", "-%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST





START_TEST(SSCANFTestLaerion57) {
    char a, b;
    s21_sscanf("e", "%10c", &a);
    sscanf("e", "%10c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLaerion58) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("+123", "%p", &a);
    sscanf("+123", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLaerion59) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("0x0X", "%p", &a);
    sscanf("0x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SSCANFTestLaerion60) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("x0X", "%p", &a);
    sscanf("x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST
START_TEST(SSCANFTestLaerion61) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("-x0X", "%p", &a);
    sscanf("-x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST



START_TEST(SSCANFTestLaerion62) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("123", "%p", &p1);
    sscanf("123", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion63) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("abc12g3", "%p", &p1);
    sscanf("abc12g3", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion64) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("abc12g3", "%3p", &p1);
    sscanf("abc12g3", "%3p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion65) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("abc12g3 abc22", "%*p%p", &p1);
    sscanf("abc12g3 abc22", "%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTestLaerion66) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];

    s21_sscanf("abc12g3 abc22", "%p%s", &p1, s1);
    sscanf("abc12g3 abc22", "%p%s", &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTestLaerion67) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];

    s21_sscanf("abc12g3 abc22", "%s%p", s1, &p1);
    sscanf("abc12g3 abc22", "%s%p", s2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTestLaerion68) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];

    s21_sscanf("  abc12g3    abc22  ", "%s%p", s1, &p1);
    sscanf("  abc12g3    abc22  ", "%s%p", s2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTestLaerion69) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 0000 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 0000 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion70) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 0x123cc 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 0x123cc 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion71) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 030xcc 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 030xcc 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion72) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 123ab±=-1//a 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 123ab±=-1//a 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion73) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 123ab±=-1//a 12", "%d%p", &num1, &p1);
    sscanf("abc12g3 123ab±=-1//a 12", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion74) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc1 2g3 12 3ab±=-1// a 12", "%d%p", &num1, &p1);
    sscanf("abc1 2g3 12 3ab±=-1// a 12", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion75) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("", "%d%p", &num1, &p1);
    sscanf("", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion76) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("10 abcdef123 qwe", "%d%4p%s", &num1, &p1, s1);
    sscanf("10 abcdef123 qwe", "%d%4p%s", &num2, &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTestLaerion77) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("10 abcdef123 qwe", "%d%1p%s", &num1, &p1, s1);
    sscanf("10 abcdef123 qwe", "%d%1p%s", &num2, &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

Suite *sscanf_suite_create() {
    Suite *s1 = suite_create("Test_sscanf");
    TCase *sscanftest = tcase_create("SSCANF1");
    TCase *sscanftest2 = tcase_create("SSCANF2");
    suite_add_tcase(s1, sscanftest);
    suite_add_tcase(s1, sscanftest2);
    tcase_add_test(sscanftest, SSCANFTestLashlyn1);
    tcase_add_test(sscanftest, SSCANFTestLashlyn2);
    tcase_add_test(sscanftest, SSCANFTestLashlyn3);
    tcase_add_test(sscanftest, SSCANFTestLashlyn4);
    tcase_add_test(sscanftest, SSCANFTestLashlyn5);
    tcase_add_test(sscanftest, SSCANFTestLashlyn6);
    tcase_add_test(sscanftest, SSCANFTestLashlyn7);
    tcase_add_test(sscanftest, SSCANFTestLashlyn8);
    tcase_add_test(sscanftest, SSCANFTestLashlyn9);
    tcase_add_test(sscanftest, SSCANFTestLashlyn10);
    tcase_add_test(sscanftest, SSCANFTestLashlyn11);
    tcase_add_test(sscanftest, SSCANFTestLashlyn12);
    tcase_add_test(sscanftest, SSCANFTestLashlyn13);
    tcase_add_test(sscanftest, SSCANFTestLashlyn14);
    tcase_add_test(sscanftest, SSCANFTestLashlyn15);
    tcase_add_test(sscanftest, SSCANFTestLashlyn16);
    tcase_add_test(sscanftest, SSCANFTestLashlyn17);
    tcase_add_test(sscanftest, SSCANFTestLashlyn18);
    tcase_add_test(sscanftest, SSCANFTestLashlyn19);
    tcase_add_test(sscanftest, SSCANFTestLashlyn20);
    tcase_add_test(sscanftest, SSCANFTestLashlyn21);
    tcase_add_test(sscanftest, SSCANFTestLashlyn22);
    tcase_add_test(sscanftest, SSCANFTestLashlyn23);
    tcase_add_test(sscanftest, SSCANFTestLashlyn24);
    tcase_add_test(sscanftest, SSCANFTestLashlyn25);
    tcase_add_test(sscanftest, SSCANFTestLashlyn26);
    tcase_add_test(sscanftest, SSCANFTestLashlyn27);
    tcase_add_test(sscanftest, SSCANFTestLashlyn28);
    tcase_add_test(sscanftest, SSCANFTestLashlyn29);
    tcase_add_test(sscanftest, SSCANFTestLashlyn30);
    tcase_add_test(sscanftest, SSCANFTestLashlyn31);
    tcase_add_test(sscanftest, SSCANFTestLashlyn32);
    tcase_add_test(sscanftest, SSCANFTestLashlyn33);
    tcase_add_test(sscanftest, SSCANFTestLashlyn34);
    tcase_add_test(sscanftest, SSCANFTestLashlyn35);
    tcase_add_test(sscanftest, SSCANFTestLashlyn36);
    tcase_add_test(sscanftest, SSCANFTestLashlyn37);
    tcase_add_test(sscanftest, SSCANFTestLashlyn38);
    tcase_add_test(sscanftest, SSCANFTestLashlyn39);
    tcase_add_test(sscanftest, SSCANFTestLashlyn40);
    tcase_add_test(sscanftest, SSCANFTestLashlyn41);
    tcase_add_test(sscanftest, SSCANFTestLashlyn42);
    tcase_add_test(sscanftest, SSCANFTestLashlyn43);
    tcase_add_test(sscanftest, SSCANFTestLashlyn44);
    tcase_add_test(sscanftest, SSCANFTestLashlyn45);
    tcase_add_test(sscanftest, SSCANFTestLashlyn46);
    tcase_add_test(sscanftest, SSCANFTestLashlyn47);
    tcase_add_test(sscanftest, SSCANFTestLashlyn48);
    tcase_add_test(sscanftest, SSCANFTestLashlyn49);
    tcase_add_test(sscanftest, SSCANFTestLashlyn50);
    tcase_add_test(sscanftest, SSCANFTestLashlyn51);
    tcase_add_test(sscanftest, SSCANFTestLashlyn52);
    tcase_add_test(sscanftest, SSCANFTestLashlyn53);
    tcase_add_test(sscanftest, SSCANFTestLashlyn54);
    tcase_add_test(sscanftest, SSCANFTestLashlyn55);
    tcase_add_test(sscanftest, SSCANFTestLashlyn56);
    tcase_add_test(sscanftest, SSCANFTestLashlyn57);
    tcase_add_test(sscanftest, SSCANFTestLashlyn58);
    tcase_add_test(sscanftest, SSCANFTestLashlyn59);
    tcase_add_test(sscanftest, SSCANFTestLashlyn60);
    tcase_add_test(sscanftest, SSCANFTestLashlyn61);
    tcase_add_test(sscanftest, SSCANFTestLashlyn62);
    tcase_add_test(sscanftest, SSCANFTestLashlyn63);
    tcase_add_test(sscanftest, SSCANFTestLashlyn64);
    tcase_add_test(sscanftest, SSCANFTestLashlyn65);
    tcase_add_test(sscanftest, SSCANFTestLashlyn66);
    tcase_add_test(sscanftest, SSCANFTestLashlyn67);
    tcase_add_test(sscanftest, SSCANFTestLashlyn68);
    tcase_add_test(sscanftest, SSCANFTestLashlyn69);
    tcase_add_test(sscanftest, SSCANFTestLashlyn70);
    tcase_add_test(sscanftest, SSCANFTestLashlyn71);
    tcase_add_test(sscanftest, SSCANFTestLashlyn72);
    tcase_add_test(sscanftest, SSCANFTestLashlyn73);
    tcase_add_test(sscanftest, SSCANFTestLashlyn74);
    tcase_add_test(sscanftest, SSCANFTestLashlyn75);
    tcase_add_test(sscanftest, SSCANFTestLashlyn76);
    tcase_add_test(sscanftest, SSCANFTestLashlyn77);
    tcase_add_test(sscanftest, SSCANFTestLashlyn78);

    tcase_add_test(sscanftest2, SSCANFTestLaerion1);
    tcase_add_test(sscanftest2, SSCANFTestLaerion2);
    tcase_add_test(sscanftest2, SSCANFTestLaerion3);
    tcase_add_test(sscanftest2, SSCANFTestLaerion4);
    tcase_add_test(sscanftest2, SSCANFTestLaerion5);
    tcase_add_test(sscanftest2, SSCANFTestLaerion6);
    tcase_add_test(sscanftest2, SSCANFTestLaerion7);
    tcase_add_test(sscanftest2, SSCANFTestLaerion8);
    tcase_add_test(sscanftest2, SSCANFTestLaerion9);
    tcase_add_test(sscanftest2, SSCANFTestLaerion10);
    tcase_add_test(sscanftest2, SSCANFTestLaerion11);
    tcase_add_test(sscanftest2, SSCANFTestLaerion12);
    tcase_add_test(sscanftest2, SSCANFTestLaerion13);
    tcase_add_test(sscanftest2, SSCANFTestLaerion14);
    tcase_add_test(sscanftest2, SSCANFTestLaerion15);
    tcase_add_test(sscanftest2, SSCANFTestLaerion16);
    tcase_add_test(sscanftest2, SSCANFTestLaerion17);
    tcase_add_test(sscanftest2, SSCANFTestLaerion18);
    tcase_add_test(sscanftest2, SSCANFTestLaerion19);
    tcase_add_test(sscanftest2, SSCANFTestLaerion20);
    tcase_add_test(sscanftest2, SSCANFTestLaerion21);
    tcase_add_test(sscanftest2, SSCANFTestLaerion22);
    tcase_add_test(sscanftest2, SSCANFTestLaerion23);
    tcase_add_test(sscanftest2, SSCANFTestLaerion24);
    tcase_add_test(sscanftest2, SSCANFTestLaerion25);
    tcase_add_test(sscanftest2, SSCANFTestLaerion26);
    tcase_add_test(sscanftest2, SSCANFTestLaerion27);
    tcase_add_test(sscanftest2, SSCANFTestLaerion28);
    tcase_add_test(sscanftest2, SSCANFTestLaerion29);
    tcase_add_test(sscanftest2, SSCANFTestLaerion30);
    tcase_add_test(sscanftest2, SSCANFTestLaerion31);
    tcase_add_test(sscanftest2, SSCANFTestLaerion32);
    tcase_add_test(sscanftest2, SSCANFTestLaerion33);
    tcase_add_test(sscanftest2, SSCANFTestLaerion34);
    tcase_add_test(sscanftest2, SSCANFTestLaerion35);
    tcase_add_test(sscanftest2, SSCANFTestLaerion36);
    tcase_add_test(sscanftest2, SSCANFTestLaerion37);
    tcase_add_test(sscanftest2, SSCANFTestLaerion38);
    tcase_add_test(sscanftest2, SSCANFTestLaerion39);
    tcase_add_test(sscanftest2, SSCANFTestLaerion40);
    tcase_add_test(sscanftest2, SSCANFTestLaerion41);
    tcase_add_test(sscanftest2, SSCANFTestLaerion42);
    tcase_add_test(sscanftest2, SSCANFTestLaerion43);
    tcase_add_test(sscanftest2, SSCANFTestLaerion44);
    tcase_add_test(sscanftest2, SSCANFTestLaerion45);
    tcase_add_test(sscanftest2, SSCANFTestLaerion46);
    tcase_add_test(sscanftest2, SSCANFTestLaerion47);
    tcase_add_test(sscanftest2, SSCANFTestLaerion48);
    tcase_add_test(sscanftest2, SSCANFTestLaerion49);
    tcase_add_test(sscanftest2, SSCANFTestLaerion50);
    tcase_add_test(sscanftest2, SSCANFTestLaerion51);
    tcase_add_test(sscanftest2, SSCANFTestLaerion52);
    tcase_add_test(sscanftest2, SSCANFTestLaerion53);
    tcase_add_test(sscanftest2, SSCANFTestLaerion54);
    tcase_add_test(sscanftest2, SSCANFTestLaerion55);
    tcase_add_test(sscanftest2, SSCANFTestLaerion56);
    tcase_add_test(sscanftest2, SSCANFTestLaerion57);
    tcase_add_test(sscanftest2, SSCANFTestLaerion58);
    tcase_add_test(sscanftest2, SSCANFTestLaerion59);
    tcase_add_test(sscanftest2, SSCANFTestLaerion60);
    tcase_add_test(sscanftest2, SSCANFTestLaerion61);
    tcase_add_test(sscanftest2, SSCANFTestLaerion62);
    tcase_add_test(sscanftest2, SSCANFTestLaerion62);
    tcase_add_test(sscanftest2, SSCANFTestLaerion63);
    tcase_add_test(sscanftest2, SSCANFTestLaerion64);
    tcase_add_test(sscanftest2, SSCANFTestLaerion65);
    tcase_add_test(sscanftest2, SSCANFTestLaerion66);
    tcase_add_test(sscanftest2, SSCANFTestLaerion67);
    tcase_add_test(sscanftest2, SSCANFTestLaerion68);
    tcase_add_test(sscanftest2, SSCANFTestLaerion69);
    tcase_add_test(sscanftest2, SSCANFTestLaerion70);
    tcase_add_test(sscanftest2, SSCANFTestLaerion71);
    tcase_add_test(sscanftest2, SSCANFTestLaerion72);
    tcase_add_test(sscanftest2, SSCANFTestLaerion73);
    tcase_add_test(sscanftest2, SSCANFTestLaerion74);
    tcase_add_test(sscanftest2, SSCANFTestLaerion75);
    tcase_add_test(sscanftest2, SSCANFTestLaerion76);
    tcase_add_test(sscanftest2, SSCANFTestLaerion77);
    return s1;
}
