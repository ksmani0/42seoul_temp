#include <stdio.h>

int main(void)
{
    //int ncm_p = 5;
    char *s_hidden = "hi low\0don't print me lol\0";

    printf("str test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("min.max\n");
    printf("%10s|\n", "abc");//       abc|최소너비가 더 크면 공백
    printf("%5s|\n", "goes over");//goes over|그냥 최소너비만 있고 인자가 넓으면 인자 따름
    printf("%-10s|\n", "abc");//abc       |-플래그따라 왼쪽
    printf("%-5s|\n", "goes over");//goes over|역시 최소너비만 있고 인자가 넓으면 인자 너비 따름

    printf("%.3s%.7s|\n", "holla", "bitch");//holbitch|최대너비가 인자 너비보다 작으면 인자 짤림. 최대너비가 인자보다 크면 공백 없이 인자만 나옴
    printf("%.0s|\n", "hello");//|최대너비가 0 이거나 없으면 아무 것도 출력 안 됨
    printf("%.s|\n", "hello");//|
    printf("%7.5s|\n", "yolo");//   yolo|최소너비가 최대너비보다 커서 공백 출력
    printf("%7.5s|\n", "bombastic");//  bomba|최대너비가 인자 나올 크기 결정. 최소너비가 최대너비보다 크면 남은 최소너비가 빈공간으로 출력

    printf("%-7s%5s|\n", "hello", "world");
    printf("%7s%-5s|\n", "hello", "world");

    printf("hello, %s.|\n", NULL);
    printf("%s|\n", NULL);
    printf("%12s|\n", NULL);
    printf("%2s|\n", NULL);
    printf("%9.s|\n", NULL);
    printf("%3.s|\n", NULL);
    printf("%.9s|\n", NULL);
    printf("%.3s|\n", NULL);
    printf("%.s|\n", NULL);
    printf("%.0s|\n", NULL);
    printf("%.03s|\n", NULL);
    printf("%.09s|\n", NULL);
    printf("%9.1s|\n", NULL);
    printf("%3.1s|\n", NULL);
    printf("%-3.8s|\n", NULL);
    printf("%-9.8s|\n", NULL);

    printf("%.s|\n", s_hidden);
    printf("%.03s|\n", s_hidden);
    printf("%.09s|\n", s_hidden);
    printf("%3.s|\n", s_hidden);
    printf("%9.s|\n", s_hidden);
    printf("%-3.s|\n", s_hidden);
    printf("%-9.s|\n", s_hidden);
    printf("%-3.8s|\n", s_hidden);
    printf("%-9.8s|\n", s_hidden);
    printf("%-1.s|\n", "\0");
    printf("%-2.s|\n", "\0");
    printf("%-6.s|\n", "\0");

    printf("%%+- 06.06s: error|\n");//. 앞이든 뒤든 0플래그는 s랑 정의할 수 없는 조합
    printf("%% -+012.06s: error|\n");//. 앞이든 뒤든 ' '플래그는 s랑 정의할 수 없는 조합
    printf("%%+-0 6.04s: error|\n");//. 앞이든 뒤든 +플래그는 s랑 정의할 수 없는 조합
    printf("%%+-0 6.09s: error|\n");//이렇게 4개 예시 속 인자 다 지움

    printf("%00s|\n", s_hidden);
    printf("%-00s|\n", s_hidden);
    printf("%0-0s|\n", s_hidden);
    printf("%03s|\n", s_hidden);
    printf("%09s|\n", s_hidden);
    printf("%+03s|\n", s_hidden);//
    printf("%+09s|\n", s_hidden);
    printf("%-03s|\n", s_hidden);
    printf("%-09s|\n", s_hidden);
    printf("%+ 3s|\n", s_hidden);
    printf("%+ 9s|\n", s_hidden);

    printf("%%.09s: |%.09s|\n", NULL);//정밀도 시작 0이면 정밀도 무시
    printf("%%.9s: |%.9s|\n", NULL);//NULL은 (NULL)로 출력
    printf("%%.-9s: error\n", NULL);//문자열에 -플래그는 불유효
    printf("%%.+9s: error\n", NULL);//문자열에 +플래그는 불유효
    printf("%%. 9s: error\n", NULL);//문자열에 ' '플래그는 불유효


    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 인자 지움
    printf("|%.09d|\n", 10);//|000000010|문자열과 달리 정밀도 앞에 0 가능
    return 0;
}
