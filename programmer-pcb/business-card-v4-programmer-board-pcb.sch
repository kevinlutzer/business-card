EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Business Card PCB Programmer"
Date "2020-08-08"
Rev "3"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x05_Male J1
U 1 1 5EB8EC61
P 2400 3650
F 0 "J1" H 2508 4031 50  0000 C CNN
F 1 "Pogo_Pin_Conn" V 2350 3650 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 2400 3650 50  0001 C CNN
F 3 "~" H 2400 3650 50  0001 C CNN
	1    2400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 5EB8F728
P 2650 3900
F 0 "#PWR0103" H 2650 3750 50  0001 C CNN
F 1 "+3.3V" H 2665 4073 50  0000 C CNN
F 2 "" H 2650 3900 50  0001 C CNN
F 3 "" H 2650 3900 50  0001 C CNN
	1    2650 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 3450 2650 3450
Wire Wire Line
	2650 3450 2650 3400
$Comp
L power:GND #PWR0104
U 1 1 5EB90733
P 2650 3400
F 0 "#PWR0104" H 2650 3150 50  0001 C CNN
F 1 "GND" H 2655 3227 50  0000 C CNN
F 2 "" H 2650 3400 50  0001 C CNN
F 3 "" H 2650 3400 50  0001 C CNN
	1    2650 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 3850 2650 3850
Wire Wire Line
	2650 3850 2650 3900
Text GLabel 2650 3650 2    50   Input ~ 0
RST
Text GLabel 2650 3550 2    50   Input ~ 0
SWCLK
Text GLabel 2650 3750 2    50   Input ~ 0
SWDIO
Wire Wire Line
	2600 3550 2650 3550
Wire Wire Line
	2600 3650 2650 3650
Wire Wire Line
	2600 3750 2650 3750
$Comp
L Connector:Conn_01x01_Male J2
U 1 1 5EB92E80
P 2450 4350
F 0 "J2" H 2558 4531 50  0000 C CNN
F 1 "Power_TP" H 2558 4440 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 2450 4350 50  0001 C CNN
F 3 "~" H 2450 4350 50  0001 C CNN
	1    2450 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5EB937DF
P 2750 4350
F 0 "#PWR0105" H 2750 4200 50  0001 C CNN
F 1 "+5V" V 2765 4478 50  0000 L CNN
F 2 "" H 2750 4350 50  0001 C CNN
F 3 "" H 2750 4350 50  0001 C CNN
	1    2750 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	2650 4350 2750 4350
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J3
U 1 1 5EB9F754
P 1350 3750
F 0 "J3" H 1400 4150 50  0000 C CNN
F 1 "Programmer_Conn" H 1550 4050 50  0000 C CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_2x05_P2.00mm_Vertical_SMD" H 1350 3750 50  0001 C CNN
F 3 "~" H 1350 3750 50  0001 C CNN
	1    1350 3750
	-1   0    0    1   
$EndComp
Text GLabel 1000 3550 0    50   Input ~ 0
SWDIO
Text GLabel 1000 3650 0    50   Input ~ 0
SWCLK
Text GLabel 1000 3950 0    50   Input ~ 0
RST
$Comp
L power:+3.3V #PWR0111
U 1 1 5EBA0E25
P 1600 3500
F 0 "#PWR0111" H 1600 3350 50  0001 C CNN
F 1 "+3.3V" H 1615 3673 50  0000 C CNN
F 2 "" H 1600 3500 50  0001 C CNN
F 3 "" H 1600 3500 50  0001 C CNN
	1    1600 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5EBA240B
P 1600 4000
F 0 "#PWR0112" H 1600 3750 50  0001 C CNN
F 1 "GND" H 1605 3827 50  0000 C CNN
F 2 "" H 1600 4000 50  0001 C CNN
F 3 "" H 1600 4000 50  0001 C CNN
	1    1600 4000
	1    0    0    -1  
$EndComp
$Comp
L dk_PMIC-Voltage-Regulators-Linear:L7805CV U2
U 1 1 5EBA737E
P 1900 1250
F 0 "U2" H 1900 1537 60  0000 C CNN
F 1 "L7805CV" H 1900 1431 60  0000 C CNN
F 2 "digikey-footprints:TO-220-3" H 2100 1450 60  0001 L CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2100 1550 60  0001 L CNN
F 4 "497-1443-5-ND" H 2100 1650 60  0001 L CNN "Digi-Key_PN"
F 5 "L7805CV" H 2100 1750 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 2100 1850 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 2100 1950 60  0001 L CNN "Family"
F 8 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2100 2050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/stmicroelectronics/L7805CV/497-1443-5-ND/585964" H 2100 2150 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 5V 1.5A TO220AB" H 2100 2250 60  0001 L CNN "Description"
F 11 "STMicroelectronics" H 2100 2350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 2450 60  0001 L CNN "Status"
	1    1900 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0113
U 1 1 5EBA7FCA
P 1500 1150
F 0 "#PWR0113" H 1500 1000 50  0001 C CNN
F 1 "+12V" H 1515 1323 50  0000 C CNN
F 2 "" H 1500 1150 50  0001 C CNN
F 3 "" H 1500 1150 50  0001 C CNN
	1    1500 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0114
U 1 1 5EBA8657
P 3300 850
F 0 "#PWR0114" H 3300 700 50  0001 C CNN
F 1 "+5V" H 3315 1023 50  0000 C CNN
F 2 "" H 3300 850 50  0001 C CNN
F 3 "" H 3300 850 50  0001 C CNN
	1    3300 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1150 1500 1250
Wire Wire Line
	1500 1250 1600 1250
Wire Wire Line
	2200 1250 2300 1250
$Comp
L Device:C C2
U 1 1 5EBAB85E
P 2300 1400
F 0 "C2" H 2415 1446 50  0000 L CNN
F 1 "1u" H 2415 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2338 1250 50  0001 C CNN
F 3 "~" H 2300 1400 50  0001 C CNN
	1    2300 1400
	1    0    0    -1  
$EndComp
Connection ~ 2300 1250
Wire Wire Line
	1500 1550 1500 1650
Wire Wire Line
	1500 1650 1900 1650
Wire Wire Line
	2300 1650 2300 1550
Wire Wire Line
	1900 1550 1900 1650
Connection ~ 1900 1650
Wire Wire Line
	1900 1650 2300 1650
$Comp
L power:GND #PWR0115
U 1 1 5EBAD99C
P 1900 1700
F 0 "#PWR0115" H 1900 1450 50  0001 C CNN
F 1 "GND" H 1905 1527 50  0000 C CNN
F 2 "" H 1900 1700 50  0001 C CNN
F 3 "" H 1900 1700 50  0001 C CNN
	1    1900 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1650 1900 1700
$Comp
L Device:CP1 C1
U 1 1 5EBB250D
P 1500 1400
F 0 "C1" H 1615 1446 50  0000 L CNN
F 1 "10uF" H 1615 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_Elec_5x5.4" H 1500 1400 50  0001 C CNN
F 3 "~" H 1500 1400 50  0001 C CNN
	1    1500 1400
	1    0    0    -1  
$EndComp
Connection ~ 1500 1250
$Comp
L Switch:SW_SPST SW1
U 1 1 5EBC5A89
P 1850 4350
F 0 "SW1" H 1850 4585 50  0000 C CNN
F 1 "RST" H 1850 4494 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 1850 4350 50  0001 C CNN
F 3 "~" H 1850 4350 50  0001 C CNN
	1    1850 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5EBC6918
P 2100 4400
F 0 "#PWR0116" H 2100 4150 50  0001 C CNN
F 1 "GND" H 2105 4227 50  0000 C CNN
F 2 "" H 2100 4400 50  0001 C CNN
F 3 "" H 2100 4400 50  0001 C CNN
	1    2100 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4350 2100 4350
Wire Wire Line
	2100 4350 2100 4400
Text GLabel 1600 4350 0    50   Input ~ 0
RST
Wire Wire Line
	1600 4350 1650 4350
$Comp
L Device:LED D2
U 1 1 5EBDE7D5
P 3300 1600
F 0 "D2" H 3293 1345 50  0000 C CNN
F 1 "LED" H 3293 1436 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 3300 1600 50  0001 C CNN
F 3 "~" H 3300 1600 50  0001 C CNN
	1    3300 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3300 1350 3300 1450
$Comp
L Device:R_US R2
U 1 1 5EBDE7DC
P 3300 2000
F 0 "R2" V 3095 2000 50  0000 C CNN
F 1 "220" V 3186 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3340 1990 50  0001 C CNN
F 3 "~" H 3300 2000 50  0001 C CNN
	1    3300 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	3300 1750 3300 1850
$Comp
L power:GND #PWR0117
U 1 1 5EBDE7E3
P 3300 2250
F 0 "#PWR0117" H 3300 2000 50  0001 C CNN
F 1 "GND" H 3305 2077 50  0000 C CNN
F 2 "" H 3300 2250 50  0001 C CNN
F 3 "" H 3300 2250 50  0001 C CNN
	1    3300 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 1350 3300 1350
Wire Wire Line
	3300 2150 3300 2250
$Comp
L Connector:Jack-DC J4
U 1 1 5EBE21BA
P 900 1350
F 0 "J4" H 957 1675 50  0000 C CNN
F 1 "Jack-DC" H 957 1584 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 950 1310 50  0001 C CNN
F 3 "~" H 950 1310 50  0001 C CNN
	1    900  1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1250 1500 1250
Wire Wire Line
	1200 1450 1200 1650
Wire Wire Line
	1200 1650 1500 1650
Connection ~ 1500 1650
Wire Wire Line
	1050 3950 1000 3950
Wire Wire Line
	1050 3550 1000 3550
Wire Wire Line
	1050 3650 1000 3650
Text Notes 700  700  0    100  ~ 0
Power Supply 
Wire Notes Line
	4000 2500 4000 500 
Wire Notes Line
	500  2750 3150 2750
Wire Notes Line
	3150 2750 3150 4750
Wire Notes Line
	3150 4750 500  4750
Text Notes 650  3150 0    100  ~ 0
Test Points and Programmer\nHeaders
Wire Wire Line
	2600 5500 2800 5500
Connection ~ 2600 5500
Wire Wire Line
	2600 5400 2600 5500
Wire Wire Line
	2400 5500 2500 5500
Connection ~ 2400 5500
Wire Wire Line
	2400 5400 2400 5500
Connection ~ 2500 5500
Wire Wire Line
	2800 5500 2800 5400
Wire Wire Line
	2500 5500 2600 5500
Wire Wire Line
	2200 5500 2400 5500
Wire Wire Line
	2200 5400 2200 5500
$Comp
L power:GND #PWR0101
U 1 1 5EB65E32
P 2500 5500
F 0 "#PWR0101" H 2500 5250 50  0001 C CNN
F 1 "GND" H 2505 5327 50  0000 C CNN
F 2 "" H 2500 5500 50  0001 C CNN
F 3 "" H 2500 5500 50  0001 C CNN
	1    2500 5500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5EB6488B
P 2400 5300
F 0 "H2" H 2500 5349 50  0000 L CNN
F 1 "MountingHole_Pad" H 2050 5100 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.5mm_Pad_Via" H 2400 5300 50  0001 C CNN
F 3 "~" H 2400 5300 50  0001 C CNN
	1    2400 5300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5EB64DA3
P 2800 5300
F 0 "H4" H 2900 5349 50  0000 L CNN
F 1 "MountingHole_Pad" H 2800 5100 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.5mm_Pad_Via" H 2800 5300 50  0001 C CNN
F 3 "~" H 2800 5300 50  0001 C CNN
	1    2800 5300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5EB64B63
P 2600 5300
F 0 "H3" H 2700 5349 50  0000 L CNN
F 1 "MountingHole_Pad" H 2800 5500 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.5mm_Pad_Via" H 2600 5300 50  0001 C CNN
F 3 "~" H 2600 5300 50  0001 C CNN
	1    2600 5300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5EB64044
P 2200 5300
F 0 "H1" H 2300 5349 50  0000 L CNN
F 1 "MountingHole_Pad" H 2050 5500 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.5mm_Pad_Via" H 2200 5300 50  0001 C CNN
F 3 "~" H 2200 5300 50  0001 C CNN
	1    2200 5300
	1    0    0    -1  
$EndComp
Wire Notes Line
	500  5000 3150 5000
Wire Notes Line
	3150 5000 3150 5750
Text Notes 550  5200 0    100  ~ 0
Mounting Holes
Wire Wire Line
	1550 3550 1600 3550
Wire Wire Line
	1600 3550 1600 3500
NoConn ~ 1050 3750
NoConn ~ 1050 3850
Wire Wire Line
	1550 3950 1600 3950
Wire Wire Line
	1600 3950 1600 4000
Wire Wire Line
	1550 3850 1600 3850
Wire Wire Line
	1600 3850 1600 3950
Connection ~ 1600 3950
Wire Wire Line
	1550 3750 1600 3750
Wire Wire Line
	1600 3750 1600 3850
Connection ~ 1600 3850
Wire Wire Line
	1550 3650 1600 3650
Wire Wire Line
	1600 3650 1600 3750
Connection ~ 1600 3750
Wire Notes Line
	3150 5750 500  5750
$Comp
L dk_Slide-Switches:JS202011SCQN S1
U 1 1 5F30FC66
P 2850 1250
F 0 "S1" H 2850 1733 50  0000 C CNN
F 1 "JS202011SCQN" H 2850 1642 50  0000 C CNN
F 2 "digikey-footprints:Switch_Slide_JS202011SCQN" H 3050 1450 50  0001 L CNN
F 3 "https://www.ckswitches.com/media/1422/js.pdf" H 3050 1550 60  0001 L CNN
F 4 "401-2002-1-ND" H 3050 1650 60  0001 L CNN "Digi-Key_PN"
F 5 "JS202011SCQN" H 3050 1750 60  0001 L CNN "MPN"
F 6 "Switches" H 3050 1850 60  0001 L CNN "Category"
F 7 "Slide Switches" H 3050 1950 60  0001 L CNN "Family"
F 8 "https://www.ckswitches.com/media/1422/js.pdf" H 3050 2050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/c-k/JS202011SCQN/401-2002-1-ND/1640098" H 3050 2150 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH SLIDE DPDT 300MA 6V" H 3050 2250 60  0001 L CNN "Description"
F 11 "C&K" H 3050 2350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3050 2450 60  0001 L CNN "Status"
	1    2850 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 950  3300 950 
Wire Wire Line
	3300 950  3300 1350
Connection ~ 3300 1350
Wire Wire Line
	2300 1250 2650 1250
Wire Wire Line
	2650 1250 2650 1050
Wire Wire Line
	2650 1250 2650 1450
Connection ~ 2650 1250
Wire Notes Line
	500  2500 4000 2500
Wire Wire Line
	3300 850  3300 950 
Connection ~ 3300 950 
$EndSCHEMATC
