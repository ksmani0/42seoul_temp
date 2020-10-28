#include <stdio.h>

int main(void)
{
    //int ncm_p = 5;

    printf("str test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("min.max\n");
    printf("%10s|\n", "abc");
    printf("%5s|\n", "goes over");
    printf("%-10s|\n", "abc");
    printf("%-5s|\n", "goes over");

    printf("%.3s%.7s|\n", "holla", "bitch");
    printf("%.0s|\n", "hello");
    printf("%.s|\n", "hello");
    printf("%7.5s|\n", "yolo");
    printf(%7.5s|\n", "bombastic");

    printf("%%.09s: |%.09s|\n", NULL);//정밀도 시작 0이면 정밀도 무시
    printf("%%.9s: |%.9s|\n", NULL);//NULL은 (NULL)로 출력
    printf("%%.-9s: error\n", NULL);//문자열에 -플래그는 불유효
    printf("%%.+9s: error\n", NULL);//문자열에 +플래그는 불유효
    printf("%%. 9s: error\n", NULL);//문자열에 ' '플래그는 불유효


    printf("\n# test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("max.min");
    printf("%#X|\n", 4294967295u);//0XFFFFFFFF|int보다 큰 값 넣을 땐 접미사 u

    printf("%#3X|\n", 0);//  0|
    printf("%#7X|\n", 52625);// 0XCD91|
    printf("%#-4X|\n", 9648627);//0X9339F3|인자 너비가 최대너비보다 크면 그냥 인자 너비

    printf("%#.3X|\n", 0);//000|최대너비보다 정밀도가 더 크면 최소너비대로
    printf("%#.3X|\n", 938862);//0XE536E|
    printf("%#.0X|\n", 0);//|그냥 최대출력너비가 아니라 .정밀도 쓰고 인자가 0이면 빈공간 출력
    printf("%#.X|\n", 0);//|
    printf("%#5.0X|\n", 0);//     |
    printf("%#5.X|\n", 0);//     |
    printf("%#.05X|\n", 0);//     |

    printf("%#.0X|\n", 2);//
    printf("%#.X|\n", 2);//
    printf("%#5.0X|\n", 2);//
    printf("%#5.X|\n", 2);//
    printf("%#.05X|\n", 2);//

    printf("%#8.3X|\n", 8375);//  0X20B7|최대너비가 제일 크니 최대너비대로
    printf("%#2.7X|\n", 3267);//0X0000CC3|정밀도가 최대너비보다 크면 0X 제외한 정밀도 따름
    printf("%#3.3X|\n", 6983);//0X1B47|인자 너비가 다 크면 인자 너비대로

    printf("%#-8.3X|\n", 8375);//0X20B7  |-플래그따라 왼쪽
    printf("%#-2.7X|\n", 3267);//0X0000CC3|-플래그 있고 정밀도가 제일 크니 정밀도 따름
    printf("%#-3.3X|\n", 6983);//0X1B47|-플래고디 있지만 인자 너비가 커서 인자 너비 그대로

    printf("%#05X|\n", 43);//0X02B|0플래그로 최대너비 못 채운 데 0 채움
    printf("%#03X|\n", 0);//000|0플래그로 정밀도 공간 채움
    printf("%#03X|\n", 698334);//0XAA7DE|0플래그 있는데 인자 너비 커서 인자 그대로
    printf("%#08.3X|\n", 8375);//  0X20B7|0플래그 있는데 정밀도도 있으면 남은 정밀도 공간 있을 때 0 채움
    printf("%#02.7X|\n", 3267);//0X0000CC3|0플래그랑 정밀도 있고 정밀도 공간 남아서 0 채움
    printf("%#03.3X|\n", 6983);//0X1B47|0플래그 있어도 인자 너비 커서 그대로

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


    printf("\nc test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%c|\n", '\0');//정의되지 않은 조합, 인자 지움
    printf("%5c|\n", '\0');//정의되지 않은 조합, 인자 지움
    printf("%-5c|\n", '\0');//정의되지 않은 조합, 인자 지움
    printf("%05c|\n", '\0');//정의되지 않은 조합, 인자 지움
    printf("% 5c|\n", '\0');//정의되지 않은 조합, 인자 지움
    printf("%5.c|\n", '\0');//정의되지 않은 조합, 인자 지움
    printf("%.5c|\n", '\0');//정의되지 않은 조합, 인자 지움


    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 인자 지움
    printf("|%.09d|\n", 10);
    return 0;
}
