import sys
# import plot_histogram
from plot_histogram import Histogram
import time

class LettersFrequency(object):
    def __init__(self, arg=2):
        self.input_folder = 'io'
        self.output_folder = 'io'
        self.FREQUENCIES = {
                                # '0': 0, '1': 0, '2': 0, '3': 0,
                                # '4': 0, '5': 0, '6': 0, '7': 0,
                                # '8': 0, '9': 0,
                                'a': 0, 'b': 0, 'c': 0, 'd': 0,
                                'e': 0, 'f': 0, 'g': 0, 'h': 0,
                                'i': 0, 'j': 0, 'k': 0, 'l': 0,
                                'm': 0, 'n': 0, 'o': 0, 'p': 0,
                                'q': 0, 'r': 0, 's': 0, 't': 0,
                                'u': 0, 'v': 0, 'w': 0, 'x': 0,
                                'y': 0, 'z': 0
                            }

        self.LABELS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
        't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

        self.histogram = Histogram()

    # INPUT TEXT
    #===========
    def _get_file_content(self):
        fh = open(self.input_folder + '/raw-input.txt', 'r')
        fc = fh.readlines()
        fh.close()
        return fc


    def _store_letter_frequency(self, letter):
        if letter in self.FREQUENCIES:
            self.FREQUENCIES[letter] = self.FREQUENCIES[letter] + 1
        else:
            self.FREQUENCIES[letter] = 1
            # None

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

    #TODO: PARSE NUMBERS TOO
    def _parse_numbers(self):
        None

    def _parse_text(self, lines):
        for i, line in enumerate(lines):
        # for line in enumerate(lines):
            for letter in line:
                lttr = self._set_to_lower_case_and_validate_ascii(letter)
                if lttr is not None:
                    self._store_letter_frequency(lttr)

    def _show_dict(self):
        # print self.FREQUENCIES
        """ universal style """
        # for i in self.FREQUENCIES:
            # print i, self.FREQUENCIES[i]

        """ python 2 style """
        # for k, v in self.FREQUENCIES.iteritems():
            # print k, v

        """ python 3 style """
        for k, v in self.FREQUENCIES.items():
            print(k, v)


    def _set_histogram(self):
        self.histogram._set_histogram(self.FREQUENCIES)
        self.histogram._set_labels_from_dictionary(self.FREQUENCIES)

    def _show_histogram(self, save_figure=False):
        # plot = self.histogram._plot()
        # plot = self.histogram.plot_thing()
        # plot = self.histogram.plot_thing_2(self.FREQUENCIES)
        # plot = self.histogram.plot_thing_3(self.FREQUENCIES)
        plot = self.histogram.plot_myLists()
        if save_figure == True:
            plot.savefig(self.output_folder + '/frequencies.png')
        plot.show()


lettersFrequency = LettersFrequency()
file_content = lettersFrequency._get_file_content()
lettersFrequency._parse_text(file_content)
# lettersFrequency._show_dict()
lettersFrequency._set_histogram()
lettersFrequency._show_histogram(True)
