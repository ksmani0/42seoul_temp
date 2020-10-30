#include <stdio.h>

int main(void)
{

    printf("e test~~~~~~~~~~~~~~~~~~\n");
    printf("%e", -985.765426499);
    printf("%e", 23.375094499);
    printf("%e", 0.0894255);
    printf("%e", -56.2012685);

    printf("%.0e,%.0e|\n", -0.0, 0.0);
    printf("%.0e,%.0e|\n", 0.000039, -0.00032);
    printf("%.0e,%.0e|\n", 9873.000001, -99.99999999);

    printf("%.3e,%.3e|\n", -0.0, 0.0);
    printf("%.3e,%.3e|\n", 0.000039, -0.00032);
    printf("%.3e,%.3e|\n", 9873.000001, -99.99999999);

    printf("%.10e,%.10e|\n", -0.0, 0.0);
    printf("%.10e,%.10e|\n", 0.000039, -0.00032);
    printf("%.10e,%.10e|\n", 9873.000001, -99.99999999);
    printf("%.10e,%.10e|\n", 9873.0000000001, -99.9999999999);

    printf("%.11e,%.11e|\n", 1.025978541236587568, 1.025978548534310421);
    printf("%.11e,%.11e|\n", 0.000000000010000000, 99.999999999990000000);

    printf("%.13e,%.13e|\n", 1.025978541236587568, 1.025978548534310421);
    printf("%.13e,%.13e|\n", 0.000000000010000000, 99.999999999990000000);

    printf("%.16e,%.16e|\n", 1.025978541236587568, 1.025978548534310421);
    printf("%.16e,%.16e|\n", 0.000000000010000000, 99.999999999990000000);

    printf("%.18e,%.18e|\n", 1.025978541236587568, 1.025978548534310421);
    printf("%.18e,%.18e|\n", 0.000000000010000000, 99.999999999990000000);

    printf("%#.0e,%#.0e|\n", 0.0, -7.3);
    printf("%#.1e,%#.1e|\n", 0.0, -7.3);

    printf("%+.0e,%+.0e|\n", 0.0, -0.0);
    printf("%+.0e,%+.0e|\n", 7.4, -7.3);
    printf("%+.3e,%+.3e|\n", 0.0, -0.0);
    printf("%+.3e,%+.3e|\n", 7.4, -7.3);

    printf("%5.0e,%5.0e,%5.0e,%5.0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%5.1e,%5.1e,%5.1e,%5.1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%5.3e,%5.3e,%5.3e,%5.3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%5.6e,%5.6e,%5.6e,%5.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%-5.0e,%-5.0e,%-5.0e,%-5.0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%-5.1e,%-5.1e,%-5.1e,%-5.1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%-5.3e,%-5.3e,%-5.3e,%-5.3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%-5.6e,%-5.6e,%-5.6e,%-5.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%%-05.0e,%%-05.0e,%%0-5.0e,%%0-5.0e: error|\n");
    //-, 0플래그가 만나면 0플래그 무시
    printf("%%-05.1e,%%-05.1e,%%0-5.1e,%%0-5.1e: error|\n");
    //-, 0플래그가 만나면 0플래그 무시, 인자 삭제
    //printf("%0-5.3e,%0-5.3e,%-05.3e,%-05.3e|\n", 0.0, -0.0, 7.4, -7.3);
    //printf("%0-5.6e,%0-5.6e,%-05.6e,%-05.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%#-5.0e,%#-5.0e,%#-5.0e,%#-5.0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%#-5.1e,%#-5.1e,%#-5.1e,%#-5.1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%-#5.3e,%-#5.3e,%-#5.3e,%-#5.3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%-#5.6e,%-#5.6e,%-#5.6e,%-#5.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%+5.0e,%+5.0e,%+5.0e,%+5.0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+5.1e,%+5.1e,%+5.1e,%+5.1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+5.3e,%+5.3e,%+5.3e,%+5.3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+5.6e,%+5.6e,%+5.6e,%+5.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%+05.0e,%+-5.0e,%+05.0e,%+-5.0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+05.1e,%+-5.1e,%+05.1e,%+-5.1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+05.3e,%+-5.3e,%+05.3e,%+-5.3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+05.6e,%+-5.6e,%+05.6e,%+-5.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%+#-5.0e,%+#-5.0e,%+#-5.0e,%+#-5.0e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("% 5.0e,% 5.0e,% 5.0e,% 5.0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("% 5.1e,% 5.1e,% 05.1e,% -5.1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("% 5.3e,% 5.3e,% 05.3e,% -5.3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("% 5.6e,% 5.6e,% 05.6e,% -5.6e|\n", 0.0, -0.0, 7.4, -7.3);

    printf("%% -05.0e,%% -05.0e,%% -05.0e,%% #-05.0e|\n");//-, 0 플래그 만나면 0 무시, 인자 삭제
    printf("#-05.1e|\n", 0.0);
    printf("#-05.3e|\n", -0.0);
    printf("#-05.6e|\n", 7.4);

    printf("%+ .0e,%+ .0e,%+ .0e,%+ .0e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+ .1e,%+ .1e,%+ .1e,%+ .1e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+ .3e,%+ .3e,%+ .3e,%+ .3e|\n", 0.0, -0.0, 7.4, -7.3);
    printf("%+ .6e,%+ .6e,%+ .6e,%+ .6e|\n", 0.0, -0.0, 7.4, -7.3);

    return 0;
}
