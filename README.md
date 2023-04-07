# ATMEGA8A Tutorial Board A

| Revision | Description                                                                                                                                                                                                                                                                                                |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1.0      | <ul><li>Completed initial design of evaluation board.</li></ul>                                                                                                                                                                                                                                            |
| 1.1      | <ul><li>Added series resistor to external reset for MCU.</li><li>Added series resistor to potentiometer for short-circuit protection.</li><li>Added series resistor to NE555 output for short-circuit protection.</li><li>Updated ISP-10 footprint to ISP-6.</li><li>Updated resistor footprint.</li></ul> |

## Getting Started

### Prerequisites

```bash
# install build tools
sudo apt-get install binutils gcc-avr avr-libc uisp avrdude flex byacc bison
```

```bash
# Windows 10
cmake --build . --preset default
# Ubuntu
cmake --build --preset default
```

## Specifications

### Rev 1.0

| Top                                     | Bottom                                        |
| --------------------------------------- | --------------------------------------------- |
| ![Board Top Layer](images/R1.0/top.svg) | ![Board Bottom Layer](images/R1.0/bottom.svg) |

### Rev 1.1

| Top                                     | Bottom                                        |
| --------------------------------------- | --------------------------------------------- |
| ![Board Top Layer](images/R1.1/top.svg) | ![Board Bottom Layer](images/R1.1/bottom.svg) |
