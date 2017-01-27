/*

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# Copyright (C) 2017 Malcolm Lewis <malcolmlewis@opensuse.org>

*/

/*
#
# Name: pcd8544_bl_ctrl.c:
# Version: 0.1
# Date: Jan 25, 2017
# Used with a SunFounder Mini LCD 5110 84*48 PCD8544 Based Shield with Backlight
# See https://www.sunfounder.com/wiki/index.php?title=Raspberry_Pi_5110_Mini_LCD_84*48_PCD8544_Usage
#
 */

#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>

int main(int argc, char *argv[]) {

	if (wiringPiSetup () == -1) {
		printf("wiringPi-Error\n");
	return 1 ;
	}

	/* This is GPIO 7, BCM_GPIO 4, Pin 7 */
	pinMode (7, OUTPUT);
	int chk;
	int flash = 0;
	int select = 0;

	while ((chk = getopt(argc, argv, "ofb")) != EOF) {

		switch (chk) {

		case 'o':
			if (select == 0) {
				printf("Turning PCD8544 backlight ON\n");
				digitalWrite (7, 0);
				select = 1;
			}
			break;
		case 'f':
			if (select == 0) {
				printf("Turning PCD8544 backlight OFF\n");
				digitalWrite (7, 1);
				select = 1;
				/* Reset to input */
				pinMode (7, INPUT);
			}
			break;
		case 'b':
			if (select == 0) {
				printf("Flash PCD8544 backlight 5 times\n");
				for ( flash = 0; flash < 5; flash = flash + 1 ){
					digitalWrite (7, 0);
					delay (750);
					digitalWrite (7, 1);
					delay (750);
				}
				select = 1;
				/* Reset to input */
				pinMode (7, INPUT);
			}
			break;
		default:
			(void)fprintf(stderr, "Usage: pcd8544_bl_ctrl [-o(on) -f(off) -b(flash 5 times)]\n");
			return(2);
		}
	}
	return(0);
}
