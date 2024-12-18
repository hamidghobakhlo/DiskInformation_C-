#define UNICODE  
#define _UNICODE 
#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "Winnetwk.h"
#include <cmath>

void GetDiskLoad();

int main()
{
	printf("\nHard Disk Information:\n");
	GetDiskLoad();
}

void GetDiskLoad() {

	wchar_t Dir[10];
	char dir1[] = "C:";
	size_t output_size;

	__int64 LPFreeBytesAvailableToCaller = 0;
	__int64 LPTotalNumberOfBytes = 0;
	__int64 LPTotalNumberOfFreeBytes = 0;

	LPCSTR DriveArray[] = { "A:\\","B:\\","C:\\","D:\\","E:\\", "F:\\","G:\\", "H:\\","I:\\", "J:\\","K:\\",
		"L:\\","M:\\", "N:\\","O:\\", "P:\\","Q:\\", "R:\\","S:\\", "T:\\","U:\\", "V:\\","W:\\",
		"X:\\","Y:\\", "Z:\\","AA:\\", "AB:\\","AC:\\", "AD:\\","AF:\\", "AE:\\" };

	DWORD DiskList = GetLogicalDrives();

	for (int i = 0; i <= 31; i++) {
		DWORD temp = pow(2, i);
		if (DiskList & temp) {
			printf("Disk Volume Number %d is %s\n", i + 1, DriveArray[i]);
			mbstowcs_s(&output_size, Dir, DriveArray[i], strlen(DriveArray[i]) + 1);

			if (!GetDiskFreeSpaceEx(Dir, (PULARGE_INTEGER)&LPFreeBytesAvailableToCaller, (PULARGE_INTEGER)&LPTotalNumberOfBytes, (PULARGE_INTEGER)&LPTotalNumberOfFreeBytes))
				printf("Error: Disk is not available or is not formatted.\n\n");
			else {
				//printf("LPFreeBytesAvailableToCaller = %u\n", div(LPFreeBytesAvailableToCaller,(UINT32)pow(2,30)));
				printf("Total Disk Space %s = %u GB\n", DriveArray[i], LPTotalNumberOfBytes / (UINT32)pow(2, 30));
				printf("Free Spce = %u GB\n", LPTotalNumberOfFreeBytes / (UINT32)pow(2, 30));
				printf("Usage Percent = %u%\%\n\n", (LPTotalNumberOfBytes - LPTotalNumberOfFreeBytes) * 100 / LPTotalNumberOfBytes);
			}

		}
	}
}

