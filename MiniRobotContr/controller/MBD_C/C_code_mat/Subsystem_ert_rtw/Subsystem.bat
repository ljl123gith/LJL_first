
cd .

if "%1"=="" ("D:\PROGRA~2\MATLAB\R2023a\bin\win64\gmake"  -f Subsystem.mk all) else ("D:\PROGRA~2\MATLAB\R2023a\bin\win64\gmake"  -f Subsystem.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1