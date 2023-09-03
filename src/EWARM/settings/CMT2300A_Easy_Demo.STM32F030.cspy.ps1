﻿param([String]$debugfile = "");

# This powershell file has been generated by the IAR Embedded Workbench
# C - SPY Debugger, as an aid to preparing a command line for running
# the cspybat command line utility using the appropriate settings.
#
# Note that this file is generated every time a new debug session
# is initialized, so you may want to move or rename the file before
# making changes.
#
# You can launch cspybat by typing Powershell.exe -File followed by the name of this batch file, followed
# by the name of the debug file (usually an ELF / DWARF or UBROF file).
#
# Read about available command line parameters in the C - SPY Debugging
# Guide. Hints about additional command line parameters that may be
# useful in specific cases :
#   --download_only   Downloads a code image without starting a debug
#                     session afterwards.
#   --silent          Omits the sign - on message.
#   --timeout         Limits the maximum allowed execution time.
#


if ($debugfile -eq "")
{
& "C:\Program Files (x86)\IAR Systems\Embedded Workbench 8.0\common\bin\cspybat" -f "G:\待更新\硅传资料盘V1.32待更新内容\CMT2300A_Easy_Demo_v2.0\EWARM\settings\CMT2300A_Easy_Demo.STM32F030.general.xcl" --backend -f "G:\待更新\硅传资料盘V1.32待更新内容\CMT2300A_Easy_Demo_v2.0\EWARM\settings\CMT2300A_Easy_Demo.STM32F030.driver.xcl" 
}
else
{
& "C:\Program Files (x86)\IAR Systems\Embedded Workbench 8.0\common\bin\cspybat" -f "G:\待更新\硅传资料盘V1.32待更新内容\CMT2300A_Easy_Demo_v2.0\EWARM\settings\CMT2300A_Easy_Demo.STM32F030.general.xcl" --debug_file=$debugfile --backend -f "G:\待更新\硅传资料盘V1.32待更新内容\CMT2300A_Easy_Demo_v2.0\EWARM\settings\CMT2300A_Easy_Demo.STM32F030.driver.xcl" 
}
