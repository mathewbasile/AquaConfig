#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#include "aquaconf.h"

#include "structs.h"

#include "AquariusKeys.h"

#include "Crc.h"
#include <stdlib.h>


param_t param_mechanical_list[] = {
	{"LEN",		0},
	{"AREA", 	1},
	{"DIA",		2},
	{"DSOS",	3},
	{"DZC",		4}
};

param_t param_mode_list[] = {
	{"BITS_AGC_MODE_1",	 		BITS_AGC_MODE_1},
	{"BITS_AGC_MODE_2",	 		BITS_AGC_MODE_2},
	{"BITS_AGC_MODE_3",	 		BITS_AGC_MODE_3},
	{"BITS_AGC_MODE_4",	 		BITS_AGC_MODE_4},
	{"BITS_AGC_MODE_5",	 		BITS_AGC_MODE_5},
	{"BITS_AGC_MODE_6",	 		BITS_AGC_MODE_6},
	{"BITS_AGC_MODE_7",	 		BITS_AGC_MODE_7},
	{"BITS_AGC_MODE_8",	 		BITS_AGC_MODE_8},
	{"BITS_AGC_MODE_9",	 		BITS_AGC_MODE_9},
	{"BITS_AGC_MODE_10", 		BITS_AGC_MODE_10},
	{"BITS_AGC_MODE_11", 		BITS_AGC_MODE_11},
	{"BITS_AGC_MODE_12", 		BITS_AGC_MODE_12},
	{"BITS_AGC_MODE_13", 		BITS_AGC_MODE_13},
	{"BITS_AGC_MODE_14", 		BITS_AGC_MODE_14},
	{"BITS_AGC_MODE_15", 		BITS_AGC_MODE_15},
	{"BIT_MEAS_ACT_AGC",		BIT_MEAS_ACT_AGC},
	{"BIT_MEAS_ACT_HFC",		BIT_MEAS_ACT_HFC},
	{"BIT_MEAS_ACT_SING",		BIT_MEAS_ACT_SING},
	{"BIT_MEAS_ACT_ADC",		BIT_MEAS_ACT_ADC},
	{"BIT_MEAS_ATR_COMP",		BIT_MEAS_ATR_COMP},
	{"BIT_MEAS_ATR_AGC_RMIN",	BIT_MEAS_ATR_AGC_RMIN },
	{"BIT_MEAS_ATR_AGC_GM11",	BIT_MEAS_ATR_AGC_GM11 },
	{"BIT_MEAS_ATR_AGC_EVAL",	BIT_MEAS_ATR_AGC_EVAL },
	{"BITS_MEAS_MODE_1",		BITS_MEAS_MODE_1  },
	{"BITS_MEAS_MODE_2",		BITS_MEAS_MODE_2  },
	{"BITS_MEAS_MODE_3",		BITS_MEAS_MODE_3  },
	{"BITS_MEAS_MODE_4",		BITS_MEAS_MODE_4  },
	{"BITS_MEAS_MODE_5",		BITS_MEAS_MODE_5  },
	{"BITS_MEAS_MODE_6",		BITS_MEAS_MODE_6  },
	{"BITS_MEAS_MODE_7",		BITS_MEAS_MODE_7  },
	{"BITS_MEAS_MODE_8",		BITS_MEAS_MODE_8  },
	{"BITS_MEAS_MODE_9",		BITS_MEAS_MODE_9  },
	{"BITS_MEAS_MODE_10",		BITS_MEAS_MODE_10 },
	{"BITS_MEAS_MODE_11",		BITS_MEAS_MODE_11 },
	{"BITS_MEAS_MODE_12",		BITS_MEAS_MODE_12 },
	{"BITS_MEAS_MODE_13",		BITS_MEAS_MODE_13 },
	{"BITS_MEAS_MODE_14",		BITS_MEAS_MODE_14 },
	{"BITS_MEAS_MODE_15",		BITS_MEAS_MODE_15 }
};

param_t param_alarm_list[] = {
	{"ALARM_TYPE_EMPTY_PIPE",	ALARM_TYPE_EMPTY_PIPE},
	{"ALARM_TYPE_TEMPERATURE",	ALARM_TYPE_TEMPERATURE},
	{"ALARM_TYPE_END_OF_LIFE",	ALARM_TYPE_END_OF_LIFE},
	{"ALARM_TYPE_NO_USAGE",		ALARM_TYPE_NO_USAGE},
	{"ALARM_TYPE_REVERSE_FLOW",	ALARM_TYPE_REVERSE_FLOW},
	{"ALARM_TYPE_LEAK",			ALARM_TYPE_LEAK},
	{"ALARM_TYPE_PROGRAM",		ALARM_TYPE_PROGRAM},
	{"ALARM_TYPE_SENSOR",		ALARM_TYPE_SENSOR},
	{"ALARM_TYPE_PRESSURE",		ALARM_TYPE_PRESSURE},
	{"ALARM_TYPE_OVERFLOW",		ALARM_TYPE_OVERFLOW}
};

param_t aquarius_alarm_keys[] = {
	{"AQUARIUS_KEY_REVERSE_TOTAL_ALARM_LIMIT",		AQUARIUS_KEY_REVERSE_TOTAL_ALARM_LIMIT},
	{"AQUARIUS_KEY_NO_USAGE_ALARM_LIMIT",			AQUARIUS_KEY_NO_USAGE_ALARM_LIMIT},
	{"AQUARIUS_KEY_LEAK_ALARM_LIMIT",				AQUARIUS_KEY_LEAK_ALARM_LIMIT},
	{"AQUARIUS_KEY_LOW_TEMPERATURE_ALARM_LIMIT",	AQUARIUS_KEY_LOW_TEMPERATURE_ALARM_LIMIT},
	{"AQUARIUS_KEY_HIGH_TEMPERATURE_ALARM_LIMIT",	AQUARIUS_KEY_HIGH_TEMPERATURE_ALARM_LIMIT},
	{"AQUARIUS_KEY_LOW_PRESSURE_ALARM_LIMIT",		AQUARIUS_KEY_LOW_PRESSURE_ALARM_LIMIT},
	{"AQUARIUS_KEY_HIGH_PRESSURE_ALARM_LIMIT",		AQUARIUS_KEY_HIGH_PRESSURE_ALARM_LIMIT},
};

uint8_t app_tables_element_size[NUM_OF_TABLES] =
{
	APP_TABLE_DATA_TYPE_FLOAT64,
	APP_TABLE_DATA_TYPE_FLOAT64,
	APP_TABLE_DATA_TYPE_FLOAT64,
	APP_TABLE_DATA_TYPE_FLOAT64,
	APP_TABLE_DATA_TYPE_FLOAT64,
	APP_TABLE_DATA_TYPE_UINT8,
	APP_TABLE_DATA_TYPE_FLOAT64,
	APP_TABLE_DATA_TYPE_FLOAT32,
	APP_TABLE_DATA_TYPE_FLOAT32,
	APP_TABLE_DATA_TYPE_UINT16,
	APP_TABLE_DATA_TYPE_FLOAT64,
};



/* The ordering of this struct must mirror the parameter order in src/common/flash/flash.c */
param_t param_ul_list[] = {
	{"MEAS_SETUP",							0},
	{"HCLK_CORE",							0},
	{"HCLK_MEAS",							0},
	{"PRESSURE_MEAS_PERIOD",				0},
	{"TEMPERATURE_MEAS_PERIOD",				0},
	{"LOW_FLOW_THRESHOLD",					0},
	{"HIGH_FLOW_THRESHOLD",					0},
	{"PARAM_UL_CONFIG_DIR1_ON",				PARAM_UL_CONFIG_DIR1_ON},
	{"PARAM_UL_LOOPC",						PARAM_UL_LOOPC},
	{"PARAM_UL_SMARK",						PARAM_UL_SMARK},
	{"PARAM_UL_SSPACE",						PARAM_UL_SSPACE},
	{"PARAM_UL_ANASAMPLE",					PARAM_UL_ANASAMPLE},
	{"PARAM_UL_PRE_MEAS_DELAY_CAL",			PARAM_UL_PRE_MEAS_DELAY_CAL},
	{"PARAM_UL_PRE_MEAS_DELAY_0",			PARAM_UL_PRE_MEAS_DELAY_0},
	{"PARAM_UL_PRE_MEAS_DELAY_1",			PARAM_UL_PRE_MEAS_DELAY_1},
	{"PARAM_UL_INIT_PULSE_DELAY",			PARAM_UL_INIT_PULSE_DELAY},
	{"PARAM_UL_LAST_PULSE_DELAY",			PARAM_UL_LAST_PULSE_DELAY},
	{"PARAM_UL_REF_CONFIG",					PARAM_UL_REF_CONFIG},
	{"PARAM_AG_STAGE1_AUTO_GM1",			PARAM_AG_STAGE1_AUTO_GM1},
	{"PARAM_AG_STAGE1_CONFIG_MIN_R1",		PARAM_AG_STAGE1_CONFIG_MIN_R1},
	{"PARAM_AG_STAGE1_CONFIG_MIN_GM1",		PARAM_AG_STAGE1_CONFIG_MIN_GM1},
	{"PARAM_AG_STAGE1_CONFIG_LOWEST",		PARAM_AG_STAGE1_CONFIG_LOWEST},
	{"PARAM_AG_STAGE1_CONFIG_R1_SEARCH",	PARAM_AG_STAGE1_CONFIG_R1_SEARCH },
	{"PARAM_AG_STAGE1_CONFIG_GM1_SEARCH",	PARAM_AG_STAGE1_CONFIG_GM1_SEARCH},
	{"PARAM_AG_STAGE2_A2",					PARAM_AG_STAGE2_A2},
	{"PARAM_AG_STAGE2_R2",					PARAM_AG_STAGE2_R2},
	{"PARAM_AG_OTHER_SEL_HP",				PARAM_AG_OTHER_SEL_HP},
	{"PARAM_AG_OTHER_SEL_PAD_BP",			PARAM_AG_OTHER_SEL_PAD_BP},
	{"PARAM_AG_PTRIGLEV",					PARAM_AG_PTRIGLEV},
	{"PARAM_TX_PCONFIG",					PARAM_TX_PCONFIG},
	{"PARAM_TX_EXC_LENGTH",					PARAM_TX_EXC_LENGTH},
	{"PARAM_TX_EXC_CONFIG_SEL_N70",			PARAM_TX_EXC_CONFIG_SEL_N70},
	{"PARAM_TX_MSEQ_EXCLEVEL",				PARAM_TX_MSEQ_EXCLEVEL},
	{"PARAM_TX_MSEQ_OUTPUTENABLE",			PARAM_TX_MSEQ_OUTPUTENABLE},
	{"PARAM_OTHER_MSEQ_STRENGTH",			PARAM_OTHER_MSEQ_STRENGTH},
	{"PARAM_AG_LOOPC",						PARAM_AG_LOOPC},
};

param_t param_low_flow_list[] = {
	{"PARAM_UL_LOOPC",						PARAM_UL_LOOPC},
};

param_t param_high_flow_list[] = {
	{"PARAM_UL_LOOPC",						PARAM_UL_LOOPC},
};

void aquaparser_init(aqua_frame_t* out, bool key_length, int type_checksum)
{
	memset((void*)out, 0x0, sizeof(aqua_frame_t));

	out->data.aqua_header.preamble = 0xa5;

	out->data.aqua_header.byte_order = ENCODER_AQUARIUS_LITTLE_ENDIAN;

	out->data.aqua_header.packet_type_length = (key_length << 15) |
		((type_checksum & 0x7) << 12);
	out->len = 4;
}

bool aquaparser_add_uint8(uint16_t key, aqua_frame_t* out, uint8_t value)
{
	return aquaparser_add_data(key, out, (uint8_t*)&value, sizeof(uint8_t));
}

bool aquaparser_add_uint16(uint16_t key, aqua_frame_t* out, uint16_t value)
{
	return aquaparser_add_data(key, out, (uint8_t*)&value, sizeof(uint16_t));
}

bool aquaparser_add_uint32(uint16_t key, aqua_frame_t* out, uint32_t value)
{
	return aquaparser_add_data(key, out, (uint8_t*)&value, sizeof(uint32_t));
}

bool aquaparser_add_uint64(uint16_t key, aqua_frame_t* out, uint64_t value)
{
	return aquaparser_add_data(key, out, (uint8_t*)&value, sizeof(uint64_t));
}

bool aquaparser_add_float(uint16_t key, aqua_frame_t* out, float value)
{
	return aquaparser_add_data(key, out, (uint8_t*)&value, sizeof(float));
}

bool aquaparser_add_double(uint16_t key, aqua_frame_t* out, double value)
{
	return aquaparser_add_data(key, out, (uint8_t*)&value, sizeof(double));
}

bool aquaparser_add_string(uint16_t key, aqua_frame_t* out, uint8_t* str)
{
	return aquaparser_add_data(key, out, str, strnlen((const char*)str, AQUA_DATA_FRAME_BUF_SIZE) + 1);
}

bool aquaparser_add_data(uint16_t key, aqua_frame_t* out, uint8_t* data, uint16_t length)
{
	Aquarius_Parameter_Buf_t buf;

	// This check only accounts for 16bit keys - do you care?
	if ((out->len + sizeof(uint16_t) + length) > (AQUARIUS_MAX_VALUE_FRAME_SIZE - 4))
		return false;

	void* ptr;
	int  copy = length;

	// Detect key type 
	if ((out->data.aqua_header.packet_type_length >> 15)) {

		buf.p.key = key;
		buf.p.length = length;
		ptr = (void*)buf.p.value;
		copy += sizeof(uint16_t) * 2;

	}
	else {

		buf.ps.key = (uint8_t)key;
		buf.ps.length = (uint8_t)length;
		length = (uint8_t)length;
		ptr = (void*)buf.ps.value;
		copy += sizeof(uint8_t) * 2;
	}

	memcpy((void*)ptr, data, length);
	memcpy(out->data.buf + out->len, buf.buf, copy);	// Merge
	out->len += copy;

	return true;
}

bool aquaparser_seal(aqua_frame_t* out)
{
	if (out->len > AQUA_DATA_FRAME_BUF_SIZE) {
		printf("aquaparser_seal - BUF_SIZE overrun\n");
		return false;
	}

	switch ((out->data.aqua_header.packet_type_length >> 12) & 0x07) {

		union {
			uint8_t  u8[4];
			uint16_t u16[2];
			uint32_t u32;
		} val;

		case ENCODER_AQUARIUS_FOOTER_TYPE_CHECKSUM:
		{
			CRC<Crc16> aqua_crc16;

			out->data.aqua_header.packet_type_length += out->len - 4 + 1;

			out->data.buf[out->len + 1] = aqua_crc16.GetCrc(out->data.buf, out->len);

			//out->data.buf[out->len + 1] = aqua_checksum(out->data.buf, out->len);

			out->len++;
		}
		break;

		case ENCODER_AQUARIUS_FOOTER_TYPE_CRC16:
		{
			CRC<Crc16> aqua_crc16;

			out->data.aqua_header.packet_type_length += out->len - 4 + 2;

			//val.u16[0] = aqua_crc16(out->data.buf, out->len);

			val.u16[0] = aqua_crc16.GetCrc(out->data.buf, out->len);

			memcpy(out->data.buf + out->len, &val.u8[0], 2);

			out->len += 2;
		}
		break;

		case ENCODER_AQUARIUS_FOOTER_TYPE_CRC32:
		{
//			CRC<Crc32> aqua_crc32;

			out->data.aqua_header.packet_type_length += out->len - 4 + 4;

			//val.u32 = aqua_crc32(out->data.buf, out->len);

//			val.u32 = aqua_crc32.GetCrc(out->data.buf, out->len);

			memcpy(out->data.buf + out->len, &val.u8[0], 4);

			out->len += 4;
		}
		break;


		default:
			printf("aquaparser_seal - wrong packet type\n");
			return false;
			break;
	}

	return true;
}

int find_param_key(char* name, param_t* p, int length)
{
	int i;

	for (i = 0; i < length; i++, p++)

		if (!strcmp(name, (char*)p->name))
			return i;

	return -1;
}

int find_param(char* name, param_t* list, int size)
{
	int i;

	for (i = 0; i < size; i++)

		if (!strcmp(name, (char*)list[i].name))
			return i;

	return -1;
}

uint8_t find_table_index(char* str)
{
	// table_id
	if (!strcmp(str, "APP_TABLE_IDX_R2K"))				return APP_TABLE_IDX_R2K;
	else if (!strcmp(str, "APP_TABLE_IDX_R2K_THRESH"))	return APP_TABLE_IDX_R2K_THRESH;
	else if (!strcmp(str, "APP_TABLE_IDX_SOS2TEMP"))		return APP_TABLE_IDX_SOS2TEMP;
	else if (!strcmp(str, "APP_TABLE_IDX_TEMP2VISC"))	return APP_TABLE_IDX_TEMP2VISC;
	else if (!strcmp(str, "APP_TABLE_IDX_USCALC"))		return APP_TABLE_IDX_USCALC;
	else if (!strcmp(str, "APP_TABLE_IDX_SCREEN_LIST"))	return APP_TABLE_IDX_SCREEN_LIST;
	else if (!strcmp(str, "APP_TABLE_IDX_RES2TEMP"))		return APP_TABLE_IDX_RES2TEMP;
	else if (!strcmp(str, "APP_TABLE_IDX_PRESSURE_CAL"))	return APP_TABLE_IDX_PRESSURE_CAL;
	else if (!strcmp(str, "APP_TABLE_IDX_TEMP_CAL"))		return APP_TABLE_IDX_TEMP_CAL;
	else if (!strcmp(str, "APP_TABLE_IDX_TEST"))			return APP_TABLE_IDX_TEST;

	fprintf(stderr, "app_calc - find_table_index unknown table %s\n", str);
	exit(EXIT_FAILURE);
}

int parse_hex_string(char* str, uint8_t* out)
{
	bool high = false;
	int  c = 0;

	uint8_t byte = 0;

	if (strncmp("0x", str, 2))
		return 0;

	uint8_t* ptr = (uint8_t*)str + 2;

	for (; *ptr; ptr++) {

		int d = (*ptr >= '0' && *ptr <= '9') ? *ptr - '0' : (*ptr - 'a') + 10;

		if (high) {
			byte |= (d & 0x0F);
			out[c++] = byte;
		}
		else
			byte = (d & 0x0F) << 4;

		high = !high;
	}

	return c;
}

int parse_mode_string(char* str)
{
	int i;
	char* p;
	int mode = 0;

	// Just a MODE and no attributes
	if (strchr(str, '+') == NULL) {
		if ((i = find_param_key(str, param_mode_list, sizeof(param_mode_list) / sizeof(param_t))) != -1)
			return param_mode_list[i].param_val;
		return -1;
	}

	// Irritate over mode string
	char* pContext = NULL;
	p = strtok_s(str, "+", &pContext);

	while (p != (char*)NULL) {
		if ((i = find_param_key(p, param_mode_list, sizeof(param_mode_list) / sizeof(param_t))) != -1)
			mode |= param_mode_list[i].param_val;
		else
			return -1;

		p = strtok_s(NULL, "+", &pContext);
	};

	return mode;
}

bool parse_nominal_string(char* str)
{
	return (
		find_param(str, param_ul_list, sizeof(param_ul_list) / sizeof(param_t)) == -1 &&
		find_param_key(str, param_mechanical_list, sizeof(param_mechanical_list) / sizeof(param_t)) == -1 &&
		strstr(str, "AQUARIUS_") == (char*)NULL && strstr(str, "ALARM_") == (char*)NULL);
}

void build_enable_clk_out(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint8_t  clock;
		uint16_t cycles;
	}  t;

	// Expect three arguments, command name, clock select, and number of cycles
	if ((*argc - *arg) != 3) {
		fprintf(stderr, "aquaconf - error ENABLE_CLK_OUT wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_ENABLE_CLK_OUT;
	t.length = 3;
	t.clock = atol(argv[*arg + 1]);
	t.cycles = atol(argv[*arg + 2]);

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 3;
}

void build_force_reset(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint8_t  mcu;
	}  t;

	// Expect two arguments, command name, and mcu to reset
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error FORCE_RESET wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_FORCE_RESET;
	t.length = 1;

	if (!strcmp(argv[*arg + 1], "ARM")) { t.mcu = 0x00; }
	else if (!strcmp(argv[*arg + 1], "ASIC")) { t.mcu = 0x01; }
	else { fprintf(stderr, "aquaconf - error FORCE_RESET invalid argument\n"); exit(EXIT_FAILURE); }

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;
}

void build_erase_nvm(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		uint8_t  region;
	}  t;
	// Expect two arguments, command name, and memory region, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error ERASE_NVM wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_ERASE_NVM;
	t.length = 5;
	t.passcode = CMD_ACTION_PASSCODE_1;

	if (!strcmp(argv[*arg + 1], "ALL")) { t.region = 0x00; }
	else if (!strcmp(argv[*arg + 1], "RWW")) { t.region = 0x01; }
	else if (!strcmp(argv[*arg + 1], "CFG")) { t.region = 0x02; }
	else { fprintf(stderr, "aquaconf - error ERASE_NVM invalid argument\n"); exit(EXIT_FAILURE); }

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;
}

void build_MID_lock_unlock(int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
	}  t;

	// Expect one arguments, command name
	if ((*argc - *arg) != 1) {
		fprintf(stderr, "aquaconf - error MID_LOCK_UNLOCK wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_MID_LOCK_UNLOCK;
	t.length = 0;

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 1;

}

void build_start_ptrig_sweep(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{

	struct {
		uint8_t command;
		uint8_t length;
		uint16_t meas_mode;
		uint16_t agc_mode;
		uint8_t  loopc;
		uint8_t  start;
		uint8_t  stop;
	}  t;

	// Expect six arguments, command name, meas mode, agc mode, loopc, start and stop
	if ((*argc - *arg) != 6) {
		fprintf(stderr, "aquaconf - error ASIC_START_PTRIG_SWEEP wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_ASIC_START_PTRIG_SWEEP;
	t.length = 7;

	int ret;

	t.meas_mode = (ret = parse_mode_string(argv[*arg + 1]));
	if (ret == -1)
		t.meas_mode = atol(argv[*arg + 1]);

	t.agc_mode = (ret = parse_mode_string(argv[*arg + 2]));
	if (ret == -1)
		t.agc_mode = atol(argv[*arg + 2]);

	t.loopc = atol(argv[*arg + 3]);
	t.start = atol(argv[*arg + 4]);
	t.stop = atol(argv[*arg + 5]);

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 6;

}

void build_clear_totalizer(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		uint8_t  totalizer;
	}  t;

	// Expect two arguments, command name, and totalizer flag, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error CLEAR_TOTALIZER wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_CLEAR_TOTALIZER;
	t.length = 5;
	t.passcode = CMD_ACTION_PASSCODE_1;
	t.totalizer = atol(argv[*arg + 1]);

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;

}

void build_set_core_regulation(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		uint8_t  core_type;
	}  t;

	// Expect two arguments, command name, and core type, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error SET_CORE_REGULATION wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_SET_CORE_REGULATION;
	t.length = 5;
	t.passcode = CMD_ACTION_PASSCODE_1;
	t.core_type = 0;

	t.core_type = !strcmp(argv[*arg + 1], "LDO") ? 0xA5 : t.core_type;
	t.core_type = !strcmp(argv[*arg + 1], "BUCK") ? 0x5A : t.core_type;

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;

}

void build_start_stg2_sweep(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint16_t mode;
		uint16_t delay;
		uint8_t  loopc;
	}  t;

	// Expect four arguments, command name, mode, delay and loopc
	if ((*argc - *arg) != 4) {
		fprintf(stderr, "aquaconf - error ASIC_START_STG2_SWEEP wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	int ret;

	t.command = CMD_ACTION_ASIC_START_STG2_SWEEP;
	t.length = 4;
	t.mode = (ret = parse_mode_string(argv[*arg + 1]));
	t.delay = atol(argv[*arg + 2]);
	t.loopc = atol(argv[*arg + 3]);

	if (ret == -1)
		t.mode = atol(argv[*arg + 1]);

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 4;

}

void build_clear_alarms(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		uint32_t alarm_mask;
	}  t;
	// Expect two arguments, command name, and alarm mask, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error changed CLEAR_ALARMS wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	t.command = CMD_ACTION_CLEAR_ALARMS;
	t.length = 8;
	t.passcode = CMD_ACTION_PASSCODE_1;
	t.alarm_mask = atoi(argv[*arg + 1]);
	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));
	(*arg) += 2;

}

void build_clear_diag_cntrs(int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
	}  t;

	// Expect one arguments, command name, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 1) {
		fprintf(stderr, "aquaconf - error CMD_ACTION_CLEAR_DIAGNOSTIC_CNTRS wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_CLEAR_DIAGNOSTIC_CNTRS;
	t.length = 4;
	t.passcode = CMD_ACTION_PASSCODE_1;

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 1;

}

void build_set_profile_compression(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		uint8_t  set_clear;
	}  t;

	// Expect two arguments, command name, and set_clear condition, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error CMD_ACTION_SET_PROFILE_COMPRESSION wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_SET_PROFILE_COMPRESSION;
	t.length = 5;
	t.passcode = CMD_ACTION_PASSCODE_1;

	if (!strcmp(argv[*arg + 1], "SET")) { t.set_clear = 0x01; }
	else if (!strcmp(argv[*arg + 1], "CLEAR")) { t.set_clear = 0x00; }
	else { fprintf(stderr, "aquaconf - error CMD_ACTION_SET_PROFILE_COMPRESSION invalid argument\n"); exit(EXIT_FAILURE); }

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;

}

void build_ALD(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{

	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		bool	 enable;
	}  t;

	// Expect two arguments, command name, and enable/disable, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error AMBIENT_LIGHT_DETECTION wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_ALD_ENABLE;
	t.length = 5;
	t.passcode = CMD_ACTION_PASSCODE_1;

	if (!strcmp(argv[*arg + 1], "ENABLE")) { t.enable = 0x01; }
	else if (!strcmp(argv[*arg + 1], "DISABLE")) { t.enable = 0x00; }
	else { fprintf(stderr, "aquaconf - error CMD_ACTION_SET_PROFILE_COMPRESSION invalid argument\n"); exit(EXIT_FAILURE); }

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;
}

void build_digital_output_3_loopback(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{

	struct {
		uint8_t  command;
		uint8_t  length;
		uint32_t passcode;
		bool	 enable;
	}  t;

	// Expect two arguments, command name, and enable/disable, passcode is hard coded to make abstraction layer less complex
	if ((*argc - *arg) != 2) {
		fprintf(stderr, "aquaconf - error DIGITAL_OUTPUT_3_LOOPBACK wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_OUTPUT3_LOOPBACK_ENABLE;
	t.length = 5;
	t.passcode = CMD_ACTION_PASSCODE_1;

	if (!strcmp(argv[*arg + 1], "ENABLE")) { t.enable = 0x01; }
	else if (!strcmp(argv[*arg + 1], "DISABLE")) { t.enable = 0x00; }
	else { fprintf(stderr, "aquaconf - error DIGITAL_OUTPUT_3_LOOPBACK invalid argument\n"); exit(EXIT_FAILURE); }

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 2;

}

void build_IR_pulse_out(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct {
		uint8_t  command;
		uint8_t  length;
		bool	 enable;
		uint16_t timeout_s;
		uint32_t meas_interval_us;
		float	 pulse_weight_m3;
	}  t;

	// Expect five arguments, command name, enable/disable, timeout, meas_interval, pulse weight
	if ((*argc - *arg) != 5) {
		fprintf(stderr, "aquaconf - error IR_PULSE_OUTPUT wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	t.command = CMD_ACTION_IR_PULSE_MODE;
	t.length = 11;

	if (!strcmp(argv[*arg + 1], "ENABLE")) { t.enable = 0x01; }
	else if (!strcmp(argv[*arg + 1], "DISABLE")) { t.enable = 0x00; }
	else { fprintf(stderr, "aquaconf - error IR_PULSE_OUTPUT invalid argument\n"); exit(EXIT_FAILURE); }

	t.timeout_s = atol(argv[*arg + 2]);
	t.meas_interval_us = atoi(argv[*arg + 3]);
	t.pulse_weight_m3 = atof(argv[*arg + 4]);

	aquaparser_add_data(AQUARIUS_KEY_POLAR_COMMAND_ACTION_REQUEST, out, (uint8_t*)&t, sizeof(t));

	(*arg) += 5;

}

void build_measurements_command(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{

	tuple3_t tuple;

	tuple.first = atol(argv[*arg + 1]);	// rtc_period
	tuple.second = atol(argv[*arg + 2]);	// meas_type
	tuple.third = atol(argv[*arg + 3]);	// num_measurements

	if (tuple.first >= RTC_MEAS_INTERVAL_MAX) {
		fprintf(stderr, "aquaconf - error : RTC period is not valid\n");
		exit(EXIT_FAILURE);
	}

	if (tuple.second > NUM_OF_MEAS_OUT_PAYLOAD_TYPES) {
		fprintf(stderr, "aquaconf - error : payload type > NUM_OF_MEAS_OUT_PAYLOAD_TYPES\n");
		exit(EXIT_FAILURE);
	}

	if (tuple.third >= MEAS_OUT_MAX_NUM_OF_MEASUREMENTS) {
		fprintf(stderr, "aquaconf - error : too many requested measurements\n");
		exit(EXIT_FAILURE);
	}

	aquaparser_add_data(AQUARIUS_KEY_POLAR_MEASUREMENT_COMMAND, out, (uint8_t*)&tuple, sizeof(tuple));

	(*arg) += 4;
}

void build_table_active_corordinates(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	// Assumes read if not enough arguments
	if ((*argc - *arg) < 6)
	{
		aquaparser_add_data(AQUARIUS_KEY_TABLE_ACTIVE_COORDINATES, out, NULL, 0);
		(*arg)++;
		// Write 
	}
	else
	{
		uint8_t tbl[5];
		if ((*argc - *arg) < 6)
		{
			fprintf(stderr, "aquaconf - error AQUARIUS_KEY_TABLE_ACTIVE_COORDINATES wrong number of arguments\n");
			exit(EXIT_FAILURE);
		}

		tbl[0] = find_table_index(argv[*arg + 1]); // table_id
		tbl[1] = atol(argv[*arg + 2]);	// start_row
		tbl[2] = atol(argv[*arg + 3]);	// start_col
		tbl[3] = atol(argv[*arg + 4]);	// end_row
		tbl[4] = atol(argv[*arg + 5]);	// end_col	
		aquaparser_add_data(AQUARIUS_KEY_TABLE_ACTIVE_COORDINATES, out, (uint8_t*)tbl, sizeof(tbl));
		(*arg) += 6;
	}
}

void build_mechanical_list(char* argv[], int* arg, int* argc, aqua_frame_t* out, uint8_t table[], int table_size, int* ival)
{
	memset((void*)table, 0x0, table_size);

	table[0] = APP_TABLE_IDX_USCALC;

	table[1] = table[3] = param_mechanical_list[*ival].param_val;

	table[5] = APP_TABLE_DATA_TYPE_FLOAT64;	// hardcoded to double

	if (*arg <= (*argc - 2) && sscanf_s(argv[*arg + 1], "%lf", (double*)table[6]) == 1) {

		aquaparser_add_data(AQUARIUS_KEY_TABLE_WRITE_CMD, out, (uint8_t*)table, sizeof(uint8_t) * 6 + sizeof(double));
		(*arg) += 3;
	}
	else {
		aquaparser_add_data(AQUARIUS_KEY_TABLE_READ_CMD, out, (uint8_t*)table, sizeof(uint8_t) * 5);
		(*arg) += 2;
	}
}

void build_alarm_keys(char* argv[], int* arg, int* argc, aqua_frame_t* out, int* ival)
{
	struct {
		uint16_t unit;
		float value;
	}  limit;

	uint16_t u;
	float v;
	if (*arg <= (*argc - 2) &&
		sscanf_s(argv[*arg], "%i", &u) == 1 &&
		sscanf_s(argv[*arg + 1], "%f", &v) == 1) {

		limit.unit = u;
		limit.value = v;

		aquaparser_add_data(aquarius_alarm_keys[*ival].param_val, out, (uint8_t*)&limit, sizeof(limit));
		(*arg) += 2;
	}
	else
		aquaparser_add_data(aquarius_alarm_keys[*ival].param_val, out, (uint8_t*)NULL, 0);

}

void build_table_write_cmd(char* argv[], int* arg, int* argc, aqua_frame_t* out, uint8_t table[], int table_size)
{
	memset((void*)table, 0x0, sizeof(table_size));

	if ((*argc - *arg) < 6) {
		fprintf(stderr, "aquaconf - error AQUARIUS_KEY_TABLE_WRITE_CMD wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	int table_type;

	table[0] = find_table_index(argv[*arg + 1]); // table_id
	table[1] = atol(argv[*arg + 2]);	// start_row
	table[2] = atol(argv[*arg + 3]);	// start_col
	table[3] = atol(argv[*arg + 4]);	// end_row
	table[4] = atol(argv[*arg + 5]);	// end_col
	table[5] = (table_type = app_tables_element_size[find_table_index(argv[*arg + 1])]);

	uint8_t* p = &table[6];

	// If optional filename read in data
	{
		FILE* fp;
		int L, ret;
		// (Re - Rs + 1) * (Ce - Cs + 1) 
		L = (table[3] - table[1] + 1) * (table[4] - table[2] + 1);

		// Parse data from supplied file
		if ((fp = fopen(argv[*arg + 6], "rb")) != (FILE*)NULL)
		{

			int guard = L * 100;	// should be enough

			int i = 0;

			while (L && guard-- && p < &table[table_size - 1])
			{

				i++;

				switch (table_type) {

				case APP_TABLE_DATA_TYPE_UINT8: {
					if ((ret = fscanf_s(fp, "%u", (uint8_t*)p)) == 1) {
						p += sizeof(uint8_t);
						L--;
					}
				}
											  break;
				case APP_TABLE_DATA_TYPE_FLOAT32: {
					float x;
					if ((ret = fscanf_s(fp, "%f", &x)) == 1) {
						memcpy((void*)p, (void*)&x, sizeof(float));
						p += sizeof(float);
						L--;
					}
				}
												break;
				case APP_TABLE_DATA_TYPE_FLOAT64: {
					double x;
					if ((ret = fscanf_s(fp, "%lf", &x)) == 1) {
						memcpy((void*)p, (void*)&x, sizeof(double));
						p += sizeof(double);
						L--;
					}
				}
												break;
				case APP_TABLE_DATA_TYPE_UINT16: {
					uint16_t x;
					if ((ret = fscanf_s(fp, "%u", &x)) == 1) {
						memcpy((void*)p, (void*)&x, sizeof(uint16_t));
						p += sizeof(uint16_t);
						L--;
					}
				}
											   break;
				default:
					fprintf(stderr, "aquaconf - AQUARIUS_KEY_TABLE_WRITE_CMD unsupported table type\n");
					exit(EXIT_FAILURE);
				}

				// ',' or NA
				if (ret == 0) {

					if ((ret = fscanf_s(fp, ",")) == EOF)  break;
					if ((ret = fscanf_s(fp, "NA")) == EOF) break;

					continue;
				}

				if (ret < 0) {
					fprintf(stderr, "aquaconf - AQUARIUS_KEY_TABLE_WRITE_CMD parse failure on item %i\n", i);
					exit(EXIT_FAILURE);
				}
			}

			if (!(p < &table[table_size - 1])) {
				fprintf(stderr, "AQUARIUS_KEY_TABLE_WRITE_CMD - too much data according to parameters\n");
				exit(EXIT_FAILURE);
			}

			if (L) {
				fprintf(stderr, "aquaconf - AQUARIUS_KEY_TABLE_WRITE_CMD unable to parse all items expected\n");
				exit(EXIT_FAILURE);
			}
		}

		else {
			fprintf(stderr, "aquaconf - AQUARIUS_KEY_TABLE_WRITE_CMD can not open file %s\n", argv[*arg + 6]);
			exit(EXIT_FAILURE);
		}
	}

	aquaparser_add_data(AQUARIUS_KEY_TABLE_WRITE_CMD, out, (uint8_t*)table, p - table);

	(*arg) += 7;

}

void build_table_read_cmd(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{

	uint8_t tbl[5];
	if ((argc - arg) < 6)
	{
		fprintf(stderr, "aquaconf - error AQUARIUS_KEY_TABLE_READ_CMD wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	tbl[0] = find_table_index(argv[*arg + 1]);	// table_id
	tbl[1] = atol(argv[*arg + 2]);	// start_row
	tbl[2] = atol(argv[*arg + 3]);	// start_col
	tbl[3] = atol(argv[*arg + 4]);	// end_row
	tbl[4] = atol(argv[*arg + 5]);	// end_col	
	aquaparser_add_data(AQUARIUS_KEY_TABLE_READ_CMD, out, (uint8_t*)tbl, sizeof(tbl));
	(*arg) += 6;

}

void build_meter_attributes(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t value, key;

		if (*arg <= (*argc - 2) && sscanf_s(argv[*arg], "%u", &key) == 1 && sscanf_s(argv[*arg + 1], "%u", &value) == 1) {
			aquaparser_add_uint16(key, sub, (uint16_t)value);
			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_METER_ATTRIBUTES, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_METER_ATTRIBUTES, out, NULL, 0);

}

void build_flow_rate(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t  key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x08:
			case 0x09:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x03:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	// Use standard form?
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x04:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint32(key, sub, v.u32);
				break;

			case 0x05:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lu", &v.u64) == 1)))
					succ = aquaparser_add_uint64(key, sub, v.u64);
				break;

			case 0x06:
				succ = aquaparser_add_string(key, sub, (uint8_t*)argv[*arg + 1]);
				break;

			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_FLOW_RATE - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_FLOW_RATE - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_FLOW_RATE, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_FLOW_RATE, out, NULL, 0);

}

void build_zff(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
			case 0x0C:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x04:
			case 0x0D:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	// Use standard form?
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x05:
			case 0x0E:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint32(key, sub, v.u32);
				break;

			case 0x06:
			case 0x0F:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lu", &v.u64) == 1)))
					succ = aquaparser_add_uint64(key, sub, v.u64);
				break;

			case 0x07:
				succ = aquaparser_add_string(key, sub, (uint8_t*)argv[*arg + 1]);
				break;

			case 0x08:
			case 0x0A:
			case 0x0B:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_ZERO_FLOW_FILTER - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_ZERO_FLOW_FILTER - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_ZERO_FLOW_FILTER, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_ZERO_FLOW_FILTER, out, NULL, 0);

}

void build_average_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_AVERAGE_FILTER - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_AVERAGE_FILTER - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_AVERAGE_FILTER, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_AVERAGE_FILTER, out, NULL, 0);

}

void build_median_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_MEDIAN_FILTER - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_MEDIAN_FILTER - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_MEDIAN_FILTER, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_MEDIAN_FILTER, out, NULL, 0);

}

void build_adaptive_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
			case 0x04:
			case 0x05:
			case 0x06:
			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_ADAPTIVE_FILTER - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_ADAPTIVE_FILTER - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_ADAPTIVE_FILTER, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_ADAPTIVE_FILTER, out, NULL, 0);

}

void build_weighted_filter(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
			case 0x04:
			case 0x05:
			case 0x06:
			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_WEIGHTED_FILTER_CONFIGURATION - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_WEIGHTED_FILTER_CONFIGURATION - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_WEIGHTED_FILTER_CONFIGURATION, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_WEIGHTED_FILTER_CONFIGURATION, out, NULL, 0);

}

void build_MBUS_report(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	uint8_t subkey_array[20];				// Array of subkeys with an expected format of [ SK1 LEN1 SK2 LEN2... ] Size is defined to support up to 10 subkeys.
	uint8_t args_length = ((*argc - 2) * 2);	// Argument counter includes only the subkey and not the length, therefore, we need to multiply by two for convenience in implementation below.

	// Validate arguments don't exceed max length
	if (args_length > 20)
	{
		fprintf(stderr, "AQUARIUS_KEY_MBUS_REPORT - Too many subkeys, Supports a max of 10");
		exit(EXIT_FAILURE);
	}

	// Scan for inputs and add them to the array
	if (args_length > 0)
	{
		uint8_t j = 0;

		for (uint8_t i = 0; i < (*argc - 2); i++)
		{
			// Key is read-only. Insert subkey followed by 0x00 to follow read-only format.
			sscanf_s(argv[(*arg)++], "%x", &subkey_array[j]);
			subkey_array[j + 1] = 0;

			// Only add valid subkeys
			switch (subkey_array[j])
			{
			case 0x00:
			case 0x01:
			case 0x07:
			case 0x08:
			case 0x11:
			case 0x12:
			case 0x13:
			case 0x14:
			case 0x15:
			case 0x23:
				break;
			case 0x24:	/* Subkey Not Supported but defined by Wiki. Product response causes parsing failure. */
			default:
				fprintf(stderr, "AQUARIUS_KEY_MBUS_REPORT -  Unsupported subkey %d\n", subkey_array[j]);
				exit(EXIT_FAILURE);
			}

			j += 2;	// Move index to next subkey array element.
		}

		// Add data to Aquarius Packet
		aquaparser_add_data(AQUARIUS_KEY_MBUS_REPORT, out, (uint8_t*)&subkey_array[0], args_length);

	}
	else
	{
		// No subkeys were provided. Implementation TBD. An option could be to read all subkeys. For now, return a standard error.
		fprintf(stderr, "AQUARIUS_KEY_MBUS_REPORT -  No subkeys were provided\n");
		exit(EXIT_FAILURE);
	}

}

void build_MBUS_cfg(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{

	uint8_t subkey_array[20];				// Array of subkeys with an expected format of [ SK1 LEN1 SK2 LEN2... ] Size is defined to support up to 10 subkeys.
	uint8_t args_length = ((*argc - 2) * 2);	// Argument counter includes only the subkey and not the length, therefore, we need to multiply by two for convenience in implementation below.

	// Validate arguments don't exceed max length
	if (args_length > 20)
	{
		fprintf(stderr, "AQUARIUS_KEY_MBUS_CFG - Too many subkeys, Supports a max of 10");
		exit(EXIT_FAILURE);
	}

	// Scan for inputs and add them to the array
	if (args_length > 0)
	{
		uint8_t j = 0;

		for (uint8_t i = 0; i < (*argc - 2); i++)
		{
			// Key is read-only. Insert subkey followed by 0x00 to follow read-only format.
			sscanf_s(argv[(*arg)++], "%x", &subkey_array[j]);
			subkey_array[j + 1] = 0;

			// Only add valid subkeys
			switch (subkey_array[j])
			{
			case 0x00:
			case 0x01:
			case 0x02: //cannot be used with wired
			case 0x03:
			case 0x04:
			case 0x05:
			case 0x06:
			case 0x07:
			case 0x09: //cannot be used by a wireless product 
			case 0x22:
			case 0x23:
			case 0x27:
				break;
			default:
				fprintf(stderr, "AQUARIUS_KEY_MBUS_CFG -  Unsupported subkey %d\n", subkey_array[j]);
				exit(EXIT_FAILURE);
			}

			j += 2;	// Move index to next subkey array element.
		}

		// Add data to Aquarius Packet
		aquaparser_add_data(AQUARIUS_KEY_MBUS_CFG, out, (uint8_t*)&subkey_array[0], args_length);

	}
	else
	{
		// No subkeys were provided. Implementation TBD. An option could be to read all subkeys. For now, return a standard error.
		fprintf(stderr, "AQUARIUS_KEY_MBUS_CFG -  No subkeys were provided\n");
		exit(EXIT_FAILURE);
	}

}

void build_MBUS_ctl(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	uint8_t subkey_array[3];				// Array of subkeys with an expected format of [ SK1 LEN1 ] if 0x20 or 0x21 is used the pattern becomes [SK1 LEN1 0x00...]
	uint8_t args_length = ((*argc - 2) * 2);	// Argument counter includes only the subkey and not the length, therefore, we need to multiply by two for convenience in implementation below.

	// Validate arguments don't exceed max length -- only one subkey is responded to by MBUS_CTL (i.e. if subkey 21 and 8 are sent only a response to 8 is returned)
	if (args_length > 3)
	{
		fprintf(stderr, "AQUARIUS_KEY_MBUS_CTL - Too many subkeys, Supports a max of 1");
		exit(EXIT_FAILURE);
	}

	// Scan for inputs and add them to the array
	if (args_length > 0)
	{
		uint8_t j = 0;

		for (uint8_t i = 0; i < (*argc - 2); i++)
		{
			// 0x08 0x28 are read only and this functions like the other MBUS_ keys. If 0x20 or 0x21 is used the args length is increased by 1 to accommodate the dummy parameter
			sscanf_s(argv[(*arg)++], "%x", &subkey_array[j]);	//allows for the keys to be entered in hex for (instead of decimal)


			// Only add valid subkeys
			switch (subkey_array[j])
			{
			case 0x08:
			case 0x28:
				subkey_array[j + 1] = 0;  // make the next byte 0x00 for reading
				j += 2;
				break;
			case 0x20:
			case 0x21:
				subkey_array[j + 1] = 1;	// make next byte 0x01 so the dummy byte can be sent (this is the length of the dummy byte message) 
				subkey_array[j + 2] = 0;	// Use 0x00 as dummy byte to distinguish between a read and a write
				args_length++;			// The args_length has to get incremented by 1 to account for the dummy byte (it is not part of the command inputs and is not contained within (argc - 2) * 2 
				j += 3;					// Move the index to next subkey in input 
				break;
			default:
				fprintf(stderr, "AQUARIUS_KEY_MBUS_CTL -  Unsupported subkey %d\n", subkey_array[j]);
				exit(EXIT_FAILURE);
			}
		}

		// Add data to Aquarius Packet

		aquaparser_add_data(AQUARIUS_KEY_MBUS_CTL, out, (uint8_t*)&subkey_array[0], args_length);

	}
	else
	{
		// No subkeys were provided. Implementation TBD. An option could be to read all subkeys. For now, return a standard error.
		fprintf(stderr, "AQUARIUS_KEY_MBUS_CTL -  No subkeys were provided\n");
		exit(EXIT_FAILURE);
	}

}

void build_rff(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x04:
			case 0x0D:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	// Use standard form?
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x08:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			case 0x0A:
			case 0x0B:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint32(key, sub, v.u32);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_REVERSE_FLOW_FILTER - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_REVERSE_FLOW_FILTER - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else {
			break;
		}
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_REVERSE_FLOW_FILTER, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_REVERSE_FLOW_FILTER, out, NULL, 0);

}

void build_temperature(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {

			case 0x01:
			case 0x08:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x02:
			case 0x09:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x03:
			case 0x0a:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	// Use standard form?
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x04:
			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_TEMPERATURE - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_TEMPERATURE - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_TEMPERATURE, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_TEMPERATURE, out, NULL, 0);

}

void build_pressure(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {

			case 0x01:
			case 0x08:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x02:
			case 0x09:
			case 0x0C:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x03:
			case 0x0a:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	// Use standard form?
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x04:
			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_PRESSURE - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_PRESSURE - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_PRESSURE, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_PRESSURE, out, NULL, 0);


}

void build_3wire_config(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
			case 0x04:
			case 0x05:
			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint32(key, sub, v.u32);
				break;

			case 0x06:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_3WIRE_CONFIGURATION - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_3WIRE_CONFIGURATION - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_3WIRE_CONFIGURATION, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_3WIRE_CONFIGURATION, out, NULL, 0);

}

void build_alarm_driver_config(char* argv[], int* arg, int* argc, aqua_frame_t* sub, aqua_frame_t* out, bool driver_status)
{
	int c;
	while (*arg <= (*argc - 1)) {

		// Alarm key found
		if ((c = find_param_key(argv[*arg], param_alarm_list, sizeof(param_alarm_list) / sizeof(param_t))) != -1) {

			aquaparser_add_uint8(0x01, sub, param_alarm_list[c].param_val);
			(*arg)++;

			// Search for key/value pair
		}
		else {

			uint32_t key, value;

			if (*arg <= (*argc - 2) &&
				sscanf_s(argv[*arg], "%u", &key) == 1 && sscanf_s(argv[*arg + 1], "%u", &value) == 1) {

				// Hack for Configuration and State
				if (key == 2)
					aquaparser_add_uint8(key, sub, (uint8_t)value);
				else if (driver_status && key == 3)
					aquaparser_add_uint8(key, sub, (uint8_t)value);
				else
					aquaparser_add_uint32(key, sub, value);

				(*arg) += 2;

				// Could be end of Driver status config - break out
			}
			else
				break;
		}
	}

	if (sub->len > 4)
		aquaparser_add_data(driver_status ? AQUARIUS_KEY_ALARM_DRIVER_STATUS : AQUARIUS_KEY_ALARM_DRIVER_CONFIGURATION, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(driver_status ? AQUARIUS_KEY_ALARM_DRIVER_STATUS : AQUARIUS_KEY_ALARM_DRIVER_CONFIGURATION, out, NULL, 0);
}

void build_ASIC_status(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub, uint32_t* u32)
{
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	if (*arg <= (*argc - 1) && sscanf_s(argv[*arg], "%i", u32) == 1) {
		aquaparser_add_uint32(0xFF, sub, *u32);
		(*arg)++;
	}
	else
		aquaparser_add_data(0xFF, sub, NULL, 0);

	aquaparser_add_data(AQUARIUS_KEY_REGISTER_ACCESS, out, sub->data.buf + 4, sub->len - 4);
}

void build_meter_read_interval(char* argv[], int* arg, int* argc, uint32_t* u32, aqua_frame_t* out)
{
	if (*arg <= (*argc - 1) && sscanf_s(argv[*arg], "%u", u32) == 1)
	{
		aquaparser_add_uint32(AQUARIUS_KEY_METER_SAMPLING_PERIOD, out, *u32);
		(*arg)++;
	}
	else
		aquaparser_add_data(AQUARIUS_KEY_METER_SAMPLING_PERIOD, out, NULL, 0);

}

void build_polar_process_variables(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {

			case 0x02:
			case 0x03:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u8);
				break;

			case 0x04:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;
			case 0x05:
			case 0x06:
			case 0x07:
			case 0x08:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u32);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_POLAR_PROCESS_VARIABLES - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_POLAR_PROCESS_VARIABLES - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_POLAR_PROCESS_VARIABLES, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_POLAR_PROCESS_VARIABLES, out, NULL, 0);

}

void build_bootloader_fw_version(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct _boot_version
	{
		uint8_t major;
		uint8_t minor;
		uint16_t rev;
	}  v;

	uint8_t ma;
	uint8_t mi;
	uint16_t r;

	if (*arg <= (*argc - 1) && sscanf_s(argv[*arg], "v%u.%u.%u\n", &ma, &mi, &r) == 3)
	{
		v.major = ma;
		v.minor = mi;
		v.rev = r;
		aquaparser_add_data(AQUARIUS_KEY_BOOTLOADER_FIRMWARE_VERSION, out, (uint8_t*)&v, sizeof(v));
		(*arg)++;
	}
	else
		aquaparser_add_data(AQUARIUS_KEY_BOOTLOADER_FIRMWARE_VERSION, out, NULL, 0);
}

void build_hardware_version(char* argv[], int* arg, int* argc, aqua_frame_t* out)
{
	struct _hw_version
	{
		uint32_t base;
		uint16_t dash;
		uint16_t rev;
	} hw;

	uint32_t b;
	uint16_t d;
	uint16_t r;

	if (*arg <= (*argc - 1) && sscanf_s(argv[*arg], "v%u.%u.%u\n", &b, &d, &r) == 3)
	{
		hw.base = b;
		hw.dash = d;
		hw.rev = r;
		aquaparser_add_data(AQUARIUS_KEY_HARDWARE_VERSION, out, (uint8_t*)&hw, sizeof(hw));
		(*arg)++;
	}
	else
		aquaparser_add_data(AQUARIUS_KEY_HARDWARE_VERSION, out, NULL, 0);
}

void build_flow_totalizer(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t  key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x08:
			case 0x09:
			case 0x0B:
			case 0x0C:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x03:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	// Use standard form?
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x04:
			case 0x0A:
			case 0x0D:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint32(key, sub, v.u32);
				break;

			case 0x05:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lu", &v.u64) == 1)))
					succ = aquaparser_add_uint64(key, sub, v.u64);
				break;

			case 0x06:
				succ = aquaparser_add_string(key, sub, (uint8_t*)argv[*arg + 1]);
				break;

			case 0x07:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_FLOW_TOTALIZER - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_FLOW_TOTALIZER - error parsing %i\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_FLOW_TOTALIZER, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_FLOW_TOTALIZER, out, (uint8_t*)NULL, 0);
}

void build_digital_output(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{

	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x01:
			case 0x02:
				if ((succ = (sscanf_s(argv[*arg + 1], "%d", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
			case 0x04:
			case 0x05:
			case 0x06:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x07:
			case 0x08:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lu", &v.u64) == 1)))
					succ = aquaparser_add_uint64(key, sub, v.u64);
				break;

			case 0x09:
				if ((succ = (sscanf_s(argv[*arg + 1], "%lf", &v.d) == 1)))	
					succ = aquaparser_add_double(key, sub, v.d);
				break;

			case 0x0A:
				if ((succ = (sscanf_s(argv[*arg + 1], "%u", &v.u32) == 1)))
					succ = aquaparser_add_uint32(key, sub, v.u32);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_DIGITAL_OUTPUT - wrong subkey %i\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_DIGITAL_OUTPUT - error parsing %s\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_DIGITAL_OUTPUT, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_DIGITAL_OUTPUT, out, NULL, 0);

}

void build_flow_simulation(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	// 8-bit subkey frame
	aquaparser_init(sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

	while (*arg <= (*argc - 1)) {

		uint16_t key;

		union {
			uint8_t  u8;
			uint16_t u16;
			uint32_t u32;
			uint64_t u64;
			float    f;
			double   d;
		} v;

		bool succ;

		if (*arg <= (*argc - 2) && (sscanf_s(argv[*arg], "%u", &key) == 1)) {

			switch (key) {
			case 0x02:
			case 0x06:
				if ((succ = (sscanf_s(argv[*arg + 1], "%d", &v.u8) == 1)))
					succ = aquaparser_add_uint8(key, sub, v.u8);
				break;

			case 0x03:
			case 0x04:
			case 0x05:
			case 0x0B:
				if ((succ = (sscanf_s(argv[*arg + 1], "%f", &v.f) == 1)))
					succ = aquaparser_add_float(key, sub, v.f);
				break;

			case 0x07:
			case 0x08:
			case 0x09:
			case 0x0A:
				if ((succ = (sscanf_s(argv[*arg + 1], "%d", &v.u16) == 1)))
					succ = aquaparser_add_uint16(key, sub, v.u16);
				break;

			default:
				fprintf(stderr, "AQUARIUS_KEY_FLOW_SIMULATION - wrong subkey %d\n", key);
				exit(EXIT_FAILURE);
			}

			if (!succ) {
				fprintf(stderr, "AQUARIUS_KEY_FLOW_SIMULATION - error parsing %s\n", argv[*arg + 1]);
				exit(EXIT_FAILURE);
			}

			(*arg) += 2;
		}
		else
			break;
	}

	if (sub->len > 4)
		aquaparser_add_data(AQUARIUS_KEY_FLOW_SIMULATION, out, sub->data.buf + 4, sub->len - 4);
	else
		aquaparser_add_data(AQUARIUS_KEY_FLOW_SIMULATION, out, NULL, 0);
}

void build_param(char* argv[], int* arg, int* argc, aqua_frame_t* out, aqua_frame_t* sub)
{
	int j, ival;
	double dval;
	bool high_flow = false;
	bool low_flow = false;
	for (; *arg < *argc; (*arg)++)
	{
		// Switch to high|low flow profile
		if (!strcmp("HIGH_FLOW", argv[*arg]))
		{
			low_flow = !(high_flow = true);
			continue;
		}

		if (!strcmp("LOW_FLOW", argv[*arg]))
		{
			high_flow = !(low_flow = true);
			continue;
		}

		if (low_flow || high_flow)
		{
			if (low_flow && (j = find_param(argv[*arg], param_low_flow_list, sizeof(param_low_flow_list) / sizeof(param_t))) == -1)
				goto aquabomb;

			if (high_flow && (j = find_param(argv[*arg], param_high_flow_list, sizeof(param_high_flow_list) / sizeof(param_t))) == -1)
				goto aquabomb;

			// Adjust param_index to flow profile assume either low flow or high flow profile
			int adjusted = low_flow ? j + ASIC_PARAM_LOW_FLOW : j + ASIC_PARAM_HIGH_FLOW;

			param_t* l = low_flow ? param_low_flow_list : param_high_flow_list;

			// next argument is a numeric value
			if ((*arg + 1) < *argc && sscanf(argv[*arg + 1], "%i", &ival) == 1)
			{
				if (!aquaparser_add_uint32(adjusted, sub, l[j].param_val | ival << 16))
				{
					fprintf(stderr, "aquaconf - aquaparser_add_uint32 failed on '%s'\n", argv[j]);
					exit(EXIT_FAILURE);
				}
			}
			else
				aquaparser_add_data(adjusted, sub, NULL, 0);
			(*arg)++;

		}
		else if ((j = find_param(argv[*arg], param_ul_list, sizeof(param_ul_list) / sizeof(param_t))) != -1)
		{

			// Next argument is not a key and is parsed as a valid integer
			if (*arg < (*argc - 1) && find_param(argv[*arg + 1], param_ul_list, sizeof(param_ul_list) / sizeof(param_t)) == -1)
			{
				if ((ival = parse_mode_string(argv[*arg + 1])) != -1)
				{
				}
				else if (sscanf(argv[*arg + 1], "%i", &ival) != 1)
				{
					fprintf(stderr, "aquaconf - value '%s' does not look like a valid argument\n", argv[*arg + 1]);
					exit(EXIT_FAILURE);
				}

				if (param_ul_list[j].param_val)
				{
					if (!aquaparser_add_uint32(j, sub, param_ul_list[j].param_val | ival << 16))
					{
						fprintf(stderr, "aquaconf - aquaparser_add_uint32 failed on '%s'\n", argv[j]);
						exit(EXIT_FAILURE);
					}
				}
				else
				{

					if (j == _LOW_FLOW_THRESHOLD || j == _HIGH_FLOW_THRESHOLD)
					{
						if (sscanf(argv[*arg + 1], "%lf", &dval) != 1)
						{
							fprintf(stderr, "aquaconf - value '%s' does not look like a valid argument\n", argv[*arg + 1]);
							exit(EXIT_FAILURE);
						}
						if (!aquaparser_add_double(j, sub, dval))
						{
							fprintf(stderr, "aquaconf - aquaparser_add_double failed on '%s'\n", argv[j]);
							exit(EXIT_FAILURE);
						}
					}
					else if (!aquaparser_add_uint16(j, sub, ival))
					{
						fprintf(stderr, "aquaconf - aquaparser_add_uint16 failed on '%s'\n", argv[j]);
						exit(EXIT_FAILURE);
					}
				}
				(*arg)++;
			}
			else
				aquaparser_add_data(j, sub, NULL, 0);
		}
		else
		{
			fprintf(stderr, "aquaconf %i - value '%d' does not look like a valid argument\n", __LINE__, j);
		aquabomb:

			fprintf(stderr, "aquaconf %i - value '%s' does not look like a valid argument\n", __LINE__, argv[*arg]);
			exit(EXIT_FAILURE);
		}
	}
}

int main(int argc, char* argv[])
{
	aqua_frame_t frame, out, sub;

	memset((void*)&frame, 0, sizeof(frame));

	if (argc >= 2)
	{
		uint8_t data[250];


		int arg, carg, ival;

		uint32_t u32;
		uint16_t u16;
		double dval;
		float  fval;

		//bool force = false;

		uint8_t table[6 + sizeof(double) * 666];

		arg = 1;


		memset(data, 0, sizeof(data));

		aquaparser_init(&out, true, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

		if (!strcmp(argv[1], "-q"))
		{
			Aquarius_Parameter_t param;

			param.key = atoi(argv[2]);

			// optional value argument	
			if (argc > 3)
			{
				int c = parse_hex_string(argv[3], data);

				if (c > 0)
				{
					aquaparser_add_data(param.key, &out, data, c);
				}

				else
				{

					aquaparser_add_uint32(param.key, &out, atol(argv[3]));
				}
			}
			else
			{
				aquaparser_add_data(param.key, &out, NULL, 0);
			}


		}
		else
		{

		}

		for (; arg <= (argc - 1); carg = arg)
		{
			if (!strcmp(argv[arg], "ENABLE_CLK_OUT"))
			{
				build_enable_clk_out(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "FORCE_RESET"))
			{
				build_force_reset(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "ERASE_NVM"))
			{
				build_erase_nvm(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "MID_LOCK_UNLOCK"))
			{
				build_MID_lock_unlock(&arg, &argc, &out); // Not tested
				continue;
			}

			if (!strcmp(argv[arg], "ASIC_START_PTRIG_SWEEP"))
			{
				build_start_ptrig_sweep(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "CLEAR_TOTALIZER"))
			{
				build_clear_totalizer(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "SET_CORE_REGULATION"))
			{
				build_set_core_regulation(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "ASIC_START_STG2_SWEEP"))
			{
				build_start_stg2_sweep(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "CLEAR_ALARMS"))
			{
				build_clear_alarms(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "CLEAR_DIAGNOSTIC_CNTRS"))
			{
				build_clear_diag_cntrs(&arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "SET_PROFILE_COMPRESSION"))
			{
				build_set_profile_compression(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "AMBIENT_LIGHT_DETECTION")) {
				build_ALD(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "DIGITAL_OUTPUT_3_LOOPBACK"))
			{
				build_digital_output_3_loopback(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "IR_PULSE_OUTPUT"))
			{
				build_IR_pulse_out(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "MEASUREMENTS_COMMAND") || !strcmp(argv[arg], "AQUARIUS_KEY_POLAR_MEASUREMENT_COMMAND"))
			{
				build_measurements_command(argv, &arg, &argc, &out);
				continue;
			}


			if (!strcmp(argv[arg], "AQUARIUS_KEY_TABLE_ACTIVE_COORDINATES"))
			{
				build_table_active_corordinates(argv, &arg, &argc, &out);
				continue;
			}

			if ((ival = find_param_key(argv[arg], param_mechanical_list, sizeof(param_mechanical_list) / sizeof(param_t))) != -1)
			{
				build_mechanical_list(argv, &arg, &argc, &out, table, sizeof(table) / sizeof(table[0]), &ival);
				continue;
			}

			if ((ival = find_param_key(argv[arg], aquarius_alarm_keys, sizeof(aquarius_alarm_keys) / sizeof(param_t))) != -1 && arg++)
			{
				build_alarm_keys(argv, &arg, &argc, &out, &ival);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_TABLE_WRITE_CMD"))
			{
				build_table_write_cmd(argv, &arg, &argc, &out, table, sizeof(table) / sizeof(table[0]));
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_TABLE_READ_CMD"))
			{
				build_table_read_cmd(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_METER_ATTRIBUTES") && arg++)
			{
				build_meter_attributes(argv, &arg, &argc, &out, &sub);  // Not Tested
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_FLOW_RATE") && arg++)
			{
				build_flow_rate(argv, &arg, &argc, &out, &sub);
				continue;
			}

			// AQUARIUS_KEY_ZERO_FLOW_FILTER_CONFIGURATION was added because in polar gen 2 AQUARIUS_KEY_ZERO_FLOW_FILTER references the same key (0x0065) 
			// as AQUARIUS_KEY_ZERO_FLOW_FILTER_CONFIGURATION does in polar integral (0x0065)
			// This does mean that the key AQUARIUS_KEY_ZERO_FLOW_FILTER (0x003D) can not be used on its own for polar integral currently
			// HOWEVER - AQUARIUS_KEY_ZERO_FLOW_FILTER_CONFIGURATION 0x0065 provides the same information as 0x003D, and adds 
			// process variable selection, enable, and reserved sub-keys information
			if ((!strcmp(argv[arg], "AQUARIUS_KEY_ZERO_FLOW_FILTER") || !strcmp(argv[arg], "AQUARIUS_KEY_ZERO_FLOW_FILTER_CONFIGURATION")) && arg++)
			{
				build_zff(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_AVERAGE_FILTER") && arg++)
			{
				build_average_filter(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MEDIAN_FILTER") && arg++)
			{
				build_median_filter(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_ADAPTIVE_FILTER") && arg++)
			{
				build_adaptive_filter(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if ((!strcmp(argv[arg], "AQUARIUS_KEY_LAMBDA_FILTER") || !strcmp(argv[arg], "AQUARIUS_KEY_WEIGHTED_FILTER_CONFIGURATION")) && arg++)
			{
				build_weighted_filter(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MBUS_REPORT") && arg++)
			{
				build_MBUS_report(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MBUS_CFG") && arg++)
			{
				build_MBUS_cfg(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MBUS_CTL") && arg++)
			{
				build_MBUS_ctl(argv, &arg, &argc, &out);
				continue;
			}

			if ((!strcmp(argv[arg], "AQUARIUS_KEY_REVERSE_FLOW_FILTER") || !strcmp(argv[arg], "AQUARIUS_KEY_REVERSE_FLOW_FILTER_TOTALIZING_FILTER")) && arg++)
			{
				build_rff(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_TEMPERATURE") && arg++)
			{
				build_temperature(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_PRESSURE") && arg++)
			{
				build_pressure(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_3WIRE_CONFIGURATION") && arg++)
			{
				build_3wire_config(argv, &arg, &argc, &out, &sub);
				continue;
			}

			bool driver_status;
			if (((driver_status = !strcmp(argv[arg], "AQUARIUS_KEY_ALARM_DRIVER_STATUS")) || !strcmp(argv[arg], "AQUARIUS_KEY_ALARM_DRIVER_CONFIGURATION")) && arg++)
			{
				// 8-bit subkey frame
				aquaparser_init(&sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);
				build_alarm_driver_config(argv, &arg, &argc, &sub, &out, driver_status);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_UNIQUE_ID") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_UNIQUE_ID, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_TABLE_PROPERTIES") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_TABLE_PROPERTIES, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_CONFIGURATION_LOG_READ") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_CONFIGURATION_LOG_READ, &out, NULL, 0);
				continue;
			}

			if ((!strcmp(argv[arg], "AQUARIUS_KEY_REGISTER_ACCESS") || !strcmp(argv[arg], "AQUARIUS_KEY_REGISTER_ACCESS_8BIT")) && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_REGISTER_ACCESS, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_ASIC_STATUS") && arg++)
			{
				build_ASIC_status(argv, &arg, &argc, &out, &sub, &u32);
				continue;
			}

			if ((!strcmp(argv[arg], "ETERNAL_SLEEP_ASIC") || !strcmp(argv[arg], "AQUARIUS_KEY_ETERNAL_SLEEP_ASIC")) && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_ETERNAL_SLEEP_ASIC, &out, NULL, 0);
				continue;
			}

			if ((!strcmp(argv[arg], "OPERATING_MODE") || !strcmp(argv[arg], "AQUARIUS_KEY_OPERATING_MODE")) && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%i", &u16) == 1)
				{
					aquaparser_add_uint16(AQUARIUS_KEY_OPERATING_MODE, &out, u16);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_OPERATING_MODE, &out, NULL, 0);

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_SECURED_PARENT_KEYS") && arg++) {
				uint8_t parent[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

				aquaparser_add_data(AQUARIUS_KEY_SECURED_PARENT_KEYS, &out, parent, sizeof(parent));

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_SECURED_TABLES") && arg++)
			{
				uint8_t unlock[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
									0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

				aquaparser_add_data(AQUARIUS_KEY_SECURED_TABLES, &out, unlock, sizeof(unlock));

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_METER_SAMPLING_PERIOD") && arg++)
			{
				build_meter_read_interval(argv, &arg, &argc, &u32, &out);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_METER_READ_INTERVAL") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_uint32(AQUARIUS_KEY_METER_READ_INTERVAL, &out, u32);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_METER_READ_INTERVAL, &out, NULL, 0);

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_CALENDAR_TIME") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_uint32(AQUARIUS_KEY_CALENDAR_TIME, &out, u32);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_CALENDAR_TIME, &out, NULL, 0);

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_ERASE_ALL_DATA_POINTS_COMMAND") && arg++) {
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_uint32(AQUARIUS_KEY_ERASE_ALL_DATA_POINTS_COMMAND, &out, u32);
					arg++;
				}
				else
				{
					fprintf(stderr, "aquaconf AQUARIUS_KEY_ERASE_ALL_DATA_POINTS_COMMAND <int-passcode>\n");
					exit(EXIT_FAILURE);
				}
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DATA_POINT_REQUEST") && arg++) {

				struct {
					uint32_t _new;
					uint32_t _old;
				}  dt;

				if (arg <= (argc - 2) && sscanf(argv[arg], "%lu", &dt._new) == 1 && sscanf(argv[arg + 1], "%lu", &dt._old) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_DATA_POINT_REQUEST, &out, (uint8_t*)&dt, sizeof(dt));
					arg += 2;
					continue;
				}
				else
				{
					fprintf(stderr, "aquaconf AQUARIUS_KEY_DATA_POINT_REQUEST <int> <int>\n");
					exit(EXIT_FAILURE);
				}
			}

			if ((!strcmp(argv[arg], "ANALOG_OUTPUT_DAC_VALUE") || !strcmp(argv[arg], "AQUARIUS_KEY_ANALOG_OUT_DAC_VALUE")) && arg++) {
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_ANALOG_OUT_DAC_VALUE, &out, (uint8_t*)&u16, sizeof(u16));

					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_ANALOG_OUT_DAC_VALUE, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DISPLAY_CUSTOM_TEST_PATTERN") && arg++) {
				int c;
				uint8_t data[512];
				if (arg <= (argc - 1) && (c = parse_hex_string(argv[arg], data)))
				{
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_CUSTOM_TEST_PATTERN, &out, data, c);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_CUSTOM_TEST_PATTERN, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DISPLAY_CONTRAST") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_CONTRAST, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_CONTRAST, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_END_OF_LIFE_COUNTER") && arg++) {
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_END_OF_LIFE_COUNTER, &out, (uint8_t*)&u32, sizeof(u32));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_END_OF_LIFE_COUNTER, &out, NULL, 0);
				continue;
			}

			if ((!strcmp(argv[arg], "DISPLAY_TEST_PATTERN") || !strcmp(argv[arg], "AQUARIUS_KEY_DISPLAY_TEST_PATTERN")) && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%i", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_TEST_PATTERN, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_TEST_PATTERN, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_POLAR_FUNCTIONAL_TYPE") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%i", &ival) == 1)
				{
					aquaparser_add_uint16(AQUARIUS_KEY_POLAR_FUNCTIONAL_TYPE, &out, ival);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_POLAR_FUNCTIONAL_TYPE, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_FIRMWARE_VERSION") && arg++)
			{
				tFirmwareVersion v;
				if (arg <= (argc - 1) && sscanf(argv[arg], "v%i.%i.%i\n", &v.fw_major, &v.fw_minor, &v.fw_revision) == 3)
				{
					aquaparser_add_data(AQUARIUS_KEY_FIRMWARE_VERSION, &out, (uint8_t*)&v, sizeof(tFirmwareVersion));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_FIRMWARE_VERSION, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_FIRMWARE_VERSION_STRING") && arg++)
			{

				// Next argument is not a key , not a value or aquarius command - then it must be a plain string.
				if (arg <= (argc - 1) && parse_nominal_string(argv[arg]))
				{
					aquaparser_add_string(AQUARIUS_KEY_FIRMWARE_VERSION_STRING, &out, (uint8_t*)argv[arg]);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_FIRMWARE_VERSION_STRING, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DEVICE_ID") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_uint32(AQUARIUS_KEY_DEVICE_ID, &out, u32);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_DEVICE_ID, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DEVICE_SOFT_RESET") && arg++) {
				aquaparser_add_data(AQUARIUS_KEY_DEVICE_SOFT_RESET, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DEVICE_ID_STRING") && arg++) {

				// Next argument is not a key , not a value or aquarius command - then it must be a plain string.
				if (arg <= (argc - 1) && parse_nominal_string(argv[arg])) {

					aquaparser_add_string(AQUARIUS_KEY_DEVICE_ID_STRING, &out, (uint8_t*)argv[arg]);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_DEVICE_ID_STRING, &out, NULL, 0);

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_METER_ID_PRIMARY") && arg++) {

				// Next argument is not a key , not a value or aquarius command - then it must be a plain string.
				if (arg <= (argc - 1) && parse_nominal_string(argv[arg])) {

					aquaparser_add_string(AQUARIUS_KEY_METER_ID_PRIMARY, &out, (uint8_t*)argv[arg]);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_METER_ID_PRIMARY, &out, NULL, 0);

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_METER_ID_SECONDARY") && arg++) {

				// Next argument is not a key , not a value or aquarius command - then it must be a plain string.
				if (arg <= (argc - 1) && parse_nominal_string(argv[arg])) {

					aquaparser_add_string(AQUARIUS_KEY_METER_ID_SECONDARY, &out, (uint8_t*)argv[arg]);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_METER_ID_SECONDARY, &out, NULL, 0);

				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_PRODUCT_ID") && arg++) {
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1) {
					aquaparser_add_data(AQUARIUS_KEY_PRODUCT_ID, &out, (uint8_t*)&u32, sizeof(u32));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_PRODUCT_ID, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_POLAR_MCU_AC_THRESHOLD") && arg++) {
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1) {
					aquaparser_add_data(AQUARIUS_KEY_POLAR_MCU_AC_THRESHOLD, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_POLAR_MCU_AC_THRESHOLD, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_POLAR_PROCESS_VARIABLES") && arg++)
			{
				build_polar_process_variables(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_BOOTLOADER_FIRMWARE_VERSION") && arg++)
			{
				build_bootloader_fw_version(argv, &arg, &argc, &out);
				continue;
			}


			if (!strcmp(argv[arg], "AQUARIUS_KEY_HARDWARE_VERSION") && arg++)
			{
				build_hardware_version(argv, &arg, &argc, &out);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_HARDWARE_VERSION_STRING") && arg++) {

				// Next argument is not a key , not a value or aquarius command - then it must be a plain string.
				if (arg <= (argc - 1) && parse_nominal_string(argv[arg]))
				{
					aquaparser_add_string(AQUARIUS_KEY_HARDWARE_VERSION_STRING, &out, (uint8_t*)argv[arg]);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_HARDWARE_VERSION_STRING, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DEVICE_MEMORY_READ_COMMAND") && arg++)
			{
				struct {
					uint32_t addr;
					uint16_t len;
				}  m;

				if (arg <= (argc - 2) && sscanf(argv[arg], "%x", &m.addr) == 1 && sscanf(argv[arg + 1], "%hu", &m.len) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_DEVICE_MEMORY_READ_COMMAND, &out, (uint8_t*)&m, sizeof(m));
					arg += 2;
					continue;
				}
				else
				{
					fprintf(stderr, "aquaconf - AQUARIUS_KEY_DEVICE_MEMORY_READ_COMMAND <addr> <len>\n");
					exit(EXIT_FAILURE);
				}
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_LOW_FLOW_CUTOFF_F64") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%lf", &dval) == 1)
				{
					aquaparser_add_double(AQUARIUS_KEY_LOW_FLOW_CUTOFF_F64, &out, dval);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_LOW_FLOW_CUTOFF_F64, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_FLOW_RATE_MAXIMUM_F32") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%f", &fval) == 1)
				{
					aquaparser_add_float(AQUARIUS_KEY_FLOW_RATE_MAXIMUM_F32, &out, fval);
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_FLOW_RATE_MAXIMUM_F32, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_ANALOG_OUTPUT_MAXIMUM_F32") && arg++)
			{
				struct analog_output_max {
					uint16_t 	channel_id;
					float 		output_scaling;
				}  analog_output_max;

				if (arg <= (argc - 1 - 1) && sscanf(argv[arg], "%i", &ival) == 1 && sscanf(argv[arg + 1], "%lf", &dval) == 1)
				{
					analog_output_max.channel_id = ival;
					analog_output_max.output_scaling = dval;

					aquaparser_add_data(AQUARIUS_KEY_ANALOG_OUTPUT_MAXIMUM_F32, &out, (uint8_t*)&analog_output_max, sizeof(analog_output_max));
					arg += 2;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_ANALOG_OUTPUT_MAXIMUM_F32, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_FLOW_TOTALIZER") && arg++)
			{
				build_flow_totalizer(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DIGITAL_OUTPUT") && arg++)
			{
				build_digital_output(argv, &arg, &argc, &out, &sub);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_DISPLAY_ACTIVE_ALARM_ICONS") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_ACTIVE_ALARM_ICONS, &out, (uint8_t*)&u32, sizeof(u32));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_DISPLAY_ACTIVE_ALARM_ICONS, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_ANALOG_OUTPUT") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_ANALOG_OUTPUT, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_ANALOG_OUTPUT, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_RADIO_MODE") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_RADIO_MODE, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_RADIO_MODE, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_RADIO_PROTOCOL") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_RADIO_PROTOCOL, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_RADIO_PROTOCOL, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_RADIO_BAND") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_RADIO_BAND, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_RADIO_BAND, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_RADIO_FREQUENCY") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_RADIO_FREQUENCY, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_RADIO_FREQUENCY, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_RADIO_MOBILE_INTERVAL") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_RADIO_MOBILE_INTERVAL, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_RADIO_MOBILE_INTERVAL, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_XCVR_IDENTIFY") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_XCVR_IDENTIFY, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_XCVR_IDENTIFY, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_EXTERNAL_MEMORY_IDENTIFY") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_EXTERNAL_MEMORY_IDENTIFY, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_EXTERNAL_MEMORY_IDENTIFY, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_POWER_STATUS") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					if (u16 == 1 || u16 == 0)
					{
						aquaparser_add_data(AQUARIUS_KEY_NETWORK_POWER_STATUS, &out, (uint8_t*)&u16, sizeof(u16));
						arg++;
					}
					else
					{
						fprintf(stderr, "AQUARIUS_KEY_NETWORK_POWER_STATUS - invalid input : %i -- only 1 or 0 is valid \n", u16);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_POWER_STATUS, &out, NULL, 0);
				}
				continue;

			}

	

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_UPDATE_PARAMS") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					if (u16 == 1 || u16 == 0)
					{
						aquaparser_add_data(AQUARIUS_KEY_MODEM_UPDATE_PARAMS, &out, (uint8_t*)&u16, sizeof(u16));
						arg++;
					}
					else
					{
						fprintf(stderr, "AQUARIUS_KEY_MODEM_UPDATE_PARAMS - invalid input : %i -- only 1 or 0 is valid \n", u16);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					fprintf(stderr, "AQUARIUS_KEY_MODEM_UPDATE_PARAMS - input needed \n", u16);
					exit(EXIT_FAILURE);
				}
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_IMEI") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_IMEI, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_MANUFACTURER") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_MANUFACTURER, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_MODEL") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_MODEL, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_SOFTWARE_VERSION") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_SOFTWARE_VERSION, &out,NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_SIM_ICCID") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_SIM_ICCID, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_NETWORK_TIME") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_NETWORK_TIME, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_CELL_NETWORK_MONITOR") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_CELL_NETWORK_MONITOR, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_TEMPERATURE") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_TEMPERATURE, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_BATTERY_STATUS") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_BATTERY_STATUS, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_OPERATOR_SELECTION") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_OPERATOR_SELECTION, &out,NULL, 0);
				continue;
			}



			if (!strcmp(argv[arg], "AQUARIUS_KEY_MODEM_SERIAL_NUMBER") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_MODEM_SERIAL_NUMBER, &out,NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_HOST_IP_ADDRESS") && arg++)
			{
				// Variable to hold the input string
				char host_ip[255];

				if (arg <= (argc - 1) && sscanf(argv[arg], "%s", host_ip) == 1)
				{
					uint8_t length = strlen(host_ip);
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_HOST_IP_ADDRESS, &out, (uint8_t*)host_ip, length);
					arg++;
					continue;
				}
				else
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_HOST_IP_ADDRESS, &out,NULL, 0);
					continue;
				}
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_HOST_IP_PORT_NUMBER") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_HOST_IP_PORT_NUMBER, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_HOST_IP_PORT_NUMBER, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_COMMUNICATION_SCHEDULE") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMMUNICATION_SCHEDULE, &out, (uint8_t*)&u32, sizeof(u32));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMMUNICATION_SCHEDULE, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_COMMUNICATION_INTERVAL") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMMUNICATION_INTERVAL, &out, (uint8_t*)&u32, sizeof(u32));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMMUNICATION_INTERVAL, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_REGISTRATION_TIMEOUT") && arg++)
			{
				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_REGISTRATION_TIMEOUT, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_REGISTRATION_TIMEOUT, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_REGISTRATION_DELAY") && arg++)
			{

				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u16) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_REGISTRATION_DELAY, &out, (uint8_t*)&u16, sizeof(u16));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_REGISTRATION_DELAY, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_SIGNAL_STRENGTH") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_NETWORK_SIGNAL_STRENGTH, &out,NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_COMM_NEXT_SCHED_TIME") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMM_NEXT_SCHED_TIME, &out, NULL, 0);
				continue;
			}

			

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_COMM_RETRY_INTERVAL") && arg++) {

				if (arg <= (argc - 1) && sscanf(argv[arg], "%u", &u32) == 1)
				{
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMM_RETRY_INTERVAL, &out, (uint8_t*)&u32, sizeof(u32));
					arg++;
				}
				else
					aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMM_RETRY_INTERVAL, &out, NULL, 0);
				continue;

			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_COMM_STATUS") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMM_STATUS, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_REGISTRATION_DURATION") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_NETWORK_REGISTRATION_DURATION, &out, NULL, 0);
				continue;
			}

			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_CARRIER_INFORMATION") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_NETWORK_CARRIER_INFORMATION, &out, NULL, 0);
				continue;
			}


			if (!strcmp(argv[arg], "AQUARIUS_KEY_NETWORK_COMM_NEXT_SCHED_ATTEMPT") && arg++)
			{
				aquaparser_add_data(AQUARIUS_KEY_NETWORK_COMM_NEXT_SCHED_ATTEMPT, &out, NULL, 0);
				continue;
			}

			
			if (!strcmp(argv[arg], "AQUARIUS_KEY_FLOW_SIMULATION") && arg++)
			{
				build_flow_simulation(argv, &arg, &argc, &out, &sub);
				continue;
			}

			aquaparser_init(&sub, false, ENCODER_AQUARIUS_FOOTER_TYPE_CRC16);

			if (out.len == 4)
			{
				build_param(argv, &arg, &argc, &out, &sub);
			}
			if (sub.len > 4)
				aquaparser_add_data(AQUARIUS_KEY_REGISTER_ACCESS, &out, sub.data.buf + 4, sub.len - 4);

			if (carg == arg)
			{
				fprintf(stderr, "aquaconf - unknown argument %s\n", argv[arg]);
				exit(EXIT_FAILURE);
			}
		}

		if (out.len == 4)
		{
			fprintf(stderr, "aquaconf - empty aquarius packet - key not found?\n");
			return 1;
		}


	}
	else
	{

	}
}