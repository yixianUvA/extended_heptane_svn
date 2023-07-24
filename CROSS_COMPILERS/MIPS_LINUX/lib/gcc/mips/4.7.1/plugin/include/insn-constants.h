/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define CCDSP_OU_REGNUM 185
#define RETURN_ADDR_REGNUM 31
#define GOT_VERSION_REGNUM 79
#define MAX_PIC_BRANCH_LENGTH 100
#define CCDSP_SC_REGNUM 183
#define CCDSP_EF_REGNUM 187
#define CCDSP_CC_REGNUM 186
#define CPRESTORE_SLOT_REGNUM 76
#define PIC_FUNCTION_ADDR_REGNUM 25
#define CCDSP_CA_REGNUM 184
#define CCDSP_PO_REGNUM 182
#define TLS_GET_TP_REGNUM 3

enum unspec {
  UNSPEC_LOAD_LEFT = 0,
  UNSPEC_LOAD_RIGHT = 1,
  UNSPEC_STORE_LEFT = 2,
  UNSPEC_STORE_RIGHT = 3,
  UNSPEC_LOAD_LOW = 4,
  UNSPEC_LOAD_HIGH = 5,
  UNSPEC_STORE_WORD = 6,
  UNSPEC_MFHC1 = 7,
  UNSPEC_MTHC1 = 8,
  UNSPEC_MFHI = 9,
  UNSPEC_MTHI = 10,
  UNSPEC_SET_HILO = 11,
  UNSPEC_LOADGP = 12,
  UNSPEC_COPYGP = 13,
  UNSPEC_MOVE_GP = 14,
  UNSPEC_POTENTIAL_CPRESTORE = 15,
  UNSPEC_CPRESTORE = 16,
  UNSPEC_RESTORE_GP = 17,
  UNSPEC_EH_RETURN = 18,
  UNSPEC_GP = 19,
  UNSPEC_SET_GOT_VERSION = 20,
  UNSPEC_UPDATE_GOT_VERSION = 21,
  UNSPEC_LOAD_CALL = 22,
  UNSPEC_LOAD_GOT = 23,
  UNSPEC_TLS_LDM = 24,
  UNSPEC_TLS_GET_TP = 25,
  UNSPEC_UNSHIFTED_HIGH = 26,
  UNSPEC_ALIGN = 27,
  UNSPEC_CONSTTABLE_INT = 28,
  UNSPEC_CONSTTABLE_FLOAT = 29,
  UNSPEC_BLOCKAGE = 30,
  UNSPEC_CLEAR_HAZARD = 31,
  UNSPEC_RDHWR = 32,
  UNSPEC_SYNCI = 33,
  UNSPEC_SYNC = 34,
  UNSPEC_MIPS_CACHE = 35,
  UNSPEC_R10K_CACHE_BARRIER = 36,
  UNSPEC_ERET = 37,
  UNSPEC_DERET = 38,
  UNSPEC_DI = 39,
  UNSPEC_EHB = 40,
  UNSPEC_RDPGPR = 41,
  UNSPEC_COP0 = 42,
  UNSPEC_CALL_ATTR = 43,
  UNSPEC_LOONGSON_ALU1_TURN_ENABLED_INSN = 44,
  UNSPEC_LOONGSON_ALU2_TURN_ENABLED_INSN = 45,
  UNSPEC_LOONGSON_FALU1_TURN_ENABLED_INSN = 46,
  UNSPEC_LOONGSON_FALU2_TURN_ENABLED_INSN = 47,
  UNSPEC_COMPARE_AND_SWAP = 48,
  UNSPEC_COMPARE_AND_SWAP_12 = 49,
  UNSPEC_SYNC_OLD_OP = 50,
  UNSPEC_SYNC_NEW_OP = 51,
  UNSPEC_SYNC_NEW_OP_12 = 52,
  UNSPEC_SYNC_OLD_OP_12 = 53,
  UNSPEC_SYNC_EXCHANGE = 54,
  UNSPEC_SYNC_EXCHANGE_12 = 55,
  UNSPEC_MEMORY_BARRIER = 56,
  UNSPEC_MOVE_TF_PS = 57,
  UNSPEC_C = 58,
  UNSPEC_ALNV_PS = 59,
  UNSPEC_CABS = 60,
  UNSPEC_ADDR_PS = 61,
  UNSPEC_CVT_PW_PS = 62,
  UNSPEC_CVT_PS_PW = 63,
  UNSPEC_MULR_PS = 64,
  UNSPEC_ABS_PS = 65,
  UNSPEC_RSQRT1 = 66,
  UNSPEC_RSQRT2 = 67,
  UNSPEC_RECIP1 = 68,
  UNSPEC_RECIP2 = 69,
  UNSPEC_SINGLE_CC = 70,
  UNSPEC_SCC = 71,
  UNSPEC_ADDQ = 72,
  UNSPEC_ADDQ_S = 73,
  UNSPEC_SUBQ = 74,
  UNSPEC_SUBQ_S = 75,
  UNSPEC_ADDSC = 76,
  UNSPEC_ADDWC = 77,
  UNSPEC_MODSUB = 78,
  UNSPEC_RADDU_W_QB = 79,
  UNSPEC_ABSQ_S = 80,
  UNSPEC_PRECRQ_QB_PH = 81,
  UNSPEC_PRECRQ_PH_W = 82,
  UNSPEC_PRECRQ_RS_PH_W = 83,
  UNSPEC_PRECRQU_S_QB_PH = 84,
  UNSPEC_PRECEQ_W_PHL = 85,
  UNSPEC_PRECEQ_W_PHR = 86,
  UNSPEC_PRECEQU_PH_QBL = 87,
  UNSPEC_PRECEQU_PH_QBR = 88,
  UNSPEC_PRECEQU_PH_QBLA = 89,
  UNSPEC_PRECEQU_PH_QBRA = 90,
  UNSPEC_PRECEU_PH_QBL = 91,
  UNSPEC_PRECEU_PH_QBR = 92,
  UNSPEC_PRECEU_PH_QBLA = 93,
  UNSPEC_PRECEU_PH_QBRA = 94,
  UNSPEC_SHLL = 95,
  UNSPEC_SHLL_S = 96,
  UNSPEC_SHRL_QB = 97,
  UNSPEC_SHRA_PH = 98,
  UNSPEC_SHRA_R = 99,
  UNSPEC_MULEU_S_PH_QBL = 100,
  UNSPEC_MULEU_S_PH_QBR = 101,
  UNSPEC_MULQ_RS_PH = 102,
  UNSPEC_MULEQ_S_W_PHL = 103,
  UNSPEC_MULEQ_S_W_PHR = 104,
  UNSPEC_DPAU_H_QBL = 105,
  UNSPEC_DPAU_H_QBR = 106,
  UNSPEC_DPSU_H_QBL = 107,
  UNSPEC_DPSU_H_QBR = 108,
  UNSPEC_DPAQ_S_W_PH = 109,
  UNSPEC_DPSQ_S_W_PH = 110,
  UNSPEC_MULSAQ_S_W_PH = 111,
  UNSPEC_DPAQ_SA_L_W = 112,
  UNSPEC_DPSQ_SA_L_W = 113,
  UNSPEC_MAQ_S_W_PHL = 114,
  UNSPEC_MAQ_S_W_PHR = 115,
  UNSPEC_MAQ_SA_W_PHL = 116,
  UNSPEC_MAQ_SA_W_PHR = 117,
  UNSPEC_BITREV = 118,
  UNSPEC_INSV = 119,
  UNSPEC_REPL_QB = 120,
  UNSPEC_REPL_PH = 121,
  UNSPEC_CMP_EQ = 122,
  UNSPEC_CMP_LT = 123,
  UNSPEC_CMP_LE = 124,
  UNSPEC_CMPGU_EQ_QB = 125,
  UNSPEC_CMPGU_LT_QB = 126,
  UNSPEC_CMPGU_LE_QB = 127,
  UNSPEC_PICK = 128,
  UNSPEC_PACKRL_PH = 129,
  UNSPEC_EXTR_W = 130,
  UNSPEC_EXTR_R_W = 131,
  UNSPEC_EXTR_RS_W = 132,
  UNSPEC_EXTR_S_H = 133,
  UNSPEC_EXTP = 134,
  UNSPEC_EXTPDP = 135,
  UNSPEC_SHILO = 136,
  UNSPEC_MTHLIP = 137,
  UNSPEC_WRDSP = 138,
  UNSPEC_RDDSP = 139,
  UNSPEC_ABSQ_S_QB = 140,
  UNSPEC_ADDU_PH = 141,
  UNSPEC_ADDU_S_PH = 142,
  UNSPEC_ADDUH_QB = 143,
  UNSPEC_ADDUH_R_QB = 144,
  UNSPEC_APPEND = 145,
  UNSPEC_BALIGN = 146,
  UNSPEC_CMPGDU_EQ_QB = 147,
  UNSPEC_CMPGDU_LT_QB = 148,
  UNSPEC_CMPGDU_LE_QB = 149,
  UNSPEC_DPA_W_PH = 150,
  UNSPEC_DPS_W_PH = 151,
  UNSPEC_MADD = 152,
  UNSPEC_MADDU = 153,
  UNSPEC_MSUB = 154,
  UNSPEC_MSUBU = 155,
  UNSPEC_MUL_PH = 156,
  UNSPEC_MUL_S_PH = 157,
  UNSPEC_MULQ_RS_W = 158,
  UNSPEC_MULQ_S_PH = 159,
  UNSPEC_MULQ_S_W = 160,
  UNSPEC_MULSA_W_PH = 161,
  UNSPEC_MULT = 162,
  UNSPEC_MULTU = 163,
  UNSPEC_PRECR_QB_PH = 164,
  UNSPEC_PRECR_SRA_PH_W = 165,
  UNSPEC_PRECR_SRA_R_PH_W = 166,
  UNSPEC_PREPEND = 167,
  UNSPEC_SHRA_QB = 168,
  UNSPEC_SHRA_R_QB = 169,
  UNSPEC_SHRL_PH = 170,
  UNSPEC_SUBU_PH = 171,
  UNSPEC_SUBU_S_PH = 172,
  UNSPEC_SUBUH_QB = 173,
  UNSPEC_SUBUH_R_QB = 174,
  UNSPEC_ADDQH_PH = 175,
  UNSPEC_ADDQH_R_PH = 176,
  UNSPEC_ADDQH_W = 177,
  UNSPEC_ADDQH_R_W = 178,
  UNSPEC_SUBQH_PH = 179,
  UNSPEC_SUBQH_R_PH = 180,
  UNSPEC_SUBQH_W = 181,
  UNSPEC_SUBQH_R_W = 182,
  UNSPEC_DPAX_W_PH = 183,
  UNSPEC_DPSX_W_PH = 184,
  UNSPEC_DPAQX_S_W_PH = 185,
  UNSPEC_DPAQX_SA_W_PH = 186,
  UNSPEC_DPSQX_S_W_PH = 187,
  UNSPEC_DPSQX_SA_W_PH = 188,
  UNSPEC_LOONGSON_PAVG = 189,
  UNSPEC_LOONGSON_PCMPEQ = 190,
  UNSPEC_LOONGSON_PCMPGT = 191,
  UNSPEC_LOONGSON_PEXTR = 192,
  UNSPEC_LOONGSON_PINSRH = 193,
  UNSPEC_LOONGSON_VINIT = 194,
  UNSPEC_LOONGSON_PMADD = 195,
  UNSPEC_LOONGSON_PMOVMSK = 196,
  UNSPEC_LOONGSON_PMULHU = 197,
  UNSPEC_LOONGSON_PMULH = 198,
  UNSPEC_LOONGSON_PMULU = 199,
  UNSPEC_LOONGSON_PASUBUB = 200,
  UNSPEC_LOONGSON_BIADD = 201,
  UNSPEC_LOONGSON_PSADBH = 202,
  UNSPEC_LOONGSON_PSHUFH = 203,
  UNSPEC_LOONGSON_PUNPCKH = 204,
  UNSPEC_LOONGSON_PUNPCKL = 205,
  UNSPEC_LOONGSON_PADDD = 206,
  UNSPEC_LOONGSON_PSUBD = 207,
  UNSPEC_LOONGSON_DSLL = 208,
  UNSPEC_LOONGSON_DSRL = 209,
  UNSPEC_ADDRESS_FIRST = 210
};
#define NUM_UNSPEC_VALUES 211
extern const char *const unspec_strings[];

enum processor {
  PROCESSOR_R3000 = 0,
  PROCESSOR_4KC = 1,
  PROCESSOR_4KP = 2,
  PROCESSOR_5KC = 3,
  PROCESSOR_5KF = 4,
  PROCESSOR_20KC = 5,
  PROCESSOR_24KC = 6,
  PROCESSOR_24KF2_1 = 7,
  PROCESSOR_24KF1_1 = 8,
  PROCESSOR_74KC = 9,
  PROCESSOR_74KF2_1 = 10,
  PROCESSOR_74KF1_1 = 11,
  PROCESSOR_74KF3_2 = 12,
  PROCESSOR_LOONGSON_2E = 13,
  PROCESSOR_LOONGSON_2F = 14,
  PROCESSOR_LOONGSON_3A = 15,
  PROCESSOR_M4K = 16,
  PROCESSOR_OCTEON = 17,
  PROCESSOR_OCTEON2 = 18,
  PROCESSOR_R3900 = 19,
  PROCESSOR_R6000 = 20,
  PROCESSOR_R4000 = 21,
  PROCESSOR_R4100 = 22,
  PROCESSOR_R4111 = 23,
  PROCESSOR_R4120 = 24,
  PROCESSOR_R4130 = 25,
  PROCESSOR_R4300 = 26,
  PROCESSOR_R4600 = 27,
  PROCESSOR_R4650 = 28,
  PROCESSOR_R5000 = 29,
  PROCESSOR_R5400 = 30,
  PROCESSOR_R5500 = 31,
  PROCESSOR_R7000 = 32,
  PROCESSOR_R8000 = 33,
  PROCESSOR_R9000 = 34,
  PROCESSOR_R10000 = 35,
  PROCESSOR_SB1 = 36,
  PROCESSOR_SB1A = 37,
  PROCESSOR_SR71000 = 38,
  PROCESSOR_XLR = 39
};
#define NUM_PROCESSOR_VALUES 40
extern const char *const processor_strings[];

#endif /* GCC_INSN_CONSTANTS_H */