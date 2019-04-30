An example of how to flash onto the stm32f4 using the built in USB dfu bootloader without first needint to flash the Maple bootloader.

stm32duino uses a custom bootloader called Maple, platformIO has a dfu upload tool that uses the Maple bootloader.
In order to use the default platformIO dfu upload tool you will need to flash the Maple bootloader onto your stm32f4.

This project shows how you can use dfu_util and bypass the need to flash the Maple bootloader onto the stm32.

Prerequisites:
install dfu_util (http://dfu-util.sourceforge.net)
For debian this is as simple as:

```sudo apt-get install dfu-util```


Now go ahead and run the PlatformIO:Upload command.
See the platformio.ini file and dfu_upload.py for how the upload works.


More info:

You do not need to make a .dfu file for the stm32f4. Since the bootloader is in the ROM, you can not accidently overwrite it.
If you want you can use https://sourceforge.net/p/dfu-util/dfu-util/ci/master/tree/dfuse-pack.py to make a .dfu file.

When flashing with a dfu file I am not sure how you can tell the mcu to leave dfu mode and start running. So I would recommend just flashing a .bin file like so with the leave flag. (this is what is happening in dfu_upload.py):
```dfu-util -a 0 -s 0x08004000:leave -D /path/to/image.bin```

