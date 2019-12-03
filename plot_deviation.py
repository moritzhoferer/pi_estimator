#!/usr/bin/python3.6

if __name__ == '__main__':
    import os
    import pandas as pd 
    import matplotlib.pyplot as plt 
    

    if 'momo' in plt.style.available:
        plt.style.use('momo')

    data = pd.read_csv('./pi.csv', index_col=0)

    fig, ax = plt.subplots(figsize=(3.375, 2.086))

    ax.plot(
        data.index,
        data.abs_dev,
        'o',
        markerfacecolor=None,
    )

    ax.set_xlabel(r'Iterations')
    ax.set_ylabel(r'Absolute deviation')

    ax.set_xscale('log')
    ax.set_yscale('log')

    plt.tight_layout(pad=.1)
    fig.savefig('./absolute_deviation.pdf')
