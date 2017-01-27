# pcd8544_bl_ctrl
pcd8544_bl_ctrl
=====================
Command line tool to control the Sunfounder PCD8544 Backlight.

INTRODUCTION
---------------------
A simple c program to pass options to the Raspberry Pi 3
BCM_GPIO 4, wiringPi 7 to turn on, off or blink the PCD8544 backlight.

INSTALLATION
---------------------
Ensure that gcc, make and wiringPi-devel packages are installed.

Unpack the source;
tar xvf pcd8544_bl_ctrl-{version}.tar.gz
cd pcd8544_bl_ctrl-{version}
make
{Switch to root user and cd to build directory}
make install

Prebuilt rpms are available on the openSUSE Build Service at;
https://software.opensuse.org/package/pcd8544_bl_ctrl

USAGE
---------------------
You need to be root user...

pcd8544_bl_ctrl -o - Turn on backlight.

pcd8544_bl_ctrl -f - Turn off backlight.

pcd8544_bl_ctrl -b - Turn backlight flash/blink 5 times.

CONTACTING THE AUTHOR
---------------------
I can be contacted at: malcolmlewis -at- opensuse -dot- org
