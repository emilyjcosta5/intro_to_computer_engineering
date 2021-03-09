# For plotting results for Problem 1

import pandas as pd 
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv('/home/emily/Documents/data_structures/homework_4/sort.txt')

fig, axes = plt.subplots(2,1,sharex=True, figsize=(8,5))

sns.barplot(data=df, x='Sort', y='Moves', hue='Case', ax=axes[0], ci=0, edgecolor='black', linewidth=2)
sns.barplot(data=df, x='Sort', y='Comparisons', hue='Case', ax=axes[1], ci=0, edgecolor='black', linewidth=2)
axes[0].set_xlabel('')
axes[1].get_legend().remove()
axes[0].legend(loc='upper left')
axes[0].set_yscale('log')
axes[1].set_yscale('log')
axes[0].set_ylim(1,10000000)
axes[1].set_ylim(1,10000000)

axes[0].yaxis.grid(color='lightgrey', linestyle=':')
axes[1].yaxis.grid(color='lightgrey', linestyle=':')
axes[0].set_axisbelow(True)
axes[1].set_axisbelow(True)

for p in axes[0].patches:
        a = (float(p.get_height()))
        a = str(int(a))
        axes[0].annotate(a, (p.get_x() + p.get_width() / 2., p.get_height()), 
                            ha = 'center', va = 'top', xytext = (0, 9), textcoords = 'offset points')
for p in axes[1].patches:
        a = (float(p.get_height()))
        a = str(int(a))
        axes[1].annotate(a, (p.get_x() + p.get_width() / 2., p.get_height()), 
                            ha = 'center', va = 'top', xytext = (0, 9), textcoords = 'offset points')

plt.tight_layout()

plt.savefig('./problem_1.jpg')