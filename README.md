# KeystrokeModifier

Do not use this code for malicious means. When this program is running it creates typos whenever someone is typing. It will modify all key strokes except ones with the keyboard settings to output keyboard strokes with an extra info of the value of programsExtraInfo in main.cpp (by default this value is 0x77196848 which is 1998153800 in decimal). The macro, programsExtraInfo in main.cpp, can only have 4 bytes of data. It can be any 4 byte value, preferably not 0x00000000 (which is 0) in decimal. It is recomended to use a random value to make it more  difficult to bypass except for by people who know the value.
