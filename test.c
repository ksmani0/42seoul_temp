#include <stdio.h>

int main(void)
{
    int ncm_p = 5;

    printf("str test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("min.max\n");
    printf("%%.09s: |%.09s|\n", NULL);//정밀도 시작 0이면 정밀도 무시
    printf("%%.9s: |%.9s|\n", NULL);//NULL은 (NULL)로 출력
    printf("%%.-9s: error\n", NULL);//문자열에 -플래그는 불유효. 에러
    printf("%%.+9s: error\n", NULL);//문자열에 +플래그는 불유효. 에러
    printf("%%. 9s: error\n", NULL);//문자열에 ' '플래그는 불유효. 에러


    printf("\n# test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%#0-8.5X: error|\n", 34);//- 있으면 0 무시. 에러
    printf("%%#0-8.5X: error|\n", 0);//- 있으면 0 무시. 에러
    printf("%%#0-2.7X: error|\n", 3267);//- 있으면 0 무시. 에러
    printf("%%#0-3.3X: error|\n", 6983);//- 있으면 0 무시. 에러

    printf("%#\n");
    printf("%%#s: error|\n", NULL);//정의되지 않은 조합
    printf("%##x|\n", 42);
    printf("%#++#-5x|\n", 42);//x에 +플래그는 정의되지 않은 조합

    printf("%%#c: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#s: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%#p|\n", &ncm_p);//선언되지 않은 ncm_p 썼다고 에러
    printf("%%#d: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#i: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#u: error|\n");//정의되지 않은 조합, 인자 지움

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 에러, 인자 지움
    printf("|%.09d|\n", 10);
}