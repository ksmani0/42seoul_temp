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
    printf("% 5.6f|\n", 7.3);//
    printf("% 05.f|\n", 7.3);//

    printf("%%# 0#5.d: error|\n");//#플래그와 d 조합은 정의할 수 없는 결과, 인자 지움
    printf("%# 05.d|\n", 5);//

    return 0;
}
