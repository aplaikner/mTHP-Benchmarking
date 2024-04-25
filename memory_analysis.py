import matplotlib.pyplot as plt
import statistics as stat
import numpy as np
import math

# TODO: Add base pages to average page usage


settings = []

file = open('output.txt')

benchmark_averages = []

current_size = 0

data = []

data_runs = []


pages_timestamp = np.zeros(8)
pages_current_run = []
pages_all_runs = []

pages_usage_average = []

def average_memory_usage():
    global data
    global data_runs
    global benchmark_averages
    global current_size

    if(len(data)==0):
        return
    data_runs.append(data)
    data = []

    del(data_runs[0])

    minimum = 2000
    for l in data_runs:
        if len(l) < minimum:
            minimum = len(l)

    for l in data_runs:
        del l[minimum:]

    averages = np.zeros(minimum)
    for i in range(minimum):
        acc = 0
        for j in range(len(data_runs)):
            acc+= data_runs[j][i]
        averages[i] = acc / len(data_runs)

    benchmark_averages.append(averages)
    data = []
    data_runs = []
    current_size = 0

def average_page_usage():
    global pages_all_runs
    global pages_current_run
    if(len(pages_current_run)==0):
        return
    pages_all_runs.append(pages_current_run)
    pages_current_run= []

    del(pages_all_runs[0])

    # Make all runs the same length
    minimum = 2000
    for current in pages_all_runs:
        if len(current) < minimum:
            minimum = len(current)
    for current in pages_all_runs:
        del current[minimum:]

    amount_of_runs = len(pages_all_runs)
    average_runs = []
    for i in range(minimum):
        temp = np.zeros(8)
        for j in range(amount_of_runs):
            temp += pages_all_runs[j][i]
        temp /= amount_of_runs
        average_runs.append(temp)

    global pages_usage_average
    pages_usage_average.append(average_runs)
    pages_all_runs = []

def plot_average_page_usage():
    global pages_usage_averagel
    # iterate over benchmarks
    setting_limit = int(len(pages_usage_average) / len(settings))
    current_setting = -1
    for i in range(len(pages_usage_average)):
        if i%setting_limit == 0: current_setting+=1
        adjusted = []
        # iterate over each index (2^index)

        maximum = 0
        for j in range(8):
            temp = []
            for k in range(len(pages_usage_average[i])):
                temp.append(pages_usage_average[i][k][j])
                if maximum < pages_usage_average[i][k][j]: maximum = pages_usage_average[i][k][j]
            adjusted.append(temp)
        x = np.arange(len(pages_usage_average[i]))
        width = 0.1
        multiplier = 0

        fig, ax = plt.subplots(layout='constrained',figsize=(30,5))
        for vals in adjusted:
            offset = width * multiplier 
            number = pow(2, multiplier+4)
            rects = ax.bar(x +offset-0.25, vals, width, label=(str(number) + "kB"))
            ax.bar_label(rects, padding = 3, rotation=90)
            multiplier+=1

        ax.tick_params(axis="x", which="major")
        ax.set_ylabel('Average times mTHP type used')
        ax.set_xlabel('Time in 50ms steps')
        ax.set_title("Benchmark " + str(i%setting_limit+1) + " average page size usage\nSetting: " + settings[current_setting][:-3])
        ax.set_xticks(x+width, x)
        ax.legend(loc='upper left', ncols=3)
        ax.set_ylim(0, maximum+1)

        plt.savefig("graphs/benchmark_" + str(int(i%setting_limit)+1)+"_"+str(settings[current_setting][:-3]) + "_pages")
        plt.close()


def plot_average_memory_usage():
    global benchmark_averages
    setting_limit = int(len(benchmark_averages) / len(settings))
    current_setting = -1
    for i in range(len(benchmark_averages)): 
        if i%setting_limit == 0: current_setting+=1
        time_steps = [i * 1 for i in range(len(benchmark_averages[i]))]
        plt.figure(figsize=(10, 8))  # Adjust figure size as needed
        plt.plot(time_steps, benchmark_averages[i])
        plt.title("Benchmark " + str(i%setting_limit+1) + " average anonymous memory consumption\nSetting: " + settings[current_setting][:-3])
        plt.xlabel("Time in 50ms steps")
        plt.ylabel("Memory consumption in kB")
        plt.grid(True)
        plt.savefig("graphs/benchmark_"+str(int(i%setting_limit)+1)+"_"+str(settings[current_setting][:-3])+"_mem")
        plt.close()

for line in file:
    if 'Benchmark' in line:
        #print(line)
        average_memory_usage()
        average_page_usage()
    if 'Setting' in line:
        c = line.split(' ')[1].split('\n')[0]
        if c not in settings:
            settings.append(line.split(' ')[1].split('\n')[0])
    if 'Run' in line:
        data_runs.append(data)
        pages_all_runs.append(pages_current_run)
        pages_current_run = []
        data = []
    if 'partial' in line:
        # ignore partial hugepages for now
        #print(line)
        continue
    if 'anon-thp-' in line:
        s = ' '.join(line.split())
        s = s.split(' ');
        # DO page size handling
        amount = int(s[1])
        sub = s[0].split('-')
        page_type = sub[4].split('kB:')[0]
        amount = int(amount / int(page_type))
        pages_timestamp[int(math.log2(int(page_type))) - 4] += amount
    if line == '\n':
        data.append(current_size)
        pages_current_run.append(pages_timestamp)
        current_size = 0
        pages_timestamp = np.zeros(8)
    if 'Anonymous:' in line:
        s = ' '.join(line.split())
        s = s.split(' ');
        current_size = int(s[1])

average_memory_usage()
average_page_usage()



# create graphs
plot_average_memory_usage()
plot_average_page_usage()
#print(settings)
#print(benchmark_averages)
#print(pages_usage_average)
