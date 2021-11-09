"""
https://www.khanacademy.org/computing/computer-science/cryptography/crypt/v/caesar-cipher
Known to be used at 58 b.c. by Julius Caesar.
The Shift Cipher
"""

import sys

class ClassName(object):
    """docstring for """
    def __init__(self, arg):
        self.arg = arg


class Cipher_Shift(object):
    """
    DEFAULT SHIFT IS 2,
    UNLESS ANOTHER SHIFT IS PASSED AS ARGUMENT TO THE SCRIPT
    FOR THIS CLASS' CONSTRUCTOR TO TAKE IT IN.
    """
    def __init__(self, arg=2):
        self.SHIFT_KEY = arg

    # INPUT TEXT
    #===========
    def _get_file_content(self):
        fh = open('io/ciphered.txt', 'r')

        fc = fh.read()
        fh.close()

        fc = "".join(fc.split())
        print(fc)
        return fc


    def _save_to_file(self, ciphered):
        fh = open("io/de-ciphered.txt", "w")
        lines_of_text = ciphered
        fh.writelines(lines_of_text)
        fh.close()

    # GET SHIFT
    #==========
    def _get_shifted_value(self, letter):
        ascii_val_shifted = 0
        if self.SHIFT_KEY > 0:
            """ check that the result of the operation would be
            within the ascii lower case letters range """
            # print "ord('a') " + str(ord('a'))
            # print "ord('" + str(letter) + "') " + str(ord(letter)) + " - " + str(self.SHIFT_KEY) + " = " + str(ord(letter) - self.SHIFT_KEY) + " = " + str(chr( ord(letter) - self.SHIFT_KEY ))
            # print "ord('z') " + str(ord('z')) + "\n"
            if ((ord(letter) - self.SHIFT_KEY) > ord('a')):
                ascii_val_shifted = ord(letter) - self.SHIFT_KEY
            elif ((ord(letter) - self.SHIFT_KEY) == ord('a')):
                ascii_val_shifted = ord(letter) - self.SHIFT_KEY
            elif ((ord(letter) - self.SHIFT_KEY) < ord('a')):
                dist_sk = ord('a') - (ord(letter) - self.SHIFT_KEY)
                ascii_val_shifted = ord('z') - dist_sk
                # print "\n\tdist_sk " + str(dist_sk) + "\n\tascii_val_shifted " + str(ascii_val_shifted) + "\n\tascii " + chr(ascii_val_shifted)
        elif self.SHIFT_KEY == 0:
            ascii_val_shifted = ord(letter)
        elif self.SHIFT_KEY < 0:
            if ((ord(letter) + self.SHIFT_KEY) < ord('a')):
                dist_sk = ord('a') - (ord(letter) - self.SHIFT_KEY) - 1
                ascii_val_shifted = ord('z') - dist_sk
            elif ((ord(letter) + self.SHIFT_KEY) == ord('a')):
                ascii_val_shifted = ord('a')
            elif ((ord(letter) + self.SHIFT_KEY) > ord('a')):
                ascii_val_shifted = ord(letter) - self.SHIFT_KEY

        return ascii_val_shifted



    # GET ASCII FOR EVERY LETTER AND SHIFT
    #=====================================
    def _get_ascii_and_shift(self, fc):
        fc_ascii = ''
        fc_ascii_shifted = ''
        fc_ascii_shifted_converted = ''
        for letter in fc:
            ascii_val = ord(letter)
            fc_ascii = str(fc_ascii) + str(ord(letter))
            # print(fc_ascii)

            """ SHIFT """
            ascii_val_shifted = self._get_shifted_value(letter)
            fc_ascii_shifted = str(fc_ascii) + str(ascii_val_shifted)
            # print(fc_ascii_shifted)
            char_val_shifted = chr(ascii_val_shifted)
            fc_ascii_shifted_converted = fc_ascii_shifted_converted + char_val_shifted
            # print(fc_ascii_shifted_converted)

        print(fc_ascii_shifted_converted)
        return fc_ascii_shifted_converted


if len(sys.argv) > 1:
    SHIFT_KEY = int(sys.argv[1])
    cipher_shift = Cipher_Shift(SHIFT_KEY)
else:
    cipher_shift = Cipher_Shift()

fc = cipher_shift._get_file_content()
ciphered = cipher_shift._get_ascii_and_shift(fc)
cipher_shift._save_to_file(ciphered)
