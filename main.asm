.gba
.thumb

.open "rom.gba", "test.gba", 0x08000000

.org allocation
.area allocation_size
    .importobj "build/linked.o"
.endarea

.org 0x0802CE48
.area 0xF0, 0xFE
    ldr r3, =atkE5_pickup |1
    bx r3
    .pool
.endarea

.close
