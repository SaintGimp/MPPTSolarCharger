EESchema Schematic File Version 4
LIBS:MPPTSolarCharger-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2550 1400 1550 1100
U 5BBDF12D
F0 "PowerStage" 50
F1 "PowerStage.sch" 50
F2 "SDA" I R 4100 1950 50 
F3 "SCL" I R 4100 2100 50 
F4 "HIGH_PWM" I R 4100 1650 50 
F5 "LOW_PWM" I R 4100 1800 50 
$EndSheet
$Sheet
S 5150 1400 1650 1150
U 5BBE0747
F0 "MCU" 50
F1 "MCU.sch" 50
F2 "SDA" I L 5150 1950 50 
F3 "SCL" I L 5150 2100 50 
F4 "LOW_PWM" I L 5150 1800 50 
F5 "HIGH_PWM" I L 5150 1650 50 
$EndSheet
Wire Wire Line
	5150 1650 4100 1650
Wire Wire Line
	5150 1800 4100 1800
Wire Wire Line
	5150 1950 4100 1950
Wire Wire Line
	5150 2100 4100 2100
$EndSCHEMATC
