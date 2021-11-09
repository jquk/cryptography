import matplotlib.pyplot as plt
import numpy as np
import operator

class Histogram(object):
    def __init__(self):
        self.x_ticks = []
        self.x = []
        self.y = []
        self.xnp = []
        self.ynp = []
        self.m_plot = plt
        self.LABELS = []


    def _add_x(self, x):
        self.x.append(x)

    def _add_y(self, y):
        self.y.append(y)

    def _set_x(self, x_list):
        for x in x_list:
            self._add_x(x)

    # def _set_y(self, m_list):
    #     m_list_max_key = max(m_list.iteritems(), key=operator.itemgetter(1))[0]
    #     m_list_max_value = max(m_list.iteritems(), key=operator.itemgetter(1))[1]
    #     # m_list_max_value = m_list[m_list_max_key]
    #     # self.y = [i for i in range(0, m_list_max_value)]
    #     self.y = m_list_max_value

    def _set_y(self, y_list):
        for y in y_list:
            self._add_y(y)

    def _set_x_and_y(self, m_list):
        for i in m_list:
            # print i, m_list[i]
            self._add_x(ord(i))
            self._add_y(m_list[i])

    def _add_x_tick(self, x_tick):
        self.x_ticks.append(x_tick)

    def _set_numpy_values(self):
        self.xnp = np.array(self.x)
        self.ynp = np.array(self.y)

    def _set_labels(self, labels):
        self.LABELS = labels

    def _set_labels_from_dictionary(self, myDictionary):
        for i in myDictionary:
            self.LABELS.append(i)

    def _set_histogram(self, m_list):
        # for i in m_list:
            # self._add_x_tick(i)
            # self._add_y(m_list[i])
        # self._set_y(m_list)
        self._set_x_and_y(m_list)
        self._set_numpy_values()

    def _show(self):
        self.m_plot.show()

    def plot_thing_2(self, myDictionary):
        width = 0.5
        self.m_plot.bar(myDictionary.keys(), myDictionary.values(), width, color='g')

    def plot_myDictionary(self, myDictionary):
        self.m_plot.bar(list(myDictionary.keys()), myDictionary.values(), color='g')

    def plot_myLists(self):
        if len(self.LABELS) > 0:
            self.m_plot.xticks(self.x, self.LABELS)

        # barWidth = 0.5
        # self.m_plot.bar(self.x, self.y, color='g', width=barWidth, align='center')
        self.m_plot.bar(self.x, self.y, color='g', align='center')
        return self.m_plot


    def plot_thing(self):
        f = plt.figure()
        sp = f.add_subplot(111)
        tx = np.array([0,1,2,3])
        ty = np.array([20,21,22,23])
        # sp.plot(tx, ty, 'o-')
        """ plot """
        # sp.plot(self.xnp, self.ynp, 'o-')
        # sp.plot(self.xnp, self.ynp, 'o')
        # sp.plot(self.xnp, self.ynp, 'r+')
        sp.plot(self.xnp, self.ynp)
        return f

# x = np.array([0,1,2,3])
# y = np.array([20,21,22,23])
# my_xticks = ['John','Arnold','Mavis','Matt']
# plt.xticks(x, my_xticks)
# plt.plot(x, y)
# plt.show()
