SPIFLASH_PHY
============

Register Listing for SPIFLASH_PHY
---------------------------------

+------------------------------------------------------------+----------------------------------------------+
| Register                                                   | Address                                      |
+============================================================+==============================================+
| :ref:`SPIFLASH_PHY_CLK_DIVISOR <SPIFLASH_PHY_CLK_DIVISOR>` | :ref:`0x82003000 <SPIFLASH_PHY_CLK_DIVISOR>` |
+------------------------------------------------------------+----------------------------------------------+

SPIFLASH_PHY_CLK_DIVISOR
^^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0x82003000 + 0x0 = 0x82003000`


    .. wavedrom::
        :caption: SPIFLASH_PHY_CLK_DIVISOR

        {
            "reg": [
                {"name": "clk_divisor[7:0]", "attr": 'reset: 1', "bits": 8},
                {"bits": 24},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


