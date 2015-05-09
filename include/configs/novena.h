/*
 * Copyright (C) 2013 Freescale Semiconductor, Inc.
 * Copyright (C) 2013 SolidRun ltd.
 * Copyright (C) 2013 Jon Nettleton <jon.nettleton@gmail.com>
 *
 * Configuration settings for the SolidRun carrier-1 (c1) board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "mx6_common.h"
#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include <asm/sizes.h>

#include "imx6_spl.h"

#undef CONFIG_SPL_LDSCRIPT
#define CONFIG_SPL_LDSCRIPT     "board/$(BOARDDIR)/u-boot-spl-novena.lds"

#define CONFIG_MX6
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_ENABLE_MMU
#define CONFIG_SPL_BOARD_INIT
#undef CONFIG_SYS_SPL_MALLOC_SIZE
#define CONFIG_SYS_SPL_MALLOC_SIZE 65536

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(1 * SZ_256K)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_MXC_GPIO

#define CONFIG_CMD_FUSE
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE		UART2_BASE

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* Command definition */
#include <config_cmd_default.h>

#undef CONFIG_CMD_IMLS

#define CONFIG_HARD_I2C
#define CONFIG_SYS_I2C /* required to get i2c_init() */
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		100000
#define CONFIG_SYS_I2C_BASE		I2C1_BASE_ADDR
#define CONFIG_SPL_I2C_SUPPORT

#define CONFIG_SPL_FAT_SUPPORT
#define CONFIG_SUPPORT_VFAT
#undef CONFIG_SPL_FAT_LOAD_PAYLOAD_NAME
#define CONFIG_SPL_FAT_LOAD_PAYLOAD_NAME	"bootloader"
#define CONFIG_SPL_FAT_LOAD_KERNEL_NAME		"kernel"
#define CONFIG_SPL_FAT_LOAD_ARGS_NAME		"args"
#define CONFIG_SPL_OS_BOOT
#define CONFIG_SYS_SPL_ARGS_ADDR	0x11800000
#define CONFIG_SYS_MMCSD_RAW_MODE_KERNEL_SECTOR	0x500 /* address 0xa0000 */
#define CONFIG_SYS_MMCSD_RAW_MODE_ARGS_SECTOR	0x80	/* 64KiB */
#define CONFIG_SYS_MMCSD_RAW_MODE_ARGS_SECTORS	8     /* 4KB */

#define CONFIG_CMD_BMODE
#define CONFIG_CMD_SETEXPR
#define CONFIG_CMD_MEMTEST
#define CONFIG_BOOTDELAY		3

#define CONFIG_SYS_MEMTEST_START	0x10000000
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + 500 * SZ_1M)

#define CONFIG_LOADADDR			0x10800000
/*#define CONFIG_SYS_TEXT_BASE		0x17800000*/

/* SATA Configuration */
#ifdef CONFIG_CMD_SATA
#define CONFIG_DWC_AHSATA
#define CONFIG_SYS_SATA_MAX_DEVICE      1
#define CONFIG_DWC_AHSATA_PORT_ID       0
#define CONFIG_DWC_AHSATA_BASE_ADDR     SATA_ARB_BASE_ADDR
#define CONFIG_LBA48
#define CONFIG_LIBATA
#endif

/* MMC Configuration */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	0
#define CONFIG_SYS_FSL_USDHC_NUM	2
#define CONFIG_SPL_MMC_SUPPORT

#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#define CONFIG_FS_EXT4
#define CONFIG_FS_FAT
#define CONFIG_CMD_FS_GENERIC

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE            ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE     RMII
#define CONFIG_ETHPRIME         "FEC"
#define CONFIG_FEC_MXC_PHYADDR      0

#define CONFIG_PHYLIB
#define CONFIG_PHY_SMSC

#define CONFIG_SYS_CONSOLE_IS_IN_ENV

#define CONFIG_EXTRA_ENV_SETTINGS \
		"netdev=eth0\0"						\
		"ethprime=FEC0\0"					\
		"uboot_addr=0xa0000000\0"				\
		"bootargs=console=ttymxc0,115200 ip=none root=/dev/ram0 rw fec_mac=00:00:AA:BB:CC:DD\0"\
		"bootcmd=safeboot 1 0x1000 0x20000 0x14000 0x90800000 0x90800000 0x90c00000\0"


/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER

#ifndef __ASSEMBLY__
extern char *config_sys_prompt;
#endif
#define CONFIG_SYS_PROMPT_MAX_CHARS	32
#define CONFIG_SYS_PROMPT		config_sys_prompt
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		1024

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + CONFIG_SYS_PROMPT_MAX_CHARS + 16)
#define CONFIG_SYS_MAXARGS	       16
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR
#define CONFIG_SYS_HZ			1000

#define CONFIG_CMDLINE_EDITING

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE
#define CONFIG_SYS_BOOTPARAMS_LEN (16 * 1024)

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_ENV_SIZE			(128 * 1024)

#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_ENV_OFFSET		(3078 * 512)
#define CONFIG_SYS_MMC_ENV_DEV	0

#define CONFIG_OF_LIBFDT
#define CONFIG_CMD_BOOTZ

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#define CONFIG_CMD_MMC

#define LINUX_BOOT_PARAM_ADDR (PHYS_SDRAM + 0x100)
#define CONFIG_MACH_TYPE 0xffffffff

#endif			       /* __CONFIG_H * */
