/***************************************************************************************
 * driveXpert GmbH Ilmenau, www.drivexpert.de
 ***********************************************************************************//**
 * @brief	  standard type definitions
 **************************************************************************************/

#ifndef BSWC_STD_TYPES_H
#define BSWC_STD_TYPES_H


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <stdint.h>

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
#if   defined ( __CC_ARM )
  #define __ASM            __asm                                      /*!< asm keyword for ARM Compiler */
  #define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler */
  #define __STATIC_INLINE  static __inline

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #define __ASM            __asm                                      /*!< asm keyword for ARM Compiler */
  #define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler */
  #define __STATIC_INLINE  static __inline

#elif defined ( __GNUC__ )
  #define __ASM            __asm                                      /*!< asm keyword for GNU Compiler */
  #define __INLINE         inline                                     /*!< inline keyword for GNU Compiler */
  #define __STATIC_INLINE  static inline

#elif defined ( __ICCARM__ )
  #define __ASM            __asm                                      /*!< asm keyword for IAR Compiler */
  #define __INLINE         inline                                     /*!< inline keyword for IAR Compiler. Only available in High optimization mode! */
  #define __STATIC_INLINE  static inline

#elif defined ( __TMS470__ )
  #define __ASM            __asm                                      /*!< asm keyword for TI CCS Compiler */
  #define __STATIC_INLINE  static inline

#elif defined ( __TASKING__ )
  #define __ASM            __asm                                      /*!< asm keyword for TASKING Compiler */
  #define __INLINE         inline                                     /*!< inline keyword for TASKING Compiler */
  #define __STATIC_INLINE  static inline

#elif defined ( __CSMC__ )
  #define __packed
  #define __ASM            _asm                                      /*!< asm keyword for COSMIC Compiler */
  #define __INLINE         inline                                    /*!< inline keyword for COSMIC Compiler. Use -pc99 on compile line */
  #define __STATIC_INLINE  static inline

#else
  #error Unknown compiler
#endif

/* Define WEAK attribute */
#if !defined(__WEAK)
#if defined ( __CC_ARM )
#define __WEAK __attribute__ ((weak))
#elif defined ( __ICCARM__ )
#define __WEAK __weak
#elif defined ( __GNUC__ )
#define __WEAK __attribute__ ((weak))
#elif defined ( __TASKING__ )
#define __WEAK __attribute__ ((weak))
#endif
#endif



/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef unsigned char uint8;           /**< \brief 8 bit unsigned value  */
typedef unsigned short uint16;         /**< \brief 16 bit unsigned value */
typedef unsigned int uint32;           /**< \brief 32 bit unsigned value */
typedef unsigned long long uint64;     /**< \brief 64 bit unsigned value */

typedef signed char sint8;             /**< \brief 8 bit signed value  */
typedef signed short sint16;           /**< \brief 16 bit signed value */
typedef signed int sint32;             /**< \brief 32 bit signed value */
typedef signed long long int64;        /**< \brief 64 bit signed value */

typedef float   float32;               /**< \brief 32 bit float value */
typedef double  float64;               /**< \brief 64 bit float value */

typedef short FixPoint16;              /**< \brief 16 bit fix point value */
typedef long  FixPoint32;              /**< \brief 32 bit fix point value */

typedef unsigned char boolean;         /**< \brief for use with TRUE/FALSE */

/** \brief boolean definitions
 */
#ifndef TRUE
#define TRUE  ((boolean) 1U)
#endif
#ifndef FALSE
#define FALSE ((boolean) 0U)
#endif


/** \brief Complex type definition
 */
typedef struct
{
  sint16 Real;  /**< \brief Real part */
  sint16 Imag;  /**< \brief Imaginary part */
}TComplex;


#endif /* BSWC_STD_TYPES_H */

