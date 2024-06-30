strlen_diy:
	mv	a5,a0
.L2:
	lbu	a4,0(a5)
	addi	a5,a5,1
	bne	a4,zero,.L2
	sub	a0,a5,a0
	addi	a0,a0,-1
	ret

memchr_diy:
	andi	a1,a1,0xff
.L5:
	beq	a2,zero,.L8
	lbu	a5,0(a0)
	bne	a5,a1,.L7
	ret
.L7:
	addi	a0,a0,1
	addi	a2,a2,-1
	j	.L5
.L8:
	li	a0,0
	ret

strnlen_diy:
	addi	sp,sp,-32
	sd	s0,16(sp)
	mv	a2,a1
	mv	s0,a1
	li	a1,0
	sd	s1,8(sp)
	sd	ra,24(sp)
	mv	s1,a0
	call	memchr_diy
	beq	a0,zero,.L10
	sub	s0,a0,s1
.L10:
	ld	ra,24(sp)
	mv	a0,s0
	ld	s0,16(sp)
	ld	s1,8(sp)
	addi	sp,sp,32
	jr	ra

strcpy_diy:
	mv	a5,a0
.L16:
	lbu	a4,0(a1)
	addi	a1,a1,1
	addi	a5,a5,1
	sb	a4,-1(a5)
	bne	a4,zero,.L16
	ret

strcat_diy:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	sd	a1,8(sp)
	mv	s0,a0
	call	strlen_diy
	ld	a1,8(sp)
	add	a0,s0,a0
	call	strcpy_diy
	ld	ra,24(sp)
	mv	a0,s0
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra

.LC1:
	.string	"len: %d\n"
.LC2:
	.string	"Hello C/C++ LIBC:"
.LC3:
	.string	"-> strcat_diy"
.LC0:
	.string	"Hello World -> (strlen_diy memchr_diy strcpy_diy strcat_diy)"

	.type	main, @function
main:
	addi	sp,sp,-80
	sd	s0,64(sp)
	mv	s0,sp
	li	a2,61
	lla	a1,.LC0
	mv	a0,s0
	sd	ra,72(sp)
	call	memcpy@plt
	mv	a0,s0
	call	strlen_diy
	mv	a2,a0
	li	a1,40
	mv	a0,s0
	call	memchr_diy
	call	puts@plt
	mv	a0,s0
	call	strlen_diy
	sext.w	a1,a0
	lla	a0,.LC1
	call	printf@plt
	li	a1,100
	mv	a0,s0
	call	strnlen_diy
	sext.w	a1,a0
	lla	a0,.LC1
	call	printf@plt
	lla	a1,.LC2
	mv	a0,s0
	call	strcpy_diy
	call	puts@plt
	lla	a1,.LC3
	mv	a0,s0
	call	strcat_diy
	call	puts@plt
	ld	ra,72(sp)
	ld	s0,64(sp)
	li	a0,0
	addi	sp,sp,80
	jr	ra
