#ifndef   _MCTL_HAL_H   
#define   _MCTL_HAL_H
#include "types.h"
#include "bsp.h"
#define pattern_goto(...)
#define DRAM_PRINK_ENABLE
#ifdef DRAM_PRINK_ENABLE
#define dram_dbg(fmt,args...)	UART_printf2(fmt ,##args)
#else
#define dram_dbg(fmt,args...)
#endif
#define DRAM_MEM_BASE_ADDR	0x40000000
#define DRAM_RET_OK		0
#define DRAM_RET_FAIL	1


typedef struct __DRAM_PARA
{
	//normal configuration
	unsigned int        dram_clk;
	unsigned int        dram_type;		//dram_type			DDR2: 2				DDR3: 3		LPDDR2: 6	LPDDR3: 7	DDR3L: 31
	//unsigned int        lpddr2_type;	//LPDDR2 type		S4:0	S2:1 	NVM:2
    unsigned int        dram_zq;		//do not need
    unsigned int		dram_odt_en;

	//control configuration
	unsigned int		dram_para1;
    unsigned int		dram_para2;

	//timing configuration
	unsigned int		dram_mr0;
    unsigned int		dram_mr1;
    unsigned int		dram_mr2;
    unsigned int		dram_mr3;
    unsigned int		dram_tpr0;	//DRAMTMG0
    unsigned int		dram_tpr1;	//DRAMTMG1
    unsigned int		dram_tpr2;	//DRAMTMG2
    unsigned int		dram_tpr3;	//DRAMTMG3
    unsigned int		dram_tpr4;	//DRAMTMG4
    unsigned int		dram_tpr5;	//DRAMTMG5
   	unsigned int		dram_tpr6;	//DRAMTMG8

    //reserved for future use
    unsigned int		dram_tpr7;
    unsigned int		dram_tpr8;
    unsigned int		dram_tpr9;
    unsigned int		dram_tpr10;
    unsigned int		dram_tpr11;
    unsigned int		dram_tpr12;
    unsigned int		dram_tpr13;


}__dram_para_t;
extern void dramc_bit_align(__dram_para_t *para);
extern void dram_udelay (unsigned int n);
extern unsigned int mctl_init(void);
extern unsigned int mctl_init_dram(void);
extern unsigned int mctl_sys_init(__dram_para_t *para);
extern void auto_set_timing_para(__dram_para_t *para);
extern void auto_set_dram_para(__dram_para_t *para);
extern signed int init_DRAM(int type, __dram_para_t *para);
extern void mctl_com_init(__dram_para_t *para);
#endif  //_MCTL_HAL_H
