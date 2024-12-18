# C++ Program to Display Disk Space Information on Windows

## Program Explanation
This C++ program is designed to fetch and display information about the available disk space on a Windows system. It utilizes Windows API functions to gather details about the logical drives and their free/total disk space. For each drive, it prints out the total space, free space, and the percentage of used space.

## Detailed Explanation of the Program

### Included Headers:
- `#include <iostream>`: For standard input/output (cin, cout) in C++.
- `#include "windows.h"`: For accessing Windows-specific functions and structures, including disk management.
- `#include "Winnetwk.h"`: For working with network-related functionality and devices.
- `#include <cmath>`: For using mathematical functions like `pow()`, which is used for exponentiation.

### Variable and Array Definitions:
- `wchar_t Dir[10];`: A character array used to store the path of each drive.
- `char dir1[] = "C:";`: The path of the C: drive.
- `__int64 LPFreeBytesAvailableToCaller, LPTotalNumberOfBytes, LPTotalNumberOfFreeBytes;`: 64-bit variables for storing free space, total space, and free space available to the caller.

### Drive Array Definition:
The `DriveArray[]` contains the drive letters of various logical drives in the system (from A: to Z: and some special drives like AA:, AB:).

### The `GetDiskLoad()` Function:
This function is responsible for displaying the total and free disk space for each available drive.

- `DWORD DiskList = GetLogicalDrives();`: This function retrieves information about the logical drives in the system.
- A for loop is used to check if a drive exists or not based on the `DiskList`.
- If the drive exists, the `GetDiskFreeSpaceEx()` function is used to get the disk space information for that particular drive.
- Finally, the program prints out the total space and free space for each drive in gigabytes.

### Displaying Information:
For each drive, the program displays the following information:
- Total disk space (in GB).
- Free disk space (in GB).
- Disk usage percentage.

### Converting Values to Gigabytes:
The program uses `pow(2, 30)` to convert bytes to gigabytes.

## Example Output:
When the program is executed, the output might look like this for each drive:

```plaintext
Hard Disk Information:
Disk Volume Number 1 is C:\
Total Disk Space C:\ = 500 GB
Free Space = 200 GB
Usage Percent = 60%

Disk Volume Number 2 is D:\
Total Disk Space D:\ = 1000 GB
Free Space = 500 GB
Usage Percent = 50%
