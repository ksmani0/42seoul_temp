#include <stdio.h>

int main(void)
{
	//12.5663999999999997925215211580507457256317138671875
	printf("%.g|%g|%.1g|%g|\n", 12.5664, 12.5664, 12.5664, 12.5664);
	//
	printf("%.2g|%.3g|%.4g|%.5g|\n", 12.5664, 12.5664, 12.5664, 12.5664);
	//

	printf("%.f|%f|%.1f|%f|\n", 12.5664, 12.5664, 12.5664, 12.5664);
	//
	printf("%.2f|%.3f|%.4f|%.5f|\n", 12.5664, 12.5664, 12.5664, 12.5664);
	//

    return 0;
}
