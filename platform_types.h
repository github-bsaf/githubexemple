/***************************************************************************************
 * driveXpert GmbH Ilmenau, www.drivexpert.de
 ***********************************************************************************//**
 * @brief	  Common types for SW reuse components.
 **************************************************************************************/

#ifndef BSWC_PLATFORM_TYPES_H_
#define BSWC_PLATFORM_TYPES_H_


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "std_types.h"
#include "static_assert.h"
#include "state_machine_base.h"
/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
/* 16Bit DUAngle typical values */
#define ANGLE_0   (0U)
#define ANGLE_15  ((uint16)((( 15.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/*  2731 */
#define ANGLE_30  ((uint16)((( 30.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/*  5461 */
#define ANGLE_40  ((uint16)((( 40.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_45  ((uint16)((( 45.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_50  ((uint16)((( 50.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_55  ((uint16)((( 55.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_60  ((uint16)((( 60.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 10923 */
#define ANGLE_75  ((uint16)((( 75.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_90  ((uint16)((( 90.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 16384 */
#define ANGLE_120 ((uint16)(((120.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 21845 */
#define ANGLE_150 ((uint16)(((150.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 27306 */
#define ANGLE_180 ((uint16)(((180.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 32768 */
#define ANGLE_210 ((uint16)(((210.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_240 ((uint16)(((240.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 43690 */
#define ANGLE_270 ((uint16)(((270.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_300 ((uint16)(((300.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))	/* 54613 */
#define ANGLE_330 ((uint16)(((330.0 * ((float64)UINT16_MAX)) / 360.0) + 0.5))
#define ANGLE_360 (0U)
#define ANGLE_MAX (UINT16_MAX)

#define DEFINE_RTE_VAR(var_name, data_type) \
        void rte_Write_##var_name(data_type value) { \
            var_name = value; \
        } \
        data_type rte_Read_##var_name() { \
            return var_name; \
        }

#define DECLARE_RTE_VAR(var_name, data_type, initial_value) \
        data_type var_name = initial_value; \
        void rte_Write_##var_name(data_type value);\
        data_type rte_Read_##var_name();


#define DEFINE_RTE_STUB(var_name, data_type) \
        data_type rte_Read_##var_name() { \
            return var_name; \
        }

#define DECLARE_RTE_STUB(var_name, data_type, initial_value) \
        data_type var_name = initial_value; \
        data_type rte_Read_##var_name();


/** \brief Shift definitions for fix point format
 */
#define STD_REAL_SHIFT_Qn8_y (-8  - 1) /**< \brief Range=[-2^(-9), 2^(-9)[; Q1.15=>Step=1/2^24, Q1.31 =>Step=1/2^40 */
#define STD_REAL_SHIFT_Qn7_y (-7  - 1) /**< \brief Range=[-2^(-8), 2^(-8)[; Q1.15=>Step=1/2^23, Q1.31 =>Step=1/2^39 */
#define STD_REAL_SHIFT_Qn6_y (-6  - 1) /**< \brief Range=[-2^(-7), 2^(-7)[; Q1.15=>Step=1/2^22, Q1.31 =>Step=1/2^38 */
#define STD_REAL_SHIFT_Qn5_y (-5  - 1) /**< \brief Range=[-2^(-6), 2^(-6)[; Q1.15=>Step=1/2^21, Q1.31 =>Step=1/2^37 */
#define STD_REAL_SHIFT_Qn4_y (-4  - 1) /**< \brief Range=[-2^(-5), 2^(-5)[; Q1.15=>Step=1/2^20, Q1.31 =>Step=1/2^36 */
#define STD_REAL_SHIFT_Qn3_y (-3  - 1) /**< \brief Range=[-2^(-4), 2^(-4)[; Q1.15=>Step=1/2^19, Q1.31 =>Step=1/2^35 */
#define STD_REAL_SHIFT_Qn2_y (-2  - 1) /**< \brief Range=[-2^(-3), 2^(-3)[; Q1.15=>Step=1/2^18, Q1.31 =>Step=1/2^34 */
#define STD_REAL_SHIFT_Qn1_y (-1  - 1) /**< \brief Range=[-2^(-2), 2^(-2)[; Q1.15=>Step=1/2^17, Q1.31 =>Step=1/2^33 */

#define STD_REAL_SHIFT_Q0_y  ( 0  - 1) /**< \brief Range=[-2^(-1), 2^(-1)[; Q1.15=>Step=1/2^16, Q1.31 =>Step=1/2^32 */
#define STD_REAL_SHIFT_Q1_y  ( 1  - 1) /**< \brief Range=[-2^0   , 2^0[;    Q1.15=>Step=1/2^15, Q1.31 =>Step=1/2^31 */
#define STD_REAL_SHIFT_Q2_y  ( 2  - 1) /**< \brief Range=[-2^1   , 2^1[;    Q1.15=>Step=1/2^14, Q1.31 =>Step=1/2^30 */
#define STD_REAL_SHIFT_Q3_y  ( 3  - 1) /**< \brief Range=[-2^2   , 2^2[;    Q1.15=>Step=1/2^13, Q1.31 =>Step=1/2^29 */
#define STD_REAL_SHIFT_Q4_y  ( 4  - 1) /**< \brief Range=[-2^3   , 2^3[;    Q1.15=>Step=1/2^12, Q1.31 =>Step=1/2^28 */
#define STD_REAL_SHIFT_Q5_y  ( 5  - 1) /**< \brief Range=[-2^4   , 2^4[;    Q1.15=>Step=1/2^11, Q1.31 =>Step=1/2^27 */
#define STD_REAL_SHIFT_Q6_y  ( 6  - 1) /**< \brief Range=[-2^5   , 2^5[;    Q1.15=>Step=1/2^10, Q1.31 =>Step=1/2^26 */
#define STD_REAL_SHIFT_Q7_y  ( 7  - 1) /**< \brief Range=[-2^6   , 2^6[;    Q7.9 =>Step=1/2^9,  Q8.24 =>Step=1/2^25 */
#define STD_REAL_SHIFT_Q8_y  ( 8  - 1) /**< \brief Range=[-2^7   , 2^7[;    Q8.8 =>Step=1/2^8,  Q8.24 =>Step=1/2^24 */
#define STD_REAL_SHIFT_Q9_y  ( 9  - 1) /**< \brief Range=[-2^8   , 2^8[;    Q9.7 =>Step=1/2^7,  Q9.23 =>Step=1/2^23 */
#define STD_REAL_SHIFT_Q10_y ( 10 - 1) /**< \brief Range=[-2^9   , 2^9[;    Q10.6=>Step=1/2^6,  Q10.22=>Step=1/2^22 */
#define STD_REAL_SHIFT_Q11_y ( 11 - 1) /**< \brief Range=[-2^10  , 2^10[;   Q11.5=>Step=1/2^5,  Q11.21=>Step=1/2^21 */
#define STD_REAL_SHIFT_Q12_y ( 12 - 1) /**< \brief Range=[-2^11  , 2^11[;   Q12.4=>Step=1/2^4,  Q12.20=>Step=1/2^20 */
#define STD_REAL_SHIFT_Q13_y ( 13 - 1) /**< \brief Range=[-2^12  , 2^12[;   Q13.3=>Step=1/2^3,  Q13.19=>Step=1/2^19 */
#define STD_REAL_SHIFT_Q14_y ( 14 - 1) /**< \brief Range=[-2^13  , 2^13[;   Q14.2=>Step=1/2^2,  Q14.18=>Step=1/2^18 */
#define STD_REAL_SHIFT_Q15_y ( 15 - 1) /**< \brief Range=[-2^14  , 2^14[;   Q15.1=>Step=1/2^1,  Q15.17=>Step=1/2^17 */
#define STD_REAL_SHIFT_Q16_y ( 16 - 1) /**< \brief Range=[-2^15  , 2^15[;   Q16.0=>Step=1,      Q16.16=>Step=1/2^16 */
#define STD_REAL_SHIFT_Q32_y ( 32 - 1) /**< \brief Range=[-2^31  , 2^31[;   Q16.0=>             Q32.0 =>Step=1      */

#define NULL_PTR ((void*)0)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

typedef		void( *CALLBACK )( void );


/** electrical motor state type definition.
 * With assignment of zerocrossing to rotor angle
 */
typedef enum Emc_MotorStates {
	/** for CW rotation */
	MC_MST_1 = 0, //!< MC_MST_1 negative zero crossing @ 0°; commutation at bemf minimum;
	MC_MST_2 = 1, //!< MC_MST_2 positive zero crossing @ 60°; commutation at bemf maximum;
	MC_MST_3 = 2, //!< MC_MST_3 negative zero crossing @ 120°; commutation at bemf minimum;
	MC_MST_4 = 3, //!< MC_MST_4 positive zero crossing @ 180°; commutation at bemf maximum;
	MC_MST_5 = 4, //!< MC_MST_5 negative zero crossing @ 240°; commutation at bemf minimum;
	MC_MST_6 = 5, //!< MC_MST_6 positive zero crossing @ 300°; commutation at bemf maximum;
	/** for CCW rotation
	MC_MST_6 - 0°/360°...60°
	MC_MST_5 - 60°...120°
	MC_MST_4 - 120°...180°
	MC_MST_3 - 180°...240°
	MC_MST_2 - 240°...300°
	MC_MST_1 - 300°...360°/0° */
} mc_MotorStates;

/** Field angle sector definitions
 * sector number = ((6*fieldAngle_DU) >> 16)
 *
 * SECTOR_0 range: >0°  .. <=60°
 * SECTOR_1 range: >60° .. <=120°
 * SECTOR_2 range: >120°.. <=180°
 * SECTOR_3 range: >180°.. <=240°
 * SECTOR_4 range: >240°.. <=300°
 * SECTOR_5 range: >300°.. <=360°
 */
#define SECTOR_0 ((uint16) 0)
#define SECTOR_1 ((uint16) 1)
#define SECTOR_2 ((uint16) 2)
#define SECTOR_3 ((uint16) 3)
#define SECTOR_4 ((uint16) 4)
#define SECTOR_5 ((uint16) 5)

/** Definition of requested rotation directions.
 */
typedef enum Emc_RequestedDirection{
	MC_DIR_REQUEST_LEFT, /*!<left rotation looking on the axis, ECU behind the rotor */
	MC_DIR_REQUEST_RIGHT,/*!<right rotation looking on the axis, ECU behind the rotor */
}mc_RequestedDirection;

/**  Definition of detected rotation directions.
 */
typedef enum Emc_DetectedDirection{
	MC_DIR_DETECT_NORMAL, /*!< rotor rotates as defined by requested Direction */
	MC_DIR_DETECT_REVERSE, /*!< rotor rotates as against requested Direction */
}mc_DetectedDirection;


typedef struct SThreePhaseSystem{
  sint32 u;  /**< value u of three phase system */
  sint32 v;  /**< value v of three phase system */
  sint32 w;  /**< value w of three phase system */
}ThreePhaseSystem;

typedef struct SStatorFixedSystem{
  sint32 alpha; /**< value alpha of stator fixed system*/
  sint32 beta;  /**< value beta of stator fixed system */
}StatorFixedSystem;

typedef struct SRotorFixedSystem{
  sint32 d; /**< value d of rotor fixed system*/
  sint32 q;  /**< value q of rotor fixed system */
}RotorFixedSystem;

/** type for fractional values:
 *    value = man * 2^exp
 * */
typedef union u_uint8e {
	struct {
		uint8 man; /* mantissa */
		sint8 exp; /* exponent */
	}me_separated;
	/* splitted access to mantissa and exponent */
	uint16 me; /* mantissa and exponent together */
} uint8e;

#endif /* BSWC_PLATFORM_TYPES_H_ */
