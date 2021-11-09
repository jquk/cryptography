"""
https://www.khanacademy.org/computing/computer-science/cryptography/crypt/v/caesar-cipher
Known to be used at 58 b.c. by Julius Caesar.
The Shift Cipher
"""

import sys

class Cipher_Shift(object):
    """
    DEFAULT SHIFT IS 2,
    UNLESS ANOTHER SHIFT IS PASSED AS ARGUMENT TO THE SCRIPT
    FOR THIS CLASS' CONSTRUCTOR TO TAKE IT IN.
    """
    def __init__(self, arg=2):
        self.SHIFT_KEY = arg
        self.ONE_LINER = False

    # INPUT TEXT
    #===========
    def _get_file_content(self):
        fh = open('io/raw-input.txt', 'r')

        if self.ONE_LINER == True:
            fc = fh.read()
            fc = "".join(fc.split())
        elif self.ONE_LINER == False:
            fc = fh.readlines()
            fc_faux = ""
            for line in fc:
                fc_faux = fc_faux + "".join(line.split())
            fc = fc_faux
        # else:
        #     None

        fh.close()

        # print(fc)
        return fc

    def _set_to_lower_case_and_validate_ascii(self, character):
        ret_val = None
        if isinstance(character, (int, long)):
            None
            # num_str = str(character)
            # ascii_num_str = ord(num_str)
            # if ((ascii_num_str >= 48) and (ascii_num_str <= 57)):
                # ret_val = num_str
        elif isinstance(character, str):
            ascii_character_lower = ord(character.lower())
            if ((ascii_character_lower >= 97) and (ascii_character_lower <= 122)):
                ret_val = character.lower()
            elif ((ascii_character_lower >= 48) and (ascii_character_lower <= 57)):
                # ret_val = character.lower()#should not affect numbers
                None
        return ret_val

    def _parse_text(self, lines):
        for i, line in enumerate(lines):
        # for line in enumerate(lines):
            for letter in line:
                lttr = self._set_to_lower_case_and_validate_ascii(letter)

    def _save_to_file(self, ciphered):
        fh = open("io/ciphered.txt", "w")
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
            if ((ord(letter) + self.SHIFT_KEY) < ord('z')):
                ascii_val_shifted = ord(letter) + self.SHIFT_KEY
            elif ((ord(letter) + self.SHIFT_KEY) == ord('z')):
                ascii_val_shifted = ord(letter) + self.SHIFT_KEY
            elif ((ord(letter) + self.SHIFT_KEY) > ord('z')):
                dist_sk = ord(letter) + self.SHIFT_KEY - ord('z')
                ascii_val_shifted = (ord('a') - 1) + dist_sk
        elif self.SHIFT_KEY == 0:
            ascii_val_shifted = ord(letter)
        elif self.SHIFT_KEY < 0:
            if ((ord(letter) + self.SHIFT_KEY) < ord('a')):
                dist_sk = ord('a') - (ord(letter) + self.SHIFT_KEY) - 1
                ascii_val_shifted = ord('z') - dist_sk
            elif ((ord(letter) + self.SHIFT_KEY) == ord('a')):
                ascii_val_shifted = ord('a')
            elif ((ord(letter) + self.SHIFT_KEY) > ord('a')):
                ascii_val_shifted = ord(letter) + self.SHIFT_KEY

        return ascii_val_shifted



    # GET ASCII FOR EVERY LETTER AND SHIFT
    #=====================================
    def _get_ascii_and_shift(self, fc):
        fc_ascii = ''
        fc_ascii_shifted = ''
        fc_ascii_shifted_converted = ''
        if self.ONE_LINER == True:
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
        elif self.ONE_LINER == False:
            # for line in fc:
            # for letter in line:
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
