#include <stdio.h>

int main(void)
{
    printf("str test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("min.max\n");
    printf("%%.09s: |%.09s|\n", NULL);//정밀도 시작 0이면 정밀도 무시
    printf("%%.9s: |%.9s|\n", NULL);//NULL은 (NULL)로 출력
    printf("%%.-9s: error\n", NULL);//문자열에 -플래그는 불유효. 에러
    printf("%%.+9s: error\n", NULL);//문자열에 +플래그는 불유효. 에러
    printf("%%. 9s: error\n", NULL);//문자열에 ' '플래그는 불유효. 에러


    printf("\n# test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%#0-8.5X: |%#0-8.5X|\n", 34);
    printf("%%#0-8.5X: |%#0-8.5X|\n", 0);
    printf("%#0-8.3X|\n", 8375);
    printf("%#0-2.7X|\n", 3267);
    printf("%#0-3.3X|\n", 6983);

    printf("%#|\n");
    printf("%#s|\n", NULL);
    printf("%##x|\n", 42);
    printf("%#++#-5x|\n", 42);

    printf("%%#c: error|\n", 'a');//정의되지 않은 조합
    printf("%%#s: error|\n", "hello");//정의되지 않은 조합
    printf("%#p|\n", &ncm_p);
    printf("%%#d: error|\n", 42);//정의되지 않은 조합
    printf("%%#i: error|\n", 42);//정의되지 않은 조합
    printf("%%#u: error|\n", 42);//정의되지 않은 조합

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%.-5d: error\n", 10);//정밀도에 -있으면 불유효, 에러
    printf("|%.09d|\n", 10);
}