#include <stdio.h>

int main(void)
{
    unsigned long long a10 = 1;

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("max.min\n");

    printf("%d|\n", 2147483647);//
    printf("%d|\n", (int)(-2147483678));//
    printf("%7d|\n", 33);//
    printf("%7d|\n", -14);//
    printf("%3d|\n", 0);//
    printf("%4d|\n", 94827);//
    printf("%4d|\n", -2464);//

    printf("%-7d|\n", 33);//
    printf("%-7d|\n", -14);//
    printf("%-3d|\n", 0);//
    printf("%-4d|\n", 94827);//
    printf("%-4d|\n", -2464);//

    printf("%.5d|\n", 2);//
    printf("%.6d|\n", -3);//
    printf("%.3d|\n", 0);//
    printf("%.3d|\n", 13862);//
    printf("%.3d|\n",-23646);//

    printf("%05d|\n", 43);//
    printf("%07d|\n", -54);//
    printf("%03d|\n", 0);//
    printf("%04d|\n", -4825);//

    printf("%10.5d|\n", -216);//
    printf("%8.5d|\n", 0);//
    printf("%3.7d|\n", -2375);//
    printf("%3.3d|\n", -8462);//

    printf("%-10.5d|\n", -216);//
    printf("%-8.5d|\n", 0);//
    printf("%-3.7d|\n", 3267);//
    printf("%-3.3d|\n", -8462);//

    printf("%08.5d|\n", 34);//
    printf("%010.5d|\n", -216);//
    printf("%08.5d|\n", 0);//
    printf("%8.05d|\n", 0);//
    printf("%08.3d|\n", -8473);//
    printf("%03.7d|\n", 3267);//0003267|
    printf("%03.3d|\n", -8462);//-8462|

    printf("%%0-10.5d: error|\n");//모든 서식지정자에서 0와 -플래그 같이 쓰면 0이 무시된다는 오류
    printf("%010.5d|\n", -216);//    -00216|역시 최대너비 앞 0플래그는 최소너비에 적용
    printf("%%0-8.5d: error|\n");//인자 지움
    printf("%08.3d|\n", -8473);//   -8473|최대너비에 0플래그 있어도 최소너비가 인자 너비보다 작아 0 없음
    printf("%%0-3.7d: error|\n");
    printf("%%0-3.3d: error|\n");

    printf("%%03.-3d: error|\n");//.정밀도가 -플래그로 시작하면 불유효, 인자 지움
    printf("%%03.+3d: error|\n");//.정밀도가 +플래그로 시작하면 불유효
    printf("%%03. 3d: error|\n");//.정밀도가 ' '플래그로 시작하면 불유효

    printf("%.0d|\n", 0);//|
    printf("%.d|\n", 0);//|
    printf("%5.0d|\n", 0);//     |
    printf("%5.d|\n", 0);//     |
    printf("%-5.0d|\n", 0);//     |
    printf("%-5.d|\n", 0);//     |
    printf("%.0d|\n", 1);//1|
    printf("%.d|\n", 1);//1|
    printf("%5.0d|\n", 1);//    1|
    printf("%5.d|\n", 1);//    1|
    printf("%-5.0d|\n", 1);//1    |
    printf("%-5.d|\n", 1);//1    |

    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 인자 지움
    printf("%.09d|\n", 10);//|000000010|정밀도 앞에 0 있으면 최소너비 남는 공간에 0 채움


    printf("\np test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%p|\n", &a10);//
    printf("%9.2p|\n", 1234);//
    printf("%2.9p|\n", 1234);//
    printf("%.5p|\n", 0);//
    printf("%.0p|\n", 0);//
    printf("%5p|\n", 0);//
    printf("%15p|\n", &a10);//
    printf("%-15p|\n", &a10);//
    printf("%015p|\n", &a10);//


    return 0;
}
