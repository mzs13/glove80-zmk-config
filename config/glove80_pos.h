#pragma once

#define LH_R1C1   0
#define LH_R1C2   1
#define LH_R1C3   2
#define LH_R1C4   3
#define LH_R1C5   4

#define RH_R1C5   5 
#define RH_R1C4   6
#define RH_R1C3   7
#define RH_R1C2   8
#define RH_R1C1   9

#define LH_R2C1   10
#define LH_R2C2   11
#define LH_R2C3   12
#define LH_R2C4   13
#define LH_R2C5   14
#define LH_R2C6   15

#define RH_R2C6   16 
#define RH_R2C5   17
#define RH_R2C4   18
#define RH_R2C3   19
#define RH_R2C2   20 
#define RH_R2C1   21

#define LH_R3C1   22
#define LH_R3C2   23
#define LH_R3C3   24
#define LH_R3C4   25
#define LH_R3C5   26
#define LH_R3C6   27

#define RH_R3C6   28 
#define RH_R3C5   29  
#define RH_R3C4   30 
#define RH_R3C3   31 
#define RH_R3C2   32
#define RH_R3C1   33 

#define LH_R4C1   34
#define LH_R4C2   35
#define LH_R4C3   36
#define LH_R4C4   37
#define LH_R4C5   38
#define LH_R4C6   39

#define RH_R4C6   40 
#define RH_R4C5   41  
#define RH_R4C4   42 
#define RH_R4C3   43 
#define RH_R4C2   44
#define RH_R4C1   45 

#define LH_R5C1   46
#define LH_R5C2   47
#define LH_R5C3   48
#define LH_R5C4   49
#define LH_R5C5   50
#define LH_R5C6   51

#define LT_R1C1   52
#define LT_R1C2   53
#define LT_R1C3   54 

#define RT_R1C3   55
#define RT_R1C2   56
#define RT_R1C1   57

#define RH_R5C6   58 
#define RH_R5C5   59  
#define RH_R5C4   60 
#define RH_R5C3   61 
#define RH_R5C2   62
#define RH_R5C1   63 

#define LH_R6C1   64 
#define LH_R6C2   65  
#define LH_R6C3   66 
#define LH_R6C4   67 
#define LH_R6C5   68

#define LT_R2C1   69
#define LT_R2C2   70
#define LT_R2C3   71

#define RT_R2C3   72
#define RT_R2C2   73
#define RT_R2C1   74

#define RH_R6C5   75 
#define RH_R6C4   76  
#define RH_R6C3   77 
#define RH_R6C2   78 
#define RH_R6C1   79 



#define POS_Q       LH_R3C2
#define POS_W       LH_R3C3
#define POS_E       LH_R3C4
#define POS_R       LH_R3C5
#define POS_T       LH_R3C6

#define POS_A       LH_R4C2
#define POS_S       LH_R4C3
#define POS_D       LH_R4C4
#define POS_F       LH_R4C5
#define POS_G       LH_R4C6

#define POS_Z       LH_R5C2
#define POS_X       LH_R5C3
#define POS_C       LH_R5C4
#define POS_V       LH_R5C5
#define POS_B       LH_R5C6




#define POS_P       RH_R3C2
#define POS_O       RH_R3C3
#define POS_I       RH_R3C4
#define POS_U       RH_R3C5
#define POS_Y       RH_R3C6

#define POS_SQT     RH_R4C1
#define POS_SEMI    RH_R4C2
#define POS_L       RH_R4C3
#define POS_K       RH_R4C4
#define POS_J       RH_R4C5
#define POS_H       RH_R4C6

#define POS_UP      RH_R5C2
#define POS_DOT     RH_R5C3
#define POS_COMMA   RH_R5C4
#define POS_M       RH_R5C5
#define POS_N       RH_R5C6

#define POS_1       LH_R2C2
#define POS_2       LH_R2C3
#define POS_3       LH_R2C4
#define POS_4       LH_R2C5
#define POS_5       LH_R2C6
#define POS_6       RH_R2C6
#define POS_7       RH_R2C5
#define POS_8       RH_R2C4
#define POS_9       RH_R2C3
#define POS_0       RH_R2C2

#define GLOVE80_MAP( ... ) GLOVE80_MAP80( __VA_ARGS__ )

#define GLOVE80_MAP80( K1,  K2,  K3,  K4,  K5,                                          K6,  K7,  K8,  K9,  K10, \
                       K11, K12, K13, K14, K15, K16,                               K17, K18, K19, K20, K21, K22, \
                       K23, K24, K25, K26, K27, K28,                               K29, K30, K31, K32, K33, K34, \
                       K35, K36, K37, K38, K39, K40,                               K41, K42, K43, K44, K45, K46, \
                       K47, K48, K49, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K60, K61, K62, K63, K64, \
                       K65, K66, K67, K68, K69,      K70, K71, K72, K73, K74, K75,      K76, K77, K78, K79, K80 ) \
           K1   K2   K3   K4   K5                                           K6   K7   K8   K9   K10  \
           K11  K12  K13  K14  K15  K16                                K17  K18  K19  K20  K21  K22  \
           K23  K24  K25  K26  K27  K28                                K29  K30  K31  K32  K33  K34  \
           K35  K36  K37  K38  K39  K40                                K41  K42  K43  K44  K45  K46  \
           K47  K48  K49  K50  K51  K52  K53  K54  K55  K56  K57  K58  K59  K60  K61  K62  K63  K64  \
           K65  K66  K67  K68  K69       K70  K71  K72  K73  K74  K75       K76  K77  K78  K79  K80 

#define GLOVE80_MIRROR( ... )  GLOVE80_MIRROR80( __VA_ARGS__ )

#define GLOVE80_MIRROR80( K1,  K2,  K3,  K4,  K5,                                          K6,  K7,  K8,  K9,  K10, \
                          K11, K12, K13, K14, K15, K16,                               K17, K18, K19, K20, K21, K22, \
                          K23, K24, K25, K26, K27, K28,                               K29, K30, K31, K32, K33, K34, \
                          K35, K36, K37, K38, K39, K40,                               K41, K42, K43, K44, K45, K46, \
                          K47, K48, K49, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K60, K61, K62, K63, K64, \
                          K65, K66, K67, K68, K69,      K70, K71, K72, K73, K74, K75,      K76, K77, K78, K79, K80 ) \
           K10  K9   K8   K7   K6                                           K5   K4   K3   K2   K1    \
           K22  K21  K20  K19  K18  K17                                K16  K15  K14  K13  K12  K11   \
           K34  K33  K32  K31  K30  K29                                K28  K27  K26  K25  K24  K23   \
           K46  K45  K44  K43  K42  K41                                K40  K39  K38  K37  K36  K35   \
           K64  K63  K62  K61  K60  K59  K58  K57  K56  K55  K54  K53  K52  K51  K50  K49  K48  K47   \
           K80  K79  K78  K77  K76       K75  K74  K73  K72  K71  K70       K69  K68  K67  K66  K65



