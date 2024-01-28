// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (C) 2020 Felix Fietkau <nbd@nbd.name> */

#ifndef __MTK_WED_REGS_H
#define __MTK_WED_REGS_H

#define MTK_WFDMA_DESC_CTRL_TO_HOST		BIT(8)
#define MTK_WDMA_DESC_CTRL_LEN1			GENMASK(14, 0)
#define MTK_WDMA_DESC_CTRL_LEN1_V2		GENMASK(13, 0)
#define MTK_WDMA_DESC_CTRL_LAST_SEG1		BIT(15)
#define MTK_WDMA_DESC_CTRL_BURST		BIT(16)
#define MTK_WDMA_DESC_CTRL_LEN0			GENMASK(29, 16)
#define MTK_WDMA_DESC_CTRL_LAST_SEG0		BIT(30)
#define MTK_WDMA_DESC_CTRL_DMA_DONE		BIT(31)

#define MTK_WDMA_TXD0_DESC_INFO_DMA_DONE	BIT(29)
#define MTK_WDMA_TXD1_DESC_INFO_DMA_DONE	BIT(31)

struct mtk_wdma_desc {
	__le32 buf0;
	__le32 ctrl;
	__le32 buf1;
	__le32 info;
} __packed __aligned(4);

#define MTK_WED_REV_ID					0x004

#define MTK_WED_RESET					0x008
#define MTK_WED_RESET_TX_BM				BIT(0)
#define MTK_WED_RESET_RX_BM				BIT(1)
#define MTK_WED_RESET_RX_PG_BM				BIT(2)
#define MTK_WED_RESET_RRO_RX_TO_PG			BIT(3)
#define MTK_WED_RESET_TX_FREE_AGENT			BIT(4)
#define MTK_WED_RESET_WPDMA_TX_DRV			BIT(8)
#define MTK_WED_RESET_WPDMA_RX_DRV			BIT(9)
#define MTK_WED_RESET_WPDMA_RX_D_DRV			BIT(10)
#define MTK_WED_RESET_WPDMA_INT_AGENT			BIT(11)
#define MTK_WED_RESET_WED_TX_DMA			BIT(12)
#define MTK_WED_RESET_WED_RX_DMA			BIT(13)
#define MTK_WED_RESET_WDMA_TX_DRV			BIT(16)
#define MTK_WED_RESET_WDMA_RX_DRV			BIT(17)
#define MTK_WED_RESET_WDMA_INT_AGENT			BIT(19)
#define MTK_WED_RESET_RX_RRO_QM				BIT(20)
#define MTK_WED_RESET_RX_ROUTE_QM			BIT(21)
#define MTK_WED_RESET_TX_AMSDU				BIT(22)
#define MTK_WED_RESET_WED				BIT(31)

#define MTK_WED_CTRL					0x00c
#define MTK_WED_CTRL_WPDMA_INT_AGENT_EN			BIT(0)
#define MTK_WED_CTRL_WPDMA_INT_AGENT_BUSY		BIT(1)
#define MTK_WED_CTRL_WDMA_INT_AGENT_EN			BIT(2)
#define MTK_WED_CTRL_WDMA_INT_AGENT_BUSY		BIT(3)
#define MTK_WED_CTRL_WED_RX_IND_CMD_EN			BIT(5)
#define MTK_WED_CTRL_WED_RX_PG_BM_EN			BIT(6)
#define MTK_WED_CTRL_WED_RX_PG_BM_BUSY			BIT(7)
#define MTK_WED_CTRL_WED_TX_BM_EN			BIT(8)
#define MTK_WED_CTRL_WED_TX_BM_BUSY			BIT(9)
#define MTK_WED_CTRL_WED_TX_FREE_AGENT_EN		BIT(10)
#define MTK_WED_CTRL_WED_TX_FREE_AGENT_BUSY		BIT(11)
#define MTK_WED_CTRL_WED_RX_BM_EN			BIT(12)
#define MTK_WED_CTRL_WED_RX_BM_BUSY			BIT(13)
#define MTK_WED_CTRL_RX_RRO_QM_EN			BIT(14)
#define MTK_WED_CTRL_RX_RRO_QM_BUSY			BIT(15)
#define MTK_WED_CTRL_RX_ROUTE_QM_EN			BIT(16)
#define MTK_WED_CTRL_RX_ROUTE_QM_BUSY			BIT(17)
#define MTK_WED_CTRL_TX_TKID_ALI_EN			BIT(20)
#define MTK_WED_CTRL_TX_TKID_ALI_BUSY			BIT(21)
#define MTK_WED_CTRL_TX_AMSDU_EN			BIT(22)
#define MTK_WED_CTRL_TX_AMSDU_BUSY			BIT(23)
#define MTK_WED_CTRL_FINAL_DIDX_READ			BIT(24)
#define MTK_WED_CTRL_ETH_DMAD_FMT			BIT(25)
#define MTK_WED_CTRL_MIB_READ_CLEAR			BIT(28)
#define MTK_WED_CTRL_FLD_MIB_RD_CLR			BIT(28)

#define MTK_WED_EXT_INT_STATUS				0x020
#define MTK_WED_EXT_INT_STATUS_TF_LEN_ERR		BIT(0)
#define MTK_WED_EXT_INT_STATUS_TKID_WO_PYLD		BIT(1)
#define MTK_WED_EXT_INT_STATUS_TKID_TITO_INVALID	BIT(4)
#define MTK_WED_EXT_INT_STATUS_TX_FBUF_LO_TH		BIT(8)
#define MTK_WED_EXT_INT_STATUS_TX_FBUF_HI_TH		BIT(9)
#define MTK_WED_EXT_INT_STATUS_RX_FBUF_LO_TH		BIT(10) /* wed v2 */
#define MTK_WED_EXT_INT_STATUS_RX_FBUF_HI_TH		BIT(11) /* wed v2 */
#define MTK_WED_EXT_INT_STATUS_RX_DRV_R_RESP_ERR	BIT(16)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_W_RESP_ERR	BIT(17)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_COHERENT		BIT(18)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_INIT_WDMA_EN	BIT(19)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_BM_DMAD_COHERENT	BIT(20)
#define MTK_WED_EXT_INT_STATUS_TX_DRV_R_RESP_ERR	BIT(21)
#define MTK_WED_EXT_INT_STATUS_TX_DMA_R_RESP_ERR	BIT(22)
#define MTK_WED_EXT_INT_STATUS_TX_DMA_W_RESP_ERR	BIT(23)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_DMA_RECYCLE	BIT(24)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_GET_BM_DMAD_SKIP	BIT(25)
#define MTK_WED_EXT_INT_STATUS_WPDMA_RX_D_DRV_ERR	BIT(26)
#define MTK_WED_EXT_INT_STATUS_WPDMA_MID_RDY		BIT(27)
#define MTK_WED_EXT_INT_STATUS_ERROR_MASK		(MTK_WED_EXT_INT_STATUS_TF_LEN_ERR | \
							 MTK_WED_EXT_INT_STATUS_TKID_WO_PYLD | \
							 MTK_WED_EXT_INT_STATUS_TKID_TITO_INVALID | \
							 MTK_WED_EXT_INT_STATUS_RX_DRV_R_RESP_ERR | \
							 MTK_WED_EXT_INT_STATUS_RX_DRV_W_RESP_ERR | \
							 MTK_WED_EXT_INT_STATUS_RX_DRV_INIT_WDMA_EN | \
							 MTK_WED_EXT_INT_STATUS_TX_DMA_R_RESP_ERR)

#define MTK_WED_EXT_INT_MASK				0x028
#define MTK_WED_EXT_INT_MASK1				0x02c
#define MTK_WED_EXT_INT_MASK2				0x030
#define MTK_WED_EXT_INT_MASK3				0x034

#define MTK_WED_STATUS					0x060
#define MTK_WED_STATUS_TX				GENMASK(15, 8)

#define MTK_WED_WPDMA_STATUS				0x068
#define MTK_WED_WPDMA_STATUS_TX_DRV			GENMASK(15, 8)

#define MTK_WED_TX_BM_CTRL				0x080
#define MTK_WED_TX_BM_CTRL_VLD_GRP_NUM			GENMASK(6, 0)
#define MTK_WED_TX_BM_CTRL_RSV_GRP_NUM			GENMASK(22, 16)
#define MTK_WED_TX_BM_CTRL_LEGACY_EN			BIT(26)
#define MTK_WED_TX_TKID_CTRL_FREE_FORMAT		BIT(27)
#define MTK_WED_TX_BM_CTRL_PAUSE			BIT(28)

#define MTK_WED_TX_BM_BASE				0x084
#define MTK_WED_TX_BM_INIT_PTR				0x088
#define MTK_WED_TX_BM_SW_TAIL_IDX			GENMASK(16, 0)
#define MTK_WED_TX_BM_INIT_SW_TAIL_IDX			BIT(16)

#define MTK_WED_TX_BM_TKID_START			GENMASK(15, 0)
#define MTK_WED_TX_BM_TKID_END				GENMASK(31, 16)

#define MTK_WED_TX_BM_BUF_LEN				0x08c

#define MTK_WED_TX_BM_INTF				0x09c
#define MTK_WED_TX_BM_INTF_TKID				GENMASK(15, 0)
#define MTK_WED_TX_BM_INTF_TKFIFO_FDEP			GENMASK(23, 16)
#define MTK_WED_TX_BM_INTF_TKID_VALID			BIT(28)
#define MTK_WED_TX_BM_INTF_TKID_READ			BIT(29)

#define MTK_WED_TX_BM_DYN_THR				0x0a0
#define MTK_WED_TX_BM_DYN_THR_LO			GENMASK(6, 0)
#define MTK_WED_TX_BM_DYN_THR_LO_V2			GENMASK(8, 0)
#define MTK_WED_TX_BM_DYN_THR_HI			GENMASK(22, 16)
#define MTK_WED_TX_BM_DYN_THR_HI_V2			GENMASK(24, 16)

#define MTK_WED_TX_TKID_CTRL				0x0c0
#define MTK_WED_TX_TKID_CTRL_VLD_GRP_NUM		GENMASK(6, 0)
#define MTK_WED_TX_TKID_CTRL_RSV_GRP_NUM		GENMASK(22, 16)
#define MTK_WED_TX_TKID_CTRL_PAUSE			BIT(28)

#define MTK_WED_TX_TKID_INTF				0x0dc
#define MTK_WED_TX_TKID_INTF_TKFIFO_FDEP		GENMASK(25, 16)

#define MTK_WED_TX_TKID_CTRL_VLD_GRP_NUM_V3		GENMASK(7, 0)
#define MTK_WED_TX_TKID_CTRL_RSV_GRP_NUM_V3		GENMASK(23, 16)

#define MTK_WED_TX_TKID_DYN_THR				0x0e0
#define MTK_WED_TX_TKID_DYN_THR_LO			GENMASK(6, 0)
#define MTK_WED_TX_TKID_DYN_THR_HI			GENMASK(22, 16)

#define MTK_WED_TXP_DW0					0x120
#define MTK_WED_TXP_DW1					0x124
#define MTK_WED_WPDMA_WRITE_TXP				GENMASK(31, 16)
#define MTK_WED_TXDP_CTRL				0x130
#define MTK_WED_TXDP_DW9_OVERWR				BIT(9)
#define MTK_WED_RX_BM_TKID_MIB				0x1cc

#define MTK_WED_INT_STATUS				0x200
#define MTK_WED_INT_MASK				0x204

#define MTK_WED_GLO_CFG					0x208
#define MTK_WED_GLO_CFG_TX_DMA_EN			BIT(0)
#define MTK_WED_GLO_CFG_TX_DMA_BUSY			BIT(1)
#define MTK_WED_GLO_CFG_RX_DMA_EN			BIT(2)
#define MTK_WED_GLO_CFG_RX_DMA_BUSY			BIT(3)
#define MTK_WED_GLO_CFG_RX_BT_SIZE			GENMASK(5, 4)
#define MTK_WED_GLO_CFG_TX_WB_DDONE			BIT(6)
#define MTK_WED_GLO_CFG_BIG_ENDIAN			BIT(7)
#define MTK_WED_GLO_CFG_DIS_BT_SIZE_ALIGN		BIT(8)
#define MTK_WED_GLO_CFG_TX_BT_SIZE_LO			BIT(9)
#define MTK_WED_GLO_CFG_MULTI_DMA_EN			GENMASK(11, 10)
#define MTK_WED_GLO_CFG_FIFO_LITTLE_ENDIAN		BIT(12)
#define MTK_WED_GLO_CFG_MI_DEPTH_RD			GENMASK(21, 13)
#define MTK_WED_GLO_CFG_TX_BT_SIZE_HI			GENMASK(23, 22)
#define MTK_WED_GLO_CFG_SW_RESET			BIT(24)
#define MTK_WED_GLO_CFG_FIRST_TOKEN_ONLY		BIT(26)
#define MTK_WED_GLO_CFG_OMIT_RX_INFO			BIT(27)
#define MTK_WED_GLO_CFG_OMIT_TX_INFO			BIT(28)
#define MTK_WED_GLO_CFG_BYTE_SWAP			BIT(29)
#define MTK_WED_GLO_CFG_RX_2B_OFFSET			BIT(31)

#define MTK_WED_RESET_IDX				0x20c
#define MTK_WED_RESET_WPDMA_IDX_RX			GENMASK(31, 30)

#define MTK_WED_TX_MIB(_n)				(0x2a0 + (_n) * 4)
#define MTK_WED_RX_MIB(_n)				(0x2e0 + (_n) * 4)

#define MTK_WED_RING_TX(_n)				(0x300 + (_n) * 0x10)

#define MTK_WED_RING_RX(_n)				(0x400 + (_n) * 0x10)
#define MTK_WED_RING_RX_DATA(_n)			(0x420 + (_n) * 0x10)

#define MTK_WED_SCR0					0x3c0
#define MTK_WED_RX1_CTRL2				0x418
#define MTK_WED_WPDMA_INT_TRIGGER			0x504
#define MTK_WED_WPDMA_INT_TRIGGER_RX_DONE		BIT(1)
#define MTK_WED_WPDMA_INT_TRIGGER_TX_DONE		GENMASK(5, 4)

#define MTK_WED_WPDMA_GLO_CFG				0x508
#define MTK_WED_WPDMA_GLO_CFG_TX_DRV_EN			BIT(0)
#define MTK_WED_WPDMA_GLO_CFG_TX_DRV_BUSY		BIT(1)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_EN			BIT(2)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_BUSY		BIT(3)
#define MTK_WED_WPDMA_GLO_CFG_RX_BT_SIZE		GENMASK(5, 4)
#define MTK_WED_WPDMA_GLO_CFG_TX_WB_DDONE		BIT(6)
#define MTK_WED_WPDMA_GLO_CFG_BIG_ENDIAN		BIT(7)
#define MTK_WED_WPDMA_GLO_CFG_DIS_BT_SIZE_ALIGN		BIT(8)
#define MTK_WED_WPDMA_GLO_CFG_TX_BT_SIZE_LO		BIT(9)
#define MTK_WED_WPDMA_GLO_CFG_MULTI_DMA_EN		GENMASK(11, 10)
#define MTK_WED_WPDMA_GLO_CFG_FIFO_LITTLE_ENDIAN	BIT(12)
#define MTK_WED_WPDMA_GLO_CFG_MI_DEPTH_RD		GENMASK(21, 13)
#define MTK_WED_WPDMA_GLO_CFG_TX_BT_SIZE_HI		GENMASK(23, 22)
#define MTK_WED_WPDMA_GLO_CFG_SW_RESET			BIT(24)
#define MTK_WED_WPDMA_GLO_CFG_FIRST_TOKEN_ONLY		BIT(26)
#define MTK_WED_WPDMA_GLO_CFG_OMIT_RX_INFO		BIT(27)
#define MTK_WED_WPDMA_GLO_CFG_OMIT_TX_INFO		BIT(28)
#define MTK_WED_WPDMA_GLO_CFG_BYTE_SWAP			BIT(29)
#define MTK_WED_WPDMA_GLO_CFG_RX_2B_OFFSET		BIT(31)

/* CONFIG_MEDIATEK_NETSYS_V2 */
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_R0_PKT_PROC	BIT(4)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_R1_PKT_PROC	BIT(5)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_R0_CRX_SYNC	BIT(6)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_R1_CRX_SYNC	BIT(7)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_EVENT_PKT_FMT_VER	GENMASK(15, 12)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_UNS_VER_FORCE_4	BIT(18)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_UNSUPPORT_FMT	BIT(19)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_EVENT_PKT_FMT_CHK	BIT(20)
#define MTK_WED_WPDMA_GLO_CFG_RX_DDONE2_WR		BIT(21)
#define MTK_WED_WPDMA_GLO_CFG_TX_TKID_KEEP		BIT(24)
#define MTK_WED_WPDMA_GLO_CFG_TX_DDONE_CHK_LAST		BIT(25)
#define MTK_WED_WPDMA_GLO_CFG_TX_DMAD_DW3_PREV		BIT(28)
#define MTK_WED_WPDMA_GLO_CFG_TX_DDONE_CHK		BIT(30)

#define MTK_WED_WPDMA_RESET_IDX				0x50c
#define MTK_WED_WPDMA_RESET_IDX_TX			GENMASK(3, 0)
#define MTK_WED_WPDMA_RESET_IDX_RX			GENMASK(17, 16)

#define MTK_WED_WPDMA_CTRL				0x518
#define MTK_WED_WPDMA_CTRL_SDL1_FIXED			BIT(31)

#define MTK_WED_WPDMA_INT_CTRL				0x520
#define MTK_WED_WPDMA_INT_CTRL_SUBRT_ADV		BIT(21)
#define MTK_WED_WPDMA_INT_CTRL_SIG_SRC			BIT(22)
#define MTK_WED_WPDMA_INT_CTRL_SRC_SEL			GENMASK(17, 16)

#define MTK_WED_WPDMA_INT_MASK				0x524

#define MTK_WED_WPDMA_INT_CTRL_TX			0x530
#define MTK_WED_WPDMA_INT_CTRL_TX0_DONE_EN		BIT(0)
#define MTK_WED_WPDMA_INT_CTRL_TX0_DONE_CLR		BIT(1)
#define MTK_WED_WPDMA_INT_CTRL_TX0_DONE_TRIG		GENMASK(6, 2)
#define MTK_WED_WPDMA_INT_CTRL_TX1_DONE_EN		BIT(8)
#define MTK_WED_WPDMA_INT_CTRL_TX1_DONE_CLR		BIT(9)
#define MTK_WED_WPDMA_INT_CTRL_TX1_DONE_TRIG		GENMASK(14, 10)

#define MTK_WED_WPDMA_INT_CTRL_RX			0x534
#define MTK_WED_WPDMA_INT_CTRL_RX0_EN			BIT(0)
#define MTK_WED_WPDMA_INT_CTRL_RX0_CLR			BIT(1)
#define MTK_WED_WPDMA_INT_CTRL_RX0_DONE_TRIG		GENMASK(6, 2)
#define MTK_WED_WPDMA_INT_CTRL_RX1_EN			BIT(8)
#define MTK_WED_WPDMA_INT_CTRL_RX1_CLR			BIT(9)
#define MTK_WED_WPDMA_INT_CTRL_RX1_DONE_TRIG		GENMASK(14, 10)

#define MTK_WED_WPDMA_INT_CTRL_TX_FREE			0x538
#define MTK_WED_WPDMA_INT_CTRL_TX_FREE_DONE_EN		BIT(0)
#define MTK_WED_WPDMA_INT_CTRL_TX_FREE_DONE_CLR		BIT(1)
#define MTK_WED_WPDMA_INT_CTRL_TX_FREE_DONE_TRIG	GENMASK(6, 2)

#define MTK_WED_PCIE_CFG_BASE				0x560

#define MTK_WED_PCIE_CFG_BASE				0x560
#define MTK_WED_PCIE_CFG_INTM				0x564
#define MTK_WED_PCIE_CFG_MSIS				0x568
#define MTK_WED_PCIE_INT_TRIGGER			0x570
#define MTK_WED_PCIE_INT_TRIGGER_STATUS			BIT(16)

#define MTK_WED_PCIE_INT_CTRL				0x57c
#define MTK_WED_PCIE_INT_CTRL_POLL_EN			GENMASK(13, 12)
#define MTK_WED_PCIE_INT_CTRL_SRC_SEL			GENMASK(17, 16)
#define MTK_WED_PCIE_INT_CTRL_MSK_EN_POLA		BIT(20)
#define MTK_WED_PCIE_INT_CTRL_MSK_IRQ_FILTER		BIT(21)

#define MTK_WED_WPDMA_CFG_BASE				0x580
#define MTK_WED_WPDMA_CFG_INT_MASK			0x584
#define MTK_WED_WPDMA_CFG_TX				0x588
#define MTK_WED_WPDMA_CFG_TX_FREE			0x58c

#define MTK_WED_WPDMA_TX_MIB(_n)			(0x5a0 + (_n) * 4)
#define MTK_WED_WPDMA_TX_COHERENT_MIB(_n)		(0x5d0 + (_n) * 4)
#define MTK_WED_WPDMA_RX_MIB(_n)			(0x5e0 + (_n) * 4)
#define MTK_WED_WPDMA_RX_COHERENT_MIB(_n)		(0x5f0 + (_n) * 4)

#define MTK_WED_WPDMA_RING_TX(_n)			(0x600 + (_n) * 0x10)
#define MTK_WED_WPDMA_RING_RX(_n)			(0x700 + (_n) * 0x10)
#define MTK_WED_WPDMA_RING_RX_DATA(_n)			(0x730 + (_n) * 0x10)

#define MTK_WED_WPDMA_RX_D_GLO_CFG			0x75c
#define MTK_WED_WPDMA_RX_D_RX_DRV_EN			BIT(0)
#define MTK_WED_WPDMA_RX_D_RX_DRV_BUSY			BIT(1)
#define MTK_WED_WPDMA_RX_D_FSM_RETURN_IDLE		BIT(3)
#define MTK_WED_WPDMA_RX_D_RST_INIT_COMPLETE		BIT(4)
#define MTK_WED_WPDMA_RX_D_INIT_PHASE_RXEN_SEL		GENMASK(11, 7)
#define MTK_WED_WPDMA_RX_D_RXD_READ_LEN			GENMASK(31, 24)

#define MTK_WED_WPDMA_RX_D_RST_IDX			0x760
#define MTK_WED_WPDMA_RX_D_RST_CRX_IDX			GENMASK(17, 16)
#define MTK_WED_WPDMA_RX_D_RST_DRV_IDX_ALL		BIT(20)
#define MTK_WED_WPDMA_RX_D_RST_DRV_IDX			GENMASK(25, 24)

#define MTK_WED_WPDMA_RX_GLO_CFG			0x76c

#define MTK_WED_WPDMA_RX_D_MIB(_n)			(0x774 + (_n) * 4)
#define MTK_WED_WPDMA_RX_D_PROCESSED_MIB(_n)		(0x784 + (_n) * 4)
#define MTK_WED_WPDMA_RX_D_COHERENT_MIB			0x78c

#define MTK_WED_WPDMA_RX_D_PREF_CFG			0x7b4
#define MTK_WED_WPDMA_RX_D_PREF_EN			BIT(0)
#define MTK_WED_WPDMA_RX_D_PREF_BUSY			BIT(1)
#define MTK_WED_WPDMA_RX_D_PREF_BURST_SIZE		GENMASK(12, 8)
#define MTK_WED_WPDMA_RX_D_PREF_LOW_THRES		GENMASK(21, 16)

#define MTK_WED_WPDMA_RX_D_PREF_RX0_SIDX		0x7b8
#define MTK_WED_WPDMA_RX_D_PREF_SIDX_IDX_CLR		BIT(15)

#define MTK_WED_WPDMA_RX_D_PREF_RX1_SIDX		0x7bc

#define MTK_WED_WPDMA_RX_D_PREF_FIFO_CFG		0x7c0
#define MTK_WED_WPDMA_RX_D_PREF_FIFO_CFG_R0_CLR		BIT(0)
#define MTK_WED_WPDMA_RX_D_PREF_FIFO_CFG_R1_CLR		BIT(16)

#define MTK_WED_WDMA_RING_TX				0x800

#define MTK_WED_WDMA_TX_MIB				0x810

#define MTK_WED_WDMA_RING_RX(_n)			(0x900 + (_n) * 0x10)
#define MTK_WED_WDMA_RX_THRES(_n)			(0x940 + (_n) * 0x4)

#define MTK_WED_WDMA_RX_PREF_CFG			0x950
#define MTK_WED_WDMA_RX_PREF_EN				BIT(0)
#define MTK_WED_WDMA_RX_PREF_BUSY			BIT(1)
#define MTK_WED_WDMA_RX_PREF_BURST_SIZE			GENMASK(12, 8)
#define MTK_WED_WDMA_RX_PREF_LOW_THRES			GENMASK(21, 16)
#define MTK_WED_WDMA_RX_PREF_RX0_SIDX_CLR		BIT(24)
#define MTK_WED_WDMA_RX_PREF_RX1_SIDX_CLR		BIT(25)
#define MTK_WED_WDMA_RX_PREF_DDONE2_EN			BIT(26)
#define MTK_WED_WDMA_RX_PREF_DDONE2_BUSY		BIT(27)

#define MTK_WED_WDMA_RX_PREF_FIFO_CFG			0x95C
#define MTK_WED_WDMA_RX_PREF_FIFO_RX0_CLR		BIT(0)
#define MTK_WED_WDMA_RX_PREF_FIFO_RX1_CLR		BIT(16)

#define MTK_WED_WDMA_GLO_CFG				0xa04
#define MTK_WED_WDMA_GLO_CFG_TX_DRV_EN			BIT(0)
#define MTK_WED_WDMA_GLO_CFG_TX_DDONE_CHK		BIT(1)
#define MTK_WED_WDMA_GLO_CFG_RX_DRV_EN			BIT(2)
#define MTK_WED_WDMA_GLO_CFG_RX_DRV_BUSY		BIT(3)
#define MTK_WED_WDMA_GLO_CFG_BT_SIZE			GENMASK(5, 4)
#define MTK_WED_WDMA_GLO_CFG_TX_WB_DDONE		BIT(6)
#define MTK_WED_WDMA_GLO_CFG_RX_DIS_FSM_AUTO_IDLE	BIT(13)
#define MTK_WED_WDMA_GLO_CFG_WCOMPLETE_SEL		BIT(16)
#define MTK_WED_WDMA_GLO_CFG_INIT_PHASE_RXDMA_BYPASS	BIT(17)
#define MTK_WED_WDMA_GLO_CFG_INIT_PHASE_BYPASS		BIT(18)
#define MTK_WED_WDMA_GLO_CFG_FSM_RETURN_IDLE		BIT(19)
#define MTK_WED_WDMA_GLO_CFG_WAIT_COHERENT		BIT(20)
#define MTK_WED_WDMA_GLO_CFG_AXI_W_AFTER_AW		BIT(21)
#define MTK_WED_WDMA_GLO_CFG_IDLE_DMAD_SUPPLY_SINGLE_W	BIT(22)
#define MTK_WED_WDMA_GLO_CFG_IDLE_DMAD_SUPPLY		BIT(23)
#define MTK_WED_WDMA_GLO_CFG_DYNAMIC_SKIP_DMAD_PREP	BIT(24)
#define MTK_WED_WDMA_GLO_CFG_DYNAMIC_DMAD_RECYCLE	BIT(25)
#define MTK_WED_WDMA_GLO_CFG_RST_INIT_COMPLETE		BIT(26)
#define MTK_WED_WDMA_GLO_CFG_RXDRV_CLKGATE_BYPASS	BIT(30)

#define MTK_WED_WDMA_RESET_IDX				0xa08
#define MTK_WED_WDMA_RESET_IDX_RX			GENMASK(17, 16)
#define MTK_WED_WDMA_RESET_IDX_RX_ALL			BIT(20)
#define MTK_WED_WDMA_RESET_IDX_DRV			GENMASK(25, 24)

#define MTK_WED_WDMA_INT_CLR				0xa24
#define MTK_WED_WDMA_INT_CLR_RX_DONE			GENMASK(17, 16)

#define MTK_WED_WDMA_INT_TRIGGER			0xa28
#define MTK_WED_WDMA_INT_TRIGGER_RX_DONE		GENMASK(17, 16)

#define MTK_WED_WDMA_INT_CTRL				0xa2c
#define MTK_WED_WDMA_INT_POLL_PRD			GENMASK(7, 0)
#define MTK_WED_WDMA_INT_CTRL_POLL_SRC_SEL		GENMASK(17, 16)

#define MTK_WED_WDMA_CFG_BASE				0xaa0
#define MTK_WED_WDMA_OFFSET0				0xaa4
#define MTK_WED_WDMA_OFFSET1				0xaa8

#define MTK_WED_WDMA_OFST0_GLO_INTS			GENMASK(15, 0)
#define MTK_WED_WDMA_OFST0_GLO_CFG			GENMASK(31, 16)
#define MTK_WED_WDMA_OFST1_TX_CTRL			GENMASK(15, 0)
#define MTK_WED_WDMA_OFST1_RX_CTRL			GENMASK(31, 16)

#define MTK_WED_WDMA_RX_MIB(_n)				(0xae0 + (_n) * 4)
#define MTK_WED_WDMA_RX_RECYCLE_MIB(_n)			(0xae8 + (_n) * 4)
#define MTK_WED_WDMA_RX_PROCESSED_MIB(_n)		(0xaf0 + (_n) * 4)

#define MTK_WED_RX_BM_RX_DMAD				0xd80
#define MTK_WED_RX_BM_RX_DMAD_SDL0			GENMASK(13, 0)

#define MTK_WED_RX_BM_BASE				0xd84
#define MTK_WED_RX_BM_INIT_PTR				0xd88
#define MTK_WED_RX_BM_SW_TAIL				GENMASK(15, 0)
#define MTK_WED_RX_BM_INIT_SW_TAIL			BIT(16)

#define MTK_WED_RX_PTR					0xd8c

#define MTK_WED_RX_BM_DYN_ALLOC_TH			0xdb4
#define MTK_WED_RX_BM_DYN_ALLOC_TH_H			GENMASK(31, 16)
#define MTK_WED_RX_BM_DYN_ALLOC_TH_L			GENMASK(15, 0)

#define MTK_WED_RING_OFS_BASE				0x00
#define MTK_WED_RING_OFS_COUNT				0x04
#define MTK_WED_RING_OFS_CPU_IDX			0x08
#define MTK_WED_RING_OFS_DMA_IDX			0x0c

#define MTK_WDMA_RING_TX(_n)				(0x000 + (_n) * 0x10)
#define MTK_WDMA_RING_RX(_n)				(0x100 + (_n) * 0x10)

#define MTK_WDMA_GLO_CFG				0x204
#define MTK_WDMA_GLO_CFG_TX_DMA_EN			BIT(0)
#define MTK_WDMA_GLO_CFG_TX_DMA_BUSY			BIT(1)
#define MTK_WDMA_GLO_CFG_RX_DMA_EN			BIT(2)
#define MTK_WDMA_GLO_CFG_RX_DMA_BUSY			BIT(3)
#define MTK_WDMA_GLO_CFG_RX_INFO3_PRERES		BIT(26)
#define MTK_WDMA_GLO_CFG_RX_INFO2_PRERES		BIT(27)
#define MTK_WDMA_GLO_CFG_RX_INFO1_PRERES		BIT(28)

#define MTK_WDMA_RESET_IDX				0x208
#define MTK_WDMA_RESET_IDX_TX				GENMASK(3, 0)
#define MTK_WDMA_RESET_IDX_RX				GENMASK(17, 16)

#define MTK_WDMA_INT_STATUS				0x220

#define MTK_WDMA_INT_MASK				0x228
#define MTK_WDMA_INT_MASK_TX_DONE			GENMASK(3, 0)
#define MTK_WDMA_INT_MASK_RX_DONE			GENMASK(17, 16)
#define MTK_WDMA_INT_MASK_TX_DELAY			BIT(28)
#define MTK_WDMA_INT_MASK_TX_COHERENT			BIT(29)
#define MTK_WDMA_INT_MASK_RX_DELAY			BIT(30)
#define MTK_WDMA_INT_MASK_RX_COHERENT			BIT(31)

#define MTK_WDMA_XDMA_TX_FIFO_CFG			0x238
#define MTK_WDMA_XDMA_TX_FIFO_CFG_TX_PAR_FIFO_CLEAR	BIT(0)
#define MTK_WDMA_XDMA_TX_FIFO_CFG_TX_CMD_FIFO_CLEAR	BIT(4)
#define MTK_WDMA_XDMA_TX_FIFO_CFG_TX_DMAD_FIFO_CLEAR	BIT(8)
#define MTK_WDMA_XDMA_TX_FIFO_CFG_TX_ARR_FIFO_CLEAR	BIT(12)

#define MTK_WDMA_XDMA_RX_FIFO_CFG			0x23c
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_PAR_FIFO_CLEAR	BIT(0)
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_CMD_FIFO_CLEAR	BIT(4)
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_DMAD_FIFO_CLEAR	BIT(8)
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_ARR_FIFO_CLEAR	BIT(12)
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_LEN_FIFO_CLEAR	BIT(15)
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_WID_FIFO_CLEAR	BIT(18)
#define MTK_WDMA_XDMA_RX_FIFO_CFG_RX_BID_FIFO_CLEAR	BIT(21)

#define MTK_WDMA_INT_GRP1				0x250
#define MTK_WDMA_INT_GRP2				0x254

#define MTK_WDMA_PREF_TX_CFG				0x2d0
#define MTK_WDMA_PREF_TX_CFG_PREF_EN			BIT(0)
#define MTK_WDMA_PREF_TX_CFG_PREF_BUSY			BIT(1)

#define MTK_WDMA_PREF_RX_CFG				0x2dc
#define MTK_WDMA_PREF_RX_CFG_PREF_EN			BIT(0)
#define MTK_WDMA_PREF_RX_CFG_PREF_BUSY			BIT(1)

#define MTK_WDMA_PREF_RX_FIFO_CFG			0x2e0
#define MTK_WDMA_PREF_RX_FIFO_CFG_RING0_CLEAR		BIT(0)
#define MTK_WDMA_PREF_RX_FIFO_CFG_RING1_CLEAR		BIT(16)

#define MTK_WDMA_PREF_TX_FIFO_CFG			0x2d4
#define MTK_WDMA_PREF_TX_FIFO_CFG_RING0_CLEAR		BIT(0)
#define MTK_WDMA_PREF_TX_FIFO_CFG_RING1_CLEAR		BIT(16)

#define MTK_WDMA_PREF_SIDX_CFG				0x2e4
#define MTK_WDMA_PREF_SIDX_CFG_TX_RING_CLEAR		GENMASK(3, 0)
#define MTK_WDMA_PREF_SIDX_CFG_RX_RING_CLEAR		GENMASK(5, 4)

#define MTK_WDMA_WRBK_TX_CFG				0x300
#define MTK_WDMA_WRBK_TX_CFG_WRBK_BUSY			BIT(0)
#define MTK_WDMA_WRBK_TX_CFG_WRBK_EN			BIT(30)

#define MTK_WDMA_WRBK_TX_FIFO_CFG(_n)			(0x304 + (_n) * 0x4)
#define MTK_WDMA_WRBK_TX_FIFO_CFG_RING_CLEAR		BIT(0)

#define MTK_WDMA_WRBK_RX_CFG				0x344
#define MTK_WDMA_WRBK_RX_CFG_WRBK_BUSY			BIT(0)
#define MTK_WDMA_WRBK_RX_CFG_WRBK_EN			BIT(30)

#define MTK_WDMA_WRBK_RX_FIFO_CFG(_n)			(0x348 + (_n) * 0x4)
#define MTK_WDMA_WRBK_RX_FIFO_CFG_RING_CLEAR		BIT(0)

#define MTK_WDMA_WRBK_SIDX_CFG				0x388
#define MTK_WDMA_WRBK_SIDX_CFG_TX_RING_CLEAR		GENMASK(3, 0)
#define MTK_WDMA_WRBK_SIDX_CFG_RX_RING_CLEAR		GENMASK(5, 4)

#define MTK_PCIE_MIRROR_MAP(n)				((n) ? 0x4 : 0x0)
#define MTK_PCIE_MIRROR_MAP_EN				BIT(0)
#define MTK_PCIE_MIRROR_MAP_WED_ID			BIT(1)

/* DMA channel mapping */
#define HIFSYS_DMA_AG_MAP				0x008

#define MTK_WED_RTQM_GLO_CFG				0xb00
#define MTK_WED_RTQM_BUSY				BIT(1)
#define MTK_WED_RTQM_Q_RST				BIT(2)
#define MTK_WED_RTQM_Q_DBG_BYPASS			BIT(5)
#define MTK_WED_RTQM_TXDMAD_FPORT			GENMASK(23, 20)

#define MTK_WED_RTQM_RST				0xb04

#define MTK_WED_RTQM_IGRS0_I2HW_DMAD_CNT		0xb1c
#define MTK_WED_RTQM_IGRS0_I2H_DMAD_CNT(_n)		(0xb20 + (_n) * 0x4)
#define	MTK_WED_RTQM_IGRS0_I2HW_PKT_CNT			0xb28
#define MTK_WED_RTQM_IGRS0_I2H_PKT_CNT(_n)		(0xb2c + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS0_FDROP_CNT			0xb34

#define MTK_WED_RTQM_IGRS1_I2HW_DMAD_CNT		0xb44
#define MTK_WED_RTQM_IGRS1_I2H_DMAD_CNT(_n)		(0xb48 + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS1_I2HW_PKT_CNT			0xb50
#define MTK_WED_RTQM_IGRS1_I2H_PKT_CNT(_n)		(0xb54 + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS1_FDROP_CNT			0xb5c

#define MTK_WED_RTQM_IGRS2_I2HW_DMAD_CNT		0xb6c
#define MTK_WED_RTQM_IGRS2_I2H_DMAD_CNT(_n)		(0xb70 + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS2_I2HW_PKT_CNT			0xb78
#define MTK_WED_RTQM_IGRS2_I2H_PKT_CNT(_n)		(0xb7c + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS2_FDROP_CNT			0xb84

#define MTK_WED_RTQM_IGRS3_I2HW_DMAD_CNT		0xb94
#define MTK_WED_RTQM_IGRS3_I2H_DMAD_CNT(_n)		(0xb98 + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS3_I2HW_PKT_CNT			0xba0
#define MTK_WED_RTQM_IGRS3_I2H_PKT_CNT(_n)		(0xba4 + (_n) * 0x4)
#define MTK_WED_RTQM_IGRS3_FDROP_CNT			0xbac

#define MTK_WED_RTQM_R2H_MIB(_n)			(0xb70 + (_n) * 0x4)
#define MTK_WED_RTQM_R2Q_MIB(_n)			(0xb78 + (_n) * 0x4)
#define MTK_WED_RTQM_Q2N_MIB				0xb80
#define MTK_WED_RTQM_Q2H_MIB(_n)			(0xb84 + (_n) * 0x4)

#define MTK_WED_RTQM_Q2B_MIB				0xb8c
#define MTK_WED_RTQM_PFDBK_MIB				0xb90

#define MTK_WED_RTQM_ENQ_CFG0				0xbb8
#define MTK_WED_RTQM_ENQ_CFG_TXDMAD_FPORT		GENMASK(15, 12)

#define MTK_WED_RTQM_FDROP_MIB				0xb84
#define MTK_WED_RTQM_ENQ_I2Q_DMAD_CNT			0xbbc
#define MTK_WED_RTQM_ENQ_I2N_DMAD_CNT			0xbc0
#define MTK_WED_RTQM_ENQ_I2Q_PKT_CNT			0xbc4
#define MTK_WED_RTQM_ENQ_I2N_PKT_CNT			0xbc8
#define MTK_WED_RTQM_ENQ_USED_ENTRY_CNT			0xbcc
#define MTK_WED_RTQM_ENQ_ERR_CNT			0xbd0

#define MTK_WED_RTQM_DEQ_DMAD_CNT			0xbd8
#define MTK_WED_RTQM_DEQ_Q2I_DMAD_CNT			0xbdc
#define MTK_WED_RTQM_DEQ_PKT_CNT			0xbe0
#define MTK_WED_RTQM_DEQ_Q2I_PKT_CNT			0xbe4
#define MTK_WED_RTQM_DEQ_USED_PFDBK_CNT			0xbe8
#define MTK_WED_RTQM_DEQ_ERR_CNT			0xbec

#define MTK_WED_RROQM_GLO_CFG				0xc04
#define MTK_WED_RROQM_RST_IDX				0xc08
#define MTK_WED_RROQM_RST_IDX_MIOD			BIT(0)
#define MTK_WED_RROQM_RST_IDX_FDBK			BIT(4)

#define MTK_WED_RROQM_MIOD_CTRL0			0xc40
#define MTK_WED_RROQM_MIOD_CTRL1			0xc44
#define MTK_WED_RROQM_MIOD_CNT				GENMASK(11, 0)

#define MTK_WED_RROQM_MIOD_CTRL2			0xc48
#define MTK_WED_RROQM_MIOD_CTRL3			0xc4c

#define MTK_WED_RROQM_FDBK_CTRL0			0xc50
#define MTK_WED_RROQM_FDBK_CTRL1			0xc54
#define MTK_WED_RROQM_FDBK_CNT				GENMASK(11, 0)

#define MTK_WED_RROQM_FDBK_CTRL2			0xc58

#define MTK_WED_RROQ_BASE_L				0xc80
#define MTK_WED_RROQ_BASE_H				0xc84

#define MTK_WED_RROQM_MIOD_CFG				0xc8c
#define MTK_WED_RROQM_MIOD_MID_DW			GENMASK(5, 0)
#define MTK_WED_RROQM_MIOD_MOD_DW			GENMASK(13, 8)
#define MTK_WED_RROQM_MIOD_ENTRY_DW			GENMASK(22, 16)

#define MTK_WED_RROQM_MID_MIB				0xcc0
#define MTK_WED_RROQM_MOD_MIB				0xcc4
#define MTK_WED_RROQM_MOD_COHERENT_MIB			0xcc8
#define MTK_WED_RROQM_FDBK_MIB				0xcd0
#define MTK_WED_RROQM_FDBK_COHERENT_MIB			0xcd4
#define MTK_WED_RROQM_FDBK_IND_MIB			0xce0
#define MTK_WED_RROQM_FDBK_ENQ_MIB			0xce4
#define MTK_WED_RROQM_FDBK_ANC_MIB			0xce8
#define MTK_WED_RROQM_FDBK_ANC2H_MIB			0xcec

#define MTK_WED_RX_BM_RX_DMAD				0xd80
#define MTK_WED_RX_BM_BASE				0xd84
#define MTK_WED_RX_BM_INIT_PTR				0xd88
#define MTK_WED_RX_BM_PTR				0xd8c
#define MTK_WED_RX_BM_PTR_HEAD				GENMASK(32, 16)
#define MTK_WED_RX_BM_PTR_TAIL				GENMASK(15, 0)

#define MTK_WED_RX_BM_BLEN				0xd90
#define MTK_WED_RX_BM_STS				0xd94
#define MTK_WED_RX_BM_INTF2				0xd98
#define MTK_WED_RX_BM_INTF				0xd9c
#define MTK_WED_RX_BM_ERR_STS				0xda8

#define MTK_RRO_IND_CMD_SIGNATURE			0xe00
#define MTK_RRO_IND_CMD_DMA_IDX				GENMASK(11, 0)
#define MTK_RRO_IND_CMD_MAGIC_CNT			GENMASK(30, 28)

#define MTK_WED_IND_CMD_RX_CTRL0			0xe04
#define MTK_WED_IND_CMD_PROC_IDX			GENMASK(11, 0)
#define MTK_WED_IND_CMD_PREFETCH_FREE_CNT		GENMASK(19, 16)
#define MTK_WED_IND_CMD_MAGIC_CNT			GENMASK(30, 28)

#define MTK_WED_IND_CMD_RX_CTRL1			0xe08
#define MTK_WED_IND_CMD_RX_CTRL2			0xe0c
#define MTK_WED_IND_CMD_MAX_CNT				GENMASK(11, 0)
#define MTK_WED_IND_CMD_BASE_M				GENMASK(19, 16)

#define MTK_WED_RRO_CFG0				0xe10
#define MTK_WED_RRO_CFG1				0xe14
#define MTK_WED_RRO_CFG1_MAX_WIN_SZ			GENMASK(31, 29)
#define MTK_WED_RRO_CFG1_ACK_SN_BASE_M			GENMASK(19, 16)
#define MTK_WED_RRO_CFG1_PARTICL_SE_ID			GENMASK(11, 0)

#define MTK_WED_ADDR_ELEM_CFG0				0xe18
#define MTK_WED_ADDR_ELEM_CFG1				0xe1c
#define MTK_WED_ADDR_ELEM_PREFETCH_FREE_CNT		GENMASK(19, 16)

#define MTK_WED_ADDR_ELEM_TBL_CFG			0xe20
#define MTK_WED_ADDR_ELEM_TBL_OFFSET			GENMASK(6, 0)
#define MTK_WED_ADDR_ELEM_TBL_RD_RDY			BIT(28)
#define MTK_WED_ADDR_ELEM_TBL_WR_RDY			BIT(29)
#define MTK_WED_ADDR_ELEM_TBL_RD			BIT(30)
#define MTK_WED_ADDR_ELEM_TBL_WR			BIT(31)

#define MTK_WED_RADDR_ELEM_TBL_WDATA			0xe24
#define MTK_WED_RADDR_ELEM_TBL_RDATA			0xe28

#define MTK_WED_PN_CHECK_CFG				0xe30
#define MTK_WED_PN_CHECK_SE_ID				GENMASK(11, 0)
#define MTK_WED_PN_CHECK_RD_RDY				BIT(28)
#define MTK_WED_PN_CHECK_WR_RDY				BIT(29)
#define MTK_WED_PN_CHECK_RD				BIT(30)
#define MTK_WED_PN_CHECK_WR				BIT(31)

#define MTK_WED_PN_CHECK_WDATA_M			0xe38
#define MTK_WED_PN_CHECK_IS_FIRST			BIT(17)

#define MTK_WED_RRO_MSDU_PG_RING_CFG(_n)		(0xe44 + (_n) * 0x8)

#define MTK_WED_RRO_MSDU_PG_RING2_CFG			0xe58
#define MTK_WED_RRO_MSDU_PG_DRV_CLR			BIT(26)
#define MTK_WED_RRO_MSDU_PG_DRV_EN			BIT(31)

#define MTK_WED_RRO_MSDU_PG_CTRL0(_n)			(0xe5c + (_n) * 0xc)
#define MTK_WED_RRO_MSDU_PG_CTRL1(_n)			(0xe60 + (_n) * 0xc)
#define MTK_WED_RRO_MSDU_PG_CTRL2(_n)			(0xe64 + (_n) * 0xc)

#define MTK_WED_RRO_RX_D_RX(_n)				(0xe80 + (_n) * 0x10)

#define MTK_WED_RRO_RX_MAGIC_CNT			BIT(13)

#define MTK_WED_RRO_RX_D_CFG(_n)			(0xea0 + (_n) * 0x4)
#define MTK_WED_RRO_RX_D_DRV_CLR			BIT(26)
#define MTK_WED_RRO_RX_D_DRV_EN				BIT(31)

#define MTK_WED_RRO_PG_BM_RX_DMAM			0xeb0
#define MTK_WED_RRO_PG_BM_RX_SDL0			GENMASK(13, 0)

#define MTK_WED_RRO_PG_BM_BASE				0xeb4
#define MTK_WED_RRO_PG_BM_INIT_PTR			0xeb8
#define MTK_WED_RRO_PG_BM_SW_TAIL_IDX			GENMASK(15, 0)
#define MTK_WED_RRO_PG_BM_INIT_SW_TAIL_IDX		BIT(16)

#define MTK_WED_WPDMA_INT_CTRL_RRO_RX			0xeec
#define MTK_WED_WPDMA_INT_CTRL_RRO_RX0_EN		BIT(0)
#define MTK_WED_WPDMA_INT_CTRL_RRO_RX0_CLR		BIT(1)
#define MTK_WED_WPDMA_INT_CTRL_RRO_RX0_DONE_TRIG	GENMASK(6, 2)
#define MTK_WED_WPDMA_INT_CTRL_RRO_RX1_EN		BIT(8)
#define MTK_WED_WPDMA_INT_CTRL_RRO_RX1_CLR		BIT(9)
#define MTK_WED_WPDMA_INT_CTRL_RRO_RX1_DONE_TRIG	GENMASK(14, 10)

#define MTK_WED_WPDMA_INT_CTRL_RRO_MSDU_PG		0xef4
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG0_EN		BIT(0)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG0_CLR		BIT(1)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG0_DONE_TRIG	GENMASK(6, 2)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG1_EN		BIT(8)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG1_CLR		BIT(9)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG1_DONE_TRIG	GENMASK(14, 10)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG2_EN		BIT(16)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG2_CLR		BIT(17)
#define MTK_WED_WPDMA_INT_CTRL_RRO_PG2_DONE_TRIG	GENMASK(22, 18)

#define MTK_WED_RRO_RX_HW_STS				0xf00
#define MTK_WED_RX_IND_CMD_BUSY				GENMASK(31, 0)

#define MTK_WED_RX_IND_CMD_CNT0				0xf20
#define MTK_WED_RX_IND_CMD_DBG_CNT_EN			BIT(31)

#define MTK_WED_RX_IND_CMD_CNT(_n)			(0xf20 + (_n) * 0x4)
#define MTK_WED_IND_CMD_MAGIC_CNT_FAIL_CNT		GENMASK(15, 0)

#define MTK_WED_RX_ADDR_ELEM_CNT(_n)			(0xf48 + (_n) * 0x4)
#define MTK_WED_ADDR_ELEM_SIG_FAIL_CNT			GENMASK(15, 0)
#define MTK_WED_ADDR_ELEM_FIRST_SIG_FAIL_CNT		GENMASK(31, 16)
#define MTK_WED_ADDR_ELEM_ACKSN_CNT			GENMASK(27, 0)

#define MTK_WED_RX_MSDU_PG_CNT(_n)			(0xf5c + (_n) * 0x4)

#define MTK_WED_RX_PN_CHK_CNT				0xf70
#define MTK_WED_PN_CHK_FAIL_CNT				GENMASK(15, 0)

#define MTK_WED_WOCPU_VIEW_MIOD_BASE			0x8000
#define MTK_WED_PCIE_INT_MASK				0x0

#define MTK_WED_AMSDU_FIFO				0x1800
#define MTK_WED_AMSDU_IS_PRIOR0_RING			BIT(10)

#define MTK_WED_AMSDU_STA_INFO				0x01810
#define MTK_WED_AMSDU_STA_INFO_DO_INIT			BIT(0)
#define MTK_WED_AMSDU_STA_INFO_SET_INIT			BIT(1)

#define MTK_WED_AMSDU_STA_INFO_INIT			0x01814
#define MTK_WED_AMSDU_STA_WTBL_HDRT_MODE		BIT(0)
#define MTK_WED_AMSDU_STA_RMVL				BIT(1)
#define MTK_WED_AMSDU_STA_MAX_AMSDU_LEN			GENMASK(7, 2)
#define MTK_WED_AMSDU_STA_MAX_AMSDU_NUM			GENMASK(11, 8)

#define MTK_WED_AMSDU_HIFTXD_BASE_L(_n)			(0x1980 + (_n) * 0x4)

#define MTK_WED_AMSDU_PSE				0x1910
#define MTK_WED_AMSDU_PSE_RESET				BIT(16)

#define MTK_WED_AMSDU_HIFTXD_CFG			0x1968
#define MTK_WED_AMSDU_HIFTXD_SRC			GENMASK(16, 15)

#define MTK_WED_MON_AMSDU_FIFO_DMAD			0x1a34

#define MTK_WED_MON_AMSDU_ENG_DMAD(_n)			(0x1a80 + (_n) * 0x50)
#define MTK_WED_MON_AMSDU_ENG_QFPL(_n)			(0x1a84 + (_n) * 0x50)
#define MTK_WED_MON_AMSDU_ENG_QENI(_n)			(0x1a88 + (_n) * 0x50)
#define MTK_WED_MON_AMSDU_ENG_QENO(_n)			(0x1a8c + (_n) * 0x50)
#define MTK_WED_MON_AMSDU_ENG_MERG(_n)			(0x1a90 + (_n) * 0x50)

#define MTK_WED_MON_AMSDU_ENG_CNT8(_n)			(0x1a94 + (_n) * 0x50)
#define MTK_WED_AMSDU_ENG_MAX_QGPP_CNT			GENMASK(10, 0)
#define MTK_WED_AMSDU_ENG_MAX_PL_CNT			GENMASK(27, 16)

#define MTK_WED_MON_AMSDU_ENG_CNT9(_n)			(0x1a98 + (_n) * 0x50)
#define MTK_WED_AMSDU_ENG_CUR_ENTRY			GENMASK(10, 0)
#define MTK_WED_AMSDU_ENG_MAX_BUF_MERGED		GENMASK(20, 16)
#define MTK_WED_AMSDU_ENG_MAX_MSDU_MERGED		GENMASK(28, 24)

#define MTK_WED_MON_AMSDU_QMEM_STS1			0x1e04

#define MTK_WED_MON_AMSDU_QMEM_CNT(_n)			(0x1e0c + (_n) * 0x4)
#define MTK_WED_AMSDU_QMEM_FQ_CNT			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_SP_QCNT			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID0_QCNT			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID1_QCNT			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID2_QCNT			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID3_QCNT			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID4_QCNT			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID5_QCNT			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID6_QCNT			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID7_QCNT			GENMASK(11, 0)

#define MTK_WED_MON_AMSDU_QMEM_PTR(_n)			(0x1e20 + (_n) * 0x4)
#define MTK_WED_AMSDU_QMEM_FQ_HEAD			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_SP_QHEAD			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID0_QHEAD			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID1_QHEAD			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID2_QHEAD			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID3_QHEAD			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID4_QHEAD			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID5_QHEAD			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID6_QHEAD			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID7_QHEAD			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_FQ_TAIL			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_SP_QTAIL			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID0_QTAIL			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID1_QTAIL			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID2_QTAIL			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID3_QTAIL			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID4_QTAIL			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID5_QTAIL			GENMASK(11, 0)
#define MTK_WED_AMSDU_QMEM_TID6_QTAIL			GENMASK(27, 16)
#define MTK_WED_AMSDU_QMEM_TID7_QTAIL			GENMASK(11, 0)

#define MTK_WED_MON_AMSDU_HIFTXD_FETCH_MSDU(_n)		(0x1ec4 + (_n) * 0x4)

#define MTK_WED_PCIE_BASE			0x11280000
#define MTK_WED_PCIE_BASE0			0x11300000
#define MTK_WED_PCIE_BASE1			0x11310000
#define MTK_WED_PCIE_BASE2			0x11290000
#endif
