#include <stdio.h>

int main(void)
{
    //int ncm_p = 5;

    printf("\nd test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");

    printf("%d", 2147483647);
    printf("%d", (int)(-2147483678);
    printf("%7d", 33);
    printf("%7d", -14);
    printf("%3d", 0);
    printf("%4d", 94827);
    printf("%4d", -2464);

    printf("%-7d", 33);
    printf("%-7d", -14);
    printf("%-3d", 0);
    printf("%-4d", 94827);
    printf("%-4d", -2464);

    printf("%.5d", 2);
    printf("%.6d", -3);
    printf("%.3d", 0);
    printf("%.3d", 13862);
    printf("%.3d",-23646);

    printf("%05d", 43);
    printf("%07d", -54);
    printf("%03d", 0);
    printf("%04d", -4825);

    printf("%10.5d", -216);
    printf("%8.5d", 0);
    printf("%3.7d", -2375);
    printf("%3.3d", -8462);

    printf("%-10.5d", -216);
    printf("%-8.5d", 0);
    printf("%-3.7d", 3267);
    printf("%-3.3d", -8462);

    printf("%08.5d", 34);
    printf("%010.5d", -216);
    printf("%08.5d", 0);
    printf("%08.3d", -8473);
    printf("%03.7d", 3267);
    printf("%03.3d", -8462);

    printf("%0-10.5d", -216);
    printf("%010.5d", -216);
    printf("%0-8.5d", 0);
    printf("%08.3d", -8473);
    printf("%0-3.7d", 3267);
    printf("%0-3.3d", -8462);

    printf("%03.-3d", -8462);
    printf("%03.+3d", -8462);
    printf("%03. 3d", -8462);

    printf("%.0d", 0);
    printf("%.d", 0);
    printf("%5.0d", 0);
    printf("%5.d", 0);
    printf("%-5.0d", 0);
    printf("%-5.d", 0);

    printf("%%.-5d: error\n");//정밀도에 -있으면 불유효, 인자 지움
    printf("|%.09d|\n", 10);//|000000010|정밀도 앞에 0 있으면


    printf("\nx test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%u", 4294967295u);
    printf("% 8.5u", 0);
    printf("%+3.7u", 3267);
    printf("%08.5u", 34);
    printf("%8. 5u", 0);
    printf("%3.+7u", 3267);
    printf("%8.05u", 34);
    printf("%8.-5u", 34);


    printf("\nx test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%x", 4294967295u);
    printf("%-4x", 9648627);
    printf("%03x", 698334);
    printf("% 8.5x", 34);
    printf("%+8.5x", 34);

    printf("%-5.x", 0);
    printf("%5.-x", 0);
    printf("%5.+x", 0);
    printf("%5. x", 0);
    printf("%5.0x", 0);

    printf("%.0x", 0);
    printf("%.x", 0);
    printf("%.0x", 2);
    printf("%.x", 2);
    printf("%5.x", 0);
    printf("%5.x", 0);
    printf("%5.x", 2);
    printf("%5.x", 2);
    printf("%.5x", 0);
    printf("%.5x", 0);
    printf("%.5x", 2);
    printf("%.5x", 2);

    printf("\np test~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


    return 0;
}
