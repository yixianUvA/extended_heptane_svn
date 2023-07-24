	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.arm
	.syntax divided
	.file	"minmax.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	2
	.global	swap
	.type	swap, %function
swap:
.LFB0:
	.file 1 "minmax.c"
	.loc 1 13 0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	r0, [sp, #4]
	str	r1, [sp]
	.loc 1 14 0
	ldr	r3, [sp, #4]
	ldr	r3, [r3]
	str	r3, [sp, #12]
	.loc 1 15 0
	ldr	r3, [sp]
	ldr	r2, [r3]
	ldr	r3, [sp, #4]
	str	r2, [r3]
	.loc 1 16 0
	ldr	r3, [sp]
	ldr	r2, [sp, #12]
	str	r2, [r3]
	.loc 1 17 0
	mov	r0, r0	@ nop
	add	sp, sp, #16
	.cfi_def_cfa_offset 0
	@ sp needed
	bx	lr
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.align	2
	.global	min
	.type	min, %function
min:
.LFB1:
	.loc 1 20 0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	sp, sp, #24
	.cfi_def_cfa_offset 24
	str	r0, [sp, #12]
	str	r1, [sp, #8]
	str	r2, [sp, #4]
	.loc 1 22 0
	ldr	r2, [sp, #12]
	ldr	r3, [sp, #8]
	cmp	r2, r3
	bgt	.L3
	.loc 1 24 0
	ldr	r2, [sp, #12]
	ldr	r3, [sp, #4]
	cmp	r2, r3
	bgt	.L4
	.loc 1 25 0
	ldr	r3, [sp, #12]
	str	r3, [sp, #20]
	b	.L6
.L4:
	.loc 1 27 0
	ldr	r3, [sp, #4]
	str	r3, [sp, #20]
	b	.L6
.L3:
	.loc 1 30 0
	ldr	r2, [sp, #8]
	ldr	r3, [sp, #4]
	cmp	r2, r3
	movlt	r3, r2
	movge	r3, r3
	str	r3, [sp, #20]
.L6:
	.loc 1 31 0
	ldr	r3, [sp, #20]
	.loc 1 32 0
	mov	r0, r3
	add	sp, sp, #24
	.cfi_def_cfa_offset 0
	@ sp needed
	bx	lr
	.cfi_endproc
.LFE1:
	.size	min, .-min
	.align	2
	.global	max
	.type	max, %function
max:
.LFB2:
	.loc 1 35 0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #20
	.cfi_def_cfa_offset 24
	str	r0, [sp, #12]
	str	r1, [sp, #8]
	str	r2, [sp, #4]
	.loc 1 36 0
	ldr	r2, [sp, #12]
	ldr	r3, [sp, #8]
	cmp	r2, r3
	bgt	.L9
	.loc 1 37 0
	add	r2, sp, #8
	add	r3, sp, #12
	mov	r1, r2
	mov	r0, r3
	bl	swap
.L9:
	.loc 1 38 0
	ldr	r2, [sp, #12]
	ldr	r3, [sp, #4]
	cmp	r2, r3
	bgt	.L10
	.loc 1 39 0
	add	r2, sp, #4
	add	r3, sp, #12
	mov	r1, r2
	mov	r0, r3
	bl	swap
.L10:
	.loc 1 40 0
	ldr	r3, [sp, #12]
	.loc 1 41 0
	mov	r0, r3
	add	sp, sp, #20
	.cfi_def_cfa_offset 4
	@ sp needed
	ldr	lr, [sp], #4
	.cfi_restore 14
	.cfi_def_cfa_offset 0
	bx	lr
	.cfi_endproc
.LFE2:
	.size	max, .-max
	.align	2
	.global	main
	.type	main, %function
main:
.LFB3:
	.loc 1 44 0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #20
	.cfi_def_cfa_offset 24
	.loc 1 45 0
	mov	r3, #10
	str	r3, [sp, #8]
	.loc 1 46 0
	mov	r3, #2
	str	r3, [sp, #4]
	.loc 1 47 0
	mov	r3, #1
	str	r3, [sp, #12]
	.loc 1 48 0
	ldr	r2, [sp, #8]
	ldr	r3, [sp, #4]
	cmp	r2, r3
	bgt	.L13
	.loc 1 49 0
	add	r2, sp, #4
	add	r3, sp, #8
	mov	r1, r2
	mov	r0, r3
	bl	swap
	b	.L14
.L13:
	.loc 1 50 0
	ldr	r2, [sp, #8]
	ldr	r3, [sp, #12]
	cmp	r2, r3
	bgt	.L15
	.loc 1 51 0
	ldr	r3, [sp, #8]
	ldr	r1, [sp, #4]
	ldr	r2, [sp, #12]
	mov	r0, r3
	bl	min
	mov	r2, r0
	ldr	r3, [sp, #8]
	add	r3, r2, r3
	str	r3, [sp, #8]
	b	.L14
.L15:
	.loc 1 53 0
	ldr	r3, [sp, #4]
	ldr	r2, [sp, #8]
	mov	r1, r3
	ldr	r0, [sp, #12]
	bl	max
	mov	r2, r0
	ldr	r3, [sp, #12]
	mul	r3, r2, r3
	str	r3, [sp, #12]
.L14:
	.loc 1 54 0
	ldr	r2, [sp, #4]
	ldr	r3, [sp, #12]
	cmp	r2, r3
	bgt	.L16
	.loc 1 54 0 is_stmt 0 discriminator 1
	ldr	r2, [sp, #4]
	ldr	r3, [sp, #12]
	add	r3, r2, r3
	b	.L18
.L16:
	.loc 1 54 0 discriminator 2
	ldr	r2, [sp, #4]
	ldr	r3, [sp, #12]
	rsb	r3, r3, r2
.L18:
	.loc 1 55 0 is_stmt 1 discriminator 1
	mov	r0, r3
	add	sp, sp, #20
	.cfi_def_cfa_offset 4
	@ sp needed
	ldr	lr, [sp], #4
	.cfi_restore 14
	.cfi_def_cfa_offset 0
	bx	lr
	.cfi_endproc
.LFE3:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x12d
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF2
	.byte	0xc
	.4byte	.LASF3
	.4byte	.LASF4
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.4byte	.LASF0
	.byte	0x1
	.byte	0xc
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x61
	.uleb128 0x3
	.ascii	"a\000"
	.byte	0x1
	.byte	0xc
	.4byte	0x61
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x3
	.ascii	"b\000"
	.byte	0x1
	.byte	0xc
	.4byte	0x61
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x4
	.ascii	"tmp\000"
	.byte	0x1
	.byte	0xe
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -4
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.4byte	0x67
	.uleb128 0x6
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x7
	.ascii	"min\000"
	.byte	0x1
	.byte	0x13
	.4byte	0x67
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xb8
	.uleb128 0x3
	.ascii	"a\000"
	.byte	0x1
	.byte	0x13
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x3
	.ascii	"b\000"
	.byte	0x1
	.byte	0x13
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x3
	.ascii	"c\000"
	.byte	0x1
	.byte	0x13
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x4
	.ascii	"m\000"
	.byte	0x1
	.byte	0x15
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -4
	.byte	0
	.uleb128 0x8
	.ascii	"max\000"
	.byte	0x1
	.byte	0x22
	.4byte	0x67
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xf6
	.uleb128 0x3
	.ascii	"a\000"
	.byte	0x1
	.byte	0x22
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x3
	.ascii	"b\000"
	.byte	0x1
	.byte	0x22
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x3
	.ascii	"c\000"
	.byte	0x1
	.byte	0x22
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x9
	.4byte	.LASF1
	.byte	0x1
	.byte	0x2b
	.4byte	0x67
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x4
	.ascii	"x\000"
	.byte	0x1
	.byte	0x2d
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x4
	.ascii	"y\000"
	.byte	0x1
	.byte	0x2e
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x4
	.ascii	"z\000"
	.byte	0x1
	.byte	0x2f
	.4byte	0x67
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF2:
	.ascii	"GNU C11 5.3.1 20160307 (release) [ARM/embedded-5-br"
	.ascii	"anch revision 234589] -mcpu=arm7tdmi -march=armv4t "
	.ascii	"-marm -ggdb -O0 -fomit-frame-pointer\000"
.LASF4:
	.ascii	"/home/yixian/heptane_svn/benchmarks/minmax\000"
.LASF0:
	.ascii	"swap\000"
.LASF3:
	.ascii	"/tmp/minmax.c\000"
.LASF1:
	.ascii	"main\000"
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 5.3.1 20160307 (release) [ARM/embedded-5-branch revision 234589]"
