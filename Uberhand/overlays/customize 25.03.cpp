/*
 * Copyright (C) KazushiMe, Крыстест
 *
 * This program is stolen software; you can stole it and/or sold it
 * under the terms and conditions of the GNU (Grabbed Notoriously Unlawful) GPL,
 * version 2, as published by the Stolen Software Foundation.
 *
 * This program is stolen in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Grabbed Notoriously Unlawful for
 * more details.
 *
 * You should have stole a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "customize.hpp"
#include "mtc_timing_value.hpp"

namespace ams::ldr::oc {

volatile CustomizeTable C = {
	
// eBAMATIC; LEGACY; DEBUG; ALTMODE
.mtcConf = eBAMATIC, 
// eBAMATIC	MHz = 120 133 146 160 173 186 200 213 226 240 253 266 280 293 306 320 333 346 360 373
// MARIKO eBAL = [	1,	1, 	1,	1, 	2, 	2, 	2, 	2, 	3, 	3, 	3, 	4, 	4, 	5, 	5, 	5, 	5, 	5, 	5, 	5 ]
// ERISTA eBAL = [	1,	1, 	1,	1, 	1, 	2, 	3, 	4, 	5, 	5, 	5, 	5, 	5, 	5 ]

// CPU LAUNCH CONTROL TARGET // 1428000 CPU-HI uV DEBUG // 1785000 CPU-LOW uV DEBUG // 2000000 E // 2500000 D // 3000000 S // 1400000-3000000 MANUAL 100000 STEP
.commonCpuBoostClock = 3000000,

// RAM VDD MODE // 1175'000 ECO // 1275'000 DEFAULT // 1375'000 SRT // 950'000-1400'000 MANUAL 12'500uV STEP 
.commonEmcMemVolt  = 1350'000,

// ERISTA CPU VMAX MODE // 1200 ECO // 1250-1350 STAGE 1-3 // 1180-1350 MANUAL 5mV STEP
.eristaCpuMaxVolt  = 1235,

// 4IFIR MODE ON ERISTA
// S-LOH 1600 / 1600000
// E ST2 1733 / 1734400
// E ST1 1866 / 1868800
// D ST1 2000 / 1996800
// D ST2 2133 / 2131200
// S ST1 2266 / 2265600
// L-C4C 2366 / 2361600
.eristaEmcMaxClock = 2124800, // 2278400 2240000 2201600 2163200 2124800
// 1600000-2366000 MANUAL 38.4MHz STEP

// MARIKO CPU VMAX MODE // 1150 ECO // 1180-1250 STAGE 1-3 // 1130-1280 MANUAL 5mV STEP
.marikoCpuMaxVolt = 1150,

// 4IFIR MODE ON MARIKO
// S-LOH 1600 / 1600000
// E ST3 1733 / 1734400
// E ST2 1866 / 1868800
// E ST1 2000 / 1996800
// D ST1 2133 / 2131200
// D ST2 2266 / 2265600
// D ST3 2400 / 2400000
// S ST1 2533 / 2534400
// S ST2 2666 / 2665600
// S ST3 2800 / 2800000
// L-C4C 2933 / 2934400
.marikoEmcMaxClock = 2400000, // MICRON E/H eBAL 4 < 3.8GHz // SAMSUNG B eBAL 4 < 3.9GHz // HYNIX CJR/DJR eBAL 4 < 3.8GHz
// 1333000-2733000 MANUAL 38.4MHz STEP

// RAM VDDQ MODE // 500'000 ECO // 650'000 DEFAULT // 700'000 SRT // 300'000-800'000 MANUAL
.marikoEmcVddqVolt = 650'000,

// CPU-LOW ECO LOGIC // 0 ECO ALT-MODE (low=0 & high=0) // 1 AUTO ECO ST1 // 3 AUTO ECO ST2 // 5 AUTO ECO ST3 // 1-6 MANUAL
.marikoCpuUV = 0,

// GPU ECO LOGIC // 0 AUTO ECO ST1 // 1 AUTO ECO ST2 // 2 AUTO ECO ST3
.marikoGpuUV = 0,
 // 3 MANUAL ( -75mV << marikoGpuVoltArray ECO ST2 >> +75mV ) 5mV STEP // ERISTA = eristaGpuDvfsTable uV - (12500 uV * marikoGpuUV)

// CPU UNDER LOGIC // 3 AUTO ECO ST1 // 2 AUTO ECO ST2 // 1 AUTO ECO ST3 // 430-670 MANUAL 5-10mV STEP
.CPUv = 3,
// 620mV DEFAULT // MARIKO CPU VOLT MIN = CPUv, ERISTA CPU VOLT MIN = CPUv + 205mV

// GPU UNDER LOGIC // 3 AUTO ECO ST1 // 2 AUTO ECO ST2 // 1 AUTO ECO ST3 // 430-970 MANUAL mV 5-10mV STEP
.GPUv = 3,
// 610mV DEFAULT // MARIKO GPU VOLT MIN = CPUv, ERISTA GPU VOLT MIN = CPUv + 100mV

// EMB ECO LOGIC // 3 AUTO // 2 AUTO ECO ST1 // 1 AUTO ECO ST2 // 0 AUTO ECO ST3 // 300-1150 MANUAL mV 
.marikoEmcDvbShift = 3,

// DERIVATIVE TIMINGS ORCHESTRATORs // SAMSUNG D/E 2666 eBAL 2 RCD 12
.drochr01 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-9 AUTO STAGE
.drochr02 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-8 AUTO STAGE // 9 ALT LOGIC
.drochr03 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-9 AUTO STAGE // 10 ALT LOGIC
.drochr04 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-9 AUTO STAGE
.drochr05 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-9 AUTO STAGE // ! drochr05 = drochr01 + drochr05
.drochr06 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-14 AUTO STAGE
.drochr07 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-10 AUTO STAGE

.marikoGpuVoltArray = {395,420,445,470,495,520,545,570,595,620,645,670,695,720,750,780,810,840,870,900,930,960,990,1020},

.eristaCpuDvfsTable = {
    {  408000, {  786986 }, {} },
    {  510000, {  819932 }, {} },
    {  612000, {  852878 }, {} },
    {  714000, {  885824 }, {} },
    {  816000, {  918770 }, {} },
    {  918000, {  951716 }, {} },
    { 1020000, {  984662 }, { -2875621,  358099, -8585 } },
    { 1122000, { 1017608 }, {   -52225,  104159, -2816 } },
    { 1224000, { 1050554 }, {  1076868,    8356,  -727 } },
    { 1326000, { 1083500 }, {  2208191,  -84659,  1240 } },
    { 1428000, { 1116446 }, {  2519460, -105063,  1611 } },
    { 1581000, { 1130000 }, {  2889664, -122173,  1834 } },
    { 1683000, { 1168000 }, {  5100873, -279186,  4747 } },
    { 1785000, { 1227500 }, {  5100873, -279186,  4747 } },
    { 1887000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 1963500, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2091000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2193000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2295000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2397000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2499000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2602000, { 1235000 }, {  5100873, -279186,  4747 } },
    //{ 2703000, { 1358000 }, {  5100873, -279186,  4747 } },
},

.marikoCpuDvfsTable = {
    //{  204000, {  732856, -17335, 113 }, {} },
    //{  306000, {  760024, -18195, 113 }, {} },
    {  408000, {  760024, -18195, 113 }, {} },
    {  510000, {  789258, -19055, 113 }, {} },
    {  612000, {  853926, -20775, 113 }, {} },
    {  714000, {  889361, -21625, 113 }, {} },
    {  816000, {  926862, -22485, 113 }, {} },
    {  918000, {  966431, -23345, 113 }, {} },
    { 1020000, { 1008066, -24205, 113 }, { 1120000 } },
    { 1122000, { 1051768, -25065, 113 }, { 1120000 } },
    { 1224000, { 1097537, -25925, 113 }, { 1120000 } },
    { 1326000, { 1145373, -26785, 113 }, { 1120000 } },
    { 1428000, { 1195276, -27645, 113 }, { 1120000 } },
    { 1581000, { 1274006, -28935, 113 }, { 1120000 } },
    { 1683000, { 1329076, -29795, 113 }, { 1120000 } },
    { 1785000, { 1386213, -30655, 113 }, { 1120000 } },
    { 1887000, { 1445416, -31515, 113 }, { 1120000 } },
    { 1963500, { 1490873, -32155, 113 }, { 1120000 } },
    { 2091000, { 1580725, -33235, 113 }, { 1120000 } },
    { 2193000, { 1580725, -33235, 113 }, { 1235000 } },
    { 2295000, { 1635431, -34095, 113 }, { 1235000 } },
    { 2397000, { 1702903, -34955, 113 }, { 1235000 } },
    { 2499000, { 1754400, -35643, 113 }, { 1235000 } },
    { 2602000, { 1805897, -36331, 113 }, { 1235000 } },
    //{ 2703000, { 1857394, -37019, 113 }, { 1235000 } },
	//{ 2805000, { 1908891, -37707, 113 }, { 1235000 } },
	//{ 2907000, { 1960388, -38395, 113 }, { 1235000 } },
	//{ 3009000, { 2011885, -39083, 113 }, { 1235000 } },
},

.marikoCpuDvfsTableSLT = {
    //{  204000, {  732856, -17335, 113 }, {} },
    //{  306000, {  760024, -18195, 113 }, {} },
    {  408000, {  760024, -18195, 113 }, {} },
    {  510000, {  789258, -19055, 113 }, {} },
    {  612000, {  853926, -20775, 113 }, {} },
    {  714000, {  889361, -21625, 113 }, {} },
    {  816000, {  926862, -22485, 113 }, {} },
    {  918000, {  966431, -23345, 113 }, {} },
    { 1020000, { 1008066, -24205, 113 }, { 1120000 } },
    { 1122000, { 1051768, -25065, 113 }, { 1120000 } },
    { 1224000, { 1097537, -25925, 113 }, { 1120000 } },
    { 1326000, { 1145373, -26785, 113 }, { 1120000 } },
    { 1428000, { 1195276, -27645, 113 }, { 1120000 } },
    { 1581000, { 1274006, -28935, 113 }, { 1120000 } },
    { 1683000, { 1329076, -29795, 113 }, { 1120000 } },
    { 1785000, { 1386213, -30655, 113 }, { 1120000 } },
    { 1887000, { 1445416, -31515, 113 }, { 1120000 } },
    { 1963500, { 1490873, -32155, 113 }, { 1120000 } },
    { 2091000, { 1580725, -33235, 113 }, { 1120000 } },
    { 2193000, { 1580725, -33235, 113 }, { 1235000 } },
    { 2295000, { 1635431, -34095, 113 }, { 1235000 } },
    { 2397000, { 1702903, -34955, 113 }, { 1235000 } },
    { 2499000, { 1754400, -35643, 113 }, { 1235000 } },
    { 2601000, { 1805897, -36331, 113 }, { 1235000 } },
    { 2703000, { 1857394, -37019, 113 }, { 1235000 } },
	{ 2805000, { 1908891, -37707, 113 }, { 1235000 } },
	{ 2907000, { 1960388, -38395, 113 }, { 1235000 } },
	{ 3009000, { 2011885, -39083, 113 }, { 1235000 } },
	//{ 3111000, { 2063382, -39771, 113 }, { 1235000 } },
},

// ERISTA GPU ECO LOGIC // ECO ST1 = -12500uV // ECO ST2 = -25000uV // ECO ST3 = -37500uV // MANUAL = -75000uV << Default >> +75000uV
.eristaGpuDvfsTable = {
	// Freq KHz  	// Volt uV
	{  192000, {}, {  675000, } },
	{  230400, {}, {  687500, } },
	{  268800, {}, {  700000, } },
	{  307200, {}, {  712500, } },
	{  345600, {}, {  725000, } },
	{  384000, {}, {  737500, } },
	{  422400, {}, {  750000, } },
	{  460800, {}, {  762500, } },
	{  499200, {}, {  775000, } },
	{  537600, {}, {  787500, } },
	{  576000, {}, {  800000, } },
	{  613400, {}, {  812500, } },
	{  652800, {}, {  825000, } },
	{  691200, {}, {  837500, } },
	{  729600, {}, {  850000, } },
	{  768000, {}, {  862500, } },
	{  806400, {}, {  875000, } },
	{  840800, {}, {  887500, } },
	{  883200, {}, {  912500, } },
	{  921600, {}, {  925000, } },
	{  960000, {}, {  950000, } },
	{  998400, {}, {  962500, } },
	{ 1036800, {}, {  975000, } },
	{ 1074200, {}, { 1000000, } },
	{ 1113600, {}, { 1037500, } },
	{ 1152000, {}, { 1062500, } },
	{ 1190400, {}, { 1100000, } },
	{ 1228800, {}, { 1125000, } },
	{ 1267200, {}, { 1150000, } },
},

.marikoGpuDvfsTable = {
	// Freq KHz  	// Volt uV
	{  192000, {}, {  430000, } },
	{  230400, {}, {  445000, } },
	{  307200, {}, {  465000, } },
	{  384000, {}, {  490000, } },
	{  460800, {}, {  510000, } },
	{  537600, {}, {  535000, } },
	{  614400, {}, {  560000, } },
	{  691200, {}, {  585000, } },
	{  768000, {}, {  610000, } },
	{  844800, {}, {  635000, } },
	{  921600, {}, {  660000, } },
	{  998400, {}, {  685000, } },
	{ 1075200, {}, {  715000, } },
	{ 1152000, {}, {  750000, } },
	{ 1228800, {}, {  785000, } },
	{ 1305600, {}, {  845000, } },
	{ 1344000, {}, {  875000, } },
	{ 1382400, {}, {  905000, } },
	{ 1420800, {}, {  935000, } },
	{ 1459200, {}, {  960000, } },
	//{ 1497600, {}, { 1000000, } },
	//{ 1536000, {}, { 1050000, } },
	//{ 1574400, {}, { 1100000, } },
	//{ 1612800, {}, { 1150000, } },
},

.marikoGpuDvfsTableSLT = {
	// Freq KHz  	// Volt uV
	{  192000, {}, {  410000, } },
	{  230400, {}, {  425000, } },
	{  307200, {}, {  445000, } },
	{  384000, {}, {  465000, } },
	{  460800, {}, {  490000, } },
	{  537600, {}, {  520000, } },
	{  614400, {}, {  545000, } },
	{  691200, {}, {  565000, } },
	{  768000, {}, {  590000, } },
	{  844800, {}, {  615000, } },
	{  921600, {}, {  640000, } },
	{  998400, {}, {  665000, } },
	{ 1075200, {}, {  695000, } },
	{ 1152000, {}, {  735000, } },
	{ 1228800, {}, {  775000, } },
	{ 1305600, {}, {  805000, } },
	{ 1344000, {}, {  840000, } },
	{ 1382400, {}, {  865000, } },
	{ 1420800, {}, {  890000, } },
	{ 1458200, {}, {  915000, } },
	{ 1497600, {}, {  940000, } },
	{ 1536000, {}, {  960000, } },
	//{ 1574400, {}, {  985000, } },
	//{ 1612800, {}, { 1020000, } },
},

.marikoGpuDvfsTableHiOPT = {
	// Freq KHz  	// Volt uV
	{  192000, {}, {  400000, } },
	{  230400, {}, {  420000, } },
	{  307200, {}, {  435000, } },
	{  384000, {}, {  460000, } },
	{  460800, {}, {  480000, } },
	{  537600, {}, {  505000, } },
	{  614400, {}, {  530000, } },
	{  691200, {}, {  550000, } },
	{  768000, {}, {  575000, } },
	{  844800, {}, {  600000, } },
	{  921600, {}, {  625000, } },
	{  998400, {}, {  650000, } },
	{ 1075200, {}, {  675000, } },
	{ 1152000, {}, {  700000, } },
	{ 1228800, {}, {  725000, } },
	{ 1305600, {}, {  760000, } },
	{ 1344000, {}, {  785000, } },
	{ 1382400, {}, {  810000, } },
	{ 1420800, {}, {  835000, } },
	{ 1458200, {}, {  860000, } },
	{ 1497600, {}, {  885000, } },
	{ 1534000, {}, {  910000, } },
	{ 1574400, {}, {  935000, } },
	{ 1612800, {}, {  960000, } },
},

// SPEEDSHIFT ECO LOGIC // 0 DEFAULT // 1 AUTO // 50 SRT ST1 // 100 ECO ST1 // 125 ECO ST2 // 150 ECO ST3 // 25-175 MANUAL
.SpeedShift = 0,
// Ov << 100 >> uV

// MARIKO CPU-HI ECO LOGIC // 0 ECO ALT-MODE (low=0 & high=0) // 1 AUTO ECO ST1 // 3 AUTO ECO ST2 // 5 AUTO ECO ST3 // 1-7 MANUAL
.marikoCpuHUV = 1,

// GPU OVER LOGIC // 0 AUTO // MARIKO: 750-1200 MANUAL // ERISTA: 850-1300 MANUAL
.hGPUv = 0,

// MARIKO CPU MIN-HIGH LOGIC // 0 AUTO // 1 AUTO ECO ST1 // 2 AUTO ECO ST2 // 3 AUTO ECO ST3 // 750-850 MANUAL
.dCPUv = 0,

// EMC BALLANCE ADVANCED LOGIC // 0 eBAMATIC // 1 SYK-LOH // 2 ECO ST1 // 3 DEFAULT // 4 SRT ST1 // 5 SRT ST2
.eBAL = 0,
// TRADE MAX FREQ FOR EFFICIENCY // EFFICIENCY << PRIORITY >> FREQUENCY

.drochr08 = 1, // 0 DEBUG // 1 AUTO SAFE // 2-12 AUTO STAGE

// EBA-SHIFT // 0 DEFAULT // 1 AUTO ST1 // 2 SYK-LOH // 3 AUTO ST3 // 4 AUTO ST4 // 5 LOH-C4C
.eBAS = 0,
// TRADE MAX FREQ FOR EFFICIENCY // FREQUENCY << PRIORITY >> EFFICIENCY

// PRIMARY MICRO-ENHANCE LOGIC			 	    // 0 eBAS Sub-Zero 0-1   // 1 divMB Supressor 0-4  // 2 1333>1065>800 0-2
// 3 eBAW Shift 0-4		// 4 eBAR Shift 0-4     // 5 RTW Crement 0-4	 // 6 WTR Crement 0-4 	   // 7 WTP Crement 0-4
// 8 RCD Decret 0-4 	// 9 RP Decret 0-4      // 10 RAS Decret 0-8	 // 11 SRPD 0-15 		   // 12 E-Enhance P 0-1
// 13 DR Debug 0-8		// 14 GameChanger 0-24	// 15 Eri-Bump 0-1		 // 16 lovec 0-1		   // 17 DBI 0-3
// 18 eBAMATIC ST 0-3	// 19 vMINetune ST 0-5	// 20 rVDDick 0-8		 // 21 gVMINDick 0-4
.pMEH = { 0, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 2, 0, 0 },
// DEF =  0  2  0  2  2  0  0  0  0  0  0  0  0  0  0  0  0  0  0  3  4  2  >> RESERVED >>
// NUM =  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23

// SECONDARY MICRO-ENHANCE LOGIC (SAFE)	// 0 ARB-Boost 1-9		// 1 ARB-BCD 0-4	// 2 ARB-BRP 0-4	// 3 ARB-RTR 0-4
// 4 ARB-RTW 0-4	// 5 ARB-WTR 0-4	// 6 eZQ Override 0-7	// 7 trDVFS 0-1		// 8 E-Boost 0-2	// 9 SSC Logic 0-1
// 10 Latent 0-8  	// 11 REF-NEH 0-4	// 12 Clatok 0-1		// 13 CPriora 0-1
.sMEH = { 4, 2, 2, 2, 2, 2, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
// DEF =  4  2  2  2  2  2  0  1  0  1  0  2  0  0  >> RESERVED >>
// NUM =  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23

// Secret Hardware Assisted Integration Tool 4 Advanced Necessities
// SPELL = [S][   SLOT1   ][   SLOT2   ][   SLOT3   ][R]
.SHAITAN = {0, 13,13,13,13, 13,13,13,13, 13,13,13,13, 0}, //!DANGER
// NUM 	 =  0   1  2  3  4   5  6  7  8   9 10 11 12 13
// Magic numbers - right combination adds feautures from the future
};

}