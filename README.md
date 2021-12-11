# Extending Cuckoo Filter With Different In-Bucket Eviction Policies

## Prerequisites

* python ( under 3.7 )
* pandas, numpy, seaborn & matplotlib ( for plotting )
* cmake

## Build up

```
    cmake . -D{eviction_policies} && make clean && make all
```

Replace the {eviction_policies} with following specs of built-in eviction policies:

* RR: For each bucket, victim entries are selected in round-roubin.
* RANDOM: Randomly selecting the entry from the bucket to replace.
* AWARE: Similar with RANDOM, but pass the index of the most recent evicted entry. 
* FIRST: Always evicting the first entry. 

## Run benchmarks

```
    python test.py
```

This python script builds and tests cuckoo filters with all aforementioned eviction policies. We use Mersenne Twister to randomly generate inserted items. We store results in the csv format. You can check them at *result/ploted_result.csv*.

## Plot figures

We build a Jupyter Notebook script, *plot.ipynb*, to visualize fpr, load factors, overheads and average relocation steps.  
