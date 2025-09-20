@echo off
setlocal enabledelayedexpansion

:: Check for Python in PATH
echo Searching for Python in PATH...
set python_found=0

for %%P in ("%PATH:;=" "%") do (
    if exist "%%~P\python.exe" (
        set python_found=1
        set python_path=%%~P\python.exe
        goto :python_found
    )
)

:python_not_found
echo Python is not found in PATH.
echo.
echo How would you like to install Python?
echo 1. Manual installation (h)
echo 2. Automatic installation of the exe file in the C disk in the current directory (d)
echo Be sure to check the Add Python (version) to PATH box when installing the exe file.
set /p choice=Enter your choice (h/d): 

if /i "%choice%"=="h" (
    echo Open the following link to download Python:
    echo https://www.python.org/downloads/
    echo Follow the instructions to complete the installation.
    pause
    exit /b
) else if /i "%choice%"=="d" (
    echo Downloading Python installer...
    curl -o python-installer.exe https://www.python.org/ftp/python/3.10.8/python-3.10.8-amd64.exe
    if not exist python-installer.exe (
        echo Failed to download the installer.
        pause
        exit /b
    )
    echo Installer downloaded.
    echo Starting Python installation...

    :: Automatically launches the downloaded file
    start python-installer.exe

    echo After completing the Python installation, press any key to continue...
    pause

    echo Please restart your computer and rerun the program to ensure the PATH is updated.
    pause

    :: Finish the program, offering to restart the computer
    exit /b
) else (
    echo Invalid choice. Exiting the program.
    pause
    exit /b
)

:check_python_again
:: Rechecking Python installation in PATH
echo Rechecking Python installation in PATH...
set python_found=0

for %%P in ("%PATH:;=" "%") do (
    if exist "%%~P\python.exe" (
        set python_found=1
        set python_path=%%~P\python.exe
        goto :python_found
    )
)

if %python_found%==0 (
    echo Python installation not detected. Please ensure Python is installed correctly.
    pause
    exit /b
)

:python_found
:: Check if Python is actually working
"%python_path%" --version > nul 2>&1
if %errorlevel% neq 0 (
    echo Python placeholder detected or not functioning.
    goto :python_not_found
)

echo Python is correctly installed at "%python_path%".
echo Proceeding to library check...

:: Update pip
echo Updating pip...
"%python_path%" -m pip install --upgrade pip

:: Update all libraries
echo Updating required libraries...
for %%L in (google-api-python-client google-auth google-auth-oauthlib) do (
    echo Updating library: %%L
    "%python_path%" -m pip install --upgrade %%L
    if %errorlevel% neq 0 (
        echo Failed to update library: %%L. Exiting...
        pause
        exit /b
    )
)

echo All required libraries have been successfully updated.
exit /b
