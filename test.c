#include <stdio.h>

int main(void)
{
    //int n;

    printf("f test~~~~~~~~~~~~~~~~~\n");
    printf("min.Below the decimal point\n");
    printf("%f|\n", -0.0);//-0.000000|
    printf("%f|\n", 9873.000001);//
    printf("%f|\n", -0.999999);//

    printf("%.0f|\n", 0.0);//
    printf("%.0f|\n", -0.0);//
    printf("%.0f|\n", -7.00036);//

    printf("%.1f|\n", -0.0);//
    printf("%.1f|\n", 0.0);//
    printf("%.1f|\n", -7.00036);//
    printf("%.3f|\n", 573.924);//
    printf("%.3f|\n", -0.0);//

    printf("%.7f|\n", -875.000001);//
    printf("%.7f|\n", 999.9999999);//
    printf("%.7f|\n", -985.765426499);//

    printf("%.13f|\n", 99.999999999999900000);//
    printf("%.17f|\n", 0.000000000000000010);//
    printf("%.18f|\n", 0.125978548534310421);//0.125978548534310425|

    printf("%#.0f|\n", 0.0);//
    printf("%#.0f|\n", -0.0);//
    printf("%#.1f|\n", 0.0);//
    printf("%#.1f|\n", -0.0);//

    printf("%#.0f|\n", 7.4);//
    printf("%#.1f|\n", 7.3);//
    printf("%#.0f|\n", -7.4);//
    printf("%#.1f|\n", -7.3);//

    printf("%+.0f|\n", -0.0);//
    printf("%+.3f|\n", 0.0);//
    printf("%+.0f|\n", -7.4);//
    printf("%+.3f|\n", -7.3);//

    printf("%5.0f|\n", 0.0);//
    printf("%5.3f|\n", -0.0);//
    printf("%5.0f|\n", -0.0);//
    printf("%5.6f|\n", -7.3);//

    printf("%05.0f|\n", 0.0);//
    printf("%05.3f|\n", -0.0);//-0.000|
    printf("%05.1f|\n", 7.3);//007.3|
    printf("%05.6f|\n", -7.3);//-7.300000|

    printf("%-5.3f|\n", -0.0);//-0.000|
    printf("%-5.6f|\n", -7.3);//-7.300000|
    printf("%-5.0f|\n", 0.0);//0    |

    printf("%%-05.3f: error|\n");//f서도 -플래그 있을 땐 0플래그 무시
    printf("%#-5.6f|\n", -7.3);//
    printf("%-5.0f|\n", 0.0);//
    printf("%+5.6f|\n", -7.3);//
    printf("%+5.6f|\n", 7.3);//
    printf("%+05.6f|\n", -7.3);//
    printf("%+-5.6f|\n", -7.3);//
    printf("%%+-05.6f: error|\n");//f서도 -플래그 있을 땐 0플래그 무시
    printf("%-+5.6f|\n", -7.3);//
    printf("%+#-5.6f|\n", -7.3);//
    printf("% 5.6f|\n", -7.3);//
    printf("% 05.6f|\n", -7.3);//
    printf("% -5.6f|\n", -7.3);//
    printf("%% -05.6f: error|\n");//f서도 -플래그 있을 땐 0플래그 무시
    printf("%- 5.6f|\n", -7.3);//

    printf("%%+ .6f: error|\n");//f서도 +플래그 있을 땐 ' '플래그 무시
    printf("%% +.6f: error|\n");//+플래그만 있는 걸로 처리하기

    printf("%-*.*d|\n", -7, -5, 123);//
    printf("%-*.*d|\n", 7, -5, 123);//

    return 0;
}
