EESchema Schematic File Version 4
LIBS:MPPTSolarCharger-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 5BBDF4F8
P 800 1800
AR Path="/5BBDF4F8" Ref="J?"  Part="1" 
AR Path="/5BBDF12D/5BBDF4F8" Ref="J1"  Part="1" 
F 0 "J1" H 720 1925 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 720 1926 50  0001 C CNN
F 2 "Saintgimp:Phoenix_Contact_MKDS_5-2-952" H 800 1800 50  0001 C CNN
F 3 "~" H 800 1800 50  0001 C CNN
	1    800  1800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1000 1800 1550 1800
Wire Wire Line
	1550 1800 1550 1250
Wire Wire Line
	1550 1250 1800 1250
$Comp
L Device:C C?
U 1 1 5BBDF502
P 1800 1850
AR Path="/5BBDF502" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF502" Ref="C1"  Part="1" 
F 0 "C1" H 1915 1896 50  0000 L CNN
F 1 "1uF" H 1915 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1838 1700 50  0001 C CNN
F 3 "~" H 1800 1850 50  0001 C CNN
	1    1800 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5BBDF509
P 2750 1850
AR Path="/5BBDF509" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF509" Ref="C3"  Part="1" 
F 0 "C3" H 2868 1896 50  0000 L CNN
F 1 "1000uF" H 2868 1805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D16.0mm_P7.50mm" H 2788 1700 50  0001 C CNN
F 3 "~" H 2750 1850 50  0001 C CNN
	1    2750 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5BBDF510
P 3300 1850
AR Path="/5BBDF510" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF510" Ref="C4"  Part="1" 
F 0 "C4" H 3418 1896 50  0000 L CNN
F 1 "1000uF" H 3418 1805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D16.0mm_P7.50mm" H 3338 1700 50  0001 C CNN
F 3 "~" H 3300 1850 50  0001 C CNN
	1    3300 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BBDF517
P 4550 1850
AR Path="/5BBDF517" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF517" Ref="C5"  Part="1" 
F 0 "C5" H 4665 1896 50  0000 L CNN
F 1 "4.7uF" H 4665 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 4588 1700 50  0001 C CNN
F 3 "~" H 4550 1850 50  0001 C CNN
	1    4550 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BBDF51E
P 5050 1850
AR Path="/5BBDF51E" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF51E" Ref="C7"  Part="1" 
F 0 "C7" H 5165 1896 50  0000 L CNN
F 1 "4.7uF" H 5165 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 5088 1700 50  0001 C CNN
F 3 "~" H 5050 1850 50  0001 C CNN
	1    5050 1850
	1    0    0    -1  
$EndComp
Text Label 1100 1800 0    50   ~ 0
SOLAR+
Connection ~ 2750 1250
Wire Wire Line
	4550 1250 5050 1250
Connection ~ 1800 1250
$Comp
L SaintGimp:PSMN5R5-60YS Q?
U 1 1 5BBDF531
P 2150 2550
AR Path="/5BBDF531" Ref="Q?"  Part="1" 
AR Path="/5BBDF12D/5BBDF531" Ref="Q1"  Part="1" 
F 0 "Q1" V 2402 2550 50  0000 C CNN
F 1 "PSMN5R5-60YS" V 2402 2550 50  0001 C CNN
F 2 "Package_TO_SOT_SMD:LFPAK56" H 2300 2550 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PSMN5R5-60YS.pdf" H 2150 2550 50  0001 C CNN
	1    2150 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1000 1900 1550 1900
Wire Wire Line
	1550 1900 1550 2250
Wire Wire Line
	1550 2250 1800 2250
Wire Wire Line
	1800 2000 1800 2250
Connection ~ 1800 2250
Wire Wire Line
	2750 2000 2750 2450
Connection ~ 2750 2450
Wire Wire Line
	3300 2000 3300 2450
Wire Wire Line
	3300 2450 4550 2450
Wire Wire Line
	4550 2000 4550 2450
Connection ~ 4550 2450
Wire Wire Line
	4550 2450 5050 2450
Wire Wire Line
	5050 2000 5050 2450
Connection ~ 5050 2450
$Comp
L Device:R R?
U 1 1 5BBDF546
P 2500 2700
AR Path="/5BBDF546" Ref="R?"  Part="1" 
AR Path="/5BBDF12D/5BBDF546" Ref="R1"  Part="1" 
F 0 "R1" H 2570 2746 50  0000 L CNN
F 1 "1M" H 2570 2655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2430 2700 50  0001 C CNN
F 3 "~" H 2500 2700 50  0001 C CNN
	1    2500 2700
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5BBDF54D
P 3100 2950
AR Path="/5BBDF54D" Ref="D?"  Part="1" 
AR Path="/5BBDF12D/5BBDF54D" Ref="D1"  Part="1" 
F 0 "D1" H 3100 3166 50  0000 C CNN
F 1 "1N4148" H 3100 3075 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 3100 2775 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 3100 2950 50  0001 C CNN
	1    3100 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBDF554
P 9650 2550
AR Path="/5BBDF554" Ref="#PWR?"  Part="1" 
AR Path="/5BBDF12D/5BBDF554" Ref="#PWR09"  Part="1" 
F 0 "#PWR09" H 9650 2300 50  0001 C CNN
F 1 "GND" H 9655 2377 50  0000 C CNN
F 2 "" H 9650 2550 50  0001 C CNN
F 3 "" H 9650 2550 50  0001 C CNN
	1    9650 2550
	1    0    0    -1  
$EndComp
$Comp
L SaintGimp:PSMN5R5-60YS Q?
U 1 1 5BBDF55A
P 6150 1350
AR Path="/5BBDF55A" Ref="Q?"  Part="1" 
AR Path="/5BBDF12D/5BBDF55A" Ref="Q2"  Part="1" 
F 0 "Q2" V 6402 1350 50  0000 C CNN
F 1 "PSMN5R5-60YS" H 6355 1305 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK56" H 6300 1350 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PSMN5R5-60YS.pdf" H 6150 1350 50  0001 C CNN
	1    6150 1350
	0    -1   -1   0   
$EndComp
$Comp
L SaintGimp:PSMN5R5-60YS Q?
U 1 1 5BBDF561
P 6400 2200
AR Path="/5BBDF561" Ref="Q?"  Part="1" 
AR Path="/5BBDF12D/5BBDF561" Ref="Q3"  Part="1" 
F 0 "Q3" H 6605 2200 50  0000 L CNN
F 1 "PSMN5R5-60YS" H 6605 2155 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK56" H 6550 2200 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PSMN5R5-60YS.pdf" H 6400 2200 50  0001 C CNN
	1    6400 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BBDF568
P 5900 1600
AR Path="/5BBDF568" Ref="R?"  Part="1" 
AR Path="/5BBDF12D/5BBDF568" Ref="R4"  Part="1" 
F 0 "R4" V 6107 1600 50  0000 C CNN
F 1 "3.3" V 6016 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5830 1600 50  0001 C CNN
F 3 "~" H 5900 1600 50  0001 C CNN
	1    5900 1600
	0    -1   -1   0   
$EndComp
Connection ~ 3300 2450
Text Label 6550 1250 0    50   ~ 0
SWITCH_NODE
Text Label 1100 1900 0    50   ~ 0
SOLAR-
$Comp
L Device:L_Core_Ferrite L?
U 1 1 5BBDF57D
P 7400 1250
AR Path="/5BBDF57D" Ref="L?"  Part="1" 
AR Path="/5BBDF12D/5BBDF57D" Ref="L1"  Part="1" 
F 0 "L1" V 7222 1250 50  0000 C CNN
F 1 "22uH" V 7313 1250 50  0000 C CNN
F 2 "Saintgimp:Coilcraft_SER2900" H 7400 1250 50  0001 C CNN
F 3 "~" H 7400 1250 50  0001 C CNN
	1    7400 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BBDF584
P 6950 1800
AR Path="/5BBDF584" Ref="R?"  Part="1" 
AR Path="/5BBDF12D/5BBDF584" Ref="R6"  Part="1" 
F 0 "R6" H 7020 1846 50  0000 L CNN
F 1 "2.2" H 7020 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 6880 1800 50  0001 C CNN
F 3 "~" H 6950 1800 50  0001 C CNN
	1    6950 1800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BBDF58B
P 6950 2150
AR Path="/5BBDF58B" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF58B" Ref="C8"  Part="1" 
F 0 "C8" H 7065 2196 50  0000 L CNN
F 1 "1nF" H 7065 2105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6988 2000 50  0001 C CNN
F 3 "~" H 6950 2150 50  0001 C CNN
	1    6950 2150
	1    0    0    -1  
$EndComp
Connection ~ 6950 1250
Wire Wire Line
	6950 1250 7250 1250
Wire Wire Line
	6950 1950 6950 2000
Wire Wire Line
	6950 2300 6950 2450
Connection ~ 6950 2450
Wire Wire Line
	6950 2450 7750 2450
Wire Wire Line
	7550 1250 7650 1250
$Comp
L Device:CP C?
U 1 1 5BBDF59A
P 7750 1850
AR Path="/5BBDF59A" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF59A" Ref="C10"  Part="1" 
F 0 "C10" H 7868 1896 50  0000 L CNN
F 1 "1000uF" H 7868 1805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D16.0mm_P7.50mm" H 7788 1700 50  0001 C CNN
F 3 "~" H 7750 1850 50  0001 C CNN
	1    7750 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 2000 7750 2450
Wire Wire Line
	1800 1250 2750 1250
Wire Wire Line
	1800 2250 1900 2250
Wire Wire Line
	2750 2450 3300 2450
Wire Wire Line
	2750 1250 3300 1250
$Sheet
S 3700 1150 550  400 
U 5BBDF5A7
F0 "SolarCurrentMonitor" 50
F1 "SolarCurrentMonitor.sch" 50
F2 "IN+" I L 3700 1250 50 
F3 "IN-" I R 4250 1250 50 
F4 "SDA" I R 4250 1350 50 
F5 "SCL" I R 4250 1450 50 
$EndSheet
Wire Wire Line
	5950 1250 5800 1250
Wire Wire Line
	6350 1250 6400 1250
Wire Wire Line
	6500 2000 6500 1250
Connection ~ 6500 1250
Wire Wire Line
	6500 1250 6950 1250
Wire Wire Line
	6500 2450 6500 2400
Wire Wire Line
	6500 2450 5050 2450
Connection ~ 6500 2450
Wire Wire Line
	6500 2450 6950 2450
Wire Wire Line
	6050 1600 6150 1600
Wire Wire Line
	6150 1600 6150 1550
Wire Wire Line
	6200 2200 6150 2200
Connection ~ 6150 2200
Wire Wire Line
	6150 2950 6150 2200
Wire Wire Line
	3250 2950 6150 2950
Wire Wire Line
	2150 2750 2150 2950
Wire Wire Line
	2500 2950 2950 2950
Wire Wire Line
	2150 2950 2500 2950
Connection ~ 2500 2950
Wire Wire Line
	2500 2850 2500 2950
Wire Wire Line
	2500 2450 2750 2450
Wire Wire Line
	2350 2450 2500 2450
Connection ~ 2500 2450
Wire Wire Line
	2500 2550 2500 2450
$Sheet
S 8300 1150 550  400 
U 5BBDF5CE
F0 "BatteryCurrentMonitor" 50
F1 "BatteryCurrentMonitor.sch" 50
F2 "IN+" I L 8300 1250 50 
F3 "IN-" I R 8850 1250 50 
F4 "SDA" B R 8850 1350 50 
F5 "SCL" B R 8850 1450 50 
$EndSheet
$Comp
L Device:Fuse F?
U 1 1 5BBDF5D4
P 9300 1250
AR Path="/5BBDF5D4" Ref="F?"  Part="1" 
AR Path="/5BBDF12D/5BBDF5D4" Ref="F1"  Part="1" 
F 0 "F1" V 9103 1250 50  0000 C CNN
F 1 "Fuse" V 9194 1250 50  0000 C CNN
F 2 "Fuse:Fuseholder_Blade_ATO_Littelfuse_Pudenz_2_Pin" V 9230 1250 50  0001 C CNN
F 3 "~" H 9300 1250 50  0001 C CNN
	1    9300 1250
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 5BBDF5DC
P 10700 1800
AR Path="/5BBDF5DC" Ref="J?"  Part="1" 
AR Path="/5BBDF12D/5BBDF5DC" Ref="J2"  Part="1" 
F 0 "J2" H 10780 1746 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 10780 1701 50  0001 L CNN
F 2 "Saintgimp:Phoenix_Contact_MKDS_5-2-952" H 10700 1800 50  0001 C CNN
F 3 "~" H 10700 1800 50  0001 C CNN
	1    10700 1800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BBDF5E3
P 9650 1850
AR Path="/5BBDF5E3" Ref="C?"  Part="1" 
AR Path="/5BBDF12D/5BBDF5E3" Ref="C13"  Part="1" 
F 0 "C13" H 9765 1896 50  0000 L CNN
F 1 "1uF" H 9765 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9688 1700 50  0001 C CNN
F 3 "~" H 9650 1850 50  0001 C CNN
	1    9650 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1250 9450 1250
Wire Wire Line
	9650 2450 9650 2000
Connection ~ 7750 2450
Wire Wire Line
	10500 1800 10000 1800
Wire Wire Line
	10000 1800 10000 1250
Wire Wire Line
	10500 1900 10000 1900
Wire Wire Line
	10000 1900 10000 2450
Wire Wire Line
	10000 2450 9650 2450
Connection ~ 9650 2450
Text Label 10100 1800 0    50   ~ 0
BATTERY+
Text Label 10100 1900 0    50   ~ 0
BATTERY-
Wire Wire Line
	5750 1600 5250 1600
Wire Wire Line
	4250 1450 4300 1450
Text HLabel 4300 1350 2    50   Input ~ 0
SDA
Wire Wire Line
	4250 1350 4300 1350
Text HLabel 4300 1450 2    50   Input ~ 0
SCL
Wire Wire Line
	8850 1350 8900 1350
Wire Wire Line
	8850 1450 8900 1450
Text HLabel 8900 1350 2    50   BiDi ~ 0
SDA
Text HLabel 8900 1450 2    50   BiDi ~ 0
SCL
Text Label 5250 1600 0    50   ~ 0
HIGH_DRIVER
Text Label 5250 2200 0    50   ~ 0
LOW_DRIVER
Text HLabel 6400 4050 0    50   Input ~ 0
HIGH_PWM
Text HLabel 6400 4200 0    50   Input ~ 0
LOW_PWM
Wire Wire Line
	10000 1250 9650 1250
Connection ~ 9650 1250
Wire Wire Line
	9150 1250 8850 1250
Connection ~ 7750 1250
Wire Wire Line
	9650 2550 9650 2450
$Comp
L SaintGimp:MIC4605-1YM U2
U 1 1 5BC0066C
P 6900 4250
AR Path="/5BC0066C" Ref="U2"  Part="1" 
AR Path="/5BBDF12D/5BC0066C" Ref="U2"  Part="1" 
F 0 "U2" H 6700 4650 50  0000 C CNN
F 1 "MIC4605-1YM" H 6350 4050 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6900 4250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/MIC4605-85V-Half-Bridge-MOSFET-Driver-DS20005853B.pdf" H 6900 4250 50  0001 C CNN
	1    6900 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4050 6400 4050
Wire Wire Line
	6400 4200 6450 4200
Wire Wire Line
	7350 4200 7850 4200
Wire Wire Line
	7350 4500 7850 4500
Text Label 7400 4200 0    50   ~ 0
HIGH_DRIVER
Text Label 7400 4500 0    50   ~ 0
LOW_DRIVER
$Comp
L Device:C C12
U 1 1 5BC0F5BB
P 5650 4250
F 0 "C12" H 5765 4296 50  0000 L CNN
F 1 "1uF" H 5765 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5688 4100 50  0001 C CNN
F 3 "~" H 5650 4250 50  0001 C CNN
	1    5650 4250
	1    0    0    -1  
$EndComp
Text Label 7850 1250 0    50   ~ 0
BUCK_OUT
$Comp
L Device:C C9
U 1 1 5BC173D6
P 8850 4200
F 0 "C9" H 8965 4246 50  0000 L CNN
F 1 "1uF" H 8965 4155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8888 4050 50  0001 C CNN
F 3 "~" H 8850 4200 50  0001 C CNN
	1    8850 4200
	-1   0    0    -1  
$EndComp
Text Label 9450 4350 2    50   ~ 0
SWITCH_NODE
$Comp
L Device:R R7
U 1 1 5BC1FA9E
P 8400 4350
F 0 "R7" V 8300 4350 50  0000 C CNN
F 1 "3" V 8500 4350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8330 4350 50  0001 C CNN
F 3 "~" H 8400 4350 50  0001 C CNN
	1    8400 4350
	0    -1   1    0   
$EndComp
Wire Wire Line
	8250 4350 8150 4350
Wire Wire Line
	8150 4350 8150 4800
Connection ~ 8150 4350
$Comp
L Diode:1N4148 D2
U 1 1 5BC340ED
P 8150 5000
F 0 "D2" V 8104 5079 50  0000 L CNN
F 1 "1N4148" V 8195 5079 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 8150 4825 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 8150 5000 50  0001 C CNN
	1    8150 5000
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5BC341D5
P 8150 5150
F 0 "#PWR05" H 8150 4900 50  0001 C CNN
F 1 "GND" H 8155 4977 50  0000 C CNN
F 2 "" H 8150 5150 50  0001 C CNN
F 3 "" H 8150 5150 50  0001 C CNN
	1    8150 5150
	-1   0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM350_TO220 U1
U 1 1 5BC45611
P 3250 3850
F 0 "U1" H 3250 4092 50  0000 C CNN
F 1 "LM350_TO220" H 3250 4001 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3250 4100 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM350.pdf" H 3250 3850 50  0001 C CNN
	1    3250 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 3850 2800 3850
$Comp
L Device:C C2
U 1 1 5BC4D102
P 2800 4150
F 0 "C2" H 2915 4196 50  0000 L CNN
F 1 "100nF" H 2915 4105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2838 4000 50  0001 C CNN
F 3 "~" H 2800 4150 50  0001 C CNN
	1    2800 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4000 2800 3850
Connection ~ 2800 3850
$Comp
L power:GND #PWR01
U 1 1 5BC4FA62
P 2800 4300
F 0 "#PWR01" H 2800 4050 50  0001 C CNN
F 1 "GND" H 2805 4127 50  0000 C CNN
F 2 "" H 2800 4300 50  0001 C CNN
F 3 "" H 2800 4300 50  0001 C CNN
	1    2800 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5BC4FBCF
P 3750 4050
F 0 "R2" H 3820 4096 50  0000 L CNN
F 1 "150" H 3820 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3680 4050 50  0001 C CNN
F 3 "~" H 3750 4050 50  0001 C CNN
	1    3750 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5BC4FC7E
P 3750 4500
F 0 "R3" H 3820 4546 50  0000 L CNN
F 1 "1000" H 3820 4455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3680 4500 50  0001 C CNN
F 3 "~" H 3750 4500 50  0001 C CNN
	1    3750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3850 3750 3850
Wire Wire Line
	3750 3900 3750 3850
Connection ~ 3750 3850
Wire Wire Line
	3750 4200 3750 4250
Wire Wire Line
	3250 4250 3250 4150
Wire Wire Line
	3250 4250 3750 4250
Connection ~ 3750 4250
Wire Wire Line
	3750 4250 3750 4350
$Comp
L power:GND #PWR02
U 1 1 5BC5B3BA
P 3750 4650
F 0 "#PWR02" H 3750 4400 50  0001 C CNN
F 1 "GND" H 3755 4477 50  0000 C CNN
F 2 "" H 3750 4650 50  0001 C CNN
F 3 "" H 3750 4650 50  0001 C CNN
	1    3750 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+10V #PWR06
U 1 1 5BC5B597
P 6900 3650
F 0 "#PWR06" H 6900 3500 50  0001 C CNN
F 1 "+10V" H 6915 3823 50  0000 C CNN
F 2 "" H 6900 3650 50  0001 C CNN
F 3 "" H 6900 3650 50  0001 C CNN
	1    6900 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+10V #PWR04
U 1 1 5BC619F0
P 4600 3750
F 0 "#PWR04" H 4600 3600 50  0001 C CNN
F 1 "+10V" H 4615 3923 50  0000 C CNN
F 2 "" H 4600 3750 50  0001 C CNN
F 3 "" H 4600 3750 50  0001 C CNN
	1    4600 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3850 4600 3750
Wire Wire Line
	3750 3850 4150 3850
$Comp
L Device:CP C6
U 1 1 5BC64FFD
P 4150 4050
F 0 "C6" H 4268 4096 50  0000 L CNN
F 1 "100uF" H 4268 4005 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 4188 3900 50  0001 C CNN
F 3 "~" H 4150 4050 50  0001 C CNN
	1    4150 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5BC650B0
P 4150 4200
F 0 "#PWR03" H 4150 3950 50  0001 C CNN
F 1 "GND" H 4155 4027 50  0000 C CNN
F 2 "" H 4150 4200 50  0001 C CNN
F 3 "" H 4150 4200 50  0001 C CNN
	1    4150 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3900 4150 3850
Connection ~ 4150 3850
Wire Wire Line
	1800 1250 1800 1700
Wire Wire Line
	2750 1250 2750 1700
Wire Wire Line
	7750 1250 7750 1700
Wire Wire Line
	9650 1250 9650 1700
Wire Wire Line
	6950 1250 6950 1650
Wire Wire Line
	4550 1250 4550 1700
$Comp
L Device:Jumper_NC_Dual JP1
U 1 1 5BC9C85B
P 2000 3600
F 0 "JP1" H 2000 3748 50  0000 C CNN
F 1 "Jumper_NC_Dual" H 2000 3748 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2000 3600 50  0001 C CNN
F 3 "~" H 2000 3600 50  0001 C CNN
	1    2000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3850 2000 3700
Wire Wire Line
	2000 3850 2800 3850
Wire Wire Line
	2250 3600 2700 3600
Wire Wire Line
	1750 3600 1400 3600
Text Label 1400 3600 0    50   ~ 0
SOLAR+
Text Label 2700 3600 2    50   ~ 0
BUCK_OUT
Wire Wire Line
	4150 3850 4600 3850
$Comp
L Connector:TestPoint_Probe TP4
U 1 1 5BCBBCB9
P 6400 1100
F 0 "TP4" H 6553 1156 50  0000 L CNN
F 1 "TestPoint_Probe" H 6553 1111 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 6600 1100 50  0001 C CNN
F 3 "~" H 6600 1100 50  0001 C CNN
	1    6400 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1100 6400 1250
Connection ~ 6400 1250
Wire Wire Line
	6400 1250 6500 1250
$Comp
L Connector:TestPoint_Probe TP3
U 1 1 5BCBF371
P 6200 1600
F 0 "TP3" H 6353 1656 50  0000 L CNN
F 1 "TestPoint_Probe" H 6353 1611 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 6400 1600 50  0001 C CNN
F 3 "~" H 6400 1600 50  0001 C CNN
	1    6200 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1600 6150 1600
Connection ~ 6150 1600
$Comp
L Connector:TestPoint_Probe TP2
U 1 1 5BCC2B39
P 6150 2100
F 0 "TP2" H 6303 2156 50  0000 L CNN
F 1 "TestPoint_Probe" H 6303 2111 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 6350 2100 50  0001 C CNN
F 3 "~" H 6350 2100 50  0001 C CNN
	1    6150 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2100 6150 2200
$Comp
L Connector:TestPoint_Probe TP1
U 1 1 5BCC63CA
P 5800 1100
F 0 "TP1" H 5953 1156 50  0000 L CNN
F 1 "TestPoint_Probe" H 5953 1111 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 6000 1100 50  0001 C CNN
F 3 "~" H 6000 1100 50  0001 C CNN
	1    5800 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1100 5800 1250
$Comp
L Connector:TestPoint_Probe TP6
U 1 1 5BCC9D4A
P 7650 1100
F 0 "TP6" H 7803 1156 50  0000 L CNN
F 1 "TestPoint_Probe" H 7803 1111 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 7850 1100 50  0001 C CNN
F 3 "~" H 7850 1100 50  0001 C CNN
	1    7650 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 1100 7650 1250
Connection ~ 7650 1250
Wire Wire Line
	7650 1250 7750 1250
$Comp
L Connector:TestPoint_Probe TP5
U 1 1 5BCCDF03
P 8100 4800
F 0 "TP5" H 8253 4856 50  0000 L CNN
F 1 "TestPoint_Probe" H 8253 4811 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 8300 4800 50  0001 C CNN
F 3 "~" H 8300 4800 50  0001 C CNN
	1    8100 4800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8100 4800 8150 4800
Connection ~ 8150 4800
Wire Wire Line
	8150 4800 8150 4850
Wire Wire Line
	5050 1250 5050 1700
Text Label 7400 4350 0    50   ~ 0
HS
Wire Wire Line
	3700 1250 3300 1250
Connection ~ 3300 1250
Wire Wire Line
	4250 1250 4550 1250
Connection ~ 4550 1250
Wire Wire Line
	5050 1250 5800 1250
Connection ~ 5050 1250
Connection ~ 5800 1250
Wire Wire Line
	1900 2450 1950 2450
Wire Wire Line
	1900 2250 1900 2450
Wire Wire Line
	3300 1250 3300 1700
Wire Wire Line
	7750 1250 8300 1250
Wire Wire Line
	7750 2450 9650 2450
Wire Wire Line
	7350 4350 8150 4350
Wire Wire Line
	8550 4350 8850 4350
Connection ~ 8850 4350
Wire Wire Line
	8850 4350 9450 4350
Wire Wire Line
	7350 4050 8850 4050
Text Label 7400 4050 0    50   ~ 0
HB
Text Notes 4450 2850 0    50   ~ 0
An external resistor between the\nLO output and the MOSFET may affect\nthe performance of the LO pin monitoring\ncircuit and is not recommended.
Wire Wire Line
	5250 2200 6150 2200
Text Notes 4450 3400 0    50   ~ 0
Adding a series resistor in the switch node limits the\npeak high-side driver current during turn-off, which\naffects the switching speed of the high-side driver. The\nresistor in series with the HO pin may be reduced to\nhelp compensate for the extra HS pin resistance.
Wire Wire Line
	6900 3650 6900 3700
Wire Wire Line
	6900 3700 5650 3700
Wire Wire Line
	5650 3700 5650 4100
Connection ~ 6900 3700
$Comp
L power:GND #PWR07
U 1 1 5BC0D619
P 6900 4850
F 0 "#PWR07" H 6900 4600 50  0001 C CNN
F 1 "GND" H 6905 4677 50  0000 C CNN
F 2 "" H 6900 4850 50  0001 C CNN
F 3 "" H 6900 4850 50  0001 C CNN
	1    6900 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4850 5650 4850
Wire Wire Line
	5650 4850 5650 4400
Connection ~ 6900 4850
$EndSCHEMATC
