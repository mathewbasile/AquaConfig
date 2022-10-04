/** 
 * <h3>D-Flow Technology AB,  2017</h3>
 * 
 * PROPRIETARY CLAUSE: This document contains information and/or data which is
 * proprietary and confidential to D-Flow Technology AB. This information and/or
 * data is to be used only for the benefit of the supplier, and is not to be
 * used for the benefit of other parties without the written consent of
 * D-Flow Technology AB.
 *
 * To enable UART-debugging please enable UART_DEBUG in defines.h
 *
 */

#ifndef __AQUACONF_H
#define __AQUACONF_H

#include "compiler_options.h"

#include <cstdint>

#include "aqualite.h"

#include "AquariusKeys.h"

#define CMD_ACTION_PASSCODE_1 1414808901 // Command Action Passcode 


 /*** Max allowed configurable measurements in MeasurementCommand */
#define MEAS_OUT_MAX_NUM_OF_MEASUREMENTS   65535

 // AGC mode
#define BITS_AGC_MODE_1	 0x0001
#define BITS_AGC_MODE_2	 0x0002
#define BITS_AGC_MODE_3	 0x0003
#define BITS_AGC_MODE_4	 0x0004
#define BITS_AGC_MODE_5	 0x0005
#define BITS_AGC_MODE_6	 0x0006
#define BITS_AGC_MODE_7	 0x0007
#define BITS_AGC_MODE_8	 0x0008
#define BITS_AGC_MODE_9	 0x0009
#define BITS_AGC_MODE_10 0x000A
#define BITS_AGC_MODE_11 0x000B
#define BITS_AGC_MODE_12 0x000C
#define BITS_AGC_MODE_13 0x000D
#define BITS_AGC_MODE_14 0x000E
#define BITS_AGC_MODE_15 0x000F
#define MSK_AGC_MODE	 0x000F

// actions
#define BIT_MEAS_ACT_AGC	0x0010
#define BIT_MEAS_ACT_HFC	0x0020
#define BIT_MEAS_ACT_SING	0x0040
#define BIT_MEAS_ACT_ADC	0x0080
#define MSK_MEAS_ACT		0x00F0
// attrib
#define BIT_MEAS_ATR_COMP	0x0100	// not used
#define BIT_MEAS_ATR_AGC_RMIN	0x0200	// set R1 = RMIN before an AGC
#define BIT_MEAS_ATR_AGC_GM11	0x0400	// set GM1 =  11 before an AGC
#define BIT_MEAS_ATR_AGC_EVAL	0x0800	// evaluate PTRIG_LOW threshold
#define MSK_MEAS_ATR		0x0F00
// mode
#define BITS_MEAS_MODE_1	0x1000
#define BITS_MEAS_MODE_2	0x2000
#define BITS_MEAS_MODE_3	0x3000
#define BITS_MEAS_MODE_4	0x4000
#define BITS_MEAS_MODE_5	0x5000
#define BITS_MEAS_MODE_6	0x6000
#define BITS_MEAS_MODE_7	0x7000
#define BITS_MEAS_MODE_8	0x8000
#define BITS_MEAS_MODE_9	0x9000
#define BITS_MEAS_MODE_10	0xA000
#define BITS_MEAS_MODE_11	0xB000
#define BITS_MEAS_MODE_12	0xC000
#define BITS_MEAS_MODE_13	0xD000
#define BITS_MEAS_MODE_14	0xE000
#define BITS_MEAS_MODE_15	0xF000
#define MSK_MEAS_MODE		0xF000

#define PARAM_UL_CONFIG				1	// *
#define PARAM_UL_CONFIG_CAL_LEN			2
#define PARAM_UL_CONFIG_DIR1_ON			3
#define PARAM_UL_CONFIG_AG_CAL_DELAY_ON		4
#define PARAM_UL_START				5
#define PARAM_UL_LOOPC				6
#define PARAM_UL_SMARK				7
#define PARAM_UL_SSPACE				8
#define PARAM_UL_ANASAMPLE			9
#define PARAM_UL_PRE_MEAS_DELAY_CAL		10
#define PARAM_UL_PRE_MEAS_DELAY_0		11
#define PARAM_UL_PRE_MEAS_DELAY_1		12
#define PARAM_UL_INIT_PULSE_DELAY		13
#define PARAM_UL_LAST_PULSE_DELAY		14
#define PARAM_UL_HFOSC_SEL			15
#define PARAM_UL_REF_CONFIG			16
#define PARAM_UL_TEST_CONFIG			17

#define PARAM_AG_STAGE1_STATIC			18
#define PARAM_AG_STAGE1_STATIC_I1		19
#define PARAM_AG_STAGE1_STATIC_ALL_TR		20
#define PARAM_AG_STAGE1_AUTO			21	// *
#define PARAM_AG_STAGE1_AUTO_R1			22
#define PARAM_AG_STAGE1_AUTO_GM1		23
#define PARAM_AG_STAGE1_AUTO_C1			24
#define PARAM_AG_STAGE1_CONFIG			25	// *
#define PARAM_AG_STAGE1_CONFIG_MIN_R1		26
#define PARAM_AG_STAGE1_CONFIG_MIN_GM1		27
#define PARAM_AG_STAGE1_CONFIG_LOWEST		28
#define PARAM_AG_STAGE1_CONFIG_R1_SEARCH	29
#define PARAM_AG_STAGE1_CONFIG_GM1_SEARCH	30
#define PARAM_AG_STAGE1_CONFIG_C1_AUTO		31
#define PARAM_AG_STAGE1_BANDWIDTH		32
#define PARAM_AG_STAGE2				33
#define PARAM_AG_STAGE2_I2			34
#define PARAM_AG_STAGE2_A2			35
#define PARAM_AG_STAGE2_R2			36
#define PARAM_AG_STAGE2_C2			37
#define PARAM_AG_OTHER				38	// *
#define PARAM_AG_OTHER_SEL_HP			39
#define PARAM_AG_OTHER_BYPASS			40
#define PARAM_AG_OTHER_SEL_PAD_BP		41
#define PARAM_AG_OTHER_ATTENUATION		42
#define PARAM_AG_OTHER_INV			43
#define PARAM_AG_OTHER_TX_IN_SEL_NPULL		44
#define PARAM_AG_POWER				45	// *
#define PARAM_AG_POWER_POWERCYCLE_EN		46
#define PARAM_AG_POWER_HSPEED_EN		47
#define PARAM_AG_PTRIGLEV			48	// *
#define PARAM_AG_PTRIGLEV_PTRIGLEV		49
#define PARAM_AG_PTRIGLEV_PTRIGLEV_LOW		50
#define PARAM_AG_PTRIGLEV_PTRIGLEV_HIGH		51
#define PARAM_AG_OFS_TRIM			52
#define PARAM_AG_PTRIG_MEM_MASK			53

#define PARAM_TX_PCONFIG			54
#define PARAM_TX_P_STRENGTH			54
#define PARAM_TX_P_STRENGTH_P5_0		55
#define PARAM_TX_P_STRENGTH_P5_1		56
#define PARAM_TX_P_STRENGTH_P5_2		57
#define PARAM_TX_P_STRENGTH_P5_3		58
#define PARAM_TX_N_STRENGTH			59
#define PARAM_TX_N_STRENGTH_N70			60
#define PARAM_TX_N_STRENGTH_N5			61
#define PARAM_TX_EXC_LENGTH			62
#define PARAM_TX_EXC_CONFIG			63
#define PARAM_TX_EXC_CONFIG_SEL_N70		64
#define PARAM_TX_EXC_CONFIG_RX_ATT		65
#define PARAM_TX_EXC_CONFIG_N5_ALWAYS		66	// UFO3
#define PARAM_TX_MSEQ_POL_ENABLE		67
#define PARAM_TX_MSEQ_POL_SELECT		68
#define PARAM_TX_MSEQ_EXCLEVEL			69
#define PARAM_TX_MSEQ_OUTPUTENABLE		70
#define PARAM_TX_MSEQ_STRONG_PD_DISABLE_0	71	// ONLY UFO2
#define PARAM_TX_MSEQ_STRONG_PD_DISABLE_1	72	// ONLY UFO2
#define PARAM_TX_MSEQ_STRONG_SEND_PD		73	// ONLY UFO2
#define PARAM_TX_STRONG_PD_CONTROL		74	// UFO3
#define PARAM_TX_STRONG_PD_CONTROL_SEND_TX_SEL	75	// UFO3
#define PARAM_TX_STRONG_PD_CONTROL_RECV_MSEQ_SEL 76	// UFO3
#define PARAM_TX_STRONG_PD_DISABLE_DIR0		77	// UFO3
#define PARAM_TX_STRONG_PD_DISABLE_DIR1		78	// UFO3

#define PARAM_TX_SENDREG0			79	// ONLY UFO2
#define PARAM_TX_SENDREG1			80	// ONLY UFO2
#define PARAM_TX_SENDREG2			81	// ONLY UFO2
#define PARAM_TX_SENDREG3			82	// ONLY UFO2
#define PARAM_TX_SENDREG0_DIR0			79	// UFO3
#define PARAM_TX_SENDREG1_DIR0			80	// UFO3
#define PARAM_TX_SENDREG2_DIR0			81	// UFO3
#define PARAM_TX_SENDREG3_DIR0			82	// UFO3
#define PARAM_TX_SENDREG0_DIR1			83	// UFO3
#define PARAM_TX_SENDREG1_DIR1			84	// UFO3
#define PARAM_TX_SENDREG2_DIR1			85	// UFO3
#define PARAM_TX_SENDREG3_DIR1			86	// UFO3
#define PARAM_TX_RECEIVEREG0			87	// ONLY UFO2
#define PARAM_TX_RECEIVEREG1			88	// ONLY UFO2
#define PARAM_TX_RECEIVEREG2			89	// ONLY UFO2
#define PARAM_TX_RECEIVEREG3			90	// ONLY UFO2
#define PARAM_TX_RECEIVEREG0_DIR0		87	// UFO3
#define PARAM_TX_RECEIVEREG1_DIR0		88	// UFO3
#define PARAM_TX_RECEIVEREG2_DIR0		89	// UFO3
#define PARAM_TX_RECEIVEREG3_DIR0		90	// UFO3
#define PARAM_TX_RECEIVEREG0_DIR1		91	// UFO3
#define PARAM_TX_RECEIVEREG1_DIR1		92	// UFO3
#define PARAM_TX_RECEIVEREG2_DIR1		93	// UFO3
#define PARAM_TX_RECEIVEREG3_DIR1		94	// UFO3

#define PARAM_TX_SENDREG_AGC_0			95	// UFO3
#define PARAM_TX_SENDREG_AGC_1			96	// UFO3
#define PARAM_TX_SENDREG_AGC_2			97	// UFO3
#define PARAM_TX_SENDREG_AGC_3			98	// UFO3
#define PARAM_TX_RECEIVEREG_AGC_0		99	// UFO3
#define PARAM_TX_RECEIVEREG_AGC_1		100	// UFO3
#define PARAM_TX_RECEIVEREG_AGC_2		101	// UFO3
#define PARAM_TX_RECEIVEREG_AGC_3		102	// UFO3

#define PARAM_TX_POL_SEND				103
#define PARAM_TX_POL_RECEIVE			104
#define PARAM_TX_POL_SWAP_EN			105

#define PARAM_AG_LOOPC					106

#define PARAM_OTHER_MSEQ_STRENGTH		107	


#define _MEAS_SETUP 0
#define _HCLK_CORE	1
#define _HCLK_MEAS	2
#define _PRESSURE_MEAS_PERIOD	3
#define _TEMPERATURE_MEAS_PERIOD	4
#define _LOW_FLOW_THRESHOLD		5
#define _HIGH_FLOW_THRESHOLD	6

#define ASIC_PARAM_MAX 62		
#define ASIC_PARAM_LOW_FLOW  (ASIC_PARAM_MAX - 21 )
#define ASIC_PARAM_HIGH_FLOW (ASIC_PARAM_MAX - 10)


#define AQUARIUS_DATA_POINT_STRING_SIZE 17


typedef enum _eRtcInterval
{
	RTC_SLEEP_TST = 0,
	RTC_MEAS_INTERVAL_1_S,
	RTC_MEAS_INTERVAL_500_MS,
	RTC_MEAS_INTERVAL_250_MS,
	RTC_MEAS_INTERVAL_125_MS,
	RTC_MEAS_INTERVAL_100_MS,
	RTC_MEAS_INTERVAL_62_MS,
	RTC_MEAS_INTERVAL_50_MS,
	RTC_MEAS_INTERVAL_2_S,

	// Insert new intervals here ... Storage mode is only used and set internally.

	RTC_MEAS_INTERVAL_STORAGE,				// For storage mode
	RTC_MEAS_INTERVAL_MAX,
}eRtcInterval;


// Measurement Output Command Measurement Types
typedef enum _eMeasurementOutputPayloadType
{
	MEAS_OUT_PAYLOAD_TYPE_TT = 0,		// Include Transmit Times
	MEAS_OUT_PAYLOAD_TYPE_TT_PT,		// Include Transmit Times, Pressure, and Fluid Temperature
	MEAS_OUT_PAYLOAD_TYPE_TT_PT_SS,		// Include Transmit Times, Pressure, Fluid Temperature and UFO Status
	MEAS_OUT_PAYLOAD_TYPE_FR,		// Include Flow Rate
	MEAS_OUT_PAYLOAD_TYPE_TT_FR,		// Include Transit Times, Flow Rate
	MEAS_OUT_PAYLOAD_TYPE_TT_SS,		// Include Transit Times, UFO Status
	MEAS_OUT_PAYLOAD_TYPE_FR_FRFILT,		// Include Flow Rate and Filtered Flow Rate
	MEAS_OUT_PAYLOAD_TYPE_FR_MI_IV,		// Include Flow Rate, Measurement Interval, Incremental Volume
	MEAS_OUT_PAYLOAD_TYPE_TT_FR_MI_IV,		// Include Transit Times, Flow Rate, Measurement Interval, Incremental Volume
	MEAS_OUT_PAYLOAD_TYPE_INCR_VOLS,		// Include Incr. Vol, ZFS Bucket Vol, Rff Buffer Vol, Post-Filter Incr. Vol
	MEAS_OUT_PAYLOAD_TYPE_TT_REYNOLDS_FR,	// Include Transit Times, Reynolds Number and Flow Rate
	MEAS_OUT_PAYLOAD_TYPE_TT_SS_FR_TOT,	    // Include Transit Times, UFO Status, Flow Rate, and Totalizer [user units]
	MEAS_OUT_PAYLOAD_TYPE_TT_SS_RE_FV,		// Include Transit Times, UFO Status, Reynolds, Flow Velocity

	MEAS_OUT_PAYLOAD_TYPE_MAX_VALUE = MEAS_OUT_PAYLOAD_TYPE_TT_SS_RE_FV,
	NUM_OF_MEAS_OUT_PAYLOAD_TYPES,
}eMeasurementOutputPayloadType;

typedef enum _eTableIndices
{
	APP_TABLE_IDX_R2K = 0,
	APP_TABLE_IDX_R2K_THRESH,
	APP_TABLE_IDX_SOS2TEMP,
	APP_TABLE_IDX_TEMP2VISC,
	APP_TABLE_IDX_USCALC,
	APP_TABLE_IDX_SCREEN_LIST,
	APP_TABLE_IDX_RES2TEMP,
	APP_TABLE_IDX_PRESSURE_CAL,
	APP_TABLE_IDX_TEMP_CAL,
	APP_TABLE_IDX_DIAG_CNTRS,
	APP_TABLE_IDX_TEST,

	APP_TABLE_IDX_MAX_VALUE = APP_TABLE_IDX_TEST,
	NUM_OF_TABLES,
}eTableIndices;

/* Align with Aquarius enumeration for supported data types */
typedef enum _eTableDataTypes
{
	APP_TABLE_DATA_TYPE_RSVD = 0,

	APP_TABLE_DATA_TYPE_UINT8,
	APP_TABLE_DATA_TYPE_UINT16,
	APP_TABLE_DATA_TYPE_UINT32,
	APP_TABLE_DATA_TYPE_UINT64,

	APP_TABLE_DATA_TYPE_SINT8,
	APP_TABLE_DATA_TYPE_SINT16,
	APP_TABLE_DATA_TYPE_SINT32,
	APP_TABLE_DATA_TYPE_SINT64,

	APP_TABLE_DATA_TYPE_FLOAT32,
	APP_TABLE_DATA_TYPE_FLOAT64,

	APP_TABLE_DATA_TYPE_STRING,
	APP_TABLE_DATA_TYPE_COMPLEX,
	APP_TABLE_DATA_TYPE_SUBKEY,

	APP_TABLE_DATA_TYPE_MAX_VALUE = APP_TABLE_DATA_TYPE_SUBKEY, /* cannot exceed 16 */
	NUM_OF_DATA_TYPES,
}eTableDataType;

typedef struct {
	uint8_t  name[128];
	uint16_t param_val;
} param_t;




typedef struct tuple3
{
	uint16_t first;
	uint16_t second;
	uint16_t third;
}  tuple3_t;


#pragma pack(push, 1)


typedef struct Aqarius_Parameter {
	uint16_t key;
	uint16_t length;
	uint8_t	 value[AQUARIUS_MAX_VALUE_FRAME_SIZE - 4];		// Practical upper limit
}   Aquarius_Parameter_t;

typedef struct Aqarius_Parameter_short {
	uint8_t		key;
	uint8_t		length;
	uint8_t		value[AQUARIUS_MAX_VALUE_FRAME_SIZE - 2];
}   Aquarius_Parameter_short_t;

typedef union {
	Aquarius_Parameter_t p;
	Aquarius_Parameter_short_t ps;
	uint8_t buf[AQUARIUS_MAX_VALUE_FRAME_SIZE];
}  Aquarius_Parameter_Buf_t;


typedef void (*a_ptr)(Aquarius_Parameter_t* param, aqua_frame_t* out);
typedef struct {
	uint16_t key;
	a_ptr action;	
}   Aquarius_Action_t;


typedef union Aquarius_Data_point {
	uint32_t u32;
	uint16_t u16;
	uint8_t  u8;
	uint8_t  string[AQUARIUS_DATA_POINT_STRING_SIZE];	
} Aquarius_Data_point_t;

#pragma pack(pop)


#define AQUARIUS_LOG(frame, s)	\
do { 							\
	aquaparser_init((frame), true, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);	\
	aquaparser_add_string(AQUARIUS_KEY_DEBUG_OUTPUT, (frame), (s));		\
	aquaparser_seal((frame));											\
}while(0);

typedef enum _eCmdActionRequest
{
	CMD_ACTION_NULL = 0,
	CMD_ACTION_ENABLE_CLK_OUT,
	CMD_ACTION_FORCE_RESET,
	CMD_ACTION_ERASE_NVM,
	CMD_ACTION_MID_LOCK_UNLOCK,
	CMD_ACTION_ASIC_START_PTRIG_SWEEP,
	CMD_ACTION_CLEAR_TOTALIZER,
	CMD_ACTION_SET_CORE_REGULATION,
	CMD_ACTION_ASIC_START_STG2_SWEEP,
	CMD_ACTION_CLEAR_ALARMS,
	CMD_ACTION_CLEAR_DIAGNOSTIC_CNTRS,
	CMD_ACTION_SET_PROFILE_COMPRESSION,
	CMD_ACTION_DISPLAY_TARGET,
	CMD_ACTION_DISPLAY_NEXT,
	CMD_ACTION_ALD_ENABLE,
	CMD_ACTION_OUTPUT3_LOOPBACK_ENABLE,
	CMD_ACTION_IR_PULSE_MODE,

	/* Insert no new commands below this comment */
	CMD_ACTION_LAST_ACTION,
} eCmdActionRequest;



typedef enum _eAlarmType
{
	ALARM_TYPE_EMPTY_PIPE = 0,
	ALARM_TYPE_TEMPERATURE,
	ALARM_TYPE_END_OF_LIFE,
	ALARM_TYPE_NO_USAGE,

	ALARM_TYPE_REVERSE_FLOW,
	ALARM_TYPE_LEAK,
	ALARM_TYPE_PROGRAM,
	ALARM_TYPE_SENSOR,

	ALARM_TYPE_PRESSURE,
	ALARM_TYPE_OVERFLOW,

	ALARM_TYPE_MAX = ALARM_TYPE_OVERFLOW,
	ALARM_TYPE_MAX_SIZE,
}eAlarmType;









/**
 * Searches for aquarius key function in model/model_aqua.c
 */
bool aquaparser_dispatch(aqua_frame_t *frame, aqua_frame_t *out);

/**
 * Predicate which returns true if we can (should) execute the request.
 */
bool aquaparser_lock_level(Aquarius_Parameter_t *param);

/**
 * Initializes an aqua_frame_t using key_length and checksum.
 */
void aquaparser_init(aqua_frame_t *out, bool key_length, int type_checksum);

/**
 * Adds U8 value to aqua_frame_t out.
 */
bool aquaparser_add_uint8(uint16_t key, aqua_frame_t *out, uint8_t value);

/**
 * Adds U16 value to aqua_frame_t out.
 */
bool aquaparser_add_uint16(uint16_t key, aqua_frame_t *out, uint16_t value);

/**
 * Adds U32 value to aqua_frame_t out.
 */
bool aquaparser_add_uint32(uint16_t key, aqua_frame_t *out, uint32_t value);

/**
 * Adds U64 value to aqua_frame_t out.
 */
bool aquaparser_add_uint64(uint16_t key, aqua_frame_t *out, uint64_t value);

/**
 * Adds float value to aqua_frame_t out.
 */

bool aquaparser_add_float(uint16_t key, aqua_frame_t *out, float value);

/**
 * Adds double value to aqua_frame_t out.
 */
bool aquaparser_add_double(uint16_t key, aqua_frame_t *out, double value);

/**
 * Adds string value to frame-buffer
 * @param - key value
 * @param - pointer to frame
 * @param - string value
 * @return bool value fits in buffer
 *
 * Assumes that string in null formated and never longer than AQUARIUS_MAX_VALUE_FRAME_SIZE.
 * If value does not fit false is returned.
 */
bool aquaparser_add_string(uint16_t key, aqua_frame_t *out, uint8_t *str);

/**
 * Adds data to aqua_frame_t out.
 */
bool aquaparser_add_data(uint16_t key, aqua_frame_t *out, uint8_t *data, uint16_t length);

/**
 * Calculates checksum of the aqua_frame_t and adds it to the message
 */
bool aquaparser_seal(aqua_frame_t *out);

/**
 * Utility function used by aquaparse aka aqualite.c
 */
char * find_param_ul_name(int key);

/**
 * Utility function used by aquaparse aka aqualite.c
 */
char * find_param_ul_element(int reg);

/**
 * Utility function used by aquaparse aka aqualite.c
 */
int find_param_key(char *name, param_t *p, int length);

/**
 * Utility function used by aquaparse aka aqualite.c
 */
char *find_param_name(int key, param_t *p, int length);

/**
 * Utility function used by aquaconf
 */
int find_param(char *name, param_t *list, int size);

/**
 * Utility function used by aquaparse aka aqualite.c
 */
uint8_t find_table_index(char *str);

/**
 * Utility function used by aquaparse aka aqualite.c
 */
char *find_diacounter_name(int key);


void build_enable_clk_out(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_force_reset(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_erase_nvm(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_MID_lock_unlock(int* arg, int* argc, aqua_frame_t* out);
void build_start_ptrig_sweep(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_clear_totalizer(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_set_core_regulation(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_start_stg2_sweep(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_clear_alarms(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_clear_diag_cntrs(int* arg, int* argc, aqua_frame_t* out);
void build_set_profile_compression(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_ALD(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_digital_output_3_loopback(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_IR_pulse_out(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_measurements_command(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_table_active_corordinates(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_mechanical_list(char* argv[], int* arg, int* argc, aqua_frame_t* out, uint8_t table[], int table_size, int* ival);
void build_alarm_keys(char* argv[], int* arg, int* argc, aqua_frame_t* out, int* ival);
void build_table_write_cmd(char* argv[], int* arg, int* argc, aqua_frame_t* out, uint8_t table[], int table_size);
void build_table_read_cmd(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_meter_attributes(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_flow_rate(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_zff(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_average_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_median_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_adaptive_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_weighted_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_MBUS_report(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_MBUS_cfg(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_MBUS_ctl(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_rff(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_temperature(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_pressure(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_3wire_config(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_alarm_driver_config(char* argv[], int* arg, int* argc, aqua_frame_t* sub, aqua_frame_t* out, bool driver_status);
void build_ASIC_status(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub, uint32_t* u32);
void build_meter_read_interval(char* argv[], int* arg, int* argc, uint32_t* u32, aqua_frame_t* out);
void build_polar_process_variables(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_bootloader_fw_version(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_hardware_version(char* argv[], int* arg, int* argc, aqua_frame_t* out);
void build_flow_totalizer(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_digital_output(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_flow_simulation(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);
void build_param(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub);

int main(int argc, char* argv[]);


#endif
