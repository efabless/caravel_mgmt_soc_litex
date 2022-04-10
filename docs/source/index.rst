.. raw:: html

   <!---
   # SPDX-FileCopyrightText: 2020 Efabless Corporation
   #
   # Licensed under the Apache License, Version 2.0 (the "License");
   # you may not use this file except in compliance with the License.
   # You may obtain a copy of the License at
   #
   #      http://www.apache.org/licenses/LICENSE-2.0
   #
   # Unless required by applicable law or agreed to in writing, software
   # distributed under the License is distributed on an "AS IS" BASIS,
   # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   # See the License for the specific language governing permissions and
   # limitations under the License.
   #
   # SPDX-License-Identifier: Apache-2.0
   -->

==============================
Caravel Management SoC - Litex
==============================

|License| |User CI| |Caravel Build|

.. contents:: Table of Contents
    :depth: 2

Overview
========

This repository contains an implementation of the management area for
`Caravel <https://github.com/efabless/caravel.git>`__.
The management area is SoC generated using Litex containing a VexRiscv core with memory, a flash controller and serial peripherals.

Features
=============

* VexRiscv core with debug port
* 2 kB SRAM plus 1 kB of DFFRAM
* XIP SPI Flash controller
* UART, SPI and GPIO ports
* 128 port logic analyzer
* Counter / timer
* 32-bit Wishbone bus extending to the user project area
* 6 user interrupts

Processor
=========

The processor core is based on a VexRiscv minimal+debug configuration.  The core has been configured with 64 bytes of instruction cache.
The core has not been configured with compress or multiply instructions.

.. include:: generated/interrupts.rst

.. include:: generated/uart.rst

Description
-----------
The UART provide general serial communication with the management SoC.  The baud rate is configured at 9600.

.. include:: generated/spi_master.rst

.. include:: generated/gpio.rst

Description
-----------
A single GPIO port is provided from the Management SoC as general indicator and diagnostic for programming or as a means
to control functionality off chip.  One example user case is to set an enable for an off-chip LDO enabling a controlled power-up sequence for the user project.

Debug
=====

Description
-----------
Debug support is enabled in the core and can be accessed through a dedicated UART port configured as a wishbone master.
The baud rate for the port is 9600.

See the following reference for more information <https://github.com/SpinalHDL/VexRiscv#debugplugin>.


.. include:: generated/timer0.rst

Logic Analyzer
==============

.. include:: generated/la.rst

Memory Map
==========

.. table:: Memory Regions
   :widths: auto

    =====           ==========      ==========
    region          address         size
    =====           ==========      ==========
    dff             0x00000000      0x00000400
    sram            0x01000000      0x00000800
    flash           0x10000000      0x01000000
    hk              0x26000000      0x00100000
    user project    0x30000000      0x10000000
    csr             0xf0000000      0x00010000
    vexriscv_debug  0xf00f0000      0x00000100
    =====           ==========      ==========

Other Registers
=============

.. toctree::
    :maxdepth: 1

    generated/interrupts

    generated/ctrl
    generated/debug_mode
    generated/debug_oeb
    generated/flash_core
    generated/flash_phy
    generated/gpio
    generated/la
    generated/mprj_wb_iena
    generated/spi_enabled
    generated/uart_enabled
    generated/user_irq_0
    generated/user_irq_1
    generated/user_irq_2
    generated/user_irq_3
    generated/user_irq_4
    generated/user_irq_5
    generated/user_irq_ena


.. include:: references.rst

   
.. |License| image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
   :target: https://opensource.org/licenses/Apache-2.0
.. |User CI| image:: https://github.com/efabless/caravel_project_example/actions/workflows/user_project_ci.yml/badge.svg
   :target: https://github.com/efabless/caravel_project_example/actions/workflows/user_project_ci.yml
.. |Caravel Build| image:: https://github.com/efabless/caravel_project_example/actions/workflows/caravel_build.yml/badge.svg
   :target: https://github.com/efabless/caravel_project_example/actions/workflows/caravel_build.yml

