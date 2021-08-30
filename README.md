# ETCetera Calibration Tool
For reading calibration files for the gold box and eventually working with the ETC.

# Build/Develop

On Windows, install Visual Studio Community 2019 or later and then install
[Craft](https://community.kde.org/Craft). On Linux, install GCC for C++ and
CMake. Then, use Craft (on Windows) or your distribution's package manager
(on Linux) to install the following dependencies:

 - Qt 5 Base
 - Qt 5 GUI
 - Qt 5 Widgets
 - Extra CMake Modules (ECM)
 - KCoreAddons
 - KXMLGUI
 - KWidgetsAddons
 - KUnitConversion
 - Ki18n

The procedure is the same no matter whether you're running from the Craft
PowerShell environment or from your normal *nix shell. Navigate to this
folder (cloned from git of course) then do the usual

~~~
mkdir build
cd build
cmake ..
~~~

On Windows, this will create a Visual Studio solution file (.sln). On
Linux, it will create a Makefile. Open the VS solution and build it, or
run `make` (on Linux).