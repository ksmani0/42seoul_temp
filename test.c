#include <stdio.h>

int main(void)
{
    printf("str test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%.09s: |%.09s|\n", NULL);//정밀도 앞에 0있으면 정밀도 무시
    printf("%%.9s: |%.9s|\n", NULL);//NULL은 (NULL)로 출력
    printf("%%.-9s: |%.-9s|\n", NULL);//에러
    printf("%%.+9s: |%.+9s|\n", NULL);//에러
    printf("%%. 9s: |%. 9s|\n", NULL);//에러


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

    printf("%#c|\n", 'a');
    printf("%#s|\n", "hello");
    printf("%#p|\n", &ncm_p);
    printf("%#d|\n", 42);
    printf("%#i|\n", 42);
    printf("%#u|\n", 42);

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|%.-5d|\n", 10);
    printf("|%.09d|\n", 10);
}