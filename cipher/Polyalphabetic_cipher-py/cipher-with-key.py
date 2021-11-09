"""
https://www.khanacademy.org/computing/computer-science/cryptography/crypt/v/polyalphabetic-cipher

The strength of the cipher depends on the time taken to detect the length of the shift keyword used,
the longer the shiftword the stronger the cipher.

Known Flaws:
- Every time a letter outstands above or below the others in the frequency distribution,
  it is leaking information.
- To break the code must determine the length of the shiftword used,
  by checking the frequency distribution at diferent intervals.
  Thus for a long enough message, the frequency distribution will be
  periodical with a lenght equal to the length of the shiftword.

- Analyzing the frequency for each

Advantages:
- Flattens the frequency of the letters.
"""
class Cipher_With_Key(object):
    """docstring for ."""
#    def __init__(self, arg):
#        super(, self).__init__()
#        self.arg = arg




    # INPUT TEXT
    #===========
    def _get_file_content(self):
        fh = open('io/raw-input.txt', 'r')

        fc = fh.read()
        fh.close()

        print(fc)
        fc = "".join(fc.split())
        print(fc)
        return fc

    def _get_key(self):
        key_file = open('io/keys/key.txt', 'r')
        key = key_file.read()
        key_file.close()
        print(key)
        return key

    def _save_to_file(self, ciphered):
        fh = open("io/output.txt", "w")
        lines_of_text = ciphered
        fh.writelines(lines_of_text)
        fh.close()

    # GET SHIFT
    #==========
    def _get_shifted_value(self, letter, key):
        letter = ord(letter)
        key = ord(key)
        ascii_val_shifted = 0
        #ENCODE
        # R = L + K
        # if R > 122
        #   R = R - 122 + 97
        if ((letter + key) < ord('z')):
            ascii_val_shifted = letter + key
        elif ((letter + key) == ord('z')):
            ascii_val_shifted = letter + key
        elif ((letter + key) > ord('z')):
#            dist_sk = letter + key - ord('z')
#            ascii_val_shifted = ord('a') + dist_sk
#            while ascii_val_shifted > ord('z'):
#                dist_sk = ascii_val_shifted - ord('z')
#                ascii_val_shifted = ord('a') + dist_sk
            ascii_val_shifted = letter + key
            while ascii_val_shifted > ord('z'):
                dist_sk =  - ord('z')
                ascii_val_shifted = ascii_val_shifted - ord('z') + ord('a')
            print("\n\t-------->  letter: " + str(letter) + "  key: " + str(key) + "  dist_sk: " + str(dist_sk) + "  ascii_val_shifted: " + str(ascii_val_shifted))

        return ascii_val_shifted

    # GET ASCII FOR EVERY LETTER AND SHIFT
    #=====================================
    def _get_ascii_and_align_with_key_and_shift_by_key(self, fc, key):
        fc_ascii = ''
        fc_ascii_shifted = ''
        fc_ascii_shifted_converted = ''
        idx = 0
        key_idx = 0
        KEY_IDX_MAX = len(key) - 1
        for letter in fc:
            fc_idx_ascii = ord(fc[idx])
            key_idx_ascii = ord(key[key_idx])
            fc_key_sum_ascii = fc_idx_ascii + key_idx_ascii

            fc_shifted = self._get_shifted_value(fc[idx], key[key_idx])
            print("\n\t-------->  letter: " + fc[idx] + " + key: " + key[key_idx] + "  =  ascii_val_shifted: " + chr(fc_shifted) + '\n')
            fc_ascii_shifted_converted = fc_ascii_shifted_converted + chr(fc_shifted)

            # update indexes
            idx = idx + 1
            if key_idx >= KEY_IDX_MAX:
                key_idx = 0
            else:
                key_idx = key_idx + 1

        print(fc_ascii_shifted_converted)
        return fc_ascii_shifted_converted


cipher_with_key = Cipher_With_Key()
fc = cipher_with_key._get_file_content()
key = cipher_with_key._get_key()
ciphered_with_key = cipher_with_key._get_ascii_and_align_with_key_and_shift_by_key(fc, key)
cipher_with_key._save_to_file(ciphered_with_key)
