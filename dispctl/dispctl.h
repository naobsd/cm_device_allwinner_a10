/*-
 * Copyright (c) 2012 FUKAUMI Naoki.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define CMD_GET_OUTPUT_TYPE	0xa
#define  OUTPUT_TYPE_NONE		0x0
#define  OUTPUT_TYPE_LCD		0x1
#define  OUTPUT_TYPE_TV			0x2
#define  OUTPUT_TYPE_HDMI		0x4
#define  OUTPUT_TYPE_VGA		0x8

#define CMD_LCD		0x140
#define  LCD_ON				0x0
#define  LCD_OFF			0x1
#define  LCD_SET_BRIGHTNESS		0x2
#define  LCD_GET_BRIGHTNESS		0x3

#define CMD_TV		0x180
#define  TV_ON				0x0
#define  TV_OFF				0x1
#define  TV_SET_MODE			0x2
#define  TV_GET_MODE			0x3

#define CMD_HDMI	0x1c0
#define  HDMI_ON			0x0
#define  HDMI_OFF			0x1
#define  HDMI_SET_MODE			0x2
#define  HDMI_GET_MODE			0x3
#define  HDMI_SUPPORT_MODE		0x4
#define  HDMI_GET_HPD_STATUS		0x5

#define CMD_VGA		0x200
#define  VGA_ON				0x0
#define  VGA_OFF			0x1
#define  VGA_SET_MODE			0x2
#define  VGA_GET_MODE			0x3

#define CMD_FB		0x280
#define  FB_REQUEST			0x0
#define  FB_RELEASE			0x1
#define  FB_GET_PARA			0x2

struct fb_para {
	int		fb_mode;
#define FB_MODE_SCREEN0			0x0
#define FB_MODE_SCREEN1			0x1
#define FB_MODE_TWO_SAME_SCREEN_TB	0x2
#define FB_MODE_TWO_DIFF_SCREEN_SAME_CONTENTS	0x3
	int		mode;
	uint32_t	buffer_num;
	uint32_t	width;
	uint32_t	height;
	uint32_t	output_width;
	uint32_t	output_height;
	uint32_t	primary_screen_id;
	uint32_t	aux_output_width;
	uint32_t	aux_output_height;
	uint32_t	line_length;
	uint32_t	smem_len;
	uint32_t	ch1_offset;
	uint32_t	ch2_offset;
};

#define TV_MODE_480I			0x0
#define TV_MODE_576I			0x1
#define TV_MODE_480P			0x2
#define TV_MODE_576P			0x3
#define TV_MODE_720P_50HZ		0x4
#define TV_MODE_720P_60HZ		0x5
#define TV_MODE_1080I_50HZ		0x6
#define TV_MODE_1080I_60HZ		0x7
#define TV_MODE_1080P_24HZ		0x8
#define TV_MODE_1080P_50HZ		0x9
#define TV_MODE_1080P_60HZ		0xa
#define TV_MODE_PAL			0xb
#define TV_MODE_PAL_SVIDEO		0xc
#define TV_MODE_NTSC			0xe
#define TV_MODE_NTSC_SVIDEO		0xf
#define TV_MODE_PAL_M			0x11
#define TV_MODE_PAL_M_SVIDEO		0x12
#define TV_MODE_PAL_NC			0x14
#define TV_MODE_PAL_NC_SVIDEO		0x15
#define TV_MODE_1080P_24HZ_3D_FP	0x17
#define TV_MODE_720P_50HZ_3D_FP		0x18
#define TV_MODE_720P_60HZ_3D_FP		0x19
#define TV_MODE_NUM			0x1a

#define VGA_MODE_H1680_V1050		0x0
#define VGA_MODE_H1440_V900		0x1
#define VGA_MODE_H1360_V768		0x2
#define VGA_MODE_H1280_V1024		0x3
#define VGA_MODE_H1024_V768		0x4
#define VGA_MODE_H800_V600		0x5
#define VGA_MODE_H640_V480		0x6
/* #define VGA_MODE_H1440_V900_RB		0x7 */
/* #define VGA_MODE_H1680_V1050_RB		0x8 */
#define VGA_MODE_H1920_V1080_RB		0x9
#define VGA_MODE_H1920_V1080		0xa
#define VGA_MODE_H1280_V720		0xb
#define VGA_MODE_NUM			0xc
