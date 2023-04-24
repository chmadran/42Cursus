**INTRO**

To send data back and forth, you’ll need to use bytes and therefore you'll need to encode the string passed as argument. The term character is a logical term (meaning it defines something in terms of the way people think of things). The term byte is a device term (meaning it defines something in terms of the way the hardware was designed). The difference is in the encoding.

The character 'A' must be encoded into a certain bit pattern that the machine can use. This is a mostly arbitrary decision on the part of hardware implementors. You could say that A=1, B=2, and so on. For ASCII (the American Standard for Computer Information Interchange), designers chose a 7-bit encoding (A=1000001), giving room for encoding 128 different characters in those seven bits. Since a byte is 8-bits on most hardware today, the hardware just pads the extra bit with a zero (A=01000001). So even in the case of simple ASCII, characters are not the same thing as bytes. ASCII reserves 32 encodings for special characters like the TAB, NEWLINE, FORMFEED, and then the remaining encodings are for printing characters like SPACE, !, @, #, $, A-Z, a-z, 0-9, and so on.

What can the eighth bit be used for? It gives 128 more character encoding numbers. Each manufacturer has used the other 128 encodings above ASCII (values 128-255) for special printing characters, such as GRAY-BLOCK, N-WITH-TILDE, and YEN. They've been pretty horrible about consistency, though: IBM's GRAY-BLOCK character is not the same number as Commodore PET's GRAY-BLOCK character. Some computers have a YEN symbol while others don't.

**ENCODING CHAR TO BINARY**

```
void	ft_encoding(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}
```


**DECODING BINARY TO CHAR**

```
void	ft_handle_signal(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR2)
		i = i | (1 << bit); // With or, result is 1 if one of the bits is 1
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}
```


Source : https://www.thethingsnetwork.org/docs/devices/bytes/
Source (bitmaths) : https://docs.arduino.cc/learn/programming/bit-math
