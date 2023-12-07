/**************************************************************************//**
* @file        ASCII_LUT.h
* @ingroup 	   Adafruit358_LCD
* @brief       ASCII LCD LUT
*
* @details     Lookup Table for ASCII characters to be drawn on LCD
*

*
* @copyright
* @author	   Justin Ye
* @date        April 19, 2021
* @version		0.1
*****************************************************************************/


#ifndef ASCII_LUT_H_
#define ASCII_LUT_H_
const char char_value[64] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	';',
	':',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'I',
	'J',
	'K',
	'L',
	'M',
	'N',
	'O',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

const char char_lookup[64] = {

	0b110100, //'0',
	0b100, //'1',
	0b1100, //'2',
	0b100100, //'3',
	0b1100100, //'4',
	0b1000100, //'5',
	0b101100, //'6',
	0b1101100, //'7',
	0b1001100, //'8',
	0b101000, //'9',
	0b1001000, //':',
	0b11000, //';',
	0b100, //'A',
	0b1100, //'B',
	0b100100, //'C',
	0b1100100, //'D',
	0b1000100, //'E',
	0b101100, //'F',
	0b1101100, //'G',
	0b1001100, //'H',
	0b101000, //'I',
	0b11010, //'J',
	0b10100, //'K',
	0b11100, //'L',
	0b110100, //'M',
	0b1110100, //'N',
	0b1010100, //'O',
	0b111100, //'P',
	0b1111100, //'Q',
	0b1011100, //'R',
	0b111000, //'S',
	0b1111000, //'T',
	0b10010100, //'U',
	0b10011100, //'V',
	0b11101000, //'W',
	0b101100, //'X',
	0b11110100, //'Y',
	0b11010100, //'Z',
	0b100, //'a',
	0b1100, //'b',
	0b100100, //'c',
	0b1100100, //'d',
	0b1000100, //'e',
	0b101100, //'f',
	0b1101100, //'g',
	0b1001100, //'h',
	0b101000, //'i',
	0b11010, //'j',
	0b10100, //'k',
	0b11100, //'l',
	0b110100, //'m',
	0b1110100, //'n',
	0b1010100, //'o',
	0b111100, //'p',
	0b1111100, //'q',
	0b1011100, //'r',
	0b111000, //'s',
	0b1111000, //'t',
	0b10010100, //'u',
	0b10011100, //'v',
	0b11101000, //'w',
	0b101100, //'x',
	0b11110100, //'y',
	0b11010100, //'z',
	};


#endif /* ASCII_LUT_H_ */