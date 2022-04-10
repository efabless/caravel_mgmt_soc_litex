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

Functionality
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
    generated/spi_master
    generated/timer0
    generated/uart
    generated/uart_enabled
    generated/user_irq_0
    generated/user_irq_1
    generated/user_irq_2
    generated/user_irq_3
    generated/user_irq_4
    generated/user_irq_5
    generated/user_irq_ena

Prerequisites
=============

- Docker

Install Caravel
===============

To setup caravel, run the following:

.. code:: bash
    
    git clone https://github.com/efabless/caravel_user_project.git
    cd caravel_user_project
    
    make install

To remove caravel, run

.. code:: bash

    make uninstall

By default
`caravel-lite <https://github.com/efabless/caravel-lite.git>`__ is
installed. To install the full version of caravel, run this prior to
calling make install.

.. code:: bash

    export CARAVEL_LITE=0

Caravel Integration
===================

Repo Integration
----------------

Caravel files are kept separate from the user project by having caravel
as submodule. The submodule commit should point to the latest of
caravel/caravel-lite master/main branch. The following files should have a symbolic
link to `caravel's <https://github.com/efabless/caravel.git>`__
corresponding files:

-  `Openlane Makefile <../../openlane/Makefile>`__: This provides an easier
   way for running openlane to harden your macros. Refer to `Hardening
   the User Project Macro using
   Openlane <#hardening-the-user-project-using-openlane>`__. Also,
   the makefile retains the openlane summary reports under the signoff
   directory.

-  `Pin order <../../openlane/user_project_wrapper/pin_order.cfg>`__ file for
   the user wrapper: The hardened user project wrapper macro must have
   the same pin order specified in caravel's repo. Failing to adhere to
   the same order will fail the gds integration of the macro with
   caravel's back-end.

The symbolic links are automatically set when you run ``make install``.

Verilog Integration
-------------------

You need to create a wrapper around your macro that adheres to the
template at
`user\_project\_wrapper <https://github.com/efabless/caravel/blob/master/verilog/rtl/__user_project_wrapper.v>`__.
The wrapper top module must be named ``user_project_wrapper`` and must
have the same input and output ports as the golden wrapper `template <https://github.com/efabless/caravel/blob/master/verilog/rtl/__user_project_wrapper.v>`__. The wrapper gives access to the
user space utilities provided by caravel like IO ports, logic analyzer
probes, and wishbone bus connection to the management SoC.

For this sample project, the user macro makes use of:

-  The IO ports for displaying the count register values on the IO pads.

-  The LA probes for supplying an optional reset and clock signals and
   for setting an initial value for the count register.

-  The wishbone port for reading/writing the count value through the
   management SoC.

Refer to `user\_project\_wrapper <../../verilog/rtl/user_project_wrapper.v>`__
for more information.

.. raw:: html

   <p align="center">
   <img src="./_static/counter_32.png" width="50%" height="50%">
   </p>

.. raw:: html

   </p>


Running Full Chip Simulation
============================

First, you will need to install the simulation environment, by

.. code:: bash

    make simenv

This will pull a docker image with the needed tools installed.

Then, run the RTL simulation by

.. code:: bash

    export PDK_ROOT=<pdk-installation-path>
    # specify simulation mode: RTL/GL
    export SIM=RTL
    # Run RTL simulation on IO ports testbench, make verify-io_ports
    make verify-<testbench-name>

Once you have the physical implementation done and you have the gate-level netlists ready, it is crucial to run full gate-level simulations to make sure that your design works as intended after running the physical implementation. 

Run the gate-level simulation by: 

.. code:: bash

    export PDK_ROOT=<pdk-installation-path>
    # specify simulation mode: RTL/GL
    export SIM=GL
    # Run RTL simulation on IO ports testbench, make verify-io_ports
    make verify-<testbench-name>


This sample project comes with four example testbenches to test the IO port connection, wishbone interface, and logic analyzer. The test-benches are under the
`verilog/dv <https://github.com/efabless/caravel_user_project/tree/main/verilog/dv>`__ directory. For more information on setting up the
simulation environment and the available testbenches for this sample
project, refer to `README <https://github.com/efabless/caravel_user_project/blob/main/verilog/dv/README.md>`__.


User Project Wrapper Requirements
=================================

Your hardened ``user_project_wrapper`` must match the `golden user_project_wrapper <https://github.com/efabless/caravel/blob/master/gds/user_project_wrapper_empty.gds.gz>`__ in the following: 

- Area ``(2.920um x 3.520um)``
- Top module name ``"user_project_wrapper"``
- Pin Placement
- Pin Sizes 
- Core Rings Width and Offset
- PDN Vertical and Horizontal Straps Width 


.. raw:: html

   <p align="center">
   <img src="./_static/empty.png" width="40%" height="40%">
   </p>
 
You are allowed to change the following if you need to: 

- PDN Vertical and Horizontal Pitch & Offset

.. raw:: html

   <p align="center">
   <img src="./_static/pitch.png" width="30%" height="30%">
   </p>
 
To make sure that you adhere to these requirements, we run an exclusive-or (XOR) check between your hardened ``user_project_wrapper`` GDS and the golden wrapper GDS after processing both layouts to include only the boundary (pins and core rings). This check is done as part of the `mpw-precheck <https://github.com/efabless/mpw_precheck>`__ tool. 


Hardening the User Project using OpenLane
==========================================

OpenLane Installation 
---------------------

You will need to install openlane by running the following

.. code:: bash

   export OPENLANE_ROOT=<openlane-installation-path>

   # you can optionally specify the openlane tag to use
   # by running: export OPENLANE_TAG=<openlane-tag>
   # if you do not set the tag, it defaults to the last verfied tag tested for this project

   make openlane

For detailed instructions on the openlane and the pdk installation refer
to
`README <https://github.com/The-OpenROAD-Project/OpenLane#setting-up-openlane>`__.

Hardening Options 
-----------------

There are three options for hardening the user project macro using
openlane:

+--------------------------------------------------------------+--------------------------------------------+--------------------------------------------+
|           Option 1                                           |            Option 2                        |           Option 3                         |
+--------------------------------------------------------------+--------------------------------------------+--------------------------------------------+
| Hardening the user macro(s) first, then inserting it in the  |  Flattening the user macro(s) with the     | Placing multiple macros in the wrapper     |
| user project wrapper with no standard cells on the top level |  user_project_wrapper                      | along with standard cells on the top level |
+==============================================================+============================================+============================================+
| |pic1|                                                       | |pic2|                                     | |pic3|                                     |
|                                                              |                                            |                                            |
+--------------------------------------------------------------+--------------------------------------------+--------------------------------------------+
|           ex: |link1|                                        |                                            |           ex: |link2|                      |
+--------------------------------------------------------------+--------------------------------------------+--------------------------------------------+

.. |link1| replace:: `caravel_user_project <https://github.com/efabless/caravel_user_project>`__

.. |link2| replace:: `caravel_ibex <https://github.com/efabless/caravel_ibex>`__


.. |pic1| image:: ./_static/option1.png
   :width: 48%

.. |pic2| image:: ./_static/option2.png
   :width: 140%

.. |pic3| image:: ./_static/option3.png
   :width: 72%

For more details on hardening macros using openlane, refer to `README <https://github.com/The-OpenROAD-Project/OpenLane/blob/master/docs/source/hardening_macros.md>`__.


Running OpenLane 
-----------------

For this sample project, we went for the first option where the user
macro is hardened first, then it is inserted in the user project
wrapper without having any standard cells on the top level.

.. raw:: html

   <p align="center">
   <img src="./_static/wrapper.png" width="30%" height="30%">
   </p>

.. raw:: html

   </p>
   
To reproduce hardening this project, run the following:

.. code:: bash

   # DO NOT cd into openlane

   # Run openlane to harden user_proj_example
   make user_proj_example
   # Run openlane to harden user_project_wrapper
   make user_project_wrapper


For more information on the openlane flow, check `README <https://github.com/The-OpenROAD-Project/OpenLane#readme>`__.


.. include:: references.rst
   
   
.. |License| image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
   :target: https://opensource.org/licenses/Apache-2.0
.. |User CI| image:: https://github.com/efabless/caravel_project_example/actions/workflows/user_project_ci.yml/badge.svg
   :target: https://github.com/efabless/caravel_project_example/actions/workflows/user_project_ci.yml
.. |Caravel Build| image:: https://github.com/efabless/caravel_project_example/actions/workflows/caravel_build.yml/badge.svg
   :target: https://github.com/efabless/caravel_project_example/actions/workflows/caravel_build.yml

