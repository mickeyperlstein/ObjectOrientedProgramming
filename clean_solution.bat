@echo off
setlocal enabledelayedexpansion

rem Function to delete x64 and .vs folders
:DeleteFolders
if exist "x64" (
    echo Deleting x64 in %~1
    rmdir /s /q "x64"
)
if exist ".vs" (
    echo Deleting .vs in %~1
    rmdir /s /q ".vs"
)
goto :eof

rem Process main directory
echo Checking main directory
call :DeleteFolders "Main Directory"

rem Go through all subdirectories
for /d %%D in (*) do (
    echo Checking directory: %%D
    pushd "%%D"
    call :DeleteFolders "%%D"
    popd
)

echo Done.
pause