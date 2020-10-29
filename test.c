#include <stdio.h>

int main(void)
{
    int n;

    printf("f test~~~~~~~~~~~~~~~~~\n");
    printf("min.Below the decimal point\n");
    printf("%f|\n", -0.0);
    printf("%f|\n", 9873.000001);
    printf("%f|\n", -0.999999);

    printf("%.0f|\n", 0.0);
    printf("%.0f|\n", -0.0);
    printf("%.0f|\n", -7.00036);

    printf("%.1f|\n", -0.0);
    printf("%.1f|\n", 0.0);
    printf("%.1f|\n", -7.00036);
    printf("%.3f|\n", 573.924);
    printf("%.3f|\n", -0.0);

    printf("%.7f|\n", -875.000001);
    printf("%.7f|\n", 999.9999999);
    printf("%.7f|\n", -985.765426499);

    printf("%.13f|\n", 99.999999999999900000);
    printf("%.17f|\n", 0.000000000000000010);
    printf("%.18f|\n", 0.125978548534310421);

    printf("%#.0f|\n", 0.0);
    printf("%#.0f|\n", -0.0);
    printf("%#.1f|\n", 0.0);
    printf("%#.1f|\n", -0.0);

    printf("%#.0f|\n", 7.4);
    printf("%#.1f|\n", 7.3);
    printf("%#.0f|\n", -7.4);
    printf("%#.1f|\n", -7.3);

    printf("%+.0f|\n", -0.0);
    printf("%+.3f|\n", 0.0);
    printf("%+.0f|\n", -7.4);
    printf("%+.3f|\n", -7.3);

    printf("%5.0f|\n", 0.0);
    printf("%5.3f|\n", -0.0);
    printf("%5.0f|\n", -0.0);
    printf("%5.6f|\n", -7.3);

    printf("%05.0f|\n", 0.0);
    printf("%05.3f|\n", -0.0);
    printf("%05.1f|\n", 7.3);
    printf("%05.6f|\n", -7.3);

    printf("%-5.3f|\n", -0.0);
    printf("%-5.6f|\n", -7.3);
    printf("%-5.0f|\n", 0.0);

    printf("n test~~~~~~~~~~~~~~~~~\n");
    printf("pft%ntest|\n", &n);//
    printf("pft%% ntest: error|\n");//' '플래그와 n 조합은 정의되지 않은 결과
    printf("pft%%#ntest: error|\n");//#플래그와 n 조합은 정의되지 않은 결과
    printf("pft%%0ntest: error|\n");//0플래그와 n 조합은 정의되지 않은 결과
    printf("pft%%-ntest: error|\n");//-플래그와 n 조합은 정의되지 않은 결과
    printf("pft%%+ntest: error|\n");//인자 지움

    printf("pft%%5ntest: error|\n");//그냥 너비도 n과 정의되지 않은 결과
    printf("pft%%.5ntest: error|\n");//인자 지움
    printf("pft%%5.5ntest: error|\n");//

    printf("pft%%.*ntest: error|\n");//n과 정밀도 조합은 정의되지 않은 결과, 인자 지움
    printf("pft%%*.ntest: error|\n");//
    printf("pft%%*.*ntest: error|\n");//

    printf("* test~~~~~~~~~~~~~~~~~\n");
    printf("%.*f|\n", -3, 3.1415926535);
    printf("%.*e|\n", -3, 3.1415926535);
    printf("%.*g|\n", -3, 3.1415926535);
    printf("%.*o|\n", -1, 12345);

    printf("%-*s|\n", 32, "abc");
    printf("%-*.*s|\n", 7, 3, "yolo");
    printf("%0*i|\n", 7, -54);
    printf("%.*i|\n", 6, -3);

    printf("%*s|\n", -32, "abc");
    printf("%-*s|\n", -32, "abc");
    printf("%-*.*s|\n", -7, -3, "yolo");
    printf("%0*i|\n", -7, -54);

    return 0;
}
