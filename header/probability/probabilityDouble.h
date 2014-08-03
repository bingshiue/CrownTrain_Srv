/**
 * @file probabilityDouble.h
 * @brief Define double game probability.
 *
 */

#ifndef PROBABILITYDOUBLE_H_
#define PROBABILITYDOUBLE_H_

#define DG_PRO_70_X0   8210
#define DG_PRO_70_X2     90
#define DG_PRO_70_X4   1690
#define DG_PRO_70_X6     10

#define DG_PRO_80_X0   7268
#define DG_PRO_80_X2   1548
#define DG_PRO_80_X4   1100
#define DG_PRO_80_X6     84

#define DG_PRO_83_X0   6245
#define DG_PRO_83_X2   3405
#define DG_PRO_83_X4    305
#define DG_PRO_83_X6     45

#define DG_PRO_86_X0   6130
#define DG_PRO_86_X2   3450
#define DG_PRO_86_X4    410
#define DG_PRO_86_X6     10

#define DG_PRO_89_X0   6120
#define DG_PRO_89_X2   3455
#define DG_PRO_89_X4    280
#define DG_PRO_89_X6    145

#define DG_PRO_92_X0   5980
#define DG_PRO_92_X2   3445
#define DG_PRO_92_X4    570
#define DG_PRO_92_X6      5

#define DG_PRO_95_X0   5310
#define DG_PRO_95_X2   4650
#define DG_PRO_95_X4     20
#define DG_PRO_95_X6     20

#define DG_PRO_98_X0   7200
#define DG_PRO_98_X2    750
#define DG_PRO_98_X4   2000
#define DG_PRO_98_X6     50

#define DG_PRO_102_X0  5800
#define DG_PRO_102_X2  3500
#define DG_PRO_102_X4   500
#define DG_PRO_102_X6   200

#define DG_PRO_105_X0  6850
#define DG_PRO_105_X2  1950
#define DG_PRO_105_X4   300
#define DG_PRO_105_X6   900

#define DG_PRO_110_X0  6000
#define DG_PRO_110_X2  3100
#define DG_PRO_110_X4   300
#define DG_PRO_110_X6   600

#define DG_PRO_115_X0  4920
#define DG_PRO_115_X2  4510
#define DG_PRO_115_X4   470
#define DG_PRO_115_X6   100

unsigned int dg_pro_70[4]  = { DG_PRO_70_X0,  DG_PRO_70_X2,  DG_PRO_70_X4,  DG_PRO_70_X6  };
unsigned int dg_pro_80[4]  = { DG_PRO_80_X0,  DG_PRO_80_X2,  DG_PRO_80_X4,  DG_PRO_80_X6  };
unsigned int dg_pro_83[4]  = { DG_PRO_83_X0,  DG_PRO_83_X2,  DG_PRO_83_X4,  DG_PRO_83_X6  };
unsigned int dg_pro_86[4]  = { DG_PRO_86_X0,  DG_PRO_86_X2,  DG_PRO_86_X4,  DG_PRO_86_X6  };
unsigned int dg_pro_89[4]  = { DG_PRO_89_X0,  DG_PRO_89_X2,  DG_PRO_89_X4,  DG_PRO_89_X6  };
unsigned int dg_pro_92[4]  = { DG_PRO_92_X0,  DG_PRO_92_X2,  DG_PRO_92_X4,  DG_PRO_92_X6  };
unsigned int dg_pro_95[4]  = { DG_PRO_95_X0,  DG_PRO_95_X2,  DG_PRO_95_X4,  DG_PRO_95_X6  };
unsigned int dg_pro_98[4]  = { DG_PRO_98_X0,  DG_PRO_98_X2,  DG_PRO_98_X4,  DG_PRO_98_X6  };
unsigned int dg_pro_102[4] = { DG_PRO_102_X0, DG_PRO_102_X2, DG_PRO_102_X4, DG_PRO_102_X6 };
unsigned int dg_pro_105[4] = { DG_PRO_105_X0, DG_PRO_105_X2, DG_PRO_105_X4, DG_PRO_105_X6 };
unsigned int dg_pro_110[4] = { DG_PRO_110_X0, DG_PRO_110_X2, DG_PRO_110_X4, DG_PRO_110_X6 };
unsigned int dg_pro_115[4] = { DG_PRO_115_X0, DG_PRO_115_X2, DG_PRO_115_X4, DG_PRO_115_X6 };

unsigned int* dg_pro_all[10] ={
		dg_pro_80,
		dg_pro_83,
		dg_pro_86,
		dg_pro_89,
		dg_pro_92,
		dg_pro_95,
		dg_pro_98,
		dg_pro_102,
		dg_pro_105,
		dg_pro_110
};

#define DG_PRO_SET_96_80    1000
#define DG_PRO_SET_96_83    1050
#define DG_PRO_SET_96_86     500
#define DG_PRO_SET_96_89     500
#define DG_PRO_SET_96_92     500
#define DG_PRO_SET_96_95     900
#define DG_PRO_SET_96_98     900
#define DG_PRO_SET_96_101   1900
#define DG_PRO_SET_96_105   1750
#define DG_PRO_SET_96_110   1000

#define DG_PRO_SET_97_80     550
#define DG_PRO_SET_97_83    1000
#define DG_PRO_SET_97_86     250
#define DG_PRO_SET_97_89     250
#define DG_PRO_SET_97_92     250
#define DG_PRO_SET_97_95    2250
#define DG_PRO_SET_97_98    1000
#define DG_PRO_SET_97_101   1800
#define DG_PRO_SET_97_105   1750
#define DG_PRO_SET_97_110    900

#define DG_PRO_SET_98_80    1700
#define DG_PRO_SET_98_83     400
#define DG_PRO_SET_98_86     250
#define DG_PRO_SET_98_89     250
#define DG_PRO_SET_98_92     250
#define DG_PRO_SET_98_95     250
#define DG_PRO_SET_98_98     250
#define DG_PRO_SET_98_101   1750
#define DG_PRO_SET_98_105   4000
#define DG_PRO_SET_98_110    900

#define DG_PRO_SET_99_80     100
#define DG_PRO_SET_99_83     700
#define DG_PRO_SET_99_86     600
#define DG_PRO_SET_99_89     500
#define DG_PRO_SET_99_92    1000
#define DG_PRO_SET_99_95    1000
#define DG_PRO_SET_99_98    1000
#define DG_PRO_SET_99_101   1600
#define DG_PRO_SET_99_105    750
#define DG_PRO_SET_99_110   2750

#define DG_PRO_SET_100_80    600
#define DG_PRO_SET_100_83    900
#define DG_PRO_SET_100_86    250
#define DG_PRO_SET_100_89    250
#define DG_PRO_SET_100_92    250
#define DG_PRO_SET_100_95    250
#define DG_PRO_SET_100_98    750
#define DG_PRO_SET_100_101  2000
#define DG_PRO_SET_100_105  2250
#define DG_PRO_SET_100_110  2500

unsigned int dg_pro_set_96[10] = {
		DG_PRO_SET_96_80,
		DG_PRO_SET_96_83,
		DG_PRO_SET_96_86,
		DG_PRO_SET_96_89,
		DG_PRO_SET_96_92,
		DG_PRO_SET_96_95,
		DG_PRO_SET_96_98,
		DG_PRO_SET_96_101,
		DG_PRO_SET_96_105,
		DG_PRO_SET_96_110
};

unsigned int dg_pro_set_97[10] = {
		DG_PRO_SET_97_80,
		DG_PRO_SET_97_83,
		DG_PRO_SET_97_86,
		DG_PRO_SET_97_89,
		DG_PRO_SET_97_92,
		DG_PRO_SET_97_95,
		DG_PRO_SET_97_98,
		DG_PRO_SET_97_101,
		DG_PRO_SET_97_105,
		DG_PRO_SET_97_110
};

unsigned int dg_pro_set_98[10] = {
		DG_PRO_SET_98_80,
		DG_PRO_SET_98_83,
		DG_PRO_SET_98_86,
		DG_PRO_SET_98_89,
		DG_PRO_SET_98_92,
		DG_PRO_SET_98_95,
		DG_PRO_SET_98_98,
		DG_PRO_SET_98_101,
		DG_PRO_SET_98_105,
		DG_PRO_SET_98_110
};

unsigned int dg_pro_set_99[10] = {
		DG_PRO_SET_99_80,
		DG_PRO_SET_99_83,
		DG_PRO_SET_99_86,
		DG_PRO_SET_99_89,
		DG_PRO_SET_99_92,
		DG_PRO_SET_99_95,
		DG_PRO_SET_99_98,
		DG_PRO_SET_99_101,
		DG_PRO_SET_99_105,
		DG_PRO_SET_99_110
};

unsigned int dg_pro_set_100[10] = {
		DG_PRO_SET_100_80,
		DG_PRO_SET_100_83,
		DG_PRO_SET_100_86,
		DG_PRO_SET_100_89,
		DG_PRO_SET_100_92,
		DG_PRO_SET_100_95,
		DG_PRO_SET_100_98,
		DG_PRO_SET_100_101,
		DG_PRO_SET_100_105,
		DG_PRO_SET_100_110
};

unsigned int* dg_pro_set_all[5] = {
		dg_pro_set_96,
		dg_pro_set_97,
		dg_pro_set_98,
		dg_pro_set_99,
		dg_pro_set_100,
};

#endif /* PROBABILITYDOUBLE_H_ */
