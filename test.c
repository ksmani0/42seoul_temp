#include <stdio.h>

int main(void)
{
    //int ncm_p = 5;

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");

    printf("%d|\n", 2147483647);
    printf("%d|\n", (int)(-2147483678));
    printf("%7d|\n", 33);
    printf("%7d|\n", -14);
    printf("%3d|\n", 0);
    printf("%4d|\n", 94827);
    printf("%4d|\n", -2464);

    printf("%-7d|\n", 33);
    printf("%-7d|\n", -14);
    printf("%-3d|\n", 0);
    printf("%-4d|\n", 94827);
    printf("%-4d|\n", -2464);

    printf("%.5d|\n", 2);
    printf("%.6d|\n", -3);
    printf("%.3d|\n", 0);
    printf("%.3d|\n", 13862);
    printf("%.3d|\n",-23646);

    printf("%05d|\n", 43);
    printf("%07d|\n", -54);
    printf("%03d|\n", 0);
    printf("%04d|\n", -4825);

    printf("%10.5d|\n", -216);
    printf("%8.5d|\n", 0);
    printf("%3.7d|\n", -2375);
    printf("%3.3d|\n", -8462);

    printf("%-10.5d|\n", -216);
    printf("%-8.5d|\n", 0);
    printf("%-3.7d|\n", 3267);
    printf("%-3.3d|\n", -8462);

    printf("%08.5d|\n", 34);
    printf("%010.5d|\n", -216);
    printf("%08.5d|\n", 0);
    printf("%8.05d|\n", 0);
    printf("%08.3d|\n", -8473);
    printf("%03.7d|\n", 3267);
    printf("%03.3d|\n", -8462);

    printf("%%0-10.5d: error|\n");//모든 서식지정자에서 0와 -플래그 같이 쓰면 0이 무시된다는 오류
    printf("%010.5d", -216);
    printf("%%0-8.5d: error|\n");//인자 지움
    printf("%08.3d", -8473);
    printf("%%0-3.7d: error|\n");
    printf("%%0-3.3d: error|\n");

    printf("%%03.-3d: error|\n");//.정밀도가 -플래그로 시작하면 불유효, 인자 지움
    printf("%%03.+3d: error|\n");//.정밀도가 +플래그로 시작하면 불유효
    printf("%%03. 3d: error|\n");//.정밀도가 ' '플래그로 시작하면 불유효

    printf("%.0d|\n", 0);
    printf("%.d|\n", 0);
    printf("%5.0d|\n", 0);
    printf("%5.d|\n", 0);
    printf("%-5.0d|\n", 0);
    printf("%-5.d|\n", 0);
    printf("%.0d|\n", 1);
    printf("%.d|\n", 1);
    printf("%5.0d|\n", 1);
    printf("%5.d|\n", 1);
    printf("%-5.0d|\n", 1);
    printf("%-5.d|\n", 1);

    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 인자 지움
    printf("|%.09d|\n", 10);//|000000010|정밀도 앞에 0 있으면


    printf("\nu test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%u", 4294967295u);
    printf("%% 8.5u: error|\n");//u에 ' '플래그는 정의되지 않은 결과
    printf("%%+3.7u: error|\n");//u에 +플래그는 정의되지 않은 결과
    printf("%08.5u|\n", 34);
    printf("%%8. 5u: error|\n");//. 뒤에 ' '플래그는 불유효, 인자 삭제
    printf("%%3.+7u: error|\n");//. 뒤에 +플래그는 불유효
    printf("%8.05u|\n", 34);
    printf("%%8.-5u: error|\n");//. 뒤에 -플래그는 불유효


    printf("\nx test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%x|\n", 4294967295u);
    printf("%-4x|\n", 9648627);
    printf("%03x|\n", 698334);
    printf("%% 8.5x: error|\n");//x에 ' '플래그는 정의되지 않은 결과, 인자 삭제
    printf("%%+8.5x: error|\n");//x에 +플래그는 정의되지 않은 결과

    printf("%-5.x|\n", 0);
    printf("%%5.-x: error|\n");//. 뒤에 -플래그는 불유효, 인자 삭제
    printf("%%5.+x: error|\n");//. 뒤에 +플래그는 불유효, 인자 삭제
    printf("%%5. x: error|\n");//. 뒤에 ' '플래그는 불유효, 인자 삭제
    printf("%5.0x|\n", 0);

    printf("%.0x|\n", 0);
    printf("%.x|\n", 0);
    printf("%.0x|\n", 2);
    printf("%.x|\n", 2);
    printf("%5.x|\n", 0);
    printf("%5.x|\n", 0);
    printf("%5.x|\n", 2);
    printf("%5.x|\n", 2);
    printf("%.5x|\n", 0);
    printf("%.5x|\n", 0);
    printf("%.5x|\n", 2);
    printf("%.5x|\n", 2);

    printf("\np test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


    return 0;
}
