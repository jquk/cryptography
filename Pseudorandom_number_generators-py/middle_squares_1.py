"""
Pseudorandom number generator know as
'The Middle-Squares method',
first invented by John Von Neumann in 1946 in the context of the development of nuclear weapons in the USA:

1. Select a truly random number, called the 'seed',
   which could come from the measurement of noise,
   or the current time in miliseconds.

The 'seed' is provided as input to a simple calculation:

2. Multiply the seed by itself
3. Output the middle of this result (i.e. trim the first and last numbers)
4. That output is used as the next seed.
5. Repeat the process as many times as needed.

Known Flaws of this method:
- The randomness of the sequence depends on the randomness of the initial seed (same seed same sequence).
- The pseudorandom sequence eventually repeats itself, when the algorithm reaches a seed that it has previously used,
  so the cycle repeats. The length of this cycle is called 'the period'.
- The period is strictly limited by the lenght of the initial seed.
- For a two digit seed, the period is 100 numbers (or algorithm iterations).
- For a three digit seed, the period is 1000 numbers.
- For a four digit seed, the period is 10000 numbers.

- When you generate pseudorandom numbers, there are many sequences that cannot occur, thus discarded from the key space.

Advantages:
- Only have to share the seed and the algorithm, instead of the full key space.
  Once the seed is shared, the ally has only to expand it to generate the same key space.
"""

""" 1. """
seed = 2373
seed_history = []
seed_history.append(seed)
seed_bk = seed
seed_bk_len = len(str(seed_bk))
run_once = False
repeated_seed = False
iteration = 0
while ((repeated_seed is not True) or (run_once is False)):
    print ">>>>>>>>>>>>>>> " + str(iteration) + ": "+ str(seed)
    """ 2. """
    seed = seed * seed
    if seed not in seed_history:
        seed_history.append(seed)
    else:
        repeated_seed = True
        print "\n>>>>>>>>>>>>>>>>>>>>>>> " + str(iteration + 1) + ": "+ str(seed) + " firstly generated at iteration " + str(seed_history.index(seed))
        print "This sequence's period is " + str(len(seed_history)) + " iterations,\nand generates the pseudo-random stream of numbers shown below:\n"
        seed_history_str = ""
        for elem in seed_history:
            seed_history_str = seed_history_str + str(elem)
        print seed_history_str
    """ 3. """
    seed = str(seed)
    if len(seed) < 3:
        # seed = seed[0:len(seed)-1]
        # seed = seed[1:]
        None
    elif len(seed) < 4:
        seed = seed[1:len(seed)-1]
    else:
        """ fix OverflowError when converting float infinity to integer """
        odd = True
        while len(seed) > (seed_bk_len + 2):
            """ back to original size """
            seed = seed[1:len(seed)-1]
            if odd == True:
                seed = seed[:len(seed)-1]
            else:
                seed = seed[1:]
            odd = not odd
    seed = float(seed)
    seed = int(seed)
    if run_once is False:
        run_once = True
    iteration = iteration + 1
