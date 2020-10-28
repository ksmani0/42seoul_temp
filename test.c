#include <stdio.h>

int main(void)
{
    //int ncm_p = 5;

    printf("str test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("min.max\n");
    printf("%%.09s: |%.09s|\n", NULL);//정밀도 시작 0이면 정밀도 무시
    printf("%%.9s: |%.9s|\n", NULL);//NULL은 (NULL)로 출력
    printf("%%.-9s: error\n", NULL);//문자열에 -플래그는 불유효
    printf("%%.+9s: error\n", NULL);//문자열에 +플래그는 불유효
    printf("%%. 9s: error\n", NULL);//문자열에 ' '플래그는 불유효


    printf("\n# test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%#X", 4294967295u);

    printf("%#3X", 0);
    printf("%#7X", 52625);
    printf(%#-4X", 9648627);

    printf("%#.3X", 0);
    printf("%#.3X", 938862);
    printf("%#.0X", 0);
    printf("%#.X", 0);
    printf("%#5.0X", 0);
    printf("%#5.X", 0);

    printf("%#8.3X", 8375);//
    printf("%#2.7X", 3267);//
    printf("%#3.3X", 6983);//

    printf("%#-8.3X", 8375);//
    printf("%#-2.7X", 3267);//
    printf("%#-3.3X", 6983);//

    printf("%#05X", 43);//
    printf("%#03X", 0);//
    printf("%#03X", 698334);//
    printf("%#08.3X", 8375);//
    printf("%#02.7X", 3267);//
    printf("%#03.3X", 6983);//

    printf("%%#0-8.5X: error|\n");//- 있으면 0 무시. 에러, 인자 지움
    printf("%%#0-8.5X: error|\n");//- 있으면 0 무시. 에러, 인자 지움
    printf("%%#0-2.7X: error|\n");//- 있으면 0 무시. 에러, 인자 지움
    printf("%%#0-3.3X: error|\n");//- 있으면 0 무시. 에러, 인자 지움

    printf("%%#: error|\n");//불완전한 형식 지정자
    printf("%%#s: error|\n", NULL);//정의되지 않은 조합
    printf("%##x|\n", 42);//
    printf("%%#++#-5x: error|\n");//x에 +플래그는 정의되지 않은 조합, 인자 지움

    printf("%%#c: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#s: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#p: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#d: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#i: error|\n");//정의되지 않은 조합, 인자 지움
    printf("%%#u: error|\n");//정의되지 않은 조합, 인자 지움

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 인자 지움
    printf("|%.09d|\n", 10);
}