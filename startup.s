.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global _start
.global Reset_Handler
.global Default_Handler

.section .isr_vector, "a", %progbits
.type _start, %object
_start:
  .word _estack               /* Top of stack */
  .word Reset_Handler         /* Reset Handler */
  .word Default_Handler       /* NMI Handler */
  .word Default_Handler       /* Hard Fault Handler */
  .word Default_Handler       /* MemManage Handler */
  .word Default_Handler       /* BusFault Handler */
  .word Default_Handler       /* UsageFault Handler */
  .word 0                     /* Reserved */
  .word 0
  .word 0
  .word 0
  .word Default_Handler       /* SVCall Handler */
  .word Default_Handler       /* Debug Monitor Handler */
  .word 0                     /* Reserved */
  .word Default_Handler       /* PendSV Handler */
  .word Default_Handler       /* SysTick Handler */

  /* Add IRQ handlers as needed */
  .word Default_Handler       /* IRQ0 */
  .word Default_Handler       /* IRQ1 */
  /* Continue for all used IRQs */

.text
.thumb_func
Reset_Handler:
  ldr   r0, =_sdata
  ldr   r1, =_edata
  ldr   r2, =_sidata
copy_data:
  cmp   r0, r1
  ittt  lt
  ldrlt r3, [r2], #4
  strlt r3, [r0], #4
  blt   copy_data

  ldr   r0, =_sbss
  ldr   r1, =_ebss
  movs  r2, #0
zero_bss:
  cmp   r0, r1
  it    lt
  strlt r2, [r0], #4
  blt   zero_bss

  bl main
  b .

.thumb_func
Default_Handler:
  b .

