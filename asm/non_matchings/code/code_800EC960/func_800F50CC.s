glabel func_800F50CC
/* B6C26C 800F50CC 3C028013 */  lui   $v0, %hi(D_8013064C) # $v0, 0x8013
/* B6C270 800F50D0 2442064C */  addiu $v0, %lo(D_8013064C) # addiu $v0, $v0, 0x64c
/* B6C274 800F50D4 8C4E0000 */  lw    $t6, ($v0)
/* B6C278 800F50D8 11C00002 */  beqz  $t6, .L800F50E4
/* B6C27C 800F50DC 00000000 */   nop   
/* B6C280 800F50E0 AC400000 */  sw    $zero, ($v0)
.L800F50E4:
/* B6C284 800F50E4 03E00008 */  jr    $ra
/* B6C288 800F50E8 00000000 */   nop   
