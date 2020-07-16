# KeystrokeModifier

Do not use this code for malicious means. When this program is running it creates typos whenever someone is typing. It will modify all key strokes except ones with the keyboard settings to output keyboard strokes with an extra info of the value of `programsExtraInfo` in main.cpp (by default this value is `0x77196848` which is `1998153800` in decimal). The macro, `programsExtraInfo` in main.cpp, can only have 4 bytes of data. It can be any 4 byte value, preferably not `0x00000000` (which is `0` in decimal). It is recomended to use a random value to make it more  difficult to bypass except for by people who know the value. One can generate a random hex number at https://www.random.org/cgi-bin/randbyte?nbytes=4&format=h. To set the value of `programsExtraInfo` using this random hex number simply set its value to `0x` which specifies the number is in hex, followed by the random hex number without spaces.
Note that the driver makes all key strokes from the user's end not create typos. The values in `programsExtraInfo` has to match the value in the original source code for it to work. The driver also has to load after the Keyboard Class driver loads.

Be sure to install the write driver for your version of Windows.

To install the driver, first put the driver at path `C:\Windows\System32\drivers\kbddrive.sys`. Next, run the file `driver installer.bat` as **an administrator**.
