set MATLAB=D:\ProgramFiles\MATLAB

cd .

if "%1"=="" ("D:\ProgramFiles\MATLAB\bin\win64\gmake"  -f LKAS.mk all) else ("D:\ProgramFiles\MATLAB\bin\win64\gmake"  -f LKAS.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
